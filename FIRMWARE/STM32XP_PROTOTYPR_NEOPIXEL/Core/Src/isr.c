/*
 * isr.c
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#include "isr.h"

volatile uint8_t flag_data_sent = 0;

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
//	HAL_DMA_Init(&hdma_tim2_ch1);
	flag_data_sent = 1;
}
