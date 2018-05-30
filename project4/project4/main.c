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
    ini_avr();
    ini_lcd();

    s = make_state();

    ADCSRA |= (1 << ADEN);
    ADMUX |= (1 << REFS0);

    timer0_start();

    while (running)
    {
    }
}

TIMER0_TICK()
{
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

    // Run FSMs
    s.next_display(&s);
}
