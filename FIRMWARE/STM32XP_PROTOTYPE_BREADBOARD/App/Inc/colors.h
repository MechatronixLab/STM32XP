/*
 * colors.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_COLORS_H_
#define INC_COLORS_H_

#include "main.h"

void COLORS_Sweep(void);

extern enum COLORS_colors {off, red, yellow, green, cyan, blue, purple, white} COLORS_state;

extern uint16_t COLORS_R, COLORS_G, COLORS_B;

#endif /* INC_COLORS_H_ */
