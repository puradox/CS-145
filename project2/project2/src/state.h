#ifndef STATE_H
#define STATE_H

#include "keypad.h"

//
// Data types
//

struct state;
typedef void state_fn(struct state *);

struct state
{
    state_fn *next_clock;
    state_fn *next_menu;

    //
    // Clock
    //

    int counter;
    char is_military_time;

    // Date
    int year;
    int month;
    int day;

    // Time
    int hour;
    int minute;
    int second;

    //
    // Menu
    //

    enum key key_pressed;
};

//
// Functions
//

struct state make_state(state_fn *clock_start, state_fn *menu_start);
void format_time(char *buf, struct state *s);
void format_date(char *buf, struct state *s);

#endif
