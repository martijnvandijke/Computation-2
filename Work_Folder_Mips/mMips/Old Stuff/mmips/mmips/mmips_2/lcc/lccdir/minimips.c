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
/*
generated at Wed Nov 14 09:57:06 2007
by $Id: lburg.c,v 2.8 1997/10/30 23:41:10 drh Exp $
*/
static void _kids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
static void _label(NODEPTR_TYPE);
static int _rule(void*, int);

#define _stmt_NT 1
#define _reg_NT 2
#define _con_NT 3
#define _acon_NT 4
#define _addr_NT 5
#define _rc_NT 6
#define _ar_NT 7
#define _magic_addr_NT 8

static char *_ntname[] = {
	0,
	"stmt",
	"reg",
	"con",
	"acon",
	"addr",
	"rc",
	"ar",
	"magic_addr",
	0
};

struct _state {
	short cost[9];
	struct {
		unsigned int _stmt:6;
		unsigned int _reg:7;
		unsigned int _con:3;
		unsigned int _acon:2;
		unsigned int _addr:3;
		unsigned int _rc:2;
		unsigned int _ar:2;
		unsigned int _magic_addr:1;
	} rule;
};

static short _nts_0[] = { 0 };
static short _nts_1[] = { _reg_NT, 0 };
static short _nts_2[] = { _con_NT, 0 };
static short _nts_3[] = { _reg_NT, _acon_NT, 0 };
static short _nts_4[] = { _acon_NT, 0 };
static short _nts_5[] = { _addr_NT, 0 };
static short _nts_6[] = { _addr_NT, _reg_NT, 0 };
static short _nts_7[] = { _reg_NT, _reg_NT, 0 };
static short _nts_8[] = { _reg_NT, _rc_NT, 0 };
static short _nts_9[] = { _ar_NT, 0 };
static short _nts_10[] = { _reg_NT, _reg_NT, _magic_addr_NT, 0 };
static short _nts_11[] = { _reg_NT, _reg_NT, _reg_NT, _magic_addr_NT, 0 };

static short *_nts[] = {
	0,	/* 0 */
	_nts_0,	/* 1 */
	_nts_0,	/* 2 */
	_nts_0,	/* 3 */
	_nts_0,	/* 4 */
	_nts_0,	/* 5 */
	_nts_0,	/* 6 */
	_nts_1,	/* 7 */
	_nts_1,	/* 8 */
	_nts_1,	/* 9 */
	_nts_1,	/* 10 */
	_nts_1,	/* 11 */
	_nts_1,	/* 12 */
	_nts_0,	/* 13 */
	_nts_0,	/* 14 */
	_nts_0,	/* 15 */
	_nts_0,	/* 16 */
	_nts_0,	/* 17 */
	_nts_1,	/* 18 */
	_nts_2,	/* 19 */
	_nts_0,	/* 20 */
	_nts_3,	/* 21 */
	_nts_3,	/* 22 */
	_nts_3,	/* 23 */
	_nts_4,	/* 24 */
	_nts_1,	/* 25 */
	_nts_0,	/* 26 */
	_nts_0,	/* 27 */
	_nts_5,	/* 28 */
	_nts_0,	/* 29 */
	_nts_0,	/* 30 */
	_nts_0,	/* 31 */
	_nts_0,	/* 32 */
	_nts_0,	/* 33 */
	_nts_0,	/* 34 */
	_nts_6,	/* 35 */
	_nts_6,	/* 36 */
	_nts_6,	/* 37 */
	_nts_6,	/* 38 */
	_nts_6,	/* 39 */
	_nts_5,	/* 40 */
	_nts_5,	/* 41 */
	_nts_5,	/* 42 */
	_nts_5,	/* 43 */
	_nts_5,	/* 44 */
	_nts_5,	/* 45 */
	_nts_5,	/* 46 */
	_nts_5,	/* 47 */
	_nts_5,	/* 48 */
	_nts_6,	/* 49 */
	_nts_7,	/* 50 */
	_nts_7,	/* 51 */
	_nts_7,	/* 52 */
	_nts_7,	/* 53 */
	_nts_7,	/* 54 */
	_nts_7,	/* 55 */
	_nts_2,	/* 56 */
	_nts_1,	/* 57 */
	_nts_8,	/* 58 */
	_nts_8,	/* 59 */
	_nts_8,	/* 60 */
	_nts_8,	/* 61 */
	_nts_8,	/* 62 */
	_nts_8,	/* 63 */
	_nts_8,	/* 64 */
	_nts_8,	/* 65 */
	_nts_8,	/* 66 */
	_nts_8,	/* 67 */
	_nts_8,	/* 68 */
	_nts_8,	/* 69 */
	_nts_1,	/* 70 */
	_nts_1,	/* 71 */
	_nts_1,	/* 72 */
	_nts_1,	/* 73 */
	_nts_7,	/* 74 */
	_nts_7,	/* 75 */
	_nts_7,	/* 76 */
	_nts_7,	/* 77 */
	_nts_1,	/* 78 */
	_nts_1,	/* 79 */
	_nts_1,	/* 80 */
	_nts_1,	/* 81 */
	_nts_1,	/* 82 */
	_nts_1,	/* 83 */
	_nts_1,	/* 84 */
	_nts_1,	/* 85 */
	_nts_1,	/* 86 */
	_nts_7,	/* 87 */
	_nts_7,	/* 88 */
	_nts_7,	/* 89 */
	_nts_7,	/* 90 */
	_nts_1,	/* 91 */
	_nts_1,	/* 92 */
	_nts_1,	/* 93 */
	_nts_1,	/* 94 */
	_nts_1,	/* 95 */
	_nts_1,	/* 96 */
	_nts_1,	/* 97 */
	_nts_0,	/* 98 */
	_nts_4,	/* 99 */
	_nts_1,	/* 100 */
	_nts_7,	/* 101 */
	_nts_7,	/* 102 */
	_nts_7,	/* 103 */
	_nts_7,	/* 104 */
	_nts_7,	/* 105 */
	_nts_7,	/* 106 */
	_nts_7,	/* 107 */
	_nts_7,	/* 108 */
	_nts_7,	/* 109 */
	_nts_7,	/* 110 */
	_nts_7,	/* 111 */
	_nts_7,	/* 112 */
	_nts_7,	/* 113 */
	_nts_7,	/* 114 */
	_nts_7,	/* 115 */
	_nts_7,	/* 116 */
	_nts_7,	/* 117 */
	_nts_7,	/* 118 */
	_nts_9,	/* 119 */
	_nts_9,	/* 120 */
	_nts_9,	/* 121 */
	_nts_9,	/* 122 */
	_nts_9,	/* 123 */
	_nts_1,	/* 124 */
	_nts_0,	/* 125 */
	_nts_0,	/* 126 */
	_nts_0,	/* 127 */
	_nts_10,	/* 128 */
	_nts_10,	/* 129 */
	_nts_10,	/* 130 */
	_nts_10,	/* 131 */
	_nts_11,	/* 132 */
	_nts_1,	/* 133 */
	_nts_1,	/* 134 */
	_nts_1,	/* 135 */
	_nts_1,	/* 136 */
	_nts_1,	/* 137 */
	_nts_1,	/* 138 */
	_nts_1,	/* 139 */
	_nts_1,	/* 140 */
	_nts_1,	/* 141 */
	_nts_1,	/* 142 */
	_nts_7,	/* 143 */
};

