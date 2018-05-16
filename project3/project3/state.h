#ifndef STATE_H
#define STATE_H

#include <stdint.h>
#include <stdbool.h>
#include "musical_notes.h"

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
    uint16_t tempo;
    uint16_t volume;
    musical_note *song;
    uint16_t song_len;
    char *song_title;

    // Menu
    bool A;
    bool B;
    bool C;
    bool D;
};

//
// Functions
//

struct state make_state(state_fn *start);

#endif
