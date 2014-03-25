/*******************************************************************************
* File Name: pinStart.h  
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

#if !defined(CY_PINS_pinStart_H) /* Pins pinStart_H */
#define CY_PINS_pinStart_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pinStart_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pinStart__PORT == 15 && ((pinStart__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    pinStart_Write(uint8 value) ;
void    pinStart_SetDriveMode(uint8 mode) ;
uint8   pinStart_ReadDataReg(void) ;
uint8   pinStart_Read(void) ;
uint8   pinStart_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinStart_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define pinStart_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define pinStart_DM_RES_UP          PIN_DM_RES_UP
#define pinStart_DM_RES_DWN         PIN_DM_RES_DWN
#define pinStart_DM_OD_LO           PIN_DM_OD_LO
#define pinStart_DM_OD_HI           PIN_DM_OD_HI
#define pinStart_DM_STRONG          PIN_DM_STRONG
#define pinStart_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define pinStart_MASK               pinStart__MASK
#define pinStart_SHIFT              pinStart__SHIFT
#define pinStart_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinStart_PS                     (* (reg8 *) pinStart__PS)
/* Data Register */
#define pinStart_DR                     (* (reg8 *) pinStart__DR)
/* Port Number */
#define pinStart_PRT_NUM                (* (reg8 *) pinStart__PRT) 
/* Connect to Analog Globals */                                                  
#define pinStart_AG                     (* (reg8 *) pinStart__AG)                       
/* Analog MUX bux enable */
#define pinStart_AMUX                   (* (reg8 *) pinStart__AMUX) 
/* Bidirectional Enable */                                                        
#define pinStart_BIE                    (* (reg8 *) pinStart__BIE)
/* Bit-mask for Aliased Register Access */
#define pinStart_BIT_MASK               (* (reg8 *) pinStart__BIT_MASK)
/* Bypass Enable */
#define pinStart_BYP                    (* (reg8 *) pinStart__BYP)
/* Port wide control signals */                                                   
#define pinStart_CTL                    (* (reg8 *) pinStart__CTL)
/* Drive Modes */
#define pinStart_DM0                    (* (reg8 *) pinStart__DM0) 
#define pinStart_DM1                    (* (reg8 *) pinStart__DM1)
#define pinStart_DM2                    (* (reg8 *) pinStart__DM2) 
/* Input Buffer Disable Override */
#define pinStart_INP_DIS                (* (reg8 *) pinStart__INP_DIS)
/* LCD Common or Segment Drive */
#define pinStart_LCD_COM_SEG            (* (reg8 *) pinStart__LCD_COM_SEG)
/* Enable Segment LCD */
#define pinStart_LCD_EN                 (* (reg8 *) pinStart__LCD_EN)
/* Slew Rate Control */
#define pinStart_SLW                    (* (reg8 *) pinStart__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pinStart_PRTDSI__CAPS_SEL       (* (reg8 *) pinStart__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pinStart_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pinStart__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pinStart_PRTDSI__OE_SEL0        (* (reg8 *) pinStart__PRTDSI__OE_SEL0) 
#define pinStart_PRTDSI__OE_SEL1        (* (reg8 *) pinStart__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pinStart_PRTDSI__OUT_SEL0       (* (reg8 *) pinStart__PRTDSI__OUT_SEL0) 
#define pinStart_PRTDSI__OUT_SEL1       (* (reg8 *) pinStart__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pinStart_PRTDSI__SYNC_OUT       (* (reg8 *) pinStart__PRTDSI__SYNC_OUT) 


#if defined(pinStart__INTSTAT)  /* Interrupt Registers */

    #define pinStart_INTSTAT                (* (reg8 *) pinStart__INTSTAT)
    #define pinStart_SNAP                   (* (reg8 *) pinStart__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pinStart_H */


/* [] END OF FILE */
