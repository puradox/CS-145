#include "clock.h"
#include "date_utils.h"
#include "config.h"

void clock_start(struct state *s)
{
    s->ticks = 0;
    s->next_clock = clock_tick;
}

void clock_tick(struct state *s)
{
    s->ticks++;

    if (s->ticks >= TICKS_PER_SEC)
    {
        increment_second(s);
        s->ticks = 0;
    }
}
