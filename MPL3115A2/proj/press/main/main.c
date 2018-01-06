#include "i2c.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_dma.h"
#include "string.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "pressure_sensor.h"
#include "misc.h"

int main(void)
{
    config_I2C();
    pressure_config();

    uint16_t pressure=0;
    while(1){

       pressure = get_pressure();
       //delay
       for(int i=0; i<100000;i++);
    }

}

