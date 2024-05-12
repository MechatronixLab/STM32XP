/*
 * app.c
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "app.h"

void APP_Init(void)
{
	CONSOLE_Init();
	DISPLAY_Init();

	BUZZER_SetVolume(1);

	ISR_StartInterruptTimer();

	APP_Run();
}

void APP_Run(void)
{
	while (1)
	{
		if (ISR_interrupt_flag)
		{
			ISR_interrupt_flag = 0;
			HAL_GPIO_TogglePin(LED_USER_GPIO_Port, LED_USER_Pin);
		}

		BUZZER_On();
		HAL_Delay(250);

		BUZZER_Off();
		HAL_Delay(250);
	}
}

