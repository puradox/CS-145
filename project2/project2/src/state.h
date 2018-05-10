#ifndef STATE_H
#define STATE_H

//
// Data types
//

struct state;
typedef void state_fn(struct state *);

struct state
{
    state_fn *next_clock;
    state_fn *next_menu;
    state_fn *next_military;

    //
    // Clock
    //

    int ticks;

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

    char A; // is A being pressed?
    char B; // is B being pressed?
    char C; // is C being pressed?
    char D; // is D being pressed?
    char is_menu_on;
    char cursor_row;
    char cursor_col;

    //
    // Military (24-hour) time
    //

    char pound; // is the pound button being pressed?
    char is_military_time;
};

//
// Functions
//

struct state make_state(state_fn *clock_start, state_fn *menu_start);

#endif
