#include "state.h"


struct state make_state(state_fn jump_start)
{
	struct state s = {
		.jump = jump_start,
		.player_in_bottom = true,
		.row1 = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		.row2 = {'P', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		.ticks_since_last_block = 4, // display is last
		.gg = false
	};
	return s;
}

