/**
 * @file mech_wheel.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/* includes */
#include "can.h"
#include "M3508.h"
#include "mech_wheel.h"
#include "mech_wheel_cal.h"
#include "dbus.h"

/* varibles */
wheel_dataTypeDef wheel_data = {0};

/* functions */

void mech_wheel_init(void)
{
    motor_ctrl_init(&M3508_Motor, DJI_M3508, &hcan2, LOW);
}

void mech_wheel_exe(void)
{
    mech_wheel_exp_cal(&wheel_data);
    speed_ctrl(&M3508_Motor, -wheel_data.exp_spd[3], -wheel_data.exp_spd[2], wheel_data.exp_spd[1], wheel_data.exp_spd[0], DJI_M3508);
}

void mech_wheel_exp_cal(wheel_dataTypeDef* wdata)
{
    float vx = 8.0f * wdata->vx;
    float vy = 8.0f * wdata->vy;
    float omega = 15.0f * wdata->omega;

    inverse_kinematics_cal(vx, vy, omega, wdata->exp_spd);

}

