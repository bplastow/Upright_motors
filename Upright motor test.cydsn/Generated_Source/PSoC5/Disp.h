/*******************************************************************************
* File Name: Disp.h
* Version 1.90
*
* Description:
*  This header file contains registers and constants associated with the
*  Character LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CHARLCD_Disp_H)
#define CY_CHARLCD_Disp_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Disp_CONVERSION_ROUTINES     (1u)
#define Disp_CUSTOM_CHAR_SET         (0u)

/* Custom character set types */
#define Disp_NONE                     (0u)    /* No Custom Fonts      */
#define Disp_HORIZONTAL_BG            (1u)    /* Horizontal Bar Graph */
#define Disp_VERTICAL_BG              (2u)    /* Vertical Bar Graph   */
#define Disp_USER_DEFINED             (3u)    /* User Defined Fonts   */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Disp_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void Disp_Init(void) ;
void Disp_Enable(void) ;
void Disp_Start(void) ;
void Disp_Stop(void) ;
void Disp_WriteControl(uint8 cByte) ;
void Disp_WriteData(uint8 dByte) ;
void Disp_PrintString(char8 const string[]) ;
void Disp_Position(uint8 row, uint8 column) ;
void Disp_PutChar(char8 character) ;
void Disp_IsReady(void) ;
void Disp_SaveConfig(void) ;
void Disp_RestoreConfig(void) ;
void Disp_Sleep(void) ;
void Disp_Wakeup(void) ;

#if((Disp_CUSTOM_CHAR_SET == Disp_VERTICAL_BG) || \
                (Disp_CUSTOM_CHAR_SET == Disp_HORIZONTAL_BG))

    void  Disp_LoadCustomFonts(uint8 const customData[])
                        ;

    void  Disp_DrawHorizontalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                         ;

    void Disp_DrawVerticalBG(uint8 row, uint8 column, uint8 maxCharacters, uint8 value)
                        ;

#endif /* ((Disp_CUSTOM_CHAR_SET == Disp_VERTICAL_BG) */

#if(Disp_CUSTOM_CHAR_SET == Disp_USER_DEFINED)

    void Disp_LoadCustomFonts(uint8 const customData[])
                            ;

#endif /* ((Disp_CUSTOM_CHAR_SET == Disp_USER_DEFINED) */

#if(Disp_CONVERSION_ROUTINES == 1u)

    /* ASCII Conversion Routines */
    void Disp_PrintInt8(uint8 value) ;
    void Disp_PrintInt16(uint16 value) ;
    void Disp_PrintNumber(uint16 value) ; 

#endif /* Disp_CONVERSION_ROUTINES == 1u */

/* Clear Macro */
#define Disp_ClearDisplay() Disp_WriteControl(Disp_CLEAR_DISPLAY)

/* Off Macro */
#define Disp_DisplayOff() Disp_WriteControl(Disp_DISPLAY_CURSOR_OFF)

/* On Macro */
#define Disp_DisplayOn() Disp_WriteControl(Disp_DISPLAY_ON_CURSOR_OFF)


/***************************************
*           Global Variables
***************************************/

extern uint8 Disp_initVar;
extern uint8 Disp_enableState;
extern uint8 const CYCODE Disp_customFonts[64u];


/***************************************
*           API Constants
***************************************/

/* Full Byte Commands Sent as Two Nibbles */
#define Disp_DISPLAY_8_BIT_INIT       (0x03u)
#define Disp_DISPLAY_4_BIT_INIT       (0x02u)
#define Disp_DISPLAY_CURSOR_OFF       (0x08u)
#define Disp_CLEAR_DISPLAY            (0x01u)
#define Disp_CURSOR_AUTO_INCR_ON      (0x06u)
#define Disp_DISPLAY_CURSOR_ON        (0x0Eu)
#define Disp_DISPLAY_2_LINES_5x10     (0x2Cu)
#define Disp_DISPLAY_ON_CURSOR_OFF    (0x0Cu)