static char *_templates[] = {
/* 0 */	0,
/* 1 */	"# read register\n",	/* reg: INDIRI1(VREGP) */
/* 2 */	"# read register\n",	/* reg: INDIRU1(VREGP) */
/* 3 */	"# read register\n",	/* reg: INDIRF4(VREGP) */
/* 4 */	"# read register\n",	/* reg: INDIRI4(VREGP) */
/* 5 */	"# read register\n",	/* reg: INDIRP4(VREGP) */
/* 6 */	"# read register\n",	/* reg: INDIRU4(VREGP) */
/* 7 */	"# write register\n",	/* stmt: ASGNI1(VREGP,reg) */
/* 8 */	"# write register\n",	/* stmt: ASGNU1(VREGP,reg) */
/* 9 */	"# write register\n",	/* stmt: ASGNF4(VREGP,reg) */
/* 10 */	"# write register\n",	/* stmt: ASGNI4(VREGP,reg) */
/* 11 */	"# write register\n",	/* stmt: ASGNP4(VREGP,reg) */
/* 12 */	"# write register\n",	/* stmt: ASGNU4(VREGP,reg) */
/* 13 */	"%a",	/* con: CNSTI1 */
/* 14 */	"%a",	/* con: CNSTU1 */
/* 15 */	"%a",	/* con: CNSTI4 */
/* 16 */	"%a",	/* con: CNSTU4 */
/* 17 */	"%a",	/* con: CNSTP4 */
/* 18 */	"",	/* stmt: reg */
/* 19 */	"%0",	/* acon: con */
/* 20 */	"%a",	/* acon: ADDRGP4 */
/* 21 */	"%1($%0)",	/* addr: ADDI4(reg,acon) */
/* 22 */	"%1($%0)",	/* addr: ADDU4(reg,acon) */
/* 23 */	"%1($%0)",	/* addr: ADDP4(reg,acon) */
/* 24 */	"%0",	/* addr: acon */
/* 25 */	"($%0)",	/* addr: reg */
/* 26 */	"%a+%F($sp)",	/* addr: ADDRFP4 */
/* 27 */	"%a+%F($sp)",	/* addr: ADDRLP4 */
/* 28 */	"\tla $%c,%0\n",	/* reg: addr */
/* 29 */	"# reg\n",	/* reg: CNSTI1 */
/* 30 */	"# reg\n",	/* reg: CNSTI4 */
/* 31 */	"# reg\n",	/* reg: CNSTU1 */
/* 32 */	"# reg\n",	/* reg: CNSTU4 */
/* 33 */	"# reg\n",	/* reg: CNSTP4 */
/* 34 */	"# reg\n",	/* reg: CNSTF4 */
/* 35 */	"\tsb $%1,%0\n",	/* stmt: ASGNI1(addr,reg) */
/* 36 */	"\tsb $%1,%0\n",	/* stmt: ASGNU1(addr,reg) */
/* 37 */	"\tsw $%1,%0\n",	/* stmt: ASGNI4(addr,reg) */
/* 38 */	"\tsw $%1,%0\n",	/* stmt: ASGNU4(addr,reg) */
/* 39 */	"\tsw $%1,%0\n",	/* stmt: ASGNP4(addr,reg) */
/* 40 */	"\tlb $%c,%0\n",	/* reg: INDIRI1(addr) */
/* 41 */	"\tlb $%c,%0; and $%c,$%c,255\n",	/* reg: INDIRU1(addr) */
/* 42 */	"\tlw $%c,%0\n",	/* reg: INDIRI4(addr) */
/* 43 */	"\tlw $%c,%0\n",	/* reg: INDIRU4(addr) */
/* 44 */	"\tlw $%c,%0\n",	/* reg: INDIRP4(addr) */
/* 45 */	"\tlb $%c,%0\n",	/* reg: CVII4(INDIRI1(addr)) */
/* 46 */	"\tlb $%c,%0; and $%c,$%c,255\n",	/* reg: CVUU4(INDIRU1(addr)) */
/* 47 */	"\tlb $%c,%0; and $%c,$%c,255\n",	/* reg: CVUI4(INDIRU1(addr)) */
/* 48 */	"\tlw $%c,%0\n",	/* reg: INDIRF4(addr) */
/* 49 */	"\tsw $%1,%0\n",	/* stmt: ASGNF4(addr,reg) */
/* 50 */	"\tjal __div\n",	/* reg: DIVI4(reg,reg) */
/* 51 */	"\tjal __divu\n",	/* reg: DIVU4(reg,reg) */
/* 52 */	"\tjal __mod\n",	/* reg: MODI4(reg,reg) */
/* 53 */	"\tjal __modu\n",	/* reg: MODU4(reg,reg) */
/* 54 */	"\tmul $%c,$%0,$%1\n",	/* reg: MULI4(reg,reg) */
/* 55 */	"\tmul $%c,$%0,$%1\n",	/* reg: MULU4(reg,reg) */
/* 56 */	"%0",	/* rc: con */
/* 57 */	"$%0",	/* rc: reg */
/* 58 */	"\taddu $%c,$%0,%1\n",	/* reg: ADDI4(reg,rc) */
/* 59 */	"\taddu $%c,$%0,%1\n",	/* reg: ADDP4(reg,rc) */
/* 60 */	"\taddu $%c,$%0,%1\n",	/* reg: ADDU4(reg,rc) */
/* 61 */	"\tand $%c,$%0,%1\n",	/* reg: BANDI4(reg,rc) */
/* 62 */	"\tor $%c,$%0,%1\n",	/* reg: BORI4(reg,rc) */
/* 63 */	"\txor $%c,$%0,%1\n",	/* reg: BXORI4(reg,rc) */
/* 64 */	"\tand $%c,$%0,%1\n",	/* reg: BANDU4(reg,rc) */
/* 65 */	"\tor $%c,$%0,%1\n",	/* reg: BORU4(reg,rc) */
/* 66 */	"\txor $%c,$%0,%1\n",	/* reg: BXORU4(reg,rc) */
/* 67 */	"\tsubu $%c,$%0,%1\n",	/* reg: SUBI4(reg,rc) */
/* 68 */	"\tsubu $%c,$%0,%1\n",	/* reg: SUBP4(reg,rc) */
/* 69 */	"\tsubu $%c,$%0,%1\n",	/* reg: SUBU4(reg,rc) */
/* 70 */	"# sll\n",	/* reg: LSHI4(reg,CNSTI4) */
/* 71 */	"# sll\n",	/* reg: LSHU4(reg,CNSTI4) */
/* 72 */	"# sra\n",	/* reg: RSHI4(reg,CNSTI4) */
/* 73 */	"# srl\n",	/* reg: RSHU4(reg,CNSTI4) */
/* 74 */	"\tjal __sll\n",	/* reg: LSHI4(reg,reg) */
/* 75 */	"\tjal __sll\n",	/* reg: LSHU4(reg,reg) */
/* 76 */	"\tjal __sra\n",	/* reg: RSHI4(reg,reg) */
/* 77 */	"\tjal __srl\n",	/* reg: RSHU4(reg,reg) */
/* 78 */	"\tli $30, -1; xor $%c,$%0,$30\n",	/* reg: BCOMI4(reg) */
/* 79 */	"\tli $30, -1; xor $%c,$%0,$30\n",	/* reg: BCOMU4(reg) */
/* 80 */	"\tnegu $%c,$%0\n",	/* reg: NEGI4(reg) */
/* 81 */	"\tmove $%c,$%0\n",	/* reg: LOADI1(reg) */
/* 82 */	"\tmove $%c,$%0\n",	/* reg: LOADU1(reg) */
/* 83 */	"\tmove $%c,$%0\n",	/* reg: LOADI4(reg) */
/* 84 */	"\tmove $%c,$%0\n",	/* reg: LOADP4(reg) */
/* 85 */	"\tmove $%c,$%0\n",	/* reg: LOADU4(reg) */
/* 86 */	"\tmove $%c,$%0\n",	/* reg: LOADF4(reg) */
/* 87 */	"\tjal float32_add\n",	/* reg: ADDF4(reg,reg) */
/* 88 */	"\tjal float32_sub\n",	/* reg: SUBF4(reg,reg) */
/* 89 */	"\tjal float32_mul\n",	/* reg: MULF4(reg,reg) */
/* 90 */	"\tjal float32_div\n",	/* reg: DIVF4(reg,reg) */
/* 91 */	"\tjal float32_neg\n",	/* reg: NEGF4(reg) */
/* 92 */	"\tsb $%0,CVII4_int; lb $%c,CVII4_int\n",	/* reg: CVII4(reg) */
/* 93 */	"\tand $%c,$%0,255\n",	/* reg: CVUI4(reg) */
/* 94 */	"\tand $%c,$%0,255\n",	/* reg: CVUU4(reg) */
/* 95 */	"\t???",	/* reg: CVFF4(reg) */
/* 96 */	"\tjal int32_to_float32\n",	/* reg: CVIF4(reg) */
/* 97 */	"\tjal float32_to_int32_round_to_zero\n",	/* reg: CVFI4(reg) */
/* 98 */	"%a:\n",	/* stmt: LABELV */
/* 99 */	"\tb %0\n",	/* stmt: JUMPV(acon) */
/* 100 */	"\tj $%0\n",	/* stmt: JUMPV(reg) */
/* 101 */	"\tbeq $%0,$%1,%a\n",	/* stmt: EQI4(reg,reg) */
/* 102 */	"\tbeq $%0,$%1,%a\n",	/* stmt: EQU4(reg,reg) */
/* 103 */	"\tbne $%0,$%1,%a\n",	/* stmt: NEI4(reg,reg) */
/* 104 */	"\tbne $%0,$%1,%a\n",	/* stmt: NEU4(reg,reg) */
/* 105 */	"\tslt $30,$%0,$%1\n\tbne $30,$0,%a\n",	/* stmt: LTI4(reg,reg) */
/* 106 */	"\tsltu $30,$%0,$%1\n\tbne $30,$0,%a\n",	/* stmt: LTU4(reg,reg) */
/* 107 */	"\tslt $30,$%1,$%0\n\tbne $30,$0,%a\n",	/* stmt: GTI4(reg,reg) */
/* 108 */	"\tsltu $30,$%1,$%0\n\tbne $30,$0,%a\n",	/* stmt: GTU4(reg,reg) */
/* 109 */	"\tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n",	/* stmt: GEI4(reg,reg) */
/* 110 */	"\tsltu $30,$%0,$%1\n\tbeq $30,$0,%a\n",	/* stmt: GEU4(reg,reg) */
/* 111 */	"\tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n",	/* stmt: LEI4(reg,reg) */
/* 112 */	"\tsltu $30,$%1,$%0\n\tbeq $30,$0,%a\n",	/* stmt: LEU4(reg,reg) */
/* 113 */	"\tbeq $%0,$%1,%a\n",	/* stmt: EQF4(reg,reg) */
/* 114 */	"\tbne $%0,$%1,%a\n",	/* stmt: NEF4(reg,reg) */
/* 115 */	"\tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n",	/* stmt: LEF4(reg,reg) */
/* 116 */	"\tslt $30,$%0,$%1\n\tbne $30,$0,%a\n",	/* stmt: LTF4(reg,reg) */
/* 117 */	"\tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n",	/* stmt: GEF4(reg,reg) */
/* 118 */	"\tslt $30,$%1,$%0\n\tbne $30,$0,%a\n",	/* stmt: GTF4(reg,reg) */
/* 119 */	"\tjal %0\n",	/* reg: CALLF4(ar) */
/* 120 */	"\tjal %0\n",	/* reg: CALLI4(ar) */
/* 121 */	"\tjal %0\n",	/* reg: CALLP4(ar) */
/* 122 */	"\tjal %0\n",	/* reg: CALLU4(ar) */
/* 123 */	"\tjal %0\n",	/* stmt: CALLV(ar) */
/* 124 */	"$%0",	/* ar: reg */
/* 125 */	"%a",	/* ar: CNSTP4 */
/* 126 */	"%a",	/* ar: ADDRGP4 */
/* 127 */	"%a",	/* magic_addr: CNSTP4 */
/* 128 */	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x30\n",	/* reg: ADDI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
/* 129 */	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x31\n",	/* reg: SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
/* 130 */	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x32\n",	/* reg: ADDI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
/* 131 */	"\t.word (%c<<11)|(%0<<21)|(%1<<16)|0x33\n",	/* reg: SUBI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
/* 132 */	"\t.word (%c<<11)|(%2<<21)|(%2<<16)|0x35\n \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x34\n",	/* reg: SUBI4(reg,SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr)))) */
/* 133 */	"# ret\n",	/* stmt: RETF4(reg) */
/* 134 */	"# ret\n",	/* stmt: RETI4(reg) */
/* 135 */	"# ret\n",	/* stmt: RETU4(reg) */
/* 136 */	"# ret\n",	/* stmt: RETP4(reg) */
/* 137 */	"# ret\n",	/* stmt: RETV(reg) */
/* 138 */	"# arg\n",	/* stmt: ARGF4(reg) */
/* 139 */	"# arg\n",	/* stmt: ARGI4(reg) */
/* 140 */	"# arg\n",	/* stmt: ARGP4(reg) */
/* 141 */	"# arg\n",	/* stmt: ARGU4(reg) */
/* 142 */	"# argb %0\n",	/* stmt: ARGB(INDIRB(reg)) */
/* 143 */	"# asgnb %0 %1\n",	/* stmt: ASGNB(reg,INDIRB(reg)) */
};

