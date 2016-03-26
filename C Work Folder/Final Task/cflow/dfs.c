/*
* dfs.c
* perform rooted depth-first searches on directed graphs
* Luiz Henrique de Figueiredo (lhf@visgraf.impa.br)
* for the Free Software Foundation and the GNU effort
* 21 Nov 89
*/

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
* major data structures
* graphs are represented by adjacency lists
* vertices are kept in a hash table
* collisions are resolved by separate chaining
*/

typedef enum				/* name tags */
{
 UNDEF,					/* still undefined */
 DEF,					/* defined */
 SEEN,					/* already seen */
 LEAF,					/* defined with no children */
 HIDDEN					/* defined with hidden children */
} Tag;

typedef struct nnode Name;		/* name node */
typedef struct cnode Child;		/* child node */

typedef struct nnode			/* name node */
{
 char *name;
 char *comment;
 Tag tag;
 int def;				/* cross-reference definition */
 Child *fchild;				/* first child */
 Child *lchild;				/* last  child */
 Name *next;				/* next name */
};

typedef struct cnode			/* child node */
{
 char *comment;
 Name *child;				/* child name node */
 Child *next;				/* next child */
};

/*
* function declarations
*/

#define ALLOC(t)	((t *) emalloc(sizeof(t)))
#define streq(x,y)	(strcmp(x,y)==0)
#define strneq(x,y)	(strcmp(x,y)!=0)

void	*malloc		(size_t);
void	*realloc	(void *, size_t);
int	getopt		(int argc, char *argv[], char *optstr);

int	doopts		(int argc, char *argv[]);
void	usage		(void);
void	build		(char *fn);
int	getedge	(FILE *f, char **parent, char **child, char **comment);
Name	*addparent	(char *name, char *comment);
Name	*addchild	(char *name, Name *parent, char *comment);
Name	*addname	(char *name, char *comment);
int	findhead	(char *name);
Name	*findname	(char *name, int h);
Child	*findchild	(Name *child, Name *parent);
void	gdfs		(void);
int	dfs		(char *name);
void	rdfs		(Name *root);
void	showtree	(Name *parent, char *comment);
void	showname	(Name *parent, int level, char *comment);
char	*getl		(FILE *f);
FILE	*efopen		(char *fn, char *mode);
char	*estrdup	(char *s);
void	*emalloc	(size_t s);
void	*erealloc	(void *, size_t);
int	eatoi		(char *s);

/*
* global variables
*/

#define EOS	'\0'			/* end of string */
#define HEADS	101			/* a nice prime */

static Name *list[HEADS];		/* hash table */

static int depth=INT_MAX;		/* how far to go down the tree */
static int multiple=0;			/* allow multiple edges? */
static int numberall=0;			/* number all lines? */
static int reverse=0;			/* reverse to child-parent? */
static int showcomment=0;		/* show comments? */
static int showindent=0;		/* show indentation level? */
static int silent=0;			/* complain about missing names? */
static char *rootfile=NULL;		/* read roots from this file */
static char *graphfile=NULL;		/* read graph from this file */
static int names=0;			/* number of names read */ 

/*
* main control function
* reads graph from stdin or given file
* performs rooted dfs on names given on command line and/or file
* returns 0 on success, 1 on error
*/

int
main(int argc, char *argv[])
{
 int rc=0;				/* return code */
 {
  int optind=doopts(argc,argv);
  argc -= optind;
  argv += optind;
 }
 if (graphfile==NULL)			/* read graph from stdin */
  graphfile="-";
 build(graphfile);
 if (rootfile!=NULL)			/* read roots from file */
 {
  char *name;
  FILE *f=efopen(rootfile,"rt");
  while (name=getl(f))
   rc |= dfs(name);
  fclose(f);
 }
 else if (argc<1)			/* do global dfs if no names given */
 {
  silent=1;				/* try "main" first silently */
  dfs("main");
  gdfs();
 }
 for (; argc-->0; argv++)		/* do rooted dfs on remaining names */
  rc |= dfs(*argv);
 return rc;
}