#define Disp_RESET_CURSOR_POSITION    (0x03u)
#define Disp_CURSOR_WINK              (0x0Du)
#define Disp_CURSOR_BLINK             (0x0Fu)
#define Disp_CURSOR_SH_LEFT           (0x10u)
#define Disp_CURSOR_SH_RIGHT          (0x14u)
#define Disp_CURSOR_HOME              (0x02u)
#define Disp_CURSOR_LEFT              (0x04u)
#define Disp_CURSOR_RIGHT             (0x06u)

/* Point to Character Generator Ram 0 */
#define Disp_CGRAM_0                  (0x40u)

/* Point to Display Data Ram 0 */
#define Disp_DDRAM_0                  (0x80u)

/* LCD Characteristics */
#define Disp_CHARACTER_WIDTH          (0x05u)
#define Disp_CHARACTER_HEIGHT         (0x08u)

#if(Disp_CONVERSION_ROUTINES == 1u)
    #define Disp_NUMBER_OF_REMAINDERS (0x05u)
    #define Disp_TEN                  (0x0Au)
#endif /* Disp_CONVERSION_ROUTINES == 1u */

/* Nibble Offset and Mask */
#define Disp_NIBBLE_SHIFT             (0x04u)
#define Disp_NIBBLE_MASK              (0x0Fu)

/* LCD Module Address Constants */
#define Disp_ROW_0_START              (0x80u)
#define Disp_ROW_1_START              (0xC0u)
#define Disp_ROW_2_START              (0x94u)
#define Disp_ROW_3_START              (0xD4u)

/* Custom Character References */
#define Disp_CUSTOM_0                 (0x00u)
#define Disp_CUSTOM_1                 (0x01u)
#define Disp_CUSTOM_2                 (0x02u)
#define Disp_CUSTOM_3                 (0x03u)
#define Disp_CUSTOM_4                 (0x04u)
#define Disp_CUSTOM_5                 (0x05u)
#define Disp_CUSTOM_6                 (0x06u)
#define Disp_CUSTOM_7                 (0x07u)

/* Other constants */
#define Disp_BYTE_UPPER_NIBBLE_SHIFT   (0x04u)
#define Disp_BYTE_LOWER_NIBBLE_MASK    (0x0Fu)
#define Disp_U16_UPPER_BYTE_SHIFT      (0x08u)
#define Disp_U16_LOWER_BYTE_MASK       (0xFFu)
#define Disp_CUSTOM_CHAR_SET_LEN       (0x40u)


/***************************************
*             Registers
***************************************/

/* Device specific registers */
#if (CY_PSOC4)

    #define Disp_PORT_DR_REG           (*(reg32 *) Disp_LCDPort__DR)  /* Data Output Register */
    #define Disp_PORT_DR_PTR           ( (reg32 *) Disp_LCDPort__DR)
    #define Disp_PORT_PS_REG           (*(reg32 *) Disp_LCDPort__PS)  /* Pin State Register */
    #define Disp_PORT_PS_PTR           ( (reg32 *) Disp_LCDPort__PS)
    
    #define Disp_PORT_PC_REG           (*(reg32 *) Disp_LCDPort__PC)
    #define Disp_PORT_PC_PTR           (*(reg32 *) Disp_LCDPort__PC)
    
#else

    #define Disp_PORT_DR_REG           (*(reg8 *) Disp_LCDPort__DR)  /* Data Output Register */
    #define Disp_PORT_DR_PTR           ( (reg8 *) Disp_LCDPort__DR)
    #define Disp_PORT_PS_REG           (*(reg8 *) Disp_LCDPort__PS)  /* Pin State Register */
    #define Disp_PORT_PS_PTR           ( (reg8 *) Disp_LCDPort__PS)

    #define Disp_PORT_DM0_REG          (*(reg8 *) Disp_LCDPort__DM0) /* Port Drive Mode 0 */
    #define Disp_PORT_DM0_PTR          ( (reg8 *) Disp_LCDPort__DM0)
    #define Disp_PORT_DM1_REG          (*(reg8 *) Disp_LCDPort__DM1) /* Port Drive Mode 1 */
    #define Disp_PORT_DM1_PTR          ( (reg8 *) Disp_LCDPort__DM1)
    #define Disp_PORT_DM2_REG          (*(reg8 *) Disp_LCDPort__DM2) /* Port Drive Mode 2 */
    #define Disp_PORT_DM2_PTR          ( (reg8 *) Disp_LCDPort__DM2)

