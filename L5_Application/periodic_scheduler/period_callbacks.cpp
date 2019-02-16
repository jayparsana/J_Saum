#include <stdint.h>
#include "io.hpp"
#include "periodic_callback.h"
#include "GPIO.hpp"
#include "eint.h"
#include "semphr.h"
#include "stdio.h"
#include "printf_lib.h"
#include "c_uart2.h"
#include "c_uart3.h"

#define JAY 0
#define SEMIL 1

Uart2 &sender = Uart2::getInstance();
Uart3 &receiver = Uart3::getInstance();
Light_Sensor &light = Light_Sensor::getInstance();
LED_Display &seven_segment = LED_Display::getInstance();

const uint32_t PERIOD_TASKS_STACK_SIZE_BYTES = (512 * 4);
const uint32_t PERIOD_MONITOR_TASK_STACK_SIZE_BYTES = (512 * 3);

bool period_init(void){
#if JAY
    sender.init(38400, 10, 10);
#endif
#if SEMIL
    receiver.init(38400, 10, 10);
#endif
    return true;
}

bool period_reg_tlm(void){
    return true;
}

void period_1Hz(uint32_t count){
}

void period_10Hz(uint32_t count){
#if JAY
//    uint8_t light_value = light.getPercentValue();
//    uint8_t units = light_value % 10;
//    uint8_t tens = light_value / 10;
//    char val[2];
//    val[0]= (char)units;
//    val[1] = (char)tens;
//    u0_dbg_printf("txx: %d\t%d\n", val[1],val[0]);
    char jay = 'J';
    bool check = sender.putChar(jay, 0);
    if(!check)
        u0_dbg_printf("Error in transmitting to semil");
#endif

#if SEMIL
    char receive = {'\0'};
    bool rx_check = receiver.getChar(&receive, 0);
    if(!rx_check)
        u0_dbg_printf("ThanthanGopal\n");
    else{
        u0_dbg_printf("chk: %c\t%c\n", receive);
//        int a[2];
//        a[0] = (int)receive;
//        a[1] = (int)receive;
//        u0_dbg_printf("RX:%d%d\n", a[1], a[0]);
    }
#endif
}

void period_100Hz(uint32_t count){
}

void period_1000Hz(uint32_t count){
}
