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

	BUZZER_SetVolume(0);

	APP_Run();
}

void APP_Run(void)
{
	while (1)
	{
		HAL_GPIO_WritePin(LED_USER_GPIO_Port, LED_USER_Pin, 1);
		BUZZER_On();

		HAL_Delay(250);

		HAL_GPIO_WritePin(LED_USER_GPIO_Port, LED_USER_Pin, 0);
		BUZZER_Off();

		HAL_Delay(250);
	}
}

