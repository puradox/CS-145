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
// void state_fn_todo(struct state *s) {} ?

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
    song *song_list;
    uint16_t song_list_len;
    uint8_t song_index;

	int note_index;
	int note_duration_played;

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

struct state make_state();


#endif
