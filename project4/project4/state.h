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

struct state
{	
	state_fn* measure;
	unsigned short measured_voltage;
};

//
// Functions
//

struct state make_state();

void measuring(struct state *);
void not_measuring(struct state *);




#endif