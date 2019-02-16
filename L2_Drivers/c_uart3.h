#ifndef C_UART3_H_
#define C_UART3_H_
#include "uart3.hpp"

#ifdef __uart3wrap
extern "C"{
#endif

bool init(unsigned int baudRate, int rxQSize, int txQSize);
bool getChar(char* pInputChar, unsigned int timeout);
bool putChar(char out, unsigned int timeout);

#ifdef __uart3wrap
}
#endif

#endif /* C_UART3_H_ */
