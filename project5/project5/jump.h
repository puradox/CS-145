#ifndef JUMP_H
#define JUMP_H

#include <stdbool.h>
#include "state.h"

void ready(struct state *);
void begin_jump(struct state *);
void mid_jump(struct state *);
void end_jump(struct state *);


#endif JUMP_H
