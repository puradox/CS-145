#ifndef SCREEN_H
#define SCREEN_H

#include "state.h"

// Initializes FSM variables
void screen_start(struct state *s);

// Shows the title and authors
void screen_intro(struct state *s);
void screen_intro_down(struct state *s);

// Displays controls
void screen_controls(struct state *s);
void screen_controls_down(struct state *s);

// Actual game
void screen_game(struct state *s);
void screen_game_down(struct state *s);

// Pause menu
void screen_pause(struct state *s); // TODO(Sam): if there is time
void screen_pause_down(struct state *s); // TODO(Sam): if there is time

// Gameover menu
void screen_game_over(struct state *s);
void screen_game_over_down(struct state *s);

#endif
