/*
 * ads1115.c
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

#include "ads1115.h"

void ADS_Test(void)
{
	volatile uint16_t result = 0;

	result = ADS_GetRegister(ADS_REGISTER_CONVERSION);
	result = ADS_GetRegister(ADS_REGISTER_CONFIG);
	result = ADS_GetRegister(ADS_REGISTER_LO_THRESH);
	result = ADS_GetRegister(ADS_REGISTER_HI_THRESH);
}

void ADS_Init(void)
{
	ADS_Write(ADS_REGISTER_CONFIG, ADS_OS
			                     | ADS_MUX_AIN0_GND
								 | ADS_PGA_6144
								 | ADS_MODE_CONTINUOUS
			                     | ADS_DATA_RATE_008SPS
								 | ADS_COMP_MODE_DEFAULT
								 | ADS_COMP_POL_LO
								 | ADS_COMP_LATCH_DISABLE
								 | ADS_COMP_QUEUE_DISABLE);
}

void ADS_Read (uint8_t register_address, uint8_t * I2C_buffer)
{
	I2C_buffer[0] = register_address;

	HAL_I2C_Master_Transmit(&ADS_I2C_HANDLE, ADS_DEVICE_ADDRESS, I2C_buffer, 1, ADS_I2C_TIMEOUT);
	HAL_I2C_Master_Receive (&ADS_I2C_HANDLE, ADS_DEVICE_ADDRESS, I2C_buffer, 2, ADS_I2C_TIMEOUT);
}

void ADS_Write(uint8_t register_address, uint16_t data)
{
	uint8_t I2C_buffer[3];

	I2C_buffer[0] = register_address;
	I2C_buffer[1] = (data >> 8) & 0x00FF;
	I2C_buffer[2] =  data       & 0x00FF;


	HAL_I2C_Master_Transmit(&ADS_I2C_HANDLE, ADS_DEVICE_ADDRESS, I2C_buffer, 3, ADS_I2C_TIMEOUT);
}

uint16_t ADS_GetRegister(uint8_t register_address)
{
	uint8_t I2C_buffer[2];
	uint16_t register_value = 0;

	ADS_Read(register_address, I2C_buffer);

	register_value = (I2C_buffer[0] << 8) + I2C_buffer[1];

	return register_value;
}

 int16_t ADS_GetConversion(void)
{
	uint8_t I2C_buffer[2];
	int16_t conversion = 0;

	ADS_Read(ADS_REGISTER_CONVERSION, I2C_buffer);

	conversion = (I2C_buffer[0] << 8) + I2C_buffer[1];

	return conversion;
}
