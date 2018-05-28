/*
 * state.c
 *
 * Created: 5/28/2018 3:22:50 PM
 *  Author: David
 */ 

#include "state.h"

struct state make_state()
{
	struct state s = {
		.measured_voltage = 500 // this will be replaced by an initial measurement
	};
	return s;
}