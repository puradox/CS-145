#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

//
// 8-bit Timer/Counter 0
//
// Clocked at 16ms per tick
//
// Calculating the CTC compare value (OCR0)
//
// CPU_FREQ / PRESCALER / MILLISECONDS_IN_SECOND * ms - 1
// 8,000,000 / 1024 / 1,000 * ms - 1
// 125 / 16 * ms - 1
// 125 - 1 where ms = 16
// 124
//

void timer0_start(void)
{
    // Configure interrupts
    TIMSK |= (OCIE0); // enable CTC interrupt
    sei();            // enable global interrupts

    // Clear Timer on Compare Match (CTC)
    TCCR0 |= (1 << WGM01);      // enable CTC mode
    OCR0 = 124;               // Set CTC compare value at 16ms per tick
    TCCR0 |= TIMER0_CLK_1024; // start timer at Fcpu/1024
}

void timer0_stop(void)
{
    TCCR0 &= TIMER0_OFF; // turn off timer
}

//
// 16-bit Timer/Counter 1
//
// Calculating the CTC compare value (OCR1A)
//
// CPU_FREQ / PRESCALER / MILLISECONDS_IN_SECOND * ms - 1
// 8,000,000 / 64 / 1,000 * ms - 1
// 125 * ms - 1
//

void timer1_start(unsigned short ms)
{
    // Configure interrupts
    TIMSK |= _BV(OCIE1A); // enable CTC interrupt
    sei();                // enable global interrupts

    // Clear Timer on Compare Match (CTC)
    TCCR1B |= (1 << WGM12);                 // enable CTC mode
    OCR1A = (unsigned short)(125 * ms - 1); // set CTC compare value

    TCCR1B |= TIMER1_CLK_64;                // Start timer at Fcpu/64
}

void timer1_stop()
{
    TCCR1B = TIMER1_OFF; // turn off timer
}

//
// 8-bit Timer/Counter 2
//
// Calculating the CTC compare value (OCR1A)
//
// CPU_FREQ / PRESCALER / MILLISECONDS_IN_SECOND * ms - 1
// 8,000,000 / 1024 / 1,000 * ms - 1
// 125 / 16 * ms - 1
// 125 - 1 where ms = 16
// 124
//

void timer2_start(void)
{
    // Interrupts
    TIMSK |= _BV(OCIE2); // enable CTC interrupt
    sei();               // enable global interrupts

    // Clear Timer on Compare Match (CTC)
    TCCR2 |= _BV(WGM21);     // enable CTC mode
    TCNT2 = 0;               // reset counter
    OCR2 = 124;              // set CTC compare value at 16ms per tick
    TCCR2 |= TIMER2_CLK_256; // start timer at Fcpu/1024
}

void timer2_stop(void)
{
    TCCR2 = TIMER2_OFF; // turn off timer
}