/*
* print usage line and die
*/

void
usage(void)
{
 fprintf(stderr,"usage: dfs [-cimnrs] [-d depth] [-f rootfile] [-g graphfile] [root...]\n");
 exit(1);
}

/*
* parse command line options
* returns index of first unread argument
*/

int
doopts(int argc, char *argv[])
{
 extern int optind;
 extern int opterr;
 extern char *optarg;
 int c;
 opterr=1;				/* allow error messages from getopt */
 while ((c=getopt(argc,argv,"cd:f:g:imnrst")) != EOF)
 {
  switch (c)
  {
   case 'c':				/* show comments */
    showcomment=1;
    break;
   case 'd':				/* how far to go down the tree */
    depth=eatoi(optarg);
    break;
   case 'f':				/* read roots from file */
    if (rootfile!=NULL)
    {
     fprintf(stderr,"dfs: cannot handle more than 1 root file\n");
     exit(1);
    }
    rootfile=estrdup(optarg);
    break;
   case 'g':				/* read graph from file */
    if (graphfile!=NULL)
    {
     fprintf(stderr,"dfs: cannot handle more than 1 graph file\n");
     exit(1);
    }
    graphfile=estrdup(optarg);
    break;
   case 'i':				/* show indentation level */
    showindent=1;
    break;
   case 'm':				/* allow multiple edges */
    multiple=1;
    break;
   case 'n':				/* number all lines */
    numberall=1;
    break;
   case 'r':				/* reverse to child-parent */
    reverse=1;
    break;
   case 's':				/* complain about missing names */
    silent=1;
    break;
   default:				/* something wrong */
    usage();
  }
 }
 return optind;
}

/*
* build graph from file data
*/

void
build(char *fn)
{
 char *parent,*child,*comment;
 FILE *f=efopen(fn,"rt");
 while (getedge(f,&parent,&child,&comment))
 {
  if (parent!=NULL)
  {
   if (child!=NULL)
    addchild(child,addparent(parent,NULL),comment);
   else
    addparent(parent,comment);
  }
  else if (child!=NULL)
   addname(child,comment);
 }
 fclose(f);
}

/*
* get an edge from a graph file
* each line describes an edge and has the form
*	vertex-a	vertex-b	label (comment)
* these fields are separated by whitespace and are all optional
* if present, a comment extends to the end of the line (whitespace included)
* vertices equal to "-" are interpreted as absent
* whether the edge is from a to b or from b to a is controlled by reverse
* returns 1 on success, 0 on end of file
*/

int
getedge(FILE *f, char **parent, char **child, char **comment)
{
 static char delim[]=" \t\n\v\f";	/* fields delimited by white space */
 char *a,*b,*s;
 s=getl(f);
 if (s==NULL)				/* end of file */
  return 0;
 a=strtok(s,delim);	if (a!=NULL && streq(a,"-")) a=NULL;
 b=strtok(NULL,delim);	if (b!=NULL && streq(b,"-")) b=NULL;
 if (!showcomment)
  *comment=NULL;
 else
 {
  char *c=strtok(NULL,"");		/* remainder of line */
  if (c!=NULL)
   c+=strspn(c,delim);			/* skip leading white space */
  *comment=c;
 }
 if (reverse)				/* child-parent */
 {
  *child=a; *parent=b;
 }
 else					/* parent-child */
 {
  *parent=a; *child=b;
 }
 return 1;
}

/*
* add a parent to the name table
* returns its name node
*/

Name *
addparent(char *name, char *comment)
{
 Name *n=addname(name,comment);		/* install name */
 n->tag=DEF;				/* only parents are defined */
 return n;
}

/*
* add a child to a parent's list
* returns the child's name node
*/

