/*
 * led_matrix.h
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_


#include "tim.h"
#include "dma.h"

#include "isr.h"
#include "ws2812.h"

#define LED_MATRIX_NUM_LEDS	64

extern DMA_HandleTypeDef hdma_tim2_ch1;

extern uint8_t LED_id;

extern uint8_t LED_matrix_data[LED_MATRIX_NUM_LEDS][3];

extern uint32_t LED_pulse[24+50];

void LED_init (void);

void LED_set_color (uint8_t LED_id, uint8_t red, uint8_t green, uint8_t blue);

void LED_write(uint8_t red, uint8_t green, uint8_t blue);

void LED_write_matrix (void);

#endif /* INC_LED_MATRIX_H_ */
