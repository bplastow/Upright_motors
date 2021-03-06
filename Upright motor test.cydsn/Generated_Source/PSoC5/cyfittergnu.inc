.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* Disp_LCDPort */
.set Disp_LCDPort__0__MASK, 0x01
.set Disp_LCDPort__0__PC, CYREG_PRT4_PC0
.set Disp_LCDPort__0__PORT, 4
.set Disp_LCDPort__0__SHIFT, 0
.set Disp_LCDPort__1__MASK, 0x02
.set Disp_LCDPort__1__PC, CYREG_PRT4_PC1
.set Disp_LCDPort__1__PORT, 4
.set Disp_LCDPort__1__SHIFT, 1
.set Disp_LCDPort__2__MASK, 0x04
.set Disp_LCDPort__2__PC, CYREG_PRT4_PC2
.set Disp_LCDPort__2__PORT, 4
.set Disp_LCDPort__2__SHIFT, 2
.set Disp_LCDPort__3__MASK, 0x08
.set Disp_LCDPort__3__PC, CYREG_PRT4_PC3
.set Disp_LCDPort__3__PORT, 4
.set Disp_LCDPort__3__SHIFT, 3
.set Disp_LCDPort__4__MASK, 0x10
.set Disp_LCDPort__4__PC, CYREG_PRT4_PC4
.set Disp_LCDPort__4__PORT, 4
.set Disp_LCDPort__4__SHIFT, 4
.set Disp_LCDPort__5__MASK, 0x20
.set Disp_LCDPort__5__PC, CYREG_PRT4_PC5
.set Disp_LCDPort__5__PORT, 4
.set Disp_LCDPort__5__SHIFT, 5
.set Disp_LCDPort__6__MASK, 0x40
.set Disp_LCDPort__6__PC, CYREG_PRT4_PC6
.set Disp_LCDPort__6__PORT, 4
.set Disp_LCDPort__6__SHIFT, 6
.set Disp_LCDPort__AG, CYREG_PRT4_AG
.set Disp_LCDPort__AMUX, CYREG_PRT4_AMUX
.set Disp_LCDPort__BIE, CYREG_PRT4_BIE
.set Disp_LCDPort__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Disp_LCDPort__BYP, CYREG_PRT4_BYP
.set Disp_LCDPort__CTL, CYREG_PRT4_CTL
.set Disp_LCDPort__DM0, CYREG_PRT4_DM0
.set Disp_LCDPort__DM1, CYREG_PRT4_DM1
.set Disp_LCDPort__DM2, CYREG_PRT4_DM2
.set Disp_LCDPort__DR, CYREG_PRT4_DR
.set Disp_LCDPort__INP_DIS, CYREG_PRT4_INP_DIS
.set Disp_LCDPort__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Disp_LCDPort__LCD_EN, CYREG_PRT4_LCD_EN
.set Disp_LCDPort__MASK, 0x7F
.set Disp_LCDPort__PORT, 4
.set Disp_LCDPort__PRT, CYREG_PRT4_PRT
.set Disp_LCDPort__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Disp_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Disp_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Disp_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Disp_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Disp_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Disp_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Disp_LCDPort__PS, CYREG_PRT4_PS
.set Disp_LCDPort__SHIFT, 0
.set Disp_LCDPort__SLW, CYREG_PRT4_SLW

/* Cont_Reg */
.set Cont_Reg_Sync_ctrl_reg__0__MASK, 0x01
.set Cont_Reg_Sync_ctrl_reg__0__POS, 0
.set Cont_Reg_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB13_14_ACTL
.set Cont_Reg_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB13_14_CTL
.set Cont_Reg_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB13_14_CTL
.set Cont_Reg_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB13_14_CTL
.set Cont_Reg_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB13_14_CTL
.set Cont_Reg_Sync_ctrl_reg__16BIT_MASK_MASK_REG, CYREG_B0_UDB13_14_MSK
.set Cont_Reg_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB13_14_MSK
.set Cont_Reg_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB13_14_MSK
.set Cont_Reg_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB13_14_MSK
.set Cont_Reg_Sync_ctrl_reg__1__MASK, 0x02
.set Cont_Reg_Sync_ctrl_reg__1__POS, 1
.set Cont_Reg_Sync_ctrl_reg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB13_ACTL
.set Cont_Reg_Sync_ctrl_reg__CONTROL_REG, CYREG_B0_UDB13_CTL
.set Cont_Reg_Sync_ctrl_reg__CONTROL_ST_REG, CYREG_B0_UDB13_ST_CTL
.set Cont_Reg_Sync_ctrl_reg__COUNT_REG, CYREG_B0_UDB13_CTL
.set Cont_Reg_Sync_ctrl_reg__COUNT_ST_REG, CYREG_B0_UDB13_ST_CTL
.set Cont_Reg_Sync_ctrl_reg__MASK, 0x03
.set Cont_Reg_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set Cont_Reg_Sync_ctrl_reg__PERIOD_REG, CYREG_B0_UDB13_MSK
.set Cont_Reg_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL

