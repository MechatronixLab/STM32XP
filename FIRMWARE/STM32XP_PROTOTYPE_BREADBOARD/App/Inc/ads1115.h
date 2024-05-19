/*
 * ads1115.h
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

// Device datasheet:
// https://www.ti.com/lit/ds/symlink/ads1115.pdf

#ifndef INC_ADS1115_H_
#define INC_ADS1115_H_

#include "main.h"
#include "i2c.h"

#define ADS_I2C_HANDLE			hi2c1	// Change here if using other I2C
#define ADS_DEVICE_ADDRESS		0x90	// (0x48 << 1)
#define ADS_I2C_TIMEOUT			5

#define ADS_REGISTER_CONVERSION	0x00
#define ADS_REGISTER_CONFIG		0x01
#define ADS_REGISTER_LO_THRESH	0x02
#define ADS_REGISTER_HI_THRESH	0x03

#define ADS_OS					0x8000	// Default set

#define ADS_MUX_AIN0_AIN1		0x0000	// Default
#define ADS_MUX_AIN0_AIN3		0x1000
#define ADS_MUX_AIN1_AIN3		0x2000
#define ADS_MUX_AIN2_AIN3		0x3000
#define ADS_MUX_AIN0_GND		0x4000
#define ADS_MUX_AIN1_GND		0x5000
#define ADS_MUX_AIN2_GND		0x6000
#define ADS_MUX_AIN3_GND		0x7000

#define ADS_PGA_6144			0x0000
#define ADS_PGA_4096			0x0200
#define ADS_PGA_2048			0x0400	// Default
#define ADS_PGA_1024			0x0600
#define ADS_PGA_0512			0x0800
#define ADS_PGA_0256			0x0E00

#define ADS_MODE_CONTINUOUS		0x0000
#define ADS_MODE_SINGLE_SHOT	0x0100	// Default

#define ADS_DATA_RATE_008SPS	0x0000
#define ADS_DATA_RATE_016SPS	0x0020
#define ADS_DATA_RATE_032SPS	0x0040
#define ADS_DATA_RATE_064SPS	0x0060
#define ADS_DATA_RATE_128SPS	0x0080	// Default
#define ADS_DATA_RATE_250SPS	0x00A0
#define ADS_DATA_RATE_475SPS	0x00C0
#define ADS_DATA_RATE_860SPS	0x00E0

#define ADS_COMP_MODE_DEFAULT	0x0000	// Default
#define ADS_COMP_MODE_WINDOW	0x0010

#define ADS_COMP_POL_LO			0x0000	// Default
#define ADS_COMP_POL_HI			0x0008

#define ADS_COMP_LATCH_DISABLE	0x0000	// Default
#define ADS_COMP_LATCH_ENABLE	0x0004

#define ADS_COMP_QUEUE_1		0x0000
#define ADS_COMP_QUEUE_2		0x0001
#define ADS_COMP_QUEUE_4		0x0002
#define ADS_COMP_QUEUE_DISABLE	0x0003	// Default

void ADS_Test(void);

void ADS_Init(void);

void ADS_Read (uint8_t register_address, uint8_t * I2C_buffer);
void ADS_Write(uint8_t register_address, uint16_t data);

uint16_t ADS_GetRegister(uint8_t register_address);
 int16_t ADS_GetConversion(void);

#endif /* INC_ADS1115_H_ */
