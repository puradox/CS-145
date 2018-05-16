#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

//
// 8-bit Timer/Counter 0
//
// Clocked at 16ms per tick
//

void timer0_start(void)
{
    // Configure interrupts
    TIMSK |= _BV(OCIE0); // Enable CTC interrupt
    sei();               // Enable global interrupts

    //
    // Calculating the CTC compare value (OCR1A)
    //
    // CPU_FREQ / PRESCALER / MILLISECONDS_IN_SECOND * ms - 1
    // 8,000,000 / 1024 / 1,000 * ms - 1
    // 125 / 16 * ms - 1
    // 125 - 1 where ms = 16
    // 124
    //

    // Configure timer
    TCCR0 |= _BV(WGM01);          // Enable CTC mode
    OCR0 = 124;                   // Set CTC compare value at 16ms per tick
    TCCR0 |= CLK_DIVIDED_BY_1024; // Start timer at Fcpu/1024
}

void timer0_stop(void)
{
    TCCR0 &= ~CLK_DIVIDED_BY_1024; // Clock Select
}

//
// 16-bit Timer/Counter 1
//

void timer1_start(unsigned short ms)
{
    // Configure interrupts
    TIMSK |= _BV(OCIE1A); // Enable CTC interrupt
    sei();                // Enable global interrupts

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
