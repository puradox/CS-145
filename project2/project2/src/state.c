#include <stdio.h>
#include "state.h"
#include "keypad.h"

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

        // Clock
        0,    // counter
        0,    // is_military_time
        2018, // year
        5,    // month
        2,    // day
        4,    // hour
        20,   // minute
        0,    // second

        // Menu
        KEY_NONE, // key_pressed
    };
    return s;
}

void format_time(char *buf, struct state *s)
{
    if (s->is_military_time)
    {
        sprintf(buf, "%2i:%02i:%02i        ",
                s->hour, s->minute, s->second);
    }
    else
    {
        int meridiem = s->hour > 12 ? "PM" : "AM";
        int hour = ((s->hour - 1) % 12) + 1;
        sprintf(buf, "%2i:%02i:%02i %s     ",
                hour, s->minute, s->second, meridiem);
    }
}

void format_date(char *buf, struct state *s)
{
    sprintf(buf, "%s %2i, %4i    ",
            MONTHS[s->month], s->day, s->year);
}
