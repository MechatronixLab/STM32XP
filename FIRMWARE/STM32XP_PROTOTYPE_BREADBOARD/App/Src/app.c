/*
 * app.c
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "app.h"

void APP_Init(void)
{
	BUZZER_SetVolume(1);
	BUZZER_On();
	HAL_Delay(250);
	BUZZER_Off();

	CONSOLE_Init();

	VERSION_Get();

	DISPLAY_Init();

	SDCARD_Test();

	ADS_Test();
	ADS_Init();

	RGB_On();

	ISR_StartInterruptTimer();

	APP_Run();
}

void APP_Run(void)
{
	int16_t adc_reading = 0;
	int32_t adc_voltage = 0;

	uint32_t counter = 0;

	while (1)
	{
		if (ISR_interrupt_flag)
		{
			ISR_interrupt_flag = 0;
			HAL_GPIO_TogglePin(LED_USER_GPIO_Port, LED_USER_Pin);

			adc_reading = ADS_GetConversion();
			adc_voltage = (adc_reading * 6144) / 32767;
			CLI_Print("UART: Counter: %8d ; ADS1115[0] = 0x%4x ; %4d mV. \r\n", counter, adc_reading, adc_voltage);
			USB_CDC_Print("USB CDC: Counter: %8d ; ADS1115[0] = 0x%4x ; %4d mV. \r\n", counter, adc_reading, adc_voltage);
			counter++;
		}

		if (BUTTONS_debounced_press)
		{
			switch (BUTTONS_output)
			{
				case (BUTTONS_UP):
					RGB_SetColor(120, 120,   0);
					CLI_Write("UP! \r\n");
					break;

				case (BUTTONS_UP | BUTTONS_RIGHT):
					RGB_SetColor(180,  60,   0);
					CLI_Write("UP-RIGHT! \r\n");
					break;

				case BUTTONS_RIGHT:
					RGB_SetColor(240,   0,   0);
					CLI_Write("RIGHT! \r\n");
					break;

				case (BUTTONS_RIGHT | BUTTONS_DOWN):
					RGB_SetColor(120, 120,   0);
					CLI_Write("DOWN-RIGHT! \r\n");
					break;

				case BUTTONS_DOWN:
					RGB_SetColor(  0, 240,   0);
					CLI_Write("DOWN! \r\n");
					break;

				case (BUTTONS_DOWN | BUTTONS_LEFT):
					RGB_SetColor(  0, 120, 120);
					CLI_Write("DOWN-LEFT! \r\n");
					break;

				case BUTTONS_LEFT:
					RGB_SetColor(  0,   0, 240);
					CLI_Write("LEFT! \r\n");
					break;

				case (BUTTONS_LEFT | BUTTONS_UP):
					RGB_SetColor( 40,  40, 120);
					CLI_Write("UP-LEFT! \r\n");
					break;

				case BUTTONS_CENTER:
					RGB_SetColor( 80,  80,  80);
					CLI_Write("CENTER! \r\n");
					break;

				case BUTTONS_USER:
					RGB_SetColor(120,   0, 120);
					//CLI_Write("USER! \r\n");
					break;

				default:
					RGB_SetColor(  0,   0,   0);
					break;
			}

			ISR_button = 0;

			BUTTONS_debounced_press = 0;
		}

		if (HAL_GPIO_ReadPin(SD_NIN_GPIO_Port, SD_NIN_Pin))
		{
			RGB_SetColor(255,   0,   0);
		}
		else
		{
			RGB_SetColor(  0, 255,   0);
		}
	}
}

