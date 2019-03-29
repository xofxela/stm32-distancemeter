/* Includes ------------------------------------------------------------------*/
#include "callback.h"

void __HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	beep = 0x01;
/*TODO*/
//	__HAL_RCC_TIM1_CLK_ENABLE();	//LGTM	__HAL_RCC_TIM1_CLK_DISABLE();
	HAL_TIM_OC_MspInit(htim);			//LGTM	HAL_TIM_OC_MspDeInit(htim);		also why there is OC ???
//	__HAL_TIM_ENABLE(htim);			//LGTM	__HAL_TIM_DISABLE(htim);
	HAL_TIM_Base_Start(htim);			//LGTM	HAL_TIM_Base_Stop(htim);
}

void __HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(beep != 0x00)
	{
		beep = 0x00;
		HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, MOTOR_Pin | BUZZER_Pin, GPIO_PIN_SET);
	}
	else
	{
		beep = 0x01;
		if (count > 20)
		{
			HAL_GPIO_WritePin(GPIOA, MOTOR_Pin | BUZZER_Pin, GPIO_PIN_RESET);
		}
	};
	count++;
	count_halt++;
	if (count > MAX_REPEAT)
	{
		count = 0;
		HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, MOTOR_Pin | BUZZER_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SET_COUNTER(&htim2, TIM2_COUNT);
	}
	if((__HAL_TIM_GET_COUNTER(&htim2)) > __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_3))
	if((__HAL_TIM_GET_COUNTER(&htim2)) < __HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_4))
	{
		beep = 0x00;
		HAL_GPIO_WritePin(GPIOB, LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, MOTOR_Pin | BUZZER_Pin, GPIO_PIN_RESET);
		count = 0;
	};
}
