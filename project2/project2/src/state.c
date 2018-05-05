#include "state.h"
#include "clock.h"
#include "menu.h"
#include "military.h"
#include "keypad.h"

struct state make_state(state_fn *clock_start, state_fn *menu_start)
{
    struct state s = {
        clock_start,    // next_clock
        menu_start,     // next_menu
        military_start, // next_military

        // Clock
        0,    // ticks
        2018, // year
        4,   // month
        7,   // day
        4,   // hour
        20,   // minute
        0,    // second

        // Menu
        KEY_NONE, // key_pressed

        // Military
        0, // is_military_time
    };
    return s;
}
