#include "hall.h"
#include "tim.h"



//定时中断
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
//	printf("tim\r\n");
}

uint8_t state = 0;
uint16_t pwm_pulse=800;
//换相中断
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim)
{
	state = get_hall_state();
	printf("%d\r\n",state);
	switch(state)
	{
		case 1:    /* U+ W- */

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,pwm_pulse);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_RESET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_RESET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_SET);//W-
//			printf("%d\r\n",pwm_pulse);
			break;
		
		case 2:     /* V+ U- */

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,0);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,pwm_pulse);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_SET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_RESET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_RESET);//W-
			break;
		
		case 3:    /* V+ W- */

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,0);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,pwm_pulse);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_RESET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_RESET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_SET);//W-
			break;

		case 4:     /* W+ V- */

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,0);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,pwm_pulse);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_RESET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_SET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_RESET);//W-
			break;

		case 5:     /* U+  V -*/

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,pwm_pulse);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,0);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_RESET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_SET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_RESET);//W-
			break;
		
		case 6:     /* W+ U- */

			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,0);	//U+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,0);	//V+
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,pwm_pulse);	//W+
			HAL_GPIO_WritePin(PWMUL_GPIO_Port,PWMUL_Pin,GPIO_PIN_SET);//U-	//GPIO_PIN_SET   GPIO_PIN_RESET
			HAL_GPIO_WritePin(PWMVL_GPIO_Port,PWMVL_Pin,GPIO_PIN_RESET);//V-
			HAL_GPIO_WritePin(PWMWL_GPIO_Port,PWMWL_Pin,GPIO_PIN_RESET);//W-
			break;

	}
}

//获取霍尔传感器值
uint8_t get_hall_state(void)
{
  uint8_t state = 0;
  
#if 1
  /* 读取霍尔传感器 U 的状态 */
  if(HAL_GPIO_ReadPin(hallu_GPIO_Port, hallu_Pin) != GPIO_PIN_RESET)
  {
    state|= 0x01U << 0;
//		printf("u1\r\n");
  }
  
  /* 读取霍尔传感器 V 的状态 */
  if(HAL_GPIO_ReadPin(hallv_GPIO_Port, hallv_Pin) != GPIO_PIN_RESET)
  {
    state |= 0x01U << 1;
//		printf("v1\r\n");
  }
  
  /* 读取霍尔传感器 W 的状态 */
  if(HAL_GPIO_ReadPin(hallw_GPIO_Port, hallw_Pin) != GPIO_PIN_RESET)
  {
    state |= 0x01U << 2;
//		printf("w1\r\n");
  }
#else
  state = (GPIOH->IDR >> 10) & 7;    // 读 3 个霍尔传感器的状态
#endif
	//printf("stateL:%d\n",state);
  return state;    // 返回传感器状态
}