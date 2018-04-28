#include "timer.h"

void ini_timer()
{
    // Clock Select (CS02, CS01, CS00): clk/64
    // The 8-bit timer will increment every 64 clock cycles.
    TCCR0 = 0x03;
}

void reset_timer(double ms)
{
    // Reset the 8-bit Timer/Counter Register to just below the
    // number of cycles needed to overflow from the given duration.
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001 * ms);

    // Set the Timer/Counter Overflow Flag (TOV) to clear it.
    // It's weird, I know. But that's what the ATMega32 wants.
    TIFR |= (1 << TOV0);

    // Reset the Watchdog Timer
    asm volatile("wdr"::);
}

void wait_timer()
{
    // Check the Timer/Counter Overflow Flag (TOV) until it enables,
    // indicating that the timer reached it's end.
    while (!(TIFR & (! << TOV0)));
}

void stop_timer()
{
    // Clock Select: Turn off the 8-bit timer.
    TCCR0 = 0x00;
}
