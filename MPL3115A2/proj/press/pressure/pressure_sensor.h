#ifndef __P_SENSOR_H
#define __P_SENSOR_H
#include "stdint.h"

void pressure_config();
uint32_t get_pressure();
extern uint8_t I2C_Rx_Buffer[8];
extern uint8_t pressure_sensor_state;
#endif
