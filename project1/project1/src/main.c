#include <asf.h>
#include "avr.h"

#define CLOCK_MHZ 1

void wait(unsigned long ms)
{
	volatile uint32_t counter = 0;
	uint32_t loops = CLOCK_MHZ * 100 * ms / 3;
	while (counter < loops)
		counter++;
}

int main (void)
{
	board_init();
	
	// Configure GPIO pins
	DDRB |= (1 << 0);
	
	// Blink that damn LED
	for (;;)
	{
		PORTB |= (1 << 0);
		wait(500);
		PORTB &= ~(1 << 0);
		wait(500);
	}

}
