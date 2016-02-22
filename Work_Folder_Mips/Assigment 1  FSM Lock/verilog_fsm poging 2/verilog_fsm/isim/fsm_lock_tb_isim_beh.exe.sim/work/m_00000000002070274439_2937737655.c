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
static const char *ng0 = "C:/Users/martijn/Documents/GitHub/Computation-2/Mips Work Folder/Assigment 1/verilog_fsm poging 2/verilog_fsm/fsm_lock_tb.v";
static const char *ng1 = "trace.txt";
static const char *ng2 = "w";
static int ng3[] = {0, 0};
static int ng4[] = {1, 0};
static int ng5[] = {32, 0};
static int ng6[] = {4, 0};
static const char *ng7 = "Completed input.";
static int ng8[] = {13, 0};
static const char *ng9 = "Correctly opens using %5b";
static const char *ng10 = "ERROR! opens using %5b";
static const char *ng11 = "%5b\t%1d\t%4b\t%b\n";



static void Initial_31_0(char *t0)
{
    char t3[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;

LAB0:    t1 = (t0 + 3808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);

LAB4:    xsi_set_current_line(32, ng0);
    *((int *)t3) = xsi_vlogfile_file_open_of_cname_ctype(ng1, ng2);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = (t0 + 2728);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(34, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(35, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(41, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(43, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 2888);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);
    xsi_set_current_line(47, ng0);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2248);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB7:    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng5)));
    memset(t3, 0, 8);
    xsi_vlog_signed_less(t3, 32, t5, 32, t6, 32);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB8:    xsi_set_current_line(47, ng0);

LAB10:    xsi_set_current_line(49, ng0);
    xsi_set_current_line(49, ng0);
    t13 = ((char*)((ng6)));
    t14 = (t0 + 2568);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);

LAB11:    t2 = (t0 + 2568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t3, 0, 8);
    xsi_vlog_signed_greatereq(t3, 32, t5, 32, t6, 32);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng4)));
    memset(t3, 0, 8);
    xsi_vlog_signed_add(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2248);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 32);
    goto LAB7;

LAB12:    xsi_set_current_line(49, ng0);

LAB14:    xsi_set_current_line(50, ng0);
    t13 = (t0 + 3616);
    xsi_process_wait(t13, 100000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(51, ng0);
    t14 = ((char*)((ng4)));
    t15 = (t0 + 1768);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng6)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB17:    t2 = (t0 + 2408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2568);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    memset(t3, 0, 8);
    xsi_vlog_signed_greater(t3, 32, t5, 32, t13, 32);
    t14 = (t3 + 4);
    t8 = *((unsigned int *)t14);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB18:    xsi_set_current_line(59, ng0);

LAB20:    xsi_set_current_line(60, ng0);
    t15 = (t0 + 3616);
    xsi_process_wait(t15, 100000LL);
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB21:    xsi_set_current_line(61, ng0);
    t16 = ((char*)((ng3)));
    t17 = (t0 + 1768);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 1);
    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB22;
    goto LAB1;

LAB22:    xsi_set_current_line(65, ng0);
    t4 = (t0 + 2248);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2248);
    t13 = (t7 + 72U);
    t14 = *((char **)t13);
    t15 = (t0 + 2408);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    xsi_vlog_generic_get_index_select_value(t18, 1, t6, t14, 2, t17, 32, 1);
    memset(t3, 0, 8);
    t19 = (t18 + 4);
    t8 = *((unsigned int *)t19);
    t9 = (~(t8));
    t10 = *((unsigned int *)t18);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB26;

LAB24:    if (*((unsigned int *)t19) == 0)
        goto LAB23;

LAB25:    t20 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t20) = 1;

LAB26:    t21 = (t3 + 4);
    t22 = (t18 + 4);
    t23 = *((unsigned int *)t18);
    t24 = (~(t23));
    *((unsigned int *)t3) = t24;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t22) != 0)
        goto LAB28;

LAB27:    t29 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t29 & 1U);
    t30 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t30 & 1U);
    t31 = (t0 + 1928);
    xsi_vlogvar_assign_value(t31, t3, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2248);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = (t0 + 2408);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    xsi_vlog_generic_get_index_select_value(t3, 1, t5, t13, 2, t16, 32, 1);
    t17 = (t0 + 2088);
    xsi_vlogvar_assign_value(t17, t3, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng4)));
    memset(t3, 0, 8);
    xsi_vlog_signed_minus(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2408);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 32);
    goto LAB17;

LAB23:    *((unsigned int *)t3) = 1;
    goto LAB26;

