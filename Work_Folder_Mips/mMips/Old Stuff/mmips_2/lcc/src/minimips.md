%{
#define INTTMP 0x0100ff00	/* 8-15, 24 */
#define INTVAR 0x00ff0000	/* 16-23 */
#define INTRET 0x00000004	/* 2 */

#define readsreg(p) \
        (generic((p)->op)==INDIR && (p)->kids[0]->op==VREG+P)
#define setsrc(d) ((d) && (d)->x.regnode && \
        (d)->x.regnode->set == src->x.regnode->set && \
        (d)->x.regnode->mask&src->x.regnode->mask)

#define relink(a, b) ((b)->x.prev = (a), (a)->x.next = (b))

#include "c.h"
#define NODEPTR_TYPE Node
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->x.state)
static void address (Symbol, Symbol, long);
static void blkfetch (int, int, int, int);
static void blkloop (int, int, int, int, int, int[]);
static void blkstore (int, int, int, int);
static void defaddress (Symbol);
static void defconst (int, int, Value);
static void defstring (int, char *);
static void defsymbol (Symbol);
static void doarg (Node);
static void emit2 (Node);
static void export (Symbol);
static void clobber (Node);
static void function (Symbol, Symbol[], Symbol[], int);
static void global (Symbol);
static void import (Symbol);
static void local (Symbol);
static void progbeg (int, char **);
static void progend (void);
static void segment (int);
static void space (int);
static void target (Node);
static int mulops_calls(int op);
static int bitcount (unsigned);
static Symbol argreg (int, int, int, int, int);

static Symbol ireg[32];
static Symbol iregw;
static int tmpregs[] = { 3, 9, 10, 30 };
static Symbol blkreg;

static int cseg;
%}
%start stmt

%term CNSTF4=4113
%term CNSTI1=1045 
%term CNSTI4=4117
%term CNSTP4=4119
%term CNSTU1=1046 
%term CNSTU4=4118

%term ARGB=41
%term ARGF4=4129
%term ARGI4=4133
%term ARGP4=4135
%term ARGU4=4134

%term ASGNB=57
%term ASGNF4=4145
%term ASGNI1=1077 
%term ASGNI4=4149
%term ASGNP4=4151
%term ASGNU1=1078 
%term ASGNU4=4150

%term INDIRB=73
%term INDIRF4=4161
%term INDIRI1=1093 
%term INDIRI4=4165
%term INDIRP4=4167
%term INDIRU1=1094 
%term INDIRU4=4166

%term CVFF4=4209
%term CVFI4=4213

%term CVIF4=4225
%term CVII1=1157 
%term CVII4=4229
%term CVIU1=1158 
%term CVIU4=4230

%term CVPU4=4246

%term CVUI1=1205 
%term CVUI4=4277
%term CVUP4=4279
%term CVUU1=1206 
%term CVUU4=4278

%term NEGF4=4289
%term NEGI4=4293

%term CALLB=217
%term CALLF4=4305
%term CALLI4=4309
%term CALLP4=4311
%term CALLU4=4310
%term CALLV=216

%term RETF4=4337
%term RETI4=4341
%term RETP4=4343
%term RETU4=4342
%term RETV=248

%term ADDRGP4=4359

%term ADDRFP4=4375

%term ADDRLP4=4391

%term ADDF4=4401
%term ADDI4=4405
%term ADDP4=4407
%term ADDU4=4406

%term SUBF4=4417
%term SUBI4=4421
%term SUBP4=4423
%term SUBU4=4422

%term LSHI4=4437
%term LSHU4=4438

%term MODI4=4453
%term MODU4=4454

%term RSHI4=4469
%term RSHU4=4470

%term BANDI4=4485
%term BANDU4=4486

%term BCOMI4=4501
%term BCOMU4=4502

%term BORI4=4517
%term BORU4=4518

%term BXORI4=4533
%term BXORU4=4534

%term DIVF4=4545
%term DIVI4=4549
%term DIVU4=4550

%term MULF4=4561
%term MULI4=4565
%term MULU4=4566

%term EQF4=4577
%term EQI4=4581
%term EQU4=4582

%term GEF4=4593
%term GEI4=4597
%term GEU4=4598

%term GTF4=4609
%term GTI4=4613
%term GTU4=4614

%term LEF4=4625
%term LEI4=4629
%term LEU4=4630

%term LTF4=4641
%term LTI4=4645
%term LTU4=4646

%term NEF4=4657
%term NEI4=4661
%term NEU4=4662

%term JUMPV=584

%term LABELV=600
%term LOADB=233
%term LOADF4=4321
%term LOADF8=8417
%term LOADF16=16609
%term LOADI1=1253
%term LOADI2=2277
%term LOADI4=4325
%term LOADI8=8421
%term LOADP4=4327
%term LOADP8=8423
%term LOADU1=1254
%term LOADU2=2278
%term LOADU4=4326
%term LOADU8=8422

