/*******************************************************************************
* File Name: PWM_1_PM.c
* Version 2.10
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "PWM_1.h"

static PWM_1_backupStruct PWM_1_backup;


/*******************************************************************************
* Function Name: PWM_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_1_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PWM_1_SaveConfig(void)
{
    
    #if(!PWM_1_UsingFixedFunction)
        #if (PWM_1_PSOC3_ES2 || PWM_1_PSOC5_ES1)
            PWM_1_backup.PWMUdb = PWM_1_ReadCounter();
            PWM_1_backup.PWMPeriod = PWM_1_ReadPeriod();
            #if (PWM_1_UseStatus)
                PWM_1_backup.InterruptMaskValue = PWM_1_STATUS_MASK;
            #endif
            
            #if(PWM_1_UseOneCompareMode)
                PWM_1_backup.PWMCompareValue = PWM_1_ReadCompare();
            #else
                PWM_1_backup.PWMCompareValue1 = PWM_1_ReadCompare1();
                PWM_1_backup.PWMCompareValue2 = PWM_1_ReadCompare2();
            #endif
            
           #if(PWM_1_DeadBandUsed)
                PWM_1_backup.PWMdeadBandValue = PWM_1_ReadDeadTime();
            #endif
          
            #if ( PWM_1_KillModeMinTime)
                PWM_1_backup.PWMKillCounterPeriod = PWM_1_ReadKillTime();
            #endif
        #endif
        
        #if (PWM_1_PSOC3_ES3 || PWM_1_PSOC5_ES2)
            #if(!PWM_1_PWMModeIsCenterAligned)
                PWM_1_backup.PWMPeriod = PWM_1_ReadPeriod();
            #endif
            PWM_1_backup.PWMUdb = PWM_1_ReadCounter();
            #if (PWM_1_UseStatus)
                PWM_1_backup.InterruptMaskValue = PWM_1_STATUS_MASK;
            #endif
            
            #if(PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_256_CLOCKS || PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_2_4_CLOCKS)
                PWM_1_backup.PWMdeadBandValue = PWM_1_ReadDeadTime();
            #endif
            
            #if(PWM_1_KillModeMinTime)
                 PWM_1_backup.PWMKillCounterPeriod = PWM_1_ReadKillTime();
            #endif
        #endif
        
        #if(PWM_1_UseControl)
            PWM_1_backup.PWMControlRegister = PWM_1_ReadControlRegister();
        #endif
    #endif  
}


/*******************************************************************************
* Function Name: PWM_1_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_1_backup:  Variables of this global structure are used to restore 
*  the values of non retention registers on wakeup from sleep mode.
*
* Reentrant:
*  Yes.
*
*******************************************************************************/
void PWM_1_RestoreConfig(void) 
{
        #if(!PWM_1_UsingFixedFunction)
            #if (PWM_1_PSOC3_ES2 || PWM_1_PSOC5_ES1)
                /* Interrupt State Backup for Critical Region*/
                uint8 PWM_1_interruptState;
                /* Enter Critical Region*/
                PWM_1_interruptState = CyEnterCriticalSection();
                #if (PWM_1_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    PWM_1_STATUS_AUX_CTRL |= PWM_1_STATUS_ACTL_INT_EN_MASK;
                    
                    PWM_1_STATUS_MASK = PWM_1_backup.InterruptMaskValue;
                #endif
                
                #if (PWM_1_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    PWM_1_AUX_CONTROLDP0 |= (PWM_1_AUX_CTRL_FIFO0_CLR);
                #else /* (PWM_1_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    PWM_1_AUX_CONTROLDP0 |= (PWM_1_AUX_CTRL_FIFO0_CLR);
                    PWM_1_AUX_CONTROLDP1 |= (PWM_1_AUX_CTRL_FIFO0_CLR);
                #endif
                /* Exit Critical Region*/
                CyExitCriticalSection(PWM_1_interruptState);
                
                PWM_1_WriteCounter(PWM_1_backup.PWMUdb);
                PWM_1_WritePeriod(PWM_1_backup.PWMPeriod);
                
                #if(PWM_1_UseOneCompareMode)
                    PWM_1_WriteCompare(PWM_1_backup.PWMCompareValue);
                #else
                    PWM_1_WriteCompare1(PWM_1_backup.PWMCompareValue1);
                    PWM_1_WriteCompare2(PWM_1_backup.PWMCompareValue2);
                #endif
                
               #if(PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_256_CLOCKS || PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_2_4_CLOCKS)
                    PWM_1_WriteDeadTime(PWM_1_backup.PWMdeadBandValue);
                #endif
            
                #if ( PWM_1_KillModeMinTime)
                    PWM_1_WriteKillTime(PWM_1_backup.PWMKillCounterPeriod);
                #endif
            #endif
            
            #if (PWM_1_PSOC3_ES3 || PWM_1_PSOC5_ES2)
                #if(!PWM_1_PWMModeIsCenterAligned)
                    PWM_1_WritePeriod(PWM_1_backup.PWMPeriod);
                #endif
                PWM_1_WriteCounter(PWM_1_backup.PWMUdb);
                #if (PWM_1_UseStatus)
                    PWM_1_STATUS_MASK = PWM_1_backup.InterruptMaskValue;
                #endif
                
                #if(PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_256_CLOCKS || PWM_1_DeadBandMode == PWM_1__B_PWM__DBM_2_4_CLOCKS)
                    PWM_1_WriteDeadTime(PWM_1_backup.PWMdeadBandValue);
                #endif
                
                #if(PWM_1_KillModeMinTime)
                    PWM_1_WriteKillTime(PWM_1_backup.PWMKillCounterPeriod);
                #endif
            #endif
            
            #if(PWM_1_UseControl)
                PWM_1_WriteControlRegister(PWM_1_backup.PWMControlRegister); 
            #endif
        #endif  
    }


/*******************************************************************************
* Function Name: PWM_1_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_1_backup.PWMEnableState:  Is modified depending on the enable state
*  of the block before entering sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void PWM_1_Sleep(void)
{
    #if(PWM_1_UseControl)
        if(PWM_1_CTRL_ENABLE == (PWM_1_CONTROL & PWM_1_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_1_backup.PWMEnableState = 0u;
        }
    #endif
    /* Stop component */
    PWM_1_Stop();
    
    /* Save registers configuration */
    PWM_1_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_1_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  PWM_1_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void PWM_1_Wakeup(void) 
{
     /* Restore registers values */
    PWM_1_RestoreConfig();
    
    if(PWM_1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_1_Enable();
    } /* Do nothing if component's block was disabled before */
    
}

/* [] END OF FILE */
