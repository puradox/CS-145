#include <avr/io.h>
#include "audio.h"

void audio_on(void)
{
    // Use timer1 for Pulse Width Modulation (PWM)
    TCCR1A |= _BV(COM1A0); // toggle OC1A on compare match
    TCCR1B |= _BV(WGM13); // PWM, Phase and Frequency Correct
    TCCR1B |= _BV(CS11) | _BV(CS10); // use prescaler 64
}

void audio_off(void)
{
    TCCR1B &= ~(_BV(CS11) | _BV(CS10)); // stop timer1
}

void play_freq(uint16_t freq, uint16_t volume)
{
    ICR1 = freq;
    OCR1A = freq * ((double)volume / 256.0);
}
