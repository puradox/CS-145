#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

//
// 8-bit Timer/Counter 0
//
// TODO
//

//
// 16-bit Timer/Counter 1
//

void timer1_start(unsigned short ms)
{
    // Configure interrupts
    TIMSK |= (1 << OCIE1A); // Enable CTC interrupt
    sei();                  // Enable global interrupts

    //
    // Calculating the CTC compare value (OCR1A)
    //
    // CPU_FREQ / PRESCALER / MILLISECONDS_IN_SECOND * ms - 1
    // 8,000,000 / 64 / 1,000 * ms - 1
    // 125 * ms - 1
    //

    // Configure timer
    TCCR1B |= (1 << WGM12);                 // Enable CTC mode
    OCR1A = (unsigned short)(125 * ms - 1); // Set CTC compare value
    TCCR1B |= CLK_DIVIDED_BY_64;            // Start timer at Fcpu/64
}

void timer1_stop()
{
    TCCR1B = TIMER_OFF; // Clock Select
}

//
// 8-bit Timer/Counter 2
//
// TODO
//
