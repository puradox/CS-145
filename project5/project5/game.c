#include "game.h"

void menu(struct state* s)
{
	// TODO: print("press 1 to play!")
	if (is_key_pressed(KEY_1))
	{
		//s->game_state = play;
	}
}

void play(struct state* s)
{
	/*
	if (is_key_pressed(KEY_A) && s->jump == ready)
	{
		s->jump = begin_jump;
	}
		
	s->jump(&s);
*/
	if (detect_player_block_collision(*s))
	{
		s->game_state = game_over;
	}

	move_row_left(s->row1, ' ', !s->player_in_bottom);
	
	if (decide_if_block(s->ticks_since_last_block))
	{
		move_row_left(s->row2, 'B', s->player_in_bottom);
		s->ticks_since_last_block = 0;
	}
	else
	{
		move_row_left(s->row2, ' ', s->player_in_bottom);
		++s->ticks_since_last_block;
	}
	
	++s->ticks_played;
	display_game(s);
}

void game_over(struct state* s)
{
	char buffer[16];
	sprintf(buffer, "GG");
	pos_lcd(0,0);
	puts_lcd2(buffer);
	
	char buffer2[16];
	sprintf(buffer2, "u ran %3i steps!", s->ticks_played);
	pos_lcd(1,0);
	puts_lcd2(buffer2);
}


void move_row_left(char* screen, char new_column, bool player_in_row)
{
	if (player_in_row)
	{
		screen[0] = 'P';
	}
	else
	{
		screen[0] = screen[1];
	}
	
	for (int i=1; i < ROW_SIZE-1; ++i)
	{
		screen[i] = screen[i+1];
	}
	screen[ROW_SIZE-1] = new_column;
}

bool decide_if_block(int ticks_since_block)
{
	return ticks_since_block > 3;
}

bool detect_player_block_collision(struct state s)
{
	if (s.player_in_bottom)
	{
		return s.row2[1] == 'B';
	}
	else
	{
		return s.row1[1] == 'B';
	}
}

void display_game(struct state* s)
{
	pos_lcd(0,0);
	puts_lcd2(s->row1);
	
	pos_lcd(1,0);
	puts_lcd2(s->row2);
}