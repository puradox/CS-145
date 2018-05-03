#ifndef STATE_H
#define STATE_H

#include "keypad.h"

#define MS_PER_CLOCK 5

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
void format_display(char *buf, struct state *s);

#endif
