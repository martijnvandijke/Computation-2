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



static void Always_32_0(char *t0)
{
    char t14[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t30;

LAB0:    t1 = (t0 + 4144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 4464);
    *((int *)t2) = 1;
    t3 = (t0 + 4176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(32, ng0);

LAB5:    xsi_set_current_line(33, ng0);
    t4 = (t0 + 3064);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3224);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 4);
    xsi_set_current_line(38, ng0);
    t2 = (t0 + 3064);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t5, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(39, ng0);

LAB20:    xsi_set_current_line(40, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 2904);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB21;

LAB22:
LAB23:    goto LAB19;

LAB9:    xsi_set_current_line(46, ng0);

LAB24:    xsi_set_current_line(47, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB25;

LAB26:
LAB27:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB28;

LAB29:
LAB30:    goto LAB19;

LAB11:    xsi_set_current_line(56, ng0);

LAB31:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB32;

LAB33:
LAB34:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB37:    goto LAB19;

LAB13:    xsi_set_current_line(66, ng0);

LAB38:    xsi_set_current_line(67, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t14, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t15 = (t12 ^ t13);
    t16 = (t11 | t15);
    t17 = *((unsigned int *)t5);
    t18 = *((unsigned int *)t6);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB42;

LAB39:    if (t19 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t14) = 1;

LAB42:    t22 = (t14 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t14);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB43;

LAB44:
LAB45:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB46;

LAB47:
LAB48:    goto LAB19;

LAB15:    xsi_set_current_line(76, ng0);

LAB49:    xsi_set_current_line(77, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB50;

LAB51:
LAB52:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB53;

LAB54:
LAB55:    goto LAB19;

LAB17:    xsi_set_current_line(87, ng0);

LAB56:    xsi_set_current_line(88, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 2904);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB57;

LAB58:
LAB59:    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t14, t2, 8);
    t3 = (t0 + 3224);
    xsi_vlogvar_assign_value(t3, t14, 0, 0, 4);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB60;

LAB61:
LAB62:    goto LAB19;

LAB21:    xsi_set_current_line(43, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB23;

LAB25:    xsi_set_current_line(50, ng0);
    t5 = ((char*)((ng5)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB27;

LAB28:    xsi_set_current_line(53, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB30;

LAB32:    xsi_set_current_line(60, ng0);
    t5 = ((char*)((ng7)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB34;

LAB35:    xsi_set_current_line(63, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB37;

LAB41:    t7 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(70, ng0);
    t28 = ((char*)((ng9)));
    memcpy(t29, t28, 8);
    t30 = (t0 + 3224);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 4);
    goto LAB45;

LAB46:    xsi_set_current_line(73, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB48;

LAB50:    xsi_set_current_line(80, ng0);
    t5 = ((char*)((ng9)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB52;

LAB53:    xsi_set_current_line(83, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB55;

LAB57:    xsi_set_current_line(91, ng0);
    t5 = ((char*)((ng4)));
    t6 = (t0 + 2744);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 1);
    goto LAB59;

LAB60:    xsi_set_current_line(96, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB62;

}


extern void work_m_00000000001200676989_2953017523_init()
{
	static char *pe[] = {(void *)Always_32_0};
	xsi_register_didat("work_m_00000000001200676989_2953017523", "isim/fsm_lock_tb_isim_beh.exe.sim/work/m_00000000001200676989_2953017523.didat");
	xsi_register_executes(pe);
}
