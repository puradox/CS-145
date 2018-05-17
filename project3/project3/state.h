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
    state_fn *menu_next;
	state_fn *player_next;
	state_fn *song_player;

	musical_note current_note;
	
	
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

struct state make_state(state_fn *menu_start,state_fn *player_start);
void playing(struct state*);

#endif
