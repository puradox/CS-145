#include <avr/sleep.h>

#include "avr.h"
#include "lcd.h"
#include "state.h"
#include "timer.h"
#include "keypad.h"
#include "clock.h"
#include "menu.h"
#include "date_utils.h"
#include "config.h"

static const unsigned short CTC_MAX = 125 * 10 - 1;
static struct state s;
static char time[16], date[16];
static char running;

int main()
{
    // Timer 0 used for initialization of LCD.
    // Timer 1 used for the FSM loop; uses interrupts
    // Timer 2 is not being used.

    // Initialization
    ini_avr();
    ini_lcd();
    set_sleep_mode(SLEEP_MODE_IDLE);
    running = 1;

    s = make_state(clock_start, menu_start);
    timer1_start(MS_PER_TICK);
    sleep_enable();

    while (running == 1)
    {
        sleep_cpu();
    }

    // Display error
    clr_lcd();
    pos_lcd(0, 0);
    puts_lcd2("ERROR");

    sleep_disable();
    timer1_stop();
    return 0;
}

TIMER1_TICK()
{
    if (s.next_clock != 0 && s.next_menu != 0 && s.next_military != 0)
    {
        // Reset the Watchdog timer (expires in 2.1 seconds)
        // If anything takes too long, the Watchdog timer will restart
        // the ATMega32 and start at the beginning of the program.
        asm volatile("wdr" ::);

        // Reset the keypad input
        s.A = is_key_pressed(KEY_A);
        s.B = is_key_pressed(KEY_B);
        s.C = is_key_pressed(KEY_C);
        s.D = is_key_pressed(KEY_D);
        s.pound = is_key_pressed(KEY_POUND);

        // Run the finite state machines
        s.next_menu(&s);
        s.next_clock(&s);
        s.next_military(&s);

        // Disable the cursor
        disable_cursor();

        // Update the date
        pos_lcd(0, 0);
        format_date(date, &s);
        puts_lcd2(date);

        // Update the time
        pos_lcd(1, 0);
        format_time(time, &s);
        puts_lcd2(time);

        // Enable the cursor
        if (s.is_menu_on)
        {
            pos_lcd(s.cursor_row, s.cursor_col);
            enable_cursor();
        }
    }
    else
    {
        running = 0;
    }
}
