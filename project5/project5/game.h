#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "state.h"
#include "keypad.h"
#include "jump.h"

#define ROW_SIZE 16

// States
void menu(struct state *);
void play(struct state *);
void game_over(struct state *);

// Helpers
struct state generate_and_move(struct state);
void move_row_left(char*, char, bool);
bool decide_if_block();
bool detect_player_block_collision(struct state);
void display_game(struct state*);

#endif GAME_H