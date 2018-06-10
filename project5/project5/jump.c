#include "jump.h"

void jump_ready(struct state *s)
{
    if (s->key_A)
    {
        s->row1[0] = 'P';
        s->row2[0] = ' ';
        s->next_jump = jump_hover;
    }
}

void jump_hover(struct state *s)
{
    if (s->jump_counter == 1)
    {
        s->row1[0] = ' ';
        s->row2[0] = 'P';
        s->jump_counter = 0;
        s->next_jump = jump_ready;
    }
    else
    {
        s->jump_counter++;
    }
}
