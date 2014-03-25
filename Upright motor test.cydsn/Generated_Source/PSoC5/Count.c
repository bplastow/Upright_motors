/*******************************************************************************
* File Name: Count.c  
* Version 2.40
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 Count_initVar = 0u;


/*******************************************************************************
* Function Name: Count_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Count_Init(void) 
{
        #if (!Count_UsingFixedFunction && !Count_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Count_UsingFixedFunction && !Count_ControlRegRemoved) */
        
        #if(!Count_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Count_interruptState;
        #endif /* (!Count_UsingFixedFunction) */
        
        #if (Count_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Count_CONTROL &= Count_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Count_CONTROL2 &= ((uint8)(~Count_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Count_CONTROL3 &= ((uint8)(~Count_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Count_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Count_CONTROL |= Count_ONESHOT;
            #endif /* (Count_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Count_CONTROL2 |= Count_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Count_RT1 &= ((uint8)(~Count_RT1_MASK));
            Count_RT1 |= Count_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Count_RT1 &= ((uint8)(~Count_SYNCDSI_MASK));
            Count_RT1 |= Count_SYNCDSI_EN;

        #else
            #if(!Count_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Count_CONTROL & ((uint8)(~Count_CTRL_CMPMODE_MASK));
            Count_CONTROL = ctrl | Count_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Count_CONTROL & ((uint8)(~Count_CTRL_CAPMODE_MASK));
            
            #if( 0 != Count_CAPTURE_MODE_CONF)
                Count_CONTROL = ctrl | Count_DEFAULT_CAPTURE_MODE;
            #else
                Count_CONTROL = ctrl;
            #endif /* 0 != Count_CAPTURE_MODE */ 
            
            #endif /* (!Count_ControlRegRemoved) */
        #endif /* (Count_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Count_UsingFixedFunction)
            Count_ClearFIFO();
        #endif /* (!Count_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Count_WritePeriod(Count_INIT_PERIOD_VALUE);
        #if (!(Count_UsingFixedFunction && (CY_PSOC5A)))
            Count_WriteCounter(Count_INIT_COUNTER_VALUE);
        #endif /* (!(Count_UsingFixedFunction && (CY_PSOC5A))) */
        Count_SetInterruptMode(Count_INIT_INTERRUPTS_MASK);
        
        #if (!Count_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Count_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Count_WriteCompare(Count_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Count_interruptState = CyEnterCriticalSection();
            
            Count_STATUS_AUX_CTRL |= Count_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Count_interruptState);
            
        #endif /* (!Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void Count_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Count_UsingFixedFunction)
        Count_GLOBAL_ENABLE |= Count_BLOCK_EN_MASK;
        Count_GLOBAL_STBY_ENABLE |= Count_BLOCK_STBY_EN_MASK;
    #endif /* (Count_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Count_ControlRegRemoved || Count_UsingFixedFunction)
        Count_CONTROL |= Count_CTRL_ENABLE;                
    #endif /* (!Count_ControlRegRemoved || Count_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Count_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  Count_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Count_Start(void) 
{
    if(Count_initVar == 0u)
    {
        Count_Init();
        
        Count_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Count_Enable();        
}


/*******************************************************************************
* Function Name: Count_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void Count_Stop(void) 
{
    /* Disable Counter */
    #if(!Count_ControlRegRemoved || Count_UsingFixedFunction)
        Count_CONTROL &= ((uint8)(~Count_CTRL_ENABLE));        
    #endif /* (!Count_ControlRegRemoved || Count_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Count_UsingFixedFunction)
        Count_GLOBAL_ENABLE &= ((uint8)(~Count_BLOCK_EN_MASK));
        Count_GLOBAL_STBY_ENABLE &= ((uint8)(~Count_BLOCK_STBY_EN_MASK));
    #endif /* (Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void Count_SetInterruptMode(uint8 interruptsMask) 
{
    Count_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Count_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   Count_ReadStatusRegister(void) 
{
    return Count_STATUS;
}


#if(!Count_ControlRegRemoved)
/*******************************************************************************
* Function Name: Count_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   Count_ReadControlRegister(void) 
{
    return Count_CONTROL;
}


/*******************************************************************************
* Function Name: Count_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    Count_WriteControlRegister(uint8 control) 
{
    Count_CONTROL = control;
}

#endif  /* (!Count_ControlRegRemoved) */


#if (!(Count_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Count_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void Count_WriteCounter(uint8 counter) \
                                   
{
    #if(Count_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Count_GLOBAL_ENABLE & Count_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Count_GLOBAL_ENABLE |= Count_BLOCK_EN_MASK;
        CY_SET_REG16(Count_COUNTER_LSB_PTR, (uint16)counter);
        Count_GLOBAL_ENABLE &= ((uint8)(~Count_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(Count_COUNTER_LSB_PTR, counter);
    #endif /* (Count_UsingFixedFunction) */
}
#endif /* (!(Count_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Count_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) The present value of the counter.
*
*******************************************************************************/
uint8 Count_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Count_UsingFixedFunction)
		(void)CY_GET_REG16(Count_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Count_COUNTER_LSB_PTR_8BIT);
	#endif/* (Count_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Count_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Count_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Count_STATICCOUNT_LSB_PTR));
    #endif /* (Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) Present Capture value.
*
*******************************************************************************/
uint8 Count_ReadCapture(void) 
{
    #if(Count_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Count_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Count_STATICCOUNT_LSB_PTR));
    #endif /* (Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint8) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Count_WritePeriod(uint8 period) 
{
    #if(Count_UsingFixedFunction)
        CY_SET_REG16(Count_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(Count_PERIOD_LSB_PTR, period);
    #endif /* (Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) Present period value.
*
*******************************************************************************/
uint8 Count_ReadPeriod(void) 
{
    #if(Count_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Count_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(Count_PERIOD_LSB_PTR));
    #endif /* (Count_UsingFixedFunction) */
}


#if (!Count_UsingFixedFunction)
/*******************************************************************************
* Function Name: Count_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void Count_WriteCompare(uint8 compare) \
                                   
{
    #if(Count_UsingFixedFunction)
        CY_SET_REG16(Count_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(Count_COMPARE_LSB_PTR, compare);
    #endif /* (Count_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Count_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint8) Present compare value.
*
*******************************************************************************/
uint8 Count_ReadCompare(void) 
{
    return (CY_GET_REG8(Count_COMPARE_LSB_PTR));
}


#if (Count_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Count_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Count_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Count_CONTROL &= ((uint8)(~Count_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Count_CONTROL |= compareMode;
}
#endif  /* (Count_COMPARE_MODE_SOFTWARE) */


#if (Count_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Count_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Count_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Count_CONTROL &= ((uint8)(~Count_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Count_CONTROL |= ((uint8)((uint8)captureMode << Count_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Count_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Count_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void Count_ClearFIFO(void) 
{

    while(0u != (Count_ReadStatusRegister() & Count_STATUS_FIFONEMP))
    {
        (void)Count_ReadCapture();
    }

}
#endif  /* (!Count_UsingFixedFunction) */


/* [] END OF FILE */

