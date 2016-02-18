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
static const char *ng13 = "The value of the state 1 is: %d";
static const char *ng14 = "The value of the state 2 is: %d";
static const char *ng15 = "The value of satte 3 is: %d";
static const char *ng16 = "The value of state 4 is: %d";
static const char *ng17 = "The value of state 5 is: %d";
static const char *ng18 = "The value of state 0 is: %d";
static const char *ng19 = "The value of the hex display is: %d";
static const char *ng20 = "The value of the output is: %d";
static const char *ng21 = "The value of the output 0 is: %d";
static const char *ng22 = "The value of the output 1 is: %d";
static const char *ng23 = "The value of the hexdispaly 0 is: %d";
static const char *ng24 = "The value of the hexdisplay 1 is: %d";
static const char *ng25 = "The value of the hexdisplay 2 is: %d";



static void Always_43_0(char *t0)
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

LAB0:    t1 = (t0 + 5232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 5800);
    *((int *)t2) = 1;
    t3 = (t0 + 5264);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(43, ng0);

LAB5:    xsi_set_current_line(44, ng0);
    t4 = (t0 + 3112U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(45, ng0);
    t11 = ((char*)((ng1)));
    memcpy(t12, t11, 8);
    t13 = (t0 + 4312);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 4);
    goto LAB8;

}

static void Always_49_1(char *t0)
{
    char t14[8];
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

LAB0:    t1 = (t0 + 5480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 5816);
    *((int *)t2) = 1;
    t3 = (t0 + 5512);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 4312);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 4152);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 4);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 4152);
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
LAB19:    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng3)));
    xsi_vlogfile_write(1, 0, 0, ng13, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng5)));
    xsi_vlogfile_write(1, 0, 0, ng14, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng7)));
    xsi_vlogfile_write(1, 0, 0, ng15, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng9)));
    xsi_vlogfile_write(1, 0, 0, ng16, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng11)));
    xsi_vlogfile_write(1, 0, 0, ng17, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng1)));
    xsi_vlogfile_write(1, 0, 0, ng18, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 3992);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng19, 2, t0, (char)118, t5, 5);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3832);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng20, 2, t0, (char)118, t5, 2);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng1)));
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t2, 1);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng3)));
    xsi_vlogfile_write(1, 0, 0, ng22, 2, t0, (char)118, t2, 1);
    xsi_set_current_line(138, ng0);
    t2 = ((char*)((ng1)));
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng3)));
    xsi_vlogfile_write(1, 0, 0, ng24, 2, t0, (char)118, t2, 3);
    xsi_set_current_line(140, ng0);
    t2 = ((char*)((ng5)));
    xsi_vlogfile_write(1, 0, 0, ng25, 2, t0, (char)118, t2, 3);
    goto LAB2;

LAB7:    xsi_set_current_line(53, ng0);

LAB20:    xsi_set_current_line(56, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t0 + 3992);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3832);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 3272U);
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
LAB23:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 3432U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB19;

LAB9:    xsi_set_current_line(64, ng0);

LAB27:    xsi_set_current_line(67, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 3992);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 5);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3832);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3432U);
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
LAB30:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB31;

LAB32:
LAB33:    goto LAB19;

LAB11:    xsi_set_current_line(76, ng0);

LAB34:    xsi_set_current_line(79, ng0);
    t3 = ((char*)((ng6)));
    t5 = (t0 + 3992);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 5);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3832);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3432U);
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
LAB37:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB38;

LAB39:
LAB40:    goto LAB19;

LAB13:    xsi_set_current_line(88, ng0);

LAB41:    xsi_set_current_line(91, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 3992);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 5);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3832);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB42;

LAB43:
LAB44:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3432U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB45;

LAB46:
LAB47:    goto LAB19;

LAB15:    xsi_set_current_line(100, ng0);

LAB48:    xsi_set_current_line(103, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 3992);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 5);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t14, t2, 8);
    t3 = (t0 + 3832);
    xsi_vlogvar_assign_value(t3, t14, 0, 0, 2);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3432U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB49;

LAB50:
LAB51:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB52;

LAB53:
LAB54:    goto LAB19;

LAB17:    xsi_set_current_line(113, ng0);

LAB55:    xsi_set_current_line(116, ng0);
    t3 = ((char*)((ng12)));
    t5 = (t0 + 3992);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 5);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 3432U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB56;

LAB57:
LAB58:    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng1)));
    memcpy(t14, t2, 8);
    t3 = (t0 + 4312);
    xsi_vlogvar_assign_value(t3, t14, 0, 0, 4);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 3272U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t9 = *((unsigned int *)t2);
    t10 = (~(t9));
    t11 = *((unsigned int *)t3);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB59;

LAB60:
LAB61:    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng3)));
    memcpy(t14, t2, 8);
    t3 = (t0 + 4312);
    xsi_vlogvar_assign_value(t3, t14, 0, 0, 4);
    goto LAB19;

LAB21:    xsi_set_current_line(59, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB23;

LAB24:    xsi_set_current_line(61, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB26;

LAB28:    xsi_set_current_line(70, ng0);
    t5 = ((char*)((ng5)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB30;

LAB31:    xsi_set_current_line(73, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB33;

LAB35:    xsi_set_current_line(82, ng0);
    t5 = ((char*)((ng7)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB37;

LAB38:    xsi_set_current_line(85, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB40;

LAB42:    xsi_set_current_line(94, ng0);
    t5 = ((char*)((ng9)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB44;

LAB45:    xsi_set_current_line(97, ng0);
    t5 = ((char*)((ng1)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB47;

LAB49:    xsi_set_current_line(106, ng0);
    t5 = ((char*)((ng9)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB51;

LAB52:    xsi_set_current_line(109, ng0);
    t5 = ((char*)((ng3)));
    memcpy(t14, t5, 8);
    t6 = (t0 + 4312);
    xsi_vlogvar_assign_value(t6, t14, 0, 0, 4);
    goto LAB54;

LAB56:    xsi_set_current_line(118, ng0);
    t5 = ((char*)((ng4)));
    t6 = (t0 + 3832);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 2);
    goto LAB58;

LAB59:    xsi_set_current_line(122, ng0);
    t5 = ((char*)((ng2)));
    t6 = (t0 + 3832);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 2);
    goto LAB61;

}


extern void work_m_00000000004121210451_2953017523_init()
{
	static char *pe[] = {(void *)Always_43_0,(void *)Always_49_1};
	xsi_register_didat("work_m_00000000004121210451_2953017523", "isim/fsm_lock_tb_isim_beh.exe.sim/work/m_00000000004121210451_2953017523.didat");
	xsi_register_executes(pe);
}
