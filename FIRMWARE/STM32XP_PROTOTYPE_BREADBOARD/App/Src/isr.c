/*
 * isr.c
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "isr.h"

uint8_t	ISR_interrupt_flag = 0;
uint8_t ISR_button = 0;

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
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)	// TODO: Debouncing
{
	if (GPIO_Pin == BUTTON_UP_Pin)
	{
		CLI_Write("UP \n");
		ISR_button = ISR_BUTTON_UP;
	}

	else if (GPIO_Pin == BUTTON_DOWN_Pin)
	{
		CLI_Write("DOWN \n");
		ISR_button = ISR_BUTTON_DOWN;
	}

	else if (GPIO_Pin == BUTTON_CENTER_Pin)
	{
		CLI_Write("CENTER \n");
		ISR_button = ISR_BUTTON_CENTER;
	}

	else if (GPIO_Pin == BUTTON_LEFT_Pin)
	{
		CLI_Write("LEFT \n");
		ISR_button = ISR_BUTTON_LEFT;
	}

	else if (GPIO_Pin == BUTTON_RIGHT_Pin)
	{
		CLI_Write("RIGHT \n");
		ISR_button = ISR_BUTTON_RIGHT;
	}
}