Name *
addchild(char *name, Name *parent, char *comment)
{
 Name *n=addname(name,NULL);		/* install name */
 Child *c=findchild(n,parent);
 if (c==NULL || multiple)		/* new child or multiple edge */
 {
  c=ALLOC(Child);
  c->comment=estrdup(comment);		/* save comment */
  c->child=n;				/* link child node to end of list */
  c->next=NULL;
  if (parent->fchild==NULL)		/* first child */
   parent->fchild=parent->lchild=c;
  else
   parent->lchild=parent->lchild->next=c;
 }
 return n;
}

/*
* add a name to the name table
* names are added only once but comments can be added later
* returns the name node
*/

Name *
addname(char *name, char *comment)
{
 int h=findhead(name);
 Name *n=findname(name,h);
 if (n==NULL)				/* new name */
 {
  n=ALLOC(Name);
  n->name=estrdup(name);		/* save name */
  n->comment=estrdup(comment);		/* save comment */
  n->tag=UNDEF;				/* no definition yet */
  n->def=0;				/* no cross-reference yet */
  n->fchild=NULL;			/* no children yet */
  n->lchild=NULL;
  n->next=list[h];			/* link name node to head of list */
  list[h]=n;  
  names++;
 }
 else if (n->comment==NULL)		/* if old name had no comment */
  n->comment=estrdup(comment);		/* save comment */
 return n;
}

/*
* find the name list to which a name belongs
* computes a polynomial hash function using Horner's method
* uses unsigned arithmetic to avoid overflow and accidental sign modification
* returns an index into the hash table
*/

int
findhead(char *name)
{
 unsigned int h;
 for (h=0; *name!=EOS; name++)		/* interpret name as binary number */
 {
  h <<= 8;
  h  += (unsigned char) *name;		/* avoid sign extension */
  h  %= HEADS;				/* make it a valid index */
 }
 return h;
}

/*
* find a name in a name list
* returns the name node or NULL if not found
*/

Name *
findname(char *name, int h)
{
 Name *n;
 for (n=list[h]; (n!=NULL) && strneq(n->name,name); n=n->next)
  ;
 return n;
}

/*
* find a child in a parent's children list
* returns the child node or NULL if not found
*/

Child *
findchild(Name *child, Name *parent)
{
 Child *c;
 for (c=parent->fchild; (c!=NULL) && (c->child!=child); c=c->next)
  ;
 return c;
}

/*
* comparison function for qsort used in gdfs
*/

int
compare(Name **a, Name **b)
{
 return strcmp((*a)->name,(*b)->name);
}

/*
* global depth first search
* performs rooted dfs in alphabetical order of names
*/

void
gdfs(void)
{
 Name **a;				/* linear hash table */
 Name **b;
 int h;
 a=emalloc((names+1)*sizeof(Name *));	/* reserve space for sentinel */
 for (b=a,h=0; h<HEADS; h++)		/* flatten hash table */
 {
  Name *n;
  for (n=list[h]; n!=NULL; n=n->next, b++)
   *b=n;
 }
 *b=NULL;				/* add sentinel */
 qsort(a,names,sizeof(*a),compare);
 for (b=a; *b!=NULL; b++)
  rdfs(*b);
 free(a);
}

/*
* start depth first search at a given name
* returns 0 on success, 1 on error
*/

int
dfs(char *name)
{
 Name *p=findname(name,findhead(name));
 if (p!=NULL)
  rdfs(p);
 else if (!silent)
  fprintf(stderr,"dfs: cannot find %s\n",name);
 return (p!=NULL);
}

/*
* rooted depth first search
*/

void
rdfs(Name *root)
{
 showtree(root,root->comment);
}

/*
* print a rooted dfs tree
* prints children trees only once
*/