%term VREGP=711

%%

reg:  INDIRI1(VREGP)    "# read register\n"
reg:  INDIRU1(VREGP)    "# read register\n"
reg:  INDIRF4(VREGP)    "# read register\n"
reg:  INDIRI4(VREGP)    "# read register\n"
reg:  INDIRP4(VREGP)    "# read register\n"
reg:  INDIRU4(VREGP)    "# read register\n"

stmt: ASGNI1(VREGP,reg) "# write register\n"
stmt: ASGNU1(VREGP,reg) "# write register\n"
stmt: ASGNF4(VREGP,reg) "# write register\n"
stmt: ASGNI4(VREGP,reg) "# write register\n"
stmt: ASGNP4(VREGP,reg) "# write register\n"
stmt: ASGNU4(VREGP,reg) "# write register\n"

con: CNSTI1  		"%a"
con: CNSTU1  		"%a"
con: CNSTI4  		"%a"
con: CNSTU4  		"%a"
con: CNSTP4  		"%a"

stmt: reg  		""
acon: con     		"%0"
acon: ADDRGP4  		"%a"
addr: ADDI4(reg,acon)  	"%1($%0)"
addr: ADDU4(reg,acon)  	"%1($%0)"
addr: ADDP4(reg,acon)  	"%1($%0)"
addr: acon  		"%0"
addr: reg   		"($%0)"
addr: ADDRFP4  		"%a+%F($sp)"
addr: ADDRLP4  		"%a+%F($sp)"
reg: addr  		"\tla $%c,%0\n"  1
reg: CNSTI1  		"# reg\n"  range(a, 0, 0)
reg: CNSTI4  		"# reg\n"  range(a, 0, 0)
reg: CNSTU1  		"# reg\n"  range(a, 0, 0)
reg: CNSTU4  		"# reg\n"  range(a, 0, 0)
reg: CNSTP4  		"# reg\n"  range(a, 0, 0)
reg: CNSTF4  		"# reg\n"  range(a, 0, 0)
stmt: ASGNI1(addr,reg)  "\tsb $%1,%0\n"  1
stmt: ASGNU1(addr,reg)  "\tsb $%1,%0\n"  1
stmt: ASGNI4(addr,reg)  "\tsw $%1,%0\n"  1
stmt: ASGNU4(addr,reg)  "\tsw $%1,%0\n"  1
stmt: ASGNP4(addr,reg)  "\tsw $%1,%0\n"  1
reg:  INDIRI1(addr)     "\tlb $%c,%0\n"  1
reg:  INDIRU1(addr)     "\tlb $%c,%0; and $%c,$%c,255\n" 2
reg:  INDIRI4(addr)     "\tlw $%c,%0\n"  1
reg:  INDIRU4(addr)     "\tlw $%c,%0\n"  1
reg:  INDIRP4(addr)     "\tlw $%c,%0\n"  1

reg:  CVII4(INDIRI1(addr))     "\tlb $%c,%0\n"  1
reg:  CVUU4(INDIRU1(addr))     "\tlb $%c,%0; and $%c,$%c,255\n" 2 
reg:  CVUI4(INDIRU1(addr))     "\tlb $%c,%0; and $%c,$%c,255\n" 2 
reg:  INDIRF4(addr)     "\tlw $%c,%0\n"  1
stmt: ASGNF4(addr,reg)  "\tsw $%1,%0\n"  1
reg: DIVI4(reg,reg)  	"\tjal __div\n"   100
reg: DIVU4(reg,reg)  	"\tjal __divu\n"  100
reg: MODI4(reg,reg)  	"\tjal __mod\n"   100
reg: MODU4(reg,reg)  	"\tjal __modu\n"  100
reg: MULI4(reg,reg)     "\tmul $%c,$%0,$%1\n"   1
reg: MULU4(reg,reg)     "\tmul $%c,$%0,$%1\n"   1
rc:  con            	"%0"
rc:  reg            	"$%0"

reg: ADDI4(reg,rc)   	"\taddu $%c,$%0,%1\n"  1
reg: ADDP4(reg,rc)   	"\taddu $%c,$%0,%1\n"  1
reg: ADDU4(reg,rc)   	"\taddu $%c,$%0,%1\n"  1
reg: BANDI4(reg,rc)  	"\tand $%c,$%0,%1\n"   1
reg: BORI4(reg,rc)   	"\tor $%c,$%0,%1\n"    1
reg: BXORI4(reg,rc)  	"\txor $%c,$%0,%1\n"   1
reg: BANDU4(reg,rc)  	"\tand $%c,$%0,%1\n"   1
reg: BORU4(reg,rc)   	"\tor $%c,$%0,%1\n"    1
reg: BXORU4(reg,rc)  	"\txor $%c,$%0,%1\n"   1
reg: SUBI4(reg,rc)   	"\tsubu $%c,$%0,%1\n"  1
reg: SUBP4(reg,rc)   	"\tsubu $%c,$%0,%1\n"  1
reg: SUBU4(reg,rc)   	"\tsubu $%c,$%0,%1\n"  1

