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
void state_fn_todo(struct state *s) {}

struct state
{

    // Finite state machines
    state_fn *next_song;
    state_fn *next_volume;
    state_fn *next_tempo;
    state_fn *next_player;


    // Data
    uint16_t tempo;
    uint16_t volume;
    musical_note *song;
    uint16_t song_len;
    char *song_title;

    // Input
    bool A;     // volume up
    bool B;     // volume down
    bool C;     // tempo up
    bool D;     // tempo down
    bool star;  // prev song
    bool pound; // next song
};

//
// Functions
//

struct state make_state(state_fn *menu_start,state_fn *player_start);
void playing(struct state*);


#endif
