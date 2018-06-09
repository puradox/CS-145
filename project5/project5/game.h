#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "state.h"


#define ROW_SIZE 16

struct state generate_and_move(struct state);
void move_row_left(char*, char, bool);
bool decide_if_block();
bool detect_player_block_collision(struct state);

#endif GAME_H