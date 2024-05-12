/*
 * app.c
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "app.h"

void APP_Init(void)
{
	DISPLAY_Init();

	CONSOLE_Init();

	APP_Run();
}

void APP_Run(void)
{
	while (1)
	{
		HAL_GPIO_TogglePin(OLED_RST_GPIO_Port, OLED_RST_Pin);
		HAL_GPIO_TogglePin(LED_USER_GPIO_Port, LED_USER_Pin);
		HAL_Delay(250);
	}
}

