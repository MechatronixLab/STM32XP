/*
 * buttons.h
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "main.h"

#include "isr.h"

#define BUTTONS_DEBOUNCE_PERIOD		10	// ms
#define BUTTONS_MASK_GPIO	(BUTTON_UP_Pin | BUTTON_DOWN_Pin | BUTTON_CENTER_Pin | BUTTON_LEFT_Pin | BUTTON_RIGHT_Pin | BUTTON_USER_Pin)
#define BUTTONS_MASK_STATUS (BUTTONS_UP | BUTTONS_DOWN | BUTTONS_CENTER | BUTTONS_LEFT | BUTTONS_RIGHT | BUTTONS_USER)

#define BUTTONS_UP		0x01
#define BUTTONS_DOWN	0x02
#define BUTTONS_CENTER	0x04
#define BUTTONS_LEFT	0x08
#define BUTTONS_RIGHT	0x10
#define BUTTONS_USER	0x80

extern uint8_t  BUTTONS_debounced_press;
extern uint8_t  BUTTONS_debounced_release;
extern uint16_t BUTTONS_output;

void BUTTONS_debounce(void);

#endif /* INC_BUTTONS_H_ */
