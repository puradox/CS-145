#include "state.h"

struct state make_state(state_fn *start)
{
    struct state s = {
        .next = start,
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
    };
    return s;
}
