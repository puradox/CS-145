#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "state.h"
#include "keypad.h"
#include "jump.h"

#define ROW_SIZE 16

// States
void game_menu(struct state *);
void game_play(struct state *);
void game_over(struct state *);

// Helpers
void move_row_left(char*, char);
bool decide_if_block();
bool detect_player_block_collision(struct state *s);
void display_game(struct state *s);

#endif GAME_H
