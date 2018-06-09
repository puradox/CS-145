#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include <stdint.h>

struct state;
typedef void state_fn(struct state *);

struct state
{
	state_fn* game_state;
	state_fn* jump;
	bool player_in_bottom;
	
    char row1[16];
	char row2[16];
	int ticks_since_last_block;
	bool gg;
};

struct state make_state();

#endif
