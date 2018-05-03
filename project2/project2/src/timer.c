#include "timer.h"

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>

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
    // The 8-bit timer will increment every 64 clock cycles.
    TCCR0 = 0x03;
}

void reset_timer0(double ms)
{
    // Reset this 8-bit Timer/Counter Register to just below the
    // number of cycles needed to overflow from the given duration.
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001 * ms);

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
    // Clock Select: Turn off this 8-bit timer.
    TCCR0 = 0x00;
}

/* Timer/Counter 1 is a bit different than the others
   and requires more work to get working. If you need to
   use this timer, find a way to finish the following
   functions:

//
// 16-bit Timer/Counter 1
//

void ini_timer1()
{
    // Clock Select (CS12, CS11, CS10): clk/64
    // This 16-bit timer will increment every 64 clock cycles.
    TCCR1 = 0x03;
}

void reset_timer1(double ms)
{
    // Reset this 16-bit Timer/Counter Register to just below the
    // number of cycles needed to overflow from the given duration.
    TCNT1 = (unsigned short)(65536 - (XTAL_FRQ / 64) * 0.001 * ms);

    // Set the Timer/Counter Overflow Flag (TOV) to clear it.
    // It's weird, I know. But that's what the ATMega32 wants.
    TIFR |= (1 << TOV1);
}

void wait_timer1()
{
    // Check the Timer/Counter Overflow Flag (TOV) until it enables,
    // indicating that the timer reached it's end.
    while (!(TIFR & (1 << TOV1)));
}

void stop_timer1()
{
    // Clock Select: Turn off this 16-bit timer.
    TCCR1 = 0x00;
}

*/

//
// 8-bit Timer/Counter 2
//

void ini_timer2()
{
    // Clock Select (CS22, CS21, CS20): clk/64
    // This 8-bit timer will increment every 64 clock cycles.
    TCCR2 = 0x03;
}

void reset_timer2(double ms)
{
    // Reset this 8-bit Timer/Counter Register to just below the
    // number of cycles needed to overflow from the given duration.
    TCNT2 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001 * ms);

    // Set the Timer/Counter Overflow Flag (TOV) to clear it.
    TIFR |= (1 << TOV2);
}

void wait_timer2()
{
    // Check the Timer/Counter Overflow Flag (TOV) until it enables,
    // indicating that the timer reached it's end.
    while (!(TIFR & (1 << TOV2)));
}

void stop_timer2()
{
    // Clock Select: Turn off this 8-bit timer.
    TCCR2 = 0x00;
}
