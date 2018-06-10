#include "jump.h"

void ready(struct state* s)
{
	s->player_in_bottom = true;

    if (s->key_A)
        s->next_jump = begin_jump;
}

void begin_jump(struct state* s)
{
	s->player_in_bottom = false;
	s->next_jump = mid_jump;
}

void mid_jump(struct state* s)
{
	s->next_jump = end_jump;
}

void end_jump(struct state* s)
{
	s->next_jump = ready;
}
