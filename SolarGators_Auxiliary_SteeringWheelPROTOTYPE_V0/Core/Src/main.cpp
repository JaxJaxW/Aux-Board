/* USER CODE BEGIN Header */

/**

  ******************************************************************************

  * @file           : main.c

  * @brief          : Main program body

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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "aux-data-module.hpp"
#include "subsystem-data-module.hpp"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

//Lights Board Variables
AUX_MESSAGE_0_DATA_PACKET auxPacket;
AUX_MESSAGE_0 aux0;
bool receivedSomething;
TIM_HandleTypeDef htim6;


/* USER CODE BEGIN PV */
CAN_HandleTypeDef hcan = {0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void ReceiveAndSend(SUBSYSTEM_DATA_MODULE*);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */

volatile bool state = true;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//For timer interrupt
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)

{
	if(auxPacket.hazardsOn == true)
	{
		HAL_GPIO_TogglePin(LT_out_GPIO_Port, LT_out_Pin);
		HAL_GPIO_TogglePin(RT_out_GPIO_Port, RT_out_Pin);
	}
	else if (auxPacket.leftOn == true)
	{
		HAL_GPIO_TogglePin(LT_out_GPIO_Port, LT_out_Pin);
	}
	else if (auxPacket.rightOn == true)
	{
		HAL_GPIO_TogglePin(RT_out_GPIO_Port, RT_out_Pin);
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	aux0.SetupReceive(ReceiveAndSend);
	bool receivedSomething;
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
  SUBSYSTEM_DATA_MODULE::StartCAN(&hcan);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)

  {

    /* USER CODE END WHILE */
	  	auxPacket = aux0.GetOldestDataPacket(&receivedSomething);
	  	if(receivedSomething)
	  	{
	  		if (auxPacket.hazardsOn)
	  		{
	  			//Turn on Interrupt
	  			HAL_TIM_Base_Start_IT(&htim6);
	  			//The interrupt is going to toggle the hazards
	  		}
	  		else
	  		{
	  			//Turn off the Interrupt
	  			HAL_TIM_Base_Stop_IT(&htim6);
	  			//Turn off left and right
	  			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_RESET);
	  			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_RESET);
	  		}
	  		if (auxPacket.headlightsOn)
	  		{
	  			HAL_GPIO_WritePin(Headlights_out_GPIO_Port, Headlights_out_Pin, GPIO_PIN_SET);
	  		}
	  		else
	  		{
	  			HAL_GPIO_WritePin(Headlights_out_GPIO_Port, Headlights_out_Pin, GPIO_PIN_RESET);
	  		}
	  		if (auxPacket.leftOn)
	  		{
	  			HAL_TIM_Base_Start_IT(&htim6);
	  			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_SET);
	  		}
	  		else
	  		{
	  			HAL_TIM_Base_Stop_IT(&htim6);
	  			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_RESET);
	  		}
	  		if (auxPacket.rightOn)
	  		{
	  			HAL_TIM_Base_Start_IT(&htim6);
	  			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_SET);
	  		}
	  		else
	  		{
	  			HAL_TIM_Base_Stop_IT(&htim6);
	  			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_RESET);
	  		}
	  	}
    /* USER CODE BEGIN 3 */

  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */


/* USER CODE BEGIN 4 */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */
//
  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */
//
  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 32000;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 750;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */
//
  /* USER CODE END TIM6_Init 2 */

}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Cruise_LED_GPIO_Port, Cruise_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Dev_LED_GPIO_Port, Dev_LED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_out_GPIO_Port, LED_out_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : Dev_Btn_Pin */
  GPIO_InitStruct.Pin = Dev_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Dev_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Cruise_LED_Pin */
  GPIO_InitStruct.Pin = Cruise_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(Cruise_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Eco_in_Pin */
  GPIO_InitStruct.Pin = Eco_in_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Eco_in_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Dev_LED_Pin */
  GPIO_InitStruct.Pin = Dev_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Dev_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_out_Pin */
  GPIO_InitStruct.Pin = LED_out_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_out_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LT_in_Pin Cruise_in_Pin CPlus_in_Pin Hazards_in_Pin
                           Regen_in_Pin */
  GPIO_InitStruct.Pin = LT_in_Pin|Cruise_in_Pin|CPlus_in_Pin|Hazards_in_Pin
                          |Regen_in_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

void ReceiveAndSend(SUBSYSTEM_DATA_MODULE*)
{
	auxPacket = aux0.GetOldestDataPacket(&receivedSomething);
	if(receivedSomething)
	{
		if (auxPacket.hazardsOn)
		{
			//Turn on Interrupt
			HAL_TIM_Base_Start_IT(&htim6);
			//The interrupt is going to toggle the hazards
		}
		else
		{
			//Turn off the Interrupt
			HAL_TIM_Base_Stop_IT(&htim6);
			//Turn off left and right
			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_RESET);
		}
		if (auxPacket.headlightsOn)
		{
			HAL_GPIO_WritePin(Headlights_out_GPIO_Port, Headlights_out_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(Headlights_out_GPIO_Port, Headlights_out_Pin, GPIO_PIN_RESET);
		}
		if (auxPacket.leftOn)
		{
			HAL_TIM_Base_Start_IT(&htim6);
			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_TIM_Base_Stop_IT(&htim6);
			HAL_GPIO_WritePin(LT_out_GPIO_Port, LT_out_Pin, GPIO_PIN_RESET);
		}
		if (auxPacket.rightOn)
		{
			HAL_TIM_Base_Start_IT(&htim6);
			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_TIM_Base_Stop_IT(&htim6);
			HAL_GPIO_WritePin(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_RESET);
		}
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */

  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */

  /* User can add his own implementation to report the file name and line number,

     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
