/*******************************************************************************
* File Name: Count_PM.c  
* Version 2.40
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Count.h"

static Count_backupStruct Count_backup;


/*******************************************************************************
* Function Name: Count_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Count_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Count_SaveConfig(void) 
{
    #if (!Count_UsingFixedFunction)

        Count_backup.CounterUdb = Count_ReadCounter();

        #if (CY_UDB_V0)
            Count_backup.CounterPeriod = Count_ReadPeriod();
            Count_backup.CompareValue = Count_ReadCompare();
            Count_backup.InterruptMaskValue = Count_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!Count_ControlRegRemoved)
            Count_backup.CounterControlRegister = Count_ReadControlRegister();
        #endif /* (!Count_ControlRegRemoved) */

    #endif /* (!Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Count_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Count_RestoreConfig(void) 
{      
    #if (!Count_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 Count_interruptState;
        #endif  /* (CY_UDB_V0) */

       Count_WriteCounter(Count_backup.CounterUdb);

        #if (CY_UDB_V0)
            Count_WritePeriod(Count_backup.CounterPeriod);
            Count_WriteCompare(Count_backup.CompareValue);

            Count_interruptState = CyEnterCriticalSection();
            Count_STATUS_AUX_CTRL |= Count_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(Count_interruptState);

            Count_STATUS_MASK = Count_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!Count_ControlRegRemoved)
            Count_WriteControlRegister(Count_backup.CounterControlRegister);
        #endif /* (!Count_ControlRegRemoved) */

    #endif /* (!Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Count_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Count_Sleep(void) 
{
    #if(!Count_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Count_CTRL_ENABLE == (Count_CONTROL & Count_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Count_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Count_backup.CounterEnableState = 0u;
        }
    #else
        Count_backup.CounterEnableState = 1u;
        if(Count_backup.CounterEnableState != 0u)
        {
            Count_backup.CounterEnableState = 0u;
        }
    #endif /* (!Count_ControlRegRemoved) */
    
    Count_Stop();
    Count_SaveConfig();
}


/*******************************************************************************
* Function Name: Count_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Count_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Count_Wakeup(void) 
{
    Count_RestoreConfig();
    #if(!Count_ControlRegRemoved)
        if(Count_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Count_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Count_ControlRegRemoved) */
    
}


/* [] END OF FILE */
