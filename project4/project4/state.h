/*
 * state.h
 *
 * Created: 5/28/2018 3:22:43 PM
 *  Author: David
 */ 


#ifndef STATE_H
#define STATE_H


struct state;
typedef void state_fn(struct state *);
// void state_fn_todo(struct state *s) {} ?

struct state
{	
	unsigned short measured_voltage;
};

//
// Functions
//

struct state make_state();


#endif