static char _isinstruction[] = {
/* 0 */	0,
/* 1 */	1,	/* # read register\n */
/* 2 */	1,	/* # read register\n */
/* 3 */	1,	/* # read register\n */
/* 4 */	1,	/* # read register\n */
/* 5 */	1,	/* # read register\n */
/* 6 */	1,	/* # read register\n */
/* 7 */	1,	/* # write register\n */
/* 8 */	1,	/* # write register\n */
/* 9 */	1,	/* # write register\n */
/* 10 */	1,	/* # write register\n */
/* 11 */	1,	/* # write register\n */
/* 12 */	1,	/* # write register\n */
/* 13 */	0,	/* %a */
/* 14 */	0,	/* %a */
/* 15 */	0,	/* %a */
/* 16 */	0,	/* %a */
/* 17 */	0,	/* %a */
/* 18 */	0,	/*  */
/* 19 */	0,	/* %0 */
/* 20 */	0,	/* %a */
/* 21 */	0,	/* %1($%0) */
/* 22 */	0,	/* %1($%0) */
/* 23 */	0,	/* %1($%0) */
/* 24 */	0,	/* %0 */
/* 25 */	0,	/* ($%0) */
/* 26 */	0,	/* %a+%F($sp) */
/* 27 */	0,	/* %a+%F($sp) */
/* 28 */	1,	/* \tla $%c,%0\n */
/* 29 */	1,	/* # reg\n */
/* 30 */	1,	/* # reg\n */
/* 31 */	1,	/* # reg\n */
/* 32 */	1,	/* # reg\n */
/* 33 */	1,	/* # reg\n */
/* 34 */	1,	/* # reg\n */
/* 35 */	1,	/* \tsb $%1,%0\n */
/* 36 */	1,	/* \tsb $%1,%0\n */
/* 37 */	1,	/* \tsw $%1,%0\n */
/* 38 */	1,	/* \tsw $%1,%0\n */
/* 39 */	1,	/* \tsw $%1,%0\n */
/* 40 */	1,	/* \tlb $%c,%0\n */
/* 41 */	1,	/* \tlb $%c,%0; and $%c,$%c,255\n */
/* 42 */	1,	/* \tlw $%c,%0\n */
/* 43 */	1,	/* \tlw $%c,%0\n */
/* 44 */	1,	/* \tlw $%c,%0\n */
/* 45 */	1,	/* \tlb $%c,%0\n */
/* 46 */	1,	/* \tlb $%c,%0; and $%c,$%c,255\n */
/* 47 */	1,	/* \tlb $%c,%0; and $%c,$%c,255\n */
/* 48 */	1,	/* \tlw $%c,%0\n */
/* 49 */	1,	/* \tsw $%1,%0\n */
/* 50 */	1,	/* \tjal __div\n */
/* 51 */	1,	/* \tjal __divu\n */
/* 52 */	1,	/* \tjal __mod\n */
/* 53 */	1,	/* \tjal __modu\n */
/* 54 */	1,	/* \tmul $%c,$%0,$%1\n */
/* 55 */	1,	/* \tmul $%c,$%0,$%1\n */
/* 56 */	0,	/* %0 */
/* 57 */	0,	/* $%0 */
/* 58 */	1,	/* \taddu $%c,$%0,%1\n */
/* 59 */	1,	/* \taddu $%c,$%0,%1\n */
/* 60 */	1,	/* \taddu $%c,$%0,%1\n */
/* 61 */	1,	/* \tand $%c,$%0,%1\n */
/* 62 */	1,	/* \tor $%c,$%0,%1\n */
/* 63 */	1,	/* \txor $%c,$%0,%1\n */
/* 64 */	1,	/* \tand $%c,$%0,%1\n */
/* 65 */	1,	/* \tor $%c,$%0,%1\n */
/* 66 */	1,	/* \txor $%c,$%0,%1\n */
/* 67 */	1,	/* \tsubu $%c,$%0,%1\n */
/* 68 */	1,	/* \tsubu $%c,$%0,%1\n */
/* 69 */	1,	/* \tsubu $%c,$%0,%1\n */
/* 70 */	1,	/* # sll\n */
/* 71 */	1,	/* # sll\n */
/* 72 */	1,	/* # sra\n */
/* 73 */	1,	/* # srl\n */
/* 74 */	1,	/* \tjal __sll\n */
/* 75 */	1,	/* \tjal __sll\n */
/* 76 */	1,	/* \tjal __sra\n */
/* 77 */	1,	/* \tjal __srl\n */
/* 78 */	1,	/* \tli $30, -1; xor $%c,$%0,$30\n */
/* 79 */	1,	/* \tli $30, -1; xor $%c,$%0,$30\n */
/* 80 */	1,	/* \tnegu $%c,$%0\n */
/* 81 */	1,	/* \tmove $%c,$%0\n */
/* 82 */	1,	/* \tmove $%c,$%0\n */
/* 83 */	1,	/* \tmove $%c,$%0\n */
/* 84 */	1,	/* \tmove $%c,$%0\n */
/* 85 */	1,	/* \tmove $%c,$%0\n */
/* 86 */	1,	/* \tmove $%c,$%0\n */
/* 87 */	1,	/* \tjal float32_add\n */
/* 88 */	1,	/* \tjal float32_sub\n */
/* 89 */	1,	/* \tjal float32_mul\n */
/* 90 */	1,	/* \tjal float32_div\n */
/* 91 */	1,	/* \tjal float32_neg\n */
/* 92 */	1,	/* \tsb $%0,CVII4_int; lb $%c,CVII4_int\n */
/* 93 */	1,	/* \tand $%c,$%0,255\n */
/* 94 */	1,	/* \tand $%c,$%0,255\n */
/* 95 */	0,	/* \t??? */
/* 96 */	1,	/* \tjal int32_to_float32\n */
/* 97 */	1,	/* \tjal float32_to_int32_round_to_zero\n */
/* 98 */	1,	/* %a:\n */
/* 99 */	1,	/* \tb %0\n */
/* 100 */	1,	/* \tj $%0\n */
/* 101 */	1,	/* \tbeq $%0,$%1,%a\n */
/* 102 */	1,	/* \tbeq $%0,$%1,%a\n */
/* 103 */	1,	/* \tbne $%0,$%1,%a\n */
/* 104 */	1,	/* \tbne $%0,$%1,%a\n */
/* 105 */	1,	/* \tslt $30,$%0,$%1\n\tbne $30,$0,%a\n */
/* 106 */	1,	/* \tsltu $30,$%0,$%1\n\tbne $30,$0,%a\n */
/* 107 */	1,	/* \tslt $30,$%1,$%0\n\tbne $30,$0,%a\n */
/* 108 */	1,	/* \tsltu $30,$%1,$%0\n\tbne $30,$0,%a\n */
/* 109 */	1,	/* \tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n */
/* 110 */	1,	/* \tsltu $30,$%0,$%1\n\tbeq $30,$0,%a\n */
/* 111 */	1,	/* \tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n */
/* 112 */	1,	/* \tsltu $30,$%1,$%0\n\tbeq $30,$0,%a\n */
/* 113 */	1,	/* \tbeq $%0,$%1,%a\n */
/* 114 */	1,	/* \tbne $%0,$%1,%a\n */
/* 115 */	1,	/* \tslt $30,$%1,$%0\n\tbeq $30,$0,%a\n */
/* 116 */	1,	/* \tslt $30,$%0,$%1\n\tbne $30,$0,%a\n */
/* 117 */	1,	/* \tslt $30,$%0,$%1\n\tbeq $30,$0,%a\n */
/* 118 */	1,	/* \tslt $30,$%1,$%0\n\tbne $30,$0,%a\n */
/* 119 */	1,	/* \tjal %0\n */
/* 120 */	1,	/* \tjal %0\n */
/* 121 */	1,	/* \tjal %0\n */
/* 122 */	1,	/* \tjal %0\n */
/* 123 */	1,	/* \tjal %0\n */
/* 124 */	0,	/* $%0 */
/* 125 */	0,	/* %a */
/* 126 */	0,	/* %a */
/* 127 */	0,	/* %a */
/* 128 */	1,	/* \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x30\n */
/* 129 */	1,	/* \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x31\n */
/* 130 */	1,	/* \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x32\n */
/* 131 */	1,	/* \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x33\n */
/* 132 */	1,	/* \t.word (%c<<11)|(%2<<21)|(%2<<16)|0x35\n \t.word (%c<<11)|(%0<<21)|(%1<<16)|0x34\n */
/* 133 */	1,	/* # ret\n */
/* 134 */	1,	/* # ret\n */
/* 135 */	1,	/* # ret\n */
/* 136 */	1,	/* # ret\n */
/* 137 */	1,	/* # ret\n */
/* 138 */	1,	/* # arg\n */
/* 139 */	1,	/* # arg\n */
/* 140 */	1,	/* # arg\n */
/* 141 */	1,	/* # arg\n */
/* 142 */	1,	/* # argb %0\n */
/* 143 */	1,	/* # asgnb %0 %1\n */
};

