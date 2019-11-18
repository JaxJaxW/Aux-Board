
#include "PinConfigs.h"
#include "main.h"


UART_HandleTypeDef huart2;
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
	HAL_Init(); // Initialization - Keep it
	SystemClock_Config();  // How fast the processor is going - Keep it

	MX_GPIO_Init(); // Custom Initialization - Initialize the port pins

	uint16_t ms = 1000;
	//uint8_t togglePin = 0;

	 while (1)
	 {
	      /*HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	      HAL_Delay(500);*/
/*
	      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
	      HAL_Delay(500);
	      HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0);
	      HAL_Delay(750);
	      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
	      HAL_Delay(ms);
*/
		 /*
	      // Port A - Eco_in, Horn_in, CLED_out
	      if(HAL_GPIO_ReadPin(GPIOA, Eco_in))
		  {
			  HAL_GPIO_WritePin(GPIOA, Eco_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOA, Eco_in, GPIO_PIN_RESET);
		  }

	      if(HAL_GPIO_ReadPin(GPIOA, Horn_in))
		  {
			  HAL_GPIO_WritePin(GPIOA, Horn_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOA, Horn_in, GPIO_PIN_RESET);
		  }

	      if(HAL_GPIO_ReadPin(GPIOA, CLED_out))
		  {
			  HAL_GPIO_TogglePin(GPIOA, CLED_out);
		  }

	      // Port B - LT_in, RT_in, Cruise_in, Cplus_in, Cminus_in

	      if(HAL_GPIO_ReadPin(GPIOB, LT_in))
		  {
			  HAL_GPIO_WritePin(GPIOB, LT_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOB, LT_in, GPIO_PIN_RESET);
		  }

	      if(HAL_GPIO_ReadPin(GPIOB, RT_in))
		  {
			  HAL_GPIO_WritePin(GPIOB, RT_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOB, RT_in, GPIO_PIN_RESET);
		  }

	      if(HAL_GPIO_ReadPin(GPIOB, Cruise_in))
		  {
			  HAL_GPIO_TogglePin(GPIOB, Cruise_in);
		  }

	      if(HAL_GPIO_ReadPin(GPIOB, Cplus_in))
		  {
			  HAL_GPIO_TogglePin(GPIOB, Cplus_in);
		  }

	      if(HAL_GPIO_ReadPin(GPIOB, Cminus_in))
		  {
			  HAL_GPIO_TogglePin(GPIOB, Cminus_in);
		  }

	      // Port C - Regen_in, Headlights_in, Reverse_in
	      if(HAL_GPIO_ReadPin(GPIOC, Regen_in))
	      {
	    	  HAL_GPIO_WritePin(GPIOC, Regen_in, GPIO_PIN_SET);
	      }
	      else
	      {
	    	  HAL_GPIO_WritePin(GPIOC, Regen_in, GPIO_PIN_RESET);
	      }

	      if(HAL_GPIO_ReadPin(GPIOC, Headlights_in))
	      {
	      	  HAL_GPIO_WritePin(GPIOC, Headlights_in, GPIO_PIN_SET);
	      }
	      else
	      {
	    	  HAL_GPIO_WritePin(GPIOC, Headlights_in, GPIO_PIN_RESET);
	      }

		  if(HAL_GPIO_ReadPin(GPIOC, Reverse_in))
		  {
			  HAL_GPIO_WritePin(GPIOC, Reverse_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOC, Reverse_in, GPIO_PIN_RESET);
		  }

		  // Port D - Hazards_in

		  if(HAL_GPIO_ReadPin(GPIOD, Hazards_in))
		  {
			  HAL_GPIO_WritePin(GPIOD, Hazards_in, GPIO_PIN_SET);
		  }
		  else
		  {
			  HAL_GPIO_WritePin(GPIOD, Hazards_in, GPIO_PIN_RESET);
		  }*/

		  // Button on MicroP
		  if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
		  {
			  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			  //HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		  }
		  /*else
		  {
			  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		  }*/



	      /*if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0))
	      {
	    	  HAL_GPIO_WritePin(GPIOC, Horn_in, GPIO_PIN_SET);
	      }
	      else
	      {
	    	  HAL_GPIO_WritePin(GPIOC, Horn_in, GPIO_PIN_RESET);
	      }*/
	 }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{


	GPIO_InitTypeDef GPIO_InitStruct = {0};

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOF_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();

	  //************************************************** - Change As Needed

	  /*Configure GPIO pin Output Level */

	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET); // Reset means 0, set means 1
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);

	  /*Configure GPIO pin : PC1 */     //Port C Pin 1

	    GPIO_InitStruct.Pin = GPIO_PIN_1;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  // Configure GPIO pin : PA3 Port A pin 3
	    GPIO_InitStruct.Pin = GPIO_PIN_2;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	    //Configure GPIO pin : PB3 Port B Pin 3
	    GPIO_InitStruct.Pin = GPIO_PIN_3;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	    //Configure GPIO pin : PC1 Port C Pin 0
	    GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	    //Configure GPIO pin : LD2_Pin  //LED 2

	    GPIO_InitStruct.Pin = LD2_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

	   //Configure GPIO button : PC13 Port C Pin 13
	   GPIO_InitStruct.Pin = GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}


void Error_Handler(void)
{
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
