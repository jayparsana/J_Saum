/*
 * c_period_callbacks.h
 *
 *  Created on: Feb 16, 2019
 *      Author: SaumPC
 */

#ifndef C_PERIOD_CALLBACKS_H_
#define C_PERIOD_CALLBACKS_H_

#ifdef __cplusplus
extern "C" {
#endif

bool c_period_init(void);
bool c_period_reg_tlm(void);

void c_period_1Hz(uint32_t count);
void c_period_10Hz(uint32_t count);
void c_period_100Hz(uint32_t count);
void c_period_1000Hz(uint32_t count);

#ifdef __cplusplus
}
#endif

#endif /* C_PERIOD_CALLBACKS_H_ */