reg: LSHI4(reg,CNSTI4) 	"# sll\n"  4
reg: LSHU4(reg,CNSTI4) 	"# sll\n"  4
reg: RSHI4(reg,CNSTI4) 	"# sra\n"  4
reg: RSHU4(reg,CNSTI4) 	"# srl\n"  4
reg: LSHI4(reg,reg)  	"\tjal __sll\n"  100
reg: LSHU4(reg,reg)  	"\tjal __sll\n"  100
reg: RSHI4(reg,reg)  	"\tjal __sra\n"  100
reg: RSHU4(reg,reg)  	"\tjal __srl\n"  100
reg: BCOMI4(reg)  	"\tli $30, -1; xor $%c,$%0,$30\n"   1
reg: BCOMU4(reg)  	"\tli $30, -1; xor $%c,$%0,$30\n"   1
reg: NEGI4(reg)   	"\tnegu $%c,$%0\n"  1
reg: LOADI1(reg)  	"\tmove $%c,$%0\n"  move(a)
reg: LOADU1(reg)  	"\tmove $%c,$%0\n"  move(a)
reg: LOADI4(reg)  	"\tmove $%c,$%0\n"  move(a)
reg: LOADP4(reg)  	"\tmove $%c,$%0\n"  move(a)
reg: LOADU4(reg)  	"\tmove $%c,$%0\n"  move(a)
reg: LOADF4(reg)     	"\tmove $%c,$%0\n"  move(a)
reg: ADDF4(reg,reg)  	"\tjal float32_add\n" 100
reg: SUBF4(reg,reg)  	"\tjal float32_sub\n" 100
reg: MULF4(reg,reg)  	"\tjal float32_mul\n" 100
reg: DIVF4(reg,reg)  	"\tjal float32_div\n" 100
reg: NEGF4(reg)      	"\tjal float32_neg\n" 100
reg: CVII4(reg)  	"\tsb $%0,CVII4_int; lb $%c,CVII4_int\n"  2
reg: CVUI4(reg)  	"\tand $%c,$%0,255\n"  1
reg: CVUU4(reg)  	"\tand $%c,$%0,255\n"  1
reg: CVFF4(reg)  	"\t???" 100
reg: CVIF4(reg)  	"\tjal int32_to_float32\n" 100
reg: CVFI4(reg)  	"\tjal float32_to_int32_round_to_zero\n" 100
stmt: LABELV  		"%a:\n"
stmt: JUMPV(acon)  	"\tb %0\n"   1
stmt: JUMPV(reg)   	"\tj $%0\n"  1

stmt: EQI4(reg,reg)  	"\tbeq $%0,$%1,%a\n"   1
stmt: EQU4(reg,reg)  	"\tbeq $%0,$%1,%a\n"   1
stmt: NEI4(reg,reg)  	"\tbne $%0,$%1,%a\n"   1
stmt: NEU4(reg,reg)  	"\tbne $%0,$%1,%a\n"   1

stmt: LTI4(reg,reg)     "\tslt $30,$%0,$%1\n\tbne $30,$0,%a\n"   2
stmt: LTU4(reg,reg)     "\tsltu $30,$%0,$%1\n\tbne $30,$0,%a\n"  2
stmt: GTI4(reg,reg)     "\tslt $30,$%1,$%0\n\tbne $30,$0,%a\n"   2
stmt: GTU4(reg,reg)     "\tsltu $30,$%1,$%0\n\tbne $30,$0,%a\n"  2
stmt: GEI4(reg,reg)     "\tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n"   2
stmt: GEU4(reg,reg)     "\tsltu $30,$%0,$%1\n\tbeq $30,$0,%a\n"  2
stmt: LEI4(reg,reg)     "\tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n"   2
stmt: LEU4(reg,reg)     "\tsltu $30,$%1,$%0\n\tbeq $30,$0,%a\n"  2 

stmt: EQF4(reg,reg)  	"\tbeq $%0,$%1,%a\n" 1
stmt: NEF4(reg,reg)  	"\tbne $%0,$%1,%a\n" 1

