#include <avr/io.h>
#include "audio.h"

void audio_on(void)
{
    DDRD |= (1 << 4);
    // Use timer1 for Pulse Width Modulation (PWM)
    TCCR1A |= _BV(COM1B1);           // toggle OC1A on compare match
    TCCR1B |= _BV(WGM13);            // PWM, Phase and Frequency Correct
    TCCR1B |= _BV(CS11) | _BV(CS10); // use prescaler 64
}

void audio_off(void)
{
    DDRD &= ~(1 << 4);
    TCCR1B &= ~(_BV(CS11) | _BV(CS10)); // stop timer1
}

void play_freq(uint16_t note, uint8_t volume)
{
    ICR1 = note;
    OCR1B = (10 * note) / volume;
}