void
showtree(Name *parent, char *comment)
{
 static int level= -1;			/* recursion level */
 ++level;
 if (parent->tag==DEF && parent->fchild==NULL)
  parent->tag=LEAF;			/* names with no children are leaves */
 switch (parent->tag)
 {
  case UNDEF:				/* external name */
  case SEEN:				/* refer to previous definition */
  case LEAF:				/* name defined but has not children */
   showname(parent,level,comment);
   break;
  case DEF:				/* immediate definition */
   if (level>=depth)			/* cannot show children now */
   {
    parent->tag=HIDDEN;			/* hide children for now */
    showname(parent,level,comment);
    parent->tag=DEF;			/* but give it another chance */
   }
   else					/* can show children now */
   {
    Child *c;
    showname(parent,level,comment);
    parent->tag=SEEN;			/* for cross reference */
    for (c=parent->fchild; c!=NULL; c=c->next)
     showtree(c->child,c->comment);
   }
 }
 --level;
}

/*
* print an entry in the dfs tree at a given indentation level
* remember cross references
*/

void
showname(Name *name, int level, char *comment)
{
 static int def=0;			/* definition number */
 int i;
 if (name->tag==DEF)			/* number all definitions */
 {
  name->def= ++def;			/* remember where defined */
  printf("%d:",def);
 }
 else if (numberall)			/* number all lines */
 {
  ++def;
  printf("%d:",def);
 }
 putchar('\t');				/* align indentation */
 for (i=0; i<level; i++)		/* indent */
  putchar('\t');
 if (showindent)			/* show indentation level */
  printf("%d ",level);
 printf("%s",name->name);		/* show name */
 switch (name->tag)			/* show tag */
 {
  case UNDEF:				/* external name */
   putchar('*');
   break;
  case DEF:				/* immediate definition */
   putchar(':');
   break;
  case SEEN:				/* refer to previous definition */
   printf("=%d",name->def);
   break;
  case LEAF:				/* name defined but has no children */
   putchar('.');
   break;
  case HIDDEN:				/* name defined but cannot show children */
   putchar('+');
   break;
 }
 if (showcomment && comment!=NULL)	/* show comment */
  printf("\t%s",comment);
 putchar('\n');				/* finish line */
}

/*
* get arbitrarily long line from a file stream
* lines are terminated by newlines or eof (newlines are removed)
* returns address of static buffer or NULL on eof or error
*/

char *
getl(FILE *f)
{
 static char *buffer=NULL;
 static size_t size=BUFSIZ;
 int c;
 size_t i;
 if (buffer==NULL)			/* first time */
  buffer=emalloc(size);
 c=getc(f);
 if (c==EOF)				/* immediate EOF */
  return NULL;
 for (i=0; ; i++)
 {
  if (i>=size)				/* buffer full */
  {
   size*=2;
   buffer=erealloc(buffer,size);
  }
  if (c=='\n' || c==EOF)		/* end of line */
  {
   buffer[i]=EOS;
   return buffer;
  }
  buffer[i]=c;
  c=getc(f);
 }
}

/*
* fopen with error trapping
* same interface as fopen but dies if request cannot be honored
* "-" is taken to be stdin or stdout, depending on mode
*/

FILE *
efopen(char *fn, char *mode)
{
 FILE *f;
 if (streq(fn,"-"))
 {
  switch (*mode)
  {
   case 'r': f=stdin;	break;
   case 'w': f=stdout;	break;
   default:
    fprintf(stderr,"efopen: bad mode %s for -\n",mode);
    exit(1);
  }
 }
 else
 {
  f=fopen(fn,mode);
  if (f==NULL)
  {
   fprintf(stderr,"dfs: cannot open ");
   perror(fn);
   exit(1);
  }
 }
 return f;
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
  fprintf(stderr,"dfs: not enough memory\n");
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
  fprintf(stderr,"dfs: not enough memory\n");
  exit(1);
 }
 return p;
}

/*
* atoi with error trapping
* same interface as atoi but dies if string is invalid
*/

int
eatoi(char *s)
{
 char *last;
 long i=strtol(s,&last,10);
 if (i<0 || last==s || *last!=EOS)
 {
  fprintf(stderr,"dfs: invalid depth\n");
  exit(1);
 }
 return i;
}
