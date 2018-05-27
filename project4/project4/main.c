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


int main(void)
{
	// next step: timer0 calling
	ini_avr();
	ini_lcd();
	
	pos_lcd(0, 0);
	puts_lcd2("workin =p");
	
    /* Replace with your application code */
    while (1) 
    {
		if (is_key_pressed(KEY_A))
		{
				pos_lcd(0, 0);
				puts_lcd2("a pressed =p");
		}

    }
}

