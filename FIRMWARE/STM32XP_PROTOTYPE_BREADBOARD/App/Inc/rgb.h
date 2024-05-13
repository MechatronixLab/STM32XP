/*
 * rgb.h
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_RGB_H_
#define INC_RGB_H_

#include "main.h"

extern TIM_HandleTypeDef htim3;

#define RGB_TIMER_HANDLE	htim3
#define RGB_R_CHANNEL		TIM_CHANNEL_1
#define RGB_G_CHANNEL		TIM_CHANNEL_2
#define RGB_B_CHANNEL		TIM_CHANNEL_3

void RGB_On (void);
void RGB_Off(void);
void RGB_SetColor(uint16_t R, uint16_t G, uint16_t B);

#endif /* INC_RGB_H_ */