/* LED_Down */
.set LED_Down__0__MASK, 0x01
.set LED_Down__0__PC, CYREG_PRT2_PC0
.set LED_Down__0__PORT, 2
.set LED_Down__0__SHIFT, 0
.set LED_Down__AG, CYREG_PRT2_AG
.set LED_Down__AMUX, CYREG_PRT2_AMUX
.set LED_Down__BIE, CYREG_PRT2_BIE
.set LED_Down__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LED_Down__BYP, CYREG_PRT2_BYP
.set LED_Down__CTL, CYREG_PRT2_CTL
.set LED_Down__DM0, CYREG_PRT2_DM0
.set LED_Down__DM1, CYREG_PRT2_DM1
.set LED_Down__DM2, CYREG_PRT2_DM2
.set LED_Down__DR, CYREG_PRT2_DR
.set LED_Down__INP_DIS, CYREG_PRT2_INP_DIS
.set LED_Down__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LED_Down__LCD_EN, CYREG_PRT2_LCD_EN
.set LED_Down__MASK, 0x01
.set LED_Down__PORT, 2
.set LED_Down__PRT, CYREG_PRT2_PRT
.set LED_Down__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LED_Down__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LED_Down__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LED_Down__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LED_Down__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LED_Down__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LED_Down__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LED_Down__PS, CYREG_PRT2_PS
.set LED_Down__SHIFT, 0
.set LED_Down__SLW, CYREG_PRT2_SLW

/* Pin_Down */
.set Pin_Down__0__MASK, 0x02
.set Pin_Down__0__PC, CYREG_PRT2_PC1
.set Pin_Down__0__PORT, 2
.set Pin_Down__0__SHIFT, 1
.set Pin_Down__AG, CYREG_PRT2_AG
.set Pin_Down__AMUX, CYREG_PRT2_AMUX
.set Pin_Down__BIE, CYREG_PRT2_BIE
.set Pin_Down__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Pin_Down__BYP, CYREG_PRT2_BYP
.set Pin_Down__CTL, CYREG_PRT2_CTL
.set Pin_Down__DM0, CYREG_PRT2_DM0
.set Pin_Down__DM1, CYREG_PRT2_DM1
.set Pin_Down__DM2, CYREG_PRT2_DM2
.set Pin_Down__DR, CYREG_PRT2_DR
.set Pin_Down__INP_DIS, CYREG_PRT2_INP_DIS
.set Pin_Down__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Pin_Down__LCD_EN, CYREG_PRT2_LCD_EN
.set Pin_Down__MASK, 0x02
.set Pin_Down__PORT, 2
.set Pin_Down__PRT, CYREG_PRT2_PRT
.set Pin_Down__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Pin_Down__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Pin_Down__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Pin_Down__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Pin_Down__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Pin_Down__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Pin_Down__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Pin_Down__PS, CYREG_PRT2_PS
.set Pin_Down__SHIFT, 1
.set Pin_Down__SLW, CYREG_PRT2_SLW

/* pinStart */
.set pinStart__0__MASK, 0x10
.set pinStart__0__PC, CYREG_PRT2_PC4
.set pinStart__0__PORT, 2
.set pinStart__0__SHIFT, 4
.set pinStart__AG, CYREG_PRT2_AG
.set pinStart__AMUX, CYREG_PRT2_AMUX
.set pinStart__BIE, CYREG_PRT2_BIE
.set pinStart__BIT_MASK, CYREG_PRT2_BIT_MASK
.set pinStart__BYP, CYREG_PRT2_BYP
.set pinStart__CTL, CYREG_PRT2_CTL
.set pinStart__DM0, CYREG_PRT2_DM0
.set pinStart__DM1, CYREG_PRT2_DM1
.set pinStart__DM2, CYREG_PRT2_DM2
.set pinStart__DR, CYREG_PRT2_DR
.set pinStart__INP_DIS, CYREG_PRT2_INP_DIS
.set pinStart__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set pinStart__LCD_EN, CYREG_PRT2_LCD_EN
.set pinStart__MASK, 0x10
.set pinStart__PORT, 2
.set pinStart__PRT, CYREG_PRT2_PRT
.set pinStart__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set pinStart__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set pinStart__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set pinStart__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set pinStart__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set pinStart__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set pinStart__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set pinStart__PS, CYREG_PRT2_PS
.set pinStart__SHIFT, 4
.set pinStart__SLW, CYREG_PRT2_SLW