stmt: LEF4(reg,reg)  	"\tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n"   2
stmt: LTF4(reg,reg)  	"\tslt $30,$%0,$%1\n\tbne $30,$0,%a\n"   2
stmt: GEF4(reg,reg)  	"\tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n"   2
stmt: GTF4(reg,reg)  	"\tslt $30,$%1,$%0\n\tbne $30,$0,%a\n"   2

reg:  CALLF4(ar)  	"\tjal %0\n"  1
reg:  CALLI4(ar)  	"\tjal %0\n"  1
reg:  CALLP4(ar)  	"\tjal %0\n"  1
reg:  CALLU4(ar)  	"\tjal %0\n"  1
stmt: CALLV(ar)  	"\tjal %0\n"  1
ar: reg    		"$%0"
ar: CNSTP4  		"%a"   range(a, 0, 0x0fffffff)
ar: ADDRGP4     	"%a"

magic_addr: CNSTP4 	"%a"   is_magic_addr(a)
reg: ADDI4(reg, ADDI4(reg, INDIRI4(magic_addr))) 	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x30\n"
reg: SUBI4(reg, ADDI4(reg, INDIRI4(magic_addr))) 	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x31\n"
reg: ADDI4(reg, SUBI4(reg, INDIRI4(magic_addr))) 	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x32\n"
reg: SUBI4(reg, SUBI4(reg, INDIRI4(magic_addr))) 	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x33\n"

reg: SUBI4(reg, SUBI4(reg, ADDI4(reg, INDIRI4(magic_addr)))) "\t.word (%c<<11)|(%2<<21)|(%2<<16)|0x35\n \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x34\n"

stmt: RETF4(reg)  	"# ret\n"  1
stmt: RETI4(reg)  	"# ret\n"  1
stmt: RETU4(reg)  	"# ret\n"  1
stmt: RETP4(reg)  	"# ret\n"  1
stmt: RETV(reg)   	"# ret\n"  1
stmt: ARGF4(reg)  	"# arg\n"  1
stmt: ARGI4(reg)  	"# arg\n"  1
stmt: ARGP4(reg)  	"# arg\n"  1
stmt: ARGU4(reg)  	"# arg\n"  1

stmt: ARGB(INDIRB(reg))       "# argb %0\n"      1
stmt: ASGNB(reg,INDIRB(reg))  "# asgnb %0 %1\n"  1

%%
int
is_magic_addr (Node p)
{
  return (int) p->syms[0]->u.c.v.p == 0x12344321 ? 0 : LBURG_MAX;
}

static void
progend (void)
{
}

static void
progbeg (int argc, char *argv[])
{
  int i;

  union
  {
    char c;
    int i;
  }
  u;

  u.i = 0;
  u.c = 1;
  swap = ((int) (u.i == 1)) != IR->little_endian;

  print ("\t.set reorder\n");
  parseflags (argc, argv);
  for (i = 0; i < 32; i++)
    ireg[i] = mkreg ("%d", i, 1, IREG);
  ireg[29]->x.name = "sp";
  iregw = mkwildcard (ireg);
  tmask[IREG] = INTTMP;
  vmask[IREG] = INTVAR;
  blkreg = mkreg ("8", 8, 7, IREG);
}

static Symbol
rmap (int opk)
{
  switch (optype (opk))
    {
    case I:
    case U:
    case P:
    case B:
    case F:
      return iregw;
    default:
      return 0;
    }
}

static void
target (Node p)
{
  assert (p);
  switch (specific (p->op))
    {
    case DIV + I:
    case MOD + I:
    case MUL + I:
    case DIV + U:
    case MOD + U:
    case MUL + U:
    case DIV + F:
    case MOD + F:
    case MUL + F:
    case ADD + F:
    case SUB + F:
      setreg (p, ireg[2]);
      rtarget (p, 0, ireg[4]);
      rtarget (p, 1, ireg[5]);
      break;
    case NEG + F:
    case CVI + F:
    case CVF + I:
      setreg (p, ireg[2]);
      rtarget (p, 0, ireg[4]);
      break;
    case LSH + I:
    case LSH + U:
    case RSH + I:
    case RSH + U:
      if (generic (p->kids[1]->op) != CNST)
	{
	  setreg (p, ireg[2]);
	  rtarget (p, 0, ireg[4]);
	  rtarget (p, 1, ireg[5]);
	}
      break;
    case CNST + I:
    case CNST + U:
    case CNST + P:
      if (range (p, 0, 0) == 0)
	{
	  setreg (p, ireg[0]);
	  p->x.registered = 1;
	}
      break;
    case CALL + V:
      rtarget (p, 0, ireg[25]);
      break;
    case CALL + I:
    case CALL + P:
    case CALL + U:
    case CALL + F:
      rtarget (p, 0, ireg[25]);
      setreg (p, ireg[2]);
      break;
    case RET + I:
    case RET + U:
    case RET + P:
    case RET + F:
      rtarget (p, 0, ireg[2]);
      break;
    case ARG + F:
    case ARG + I:
    case ARG + P:
    case ARG + U:
      {
	static int ty0;
	int ty = optype (p->op);
	Symbol q;

	q = argreg (p->x.argno, p->syms[2]->u.c.v.i, ty, opsize (p->op), ty0);
	if (p->x.argno == 0)
	  ty0 = ty;
	if (q)
	  rtarget (p, 0, q);
	break;
      }
    case ASGN + B:
      rtarget (p->kids[1], 0, blkreg);
      break;
    }
}

