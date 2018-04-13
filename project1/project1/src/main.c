#include <asf.h>
#include "avr.h"

#define CLOCK_MHZ 1

struct state;
typedef void state_fn(struct state*);

struct state 
{
	void (*next)(struct state*);
	unsigned char button;
	unsigned char counter;
	unsigned char led_on;
};

state_fn start, down_on, down_off, up_on, up_off, wind_down;

void start(struct state *state)
{
	if (state->button)
	{
		state->next = down_on;
		state->led_on = 1;
	}
}

void down_on(struct state *state)
{
	state->counter++;
		
	if (!state->button)
		state->next = up_on;
	
	if (state->counter > 10)
	{
		state->next = down_off;
		state->counter = 0;
		state->led_on = 0;
	}
}

void down_off(struct state *state)
{
	state->counter++;

	if (!state->button)
		state->next = up_off;
	
	if (state->counter > 10)
	{
		state->next = down_on;
		state->counter = 0;
		state->led_on = 1;
	}
}

void up_on(struct state *state)
{
	state->counter++;
	
	if (state->button)
	{
		state->next = wind_down;
		state->counter = 0;
		state->led_on = 0;
	}
		
	if (state->counter > 10)
	{
		state->next = up_off;
		state->counter = 0;
		state->led_on = 0;
	}
}

void up_off(struct state *state)
{
	state->counter++;
	
	if (state->button)
	{
		state->next = wind_down;
		state->counter = 0;
	}
	
	if (state->counter > 10)
	{
		state->next = up_on;
		state->counter = 0;
		state->led_on = 1;
	}
}

void wind_down(struct state *state)
{	
	if (!state->button)
		state->next = start;
}

void wait(unsigned short ms)
{
	/*
	volatile uint32_t counter = 0;
	uint32_t loops = CLOCK_MHZ * 100 * ms / 3;
	while (counter < loops)
		counter++;
	*/
	wait_avr(ms);
}

int main()
{
	// Initialize
	board_init();
	ini_avr();
	
	// Configure GPIO pins
	DDRB |= (1 << 0);	// B0 is an output
	DDRB &= ~(1 << 1);	// B1 is an input
	
	// Blink that damn LED
	struct state s = { start, 0, 0, 0 };
	while (s.next)
	{
		s.button = PINB & (1 << 1);
		s.next(&s);
		
		if (s.led_on)
			PORTB |= 1;
		else
			PORTB &= ~1;
			
		wait_avr(5);
	}

	return 0;
}
