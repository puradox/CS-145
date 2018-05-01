#include "clock.h"
#include "date_utils.h"

const int CLOCKS_PER_SEC = 1000 / MS_PER_CLOCK;

void clock_start(struct state *s)
{
    s->counter = 0;
    s->next_clock = clock_tick;
}

void clock_tick(struct state *s)
{
    s->counter++;

    if (s->counter >= CLOCKS_PER_SEC)
    {
        s->minute += s->counter / CLOCKS_PER_SEC;
        s->counter %= CLOCKS_PER_SEC;
    }
    if (s->minute >= 60)
    {
        s->hour += s->minute / 60;
        s->minute %= 60;
    }
    if (s->hour >= 24)
    {
        s->day += s->hour / 60;
        s->hour %= 60;
    }

    int max_days = days_in_month(s->month, s->year);
    while (s->day >= max_days)
    {
        s->month++;
        s->day -= max_days;

        if (s->month >= 12)
        {
            s->year += s->month / 12;
            s->month %= 12;
        }

        max_days = days_in_month(s->month, s->year);
    }
}