static void
clobber (Node p)
{
  assert (p);
  switch (specific (p->op))
    {
    case CALL + I:
    case CALL + P:
    case CALL + U:
    case CALL + F:
    case ADD + F:
    case SUB + F:
    case NEG + F:
    case DIV + F:
    case MOD + F:
    case MUL + F:
    case DIV + I:
    case DIV + U:
    case MOD + I:
    case MOD + U:
    case MUL + I:
    case MUL + U:
    case CVI + F:
    case CVF + I:
      spill (INTTMP, IREG, p);
      break;
    case RSH + I:
    case LSH + I:
    case RSH + U:
    case LSH + U:
      if (generic (p->kids[1]->op) != CNST)
	spill (INTTMP, IREG, p);
      break;
    case CALL + V:
      spill (INTTMP | INTRET, IREG, p);
      break;
    }
}

static void
emit2shift (Node p, char *shift_opcode)
{
  int distance = p->kids[1]->syms[0]->u.c.v.i & 31;
  int src = getregnum (p->x.kids[0]);
  int dst = getregnum (p);

  if (distance == 0)
    print ("\tmove $%d, $%d\n", dst, src);
  else
    {
      if (distance & 1)
	{
	  print ("\t%s $%d, $%d, 1\n", shift_opcode, dst, src);
	  src = dst;
	}
      if (distance & 2)
	{
	  print ("\t%s $%d, $%d, 2\n", shift_opcode, dst, src);
	  src = dst;
	}
      if (distance & 4)
	{
	  print ("\t%s $%d, $%d, 2\n", shift_opcode, dst, src);
	  print ("\t%s $%d, $%d, 2\n", shift_opcode, dst, dst);
	  src = dst;
	}
      if (distance & 8)
	{
	  print ("\t%s $%d, $%d, 8\n", shift_opcode, dst, src);
	  src = dst;
	}
      if (distance & 16)
	{
	  print ("\t%s $%d, $%d, 8\n", shift_opcode, dst, src);
	  print ("\t%s $%d, $%d, 8\n", shift_opcode, dst, dst);
	  src = dst;
	}
    }
}

static void
emit2 (Node p)
{
  int src, sz, ty;
  static int ty0;
  Symbol q;

  switch (specific (p->op))
    {
    case ARG + F:
    case ARG + I:
    case ARG + P:
    case ARG + U:
      ty = optype (p->op);
      sz = opsize (p->op);
      if (p->x.argno == 0)
	ty0 = ty;
      q = argreg (p->x.argno, p->syms[2]->u.c.v.i, ty, sz, ty0);
      src = getregnum (p->x.kids[0]);
      if (q == NULL)
	print ("\tsw $%d,%d($sp)\n", src, p->syms[2]->u.c.v.i);
      break;
    case ASGN + B:
      dalign = salign = p->syms[1]->u.c.v.i;
      blkcopy (getregnum (p->x.kids[0]), 0,
	       getregnum (p->x.kids[1]), 0, p->syms[0]->u.c.v.i, tmpregs);
      break;
    case LSH + I:
    case LSH + U:
      emit2shift (p, "sll");
      break;
    case RSH + I:
      emit2shift (p, "sra");
      break;
    case RSH + U:
      emit2shift (p, "srl");
      break;
    }
}

static Symbol
argreg (int argno, int offset, int ty, int sz, int ty0)
{
  assert ((offset & 3) == 0);

  if (offset > 12)
    return NULL;
  else
    return ireg[(offset / 4) + 4];
}

static void
doarg (Node p)
{
  static int argno;
  int align;

  if (argoffset == 0)
    argno = 0;
  p->x.argno = argno++;
  align = p->syms[1]->u.c.v.i < 4 ? 4 : p->syms[1]->u.c.v.i;
  p->syms[2] = intconst (mkactual (align, p->syms[0]->u.c.v.i));
}

static void
local (Symbol p)
{
  if (askregvar (p, rmap (ttob (p->type))) == 0)
    mkauto (p);
}

