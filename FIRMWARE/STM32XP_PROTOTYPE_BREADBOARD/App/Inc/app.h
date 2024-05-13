/*
 * app.h
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"

#include "buzzer.h"
#include "console.h"
#include "display.h"
#include "isr.h"
#include "rgb.h"

void APP_Init(void);
void APP_Run(void);

#endif /* INC_APP_H_ */
