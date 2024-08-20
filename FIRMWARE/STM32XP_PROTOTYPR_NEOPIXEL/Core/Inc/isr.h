/*
 * isr.h
 *
 *  Created on: Sep 17, 2023
 *      Author: André A. M. Araújo
 */

#ifndef INC_ISR_H_
#define INC_ISR_H_

#include "tim.h"

extern DMA_HandleTypeDef hdma_tim2_ch1;

extern volatile uint8_t flag_data_sent;

#endif /* INC_ISR_H_ */
