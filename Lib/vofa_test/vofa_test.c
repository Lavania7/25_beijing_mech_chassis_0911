/**
 * @file vofa_test.c
 * @author Iris Howard (lavania7@foxmail.com)
 * @brief vofa+串口测试驱动
 *          
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/* includes */
#include "main.h"
#include "vofa_test.h"

uint8_t tail[4] = {0x00, 0x00, 0x80, 0x7f};
