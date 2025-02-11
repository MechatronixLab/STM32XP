/*
 * sdcard.h
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

// Based on this tutorial: https://01001000.xyz/2020-08-09-Tutorial-STM32CubeIDE-SD-card/

#ifndef INC_SDCARD_H_
#define INC_SDCARD_H_

#include "main.h"
#include "spi.h"

#include "cli.h"

#include "user_diskio_spi.h"

#define SD_SPI_HANDLE hspi2

void SDCARD_Test(void);

#endif /* INC_SDCARD_H_ */
