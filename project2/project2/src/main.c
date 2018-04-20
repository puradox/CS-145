#include <asf.h>
#include "avr.h"
#include "lcd.h"

int is_pressed(int row, int col)
{
    // Program row/column and clear everything else
    DDRC  = (1 << row);        // row is an output (strong 0)
    PORTC = (1 << (col + 4));  // col is a "pull up" input (weak 1)

    // Read the row/column
    int result = PINC & (1 << (col + 4));
    return result ? 0 : 1;
}

int get_key()
{
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if (is_pressed(row, col))
                return row * 4 + col + 1;
        }
    }
}

int main (void)
{
    // Initalization
	board_init();
    ini_avr();
    //ini_lcd();

    // Configure GPIO pins
    DDRB |= (1 << 0);  // B0 is an output

    for (;;) {
        char key = get_key();

        if (key)
            PORTB |= 1;
        else
            PORTB &= ~1;
    }

    return 0;
}
