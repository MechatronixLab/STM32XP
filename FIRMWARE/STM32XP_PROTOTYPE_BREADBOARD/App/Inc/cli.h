/*
 * cli.h
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_CLI_H_
#define INC_CLI_H_

#include "usart.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern UART_HandleTypeDef 	huart1;

#define CLI_UART_HANDLE		huart1		// Change here if using other UART

void CLI_Write(char * buffer);
void CLI_NewLine(void);

void CLI_Print(const char *fmt, ...);	// Equivalent to printf(), but prints to serial port

#endif /* INC_CLI_H_ */
