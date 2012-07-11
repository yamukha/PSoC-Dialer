/*******************************************************************************
* File Name: DTMFLO.h  
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

#if !defined(CY_PINS_DTMFLO_H) /* Pins DTMFLO_H */
#define CY_PINS_DTMFLO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DTMFLO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DTMFLO_Write(uint8 value) ;
void    DTMFLO_SetDriveMode(uint8 mode) ;
uint8   DTMFLO_ReadDataReg(void) ;
uint8   DTMFLO_Read(void) ;
uint8   DTMFLO_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DTMFLO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DTMFLO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DTMFLO_DM_RES_UP          PIN_DM_RES_UP
#define DTMFLO_DM_RES_DWN         PIN_DM_RES_DWN
#define DTMFLO_DM_OD_LO           PIN_DM_OD_LO
#define DTMFLO_DM_OD_HI           PIN_DM_OD_HI
#define DTMFLO_DM_STRONG          PIN_DM_STRONG
#define DTMFLO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DTMFLO_MASK               DTMFLO__MASK
#define DTMFLO_SHIFT              DTMFLO__SHIFT
#define DTMFLO_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DTMFLO_PS                     (* (reg8 *) DTMFLO__PS)
/* Data Register */
#define DTMFLO_DR                     (* (reg8 *) DTMFLO__DR)
/* Port Number */
#define DTMFLO_PRT_NUM                (* (reg8 *) DTMFLO__PRT) 
/* Connect to Analog Globals */                                                  
#define DTMFLO_AG                     (* (reg8 *) DTMFLO__AG)                       
/* Analog MUX bux enable */
#define DTMFLO_AMUX                   (* (reg8 *) DTMFLO__AMUX) 
/* Bidirectional Enable */                                                        
#define DTMFLO_BIE                    (* (reg8 *) DTMFLO__BIE)
/* Bit-mask for Aliased Register Access */
#define DTMFLO_BIT_MASK               (* (reg8 *) DTMFLO__BIT_MASK)
/* Bypass Enable */
#define DTMFLO_BYP                    (* (reg8 *) DTMFLO__BYP)
/* Port wide control signals */                                                   
#define DTMFLO_CTL                    (* (reg8 *) DTMFLO__CTL)
/* Drive Modes */
#define DTMFLO_DM0                    (* (reg8 *) DTMFLO__DM0) 
#define DTMFLO_DM1                    (* (reg8 *) DTMFLO__DM1)
#define DTMFLO_DM2                    (* (reg8 *) DTMFLO__DM2) 
/* Input Buffer Disable Override */
#define DTMFLO_INP_DIS                (* (reg8 *) DTMFLO__INP_DIS)
/* LCD Common or Segment Drive */
#define DTMFLO_LCD_COM_SEG            (* (reg8 *) DTMFLO__LCD_COM_SEG)
/* Enable Segment LCD */
#define DTMFLO_LCD_EN                 (* (reg8 *) DTMFLO__LCD_EN)
/* Slew Rate Control */
#define DTMFLO_SLW                    (* (reg8 *) DTMFLO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DTMFLO_PRTDSI__CAPS_SEL       (* (reg8 *) DTMFLO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DTMFLO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DTMFLO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DTMFLO_PRTDSI__OE_SEL0        (* (reg8 *) DTMFLO__PRTDSI__OE_SEL0) 
#define DTMFLO_PRTDSI__OE_SEL1        (* (reg8 *) DTMFLO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DTMFLO_PRTDSI__OUT_SEL0       (* (reg8 *) DTMFLO__PRTDSI__OUT_SEL0) 
#define DTMFLO_PRTDSI__OUT_SEL1       (* (reg8 *) DTMFLO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DTMFLO_PRTDSI__SYNC_OUT       (* (reg8 *) DTMFLO__PRTDSI__SYNC_OUT) 


#if defined(DTMFLO__INTSTAT)  /* Interrupt Registers */

    #define DTMFLO_INTSTAT                (* (reg8 *) DTMFLO__INTSTAT)
    #define DTMFLO_SNAP                   (* (reg8 *) DTMFLO__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DTMFLO_H */


/* [] END OF FILE */
