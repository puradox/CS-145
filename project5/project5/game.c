#include "game.h"


struct state generate_and_move(struct state s)
{
	move_row_left(s.row1, ' ');
		
	if (decide_if_block(s.ticks_since_last_block))
	{
		move_row_left(s.row2, 'B');
		s.ticks_since_last_block = 0;
	}
	else
	{
		move_row_left(s.row2, ' ');
		++s.ticks_since_last_block;
	}
	
	return s;
}

move_row_left(char* screen, char new_column)
{
	for (int i=0; i < ROW_SIZE-1; ++i)
	{
		screen[i] = screen[i+1];
	}
	screen[ROW_SIZE-1] = new_column;
}

bool decide_if_block(int ticks_since_block)
{
	return ticks_since_block > 3;
}