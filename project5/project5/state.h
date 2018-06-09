#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include <stdint.h>

struct state;
typedef void state_fn(struct state *);

struct state
{

    bool key_A;
	
    char row1[16];
	char row2[16];
	int row_size;
	
	int ticks_since_last_block;
	
};

struct state make_state();

#endif
