 #include <avr/io.h>
#include <avr/wdt.h>

#include "lcd.h"
#include "timer.h"
#include "state.h"

static struct state s;
char running = 1;

int main(void)
{
	// next step: timer0 calling
	//ini_avr();
	ini_lcd();
	
	s = make_state(measuring);
	
	ADCSRA |= (1 << ADEN);
	ADMUX |= (1 << REFS0);
	
	timer1_start(500);
		
    while (running) 
    {
    }
}


TIMER1_TICK()
{
	/*
	s.measure(&s);
	char* buffer[8];
]	sprintf(buffer, "%i", s.measured_voltage);
	pos_lcd(0, 0);
	puts_lcd2(buffer);
	*/
	
	if ((ADCSRA & (1 << ADSC)) == 0) {
		ADCSRA |= (1 << ADSC); // automatically cleared when done
	

		char* buffer[8];
		sprintf(buffer, "%4i", ADC);
		pos_lcd(0, 0);
		puts_lcd2(buffer);
		

	}
}


