#include "c_uart3.h"

bool init(unsigned int baudRate, int rxQSize, int txQSize){
    Uart3::getInstance().init(baudRate, rxQSize=32, txQSize=64);
}
bool getChar(char* pInputChar, unsigned int timeout){
    Uart3::getInstance().getChar(pInputChar, timeout);
}
bool putChar(char out, unsigned int timeout){
    Uart3::getInstance().putChar(out, timeout);
}
