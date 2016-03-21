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
static const char *ng0 = "D:/Computation-2/Work_Folder_Mips/mMips/mmips_6/verilog/aluctrl.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {6U, 0U};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {10U, 0U};
static int ng7[] = {2, 0};
static unsigned int ng8[] = {11U, 0U};
static int ng9[] = {8, 0};
static unsigned int ng10[] = {12U, 0U};
static unsigned int ng11[] = {13U, 0U};
static unsigned int ng12[] = {14U, 0U};
static unsigned int ng13[] = {15U, 0U};
static unsigned int ng14[] = {3U, 0U};
static unsigned int ng15[] = {16U, 0U};
static unsigned int ng16[] = {17U, 0U};
static unsigned int ng17[] = {18U, 0U};
static unsigned int ng18[] = {25U, 0U};
static unsigned int ng19[] = {19U, 0U};
static unsigned int ng20[] = {32U, 0U};
static unsigned int ng21[] = {33U, 0U};
static unsigned int ng22[] = {35U, 0U};
static unsigned int ng23[] = {36U, 0U};
static unsigned int ng24[] = {37U, 0U};
static unsigned int ng25[] = {38U, 0U};
static unsigned int ng26[] = {4U, 0U};
static unsigned int ng27[] = {42U, 0U};
static unsigned int ng28[] = {7U, 0U};
static unsigned int ng29[] = {43U, 0U};
static unsigned int ng30[] = {8U, 0U};
static unsigned int ng31[] = {48U, 0U};
static unsigned int ng32[] = {52U, 0U};
static unsigned int ng33[] = {5U, 0U};
static unsigned int ng34[] = {9U, 0U};



static void Always_26_0(char *t0)
{
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
    int t11;
    int t12;
    char *t13;

LAB0:    t1 = (t0 + 2984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 3304);
    *((int *)t2) = 1;
    t3 = (t0 + 3016);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(27, ng0);

LAB5:    t4 = (t0 + 280);
    xsi_vlog_namedbase_setdisablestate(t4, &&LAB6);
    t5 = (t0 + 2792);
    xsi_vlog_namedbase_pushprocess(t4, t5);

LAB7:    xsi_set_current_line(28, ng0);
    t6 = (t0 + 1504U);
    t7 = *((char **)t6);

LAB8:    t6 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t6, 32);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng26)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng33)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng28)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng30)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng34)));
    t8 = xsi_vlog_unsigned_case_compare(t7, 5, t2, 32);
    if (t8 == 1)
        goto LAB27;

LAB28:
LAB30:
LAB29:    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);

LAB31:    t2 = (t0 + 280);
    xsi_vlog_namedbase_popprocess(t2);

LAB6:    t3 = (t0 + 2792);
    xsi_vlog_dispose_process_subprogram_invocation(t3);
    goto LAB2;

LAB9:    xsi_set_current_line(30, ng0);
    t9 = ((char*)((ng2)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 6);
    goto LAB31;

LAB11:    xsi_set_current_line(33, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2064);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 6);
    goto LAB31;

LAB13:    xsi_set_current_line(36, ng0);

LAB32:    xsi_set_current_line(37, ng0);
    t3 = (t0 + 1344U);
    t4 = *((char **)t3);

LAB33:    t3 = ((char*)((ng1)));
    t11 = xsi_vlog_unsigned_case_compare(t4, 6, t3, 32);
    if (t11 == 1)
        goto LAB34;

LAB35:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB36;

LAB37:    t2 = ((char*)((ng14)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng15)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng17)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB42;

LAB43:    t2 = ((char*)((ng18)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB44;

LAB45:    t2 = ((char*)((ng20)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng21)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng22)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng23)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng24)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB54;

