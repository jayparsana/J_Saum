/*
 * c_period_callbacks.cpp
 *
 *  Created on: Feb 16, 2019
 *      Author: SaumPC
 */

#include "periodic_callback.h"
#include "c_period_callbacks.h"
#include <stdint.h>

bool c_period_init(void)
{
	period_init();
	return true;
}

bool c_period_reg_tlm(void)
{
	period_reg_tlm();
	return true;
}

void c_period_1Hz(uint32_t count)
{
	 period_1Hz(count);
}
void c_period_10Hz(uint32_t count)
{
	period_10Hz(count);
}
void c_period_100Hz(uint32_t count)
{
	period_100Hz(count);
}
void c_period_1000Hz(uint32_t count)
{
	period_1000Hz(count);
}


