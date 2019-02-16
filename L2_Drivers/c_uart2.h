#ifndef C_UART2_H_
#define C_UART2_H_
#include "uart2.hpp"

#ifdef __cplusplus
extern "C"{
#endif

bool init(unsigned int baudRate, int rxQSize, int txQSize);
bool getChar(char* pInputChar, unsigned int timeout);
bool putChar(char out, unsigned int timeout);

#ifdef __cplusplus
}
#endif

#endif /* C_UART2_H_ */
