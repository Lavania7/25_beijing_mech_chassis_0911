#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "main.h"
#include "can.h"

void interface_chassis_to_arm(void);
void interface_chassis_receive(CAN_RxHeaderTypeDef* rx_header, uint8_t* data);

#endif
