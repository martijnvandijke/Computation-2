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
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static int ng5[] = {0, 0};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {5U, 0U};
static int ng8[] = {1, 0};



static void Always_32_0(char *t0)
{
    char t15[8];
    char t30[8];
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
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t31;

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

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 3);
    if (t8 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(39, ng0);

LAB20:    xsi_set_current_line(40, ng0);
    t6 = (t0 + 2184U);
    t7 = *((char **)t6);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB21;

LAB22:
LAB23:    goto LAB19;

LAB9:    xsi_set_current_line(44, ng0);

LAB24:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 2344U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB25;

LAB26:
LAB27:    xsi_set_current_line(48, ng0);
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

LAB11:    xsi_set_current_line(52, ng0);

LAB31:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 2344U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB32;

LAB33:
LAB34:    xsi_set_current_line(56, ng0);
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

LAB13:    xsi_set_current_line(60, ng0);

LAB38:    xsi_set_current_line(61, ng0);
    t3 = (t0 + 2184U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng5)));
    memset(t15, 0, 8);
    t6 = (t5 + 4);
    t7 = (t3 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t3);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    t17 = (t12 ^ t13);
    t18 = (t11 | t17);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t7);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB42;

LAB39:    if (t21 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t15) = 1;

LAB42:    t16 = (t15 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t26 = *((unsigned int *)t15);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB43;

LAB44:
LAB45:    xsi_set_current_line(64, ng0);
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

LAB15:    xsi_set_current_line(68, ng0);

LAB49:    xsi_set_current_line(69, ng0);
    t3 = (t0 + 2344U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB50;

LAB51:
LAB52:    xsi_set_current_line(72, ng0);
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

LAB17:    xsi_set_current_line(77, ng0);

LAB56:    xsi_set_current_line(78, ng0);
    t3 = (t0 + 2344U);
    t5 = *((char **)t3);
    t3 = (t5 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (~(t9));
    t11 = *((unsigned int *)t5);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB57;

LAB58:
LAB59:    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t15, t2, 8);
    t3 = (t0 + 3224);
    xsi_vlogvar_assign_value(t3, t15, 0, 0, 4);
    xsi_set_current_line(83, ng0);
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

LAB21:    xsi_set_current_line(41, ng0);
    t14 = ((char*)((ng2)));
    memcpy(t15, t14, 8);
    t16 = (t0 + 3224);
    xsi_vlogvar_assign_value(t16, t15, 0, 0, 4);
    goto LAB23;

LAB25:    xsi_set_current_line(46, ng0);
    t6 = ((char*)((ng3)));
    memcpy(t15, t6, 8);
    t7 = (t0 + 3224);
    xsi_vlogvar_assign_value(t7, t15, 0, 0, 4);
    goto LAB27;

LAB28:    xsi_set_current_line(49, ng0);
    t5 = ((char*)((ng2)));
    memcpy(t15, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 4);
    goto LAB30;

LAB32:    xsi_set_current_line(54, ng0);
    t6 = ((char*)((ng4)));
    memcpy(t15, t6, 8);
    t7 = (t0 + 3224);
    xsi_vlogvar_assign_value(t7, t15, 0, 0, 4);
    goto LAB34;

LAB35:    xsi_set_current_line(57, ng0);
    t5 = ((char*)((ng2)));
    memcpy(t15, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 4);
    goto LAB37;

LAB41:    t14 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(62, ng0);
    t29 = ((char*)((ng6)));
    memcpy(t30, t29, 8);
    t31 = (t0 + 3224);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 4);
    goto LAB45;

LAB46:    xsi_set_current_line(65, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t15, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 4);
    goto LAB48;

LAB50:    xsi_set_current_line(70, ng0);
    t6 = ((char*)((ng6)));
    memcpy(t15, t6, 8);
    t7 = (t0 + 3224);
    xsi_vlogvar_assign_value(t7, t15, 0, 0, 4);
    goto LAB52;

LAB53:    xsi_set_current_line(73, ng0);
    t5 = ((char*)((ng2)));
    memcpy(t15, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 4);
    goto LAB55;

LAB57:    xsi_set_current_line(79, ng0);
    t6 = ((char*)((ng8)));
    t7 = (t0 + 2744);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    goto LAB59;

LAB60:    xsi_set_current_line(84, ng0);
    t5 = ((char*)((ng2)));
    memcpy(t15, t5, 8);
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t15, 0, 0, 4);
    goto LAB62;

}


extern void work_m_00000000001200676989_2953017523_init()
{
	static char *pe[] = {(void *)Always_32_0};
	xsi_register_didat("work_m_00000000001200676989_2953017523", "isim/fsm_lock_isim_beh.exe.sim/work/m_00000000001200676989_2953017523.didat");
	xsi_register_executes(pe);
}