static char *_string[] = {
/* 0 */	0,
/* 1 */	"reg: INDIRI1(VREGP)",
/* 2 */	"reg: INDIRU1(VREGP)",
/* 3 */	"reg: INDIRF4(VREGP)",
/* 4 */	"reg: INDIRI4(VREGP)",
/* 5 */	"reg: INDIRP4(VREGP)",
/* 6 */	"reg: INDIRU4(VREGP)",
/* 7 */	"stmt: ASGNI1(VREGP,reg)",
/* 8 */	"stmt: ASGNU1(VREGP,reg)",
/* 9 */	"stmt: ASGNF4(VREGP,reg)",
/* 10 */	"stmt: ASGNI4(VREGP,reg)",
/* 11 */	"stmt: ASGNP4(VREGP,reg)",
/* 12 */	"stmt: ASGNU4(VREGP,reg)",
/* 13 */	"con: CNSTI1",
/* 14 */	"con: CNSTU1",
/* 15 */	"con: CNSTI4",
/* 16 */	"con: CNSTU4",
/* 17 */	"con: CNSTP4",
/* 18 */	"stmt: reg",
/* 19 */	"acon: con",
/* 20 */	"acon: ADDRGP4",
/* 21 */	"addr: ADDI4(reg,acon)",
/* 22 */	"addr: ADDU4(reg,acon)",
/* 23 */	"addr: ADDP4(reg,acon)",
/* 24 */	"addr: acon",
/* 25 */	"addr: reg",
/* 26 */	"addr: ADDRFP4",
/* 27 */	"addr: ADDRLP4",
/* 28 */	"reg: addr",
/* 29 */	"reg: CNSTI1",
/* 30 */	"reg: CNSTI4",
/* 31 */	"reg: CNSTU1",
/* 32 */	"reg: CNSTU4",
/* 33 */	"reg: CNSTP4",
/* 34 */	"reg: CNSTF4",
/* 35 */	"stmt: ASGNI1(addr,reg)",
/* 36 */	"stmt: ASGNU1(addr,reg)",
/* 37 */	"stmt: ASGNI4(addr,reg)",
/* 38 */	"stmt: ASGNU4(addr,reg)",
/* 39 */	"stmt: ASGNP4(addr,reg)",
/* 40 */	"reg: INDIRI1(addr)",
/* 41 */	"reg: INDIRU1(addr)",
/* 42 */	"reg: INDIRI4(addr)",
/* 43 */	"reg: INDIRU4(addr)",
/* 44 */	"reg: INDIRP4(addr)",
/* 45 */	"reg: CVII4(INDIRI1(addr))",
/* 46 */	"reg: CVUU4(INDIRU1(addr))",
/* 47 */	"reg: CVUI4(INDIRU1(addr))",
/* 48 */	"reg: INDIRF4(addr)",
/* 49 */	"stmt: ASGNF4(addr,reg)",
/* 50 */	"reg: DIVI4(reg,reg)",
/* 51 */	"reg: DIVU4(reg,reg)",
/* 52 */	"reg: MODI4(reg,reg)",
/* 53 */	"reg: MODU4(reg,reg)",
/* 54 */	"reg: MULI4(reg,reg)",
/* 55 */	"reg: MULU4(reg,reg)",
/* 56 */	"rc: con",
/* 57 */	"rc: reg",
/* 58 */	"reg: ADDI4(reg,rc)",
/* 59 */	"reg: ADDP4(reg,rc)",
/* 60 */	"reg: ADDU4(reg,rc)",
/* 61 */	"reg: BANDI4(reg,rc)",
/* 62 */	"reg: BORI4(reg,rc)",
/* 63 */	"reg: BXORI4(reg,rc)",
/* 64 */	"reg: BANDU4(reg,rc)",
/* 65 */	"reg: BORU4(reg,rc)",
/* 66 */	"reg: BXORU4(reg,rc)",
/* 67 */	"reg: SUBI4(reg,rc)",
/* 68 */	"reg: SUBP4(reg,rc)",
/* 69 */	"reg: SUBU4(reg,rc)",
/* 70 */	"reg: LSHI4(reg,CNSTI4)",
/* 71 */	"reg: LSHU4(reg,CNSTI4)",
/* 72 */	"reg: RSHI4(reg,CNSTI4)",
/* 73 */	"reg: RSHU4(reg,CNSTI4)",
/* 74 */	"reg: LSHI4(reg,reg)",
/* 75 */	"reg: LSHU4(reg,reg)",
/* 76 */	"reg: RSHI4(reg,reg)",
/* 77 */	"reg: RSHU4(reg,reg)",
/* 78 */	"reg: BCOMI4(reg)",
/* 79 */	"reg: BCOMU4(reg)",
/* 80 */	"reg: NEGI4(reg)",
/* 81 */	"reg: LOADI1(reg)",
/* 82 */	"reg: LOADU1(reg)",
/* 83 */	"reg: LOADI4(reg)",
/* 84 */	"reg: LOADP4(reg)",
/* 85 */	"reg: LOADU4(reg)",
/* 86 */	"reg: LOADF4(reg)",
/* 87 */	"reg: ADDF4(reg,reg)",
/* 88 */	"reg: SUBF4(reg,reg)",
/* 89 */	"reg: MULF4(reg,reg)",
/* 90 */	"reg: DIVF4(reg,reg)",
/* 91 */	"reg: NEGF4(reg)",
/* 92 */	"reg: CVII4(reg)",
/* 93 */	"reg: CVUI4(reg)",
/* 94 */	"reg: CVUU4(reg)",
/* 95 */	"reg: CVFF4(reg)",
/* 96 */	"reg: CVIF4(reg)",
/* 97 */	"reg: CVFI4(reg)",
/* 98 */	"stmt: LABELV",
/* 99 */	"stmt: JUMPV(acon)",
/* 100 */	"stmt: JUMPV(reg)",
/* 101 */	"stmt: EQI4(reg,reg)",
/* 102 */	"stmt: EQU4(reg,reg)",
/* 103 */	"stmt: NEI4(reg,reg)",
/* 104 */	"stmt: NEU4(reg,reg)",
/* 105 */	"stmt: LTI4(reg,reg)",
/* 106 */	"stmt: LTU4(reg,reg)",
/* 107 */	"stmt: GTI4(reg,reg)",
/* 108 */	"stmt: GTU4(reg,reg)",
/* 109 */	"stmt: GEI4(reg,reg)",
/* 110 */	"stmt: GEU4(reg,reg)",
/* 111 */	"stmt: LEI4(reg,reg)",
/* 112 */	"stmt: LEU4(reg,reg)",
/* 113 */	"stmt: EQF4(reg,reg)",
/* 114 */	"stmt: NEF4(reg,reg)",
/* 115 */	"stmt: LEF4(reg,reg)",
/* 116 */	"stmt: LTF4(reg,reg)",
/* 117 */	"stmt: GEF4(reg,reg)",
/* 118 */	"stmt: GTF4(reg,reg)",
/* 119 */	"reg: CALLF4(ar)",
/* 120 */	"reg: CALLI4(ar)",
/* 121 */	"reg: CALLP4(ar)",
/* 122 */	"reg: CALLU4(ar)",
/* 123 */	"stmt: CALLV(ar)",
/* 124 */	"ar: reg",
/* 125 */	"ar: CNSTP4",
/* 126 */	"ar: ADDRGP4",
/* 127 */	"magic_addr: CNSTP4",
/* 128 */	"reg: ADDI4(reg,ADDI4(reg,INDIRI4(magic_addr)))",
/* 129 */	"reg: SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr)))",
/* 130 */	"reg: ADDI4(reg,SUBI4(reg,INDIRI4(magic_addr)))",
/* 131 */	"reg: SUBI4(reg,SUBI4(reg,INDIRI4(magic_addr)))",
/* 132 */	"reg: SUBI4(reg,SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr))))",
/* 133 */	"stmt: RETF4(reg)",
/* 134 */	"stmt: RETI4(reg)",
/* 135 */	"stmt: RETU4(reg)",
/* 136 */	"stmt: RETP4(reg)",
/* 137 */	"stmt: RETV(reg)",
/* 138 */	"stmt: ARGF4(reg)",
/* 139 */	"stmt: ARGI4(reg)",
/* 140 */	"stmt: ARGP4(reg)",
/* 141 */	"stmt: ARGU4(reg)",
/* 142 */	"stmt: ARGB(INDIRB(reg))",
/* 143 */	"stmt: ASGNB(reg,INDIRB(reg))",
};

