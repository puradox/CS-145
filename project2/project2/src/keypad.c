#include <avr/io.h>
#include "keypad.h"
#include "timer.h"

int is_pressed(int row, int col)
{
    // Program row/column and clear everything else
    DDRC = (1 << row);        // row is an output (strong 0)
    PORTC = (1 << (col + 4)); // col is a "pull up" input (weak 1)

    // Wait 1000 microseconds for the programming to take affect
    sleep_timer2(1000);

    // Read the row/column
    int result = PINC & (1 << (col + 4));
    return result ? 0 : 1;
}

enum key get_key()
{
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if (is_pressed(row, col))
                return (enum key)(row * 4 + col + 1);
        }
    }
    return KEY_NONE;
}
