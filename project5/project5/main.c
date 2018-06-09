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
#include "state.h"

static struct state s;
//char buffer[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'e'};
// int i = 0;
int main(void)
{
	
	ini_lcd();
		
	timer1_start(500);
		
	s = make_state();
	
	
    /* Replace with your application code */
    while (1) 
    {
	}
}

TIMER1_TICK()
{
	
	
	pos_lcd(0,0);
	puts_lcd2(s.row1);
	
	pos_lcd(1,0);
	puts_lcd2(s.row2);
	
	move_row_left(s.row1);
	move_row_left(s.row2);


}