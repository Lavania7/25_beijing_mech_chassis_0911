#ifndef __MECH_WHEEL_H
#define __MECH_WHEEL_H

typedef struct __wheel_dataTypeDef
{
    float vx;
    float vy;
    float omega;
    
    float exp_spd[4];

}wheel_dataTypeDef;


extern wheel_dataTypeDef wheel_data;

void mech_wheel_init(void);
void mech_wheel_exe(void);
void mech_wheel_exp_cal(wheel_dataTypeDef* wdata);

#endif