/* But_Reg */
.set But_Reg_sts_sts_reg__0__MASK, 0x01
.set But_Reg_sts_sts_reg__0__POS, 0
.set But_Reg_sts_sts_reg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB13_14_ACTL
.set But_Reg_sts_sts_reg__16BIT_STATUS_REG, CYREG_B0_UDB13_14_ST
.set But_Reg_sts_sts_reg__1__MASK, 0x02
.set But_Reg_sts_sts_reg__1__POS, 1
.set But_Reg_sts_sts_reg__2__MASK, 0x04
.set But_Reg_sts_sts_reg__2__POS, 2
.set But_Reg_sts_sts_reg__3__MASK, 0x08
.set But_Reg_sts_sts_reg__3__POS, 3
.set But_Reg_sts_sts_reg__4__MASK, 0x10
.set But_Reg_sts_sts_reg__4__POS, 4
.set But_Reg_sts_sts_reg__MASK, 0x1F
.set But_Reg_sts_sts_reg__MASK_REG, CYREG_B0_UDB13_MSK
.set But_Reg_sts_sts_reg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set But_Reg_sts_sts_reg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set But_Reg_sts_sts_reg__STATUS_AUX_CTL_REG, CYREG_B0_UDB13_ACTL
.set But_Reg_sts_sts_reg__STATUS_CNT_REG, CYREG_B0_UDB13_ST_CTL
.set But_Reg_sts_sts_reg__STATUS_CONTROL_REG, CYREG_B0_UDB13_ST_CTL
.set But_Reg_sts_sts_reg__STATUS_REG, CYREG_B0_UDB13_ST

/* Clock_1 */
.set Clock_1__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock_1__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock_1__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock_1__CFG2_SRC_SEL_MASK, 0x07
.set Clock_1__INDEX, 0x00
.set Clock_1__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_1__PM_ACT_MSK, 0x01
.set Clock_1__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_1__PM_STBY_MSK, 0x01

/* LED_Up */
.set LED_Up__0__MASK, 0x04
.set LED_Up__0__PC, CYREG_PRT2_PC2
.set LED_Up__0__PORT, 2
.set LED_Up__0__SHIFT, 2
.set LED_Up__AG, CYREG_PRT2_AG
.set LED_Up__AMUX, CYREG_PRT2_AMUX
.set LED_Up__BIE, CYREG_PRT2_BIE
.set LED_Up__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LED_Up__BYP, CYREG_PRT2_BYP
.set LED_Up__CTL, CYREG_PRT2_CTL
.set LED_Up__DM0, CYREG_PRT2_DM0
.set LED_Up__DM1, CYREG_PRT2_DM1
.set LED_Up__DM2, CYREG_PRT2_DM2
.set LED_Up__DR, CYREG_PRT2_DR
.set LED_Up__INP_DIS, CYREG_PRT2_INP_DIS
.set LED_Up__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LED_Up__LCD_EN, CYREG_PRT2_LCD_EN
.set LED_Up__MASK, 0x04
.set LED_Up__PORT, 2
.set LED_Up__PRT, CYREG_PRT2_PRT
.set LED_Up__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LED_Up__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LED_Up__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LED_Up__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LED_Up__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LED_Up__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LED_Up__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LED_Up__PS, CYREG_PRT2_PS
.set LED_Up__SHIFT, 2
.set LED_Up__SLW, CYREG_PRT2_SLW

/* Pin_Up */
.set Pin_Up__0__MASK, 0x08
.set Pin_Up__0__PC, CYREG_PRT2_PC3
.set Pin_Up__0__PORT, 2
.set Pin_Up__0__SHIFT, 3
.set Pin_Up__AG, CYREG_PRT2_AG
.set Pin_Up__AMUX, CYREG_PRT2_AMUX
.set Pin_Up__BIE, CYREG_PRT2_BIE
.set Pin_Up__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Pin_Up__BYP, CYREG_PRT2_BYP
.set Pin_Up__CTL, CYREG_PRT2_CTL
.set Pin_Up__DM0, CYREG_PRT2_DM0
.set Pin_Up__DM1, CYREG_PRT2_DM1
.set Pin_Up__DM2, CYREG_PRT2_DM2
.set Pin_Up__DR, CYREG_PRT2_DR
.set Pin_Up__INP_DIS, CYREG_PRT2_INP_DIS
.set Pin_Up__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Pin_Up__LCD_EN, CYREG_PRT2_LCD_EN
.set Pin_Up__MASK, 0x08
.set Pin_Up__PORT, 2
.set Pin_Up__PRT, CYREG_PRT2_PRT
.set Pin_Up__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Pin_Up__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Pin_Up__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Pin_Up__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Pin_Up__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Pin_Up__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Pin_Up__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Pin_Up__PS, CYREG_PRT2_PS
.set Pin_Up__SHIFT, 3
.set Pin_Up__SLW, CYREG_PRT2_SLW

