#include "c_uart2.h"

bool init(unsigned int baudRate, int rxQSize, int txQSize){
    Uart2::getInstance().init(baudRate, rxQSize=32, txQSize=64);
}
bool getChar(char* pInputChar, unsigned int timeout){
    Uart2::getInstance().getChar(pInputChar, timeout);
}
bool putChar(char out, unsigned int timeout){
    Uart2::getInstance().putChar(out, timeout);
}
