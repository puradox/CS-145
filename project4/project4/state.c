/*
 * state.c
 *
 * Created: 5/28/2018 3:22:50 PM
 *  Author: David
 */ 

#include "state.h"

struct state make_state(state_fn* measure_start)
{
	struct state s = {
		measure_start,
		50 // this will be replaced by an initial measurement
	};
	return s;
}

void measuring(struct state *s)
{
	s->measured_voltage += 1;
	//s->measured_voltage = ADC;
}

void not_measuring(struct state *s)
{
	
}