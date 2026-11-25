/**
 * @file bsp_tim.c
 * @author BNGU
 * @brief 
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */


/* includes */
#include "tim.h"
#include "bsp_tim.h"
#include "mech_wheel.h"

/* functions */

void bsp_tim_init(void)
{
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim4);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if      (htim->Instance == TIM2)
    {
        /* code */
    }
    else if (htim->Instance == TIM3)
    {
        mech_wheel_exe(); 
    }
    else if (htim->Instance == TIM4)
    {
        
        HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12);
    }
    
}
