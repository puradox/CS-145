#include "game.h"


move_screen_left(char* screen, int size)
{
	
	for (int i=0; i < size -1; ++i)
	{
		screen[i] = screen[i+1];
	}
}