/*
 * neopixel.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "neopixel.h"

uint8_t LED_id = 0;

uint8_t LED_matrix_data[NEOPIXEL_MATRIX_NUM_LEDS][3];

uint32_t PWM_buffer[24*NEOPIXEL_MATRIX_NUM_LEDS + 50];

extern DMA_HandleTypeDef hdma_tim2_ch1;

void NEOPIXEL_Init (void)
{
	uint8_t LED_id = 0;

	for (LED_id = 0; LED_id < NEOPIXEL_MATRIX_NUM_LEDS; LED_id++)
	{
		NEOPIXEL_Set_Color(LED_id, 0x00, 0x00, 0x00);
	}
}

void NEOPIXEL_Set_Color (uint8_t LED_id, uint8_t red, uint8_t green, uint8_t blue)
{
	LED_matrix_data[LED_id][0] = red;
	LED_matrix_data[LED_id][1] = green;
	LED_matrix_data[LED_id][2] = blue;
}

void NEOPIXEL_Write(uint8_t red, uint8_t green, uint8_t blue)
{
	int8_t color_bit = 0;
	uint8_t end_of_message = 0;
	uint32_t WS2812_color = (red << 8) | (green << 16) | blue;

	for (color_bit = 0; color_bit < 24; color_bit++)
	{
		if ( (WS2812_color >> (23 - color_bit)) & 0x01 )
		{
			PWM_buffer[color_bit] = NEOPIXEL_BIT_SET;
		}
		else
		{
			PWM_buffer[color_bit] = NEOPIXEL_BIT_RST;
		}
	}
	for (end_of_message = 24; end_of_message<(24+50); end_of_message++)
	{
		PWM_buffer[color_bit] = 0;
	}

	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)PWM_buffer, 24+50);

	while(!flag_data_sent)	// TODO: fazer timeout
	{
		asm("NOP");
	}
	flag_data_sent = 0;
	HAL_DMA_Abort(&hdma_tim2_ch1);
}


void NEOPIXEL_Write_Matrix (void)
{
	uint16_t index = 0;
	uint8_t LED_id = 0;
	uint8_t bit_counter = 0;
	uint32_t color = 0;

	for (LED_id = 0; LED_id < NEOPIXEL_MATRIX_NUM_LEDS; LED_id++)
	{
		color = (LED_matrix_data[LED_id][0] << 8)
		      | (LED_matrix_data[LED_id][1] << 16)
			  |  LED_matrix_data[LED_id][2];

		for (bit_counter = 0; bit_counter < 24; bit_counter++)
		{
			if ( (color >> (23 - bit_counter)) & 0x01 )
			{
				PWM_buffer[index] = NEOPIXEL_BIT_SET;
			}
			else
			{
				PWM_buffer[index] = NEOPIXEL_BIT_RST;
			}

			index++;
		}
	}

	for (bit_counter = 0; bit_counter < 50; bit_counter++)
	{
		PWM_buffer[index] = 0;
		index++;
	}

	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)PWM_buffer, index);
	while(!flag_data_sent)
	{
		asm("NOP");
	}
	flag_data_sent = 0;
	HAL_DMA_Abort(&hdma_tim2_ch1);	// Investigando por que no C0 o DMA fica ocupado após primeira interrupção.
									// Solução paliativa foi usar esta função para "destravar" o DMA.
}