static void
function (Symbol f, Symbol caller[], Symbol callee[], int ncalls)
{
  int i, saved, sizeisave, varargs;
  Symbol r, argregs[4];

  usedmask[0] = usedmask[1] = 0;
  freemask[0] = freemask[1] = ~(unsigned) 0;
  offset = maxoffset = maxargoffset = 0;
  for (i = 0; callee[i]; i++)
    ;
  varargs = variadic (f->type)
    || i > 0 && strcmp (callee[i - 1]->name, "va_alist") == 0;
  for (i = 0; callee[i]; i++)
    {
      Symbol p = callee[i];
      Symbol q = caller[i];
      assert (q);
      offset = roundup (offset, q->type->align);
      p->x.offset = q->x.offset = offset;
      p->x.name = q->x.name = stringd (offset);
      r = argreg (i, offset, optype (ttob (q->type)), q->type->size,
		  optype (ttob (caller[0]->type)));
      if (i < 4)
	argregs[i] = r;
      offset = roundup (offset + q->type->size, 4);
      if (varargs)
	p->sclass = AUTO;
      else if (r && ncalls == 0 &&
	       !isstruct (q->type) && !p->addressed &&
	       !(isfloat (q->type) && r->x.regnode->set == IREG))
	{
	  p->sclass = q->sclass = REGISTER;
	  askregvar (p, r);
	  assert (p->x.regnode && p->x.regnode->vbl == p);
	  q->x = p->x;
	  q->type = p->type;
	}
      else if (askregvar (p, rmap (ttob (p->type)))
	       && r != NULL && (isint (p->type) || p->type == q->type))
	{
	  assert (q->sclass != REGISTER);
	  p->sclass = q->sclass = REGISTER;
	  q->type = p->type;
	}
    }
  assert (!caller[i]);
  offset = 0;
  gencode (caller, callee);
  if (ncalls)
    usedmask[IREG] |= ((unsigned) 1) << 31;
  usedmask[IREG] &= 0xc0ff0000;
  maxargoffset = roundup (maxargoffset, 4);
  if (ncalls && maxargoffset < 16)
    maxargoffset = 16;
  sizeisave = 4 * bitcount (usedmask[IREG]);
  framesize = roundup (maxargoffset + sizeisave + maxoffset, 8);
  segment (CODE);
  print ("\t.align 2\n");
  print ("\t.ent %s\n", f->x.name);
  print ("%s:\n", f->x.name);
  i = maxargoffset - framesize;
  print ("\t.frame $sp,%d,$31\n", framesize);
  if (framesize > 0)
    print ("\taddu $sp,$sp,%d\n", -framesize);
  if (usedmask[IREG])
    print ("\t.mask 0x%x,%d\n", usedmask[IREG], i + sizeisave - 4);
  saved = maxargoffset;

  for (i = 16; i <= 31; i++)
    if (usedmask[IREG] & (1 << i))
      {
	print ("\tsw $%d,%d($sp)\n", i, saved);
	saved += 4;
      }
  for (i = 0; i < 4 && callee[i]; i++)
    {
      r = argregs[i];
      if (r && r->x.regnode != callee[i]->x.regnode)
	{
	  Symbol out = callee[i];
	  Symbol in = caller[i];
	  int rn = r->x.regnode->number;

	  assert (out && in && r && r->x.regnode);
	  assert (out->sclass != REGISTER || out->x.regnode);
	  if (out->sclass == REGISTER
	      && (isint (out->type) || out->type == in->type))
	    {
	      int outn = out->x.regnode->number;
	      print ("\tmove $%d,$%d\n", outn, rn);
	    }
	  else
	    {
	      int off = in->x.offset + framesize;
	      {
		int i, n = (in->type->size + 3) / 4;
		for (i = rn; i < rn + n && i <= 7; i++)
		  print ("\tsw $%d,%d($sp)\n", i, off + (i - rn) * 4);
	      }
	    }
	}
    }
  if (varargs && callee[i - 1])
    {
      i = callee[i - 1]->x.offset + callee[i - 1]->type->size;
      for (i = roundup (i, 4) / 4; i <= 3; i++)
	print ("\tsw $%d,%d($sp)\n", i + 4, framesize + 4 * i);
    }
  emitcode ();
  saved = maxargoffset;
  for (i = 16; i <= 31; i++)
    if (usedmask[IREG] & (1 << i))
      {
	print ("\tlw $%d,%d($sp)\n", i, saved);
	saved += 4;
      }
  if (framesize > 0)
    print ("\taddu $sp,$sp,%d\n", framesize);
  print ("\tj $31\n");
  print ("\t.end %s\n", f->x.name);
}

