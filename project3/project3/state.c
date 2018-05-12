#include "state.h"

struct state make_state(state_fn *start)
{
    struct state s = {
        .next = start,
        .running = true,

        // Music player
        .volume = 128,
    };
    return s;
}
