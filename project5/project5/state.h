#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include <stdint.h>
#include "screen.h"

struct state;
typedef void state_fn(struct state *);

struct state
{
    state_fn *next_screen;
    state_fn *next_game;
	state_fn *next_jump;

    //
    // Inputs
    //

    // keypad
    bool key_A;
    bool key_B;
    bool key_C;
    bool key_D;

    // analog
    uint16_t measured_voltage;

    //
    // Game FSM
    //

    char row1[16];
	char row2[16];
	int ticks_since_last_block;
	bool gg;
	int ticks_played;

    //
    // Player FSM
    //

    musical_song *song_list;
    uint16_t song_list_len;

    uint8_t song_index;
    uint8_t note_index;
    uint16_t duration_max;
    uint16_t duration_curr;

    //
    // Jump FSM
    //

};

struct state make_state();

#endif
