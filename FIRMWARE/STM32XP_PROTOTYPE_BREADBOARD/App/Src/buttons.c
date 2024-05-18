/*
 * buttons.c
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "buttons.h"

static uint16_t previous_buttons = 0x0000;
	   uint16_t current_buttons  = 0x0000;

	   uint8_t  BUTTONS_debounced_press = 0;
	   uint8_t  BUTTONS_debounced_release = 0;
	   uint16_t BUTTONS_output = 0;

void BUTTONS_debounce(void)
{

	static uint8_t debounce_counter = 0;

	current_buttons = BUTTONS_MASK_STATUS
			        ^ (HAL_GPIO_ReadPin(BUTTON_UP_GPIO_Port    , BUTTON_UP_Pin    ) * BUTTONS_UP    )
					^ (HAL_GPIO_ReadPin(BUTTON_DOWN_GPIO_Port  , BUTTON_DOWN_Pin  ) * BUTTONS_DOWN  )
					^ (HAL_GPIO_ReadPin(BUTTON_CENTER_GPIO_Port, BUTTON_CENTER_Pin) * BUTTONS_CENTER)
					^ (HAL_GPIO_ReadPin(BUTTON_LEFT_GPIO_Port  , BUTTON_LEFT_Pin  ) * BUTTONS_LEFT  )
					^ (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port , BUTTON_RIGHT_Pin ) * BUTTONS_RIGHT )
					^ (HAL_GPIO_ReadPin(BUTTON_USER_GPIO_Port  , BUTTON_USER_Pin  ) * BUTTONS_USER  );
//	current_buttons = (current_buttons ^ 0xFFFF);

	if (current_buttons == previous_buttons)
	{
		debounce_counter++;
	}
	else
	{
		debounce_counter = 0;
	}

	if (debounce_counter >= BUTTONS_DEBOUNCE_PERIOD)
	{
		HAL_TIM_Base_Stop(&ISR_DEBOUNCE_TIMER_HANDLER);
		debounce_counter = 0;

		if (current_buttons != 0x0000)
		{
			BUTTONS_debounced_press = 1;
		}
		else
		{
			BUTTONS_debounced_release = 1;
		}

		BUTTONS_output = current_buttons;

		__HAL_GPIO_EXTI_CLEAR_IT(BUTTONS_MASK_GPIO);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
		HAL_NVIC_EnableIRQ(EXTI2_IRQn);
		HAL_NVIC_EnableIRQ(EXTI4_IRQn);
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	}

	previous_buttons = current_buttons;
}
