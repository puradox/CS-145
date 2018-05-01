#include "date_utils.h"

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

void increment_month(struct state *s)
{
    s->month++;
    if (s->month >= 12) {
        increment_year(s);
        s->month -= 11;
    }
}

void increment_day(struct state *s)
{
    s->day++;
    int days_month = days_in_month(s->month, s->year);
    if (s->day >= days_month) {
        increment_month(s);
        s->day -= days_month;
    }
}

void increment_year(struct state *s)
{
    s->year++;
}

void increment_hour(struct state *s)
{
    s->hour++;
    if (s->hour >= 24) {
        increment_day(s);
        s->hour -= 24;
    }
}

void increment_minute(struct state *s)
{
    s->minute++;
    if (s->minute >= 60) {
        increment_hour(s);
        s->minute -= 60;
    }
}

void increment_second(struct state *s)
{
    s->second++;
    if (s->minute >= 60) {
        increment_minute(s);
        s->second -= 60;
    }
}
