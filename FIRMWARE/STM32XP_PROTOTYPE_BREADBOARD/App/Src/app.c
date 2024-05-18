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
	RGB_On();

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

		if (BUTTONS_debounced_press)
		{
			switch (BUTTONS_output)
			{
				case BUTTONS_UP:
					RGB_SetColor(200, 200,   0);
					break;

				case BUTTONS_DOWN:
					RGB_SetColor(  0, 200,   0);
					break;

				case BUTTONS_CENTER:
					RGB_SetColor(  0, 200, 200);
					break;

				case BUTTONS_LEFT:
					RGB_SetColor(  0,   0, 200);
					break;

				case BUTTONS_RIGHT:
					RGB_SetColor(200,   0,   0);
					break;

				case BUTTONS_USER:
					RGB_SetColor(200, 200, 200);
					break;

				default:
					RGB_SetColor(  0,   0,   0);
					break;
			}
			ISR_button = 0;

			BUTTONS_debounced_press = 0;
		}
	}
}

