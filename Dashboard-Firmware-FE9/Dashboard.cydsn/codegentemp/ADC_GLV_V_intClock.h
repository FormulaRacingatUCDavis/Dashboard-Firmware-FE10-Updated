/*******************************************************************************
* File Name: ADC_GLV_V_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ADC_GLV_V_intClock_H)
#define CY_CLOCK_ADC_GLV_V_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ADC_GLV_V_intClock_StartEx(uint32 alignClkDiv);
#define ADC_GLV_V_intClock_Start() \
    ADC_GLV_V_intClock_StartEx(ADC_GLV_V_intClock__PA_DIV_ID)

#else

void ADC_GLV_V_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ADC_GLV_V_intClock_Stop(void);

void ADC_GLV_V_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ADC_GLV_V_intClock_GetDividerRegister(void);
uint8  ADC_GLV_V_intClock_GetFractionalDividerRegister(void);

#define ADC_GLV_V_intClock_Enable()                         ADC_GLV_V_intClock_Start()
#define ADC_GLV_V_intClock_Disable()                        ADC_GLV_V_intClock_Stop()
#define ADC_GLV_V_intClock_SetDividerRegister(clkDivider, reset)  \
    ADC_GLV_V_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define ADC_GLV_V_intClock_SetDivider(clkDivider)           ADC_GLV_V_intClock_SetDividerRegister((clkDivider), 1u)
#define ADC_GLV_V_intClock_SetDividerValue(clkDivider)      ADC_GLV_V_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ADC_GLV_V_intClock_DIV_ID     ADC_GLV_V_intClock__DIV_ID

#define ADC_GLV_V_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ADC_GLV_V_intClock_CTRL_REG   (*(reg32 *)ADC_GLV_V_intClock__CTRL_REGISTER)
#define ADC_GLV_V_intClock_DIV_REG    (*(reg32 *)ADC_GLV_V_intClock__DIV_REGISTER)

#define ADC_GLV_V_intClock_CMD_DIV_SHIFT          (0u)
#define ADC_GLV_V_intClock_CMD_PA_DIV_SHIFT       (8u)
#define ADC_GLV_V_intClock_CMD_DISABLE_SHIFT      (30u)
#define ADC_GLV_V_intClock_CMD_ENABLE_SHIFT       (31u)

#define ADC_GLV_V_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ADC_GLV_V_intClock_CMD_DISABLE_SHIFT))
#define ADC_GLV_V_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ADC_GLV_V_intClock_CMD_ENABLE_SHIFT))

#define ADC_GLV_V_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define ADC_GLV_V_intClock_DIV_FRAC_SHIFT (3u)
#define ADC_GLV_V_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define ADC_GLV_V_intClock_DIV_INT_SHIFT  (8u)

#else 

#define ADC_GLV_V_intClock_DIV_REG        (*(reg32 *)ADC_GLV_V_intClock__REGISTER)
#define ADC_GLV_V_intClock_ENABLE_REG     ADC_GLV_V_intClock_DIV_REG
#define ADC_GLV_V_intClock_DIV_FRAC_MASK  ADC_GLV_V_intClock__FRAC_MASK
#define ADC_GLV_V_intClock_DIV_FRAC_SHIFT (16u)
#define ADC_GLV_V_intClock_DIV_INT_MASK   ADC_GLV_V_intClock__DIVIDER_MASK
#define ADC_GLV_V_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ADC_GLV_V_intClock_H) */

/* [] END OF FILE */
