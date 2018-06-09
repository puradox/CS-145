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
#include "state.h"
#include "game.h"

struct state s;
//char buffer[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'e'};
// int i = 0;

void display_game()
{
	pos_lcd(0,0);
	puts_lcd2(s.row1);
	
	pos_lcd(1,0);
	puts_lcd2(s.row2);
}

int main(void)
{
	
	ini_lcd();
		
	s = make_state();

	timer1_start(200);
		
	
    /* Replace with your application code */
    while (1) 
    {
	}
}

TIMER1_TICK()
{
	
	display_game();
	s = generate_and_move(s,true);
	
}