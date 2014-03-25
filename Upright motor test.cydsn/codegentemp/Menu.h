/*******************************************************************************
* File Name: Menu.h  
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

#if !defined(CY_PINS_Menu_H) /* Pins Menu_H */
#define CY_PINS_Menu_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Menu_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Menu__PORT == 15 && ((Menu__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Menu_Write(uint8 value) ;
void    Menu_SetDriveMode(uint8 mode) ;
uint8   Menu_ReadDataReg(void) ;
uint8   Menu_Read(void) ;
uint8   Menu_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Menu_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Menu_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Menu_DM_RES_UP          PIN_DM_RES_UP
#define Menu_DM_RES_DWN         PIN_DM_RES_DWN
#define Menu_DM_OD_LO           PIN_DM_OD_LO
#define Menu_DM_OD_HI           PIN_DM_OD_HI
#define Menu_DM_STRONG          PIN_DM_STRONG
#define Menu_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Menu_MASK               Menu__MASK
#define Menu_SHIFT              Menu__SHIFT
#define Menu_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Menu_PS                     (* (reg8 *) Menu__PS)
/* Data Register */
#define Menu_DR                     (* (reg8 *) Menu__DR)
/* Port Number */
#define Menu_PRT_NUM                (* (reg8 *) Menu__PRT) 
/* Connect to Analog Globals */                                                  
#define Menu_AG                     (* (reg8 *) Menu__AG)                       
/* Analog MUX bux enable */
#define Menu_AMUX                   (* (reg8 *) Menu__AMUX) 
/* Bidirectional Enable */                                                        
#define Menu_BIE                    (* (reg8 *) Menu__BIE)
/* Bit-mask for Aliased Register Access */
#define Menu_BIT_MASK               (* (reg8 *) Menu__BIT_MASK)
/* Bypass Enable */
#define Menu_BYP                    (* (reg8 *) Menu__BYP)
/* Port wide control signals */                                                   
#define Menu_CTL                    (* (reg8 *) Menu__CTL)
/* Drive Modes */
#define Menu_DM0                    (* (reg8 *) Menu__DM0) 
#define Menu_DM1                    (* (reg8 *) Menu__DM1)
#define Menu_DM2                    (* (reg8 *) Menu__DM2) 
/* Input Buffer Disable Override */
#define Menu_INP_DIS                (* (reg8 *) Menu__INP_DIS)
/* LCD Common or Segment Drive */
#define Menu_LCD_COM_SEG            (* (reg8 *) Menu__LCD_COM_SEG)
/* Enable Segment LCD */
#define Menu_LCD_EN                 (* (reg8 *) Menu__LCD_EN)
/* Slew Rate Control */
#define Menu_SLW                    (* (reg8 *) Menu__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Menu_PRTDSI__CAPS_SEL       (* (reg8 *) Menu__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Menu_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Menu__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Menu_PRTDSI__OE_SEL0        (* (reg8 *) Menu__PRTDSI__OE_SEL0) 
#define Menu_PRTDSI__OE_SEL1        (* (reg8 *) Menu__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Menu_PRTDSI__OUT_SEL0       (* (reg8 *) Menu__PRTDSI__OUT_SEL0) 
#define Menu_PRTDSI__OUT_SEL1       (* (reg8 *) Menu__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Menu_PRTDSI__SYNC_OUT       (* (reg8 *) Menu__PRTDSI__SYNC_OUT) 


#if defined(Menu__INTSTAT)  /* Interrupt Registers */

    #define Menu_INTSTAT                (* (reg8 *) Menu__INTSTAT)
    #define Menu_SNAP                   (* (reg8 *) Menu__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Menu_H */


/* [] END OF FILE */
