/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/martijn/Documents/GitHub/Computation-2/Mips Work Folder/Assigment 1/verilog_fsm poging 2/verilog_fsm/fsm_lock.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {2U, 0U};
static int ng6[] = {2, 0};
static unsigned int ng7[] = {3U, 0U};
static int ng8[] = {3, 0};
static unsigned int ng9[] = {4U, 0U};
static int ng10[] = {4, 0};
static unsigned int ng11[] = {5U, 0U};
static int ng12[] = {5, 0};



static void Initial_51_0(char *t0)
{
    char t2[8];
    char *t1;
    char *t3;

LAB0:    xsi_set_current_line(51, ng0);

LAB2:    xsi_set_current_line(52, ng0);
    t1 = ((char*)((ng1)));
    memcpy(t2, t1, 8);
    t3 = (t0 + 3064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(53, ng0);
    t1 = ((char*)((ng1)));
    memcpy(t2, t1, 8);
    t3 = (t0 + 3224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB1:    return;
}

static void Always_55_1(char *t0)
{
    char t12[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t13;
    int t14;

LAB0:    t1 = (t0 + 4392U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 4960);
    *((int *)t2) = 1;
    t3 = (t0 + 4424);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(55, ng0);

LAB5:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 3224);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3064);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 4);

LAB8:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 3064);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB9:    t5 = ((char*)((ng1)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t5, 3);
    if (t14 == 1)
        goto LAB10;

LAB11:    t2 = ((char*)((ng3)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t14 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng5)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t14 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng7)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t14 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng9)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t14 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng11)));
    t14 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t14 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB2;

LAB6:    xsi_set_current_line(57, ng0);
    t11 = ((char*)((ng1)));
    memcpy(t12, t11, 8);
    t13 = (t0 + 3224);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 4);
    goto LAB8;

LAB10:    xsi_set_current_line(63, ng0);

LAB23:    xsi_set_current_line(66, ng0);
    t11 = ((char*)((ng2)));
    t13 = (t0 + 2904);
    xsi_vlogvar_assign_value(t13, t11, 0, 0, 4);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB22;

LAB12:    xsi_set_current_line(74, ng0);

LAB27:    xsi_set_current_line(77, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB28;

LAB29:
LAB30:    goto LAB22;

LAB14:    xsi_set_current_line(86, ng0);

LAB31:    xsi_set_current_line(89, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB32;

LAB33:
LAB34:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB22;

LAB16:    xsi_set_current_line(98, ng0);

LAB38:    xsi_set_current_line(101, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(102, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB39;

LAB40:
LAB41:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB42;

LAB43:
LAB44:    goto LAB22;

LAB18:    xsi_set_current_line(110, ng0);

LAB45:    xsi_set_current_line(113, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 4);
    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB46;

LAB47:
LAB48:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB49;

LAB50:
LAB51:    goto LAB22;

LAB20:    xsi_set_current_line(122, ng0);

LAB52:    xsi_set_current_line(125, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 2744);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 2);
    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 2904);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB53;

LAB54:
LAB55:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB56;

LAB57:
LAB58:    goto LAB22;

LAB24:    xsi_set_current_line(69, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB26;

LAB28:    xsi_set_current_line(80, ng0);
    t5 = ((char*)((ng5)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB30;

LAB32:    xsi_set_current_line(92, ng0);
    t5 = ((char*)((ng7)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB34;

LAB35:    xsi_set_current_line(95, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB37;

LAB39:    xsi_set_current_line(104, ng0);
    t5 = ((char*)((ng9)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB41;

LAB42:    xsi_set_current_line(107, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB44;

LAB46:    xsi_set_current_line(116, ng0);
    t5 = ((char*)((ng11)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB48;

LAB49:    xsi_set_current_line(119, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB51;

LAB53:    xsi_set_current_line(128, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB55;

LAB56:    xsi_set_current_line(131, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t12, t5, 8);
    t11 = (t0 + 3224);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 4);
    goto LAB58;

}

static void Always_155_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 4640U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(155, ng0);
    t2 = (t0 + 4976);
    *((int *)t2) = 1;
    t3 = (t0 + 4672);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(155, ng0);

LAB5:    xsi_set_current_line(156, ng0);
    t4 = (t0 + 3224);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3064);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 4);
    goto LAB2;

}


extern void work_m_00000000003363890335_2953017523_init()
{
	static char *pe[] = {(void *)Initial_51_0,(void *)Always_55_1,(void *)Always_155_2};
	xsi_register_didat("work_m_00000000003363890335_2953017523", "isim/fsm_lock_tb_isim_beh.exe.sim/work/m_00000000003363890335_2953017523.didat");
	xsi_register_executes(pe);
}
