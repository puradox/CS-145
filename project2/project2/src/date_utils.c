#include <stdio.h>
#include "date_utils.h"

void format_time(char *buf, struct state *s)
{
    if (s->is_military_time)
    {
        sprintf(buf, "%02d:%02d:%02d   ",
                s->hour, s->minute, s->second);
    }
    else
    {
        int hour = (s->hour % 12 == 0) ? 12 : (s->hour % 12);
        char *meridiem = (s->hour >= 12) ? "PM" : "AM";
        sprintf(buf, "%2d:%02d:%02d %s",
                hour, s->minute, s->second, meridiem);
    }
}

void format_date(char *buf, struct state *s)
{
    sprintf(buf, "%s %d, %4d ",
            MONTHS[s->month], s->day, s->year);
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

//
// Increment
//

void increment_year(struct state *s)
{
    s->year++;
}

void increment_month(struct state *s)
{
    s->month++;
    if (s->month == 12)
    {
        increment_year(s);
        s->month = 0;
    }

    // Make sure the day never extends over what the month allows.
    int max_days = days_in_month(s->month, s->year);
    if (s->day > max_days)
    {
        s->day = max_days;
    }
}

void increment_day(struct state *s)
{
    s->day++;
    if (s->day == days_in_month(s->month, s->year) + 1)
    {
        increment_month(s);
        s->day = 1;
    }
}

void increment_hour(struct state *s)
{
    s->hour++;
    if (s->hour == 24)
    {
        increment_day(s);
        s->hour = 0;
    }
}

void increment_minute(struct state *s)
{
    s->minute++;
    if (s->minute == 60)
    {
        increment_hour(s);
        s->minute = 0;
    }
}

void increment_second(struct state *s)
{
    s->second++;
    if (s->second == 60)
    {
        increment_minute(s);
        s->second = 0;
    }
}

//
// Decrement
//

void decrement_year(struct state *s)
{
    s->year--;
}

void decrement_month(struct state *s)
{
    s->month--;
    if (s->month == -1)
    {
        decrement_year(s);
        s->month = 11;
    }

    // Make sure the day never extends over what the month allows.
    int max_days = days_in_month(s->month, s->year);
    if (s->day > max_days)
    {
        s->day = max_days;
    }
}

void decrement_day(struct state *s)
{
    s->day--;
    if (s->day == 0)
    {
        decrement_month(s);
        s->day = days_in_month(s->month, s->year);
    }
}

void decrement_hour(struct state *s)
{
    s->hour--;
    if (s->hour == -1)
    {
        decrement_day(s);
        s->hour == 23;
    }
}

void decrement_minute(struct state *s)
{
    s->minute--;
    if (s->minute == -1)
    {
        decrement_hour(s);
        s->minute = 59;
    }
}

void decrement_second(struct state *s)
{
    s->second--;
    if (s->second == -1)
    {
        decrement_minute(s);
        s->second = 59;
    }
}
