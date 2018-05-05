#ifndef MILITARY_H
#define MILITARY_H

#include "state.h"

void military_start(struct state *);
void military_off_down(struct state *);
void military_off_up(struct state *);
void military_on_down(struct state *);
void military_on_up(struct state *);

#endif
