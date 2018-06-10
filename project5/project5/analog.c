#include <avr/io.h>
#include "analog.h"

void analog_init()
{
    ADCSRA |= (1 << ADEN);
    ADMUX |= (1 << REFS0);
}

void analog_wait()
{
    // Wait for the ADC to finish converting
    while ((ADCSRA & 64) != 0)
    {
    }
    ADCSRA |= (1 << ADSC); // automatically cleared when done
}
