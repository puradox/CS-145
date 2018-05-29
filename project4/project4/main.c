/*
 * project4.c
 *
 * Created: 5/24/2018 11:20:16 AM
 * Author : David
 */ 

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
	
    while (running) 
    {
    }
}


TIMER0_TICK()
{
	s.measure(&s);
	char* buffer[8];
	sprintf(buffer, "%i", s.measured_voltage);
	pos_lcd(0, 0);
	puts_lcd2(buffer);
}