/* isr_1 */
.set isr_1__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set isr_1__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set isr_1__INTC_MASK, 0x01
.set isr_1__INTC_NUMBER, 0
.set isr_1__INTC_PRIOR_NUM, 7
.set isr_1__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set isr_1__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set isr_1__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Back */
.set Back__0__MASK, 0x80
.set Back__0__PC, CYREG_PRT2_PC7
.set Back__0__PORT, 2
.set Back__0__SHIFT, 7
.set Back__AG, CYREG_PRT2_AG
.set Back__AMUX, CYREG_PRT2_AMUX
.set Back__BIE, CYREG_PRT2_BIE
.set Back__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Back__BYP, CYREG_PRT2_BYP
.set Back__CTL, CYREG_PRT2_CTL
.set Back__DM0, CYREG_PRT2_DM0
.set Back__DM1, CYREG_PRT2_DM1
.set Back__DM2, CYREG_PRT2_DM2
.set Back__DR, CYREG_PRT2_DR
.set Back__INP_DIS, CYREG_PRT2_INP_DIS
.set Back__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Back__LCD_EN, CYREG_PRT2_LCD_EN
.set Back__MASK, 0x80
.set Back__PORT, 2
.set Back__PRT, CYREG_PRT2_PRT
.set Back__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Back__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Back__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Back__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Back__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Back__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Back__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Back__PS, CYREG_PRT2_PS
.set Back__SHIFT, 7
.set Back__SLW, CYREG_PRT2_SLW

/* Down */
.set Down__0__MASK, 0x04
.set Down__0__PC, CYREG_PRT1_PC2
.set Down__0__PORT, 1
.set Down__0__SHIFT, 2
.set Down__AG, CYREG_PRT1_AG
.set Down__AMUX, CYREG_PRT1_AMUX
.set Down__BIE, CYREG_PRT1_BIE
.set Down__BIT_MASK, CYREG_PRT1_BIT_MASK
.set Down__BYP, CYREG_PRT1_BYP
.set Down__CTL, CYREG_PRT1_CTL
.set Down__DM0, CYREG_PRT1_DM0
.set Down__DM1, CYREG_PRT1_DM1
.set Down__DM2, CYREG_PRT1_DM2
.set Down__DR, CYREG_PRT1_DR
.set Down__INP_DIS, CYREG_PRT1_INP_DIS
.set Down__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set Down__LCD_EN, CYREG_PRT1_LCD_EN
.set Down__MASK, 0x04
.set Down__PORT, 1
.set Down__PRT, CYREG_PRT1_PRT
.set Down__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set Down__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set Down__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set Down__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set Down__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set Down__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set Down__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set Down__PS, CYREG_PRT1_PS
.set Down__SHIFT, 2
.set Down__SLW, CYREG_PRT1_SLW

/* Menu */
.set Menu__0__MASK, 0x20
.set Menu__0__PC, CYREG_PRT2_PC5
.set Menu__0__PORT, 2
.set Menu__0__SHIFT, 5
.set Menu__AG, CYREG_PRT2_AG
.set Menu__AMUX, CYREG_PRT2_AMUX
.set Menu__BIE, CYREG_PRT2_BIE
.set Menu__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Menu__BYP, CYREG_PRT2_BYP
.set Menu__CTL, CYREG_PRT2_CTL
.set Menu__DM0, CYREG_PRT2_DM0
.set Menu__DM1, CYREG_PRT2_DM1
.set Menu__DM2, CYREG_PRT2_DM2
.set Menu__DR, CYREG_PRT2_DR
.set Menu__INP_DIS, CYREG_PRT2_INP_DIS
.set Menu__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Menu__LCD_EN, CYREG_PRT2_LCD_EN
.set Menu__MASK, 0x20
.set Menu__PORT, 2
.set Menu__PRT, CYREG_PRT2_PRT
.set Menu__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Menu__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Menu__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Menu__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Menu__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Menu__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Menu__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Menu__PS, CYREG_PRT2_PS
.set Menu__SHIFT, 5
.set Menu__SLW, CYREG_PRT2_SLW

