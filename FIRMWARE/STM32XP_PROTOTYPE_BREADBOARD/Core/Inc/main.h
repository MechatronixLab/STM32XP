/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_USER_Pin GPIO_PIN_13
#define BUTTON_USER_GPIO_Port GPIOC
#define BUTTON_USER_EXTI_IRQn EXTI15_10_IRQn
#define LED_USER_Pin GPIO_PIN_5
#define LED_USER_GPIO_Port GPIOA
#define ST7789_DC_Pin GPIO_PIN_6
#define ST7789_DC_GPIO_Port GPIOA
#define ST7789_RST_Pin GPIO_PIN_7
#define ST7789_RST_GPIO_Port GPIOA
#define BUTTON_LEFT_Pin GPIO_PIN_4
#define BUTTON_LEFT_GPIO_Port GPIOC
#define BUTTON_LEFT_EXTI_IRQn EXTI4_IRQn
#define BUTTON_RIGHT_Pin GPIO_PIN_5
#define BUTTON_RIGHT_GPIO_Port GPIOC
#define BUTTON_RIGHT_EXTI_IRQn EXTI9_5_IRQn
#define BUTTON_UP_Pin GPIO_PIN_0
#define BUTTON_UP_GPIO_Port GPIOB
#define BUTTON_UP_EXTI_IRQn EXTI0_IRQn
#define BUTTON_DOWN_Pin GPIO_PIN_1
#define BUTTON_DOWN_GPIO_Port GPIOB
#define BUTTON_DOWN_EXTI_IRQn EXTI1_IRQn
#define BUTTON_CENTER_Pin GPIO_PIN_2
#define BUTTON_CENTER_GPIO_Port GPIOB
#define BUTTON_CENTER_EXTI_IRQn EXTI2_IRQn
#define SD_CS_Pin GPIO_PIN_12
#define SD_CS_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_8
#define BUTTON_2_GPIO_Port GPIOA
#define BUTTON_2_EXTI_IRQn EXTI9_5_IRQn
#define BUTTON_1_Pin GPIO_PIN_9
#define BUTTON_1_GPIO_Port GPIOA
#define BUTTON_1_EXTI_IRQn EXTI9_5_IRQn
#define ST7789_CS_Pin GPIO_PIN_10
#define ST7789_CS_GPIO_Port GPIOA
#define SD_NIN_Pin GPIO_PIN_10
#define SD_NIN_GPIO_Port GPIOC
#define OLED_RST_Pin GPIO_PIN_5
#define OLED_RST_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
