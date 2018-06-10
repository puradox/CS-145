#include "state.h"
#include "screen.h"
#include "game.h"
#include "jump.h"
#include "player.h"
#include "song_list.h"

struct state make_state()
{
	struct state s = {
		.next_screen = screen_start,
        .next_game = game_start,
		.next_jump = jump_ready,
		.next_player = player_start,

        .jump_counter = 0,

		.song = song_none,
		.note_index = 0,
		.duration_curr = 0,
	};
	return s;
}
