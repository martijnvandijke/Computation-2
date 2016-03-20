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

/* This file is designed for use with ISim build 0xa0883be4 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Computation-2/Work_Folder_Mips/mMips/mmips_3_LAB2_path/verilog/alu.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {6U, 0U};
static int ng8[] = {1, 0};
static unsigned int ng9[] = {7U, 0U};
static unsigned int ng10[] = {8U, 0U};
static unsigned int ng11[] = {9U, 0U};
static int ng12[] = {16, 0};
static unsigned int ng13[] = {10U, 0U};
static unsigned int ng14[] = {11U, 0U};
static int ng15[] = {2, 0};
static unsigned int ng16[] = {12U, 0U};
static int ng17[] = {8, 0};
static unsigned int ng18[] = {13U, 0U};
static unsigned int ng19[] = {14U, 0U};
static unsigned int ng20[] = {15U, 0U};
static unsigned int ng21[] = {16U, 0U};
static int ng22[] = {31, 0};
static unsigned int ng23[] = {17U, 0U};
static int ng24[] = {30, 0};
static unsigned int ng25[] = {18U, 0U};
static int ng26[] = {24, 0};
static unsigned int ng27[] = {19U, 0U};
static unsigned int ng28[] = {48U, 0U};
static int ng29[] = {255, 0};
static unsigned int ng30[] = {52U, 0U};



static void Always_41_0(char *t0)
{
    char t11[8];
    char t44[8];
    char t45[8];
    char t51[8];
    char t72[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    int t46;
    int t47;
    int t48;
    int t49;
    int t50;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;

LAB0:    t1 = (t0 + 4744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 5064);
    *((int *)t2) = 1;
    t3 = (t0 + 4776);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(42, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 4552);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(45, ng0);
    t6 = (t0 + 1504U);
    t7 = *((char **)t6);
    t6 = (t0 + 2544);
    xsi_vlogvar_assign_value(t6, t7, 0, 0, 32);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 1664U);
    t3 = *((char **)t2);
    t2 = (t0 + 2704);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 32);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2864);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3024);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1344U);
    t3 = *((char **)t2);

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng10)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng13)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng16)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng18)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng19)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng20)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng21)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng23)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng25)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng27)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng28)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng30)));
    t8 = xsi_vlog_unsigned_case_compare(t3, 6, t2, 32);
    if (t8 == 1)
        goto LAB49;

LAB50:
LAB52:
LAB51:    xsi_set_current_line(179, ng0);

LAB129:
LAB53:    xsi_set_current_line(190, ng0);
    t2 = (t0 + 3184);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2064);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    xsi_set_current_line(191, ng0);
    t2 = (t0 + 3344);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2224);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    xsi_set_current_line(192, ng0);
    t2 = (t0 + 3824);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 2384);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 1);
    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t4 = (t0 + 4552);
    xsi_vlog_dispose_process_subprogram_invocation(t4);
    goto LAB2;

LAB9:    xsi_set_current_line(55, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t10);
    t14 = (t12 & t13);
    *((unsigned int *)t11) = t14;
    t15 = (t6 + 4);
    t16 = (t10 + 4);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t15);
    t19 = *((unsigned int *)t16);
    t20 = (t18 | t19);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB54;

LAB55:
LAB56:    t43 = (t0 + 3184);
    xsi_vlogvar_assign_value(t43, t11, 0, 0, 32);
    goto LAB53;

LAB11:    xsi_set_current_line(58, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t10);
    t14 = (t12 | t13);
    *((unsigned int *)t11) = t14;
    t15 = (t6 + 4);
    t16 = (t10 + 4);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t15);
    t19 = *((unsigned int *)t16);
    t20 = (t18 | t19);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB57;

LAB58:
LAB59:    t43 = (t0 + 3184);
    xsi_vlogvar_assign_value(t43, t11, 0, 0, 32);
    goto LAB53;

LAB13:    xsi_set_current_line(61, ng0);

LAB60:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 2864);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3024);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_add(t11, 32, t6, 32, t10, 32);
    t15 = (t0 + 3184);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 32);
    goto LAB53;

LAB15:    xsi_set_current_line(70, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t6, 32, t10, 32);
    t15 = (t0 + 3184);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 32);
    goto LAB53;

LAB17:    xsi_set_current_line(73, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t10);
    t14 = (t12 ^ t13);
    *((unsigned int *)t11) = t14;
    t15 = (t6 + 4);
    t16 = (t10 + 4);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t15);
    t19 = *((unsigned int *)t16);
    t20 = (t18 | t19);
    *((unsigned int *)t17) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB61;

LAB62:
LAB63:    t25 = (t0 + 3184);
    xsi_vlogvar_assign_value(t25, t11, 0, 0, 32);
    goto LAB53;

LAB19:    xsi_set_current_line(76, ng0);

LAB64:    xsi_set_current_line(77, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_minus(t11, 32, t6, 32, t10, 32);
    t15 = (t0 + 3184);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 32);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 3184);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t11, 0, 8);
    t7 = (t5 + 4);
    t9 = (t6 + 4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t6);
    t14 = (t12 ^ t13);
    t18 = *((unsigned int *)t7);
    t19 = *((unsigned int *)t9);
    t20 = (t18 ^ t19);
    t21 = (t14 | t20);
    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t9);
    t24 = (t22 | t23);
    t27 = (~(t24));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB68;

LAB65:    if (t24 != 0)
        goto LAB67;

LAB66:    *((unsigned int *)t11) = 1;

LAB68:    t15 = (t11 + 4);
    t29 = *((unsigned int *)t15);
    t30 = (~(t29));
    t31 = *((unsigned int *)t11);
    t32 = (t31 & t30);
    t33 = (t32 != 0);
    if (t33 > 0)
        goto LAB69;

LAB70:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 3824);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);

LAB71:    goto LAB53;

LAB21:    xsi_set_current_line(84, ng0);

LAB72:    xsi_set_current_line(85, ng0);
    t4 = (t0 + 2864);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 3024);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_less(t11, 32, t6, 32, t10, 32);
    t15 = (t11 + 4);
    t12 = *((unsigned int *)t15);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB73;

LAB74:    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 3184);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB75:    goto LAB53;

LAB23:    xsi_set_current_line(96, ng0);

LAB76:    xsi_set_current_line(97, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    t15 = (t6 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB78;

LAB77:    t16 = (t10 + 4);
    if (*((unsigned int *)t16) != 0)
        goto LAB78;

LAB81:    if (*((unsigned int *)t6) < *((unsigned int *)t10))
        goto LAB79;

LAB80:    t25 = (t11 + 4);
    t12 = *((unsigned int *)t25);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB82;

LAB83:    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 3184);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);

LAB84:    goto LAB53;

LAB25:    xsi_set_current_line(108, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng12)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_lshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB27:    xsi_set_current_line(111, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng8)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_lshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB29:    xsi_set_current_line(114, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng15)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_lshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB31:    xsi_set_current_line(117, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng17)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_lshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB33:    xsi_set_current_line(120, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng8)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB35:    xsi_set_current_line(123, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng15)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB37:    xsi_set_current_line(126, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng17)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t6, 32, t7, 32);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    goto LAB53;

LAB39:    xsi_set_current_line(130, ng0);

LAB85:    xsi_set_current_line(131, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t9 = (t6 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t9);
    t18 = (t14 >> 31);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 1U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 1U);
    t10 = (t0 + 3504);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 1);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng8)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t5, 32, t6, 32);
    t7 = (t0 + 3184);
    xsi_vlogvar_assign_value(t7, t11, 0, 0, 32);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3184);
    t7 = (t0 + 3184);
    t9 = (t7 + 72U);
    t10 = *((char **)t9);
    t15 = ((char*)((ng22)));
    t16 = ((char*)((ng22)));
    xsi_vlog_convert_partindices(t11, t44, t45, ((int*)(t10)), 2, t15, 32, 1, t16, 32, 1);
    t17 = (t11 + 4);
    t12 = *((unsigned int *)t17);
    t8 = (!(t12));
    t25 = (t44 + 4);
    t13 = *((unsigned int *)t25);
    t35 = (!(t13));
    t36 = (t8 && t35);
    t26 = (t45 + 4);
    t14 = *((unsigned int *)t26);
    t46 = (!(t14));
    t47 = (t36 && t46);
    if (t47 == 1)
        goto LAB86;

LAB87:    goto LAB53;

LAB41:    xsi_set_current_line(137, ng0);

LAB88:    xsi_set_current_line(138, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t9 = (t6 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t9);
    t18 = (t14 >> 31);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 1U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 1U);
    t10 = (t0 + 3504);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 1);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng15)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t5, 32, t6, 32);
    t7 = (t0 + 3184);
    xsi_vlogvar_assign_value(t7, t11, 0, 0, 32);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3504);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    xsi_vlogtype_concat(t11, 2, 2, 2U, t9, 1, t5, 1);
    t10 = (t0 + 3184);
    t15 = (t0 + 3184);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t25 = ((char*)((ng22)));
    t26 = ((char*)((ng24)));
    xsi_vlog_convert_partindices(t44, t45, t51, ((int*)(t17)), 2, t25, 32, 1, t26, 32, 1);
    t43 = (t44 + 4);
    t12 = *((unsigned int *)t43);
    t8 = (!(t12));
    t52 = (t45 + 4);
    t13 = *((unsigned int *)t52);
    t35 = (!(t13));
    t36 = (t8 && t35);
    t53 = (t51 + 4);
    t14 = *((unsigned int *)t53);
    t46 = (!(t14));
    t47 = (t36 && t46);
    if (t47 == 1)
        goto LAB89;

LAB90:    goto LAB53;

LAB43:    xsi_set_current_line(144, ng0);

LAB91:    xsi_set_current_line(145, ng0);
    t4 = (t0 + 2704);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t11, 0, 8);
    t7 = (t11 + 4);
    t9 = (t6 + 4);
    t12 = *((unsigned int *)t6);
    t13 = (t12 >> 31);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t9);
    t18 = (t14 >> 31);
    *((unsigned int *)t7) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 1U);
    t20 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t20 & 1U);
    t10 = (t0 + 3504);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 1);
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng17)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_rshift(t11, 32, t5, 32, t6, 32);
    t7 = (t0 + 3184);
    xsi_vlogvar_assign_value(t7, t11, 0, 0, 32);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 3504);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3504);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t0 + 3504);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    t17 = (t0 + 3504);
    t25 = (t17 + 56U);
    t26 = *((char **)t25);
    t43 = (t0 + 3504);
    t52 = (t43 + 56U);
    t53 = *((char **)t52);
    t54 = (t0 + 3504);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    t57 = (t0 + 3504);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    t60 = (t0 + 3504);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    xsi_vlogtype_concat(t11, 8, 8, 8U, t62, 1, t59, 1, t56, 1, t53, 1, t26, 1, t16, 1, t9, 1, t5, 1);
    t63 = (t0 + 3184);
    t64 = (t0 + 3184);
    t65 = (t64 + 72U);
    t66 = *((char **)t65);
    t67 = ((char*)((ng22)));
    t68 = ((char*)((ng26)));
    xsi_vlog_convert_partindices(t44, t45, t51, ((int*)(t66)), 2, t67, 32, 1, t68, 32, 1);
    t69 = (t44 + 4);
    t12 = *((unsigned int *)t69);
    t8 = (!(t12));
    t70 = (t45 + 4);
    t13 = *((unsigned int *)t70);
    t35 = (!(t13));
    t36 = (t8 && t35);
    t71 = (t51 + 4);
    t14 = *((unsigned int *)t71);
    t46 = (!(t14));
    t47 = (t36 && t46);
    if (t47 == 1)
        goto LAB92;

LAB93:    goto LAB53;

LAB45:    xsi_set_current_line(151, ng0);

LAB94:    xsi_set_current_line(152, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 2704);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    xsi_vlog_unsigned_multiply(t72, 64, t6, 32, t10, 32);
    t15 = (t0 + 3664);
    xsi_vlogvar_assign_value(t15, t72, 0, 0, 64);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 3664);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t11, 0, 8);
    t6 = (t11 + 4);
    t7 = (t5 + 4);
    t12 = *((unsigned int *)t5);
    t13 = (t12 >> 0);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t7);
    t18 = (t14 >> 0);
    *((unsigned int *)t6) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 4294967295U);
    t20 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t20 & 4294967295U);
    t9 = (t0 + 3184);
    xsi_vlogvar_assign_value(t9, t11, 0, 0, 32);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 3664);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t11, 0, 8);
    t6 = (t11 + 4);
    t7 = (t5 + 8);
    t9 = (t5 + 12);
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 0);
    *((unsigned int *)t11) = t13;
    t14 = *((unsigned int *)t9);
    t18 = (t14 >> 0);
    *((unsigned int *)t6) = t18;
    t19 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t19 & 4294967295U);
    t20 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t20 & 4294967295U);
    t10 = (t0 + 3344);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 32);
    goto LAB53;

LAB47:    xsi_set_current_line(157, ng0);

LAB95:    xsi_set_current_line(158, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t11, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB97;

LAB96:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB97;

LAB100:    if (*((unsigned int *)t6) < *((unsigned int *)t7))
        goto LAB98;

LAB99:    t16 = (t11 + 4);
    t12 = *((unsigned int *)t16);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB101;

LAB102:
LAB103:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 2544);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng29)));
    memset(t11, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB105;

LAB104:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB105;

LAB108:    if (*((unsigned int *)t5) > *((unsigned int *)t6))
        goto LAB106;

LAB107:    t15 = (t11 + 4);
    t12 = *((unsigned int *)t15);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB109;

LAB110:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 2544);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3184);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);

LAB111:    goto LAB53;

LAB49:    xsi_set_current_line(167, ng0);

LAB112:    xsi_set_current_line(168, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng29)));
    memset(t11, 0, 8);
    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB114;

LAB113:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB114;

LAB117:    if (*((unsigned int *)t6) > *((unsigned int *)t7))
        goto LAB115;

LAB116:    t16 = (t11 + 4);
    t12 = *((unsigned int *)t16);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB118;

LAB119:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 2544);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng1)));
    memset(t11, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB122;

LAB121:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB122;

LAB125:    if (*((unsigned int *)t5) < *((unsigned int *)t6))
        goto LAB123;

LAB124:    t15 = (t11 + 4);
    t12 = *((unsigned int *)t15);
    t13 = (~(t12));
    t14 = *((unsigned int *)t11);
    t18 = (t14 & t13);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB126;

LAB127:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 2544);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 3184);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);

LAB128:
LAB120:    goto LAB53;

LAB54:    t23 = *((unsigned int *)t11);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t11) = (t23 | t24);
    t25 = (t6 + 4);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t6);
    t28 = (~(t27));
    t29 = *((unsigned int *)t25);
    t30 = (~(t29));
    t31 = *((unsigned int *)t10);
    t32 = (~(t31));
    t33 = *((unsigned int *)t26);
    t34 = (~(t33));
    t35 = (t28 & t30);
    t36 = (t32 & t34);
    t37 = (~(t35));
    t38 = (~(t36));
    t39 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t39 & t37);
    t40 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t40 & t38);
    t41 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t41 & t37);
    t42 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t42 & t38);
    goto LAB56;

LAB57:    t23 = *((unsigned int *)t11);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t11) = (t23 | t24);
    t25 = (t6 + 4);
    t26 = (t10 + 4);
    t27 = *((unsigned int *)t25);
    t28 = (~(t27));
    t29 = *((unsigned int *)t6);
    t35 = (t29 & t28);
    t30 = *((unsigned int *)t26);
    t31 = (~(t30));
    t32 = *((unsigned int *)t10);
    t36 = (t32 & t31);
    t33 = (~(t35));
    t34 = (~(t36));
    t37 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t37 & t33);
    t38 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t38 & t34);
    goto LAB59;

LAB61:    t23 = *((unsigned int *)t11);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t11) = (t23 | t24);
    goto LAB63;

LAB67:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB68;

LAB69:    xsi_set_current_line(79, ng0);
    t16 = ((char*)((ng8)));
    t17 = (t0 + 3824);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 1);
    goto LAB71;

LAB73:    xsi_set_current_line(86, ng0);
    t16 = ((char*)((ng8)));
    t17 = (t0 + 3184);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 32);
    goto LAB75;

LAB78:    t17 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB80;

LAB79:    *((unsigned int *)t11) = 1;
    goto LAB80;

LAB82:    xsi_set_current_line(98, ng0);
    t26 = ((char*)((ng8)));
    t43 = (t0 + 3184);
    xsi_vlogvar_assign_value(t43, t26, 0, 0, 32);
    goto LAB84;

LAB86:    t18 = *((unsigned int *)t45);
    t48 = (t18 + 0);
    t19 = *((unsigned int *)t11);
    t20 = *((unsigned int *)t44);
    t49 = (t19 - t20);
    t50 = (t49 + 1);
    xsi_vlogvar_assign_value(t6, t5, t48, *((unsigned int *)t44), t50);
    goto LAB87;

LAB89:    t18 = *((unsigned int *)t51);
    t48 = (t18 + 0);
    t19 = *((unsigned int *)t44);
    t20 = *((unsigned int *)t45);
    t49 = (t19 - t20);
    t50 = (t49 + 1);
    xsi_vlogvar_assign_value(t10, t11, t48, *((unsigned int *)t45), t50);
    goto LAB90;

LAB92:    t18 = *((unsigned int *)t51);
    t48 = (t18 + 0);
    t19 = *((unsigned int *)t44);
    t20 = *((unsigned int *)t45);
    t49 = (t19 - t20);
    t50 = (t49 + 1);
    xsi_vlogvar_assign_value(t63, t11, t48, *((unsigned int *)t45), t50);
    goto LAB93;

LAB97:    t15 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB99;

LAB98:    *((unsigned int *)t11) = 1;
    goto LAB99;

LAB101:    xsi_set_current_line(159, ng0);
    t17 = ((char*)((ng1)));
    t25 = (t0 + 3184);
    xsi_vlogvar_assign_value(t25, t17, 0, 0, 32);
    goto LAB103;

LAB105:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB107;

LAB106:    *((unsigned int *)t11) = 1;
    goto LAB107;

LAB109:    xsi_set_current_line(161, ng0);
    t16 = ((char*)((ng29)));
    t17 = (t0 + 3184);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 32);
    goto LAB111;

LAB114:    t15 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB116;

LAB115:    *((unsigned int *)t11) = 1;
    goto LAB116;

LAB118:    xsi_set_current_line(169, ng0);
    t17 = ((char*)((ng29)));
    t25 = (t0 + 3184);
    xsi_vlogvar_assign_value(t25, t17, 0, 0, 32);
    goto LAB120;

LAB122:    t10 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB124;

LAB123:    *((unsigned int *)t11) = 1;
    goto LAB124;

LAB126:    xsi_set_current_line(171, ng0);
    t16 = ((char*)((ng1)));
    t17 = (t0 + 3184);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 32);
    goto LAB128;

}


extern void work_m_00000000000008269599_0886308060_init()
{
	static char *pe[] = {(void *)Always_41_0};
	xsi_register_didat("work_m_00000000000008269599_0886308060", "isim/testbench_isim_beh.exe.sim/work/m_00000000000008269599_0886308060.didat");
	xsi_register_executes(pe);
}