LAB28:    t25 = *((unsigned int *)t3);
    t26 = *((unsigned int *)t22);
    *((unsigned int *)t3) = (t25 | t26);
    t27 = *((unsigned int *)t21);
    t28 = *((unsigned int *)t22);
    *((unsigned int *)t21) = (t27 | t28);
    goto LAB27;

LAB29:    xsi_set_current_line(69, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2408);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);

LAB30:    t2 = (t0 + 2408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t3, 0, 8);
    xsi_vlog_signed_greatereq(t3, 32, t5, 32, t6, 32);
    t7 = (t3 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2568);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng4)));
    memset(t3, 0, 8);
    xsi_vlog_signed_minus(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2568);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 32);
    goto LAB11;

LAB31:    xsi_set_current_line(72, ng0);

LAB33:    xsi_set_current_line(73, ng0);
    t13 = (t0 + 3616);
    xsi_process_wait(t13, 100000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB34:    xsi_set_current_line(74, ng0);
    t14 = ((char*)((ng3)));
    t15 = (t0 + 1768);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2088);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 3616);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB35:    xsi_set_current_line(78, ng0);
    t4 = (t0 + 2248);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2248);
    t13 = (t7 + 72U);
    t14 = *((char **)t13);
    t15 = (t0 + 2408);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    xsi_vlog_generic_get_index_select_value(t18, 1, t6, t14, 2, t17, 32, 1);
    memset(t3, 0, 8);
    t19 = (t18 + 4);
    t8 = *((unsigned int *)t19);
    t9 = (~(t8));
    t10 = *((unsigned int *)t18);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB39;

LAB37:    if (*((unsigned int *)t19) == 0)
        goto LAB36;

LAB38:    t20 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t20) = 1;

LAB39:    t21 = (t3 + 4);
    t22 = (t18 + 4);
    t23 = *((unsigned int *)t18);
    t24 = (~(t23));
    *((unsigned int *)t3) = t24;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t22) != 0)
        goto LAB41;

LAB40:    t29 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t29 & 1U);
    t30 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t30 & 1U);
    t31 = (t0 + 1928);
    xsi_vlogvar_assign_value(t31, t3, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2248);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2248);
    t7 = (t6 + 72U);
    t13 = *((char **)t7);
    t14 = (t0 + 2408);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    xsi_vlog_generic_get_index_select_value(t3, 1, t5, t13, 2, t16, 32, 1);
    t17 = (t0 + 2088);
    xsi_vlogvar_assign_value(t17, t3, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2408);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng4)));
    memset(t3, 0, 8);
    xsi_vlog_signed_minus(t3, 32, t5, 32, t6, 32);
    t7 = (t0 + 2408);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 32);
    goto LAB30;

LAB36:    *((unsigned int *)t3) = 1;
    goto LAB39;

LAB41:    t25 = *((unsigned int *)t3);
    t26 = *((unsigned int *)t22);
    *((unsigned int *)t3) = (t25 | t26);
    t27 = *((unsigned int *)t21);
    t28 = *((unsigned int *)t22);
    *((unsigned int *)t21) = (t27 | t28);
    goto LAB40;

LAB42:    xsi_set_current_line(84, ng0);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2728);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlogfile_fclose(*((unsigned int *)t5));
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 2728);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);
    xsi_set_current_line(87, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}

static void Always_90_1(char *t0)
{
    char t6[8];
    char t32[8];
    char t39[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;

LAB0:    t1 = (t0 + 4056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 4872);
    *((int *)t2) = 1;
    t3 = (t0 + 4088);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(90, ng0);

LAB5:    xsi_set_current_line(91, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(91, ng0);

LAB13:    xsi_set_current_line(92, ng0);
    t28 = (t0 + 2248);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = ((char*)((ng8)));
    memset(t32, 0, 8);
    xsi_vlog_signed_equal(t32, 32, t30, 32, t31, 32);
    t33 = (t32 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t32);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(94, ng0);

LAB18:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 0);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 0);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t13 & 31U);
    t14 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t14 & 31U);
    xsi_vlogfile_write(1, 0, 0, ng10, 2, t0, (char)118, t6, 5);
    xsi_set_current_line(96, ng0);
    xsi_vlog_finish(1);

LAB16:    goto LAB12;

LAB14:    xsi_set_current_line(92, ng0);

LAB17:    xsi_set_current_line(93, ng0);
    t40 = (t0 + 2248);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memset(t39, 0, 8);
    t43 = (t39 + 4);
    t44 = (t42 + 4);
    t45 = *((unsigned int *)t42);
    t46 = (t45 >> 0);
    *((unsigned int *)t39) = t46;
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 0);
    *((unsigned int *)t43) = t48;
    t49 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t49 & 31U);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t50 & 31U);
    xsi_vlogfile_write(1, 0, 0, ng9, 2, t0, (char)118, t39, 5);
    goto LAB16;

}

