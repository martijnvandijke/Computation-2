/*
* cgraph.c
* extract call graphs from c sources
* Luiz Henrique de Figueiredo (lhf@visgraf.impa.br)
* for the Free Software Foundation and the GNU effort
* 28 Nov 89
*/

#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*
* function declarations
*/

#define	iscsymf(c)	(isalpha(c) || (c)=='_')
#define	iscsym(c)	(isalnum(c) || (c)=='_')

#define streq(x,y)	(strcmp(x,y)==0)
#define strneq(x,y)	(strcmp(x,y)!=0)

#define	emit(p,c,l)	printf("%s\t%s\t%d\t%s\n",p,c,l,filename)

void	*malloc		(size_t);
void	*realloc	(void *, size_t);

int	scan		(FILE *f, char *filename);	
void	macro		(FILE *f, char *filename);
int	getc4		(FILE *f);
int	getc3		(FILE *f);
int	getc2		(FILE *f);
int	getc1		(FILE *f);
int	ungetc1		(int c, FILE *f);
void	select		(int);
int	reserved	(char *s);
char	*estrdup	(char *s);
void	*emalloc	(size_t s);
void	*erealloc	(void *, size_t);

#define	loop	for(;;)

/*
* global variables
*/

#define EOS	'\0'			/* end of string */

typedef enum { KNR, ANSI, GNU };	/* choice of keywords */

static char *name=NULL;			/* last identifier seen */
static int line;			/* current input line */
static int idline;			/* line where last identifier occured */
static int synch=0;			/* synch brace level? */

/*
* main control function
* scans files given on command line or stdin if none given
* returns 0 on success, 1 on error
*/

int
main(int argc, char *argv[])
{
 static char usage[]=
  "usage: cgraph [-traditional] [-ansi] [-gnu] [-gcc] [-synch] [file...]\n";
 int rc=0;				/* return code */
 int nf=0;				/* number of files on command line */
 int i;
 select(GNU);				/* select gcc keywords by default */
 for (i=1; i<argc; i++)
 {
  char *arg=argv[i];
  if (arg[0]=='-')			/* an option */
  {
   if (streq(arg,"-"))			/* "-" means stdin */
    scan(stdin,"(stdin)");
   else if (streq(arg,"-traditional"))	/* select k&r keywords */
    select(KNR);
   else if (streq(arg,"-ansi"))		/* select ansi keywords */
    select(ANSI);
   else if (streq(arg,"-gcc"))		/* select gcc keywords */
    select(GNU);
   else if (streq(arg,"-gnu"))		/* select gcc keywords */
    select(GNU);
   else if (streq(arg,"-synch"))	/* synch brace level */
    synch=1;
   else					/* invalid option */
   {
    fprintf(stderr,"cgraph: unknown option %s\n",arg);
    fprintf(stderr,usage);
    return 1;
   }
  }
  else					/* better be a filename */
  {
   FILE *f=fopen(arg,"rt");	
   ++nf;
   if (f==NULL)
   {
    fprintf(stderr,"cgraph: cannot open ");
    perror(arg);
    rc=1;
   }
   else
   {
    rc |= scan(f,arg);
    fclose(f);
   }
  }
 }
 if (nf==0)				/* scan stdin if no files given */
  return scan(stdin,"(stdin)");
 else
  return rc;
}

/*
* scan top level for function definitions
*  function bodies begin after "){" or ";{" or "va_dcl{"
*  function names occur at the last "i(" before "{"
* scan function bodies for function or macro calls
*  cannot tell function calls from function declarations inside bodies
*  treats all occurences of "i(" as function calls
* returns 1 if brace mismatch, 0 otherwise
*/

