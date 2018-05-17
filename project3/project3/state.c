#include "state.h"
/*
void play(struct state* s)
{
	if (s->playing) // playing should be a state
	{
		if (s->time_note_played < note_duration)
		{
			play(s->current_note);
		}
		else
		{
			if (end_of_song())
			{
				state = done_with_song; // get outta here
			}
			else
			{
				s->index++;
				s->current_note = SONG[s->index];
			}
		}
	}
}
*/

void playing(struct state* s)
{
	play_freq(s->current_note.freq);
}

struct state make_state(state_fn *menu_start, state_fn *player_start)
{
    struct state s = {
        .menu_next = menu_start,
		.player_next = player_start,
        .running = true,

        // Music player
        .tempo = 128,
        .volume = 128,
        .song = 0,
        .song_len = 0,

        // Menu
        .A = false,
        .B = false,
        .C = false,
        .D = false,
		
		// testing stuff
		.current_note = WHOLE_NOTE(A4)
    };
    return s;
}