#endif /* CY_PSOC4 */


/***************************************
*       Register Constants
***************************************/

/* SHIFT must be 1 or 0 */
#if (0 == Disp_LCDPort__SHIFT)
    #define Disp_PORT_SHIFT               (0x00u)
#else
    #define Disp_PORT_SHIFT               (0x01u)
#endif /* (0 == Disp_LCDPort__SHIFT) */

#define Disp_PORT_MASK                ((uint8) (Disp_LCDPort__MASK))

#if (CY_PSOC4)

    /* Hi-Z Digital is defined by value of "001b" and this should be set for
    * four data pins in this way we get - 0x00000249. Similar Strong drive
    * is defibed by "110b" so we get 0x00000DB6.
    */
    #define Disp_HIGH_Z_DATA_DM           (0x00000249ul)
    #define Disp_STRONG_DATA_DM           (0x00000DB6ul)
    #define Disp_DATA_PINS_MASK           (0x00000FFFul)
    #define Disp_DM_DATA_MASK             ((uint32)(Disp_DATA_PINS_MASK << \
                                                          (Disp_PORT_SHIFT * 3u)))
    
#else

    /* Drive Mode register values for High Z */
    #define Disp_HIGH_Z_DM0               (0xFFu)
    #define Disp_HIGH_Z_DM1               (0x00u)
    #define Disp_HIGH_Z_DM2               (0x00u)

    /* Drive Mode register values for High Z Analog */
    #define Disp_HIGH_Z_A_DM0             (0x00u)
    #define Disp_HIGH_Z_A_DM1             (0x00u)
    #define Disp_HIGH_Z_A_DM2             (0x00u)

    /* Drive Mode register values for Strong */
    #define Disp_STRONG_DM0               (0x00u)
    #define Disp_STRONG_DM1               (0xFFu)
    #define Disp_STRONG_DM2               (0xFFu)

#endif /* CY_PSOC4 */

/* Pin Masks */
#define Disp_RS                     ((uint8) \
                                                (((uint8) 0x20u) << Disp_LCDPort__SHIFT))
#define Disp_RW                     ((uint8) \
                                                (((uint8) 0x40u) << Disp_LCDPort__SHIFT))
#define Disp_E                      ((uint8) \
                                                (((uint8) 0x10u) << Disp_LCDPort__SHIFT))
#define Disp_READY_BIT              ((uint8) \
                                                (((uint8) 0x08u) << Disp_LCDPort__SHIFT))
#define Disp_DATA_MASK              ((uint8) \
                                                (((uint8) 0x0Fu) << Disp_LCDPort__SHIFT))

/* These names are obsolete and will be removed in future revisions */
#define Disp_PORT_DR                  Disp_PORT_DR_REG
#define Disp_PORT_PS                  Disp_PORT_PS_REG
#define Disp_PORT_DM0                 Disp_PORT_DM0_REG
#define Disp_PORT_DM1                 Disp_PORT_DM1_REG
#define Disp_PORT_DM2                 Disp_PORT_DM2_REG


/***************************************
*       Obsolete function names
***************************************/
#if(Disp_CONVERSION_ROUTINES == 1u)
    /* This function names are obsolete an they will be removed in future 
    * revisions of component.
    */
    #define Disp_PrintDecUint16(x)   Disp_PrintNumber(x)  
    #define Disp_PrintHexUint8(x)    Disp_PrintInt8(x)
    #define Disp_PrintHexUint16(x)   Disp_PrintInt16(x)        

#endif /* Disp_CONVERSION_ROUTINES == 1u */

#endif /* CY_CHARLCD_Disp_H */


/* [] END OF FILE */
