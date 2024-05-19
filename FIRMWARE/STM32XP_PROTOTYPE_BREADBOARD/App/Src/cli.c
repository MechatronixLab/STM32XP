/*
 * cli.c
 *
 *  Created on: May 12, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "cli.h"

void CLI_Write(char * buffer)
{
	HAL_UART_Transmit(&CLI_UART_HANDLE,
			(uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

void CLI_NewLine(void)
{
	CLI_Write("\r\n");
}

void CLI_Print(const char *fmt, ...)
{
	static char buffer[256];
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	HAL_UART_Transmit(&CLI_UART_HANDLE, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
}
