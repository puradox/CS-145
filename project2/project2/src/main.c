#include "avr.h"
#include "lcd.h"
#include "state.h"
#include "timer.h"
#include "keypad.h"
#include "clock.h"
#include "menu.h"

static const unsigned short CTC_MAX = 125 * 10 - 1;
static struct state s;
static char time[16], date[16];

int main()
{
    // Timer 0 used for initialization of LCD.
    // Timer 1 used for the FSM loop.
    // Timer 2 is not being used.

    // Initialization
    ini_avr();
    ini_lcd();

    s = make_state(clock_start, menu_start);
    start_timer1(10);

    for (;;)
    {
    }

    return 0;
}

TIMER1_TICK()
{
    if (s.next_clock != 0 && s.next_menu != 0)
    {
        // Reset the Watchdog timer (expires in 2.1 seconds)
        // If anything takes too long, the Watchdog timer will restart
        // the ATMega32 and start at the beginning of the program.
        asm volatile("wdr" ::);

        // Reset the keypad input
        s.key_pressed = get_key();

        // Run the finite state machines
        s.next_menu(&s);
        s.next_clock(&s);

        // Update the time
        pos_lcd(0, 0);
        format_time(time, &s);
        puts_lcd2(time);

        // Update the date
        //pos_lcd(1, 0);
        //format_date(date, &s);
        //puts_lcd2(date);
    }
}
