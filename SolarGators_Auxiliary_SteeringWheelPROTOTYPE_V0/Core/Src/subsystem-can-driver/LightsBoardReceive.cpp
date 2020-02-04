#include "LightsBoardReceive.hpp"

LightsBoardReceive::LightsBoardReceive()
{
	aux0.SetupReceive(ReceiveAndSend);

	auxPacket.hazardsOn = false;
	auxPacket.headlightsOn = false;
	auxPacket.leftOn = false;
	auxPacket.rightOn = false;
}

void LightsBoardReceive::ReceiveAndSend(SUBSYSTEM_DATA_MODULE*)
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
		HAL_GPIO_WritePIn(RT_out_GPIO_Port, RT_out_Pin, GPIO_PIN_RESET);
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