LAB55:    t2 = ((char*)((ng25)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB56;

LAB57:    t2 = ((char*)((ng27)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB58;

LAB59:    t2 = ((char*)((ng29)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB60;

LAB61:    t2 = ((char*)((ng31)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB62;

LAB63:    t2 = ((char*)((ng32)));
    t8 = xsi_vlog_unsigned_case_compare(t4, 6, t2, 32);
    if (t8 == 1)
        goto LAB64;

LAB65:
LAB67:
LAB66:    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);

LAB68:    goto LAB31;

LAB15:    xsi_set_current_line(116, ng0);
    t3 = ((char*)((ng14)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB17:    xsi_set_current_line(119, ng0);
    t3 = ((char*)((ng1)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB19:    xsi_set_current_line(122, ng0);
    t3 = ((char*)((ng3)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB21:    xsi_set_current_line(125, ng0);
    t3 = ((char*)((ng26)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB23:    xsi_set_current_line(128, ng0);
    t3 = ((char*)((ng28)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB25:    xsi_set_current_line(131, ng0);
    t3 = ((char*)((ng30)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB27:    xsi_set_current_line(134, ng0);
    t3 = ((char*)((ng34)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB31;

LAB34:    xsi_set_current_line(39, ng0);
    t5 = (t0 + 1664U);
    t6 = *((char **)t5);

LAB69:    t5 = ((char*)((ng5)));
    t12 = xsi_vlog_unsigned_case_compare(t6, 5, t5, 32);
    if (t12 == 1)
        goto LAB70;

LAB71:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 5, t2, 32);
    if (t8 == 1)
        goto LAB72;

LAB73:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 5, t2, 32);
    if (t8 == 1)
        goto LAB74;

LAB75:
LAB77:
LAB76:    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);

LAB78:    goto LAB68;

LAB36:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 1664U);
    t5 = *((char **)t3);

LAB79:    t3 = ((char*)((ng5)));
    t11 = xsi_vlog_unsigned_case_compare(t5, 5, t3, 32);
    if (t11 == 1)
        goto LAB80;

LAB81:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 32);
    if (t8 == 1)
        goto LAB82;

LAB83:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 32);
    if (t8 == 1)
        goto LAB84;

LAB85:
LAB87:
LAB86:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);

LAB88:    goto LAB68;

LAB38:    xsi_set_current_line(63, ng0);
    t3 = (t0 + 1664U);
    t9 = *((char **)t3);

LAB89:    t3 = ((char*)((ng5)));
    t11 = xsi_vlog_unsigned_case_compare(t9, 5, t3, 32);
    if (t11 == 1)
        goto LAB90;

LAB91:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t9, 5, t2, 32);
    if (t8 == 1)
        goto LAB92;

LAB93:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t9, 5, t2, 32);
    if (t8 == 1)
        goto LAB94;

LAB95:
LAB97:
LAB96:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2064);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);

LAB98:    goto LAB68;

LAB40:    xsi_set_current_line(75, ng0);
    t3 = ((char*)((ng1)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB42:    xsi_set_current_line(78, ng0);
    t3 = ((char*)((ng1)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB44:    xsi_set_current_line(81, ng0);
    t3 = ((char*)((ng19)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB46:    xsi_set_current_line(84, ng0);
    t3 = ((char*)((ng2)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB48:    xsi_set_current_line(87, ng0);
    t3 = ((char*)((ng14)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB50:    xsi_set_current_line(90, ng0);
    t3 = ((char*)((ng4)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB52:    xsi_set_current_line(93, ng0);
    t3 = ((char*)((ng1)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB54:    xsi_set_current_line(96, ng0);
    t3 = ((char*)((ng3)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB56:    xsi_set_current_line(99, ng0);
    t3 = ((char*)((ng26)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB58:    xsi_set_current_line(102, ng0);
    t3 = ((char*)((ng28)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB60:    xsi_set_current_line(105, ng0);
    t3 = ((char*)((ng30)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB62:    xsi_set_current_line(107, ng0);
    t3 = ((char*)((ng32)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB64:    xsi_set_current_line(110, ng0);
    t3 = ((char*)((ng32)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB68;

LAB70:    xsi_set_current_line(41, ng0);
    t9 = ((char*)((ng6)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 6);
    goto LAB78;

LAB72:    xsi_set_current_line(43, ng0);
    t3 = ((char*)((ng8)));
    t5 = (t0 + 2064);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 6);
    goto LAB78;

LAB74:    xsi_set_current_line(45, ng0);
    t3 = ((char*)((ng10)));
    t5 = (t0 + 2064);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 6);
    goto LAB78;

LAB80:    xsi_set_current_line(53, ng0);
    t9 = ((char*)((ng11)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 6);
    goto LAB88;

LAB82:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng12)));
    t9 = (t0 + 2064);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 6);
    goto LAB88;

LAB84:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng13)));
    t9 = (t0 + 2064);
    xsi_vlogvar_assign_value(t9, t3, 0, 0, 6);
    goto LAB88;

LAB90:    xsi_set_current_line(65, ng0);
    t10 = ((char*)((ng15)));
    t13 = (t0 + 2064);
    xsi_vlogvar_assign_value(t13, t10, 0, 0, 6);
    goto LAB98;

LAB92:    xsi_set_current_line(67, ng0);
    t3 = ((char*)((ng16)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB98;

LAB94:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng17)));
    t10 = (t0 + 2064);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 6);
    goto LAB98;

}


extern void work_m_00000000002219147006_3124857149_init()
{
	static char *pe[] = {(void *)Always_26_0};
	xsi_register_didat("work_m_00000000002219147006_3124857149", "isim/testbench_isim_beh.exe.sim/work/m_00000000002219147006_3124857149.didat");
	xsi_register_executes(pe);
}
