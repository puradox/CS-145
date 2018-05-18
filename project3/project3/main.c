#include <avr/io.h>
#include <avr/wdt.h>

#include "audio.h"
#include "keypad.h"
#include "lcd.h"
#include "menu.h"
#include "state.h"
#include "timer.h"
#include "musical_notes.h"

static struct state s;
static char running;

int main(void)
{
    // Timer 0 set in CTC mode for FSM loop.
    // Timer 1 set in PWM mode connected to the speaker
    // Timer 2 is not being used.

    // Initialization
    ini_avr();
    ini_lcd();
    running = 1;

    s = make_state();
    timer0_start(); // Ticks every 16ms
    audio_on();
	
void menu_start(struct state *);

    play_freq(NOTE_C5, 200);
	play_freq(NOTE_A4, 200);

    while (running == 1)
    {
    }

    // Display error
    clr_lcd();
    pos_lcd(0, 0);
    puts_lcd2("ERROR");

    timer0_stop();
    return 0;
}

TIMER0_TICK()
{
    if (s.next_song && s.next_volume && s.next_tempo && s.next_player)
    {
        // Reset the Watchdog timer (expires in 2.1 seconds)
        wdt_reset();

        // Reset the keypad input
        s.A = is_key_pressed(KEY_A);
        s.B = is_key_pressed(KEY_B);
        s.C = is_key_pressed(KEY_C);
        s.D = is_key_pressed(KEY_D);
        s.star = is_key_pressed(KEY_STAR);
        s.pound = is_key_pressed(KEY_POUND);

        // Run the finite state machines
        s.next_song(&s);
        s.next_volume(&s);
        s.next_tempo(&s);
        s.next_player(&s);
    }
    else
    {
        running = 0;
    }
}
