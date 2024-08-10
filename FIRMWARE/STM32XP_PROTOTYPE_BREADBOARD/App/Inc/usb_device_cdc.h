/*
 * usb_device_cdc.h
 *
 *  Created on: Aug 10, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_USB_DEVICE_CDC_H_
#define INC_USB_DEVICE_CDC_H_

#include "main.h"
#include "usb_device.h"

#include "usbd_cdc_if.h"

#include <string.h>
#include <stdarg.h>

void USB_CDCI_Write(char * buffer);
void USB_CDC_NewLine(void);

void USB_CDC_Print(const char *fmt, ...);	// Equivalent to printf(), but prints to serial port

#endif /* INC_USB_DEVICE_CDC_H_ */
