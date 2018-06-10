#include <avr/io.h>
#include <avr/wdt.h>
#include <stdbool.h>
#include <stddef.h>

#include "game.h"
#include "jump.h"
#include "keypad.h"
#include "lcd.h"
#include "state.h"
#include "timer.h"

static struct state s;
static bool running = true;

int main(void)
{
    // next step: timer0 calling
    ini_avr();
    ini_lcd();

    s = make_state();

    ADCSRA |= (1 << ADEN);
    ADMUX |= (1 << REFS0);

    timer1_start(100);

    while (running)
    {
    }

    return 0;
}


TIMER1_TICK()
{
    // Reset the Watchdog timer (expires in 2.1 seconds)
    wdt_reset();

    // Check for invalid FSM states
    if (s.next_screen == NULL)
    {
        running = false;
        return;
    }

    // Wait for the ADC to finish converting
    while ((ADCSRA & 64) != 0)
    {
    }
    ADCSRA |= (1 << ADSC); // automatically cleared when done

    // Update inputs
    s.measured_voltage = ADC;
    s.key_A = is_key_pressed(KEY_A); // continue & jump
    s.key_B = is_key_pressed(KEY_B); // pause
    // s.key_C = is_key_pressed(KEY_C);
    // s.key_D = is_key_pressed(KEY_D);

    // Run FSMs
    s.next_screen(&s);
}
