#ifndef KEYPAD_H
#define KEYPAD_H

enum key
{
    KEY_1 = 0,
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
int is_key_pressed(enum key k);
enum key get_key(void);

#endif
