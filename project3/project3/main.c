#include <avr/io.h>
#include <avr/wdt.h>


int main(void)
{
    // Enable the Watchdog timer to restart the program after 1 second
    // of inactivity. This is to ensure the program does not hang.
    wdt_enable(WDTO_1S);

    while (1)
    {
        wdt_reset();
    }
}