static short _decode_stmt[] = {
	0,
	7,
	8,
	9,
	10,
	11,
	12,
	18,
	35,
	36,
	37,
	38,
	39,
	49,
	98,
	99,
	100,
	101,
	102,
	103,
	104,
	105,
	106,
	107,
	108,
	109,
	110,
	111,
	112,
	113,
	114,
	115,
	116,
	117,
	118,
	123,
	133,
	134,
	135,
	136,
	137,
	138,
	139,
	140,
	141,
	142,
	143,
};

static short _decode_reg[] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	50,
	51,
	52,
	53,
	54,
	55,
	58,
	59,
	60,
	61,
	62,
	63,
	64,
	65,
	66,
	67,
	68,
	69,
	70,
	71,
	72,
	73,
	74,
	75,
	76,
	77,
	78,
	79,
	80,
	81,
	82,
	83,
	84,
	85,
	86,
	87,
	88,
	89,
	90,
	91,
	92,
	93,
	94,
	95,
	96,
	97,
	119,
	120,
	121,
	122,
	128,
	129,
	130,
	131,
	132,
};

static short _decode_con[] = {
	0,
	13,
	14,
	15,
	16,
	17,
};

static short _decode_acon[] = {
	0,
	19,
	20,
};

static short _decode_addr[] = {
	0,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
};

static short _decode_rc[] = {
	0,
	56,
	57,
};

static short _decode_ar[] = {
	0,
	124,
	125,
	126,
};

static short _decode_magic_addr[] = {
	0,
	127,
};

static int _rule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 8)
		fatal("_rule", "Bad goal nonterminal %d\n", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case _stmt_NT:	return _decode_stmt[((struct _state *)state)->rule._stmt];
	case _reg_NT:	return _decode_reg[((struct _state *)state)->rule._reg];
	case _con_NT:	return _decode_con[((struct _state *)state)->rule._con];
	case _acon_NT:	return _decode_acon[((struct _state *)state)->rule._acon];
	case _addr_NT:	return _decode_addr[((struct _state *)state)->rule._addr];
	case _rc_NT:	return _decode_rc[((struct _state *)state)->rule._rc];
	case _ar_NT:	return _decode_ar[((struct _state *)state)->rule._ar];
	case _magic_addr_NT:	return _decode_magic_addr[((struct _state *)state)->rule._magic_addr];
	default:
		fatal("_rule", "Bad goal nonterminal %d\n", goalnt);
		return 0;
	}
}

static void _closure_reg(NODEPTR_TYPE, int);
static void _closure_con(NODEPTR_TYPE, int);
static void _closure_acon(NODEPTR_TYPE, int);
static void _closure_addr(NODEPTR_TYPE, int);

static void _closure_reg(NODEPTR_TYPE a, int c) {
	struct _state *p = STATE_LABEL(a);
	if (c + 0 < p->cost[_ar_NT]) {
		p->cost[_ar_NT] = c + 0;
		p->rule._ar = 1;
	}
	if (c + 0 < p->cost[_rc_NT]) {
		p->cost[_rc_NT] = c + 0;
		p->rule._rc = 2;
	}
	if (c + 0 < p->cost[_addr_NT]) {
		p->cost[_addr_NT] = c + 0;
		p->rule._addr = 5;
		_closure_addr(a, c + 0);
	}
	if (c + 0 < p->cost[_stmt_NT]) {
		p->cost[_stmt_NT] = c + 0;
		p->rule._stmt = 7;
	}
}

static void _closure_con(NODEPTR_TYPE a, int c) {
	struct _state *p = STATE_LABEL(a);
	if (c + 0 < p->cost[_rc_NT]) {
		p->cost[_rc_NT] = c + 0;
		p->rule._rc = 1;
	}
	if (c + 0 < p->cost[_acon_NT]) {
		p->cost[_acon_NT] = c + 0;
		p->rule._acon = 1;
		_closure_acon(a, c + 0);
	}
}

static void _closure_acon(NODEPTR_TYPE a, int c) {
	struct _state *p = STATE_LABEL(a);
	if (c + 0 < p->cost[_addr_NT]) {
		p->cost[_addr_NT] = c + 0;
		p->rule._addr = 4;
		_closure_addr(a, c + 0);
	}
}

static void _closure_addr(NODEPTR_TYPE a, int c) {
	struct _state *p = STATE_LABEL(a);
	if (c + 1 < p->cost[_reg_NT]) {
		p->cost[_reg_NT] = c + 1;
		p->rule._reg = 7;
		_closure_reg(a, c + 1);
	}
}

