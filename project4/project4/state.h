#ifndef STATE_H
#define STATE_H

#include <stdbool.h>
#include <stdint.h>

struct state;
typedef void state_fn(struct state *);

struct state
{
    state_fn *next_display;

    //
    // input
    //

    bool key_A; // is A on the keypad pressed?
    uint16_t measured_voltage;

    //
    // display FSM
    //

    // Circular array of past and current voltages
    uint16_t *voltages;

    // Cursor to the next voltage to replace in the circular array
    uint8_t cursor;

    // Number of voltages stored in the circular array
    uint8_t count;

    // Running sum of the past and current voltages
    uint16_t sum;
};

struct state make_state();

#endif
