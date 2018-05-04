#include "clock.h"
#include "date_utils.h"
#include "config.h"

void clock_start(struct state *s)
{
    s->counter = 0;
    s->next_clock = clock_tick;
}

void clock_tick(struct state *s)
{
    s->counter++;

    if (s->counter >= TICKS_PER_SEC)
    {
        increment_second(s);
        s->counter = 0;
    }
}
