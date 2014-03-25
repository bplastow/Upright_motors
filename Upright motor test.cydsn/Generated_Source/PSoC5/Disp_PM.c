/*******************************************************************************
* File Name: Disp_PM.c
* Version 1.90
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Disp.h"


static Disp_BACKUP_STRUCT Disp_backup;


/*******************************************************************************
* Function Name: Disp_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Disp_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: Disp_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Disp_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: Disp_Sleep
********************************************************************************
*
* Summary:
*  Prepares component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Disp_Sleep(void) 
{
    Disp_backup.enableState = Disp_enableState;
    Disp_SaveConfig();
    Disp_Stop();
}


/*******************************************************************************
* Function Name: Disp_Wakeup
********************************************************************************
*
* Summary:
*  Wakes component from sleep mode. Configures DMA and enables the component for
*  normal operation.
*
* Parameters:
*  Disp_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Disp_Wakeup(void) 
{
    Disp_RestoreConfig();

    if(Disp_backup.enableState == 1u)
    {
        Disp_Enable();
    }
}


/* [] END OF FILE */
