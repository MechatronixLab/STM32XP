/*
 * isr.h
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_ISR_H_
#define INC_ISR_H_

#include "main.h"

#include "cli.h"

extern TIM_HandleTypeDef htim5;

#define ISR_INTERRUPT_TIMER_HANDLE	htim5

////#define TIM16_SAMPLE_RATE	30					// Hz
//
//#define TIM16_PSC (48000 - 1)					// 1 kHz
//#define TIM16_ARR (1000/TIM16_SAMPLE_RATE - 1)	// TIM16_SAMPLE_RATE Hz

extern uint8_t	ISR_interrupt_flag;

void ISR_StartInterruptTimer(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_ISR_H_ */
