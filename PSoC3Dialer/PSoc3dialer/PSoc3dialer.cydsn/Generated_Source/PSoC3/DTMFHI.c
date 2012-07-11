/*******************************************************************************
* File Name: DTMFHI.c  
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
#include "DTMFHI.h"


/*******************************************************************************
* Function Name: DTMFHI_Write
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
void DTMFHI_Write(uint8 value) 
{
    uint8 staticBits = DTMFHI_DR & ~DTMFHI_MASK;
    DTMFHI_DR = staticBits | ((value << DTMFHI_SHIFT) & DTMFHI_MASK);
}


/*******************************************************************************
* Function Name: DTMFHI_SetDriveMode
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
void DTMFHI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DTMFHI_0, mode);
}


/*******************************************************************************
* Function Name: DTMFHI_Read
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
*  Macro DTMFHI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DTMFHI_Read(void) 
{
    return (DTMFHI_PS & DTMFHI_MASK) >> DTMFHI_SHIFT;
}


/*******************************************************************************
* Function Name: DTMFHI_ReadDataReg
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
uint8 DTMFHI_ReadDataReg(void) 
{
    return (DTMFHI_DR & DTMFHI_MASK) >> DTMFHI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DTMFHI_INTSTAT) 

    /*******************************************************************************
    * Function Name: DTMFHI_ClearInterrupt
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
    uint8 DTMFHI_ClearInterrupt(void) 
    {
        return (DTMFHI_INTSTAT & DTMFHI_MASK) >> DTMFHI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
