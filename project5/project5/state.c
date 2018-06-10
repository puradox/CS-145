#include "state.h"
#include "screen.h"
#include "game.h"
#include "jump.h"
#include "player.h"

struct state make_state()
{
	struct state s = {
		.next_screen = screen_start,
        .next_game = game_play,
		.next_jump = jump_ready,
		//.next_player = player_start,

        .row1 = "                ",
        .row2 = "P               ",

		.ticks_since_last_block = 4, // display is last
		.gg = false,
		.ticks_played = 0,

        .jump_counter = 0,
		
		.song_list = song_mario_theme,
		.note_index = 0,
		.duration_curr = 0,
	};
	return s;
}
