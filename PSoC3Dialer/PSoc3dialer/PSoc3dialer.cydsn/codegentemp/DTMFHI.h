/*******************************************************************************
* File Name: DTMFHI.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_DTMFHI_H) /* Pins DTMFHI_H */
#define CY_PINS_DTMFHI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DTMFHI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DTMFHI_Write(uint8 value) ;
void    DTMFHI_SetDriveMode(uint8 mode) ;
uint8   DTMFHI_ReadDataReg(void) ;
uint8   DTMFHI_Read(void) ;
uint8   DTMFHI_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DTMFHI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DTMFHI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DTMFHI_DM_RES_UP          PIN_DM_RES_UP
#define DTMFHI_DM_RES_DWN         PIN_DM_RES_DWN
#define DTMFHI_DM_OD_LO           PIN_DM_OD_LO
#define DTMFHI_DM_OD_HI           PIN_DM_OD_HI
#define DTMFHI_DM_STRONG          PIN_DM_STRONG
#define DTMFHI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DTMFHI_MASK               DTMFHI__MASK
#define DTMFHI_SHIFT              DTMFHI__SHIFT
#define DTMFHI_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DTMFHI_PS                     (* (reg8 *) DTMFHI__PS)
/* Data Register */
#define DTMFHI_DR                     (* (reg8 *) DTMFHI__DR)
/* Port Number */
#define DTMFHI_PRT_NUM                (* (reg8 *) DTMFHI__PRT) 
/* Connect to Analog Globals */                                                  
#define DTMFHI_AG                     (* (reg8 *) DTMFHI__AG)                       
/* Analog MUX bux enable */
#define DTMFHI_AMUX                   (* (reg8 *) DTMFHI__AMUX) 
/* Bidirectional Enable */                                                        
#define DTMFHI_BIE                    (* (reg8 *) DTMFHI__BIE)
/* Bit-mask for Aliased Register Access */
#define DTMFHI_BIT_MASK               (* (reg8 *) DTMFHI__BIT_MASK)
/* Bypass Enable */
#define DTMFHI_BYP                    (* (reg8 *) DTMFHI__BYP)
/* Port wide control signals */                                                   
#define DTMFHI_CTL                    (* (reg8 *) DTMFHI__CTL)
/* Drive Modes */
#define DTMFHI_DM0                    (* (reg8 *) DTMFHI__DM0) 
#define DTMFHI_DM1                    (* (reg8 *) DTMFHI__DM1)
#define DTMFHI_DM2                    (* (reg8 *) DTMFHI__DM2) 
/* Input Buffer Disable Override */
#define DTMFHI_INP_DIS                (* (reg8 *) DTMFHI__INP_DIS)
/* LCD Common or Segment Drive */
#define DTMFHI_LCD_COM_SEG            (* (reg8 *) DTMFHI__LCD_COM_SEG)
/* Enable Segment LCD */
#define DTMFHI_LCD_EN                 (* (reg8 *) DTMFHI__LCD_EN)
/* Slew Rate Control */
#define DTMFHI_SLW                    (* (reg8 *) DTMFHI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DTMFHI_PRTDSI__CAPS_SEL       (* (reg8 *) DTMFHI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DTMFHI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DTMFHI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DTMFHI_PRTDSI__OE_SEL0        (* (reg8 *) DTMFHI__PRTDSI__OE_SEL0) 
#define DTMFHI_PRTDSI__OE_SEL1        (* (reg8 *) DTMFHI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DTMFHI_PRTDSI__OUT_SEL0       (* (reg8 *) DTMFHI__PRTDSI__OUT_SEL0) 
#define DTMFHI_PRTDSI__OUT_SEL1       (* (reg8 *) DTMFHI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DTMFHI_PRTDSI__SYNC_OUT       (* (reg8 *) DTMFHI__PRTDSI__SYNC_OUT) 


#if defined(DTMFHI__INTSTAT)  /* Interrupt Registers */

    #define DTMFHI_INTSTAT                (* (reg8 *) DTMFHI__INTSTAT)
    #define DTMFHI_SNAP                   (* (reg8 *) DTMFHI__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DTMFHI_H */


/* [] END OF FILE */
