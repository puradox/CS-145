#include "avr.h"
#include "lcd.h"
#include "timer.h"
#include "state.h"
#include "clock.h"
#include "menu.h"
#include "keypad.h"

int main(void)
{
    // Initalization
    ini_avr();
    ini_timers();
    ini_lcd();

    // Timer 0 is being used for the FSM loop.
    // Timer 1 is not being used.
    // Timer 2 is being used for the keypad and LCD.

    struct state s = make_state(clock_start, menu_start);
    char time[16], date[16];

    while (s.next_clock != 0 && s.next_menu != 0)
    {
        reset_timer1(MS_PER_CLOCK);

        // Reset the Watchdog timer (expires in 2.1 seconds)
        // If anything takes too long, the Watchdog timer will restart
        // the ATMega32 and start at the beginning of the program.
        asm volatile("wdr"::);

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
        pos_lcd(1, 0);
        format_date(date, &s);
        puts_lcd2(date);

        // Wait until the timer expires
        wait_timer1();
    }

    stop_timers();
    return 0;
}
