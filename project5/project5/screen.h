#ifndef SCREEN_H
#define SCREEN_H

#include "state.h"

// Initializes FSM variables
void screen_start(struct state *s);

// Shows the title and authors
void screen_intro(struct state *s);

// Displays controls
void screen_controls(struct state *s);

// Actual game
void screen_game(struct state *s);

// Pause menu
void screen_pause(struct state *s); // TODO(Sam): if there is time

// Gameover menu
void screen_gameover(struct state *s);

#endif
