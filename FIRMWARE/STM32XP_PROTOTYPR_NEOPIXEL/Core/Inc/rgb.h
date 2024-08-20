/*
 * rgb.h
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_RGB_H_
#define INC_RGB_H_

#include "main.h"

#include "ws2812.h"

void RGB_sweep(void);

extern enum RGB_colors {off, red, yellow, green, cyan, blue, purple, white} RGB_state;

extern uint16_t RGB_R, RGB_G, RGB_B;

#endif /* INC_RGB_H_ */
