#include "game.h"


move_row_left(char* screen)
{
	
	for (int i=0; i < ROW_SIZE -1; ++i)
	{
		screen[i] = screen[i+1];
	}
}