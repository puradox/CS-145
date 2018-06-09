#include "game.h"


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