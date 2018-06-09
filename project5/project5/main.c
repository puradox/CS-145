/*
 * project5.c
 *
 * Created: 6/6/2018 11:20:45 PM
 * Author : Sam
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "keypad.h"
#include "timer.h"
#include "game.h"

char buffer[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'e'};
// int i = 0;
int main(void)
{
	
	ini_lcd();
		
	timer1_start(500);
		
	
    /* Replace with your application code */
    while (1) 
    {
	}
}

TIMER1_TICK()
{
	move_screen_left(buffer, 8);
	
	
	//sprintf(buffer, "starting");
	pos_lcd(0,0);
	puts_lcd2(buffer);
	pos_lcd(1,0);
	
	/* to test for program crashes
	char buffer2[8];
	sprintf(buffer2, "%i", i);
	puts_lcd2(buffer2);
	++i; */
}