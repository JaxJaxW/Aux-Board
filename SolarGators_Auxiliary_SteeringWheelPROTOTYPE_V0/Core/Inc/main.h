/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f0xx_hal.h"

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
#define Dev_Btn_Pin GPIO_PIN_13
#define Dev_Btn_GPIO_Port GPIOC
#define Dev_Btn_EXTI_IRQn EXTI4_15_IRQn
#define Cruise_LED_Pin GPIO_PIN_0
#define Cruise_LED_GPIO_Port GPIOA
#define Eco_in_Pin GPIO_PIN_1
#define Eco_in_GPIO_Port GPIOA
#define Dev_LED_Pin GPIO_PIN_5
#define Dev_LED_GPIO_Port GPIOA
#define LED_out_Pin GPIO_PIN_12
#define LED_out_GPIO_Port GPIOC
#define LT_in_Pin GPIO_PIN_3
#define LT_in_GPIO_Port GPIOB
#define Cruise_in_Pin GPIO_PIN_4
#define Cruise_in_GPIO_Port GPIOB
#define Cruise_in_EXTI_IRQn EXTI4_15_IRQn
#define CPlus_in_Pin GPIO_PIN_5
#define CPlus_in_GPIO_Port GPIOB
#define CPlus_in_EXTI_IRQn EXTI4_15_IRQn
#define Hazards_in_Pin GPIO_PIN_6
#define Hazards_in_GPIO_Port GPIOB
#define Hazards_in_EXTI_IRQn EXTI4_15_IRQn
#define Regen_in_Pin GPIO_PIN_7
#define Regen_in_GPIO_Port GPIOB
#define Regen_in_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */
#define Headlights_out_GPIO_Port GPIOB
#define Headlights_out_Pin GPIO_PIN_5
#define Reverse_out_GPIO_Port GPIOB
#define Reverse_out_Pin GPIO_PIN_3
#define RT_out_GPIO_Port GPIOC
#define RT_out_Pin GPIO_PIN_11
#define LT_out_GPIO_Port GPIOC
#define LT_out_Pin GPIO_PIN_10
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
