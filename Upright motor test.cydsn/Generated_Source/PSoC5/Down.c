/*******************************************************************************
* File Name: Down.c  
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
#include "Down.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Down__PORT == 15 && ((Down__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Down_Write
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
void Down_Write(uint8 value) 
{
    uint8 staticBits = (Down_DR & (uint8)(~Down_MASK));
    Down_DR = staticBits | ((uint8)(value << Down_SHIFT) & Down_MASK);
}


/*******************************************************************************
* Function Name: Down_SetDriveMode
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
void Down_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Down_0, mode);
}


/*******************************************************************************
* Function Name: Down_Read
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
*  Macro Down_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Down_Read(void) 
{
    return (Down_PS & Down_MASK) >> Down_SHIFT;
}


/*******************************************************************************
* Function Name: Down_ReadDataReg
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
uint8 Down_ReadDataReg(void) 
{
    return (Down_DR & Down_MASK) >> Down_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Down_INTSTAT) 

    /*******************************************************************************
    * Function Name: Down_ClearInterrupt
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
    uint8 Down_ClearInterrupt(void) 
    {
        return (Down_INTSTAT & Down_MASK) >> Down_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
