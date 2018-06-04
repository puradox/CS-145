#include <avr/io.h>
#include <avr/wdt.h>
#include <stddef.h>

#include "lcd.h"
#include "timer.h"
#include "keypad.h"
#include "state.h"
#include "display.h"

static struct state s;
char running = 1;

int main(void)
{
    // next step: timer0 calling
    ini_avr();
    ini_lcd();

    s = make_state();

    ADCSRA |= (1 << ADEN);
    ADMUX |= (1 << REFS0);

    timer1_start(500);

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
    if (s.next_display == NULL)
    {
        running = 0;
        return;
    }

    // Wait for the ADC to finish converting
    while ((ADCSRA & 64) != 0)
    {
    }
    ADCSRA |= (1 << ADSC); // automatically cleared when done

    // Update inputs
    s.measured_voltage = ADC;
    s.key_A = is_key_pressed(KEY_A);
	
	if (s.key_A)
	{
		s.next_display = display_restart;
	}

    // Run FSMs
    s.next_display(&s);
	


}
