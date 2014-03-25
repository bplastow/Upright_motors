/*******************************************************************************
* File Name: pinStartO.h  
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

#if !defined(CY_PINS_pinStartO_H) /* Pins pinStartO_H */
#define CY_PINS_pinStartO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pinStartO_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pinStartO__PORT == 15 && ((pinStartO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    pinStartO_Write(uint8 value) ;
void    pinStartO_SetDriveMode(uint8 mode) ;
uint8   pinStartO_ReadDataReg(void) ;
uint8   pinStartO_Read(void) ;
uint8   pinStartO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinStartO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define pinStartO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define pinStartO_DM_RES_UP          PIN_DM_RES_UP
#define pinStartO_DM_RES_DWN         PIN_DM_RES_DWN
#define pinStartO_DM_OD_LO           PIN_DM_OD_LO
#define pinStartO_DM_OD_HI           PIN_DM_OD_HI
#define pinStartO_DM_STRONG          PIN_DM_STRONG
#define pinStartO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define pinStartO_MASK               pinStartO__MASK
#define pinStartO_SHIFT              pinStartO__SHIFT
#define pinStartO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinStartO_PS                     (* (reg8 *) pinStartO__PS)
/* Data Register */
#define pinStartO_DR                     (* (reg8 *) pinStartO__DR)
/* Port Number */
#define pinStartO_PRT_NUM                (* (reg8 *) pinStartO__PRT) 
/* Connect to Analog Globals */                                                  
#define pinStartO_AG                     (* (reg8 *) pinStartO__AG)                       
/* Analog MUX bux enable */
#define pinStartO_AMUX                   (* (reg8 *) pinStartO__AMUX) 
/* Bidirectional Enable */                                                        
#define pinStartO_BIE                    (* (reg8 *) pinStartO__BIE)
/* Bit-mask for Aliased Register Access */
#define pinStartO_BIT_MASK               (* (reg8 *) pinStartO__BIT_MASK)
/* Bypass Enable */
#define pinStartO_BYP                    (* (reg8 *) pinStartO__BYP)
/* Port wide control signals */                                                   
#define pinStartO_CTL                    (* (reg8 *) pinStartO__CTL)
/* Drive Modes */
#define pinStartO_DM0                    (* (reg8 *) pinStartO__DM0) 
#define pinStartO_DM1                    (* (reg8 *) pinStartO__DM1)
#define pinStartO_DM2                    (* (reg8 *) pinStartO__DM2) 
/* Input Buffer Disable Override */
#define pinStartO_INP_DIS                (* (reg8 *) pinStartO__INP_DIS)
/* LCD Common or Segment Drive */
#define pinStartO_LCD_COM_SEG            (* (reg8 *) pinStartO__LCD_COM_SEG)
/* Enable Segment LCD */
#define pinStartO_LCD_EN                 (* (reg8 *) pinStartO__LCD_EN)
/* Slew Rate Control */
#define pinStartO_SLW                    (* (reg8 *) pinStartO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pinStartO_PRTDSI__CAPS_SEL       (* (reg8 *) pinStartO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pinStartO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pinStartO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pinStartO_PRTDSI__OE_SEL0        (* (reg8 *) pinStartO__PRTDSI__OE_SEL0) 
#define pinStartO_PRTDSI__OE_SEL1        (* (reg8 *) pinStartO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pinStartO_PRTDSI__OUT_SEL0       (* (reg8 *) pinStartO__PRTDSI__OUT_SEL0) 
#define pinStartO_PRTDSI__OUT_SEL1       (* (reg8 *) pinStartO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pinStartO_PRTDSI__SYNC_OUT       (* (reg8 *) pinStartO__PRTDSI__SYNC_OUT) 


#if defined(pinStartO__INTSTAT)  /* Interrupt Registers */

    #define pinStartO_INTSTAT                (* (reg8 *) pinStartO__INTSTAT)
    #define pinStartO_SNAP                   (* (reg8 *) pinStartO__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pinStartO_H */


/* [] END OF FILE */