static void Always_101_2(char *t0)
{
    char t8[8];
    char t9[8];
    char t25[8];
    char t26[8];
    char t34[8];
    char t75[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    char *t74;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;

LAB0:    t1 = (t0 + 4304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 4888);
    *((int *)t2) = 1;
    t3 = (t0 + 4336);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(101, ng0);

LAB5:    xsi_set_current_line(102, ng0);
    t4 = (t0 + 2888);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_signed_equal(t8, 32, t6, 32, t7, 32);
    memset(t9, 0, 8);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t8);
    t14 = (t13 & t12);
    t15 = (t14 & 1U);
    if (t15 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t10) != 0)
        goto LAB8;

LAB9:    t17 = (t9 + 4);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t17);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB10;

LAB11:    memcpy(t34, t9, 8);

LAB12:    t66 = (t34 + 4);
    t67 = *((unsigned int *)t66);
    t68 = (~(t67));
    t69 = *((unsigned int *)t34);
    t70 = (t69 & t68);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB20;

LAB21:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB8:    t16 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB9;

LAB10:    t21 = (t0 + 2728);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = ((char*)((ng3)));
    memset(t25, 0, 8);
    xsi_vlog_signed_not_equal(t25, 32, t23, 32, t24, 32);
    memset(t26, 0, 8);
    t27 = (t25 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t25);
    t31 = (t30 & t29);
    t32 = (t31 & 1U);
    if (t32 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t27) != 0)
        goto LAB15;

LAB16:    t35 = *((unsigned int *)t9);
    t36 = *((unsigned int *)t26);
    t37 = (t35 & t36);
    *((unsigned int *)t34) = t37;
    t38 = (t9 + 4);
    t39 = (t26 + 4);
    t40 = (t34 + 4);
    t41 = *((unsigned int *)t38);
    t42 = *((unsigned int *)t39);
    t43 = (t41 | t42);
    *((unsigned int *)t40) = t43;
    t44 = *((unsigned int *)t40);
    t45 = (t44 != 0);
    if (t45 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB15:    t33 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB16;

LAB17:    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t40);
    *((unsigned int *)t34) = (t46 | t47);
    t48 = (t9 + 4);
    t49 = (t26 + 4);
    t50 = *((unsigned int *)t9);
    t51 = (~(t50));
    t52 = *((unsigned int *)t48);
    t53 = (~(t52));
    t54 = *((unsigned int *)t26);
    t55 = (~(t54));
    t56 = *((unsigned int *)t49);
    t57 = (~(t56));
    t58 = (t51 & t53);
    t59 = (t55 & t57);
    t60 = (~(t58));
    t61 = (~(t59));
    t62 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t62 & t60);
    t63 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t63 & t61);
    t64 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t64 & t60);
    t65 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t65 & t61);
    goto LAB19;

LAB20:    xsi_set_current_line(102, ng0);

LAB23:    xsi_set_current_line(103, ng0);
    t72 = (t0 + 2728);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    t76 = (t0 + 2248);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    memset(t75, 0, 8);
    t79 = (t75 + 4);
    t80 = (t78 + 4);
    t81 = *((unsigned int *)t78);
    t82 = (t81 >> 0);
    *((unsigned int *)t75) = t82;
    t83 = *((unsigned int *)t80);
    t84 = (t83 >> 0);
    *((unsigned int *)t79) = t84;
    t85 = *((unsigned int *)t75);
    *((unsigned int *)t75) = (t85 & 31U);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t86 & 31U);
    t87 = (t0 + 2568);
    t88 = (t87 + 56U);
    t89 = *((char **)t88);
    t90 = (t0 + 1208U);
    t91 = *((char **)t90);
    t90 = (t0 + 1048U);
    t92 = *((char **)t90);
    xsi_vlogfile_fwrite(*((unsigned int *)t74), 0, 0, 1, ng11, 5, t0, (char)118, t75, 5, (char)119, t89, 32, (char)118, t91, 4, (char)118, t92, 1);
    goto LAB22;

}

static void Always_107_3(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(107, ng0);

LAB4:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 4360);
    xsi_process_wait(t2, 50000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(110, ng0);
    t4 = (t0 + 1608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1608);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

}


extern void work_m_00000000002070274439_2937737655_init()
{
	static char *pe[] = {(void *)Initial_31_0,(void *)Always_90_1,(void *)Always_101_2,(void *)Always_107_3};
	xsi_register_didat("work_m_00000000002070274439_2937737655", "isim/fsm_lock_tb_isim_beh.exe.sim/work/m_00000000002070274439_2937737655.didat");
	xsi_register_executes(pe);
}
