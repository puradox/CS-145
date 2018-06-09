#include "jump.h"

void ready(struct state* s)
{
	s->player_in_bottom = true;
}

void begin_jump(struct state* s)
{
	s->player_in_bottom = false;
	s->jump = mid_jump;
}

void mid_jump(struct state* s)
{
	s->jump = end_jump;
}

void end_jump(struct state* s)
{
	s->jump = ready;
}