int
scan(FILE *f, char *filename)
{
 char *parent=strdup("(toplevel)");	/* function being scanned */
 int defline=0;				/* line where function name occured */
 int misline=0;				/* line where first mismatch occured */
 int inbody=0;				/* inside function body? */
 int p=0;				/* previous token */
 int n=0;				/* brace level */

 line=1;
 loop
 {
  int c=getc3(f);
  switch (c)
  {
   case '#':				/* possible macro definition */
   {
    char *last=estrdup(name);		/* save last name */
    macro(f,filename);
    if (last!=NULL)			/* restore last name */
    {
     strcpy(name,last);
     free(last);
    }
    continue;				/* pretend did not see pp line */
   }
   case '(':
    if (p=='i')
    {
     if (n==0)				/* possible function definition */	
     {
      free(parent);			/* remember function name and line */
      parent=estrdup(name);
      defline=idline;
     }
     else if (inbody)			/* function call */
      emit(parent,name,idline);
    }
    break;
   case 's':				/* synch point */
    --n;
    if (n!=0)
    {
     fprintf(stderr,"cgraph: synch at line %d in %s\n",line,filename);
     n=0;
    }
    inbody=0;
    break;
   case '}':
    --n;
    if (n==0)				/* end of body */
    {
     free(parent);
     parent=strdup("(toplevel)");	/* safeguard against syntax error */
     defline=line;
     inbody=0;
    }
    else if (n<0)			/* apparent brace mismatch */
    {
     if (synch)
     {
      fprintf(stderr,"cgraph: synch at line %d in %s\n",line,filename);
      n=0;
      inbody=0;
     }
     else if (misline==0) 		/* remember first mismatch only */
      misline=line;
    }
    break;
   case '{':
    if (n==0)				/* possible function body */	
    {
     if (p==')' || p==';' || (p=='i' && streq(name,"va_dcl")))
     {					/* ansi or k&r function definition */
      emit(parent,"-",defline);
      inbody=1;
     }
    }
    ++n;
    break;
   case EOF:
    if (n!=0 || misline!=0)		/* warn about apparent brace mismatch */
    {
     fprintf(stderr,"cgraph: apparent brace mismatch at ");
     if (misline==0)
      fprintf(stderr,"eof");
     else
      fprintf(stderr,"line %d",misline);
     fprintf(stderr," in %s%s\n",filename,
	synch ? "" : " -- try -synch");	/* do not make useless suggestion */
     return 1;
    }
    else
     return 0;
  }
  p=c;					/* remember previous token */
 }
}

/*
* scan preprocessor lines for macro definitions
* scan macro bodies for function or macro calls
* is confused by parameters being used as functions inside body
*  as in #define apply(f) f(x,y)
*/

void
macro(FILE *f, char *filename)
{
 char *parent;				/* macro name */
 int defline;				/* line where macro name occured */
 int p=0;				/* previous token */
 int c;

 c=getc4(f);
 if (c!='i' || strneq(name,"define"))	/* not #define */
  goto skip;
 c=getc4(f);
 if (c!='i')				/* not #define id */
  goto skip;
 defline=idline;			/* remember where defined */
 c=getc2(f);				/* whitespace significant here! */
 if (c!='(')				/* not #define id( */
  goto skip;
 parent=estrdup(name);			/* remember macro name */
 emit(parent,"-",defline);
 loop
 {
  c=getc4(f);
  switch (c)
  {
   case '(':				/* possible function call */
    if (p=='i')
     emit(parent,name,idline);
    break;
   case '\n':				/* end of macro body */
    free(parent);
    return;
  }
  p=c;					/* remember previous token */
 }
skip:
 while (c!='\n')			/* eat rest of line */
  c=getc4(f);
 return;
}

/*
* phase 4
* removal of whitespace for preprocessor lines
* keeps newlines and generates fake newline at eof
*/

int
getc4(FILE *f)
{
 loop
 {
  int c=getc2(f);
  switch (c)
  {
   case ' ':				/* remove whitespace */
   case '\t':
   case '\r':
   case '\f':
   case '\v':
    continue;
   case EOF:				/* safeguard against syntax error */
    return '\n';
   default:
    return c;
  }
 }
}

/*
* phase 3
* removal of whitespace
* recognizes '}' in the first column of a line for possible synch
*/

int
getc3(FILE *f)
{
 static int p=0;			/* previous token */
 loop
 {
  int c=getc2(f);
  switch (c)
  {
   case ' ':				/* remove whitespace */
   case '\t':
   case '\n':
   case '\r':
   case '\f':
   case '\v':
    p=c;				/* remember previous token */
    continue;
   case '}':				/* possible synch */
    if (p=='\n' && synch)
     c='s';
   default:
    p=c;				/* remember previous token */
    return c;
  }
 }
}

/*
* phase 2
* tokenization of comments, quoted text, identifiers and keywords
* replaces comments by space and quoted text by the quote
* replaces keywords by 'k' and identifiers by 'i'
* handles arbitrarily long identifiers
*/