static void _label(NODEPTR_TYPE a) {
	int c;
	struct _state *p;

	if (!a)
		fatal("_label", "Null tree\n", 0);
	STATE_LABEL(a) = p = allocate(sizeof *p, FUNC);
	p->rule._stmt = 0;
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 41: /* ARGB */
		_label(LEFT_CHILD(a));
		if (	/* stmt: ARGB(INDIRB(reg)) */
			LEFT_CHILD(a)->op == 73 /* INDIRB */
		) {
			c = ((struct _state *)(LEFT_CHILD(LEFT_CHILD(a))->x.state))->cost[_reg_NT] + 1;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 45;
			}
		}
		break;
	case 57: /* ASGNB */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNB(reg,INDIRB(reg)) */
			RIGHT_CHILD(a)->op == 73 /* INDIRB */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + 1;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 46;
			}
		}
		break;
	case 73: /* INDIRB */
		_label(LEFT_CHILD(a));
		break;
	case 216: /* CALLV */
		_label(LEFT_CHILD(a));
		/* stmt: CALLV(ar) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_ar_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 35;
		}
		break;
	case 217: /* CALLB */
		break;
	case 233: /* LOADB */
		break;
	case 248: /* RETV */
		_label(LEFT_CHILD(a));
		/* stmt: RETV(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 40;
		}
		break;
	case 584: /* JUMPV */
		_label(LEFT_CHILD(a));
		/* stmt: JUMPV(acon) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_acon_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 15;
		}
		/* stmt: JUMPV(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 16;
		}
		break;
	case 600: /* LABELV */
		/* stmt: LABELV */
		if (0 + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = 0 + 0;
			p->rule._stmt = 14;
		}
		break;
	case 711: /* VREGP */
		break;
	case 1045: /* CNSTI1 */
		/* con: CNSTI1 */
		if (0 + 0 < p->cost[_con_NT]) {
			p->cost[_con_NT] = 0 + 0;
			p->rule._con = 1;
			_closure_con(a, 0 + 0);
		}
		/* reg: CNSTI1 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 8;
			_closure_reg(a, c + 0);
		}
		break;
	case 1046: /* CNSTU1 */
		/* con: CNSTU1 */
		if (0 + 0 < p->cost[_con_NT]) {
			p->cost[_con_NT] = 0 + 0;
			p->rule._con = 2;
			_closure_con(a, 0 + 0);
		}
		/* reg: CNSTU1 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 10;
			_closure_reg(a, c + 0);
		}
		break;
	case 1077: /* ASGNI1 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNI1(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 1;
			}
		}
		/* stmt: ASGNI1(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 8;
		}
		break;
	case 1078: /* ASGNU1 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNU1(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 2;
			}
		}
		/* stmt: ASGNU1(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 9;
		}
		break;
	case 1093: /* INDIRI1 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRI1(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 1;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRI1(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 14;
			_closure_reg(a, c + 0);
		}
		break;
	case 1094: /* INDIRU1 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRU1(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 2;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRU1(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 2;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 15;
			_closure_reg(a, c + 0);
		}
		break;
	case 1157: /* CVII1 */
		break;
	case 1158: /* CVIU1 */
		break;
	case 1205: /* CVUI1 */
		break;
	case 1206: /* CVUU1 */
		break;
	case 1253: /* LOADI1 */
		_label(LEFT_CHILD(a));
		/* reg: LOADI1(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 52;
			_closure_reg(a, c + 0);
		}
		break;
	case 1254: /* LOADU1 */
		_label(LEFT_CHILD(a));
		/* reg: LOADU1(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 53;
			_closure_reg(a, c + 0);
		}
		break;
	case 2277: /* LOADI2 */
		break;
	case 2278: /* LOADU2 */
		break;
	case 4113: /* CNSTF4 */
		/* reg: CNSTF4 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 13;
			_closure_reg(a, c + 0);
		}
		break;
	case 4117: /* CNSTI4 */
		/* con: CNSTI4 */
		if (0 + 0 < p->cost[_con_NT]) {
			p->cost[_con_NT] = 0 + 0;
			p->rule._con = 3;
			_closure_con(a, 0 + 0);
		}
		/* reg: CNSTI4 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 9;
			_closure_reg(a, c + 0);
		}
		break;
	case 4118: /* CNSTU4 */
		/* con: CNSTU4 */
		if (0 + 0 < p->cost[_con_NT]) {
			p->cost[_con_NT] = 0 + 0;
			p->rule._con = 4;
			_closure_con(a, 0 + 0);
		}
		/* reg: CNSTU4 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 11;
			_closure_reg(a, c + 0);
		}
		break;
	case 4119: /* CNSTP4 */
		/* con: CNSTP4 */
		if (0 + 0 < p->cost[_con_NT]) {
			p->cost[_con_NT] = 0 + 0;
			p->rule._con = 5;
			_closure_con(a, 0 + 0);
		}
		/* reg: CNSTP4 */
		c = (range(a, 0, 0));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 12;
			_closure_reg(a, c + 0);
		}
		/* ar: CNSTP4 */
		c = (range(a, 0, 0x0fffffff));
		if (c + 0 < p->cost[_ar_NT]) {
			p->cost[_ar_NT] = c + 0;
			p->rule._ar = 2;
		}
		/* magic_addr: CNSTP4 */
		c = (is_magic_addr(a));
		if (c + 0 < p->cost[_magic_addr_NT]) {
			p->cost[_magic_addr_NT] = c + 0;
			p->rule._magic_addr = 1;
		}
		break;
	case 4129: /* ARGF4 */
		_label(LEFT_CHILD(a));
		/* stmt: ARGF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 41;
		}
		break;
	case 4133: /* ARGI4 */
		_label(LEFT_CHILD(a));
		/* stmt: ARGI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 42;
		}
		break;
	case 4134: /* ARGU4 */
		_label(LEFT_CHILD(a));
		/* stmt: ARGU4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 44;
		}
		break;
	case 4135: /* ARGP4 */
		_label(LEFT_CHILD(a));
		/* stmt: ARGP4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 43;
		}
		break;
	case 4145: /* ASGNF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNF4(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 3;
			}
		}
		/* stmt: ASGNF4(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 13;
		}
		break;
	case 4149: /* ASGNI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNI4(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 4;
			}
		}
		/* stmt: ASGNI4(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 10;
		}
		break;
	case 4150: /* ASGNU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNU4(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 6;
			}
		}
		/* stmt: ASGNU4(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 11;
		}
		break;
	case 4151: /* ASGNP4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* stmt: ASGNP4(VREGP,reg) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			c = ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 0;
			if (c + 0 < p->cost[_stmt_NT]) {
				p->cost[_stmt_NT] = c + 0;
				p->rule._stmt = 5;
			}
		}
		/* stmt: ASGNP4(addr,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 12;
		}
		break;
	case 4161: /* INDIRF4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRF4(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 3;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRF4(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 22;
			_closure_reg(a, c + 0);
		}
		break;
	case 4165: /* INDIRI4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRI4(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 4;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRI4(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 16;
			_closure_reg(a, c + 0);
		}
		break;
	case 4166: /* INDIRU4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRU4(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 6;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRU4(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 17;
			_closure_reg(a, c + 0);
		}
		break;
	case 4167: /* INDIRP4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: INDIRP4(VREGP) */
			LEFT_CHILD(a)->op == 711 /* VREGP */
		) {
			if (mayrecalc(a)) {
				struct _state *q = a->syms[RX]->u.t.cse->x.state;
				if (q->cost[_stmt_NT] == 0) {
					p->cost[_stmt_NT] = 0;
					p->rule._stmt = q->rule._stmt;
				}
				if (q->cost[_reg_NT] == 0) {
					p->cost[_reg_NT] = 0;
					p->rule._reg = q->rule._reg;
				}
				if (q->cost[_con_NT] == 0) {
					p->cost[_con_NT] = 0;
					p->rule._con = q->rule._con;
				}
				if (q->cost[_acon_NT] == 0) {
					p->cost[_acon_NT] = 0;
					p->rule._acon = q->rule._acon;
				}
				if (q->cost[_addr_NT] == 0) {
					p->cost[_addr_NT] = 0;
					p->rule._addr = q->rule._addr;
				}
				if (q->cost[_rc_NT] == 0) {
					p->cost[_rc_NT] = 0;
					p->rule._rc = q->rule._rc;
				}
				if (q->cost[_ar_NT] == 0) {
					p->cost[_ar_NT] = 0;
					p->rule._ar = q->rule._ar;
				}
				if (q->cost[_magic_addr_NT] == 0) {
					p->cost[_magic_addr_NT] = 0;
					p->rule._magic_addr = q->rule._magic_addr;
				}
			}
			c = 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 5;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: INDIRP4(addr) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_addr_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 18;
			_closure_reg(a, c + 0);
		}
		break;
	case 4209: /* CVFF4 */
		_label(LEFT_CHILD(a));
		/* reg: CVFF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 66;
			_closure_reg(a, c + 0);
		}
		break;
	case 4213: /* CVFI4 */
		_label(LEFT_CHILD(a));
		/* reg: CVFI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 68;
			_closure_reg(a, c + 0);
		}
		break;
	case 4225: /* CVIF4 */
		_label(LEFT_CHILD(a));
		/* reg: CVIF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 67;
			_closure_reg(a, c + 0);
		}
		break;
	case 4229: /* CVII4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: CVII4(INDIRI1(addr)) */
			LEFT_CHILD(a)->op == 1093 /* INDIRI1 */
		) {
			c = ((struct _state *)(LEFT_CHILD(LEFT_CHILD(a))->x.state))->cost[_addr_NT] + 1;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 19;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: CVII4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 63;
			_closure_reg(a, c + 0);
		}
		break;
	case 4230: /* CVIU4 */
		break;
	case 4246: /* CVPU4 */
		break;
	case 4277: /* CVUI4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: CVUI4(INDIRU1(addr)) */
			LEFT_CHILD(a)->op == 1094 /* INDIRU1 */
		) {
			c = ((struct _state *)(LEFT_CHILD(LEFT_CHILD(a))->x.state))->cost[_addr_NT] + 2;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 21;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: CVUI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 64;
			_closure_reg(a, c + 0);
		}
		break;
	case 4278: /* CVUU4 */
		_label(LEFT_CHILD(a));
		if (	/* reg: CVUU4(INDIRU1(addr)) */
			LEFT_CHILD(a)->op == 1094 /* INDIRU1 */
		) {
			c = ((struct _state *)(LEFT_CHILD(LEFT_CHILD(a))->x.state))->cost[_addr_NT] + 2;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 20;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: CVUU4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 65;
			_closure_reg(a, c + 0);
		}
		break;
	case 4279: /* CVUP4 */
		break;
	case 4289: /* NEGF4 */
		_label(LEFT_CHILD(a));
		/* reg: NEGF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 62;
			_closure_reg(a, c + 0);
		}
		break;
	case 4293: /* NEGI4 */
		_label(LEFT_CHILD(a));
		/* reg: NEGI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 51;
			_closure_reg(a, c + 0);
		}
		break;
	case 4305: /* CALLF4 */
		_label(LEFT_CHILD(a));
		/* reg: CALLF4(ar) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_ar_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 69;
			_closure_reg(a, c + 0);
		}
		break;
	case 4309: /* CALLI4 */
		_label(LEFT_CHILD(a));
		/* reg: CALLI4(ar) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_ar_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 70;
			_closure_reg(a, c + 0);
		}
		break;
	case 4310: /* CALLU4 */
		_label(LEFT_CHILD(a));
		/* reg: CALLU4(ar) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_ar_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 72;
			_closure_reg(a, c + 0);
		}
		break;
	case 4311: /* CALLP4 */
		_label(LEFT_CHILD(a));
		/* reg: CALLP4(ar) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_ar_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 71;
			_closure_reg(a, c + 0);
		}
		break;
	case 4321: /* LOADF4 */
		_label(LEFT_CHILD(a));
		/* reg: LOADF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 57;
			_closure_reg(a, c + 0);
		}
		break;
	case 4325: /* LOADI4 */
		_label(LEFT_CHILD(a));
		/* reg: LOADI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 54;
			_closure_reg(a, c + 0);
		}
		break;
	case 4326: /* LOADU4 */
		_label(LEFT_CHILD(a));
		/* reg: LOADU4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 56;
			_closure_reg(a, c + 0);
		}
		break;
	case 4327: /* LOADP4 */
		_label(LEFT_CHILD(a));
		/* reg: LOADP4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + (move(a));
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 55;
			_closure_reg(a, c + 0);
		}
		break;
	case 4337: /* RETF4 */
		_label(LEFT_CHILD(a));
		/* stmt: RETF4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 36;
		}
		break;
	case 4341: /* RETI4 */
		_label(LEFT_CHILD(a));
		/* stmt: RETI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 37;
		}
		break;
	case 4342: /* RETU4 */
		_label(LEFT_CHILD(a));
		/* stmt: RETU4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 38;
		}
		break;
	case 4343: /* RETP4 */
		_label(LEFT_CHILD(a));
		/* stmt: RETP4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 39;
		}
		break;
	case 4359: /* ADDRGP4 */
		/* acon: ADDRGP4 */
		if (0 + 0 < p->cost[_acon_NT]) {
			p->cost[_acon_NT] = 0 + 0;
			p->rule._acon = 2;
			_closure_acon(a, 0 + 0);
		}
		/* ar: ADDRGP4 */
		if (0 + 0 < p->cost[_ar_NT]) {
			p->cost[_ar_NT] = 0 + 0;
			p->rule._ar = 3;
		}
		break;
	case 4375: /* ADDRFP4 */
		/* addr: ADDRFP4 */
		if (0 + 0 < p->cost[_addr_NT]) {
			p->cost[_addr_NT] = 0 + 0;
			p->rule._addr = 6;
			_closure_addr(a, 0 + 0);
		}
		break;
	case 4391: /* ADDRLP4 */
		/* addr: ADDRLP4 */
		if (0 + 0 < p->cost[_addr_NT]) {
			p->cost[_addr_NT] = 0 + 0;
			p->rule._addr = 7;
			_closure_addr(a, 0 + 0);
		}
		break;
	case 4401: /* ADDF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: ADDF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 58;
			_closure_reg(a, c + 0);
		}
		break;
	case 4405: /* ADDI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* addr: ADDI4(reg,acon) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_acon_NT] + 0;
		if (c + 0 < p->cost[_addr_NT]) {
			p->cost[_addr_NT] = c + 0;
			p->rule._addr = 1;
			_closure_addr(a, c + 0);
		}
		/* reg: ADDI4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 29;
			_closure_reg(a, c + 0);
		}
		if (	/* reg: ADDI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
			RIGHT_CHILD(a)->op == 4405 && /* ADDI4 */
			RIGHT_CHILD(RIGHT_CHILD(a))->op == 4165 /* INDIRI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->x.state))->cost[_magic_addr_NT] + 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 73;
				_closure_reg(a, c + 0);
			}
		}
		if (	/* reg: ADDI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
			RIGHT_CHILD(a)->op == 4421 && /* SUBI4 */
			RIGHT_CHILD(RIGHT_CHILD(a))->op == 4165 /* INDIRI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->x.state))->cost[_magic_addr_NT] + 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 75;
				_closure_reg(a, c + 0);
			}
		}
		break;
	case 4406: /* ADDU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* addr: ADDU4(reg,acon) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_acon_NT] + 0;
		if (c + 0 < p->cost[_addr_NT]) {
			p->cost[_addr_NT] = c + 0;
			p->rule._addr = 2;
			_closure_addr(a, c + 0);
		}
		/* reg: ADDU4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 31;
			_closure_reg(a, c + 0);
		}
		break;
	case 4407: /* ADDP4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* addr: ADDP4(reg,acon) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_acon_NT] + 0;
		if (c + 0 < p->cost[_addr_NT]) {
			p->cost[_addr_NT] = c + 0;
			p->rule._addr = 3;
			_closure_addr(a, c + 0);
		}
		/* reg: ADDP4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 30;
			_closure_reg(a, c + 0);
		}
		break;
	case 4417: /* SUBF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: SUBF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 59;
			_closure_reg(a, c + 0);
		}
		break;
	case 4421: /* SUBI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: SUBI4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 38;
			_closure_reg(a, c + 0);
		}
		if (	/* reg: SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
			RIGHT_CHILD(a)->op == 4405 && /* ADDI4 */
			RIGHT_CHILD(RIGHT_CHILD(a))->op == 4165 /* INDIRI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->x.state))->cost[_magic_addr_NT] + 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 74;
				_closure_reg(a, c + 0);
			}
		}
		if (	/* reg: SUBI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
			RIGHT_CHILD(a)->op == 4421 && /* SUBI4 */
			RIGHT_CHILD(RIGHT_CHILD(a))->op == 4165 /* INDIRI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->x.state))->cost[_magic_addr_NT] + 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 76;
				_closure_reg(a, c + 0);
			}
		}
		if (	/* reg: SUBI4(reg,SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr)))) */
			RIGHT_CHILD(a)->op == 4421 && /* SUBI4 */
			RIGHT_CHILD(RIGHT_CHILD(a))->op == 4405 && /* ADDI4 */
			RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->op == 4165 /* INDIRI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(a))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))->x.state))->cost[_reg_NT] + ((struct _state *)(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a))))->x.state))->cost[_magic_addr_NT] + 0;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 77;
				_closure_reg(a, c + 0);
			}
		}
		break;
	case 4422: /* SUBU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: SUBU4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 40;
			_closure_reg(a, c + 0);
		}
		break;
	case 4423: /* SUBP4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: SUBP4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 39;
			_closure_reg(a, c + 0);
		}
		break;
	case 4437: /* LSHI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* reg: LSHI4(reg,CNSTI4) */
			RIGHT_CHILD(a)->op == 4117 /* CNSTI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 4;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 41;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: LSHI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 45;
			_closure_reg(a, c + 0);
		}
		break;
	case 4438: /* LSHU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* reg: LSHU4(reg,CNSTI4) */
			RIGHT_CHILD(a)->op == 4117 /* CNSTI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 4;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 42;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: LSHU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 46;
			_closure_reg(a, c + 0);
		}
		break;
	case 4453: /* MODI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: MODI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 25;
			_closure_reg(a, c + 0);
		}
		break;
	case 4454: /* MODU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: MODU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 26;
			_closure_reg(a, c + 0);
		}
		break;
	case 4469: /* RSHI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* reg: RSHI4(reg,CNSTI4) */
			RIGHT_CHILD(a)->op == 4117 /* CNSTI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 4;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 43;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: RSHI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 47;
			_closure_reg(a, c + 0);
		}
		break;
	case 4470: /* RSHU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		if (	/* reg: RSHU4(reg,CNSTI4) */
			RIGHT_CHILD(a)->op == 4117 /* CNSTI4 */
		) {
			c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 4;
			if (c + 0 < p->cost[_reg_NT]) {
				p->cost[_reg_NT] = c + 0;
				p->rule._reg = 44;
				_closure_reg(a, c + 0);
			}
		}
		/* reg: RSHU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 48;
			_closure_reg(a, c + 0);
		}
		break;
	case 4485: /* BANDI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BANDI4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 32;
			_closure_reg(a, c + 0);
		}
		break;
	case 4486: /* BANDU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BANDU4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 35;
			_closure_reg(a, c + 0);
		}
		break;
	case 4501: /* BCOMI4 */
		_label(LEFT_CHILD(a));
		/* reg: BCOMI4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 49;
			_closure_reg(a, c + 0);
		}
		break;
	case 4502: /* BCOMU4 */
		_label(LEFT_CHILD(a));
		/* reg: BCOMU4(reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 50;
			_closure_reg(a, c + 0);
		}
		break;
	case 4517: /* BORI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BORI4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 33;
			_closure_reg(a, c + 0);
		}
		break;
	case 4518: /* BORU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BORU4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 36;
			_closure_reg(a, c + 0);
		}
		break;
	case 4533: /* BXORI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BXORI4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 34;
			_closure_reg(a, c + 0);
		}
		break;
	case 4534: /* BXORU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: BXORU4(reg,rc) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_rc_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 37;
			_closure_reg(a, c + 0);
		}
		break;
	case 4545: /* DIVF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: DIVF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 61;
			_closure_reg(a, c + 0);
		}
		break;
	case 4549: /* DIVI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: DIVI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 23;
			_closure_reg(a, c + 0);
		}
		break;
	case 4550: /* DIVU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: DIVU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 24;
			_closure_reg(a, c + 0);
		}
		break;
	case 4561: /* MULF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: MULF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 100;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 60;
			_closure_reg(a, c + 0);
		}
		break;
	case 4565: /* MULI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: MULI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 27;
			_closure_reg(a, c + 0);
		}
		break;
	case 4566: /* MULU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* reg: MULU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_reg_NT]) {
			p->cost[_reg_NT] = c + 0;
			p->rule._reg = 28;
			_closure_reg(a, c + 0);
		}
		break;
	case 4577: /* EQF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: EQF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 29;
		}
		break;
	case 4581: /* EQI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: EQI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 17;
		}
		break;
	case 4582: /* EQU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: EQU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 18;
		}
		break;
	case 4593: /* GEF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GEF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 33;
		}
		break;
	case 4597: /* GEI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GEI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 25;
		}
		break;
	case 4598: /* GEU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GEU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 26;
		}
		break;
	case 4609: /* GTF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GTF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 34;
		}
		break;
	case 4613: /* GTI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GTI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 23;
		}
		break;
	case 4614: /* GTU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: GTU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 24;
		}
		break;
	case 4625: /* LEF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LEF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 31;
		}
		break;
	case 4629: /* LEI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LEI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 27;
		}
		break;
	case 4630: /* LEU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LEU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 28;
		}
		break;
	case 4641: /* LTF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LTF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 32;
		}
		break;
	case 4645: /* LTI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LTI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 21;
		}
		break;
	case 4646: /* LTU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: LTU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 2;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 22;
		}
		break;
	case 4657: /* NEF4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: NEF4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 30;
		}
		break;
	case 4661: /* NEI4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: NEI4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 19;
		}
		break;
	case 4662: /* NEU4 */
		_label(LEFT_CHILD(a));
		_label(RIGHT_CHILD(a));
		/* stmt: NEU4(reg,reg) */
		c = ((struct _state *)(LEFT_CHILD(a)->x.state))->cost[_reg_NT] + ((struct _state *)(RIGHT_CHILD(a)->x.state))->cost[_reg_NT] + 1;
		if (c + 0 < p->cost[_stmt_NT]) {
			p->cost[_stmt_NT] = c + 0;
			p->rule._stmt = 20;
		}
		break;
	case 8417: /* LOADF8 */
		break;
	case 8421: /* LOADI8 */
		break;
	case 8422: /* LOADU8 */
		break;
	case 8423: /* LOADP8 */
		break;
	case 16609: /* LOADF16 */
		break;
	default:
		fatal("_label", "Bad terminal %d\n", OP_LABEL(a));
	}
}

