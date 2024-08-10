/*
 * usb_device_cdc.c
 *
 *  Created on: Aug 10, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "usb_device_cdc.h"

char *usbd_cdc_data = "Hello World from USB CDC \r\n";

void USB_CDC_Write(char * buffer)
{
	CDC_Transmit_FS((uint8_t *)buffer, strlen(buffer));
}

void USB_CDC_NewLine(void)
{
	USB_CDCI_Write("\r\n");
}

void USB_CDC_Print(const char *fmt, ...)
{
	static char buffer[256];
	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	CDC_Transmit_FS((uint8_t *)buffer, strlen(buffer));
}