/* stop */
.set stop__0__MASK, 0x20
.set stop__0__PC, CYREG_PRT6_PC5
.set stop__0__PORT, 6
.set stop__0__SHIFT, 5
.set stop__AG, CYREG_PRT6_AG
.set stop__AMUX, CYREG_PRT6_AMUX
.set stop__BIE, CYREG_PRT6_BIE
.set stop__BIT_MASK, CYREG_PRT6_BIT_MASK
.set stop__BYP, CYREG_PRT6_BYP
.set stop__CTL, CYREG_PRT6_CTL
.set stop__DM0, CYREG_PRT6_DM0
.set stop__DM1, CYREG_PRT6_DM1
.set stop__DM2, CYREG_PRT6_DM2
.set stop__DR, CYREG_PRT6_DR
.set stop__INP_DIS, CYREG_PRT6_INP_DIS
.set stop__LCD_COM_SEG, CYREG_PRT6_LCD_COM_SEG
.set stop__LCD_EN, CYREG_PRT6_LCD_EN
.set stop__MASK, 0x20
.set stop__PORT, 6
.set stop__PRT, CYREG_PRT6_PRT
.set stop__PRTDSI__CAPS_SEL, CYREG_PRT6_CAPS_SEL
.set stop__PRTDSI__DBL_SYNC_IN, CYREG_PRT6_DBL_SYNC_IN
.set stop__PRTDSI__OE_SEL0, CYREG_PRT6_OE_SEL0
.set stop__PRTDSI__OE_SEL1, CYREG_PRT6_OE_SEL1
.set stop__PRTDSI__OUT_SEL0, CYREG_PRT6_OUT_SEL0
.set stop__PRTDSI__OUT_SEL1, CYREG_PRT6_OUT_SEL1
.set stop__PRTDSI__SYNC_OUT, CYREG_PRT6_SYNC_OUT
.set stop__PS, CYREG_PRT6_PS
.set stop__SHIFT, 5
.set stop__SLW, CYREG_PRT6_SLW

/* Up */
.set Up__0__MASK, 0x10
.set Up__0__PC, CYREG_PRT1_PC4
.set Up__0__PORT, 1
.set Up__0__SHIFT, 4
.set Up__AG, CYREG_PRT1_AG
.set Up__AMUX, CYREG_PRT1_AMUX
.set Up__BIE, CYREG_PRT1_BIE
.set Up__BIT_MASK, CYREG_PRT1_BIT_MASK
.set Up__BYP, CYREG_PRT1_BYP
.set Up__CTL, CYREG_PRT1_CTL
.set Up__DM0, CYREG_PRT1_DM0
.set Up__DM1, CYREG_PRT1_DM1
.set Up__DM2, CYREG_PRT1_DM2
.set Up__DR, CYREG_PRT1_DR
.set Up__INP_DIS, CYREG_PRT1_INP_DIS
.set Up__LCD_COM_SEG, CYREG_PRT1_LCD_COM_SEG
.set Up__LCD_EN, CYREG_PRT1_LCD_EN
.set Up__MASK, 0x10
.set Up__PORT, 1
.set Up__PRT, CYREG_PRT1_PRT
.set Up__PRTDSI__CAPS_SEL, CYREG_PRT1_CAPS_SEL
.set Up__PRTDSI__DBL_SYNC_IN, CYREG_PRT1_DBL_SYNC_IN
.set Up__PRTDSI__OE_SEL0, CYREG_PRT1_OE_SEL0
.set Up__PRTDSI__OE_SEL1, CYREG_PRT1_OE_SEL1
.set Up__PRTDSI__OUT_SEL0, CYREG_PRT1_OUT_SEL0
.set Up__PRTDSI__OUT_SEL1, CYREG_PRT1_OUT_SEL1
.set Up__PRTDSI__SYNC_OUT, CYREG_PRT1_SYNC_OUT
.set Up__PS, CYREG_PRT1_PS
.set Up__SHIFT, 4
.set Up__SLW, CYREG_PRT1_SLW

/* Miscellaneous */
/* -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release */
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_MEMBER_5B, 4
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_DIE_PSOC5LP, 4
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_DIE_PSOC5LP
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 3
.set CYDEV_CHIP_DIE_PSOC4A, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E123069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 2
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REV_PSOC5LP_PRODUCTION
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x1000
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000001
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x4000
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0, 5
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1, 5
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2, 5
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3, 5
.set CYDEV_VIO3_MV, 5000
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
