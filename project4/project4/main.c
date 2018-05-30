#include <avr/io.h>
#include <avr/wdt.h>
#include <stddef.h>

#include "lcd.h"
#include "timer.h"
#include "state.h"

static struct state s;
char running = 1;

int main(void)
{
    // next step: timer0 calling
    //ini_avr();
    ini_lcd();
	wait_avr(50);

    //s = make_state();

    ADCSRA |= (1 << ADEN);
    ADMUX |= (1 << REFS0);

    timer1_start(500);

    while (running)
    {
    }
}

TIMER1_TICK()
{
    // Check for invalid FSM states
	/*
    if (s.next_display == NULL)
    {
        running = 0;
        return;
    }
	*/

    // Wait for the ADC to finish converting
    while ((ADCSRA & 64) != 0)
    {
    }
    ADCSRA |= (1 << ADSC); // automatically cleared when done

    // Update inputs
    //s.measured_voltage = ADC;

	char buffer[8];
	sprintf(buffer, "%4i", ADC);
	pos_lcd(0,0);
	puts_lcd2(buffer);

    // Run FSMs
    //s.next_display(&s);
}
