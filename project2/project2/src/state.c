#include <stdio.h>
#include "state.h"

const char MONTHS[12][3] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
};

struct state make_state(state_fn *clock_start, state_fn *menu_start)
{
    struct state s = {
        clock_start, // next_clock
        menu_start,  // next_menu
        2018,        // year
        5,           // month
        1,           // minute
        0,           // second
        0,           // counter
        0,           // number
        0,           // menu
        0,           // increment
        0,           // decrement
        0            // military
    };
    return s;
}

void format_display(char *buf, struct state *s)
{
    if (s->military)
    {
        sprintf(buf, "%2i:%02i:%02i        %s %2i, %4i    ",
                s->hour, s->minute, s->second,
                MONTHS[s->month], s->day, s->year);
    }
    else
    {
        int meridiem = s->hour > 12 ? "PM" : "AM";
        int hour = ((s->hour - 1) % 12) + 1;
        sprintf(buf, "%2i:%02i:%02i %s     %s %2i, %4i    ",
                hour, s->minute, s->second, meridiem,
                MONTHS[s->month], s->day, s->year);
    }
}
