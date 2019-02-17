#include <stdint.h>
#include "io.hpp"
#include "periodic_callback.h"
#include "GPIO.hpp"
#include "eint.h"
#include "semphr.h"
#include "stdio.h"
#include "printf_lib.h"
#include "uart2.hpp"
#include "uart3.hpp"

#define SENDER 0
#define RECEIVER 1

Uart2 &sender = Uart2::getInstance();
Uart3 &receiver = Uart3::getInstance();
Light_Sensor &light = Light_Sensor::getInstance();
LED_Display &seven_segment = LED_Display::getInstance();

const uint32_t PERIOD_TASKS_STACK_SIZE_BYTES = (512 * 4);
const uint32_t PERIOD_MONITOR_TASK_STACK_SIZE_BYTES = (512 * 3);

bool period_init(void){
#if SENDER
    sender.init(38400, 10, 10);
#endif
#if RECEIVER
    receiver.init(38400, 10, 10);
    seven_segment.init();
#endif
    return true;
}

bool period_reg_tlm(void){
    return true;
}

void period_1Hz(uint32_t count){
}

void period_10Hz(uint32_t count){
#if SENDER
    char light_value = (char)light.getPercentValue();
    bool tx_check = sender.putChar(light_value, 0);
    if (!tx_check)
        u0_dbg_printf("Error in TX");
#endif

#if RECEIVER
    char receive = {'\0'};
    bool rx_check = receiver.getChar(&receive, 0);
    if(!rx_check){
        u0_dbg_printf("Did not receive any data\n");
    }
    else{
        seven_segment.setNumber(receive);
        u0_dbg_printf("RX:%d\n", (int)receive);
    }
#endif
}

void period_100Hz(uint32_t count){
}

void period_1000Hz(uint32_t count){
}
