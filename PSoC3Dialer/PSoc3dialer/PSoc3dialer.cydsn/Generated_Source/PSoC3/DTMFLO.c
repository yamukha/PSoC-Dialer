/*******************************************************************************
* File Name: DTMFLO.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "DTMFLO.h"


/*******************************************************************************
* Function Name: DTMFLO_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void DTMFLO_Write(uint8 value) 
{
    uint8 staticBits = DTMFLO_DR & ~DTMFLO_MASK;
    DTMFLO_DR = staticBits | ((value << DTMFLO_SHIFT) & DTMFLO_MASK);
}


/*******************************************************************************
* Function Name: DTMFLO_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void DTMFLO_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DTMFLO_0, mode);
}


/*******************************************************************************
* Function Name: DTMFLO_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro DTMFLO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DTMFLO_Read(void) 
{
    return (DTMFLO_PS & DTMFLO_MASK) >> DTMFLO_SHIFT;
}


/*******************************************************************************
* Function Name: DTMFLO_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 DTMFLO_ReadDataReg(void) 
{
    return (DTMFLO_DR & DTMFLO_MASK) >> DTMFLO_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DTMFLO_INTSTAT) 

    /*******************************************************************************
    * Function Name: DTMFLO_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 DTMFLO_ClearInterrupt(void) 
    {
        return (DTMFLO_INTSTAT & DTMFLO_MASK) >> DTMFLO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
