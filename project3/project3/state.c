#include "state.h"
#include "menu.h"
#include "player.h"
#include "song_list.h"

struct state make_state()
{
    struct state s = {

        .next_song = song_start,
        .next_volume = volume_start,
        .next_tempo = tempo_start,
        .next_player = player_start,

        // Music player
        .tempo = 100,
        .volume = 5,

        .song_list = song_list,
        .song_list_len = sizeof(song_list) / sizeof(musical_song),

        .song_index = 0,
		.note_index = 0,
		.duration_max = 0,
		.duration_curr = 0,

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