static void
defconst (int suffix, int size, Value v)
{
  if (suffix == F)
    {
      float f = v.d;
      print ("\t.word 0x%x\n", *(unsigned *) &f);
    }
  else if (suffix == P)
    print ("\t.word 0x%x\n", v.p);
  else if (size == 1)
    print ("\t.byte 0x%x\n", suffix == I ? v.i : v.u);
  else if (size == 2)
    print ("\t.half 0x%x\n", suffix == I ? v.i : v.u);
  else if (size == 4)
    print ("\t.word 0x%x\n", suffix == I ? v.i : v.u);
}

static void
defaddress (Symbol p)
{
  print ("\t.word %s\n", p->x.name);
}

static void
defstring (int n, char *str)
{
  int i;

  for (i = 0; i < n / 4; i++)
  {
    print ("\t.byte %d\n", str[(i << 2) + 3] & 0377);
    print ("\t.byte %d\n", str[(i << 2) + 2] & 0377);
    print ("\t.byte %d\n", str[(i << 2) + 1] & 0377);
    print ("\t.byte %d\n", str[(i << 2) + 0] & 0377);
  }

  i = n - 4*(n/4);
 
  if (i == 3)
  {
    print ("\t.byte 0\n");
    print ("\t.byte %d\n", str[4*(n/4) + 2] & 0377);
    print ("\t.byte %d\n", str[4*(n/4) + 1] & 0377);
    print ("\t.byte %d\n", str[4*(n/4) + 0] & 0377);
  }
  else if (i == 2)
  {
    print ("\t.byte 0\n");
    print ("\t.byte 0\n");
    print ("\t.byte %d\n", str[4*(n/4) + 1] & 0377);
    print ("\t.byte %d\n", str[4*(n/4) + 0] & 0377);
  }
  else if (i == 1)
  {
    print ("\t.byte 0\n");
    print ("\t.byte 0\n");
    print ("\t.byte 0\n");
    print ("\t.byte %d\n", str[4*(n/4) + 0] & 0377);
  }

/*
  char *s;

  for (s = str; s < str + n; s++)
    print ("\t.byte %d\n", (*s) & 0377);
*/
}

static void
export (Symbol p)
{
  print ("\t.globl %s\n", p->x.name);
}

static void
import (Symbol p)
{
  if (!isfunc (p->type))
    print ("\t.extern %s %d\n", p->name, p->type->size);
}

static void
defsymbol (Symbol p)
{
  if (p->scope >= LOCAL && p->sclass == STATIC)
    p->x.name = stringf ("L.%d", genlabel (1));
  else if (p->generated)
    p->x.name = stringf ("L.%s", p->name);
  else
    assert (p->scope != CONSTANTS || isint (p->type) || isptr (p->type)),
      p->x.name = p->name;
}

static void
address (Symbol q, Symbol p, long n)
{
  if (p->scope == GLOBAL || p->sclass == STATIC || p->sclass == EXTERN)
    q->x.name = stringf ("%s%s%D", p->x.name, n >= 0 ? "+" : "", n);
  else
    {
      assert (n <= INT_MAX && n >= INT_MIN);
      q->x.offset = p->x.offset + n;
      q->x.name = stringd (q->x.offset);
    }
}

static void global (Symbol p)
{
  if (p->u.seg == BSS)
    {
      if (p->sclass == STATIC || Aflag >= 2)
	print ("\t.lcomm %s,%d\n", p->x.name, p->type->size);
      else
	print ("\t.comm %s,%d\n", p->x.name, p->type->size);
    }
  else
    {
      print ("\t.data\n");
      print ("\t.align %c\n", ".01.2...3"[p->type->align]);
      print ("%s:\n", p->x.name);
    }
}

static void
segment (int n)
{
  cseg = n;
  switch (n)
    {
    case CODE:
      print ("\t.text\n");
      break;
    case LIT:
      print ("\t.rdata\n");
      break;
    }
}

static void
space (int n)
{
  if (cseg != BSS)
    print ("\t.space %d\n", n);
}

static void
blkloop (int dreg, int doff, int sreg, int soff, int size, int tmps[])
{
  int lab = genlabel (1);

  print ("\taddu $%d,$%d,%d\n", sreg, sreg, size & ~7);
  print ("\taddu $%d,$%d,%d\n", tmps[2], dreg, size & ~7);
  blkcopy (tmps[2], doff, sreg, soff, size & 7, tmps);
  print ("L.%d:\n", lab);
  print ("\taddu $%d,$%d,%d\n", sreg, sreg, -8);
  print ("\taddu $%d,$%d,%d\n", tmps[2], tmps[2], -8);
  blkcopy (tmps[2], doff, sreg, soff, 8, tmps);
  print ("\tbltu $%d,$%d,L.%d\n", dreg, tmps[2], lab);
}

