#include "state.h"
#include "menu.h"

struct state make_state()
{
    struct state s = {
        .next_song = song_start,
        .next_volume = volume_start,
        .next_tempo = tempo_start,
        .next_player = state_fn_todo,

        // Music player
        .tempo = 128,
        .volume = 128,
        .song = 0,
        .song_len = 0,
        .song_title = "catch me outside",

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
