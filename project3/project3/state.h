#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <stdbool.h>

//
// Data types
//

struct state;
typedef void state_fn(struct state *);

struct state
{
    state_fn *next;
    bool running;

    // Music player
    uint16_t volume;
    uint16_t bpm;
};

//
// Functions
//

struct state make_state(state_fn *start);

#endif
