/*******************************************************************************
* File Name: But_Reg.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_But_Reg_H) /* CY_STATUS_REG_But_Reg_H */
#define CY_STATUS_REG_But_Reg_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 But_Reg_Read(void) ;
void But_Reg_InterruptEnable(void) ;
void But_Reg_InterruptDisable(void) ;
void But_Reg_WriteMask(uint8 mask) ;
uint8 But_Reg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define But_Reg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define But_Reg_INPUTS              5


/***************************************
*             Registers
***************************************/

/* Status Register */
#define But_Reg_Status             (* (reg8 *) But_Reg_sts_sts_reg__STATUS_REG )
#define But_Reg_Status_PTR         (  (reg8 *) But_Reg_sts_sts_reg__STATUS_REG )
#define But_Reg_Status_Mask        (* (reg8 *) But_Reg_sts_sts_reg__MASK_REG )
#define But_Reg_Status_Aux_Ctrl    (* (reg8 *) But_Reg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_But_Reg_H */


/* [] END OF FILE */
