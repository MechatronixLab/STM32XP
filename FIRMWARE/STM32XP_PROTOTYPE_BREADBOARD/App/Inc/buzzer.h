/*
 * buzzer.h
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"
#include "tim.h"

#define BUZZER_TIMER_HANDLE	htim3
#define BUZZER_PWM_CHANNEL	TIM_CHANNEL_4

void BUZZER_On(void);
void BUZZER_Off(void);
void BUZZER_SetVolume(uint8_t volume);
//void BUZZER_SetTone(uint16_t frequency);	// TODO


#endif /* INC_BUZZER_H_ */
