#include "clock.h"

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

char is_leap_year(int year)
{
    // A leap year extends February to 29 days, rather than the normal 28 days.
    // These extra days occur in years which are multiples of four
    // (with the exception of years divisible by 100 but not by 400).
    if (year % 100 == 0 && year % 400 != 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    else
        return 0;
}

char days_in_month(int month, int year)
{
    if (is_leap_year(year))
        return DAYS_PER_MONTH_LEAP_YEAR[month];
    else
        return DAYS_PER_MONTH[month];
}
