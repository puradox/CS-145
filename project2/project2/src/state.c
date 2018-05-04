#include <stdio.h>
#include "state.h"
#include "keypad.h"
#include "date_utils.h"

struct state make_state(state_fn *clock_start, state_fn *menu_start)
{
    struct state s = {
        clock_start, // next_clock
        menu_start,  // next_menu

        // Clock
        0,    // counter
        0,    // is_military_time
        2018, // year
        12,    // month
        31,    // day
        24,    // hour
        59,   // minute
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
        sprintf(buf, "%2d:%02d:%02d",
                s->hour, s->minute, s->second);
    }
    else
    {
        int meridiem = s->hour >= 12 ? "PM" : "AM";
        int hour = ((s->hour - 1) % 12) + 1;
        sprintf(buf, "%2d:%02d:%02d %s",
                hour, s->minute, s->second, meridiem);
    }
}

void format_date(char *buf, struct state *s)
{
    sprintf(buf, "%s %2d, %4d",
            MONTHS[s->month], s->day, s->year);
}
