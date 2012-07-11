/*******************************************************************************
* File Name: ADC_DelSig_1_AMux.h
* Version 1.50
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_ADC_DelSig_1_AMux_H)
#define CY_AMUX_ADC_DelSig_1_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void ADC_DelSig_1_AMux_Start(void);
void ADC_DelSig_1_AMux_Init(void);
void ADC_DelSig_1_AMux_Stop(void);
void ADC_DelSig_1_AMux_Select(uint8 channel) ;
void ADC_DelSig_1_AMux_FastSelect(uint8 channel) ;
void ADC_DelSig_1_AMux_DisconnectAll(void) ;
/* The Connect and Disconnect functions are declared elsewhere */
/* void ADC_DelSig_1_AMux_Connect(uint8 channel); */
/* void ADC_DelSig_1_AMux_Disconnect(uint8 channel); */


/***************************************
*     Initial Parameter Constants
***************************************/

#define ADC_DelSig_1_AMux_CHANNELS  2
#define ADC_DelSig_1_AMux_MUXTYPE   1


/***************************************
*             API Constants
***************************************/

#define ADC_DelSig_1_AMux_NULL_CHANNEL  0xFFu
#define ADC_DelSig_1_AMux_MUX_SINGLE   1
#define ADC_DelSig_1_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if ADC_DelSig_1_AMux_MUXTYPE == ADC_DelSig_1_AMux_MUX_SINGLE
# define ADC_DelSig_1_AMux_Connect(channel) ADC_DelSig_1_AMux_Set(channel)
# define ADC_DelSig_1_AMux_Disconnect(channel) ADC_DelSig_1_AMux_Unset(channel)
#else
void ADC_DelSig_1_AMux_Connect(uint8 channel) ;
void ADC_DelSig_1_AMux_Disconnect(uint8 channel) ;
#endif

#endif /* CY_AMUX_ADC_DelSig_1_AMux_H */


/* [] END OF FILE */
