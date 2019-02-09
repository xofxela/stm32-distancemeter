#ifndef __CALLBACK_H
#define __CALLBACK_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
	 
/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* External variables --------------------------------------------------------*/
extern uint16_t 					count, count_halt;
uint8_t 									beep = 0x00;
extern TIM_HandleTypeDef 	htim1;
extern TIM_HandleTypeDef 	htim2;

#define MAX_REPEAT	5000
#define TIM2_COUNT              (0x3FF5)
	 
void __HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void __HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
	 
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CALLBACK_H */
