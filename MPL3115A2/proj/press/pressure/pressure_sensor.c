#include "pressure_sensor.h"
#include "i2c.h"
#include "string.h"
#define PRESS_CHIP_ADDR 0xC0
#define PRESS_CONTROL_REG1 0x26
#define PRESS_STATE_REG 0x00


uint8_t i2c_dma_ready=0;
void pressure_config(){

    uint8_t buff[1]={0x04};
    //Reset
    I2C_Write(PRESS_CHIP_ADDR,PRESS_CONTROL_REG1, 1,1,buff);
    int j;
    for (j=0; j<100000;j++);
    buff[0]=0x31; //0x39 for 512ms
    //Set sample time 256ms and set active
    I2C_Write(PRESS_CHIP_ADDR,PRESS_CONTROL_REG1, 1,1,buff);
    //while(!Get_Pressure());
}

uint32_t get_pressure(){
    uint8_t buff[3];
    uint8_t frac;
    uint32_t pressure,  intg;

    I2C_DMA_Read(PRESS_CHIP_ADDR);
    while(i2c_dma_ready==0);
    i2c_dma_ready=0;
    memcpy(buff, I2C_Rx_Buffer, 3);
    float press = (float)((buff[0]<<16 | buff[1]<<8 | buff[2])>>4);
    press/=4;

    intg = (uint32_t)(press/100);
    frac = (uint8_t)((press - (float)intg*100)/1);

    pressure = intg<<8 | frac;

    return pressure;
}

