#include "interface.h"
#include "can.h"
#include "main.h"
#include "mech_wheel.h"


void interface_chassis_to_arm(void)
{
    /* codes */
}

void interface_chassis_receive(CAN_RxHeaderTypeDef* rx_header, uint8_t* data)
{
	if (rx_header->StdId == 0x111)
	{
		wheel_data.vx = data[0] | (data[1] << 8);
		wheel_data.vy = data[2] | (data[3] << 8);
		wheel_data.omega = data[4] | (data[5] << 8);
		//HAL_IWDG_Refresh(&hiwdg);
	}
}