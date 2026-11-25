/**
 * @file mech_wheel_cal.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/* includes */
#include "mech_wheel_cal.h"
#include "rm_motor.h"

/* defines */
#define center_to_wheel_x       0.15    // 底盘中心到轮子的x距离 
#define center_to_wheel_y       0.20    // 底盘中心到轮子的y距离 

/* varibles */


/* functions */

/**
 * @brief 
 * 
 * @param vx    底盘横向速度
 * @param vy    底盘纵向速度
 * @param omega 底盘旋转
 * @param exp_speed 目标电机速度，最大为4
 */
void inverse_kinematics_cal(float vx, float vy, float omega, float exp_speed[])
{
    static const float kin_matrix[4][3] = {     // 运动学逆解矩阵系数
        {1, -1, -(center_to_wheel_x + center_to_wheel_y)},  // 右前轮
        {1,  1,  - (center_to_wheel_x + center_to_wheel_y)},  // 左前轮
        {1, -1, ( (center_to_wheel_x + center_to_wheel_y))},  // 左后轮
        {1,  1, ( (center_to_wheel_x + center_to_wheel_y))}   // 右后轮
    };

    // 计算每个轮子的速度
    for(int i = 0; i < 4; i++) { exp_speed[i] =
(     kin_matrix[i][0] * (-vx) + 
      kin_matrix[i][1] * (-vy) + 
        kin_matrix[i][2] * omega);
    }

}
