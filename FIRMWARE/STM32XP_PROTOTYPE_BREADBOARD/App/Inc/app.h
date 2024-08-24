/*
 * app.h
 *
 *  Created on: May 11, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"

#include "ads1115.h"
#include "buzzer.h"
#include "colors.h"
#include "console.h"
#include "display.h"
#include "isr.h"
#include "neopixel.h"
#include "rgb.h"
#include "rtcc.h"
#include "sdcard.h"
#include "usb_device_cdc.h"

void APP_Init(void);
void APP_Run(void);

#endif /* INC_APP_H_ */
