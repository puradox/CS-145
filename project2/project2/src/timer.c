#include <avr/io.h>
#include "timer.h"

//
// For all timers
//

void ini_timers()
{
    ini_timer0();
    ini_timer1();
    ini_timer2();
}

void stop_timers()
{
    stop_timer0();
    stop_timer1();
    stop_timer2();
}

//
// 8-bit Timer/Counter 0
//

void ini_timer0()
{
    // Clock Select (CS02, CS01, CS00): clk/64
    // The 8-bit counter will increment every 64 clock cycles.
    TCCR0 = CLK_DIVIDED_BY_64;
}

void reset_timer0(unsigned short us)
{
    // Reset this 8-bit Timer/Counter Register to just below the
    // number of cycles needed to overflow from the given duration.
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * (0.000001 * us));

    // Set the Timer/Counter Overflow Flag (TOV) to clear it.
    // It's weird, I know. But that's what the ATMega32 wants.
    TIFR |= (1 << TOV0);
}

void wait_timer0()
{
    // Check the Timer/Counter Overflow Flag (TOV) until it enables,
    // indicating that the timer reached it's end.
    while (!(TIFR & (1 << TOV0)));
}

void stop_timer0()
{
    // Turn the timer off
    TCCR0 = TIMER_OFF; // Clock Select
}

void sleep_timer0(unsigned short us)
{
    reset_timer0(us);
    wait_timer0();
}

//
// 16-bit Timer/Counter 1
//

void ini_timer1()
{
    TCCR1B = CLK_DIVIDED_BY_64; // Clock Select
}

void reset_timer1(unsigned short ms)
{
    TCNT1 = (unsigned short)(65536 - (XTAL_FRQ / 64) * 0.001 * ms); // Timer/Counter Register
    TIFR |= (1 << TOV1); // Timer/Counter Overflow Flag (TOV)
}

void wait_timer1()
{
    while (!(TIFR & (1 << TOV1))); // Timer/Counter Overflow Flag (TOV)
}

void stop_timer1()
{
    TCCR1B = TIMER_OFF; // Clock Select
}

void sleep_timer1(unsigned short ms)
{
    reset_timer1(ms);
    wait_timer1();
}

//
// 8-bit Timer/Counter 2
//

void ini_timer2()
{
    TCCR2 = CLK_DIVIDED_BY_64; // Clock Select
}

void reset_timer2(unsigned short us)
{
    TCNT2 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.000001 * us); // Timer/Counter Register
    TIFR |= (1 << TOV2); // Timer/Counter Overflow Flag (TOV)
}

void wait_timer2()
{
    while (!(TIFR & (1 << TOV2))); // Timer/Counter Overflow Flag (TOV)
}

void stop_timer2()
{
    TCCR2 = TIMER_OFF; // Clock Select
}

void sleep_timer2(unsigned short us)
{
    reset_timer2(us);
    wait_timer2();
}
