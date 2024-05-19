/*
 * sdcard.h
 *
 *  Created on: May 18, 2024
 *      Author: Eng. André A. M. Araújo
 */

#ifndef INC_SDCARD_H_
#define INC_SDCARD_H_

#include "main.h"
#include "spi.h"

#include "cli.h"

#include "user_diskio_spi.h"

#define SD_SPI_HANDLE hspi2

void SDCARD_Test(void);

#endif /* INC_SDCARD_H_ */
