#include "state.h"
#include "menu.h"
#include "player.h"

struct state make_state()
{
    struct state s = {

        .next_song = song_start,
        .next_volume = volume_start,
        .next_tempo = tempo_start,
        .next_player = song_start,

        // Music player
        .tempo = 128,
        .volume = 128,
        .song = -1,
        .song_len = 0,
        .song_title = "catch me outside",
		
		.note_duration_played = 0,
		.note_index = 0,
		
		// 1 line ---> 4 beats
		.mario = SONG(EIGHTH_NOTE(MUSICAL_NOTE(E5, 8)), MUSICAL_NOTE(E5, 8)), MUSICAL_NOTE(E5, 8), MUSICAL_NOTE(REST, 8),
		MUSICAL_NOTE(G5, 4), MUSICAL_NOTE(REST, 4), MUSICAL_NOTE(G4, 4), MUSICAL_NOTE(REST, 4)),
		.mario_length = 8,

        // Menu
        .A = false,
        .B = false,
        .C = false,
        .D = false,

        .star = false,
        .pound = false,
    };
    return s;
}
