/*
 * neopixel.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_NEOPIXEL_H_
#define INC_NEOPIXEL_H_

#include "tim.h"
#include "dma.h"

#include "isr.h"

#define NEOPIXEL_MATRIX_NUM_LEDS	57

#define NEOPIXEL_BIT_WIDTH	(60 - 1)
#define NEOPIXEL_BIT_SET 		  40
#define NEOPIXEL_BIT_RST 	      20

extern DMA_HandleTypeDef hdma_tim2_ch1;

extern uint8_t LED_id;

extern uint8_t LED_matrix_data[NEOPIXEL_MATRIX_NUM_LEDS][3];

extern uint32_t LED_pulse[24+50];

void NEOPIXEL_Init (void);
void NEOPIXEL_Set_Color (uint8_t LED_id, uint8_t red, uint8_t green, uint8_t blue);
void NEOPIXEL_Write(uint8_t red, uint8_t green, uint8_t blue);
void NEOPIXEL_Write_Matrix (void);

#endif /* INC_NEOPIXEL_H_ */
