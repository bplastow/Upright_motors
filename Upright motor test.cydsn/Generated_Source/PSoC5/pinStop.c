/*******************************************************************************
* File Name: pinStop.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "pinStop.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 pinStop__PORT == 15 && ((pinStop__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: pinStop_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void pinStop_Write(uint8 value) 
{
    uint8 staticBits = (pinStop_DR & (uint8)(~pinStop_MASK));
    pinStop_DR = staticBits | ((uint8)(value << pinStop_SHIFT) & pinStop_MASK);
}


/*******************************************************************************
* Function Name: pinStop_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void pinStop_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(pinStop_0, mode);
}


/*******************************************************************************
* Function Name: pinStop_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro pinStop_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinStop_Read(void) 
{
    return (pinStop_PS & pinStop_MASK) >> pinStop_SHIFT;
}


/*******************************************************************************
* Function Name: pinStop_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 pinStop_ReadDataReg(void) 
{
    return (pinStop_DR & pinStop_MASK) >> pinStop_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinStop_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinStop_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 pinStop_ClearInterrupt(void) 
    {
        return (pinStop_INTSTAT & pinStop_MASK) >> pinStop_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