static void
blkfetch (int size, int off, int reg, int tmp)
{
  assert (size == 1 || size == 2 || size == 4);
  assert (tmp != reg);

  if (size == 1)
    print ("\tlb $%d,%d($%d)\n", tmp, off, reg);
  else if (size == 2)
    {
      print ("\tlb $%d,%d($%d)\n", tmp, off + 1, reg);
      print ("\tsll $%d,$%d,8\n", tmp, tmp);
      print ("\tlb $%d,%d($%d)\n", 30, off + 0, reg);
      print ("\tor $%d,$%d,$%d\n", tmp, tmp, 30);
    }
  else
    {
      if (salign >= size)
	print ("\tlw $%d,%d($%d)\n", tmp, off, reg);
      else
	{
	  print ("\tlb $%d,%d($%d)\n", tmp, off + 3, reg);
	  print ("\tsll $%d,$%d,8\n", tmp, tmp);
	  print ("\tlb $%d,%d($%d)\n", 30, off + 2, reg);
	  print ("\tor $%d,$%d,$%d\n", tmp, tmp, 30);
	  print ("\tsll $%d,$%d,8\n", tmp, tmp);
	  print ("\tlb $%d,%d($%d)\n", 30, off + 1, reg);
	  print ("\tor $%d,$%d,$%d\n", tmp, tmp, 30);
	  print ("\tsll $%d,$%d,8\n", tmp, tmp);
	  print ("\tlb $%d,%d($%d)\n", 30, off + 0, reg);
	  print ("\tor $%d,$%d,$%d\n", tmp, tmp, 30);
	}
    }
}

static void
blkstore (int size, int off, int reg, int tmp)
{
  assert (size == 1 || size == 2 || size == 4);
  assert (tmp != reg);

  if (size == 1)
    print ("\tsb $%d,%d($%d)\n", tmp, off, reg);
  else if (size == 2)
    {
      print ("\tsb $%d,%d($%d)\n", tmp, off, reg);
      print ("\tsrl $%d,$%d,8\n", 30, tmp);
      print ("\tsb $%d,%d($%d)\n", 30, off + 1, reg);
    }
  else
    {
      if (dalign >= size)
	print ("sw $%d,%d($%d)\n", tmp, off, reg);
      else
	{
	  print ("\tsb $%d,%d($%d)\n", tmp, off, reg);
	  print ("\tsrl $%d,$%d,8\n", 30, tmp);
	  print ("\tsb $%d,%d($%d)\n", 30, off + 1, reg);
	  print ("\tsrl $%d,$%d,8\n", 30, 30);
	  print ("\tsb $%d,%d($%d)\n", 30, off + 2, reg);
	  print ("\tsrl $%d,$%d,8\n", 30, 30);
	  print ("\tsb $%d,%d($%d)\n", 30, off + 3, reg);
	}
    }
}

static int
bitcount (unsigned mask)
{
  unsigned i, n = 0;

  for (i = 1; i; i <<= 1)
    if (mask & i)
      n++;
  return n;
}

static int
mulops_calls (int op)
{
  if (generic (op) == DIV || generic (op) == MOD || generic (op) == MUL)
    return 1;

  if (generic (op) == LSH || generic (op) == RSH)
    return 1;

  if ((generic (op) == ADD || generic (op) == SUB) && optype (op) == F)
    return 1;

  if (generic (op) == NEG && optype (op) == F)
    return 1;

  if (generic (op) == CVI && optype (op) == F)
    return 1;

  if (generic (op) == CVF && optype (op) == I)
    return 1;

  return 0;
}

Interface minimipsIR = {
  1, 1, 0,			/* char */
  4, 4, 0,			/* short */
  4, 4, 0,			/* int */
  4, 4, 0,			/* long */
  4, 4, 0,			/* long long */
  4, 4, 1,			/* float */
  4, 4, 1,			/* double */
  4, 4, 1,			/* long double */
  4, 4, 0,			/* T * */
  0, 1, 0,			/* struct */
  0,				/* little_endian */
  mulops_calls,			/* mulops_calls */
  0,				/* wants_callb */
  0,				/* wants_argb */
  1,				/* left_to_right */
  0,				/* wants_dag */
  0,				/* unsigned_char */
  address,
  blockbeg,
  blockend,
  defaddress,
  defconst,
  defstring,
  defsymbol,
  emit,
  export,
  function,
  gen,
  global,
  import,
  local,
  progbeg,
  progend,
  segment,
  space,
  0, 0, 0, 0, 0, 0, 0,
  {
   4,				/* max_unaligned_load */
   rmap,
   blkfetch, blkstore, blkloop,
   _label,
   _rule,
   _nts,
   _kids,
   _string,
   _templates,
   _isinstruction,
   _ntname,
   emit2,
   doarg,
   target,
   clobber,
   }
};
