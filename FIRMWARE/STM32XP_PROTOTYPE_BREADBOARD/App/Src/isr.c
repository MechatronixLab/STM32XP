/*
 * isr.c
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "isr.h"

uint8_t	ISR_interrupt_flag = 0;
uint8_t ISR_button = 0;

volatile uint8_t ISR_flag_data_sent = 0;
volatile uint8_t ISR_flag_ADC_EOC = 0;

void ISR_StartInterruptTimer(void)
{
	HAL_TIM_Base_Start_IT(&ISR_INTERRUPT_TIMER_HANDLE);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &ISR_INTERRUPT_TIMER_HANDLE)
	{	// Flag for interrupt routines to be handled in the main loop: APP_Run();
		ISR_interrupt_flag = 1;
	}
	else if (htim == &ISR_DEBOUNCE_TIMER_HANDLER)	// Timed debounce routine:
	{												//	After first edge is detected, accumulate
													// 	DEBOUNCE_STABLE_PERIOD equal samples and
													// 	finally set PRESSED or RELEASED flag and
													//	disables this counter until next edge occurs
		BUTTONS_debounce();
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	__HAL_GPIO_EXTI_CLEAR_IT(BUTTONS_MASK_GPIO);
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	HAL_NVIC_DisableIRQ(EXTI1_IRQn);
	HAL_NVIC_DisableIRQ(EXTI2_IRQn);
	HAL_NVIC_DisableIRQ(EXTI4_IRQn);
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
	__HAL_GPIO_EXTI_CLEAR_IT(BUTTONS_MASK_GPIO);

	switch (GPIO_Pin)
	{
		case BUTTON_UP_Pin   	:
		case BUTTON_DOWN_Pin  	:
		case BUTTON_CENTER_Pin	:
		case BUTTON_LEFT_Pin  	:
		case BUTTON_RIGHT_Pin 	:
			CLI_Write("Directional Button pressed: ");
			break;

		case BUTTON_USER_Pin  	:
			CLI_Write("USER Button pressed \r\n");
			break;
	}

	HAL_TIM_Base_Start_IT(&ISR_DEBOUNCE_TIMER_HANDLER);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
	ISR_flag_data_sent = 1;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{	// Interrupção que ocorre quando um conjunto de conversões é finalizado
	ISR_flag_ADC_EOC = 1;								// Seta flag para tratamento no main()
}
