#include "avr.h"

void ini_avr(void)
{
    // Enable the Watchdog Timer and configure it to timeout if it isn't
    // reset every 2.1 seconds.
    // Bit 3 - WDE: Watchdog Enable - Enable (binary 1)
    // Bit 2..0 - WDP: Watchdog Timer Prescaler - 2.1s (binary 111)
    WDTCR = 0x0F;
}

void wait_avr(unsigned short msec)
{
    TCCR0 = 3;
    while (msec--)
    {
        TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
        SET_BIT(TIFR, TOV0);
        WDR();
        while (!GET_BIT(TIFR, TOV0))
            ;
    }
    TCCR0 = 0;
}
