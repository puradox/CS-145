#ifndef PLAYER_H
#define PLAYER_H

#include "state.h"

void player_start(struct state *);

void play(struct state*);

/*
void song_start(struct state *);
void song_none_pressed(struct state *);
void song_next_pressed(struct state *);
void song_prev_pressed(struct state *);

void volume_start(struct state *);
void volume_none_pressed(struct state *);
void volume_up_pressed(struct state *);
void volume_down_pressed(struct state *);

void tempo_start(struct state *);
void tempo_none_pressed(struct state *);
void tempo_up_pressed(struct state *);
void tempo_down_pressed(struct state *);
*/

#endif
