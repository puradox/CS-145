#include <avr/io.h>
#include <avr/wdt.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "analog.h"
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
	srand(420);
    ini_avr();
    ini_lcd();
    analog_init();

    s = make_state();

    timer2_start(); // ticks every 1ms

    while (running)
    {
    }

    // Display error
    clr_lcd();
    pos_lcd(0, 0);
    puts_lcd2("ERROR");

    return 0;
}

TIMER2_TICK()
{
    // Reset the Watchdog timer (expires in 2.1 seconds)
    wdt_reset();

    // Check for invalid FSM states
    if (s.next_screen == NULL || s.next_game == NULL || s.next_jump == NULL || s.next_player == NULL)
    {
        running = false;
        return;
    }

    analog_wait();

    // Update inputs
    s.measured_voltage = ADC;
    s.key_A = is_key_pressed(KEY_A); // continue & jump
    s.key_B = is_key_pressed(KEY_B); // pause
    // s.key_C = is_key_pressed(KEY_C);
    // s.key_D = is_key_pressed(KEY_D);

    // Run FSMs
    s.next_screen(&s);
    s.next_player(&s);
}
