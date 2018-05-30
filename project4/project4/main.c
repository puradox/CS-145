 #include <avr/io.h>
#include <avr/wdt.h>

#include "keypad.h"
#include "lcd.h"
#include "timer.h"
#include "state.h"

static struct state s;
char running = 1;

int main(void)
{
	// next step: timer0 calling
	ini_avr();
	ini_lcd();
	
	timer0_start();
	s = make_state(measuring);
	
	ADCSRA |= (1 << ADEN);
	ADMUX |= (1 << REFS0);
		
    while (running) 
    {
    }
}

int i = 0;


TIMER0_TICK()
{
	/*
	s.measure(&s);
	char* buffer[8];
]	sprintf(buffer, "%i", s.measured_voltage);
	pos_lcd(0, 0);
	puts_lcd2(buffer);
	*/
	if ((ADCSRA & 64) == 0) {
		ADCSRA |= (1 << ADSC); // automatically cleared when done
	
		// display adc
		char* buffer[8];
		sprintf(buffer, "%i", ADC);
		pos_lcd(0, 0);
		puts_lcd2(buffer);
		
		// display tick count
		char* buffer2[8];
		sprintf(buffer2, "     %i", i);
		pos_lcd(0, 0);
		puts_lcd2(buffer2);
		++i;
	}
}


