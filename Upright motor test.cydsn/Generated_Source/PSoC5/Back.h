/*******************************************************************************
* File Name: Back.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Back_H) /* Pins Back_H */
#define CY_PINS_Back_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Back_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Back__PORT == 15 && ((Back__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Back_Write(uint8 value) ;
void    Back_SetDriveMode(uint8 mode) ;
uint8   Back_ReadDataReg(void) ;
uint8   Back_Read(void) ;
uint8   Back_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Back_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Back_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Back_DM_RES_UP          PIN_DM_RES_UP
#define Back_DM_RES_DWN         PIN_DM_RES_DWN
#define Back_DM_OD_LO           PIN_DM_OD_LO
#define Back_DM_OD_HI           PIN_DM_OD_HI
#define Back_DM_STRONG          PIN_DM_STRONG
#define Back_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Back_MASK               Back__MASK
#define Back_SHIFT              Back__SHIFT
#define Back_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Back_PS                     (* (reg8 *) Back__PS)
/* Data Register */
#define Back_DR                     (* (reg8 *) Back__DR)
/* Port Number */
#define Back_PRT_NUM                (* (reg8 *) Back__PRT) 
/* Connect to Analog Globals */                                                  
#define Back_AG                     (* (reg8 *) Back__AG)                       
/* Analog MUX bux enable */
#define Back_AMUX                   (* (reg8 *) Back__AMUX) 
/* Bidirectional Enable */                                                        
#define Back_BIE                    (* (reg8 *) Back__BIE)
/* Bit-mask for Aliased Register Access */
#define Back_BIT_MASK               (* (reg8 *) Back__BIT_MASK)
/* Bypass Enable */
#define Back_BYP                    (* (reg8 *) Back__BYP)
/* Port wide control signals */                                                   
#define Back_CTL                    (* (reg8 *) Back__CTL)
/* Drive Modes */
#define Back_DM0                    (* (reg8 *) Back__DM0) 
#define Back_DM1                    (* (reg8 *) Back__DM1)
#define Back_DM2                    (* (reg8 *) Back__DM2) 
/* Input Buffer Disable Override */
#define Back_INP_DIS                (* (reg8 *) Back__INP_DIS)
/* LCD Common or Segment Drive */
#define Back_LCD_COM_SEG            (* (reg8 *) Back__LCD_COM_SEG)
/* Enable Segment LCD */
#define Back_LCD_EN                 (* (reg8 *) Back__LCD_EN)
/* Slew Rate Control */
#define Back_SLW                    (* (reg8 *) Back__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Back_PRTDSI__CAPS_SEL       (* (reg8 *) Back__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Back_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Back__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Back_PRTDSI__OE_SEL0        (* (reg8 *) Back__PRTDSI__OE_SEL0) 
#define Back_PRTDSI__OE_SEL1        (* (reg8 *) Back__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Back_PRTDSI__OUT_SEL0       (* (reg8 *) Back__PRTDSI__OUT_SEL0) 
#define Back_PRTDSI__OUT_SEL1       (* (reg8 *) Back__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Back_PRTDSI__SYNC_OUT       (* (reg8 *) Back__PRTDSI__SYNC_OUT) 


#if defined(Back__INTSTAT)  /* Interrupt Registers */

    #define Back_INTSTAT                (* (reg8 *) Back__INTSTAT)
    #define Back_SNAP                   (* (reg8 *) Back__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Back_H */


/* [] END OF FILE */
