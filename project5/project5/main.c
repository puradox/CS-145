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
#include "jump.h"

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
		
	s = make_state(ready);

	timer1_start(1000);
		
	
    /* Replace with your application code */
    while (1) 
    {
	}
}

TIMER1_TICK()
{	
	if (!s.gg)
	{
		if (is_key_pressed(KEY_A) && s.jump == ready)
		{
			s.jump = begin_jump;
		}
	
		s.jump(&s);
		s = generate_and_move(s);
		// detect right after move
		display_game();
	}
	else
	{
		char buffer[8];
		sprintf(buffer, "GG");
		pos_lcd(0,0);
		puts_lcd2(buffer);
	}
}