static void _kids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		fatal("_kids", "Null tree\n", 0);
	if (!kids)
		fatal("_kids", "Null kids\n", 0);
	switch (eruleno) {
	case 127: /* magic_addr: CNSTP4 */
	case 126: /* ar: ADDRGP4 */
	case 125: /* ar: CNSTP4 */
	case 98: /* stmt: LABELV */
	case 34: /* reg: CNSTF4 */
	case 33: /* reg: CNSTP4 */
	case 32: /* reg: CNSTU4 */
	case 31: /* reg: CNSTU1 */
	case 30: /* reg: CNSTI4 */
	case 29: /* reg: CNSTI1 */
	case 27: /* addr: ADDRLP4 */
	case 26: /* addr: ADDRFP4 */
	case 20: /* acon: ADDRGP4 */
	case 17: /* con: CNSTP4 */
	case 16: /* con: CNSTU4 */
	case 15: /* con: CNSTI4 */
	case 14: /* con: CNSTU1 */
	case 13: /* con: CNSTI1 */
	case 6: /* reg: INDIRU4(VREGP) */
	case 5: /* reg: INDIRP4(VREGP) */
	case 4: /* reg: INDIRI4(VREGP) */
	case 3: /* reg: INDIRF4(VREGP) */
	case 2: /* reg: INDIRU1(VREGP) */
	case 1: /* reg: INDIRI1(VREGP) */
		break;
	case 12: /* stmt: ASGNU4(VREGP,reg) */
	case 11: /* stmt: ASGNP4(VREGP,reg) */
	case 10: /* stmt: ASGNI4(VREGP,reg) */
	case 9: /* stmt: ASGNF4(VREGP,reg) */
	case 8: /* stmt: ASGNU1(VREGP,reg) */
	case 7: /* stmt: ASGNI1(VREGP,reg) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 124: /* ar: reg */
	case 57: /* rc: reg */
	case 56: /* rc: con */
	case 28: /* reg: addr */
	case 25: /* addr: reg */
	case 24: /* addr: acon */
	case 19: /* acon: con */
	case 18: /* stmt: reg */
		kids[0] = p;
		break;
	case 118: /* stmt: GTF4(reg,reg) */
	case 117: /* stmt: GEF4(reg,reg) */
	case 116: /* stmt: LTF4(reg,reg) */
	case 115: /* stmt: LEF4(reg,reg) */
	case 114: /* stmt: NEF4(reg,reg) */
	case 113: /* stmt: EQF4(reg,reg) */
	case 112: /* stmt: LEU4(reg,reg) */
	case 111: /* stmt: LEI4(reg,reg) */
	case 110: /* stmt: GEU4(reg,reg) */
	case 109: /* stmt: GEI4(reg,reg) */
	case 108: /* stmt: GTU4(reg,reg) */
	case 107: /* stmt: GTI4(reg,reg) */
	case 106: /* stmt: LTU4(reg,reg) */
	case 105: /* stmt: LTI4(reg,reg) */
	case 104: /* stmt: NEU4(reg,reg) */
	case 103: /* stmt: NEI4(reg,reg) */
	case 102: /* stmt: EQU4(reg,reg) */
	case 101: /* stmt: EQI4(reg,reg) */
	case 90: /* reg: DIVF4(reg,reg) */
	case 89: /* reg: MULF4(reg,reg) */
	case 88: /* reg: SUBF4(reg,reg) */
	case 87: /* reg: ADDF4(reg,reg) */
	case 77: /* reg: RSHU4(reg,reg) */
	case 76: /* reg: RSHI4(reg,reg) */
	case 75: /* reg: LSHU4(reg,reg) */
	case 74: /* reg: LSHI4(reg,reg) */
	case 69: /* reg: SUBU4(reg,rc) */
	case 68: /* reg: SUBP4(reg,rc) */
	case 67: /* reg: SUBI4(reg,rc) */
	case 66: /* reg: BXORU4(reg,rc) */
	case 65: /* reg: BORU4(reg,rc) */
	case 64: /* reg: BANDU4(reg,rc) */
	case 63: /* reg: BXORI4(reg,rc) */
	case 62: /* reg: BORI4(reg,rc) */
	case 61: /* reg: BANDI4(reg,rc) */
	case 60: /* reg: ADDU4(reg,rc) */
	case 59: /* reg: ADDP4(reg,rc) */
	case 58: /* reg: ADDI4(reg,rc) */
	case 55: /* reg: MULU4(reg,reg) */
	case 54: /* reg: MULI4(reg,reg) */
	case 53: /* reg: MODU4(reg,reg) */
	case 52: /* reg: MODI4(reg,reg) */
	case 51: /* reg: DIVU4(reg,reg) */
	case 50: /* reg: DIVI4(reg,reg) */
	case 49: /* stmt: ASGNF4(addr,reg) */
	case 39: /* stmt: ASGNP4(addr,reg) */
	case 38: /* stmt: ASGNU4(addr,reg) */
	case 37: /* stmt: ASGNI4(addr,reg) */
	case 36: /* stmt: ASGNU1(addr,reg) */
	case 35: /* stmt: ASGNI1(addr,reg) */
	case 23: /* addr: ADDP4(reg,acon) */
	case 22: /* addr: ADDU4(reg,acon) */
	case 21: /* addr: ADDI4(reg,acon) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 141: /* stmt: ARGU4(reg) */
	case 140: /* stmt: ARGP4(reg) */
	case 139: /* stmt: ARGI4(reg) */
	case 138: /* stmt: ARGF4(reg) */
	case 137: /* stmt: RETV(reg) */
	case 136: /* stmt: RETP4(reg) */
	case 135: /* stmt: RETU4(reg) */
	case 134: /* stmt: RETI4(reg) */
	case 133: /* stmt: RETF4(reg) */
	case 123: /* stmt: CALLV(ar) */
	case 122: /* reg: CALLU4(ar) */
	case 121: /* reg: CALLP4(ar) */
	case 120: /* reg: CALLI4(ar) */
	case 119: /* reg: CALLF4(ar) */
	case 100: /* stmt: JUMPV(reg) */
	case 99: /* stmt: JUMPV(acon) */
	case 97: /* reg: CVFI4(reg) */
	case 96: /* reg: CVIF4(reg) */
	case 95: /* reg: CVFF4(reg) */
	case 94: /* reg: CVUU4(reg) */
	case 93: /* reg: CVUI4(reg) */
	case 92: /* reg: CVII4(reg) */
	case 91: /* reg: NEGF4(reg) */
	case 86: /* reg: LOADF4(reg) */
	case 85: /* reg: LOADU4(reg) */
	case 84: /* reg: LOADP4(reg) */
	case 83: /* reg: LOADI4(reg) */
	case 82: /* reg: LOADU1(reg) */
	case 81: /* reg: LOADI1(reg) */
	case 80: /* reg: NEGI4(reg) */
	case 79: /* reg: BCOMU4(reg) */
	case 78: /* reg: BCOMI4(reg) */
	case 73: /* reg: RSHU4(reg,CNSTI4) */
	case 72: /* reg: RSHI4(reg,CNSTI4) */
	case 71: /* reg: LSHU4(reg,CNSTI4) */
	case 70: /* reg: LSHI4(reg,CNSTI4) */
	case 48: /* reg: INDIRF4(addr) */
	case 44: /* reg: INDIRP4(addr) */
	case 43: /* reg: INDIRU4(addr) */
	case 42: /* reg: INDIRI4(addr) */
	case 41: /* reg: INDIRU1(addr) */
	case 40: /* reg: INDIRI1(addr) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 142: /* stmt: ARGB(INDIRB(reg)) */
	case 47: /* reg: CVUI4(INDIRU1(addr)) */
	case 46: /* reg: CVUU4(INDIRU1(addr)) */
	case 45: /* reg: CVII4(INDIRI1(addr)) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		break;
	case 131: /* reg: SUBI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
	case 130: /* reg: ADDI4(reg,SUBI4(reg,INDIRI4(magic_addr))) */
	case 129: /* reg: SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
	case 128: /* reg: ADDI4(reg,ADDI4(reg,INDIRI4(magic_addr))) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		break;
	case 132: /* reg: SUBI4(reg,SUBI4(reg,ADDI4(reg,INDIRI4(magic_addr)))) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		kids[3] = LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p))));
		break;
	case 143: /* stmt: ASGNB(reg,INDIRB(reg)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	default:
		fatal("_kids", "Bad rule number %d\n", eruleno);
	}
}

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
