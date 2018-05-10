#include "military.h"

void military_start(struct state *s)
{
    s->next_military = military_off_up;
}

void military_off_down(struct state *s)
{
    if (!s->pound)
        s->next_military = military_off_up;
}

void military_off_up(struct state *s)
{
    if (s->pound)
    {
        s->is_military_time = 1;
        s->next_military = military_on_down;
    }
}

void military_on_down(struct state *s)
{
    if (!s->pound)
        s->next_military = military_on_up;
}

void military_on_up(struct state *s)
{
    if (s->pound)
    {
        s->is_military_time = 0;
        s->next_military = military_off_down;
    }
}