int
getc2(FILE *f)
{
 int c=getc1(f);
 switch (c)
 {
  case '/':				/* opening comment? */
   c=getc1(f);
   if (c!='*')				/* no, recover */
   {
    ungetc1(c,f);
    return '/';
   }
   else					/* yes, replace comment by space */
   {
    int p;
    c=0;
    do
    {
     p=c;				/* remember previous token */
     c=getc1(f);
     if (c==EOF)			/* safeguard against syntax error */
      break;
    } while (c!='/' || p!='*');
    return ' ';
   }
  case '"':				/* quoted text */
  case '\'':
  {
   int q=c;
   do
   {
    if (c=='\\') getc1(f);		/* eat escape sequence */
    c=getc1(f);
    if (c==EOF)				/* safeguard against syntax error */
     break;
   } while (c!=q);
   return q;
  }
  default:
   if (iscsymf(c))			/* start of identifier */
   {
    static int len=32;			/* current max length of identifier */
    int i=0;
    idline=line;			/* remember line number */
    if (name==NULL)			/* first time */
     name=emalloc(len+1);
    do
    {
     if (i>=len)			/* identifier too long */
     {
      len *= 2;
      name=erealloc(name,len+1);
     }
     name[i++]=c;
     c=getc1(f);
     if (c==EOF)			/* safeguard against syntax error */
      break;
    } while (iscsym(c));
    name[i]=EOS;
    ungetc1(c,f);
    return reserved(name) ? 'k' : 'i';
   }
   return c;
 }
}

/*
* phase 1
* removal of <backslash> <newline>
* keeps tracks of line numbers
*/

inline
int
getc1(FILE *f)
{
 loop
 {
  int c=getc(f);
  switch (c)
  {
   case '\\':
    c=getc(f);
    if (c=='\n')
    {
     ++line;
     continue;
    }
    else
    {
     ungetc(c,f);
     return '\\';
    }
   case '\n':
    ++line;
   default:
    return c;
  }
 }
}

/*
* unget for phase 1
* keeps tracks of line numbers
*/

int
ungetc1(int c, FILE *f)
{
 if (c=='\n')
  --line;
 return ungetc(c,f);
}

/*
* sets of reserved keywords
*/

static char *knr[]=			/* k&r reserved words */
{
 "auto",
 "break",
 "case", "char", "continue",
 "default", "do", "double",
 "else", "enum", "extern",
 "float", "for",
 "goto",
 "if", "int",
 "long",
 "register", "return",
 "short", "sizeof", "static", "struct", "switch",
 "typedef",
 "union", "unsigned",
 "void",
 "while"
};

static char *ansi[]=			/* ansi reserved words */
{
 "auto",
 "break",
 "case", "char", "const", "continue",
 "default", "do", "double",
 "else", "enum", "extern",
 "float", "for",
 "goto",
 "if", "int",
 "long",
 "register", "return",
 "short", "signed", "sizeof", "static", "struct", "switch",
 "typedef",
 "union", "unsigned",
 "void", "volatile",
 "while"
};

static char *gcc[]=			/* gcc reserved words */
{
 "__alignof", "__alignof__",
 "__asm", "__asm__",
 "__const", "__const__",
 "__inline", "__inline__",
 "__signed", "__signed__",
 "__typeof", "__typeof__",
 "__volatile", "__volatile__",
 "asm", "auto",
 "break",
 "case", "char", "const", "continue",
 "default", "do", "double",
 "else", "enum", "extern",
 "float", "for",
 "goto",
 "if", "inline", "int",
 "long",
 "register", "return",
 "short", "signed", "sizeof", "static", "struct", "switch",
 "typedef", "typeof",
 "union", "unsigned",
 "void", "volatile",
 "while"
};

/*
* select reserved words
*/

static char **rw;			/* current set of reserved words */
static int nrw;				/* size of current set */

#define	SIZE(a)	  (sizeof(a)/sizeof(a[0]))

void
select(int choice)
{
 switch (choice)
 {
  case KNR:
   rw=knr;	nrw=SIZE(knr);
   break;
  case ANSI:
   rw=ansi;	nrw=SIZE(ansi);
   break;
  case GNU:
   rw=gcc;	nrw=SIZE(gcc);
   break;
 }
}

/*
* identify reserved words
*/

int
compare(char **a, char **b)
{
 return strcmp(*a,*b);
}

inline
int
reserved(char *s)			/* is reserved word? */
{
 return (bsearch(&s,rw,nrw,sizeof(rw[0]),compare)!=NULL);
}

/*
* strdup with error trapping
* same interface as strdup but dies if request cannot be honored
* handles NULL pointers gracefully
*/

char *
estrdup(char *s)
{
 return (s==NULL) ? NULL : strcpy(emalloc(strlen(s)+1),s);
}

/*
* malloc with error trapping
* same interface as malloc but dies if request cannot be honored
*/

void *
emalloc(size_t s)
{
 void *p=malloc(s);
 if (p==NULL)
 {
  fprintf(stderr,"cgraph: not enough memory\n");
  exit(1);
 }
 return p;
}

/*
* realloc with error trapping
* same interface as realloc but dies if request cannot be honored
*/

void *
erealloc(void *p, size_t s)
{
 p=realloc(p,s);
 if (p==NULL)
 {
  fprintf(stderr,"cgraph: not enough memory\n");
  exit(1);
 }
 return p;
}
