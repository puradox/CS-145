#include "state.h"
#include "display.h"
#include "game.h"
#include "jump.h"

struct state make_state()
{
	struct state s = {
		.next_display = display_start,
        .next_game = game_menu,
		.next_jump = jump_start,

        .row1 = "                ",
        .row2 = "P               ",

		.ticks_since_last_block = 4, // display is last
		.gg = false,
		.ticks_played = 0
	};
	return s;
}
