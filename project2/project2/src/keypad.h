#ifndef KEYPAD_H
#define KEYPAD_H

#include "timer.h"

enum key {
    KEY_NONE = 0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_A,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_B,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_C,
    KEY_STAR,
    KEY_0,
    KEY_POUND,
    KEY_D,
};

int is_pressed(int row, int col);
enum key get_key(void);

#endif
