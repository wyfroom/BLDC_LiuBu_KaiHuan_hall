/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define hallu_Pin GPIO_PIN_6
#define hallu_GPIO_Port GPIOA
#define hallv_Pin GPIO_PIN_7
#define hallv_GPIO_Port GPIOA
#define hallw_Pin GPIO_PIN_0
#define hallw_GPIO_Port GPIOB
#define PWMWL_Pin GPIO_PIN_13
#define PWMWL_GPIO_Port GPIOB
#define PWMVL_Pin GPIO_PIN_14
#define PWMVL_GPIO_Port GPIOB
#define PWMUL_Pin GPIO_PIN_15
#define PWMUL_GPIO_Port GPIOB
#define PWMW_Pin GPIO_PIN_8
#define PWMW_GPIO_Port GPIOA
#define PWMV_Pin GPIO_PIN_9
#define PWMV_GPIO_Port GPIOA
#define PWMU_Pin GPIO_PIN_10
#define PWMU_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
