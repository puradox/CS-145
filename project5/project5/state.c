#include "state.h"


struct state make_state()
{
	struct state s = {
		.key_A = false,
		.row1 = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		.row2 = {'P', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		.ticks_since_last_block = 0
	};
	return s;
}

