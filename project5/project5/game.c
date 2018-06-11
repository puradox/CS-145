#include "game.h"
#include "state.h"
#include <stdlib.h>

void game_start(struct state *s)
{
    for (int i = 0; i < 16; i++)
        s->row1[i] = ' ';

    s->row2[0] = PLAYER;
    for (int i = 1; i < 16; i++)
        s->row2[i] = ' ';

    s->ticks_since_last_block = 4; // display is last
	s->ticks_until_next_block = ((uint8_t)rand() & 0x07) + 4; // 4 - 11
    s->ticks_played = 0;
    s->game_over = false;
    s->next_game = game_play;
}

void game_play(struct state *s)
{
    if (detect_player_block_collision(s))
    {
        s->game_over = true;
        s->next_game = game_start;
        return;
    }

	if (s->ticks_since_last_block == s->ticks_until_next_block)
	{
		s->ticks_since_last_block = 0;
		
		if ((uint8_t)rand() > 100)
		{
				move_row_left(s->row1, ' ');
			    move_row_left(s->row2, BLOCK);
				s->ticks_until_next_block = ((uint8_t)rand() & 0x07) + 4; // 4 to 11
		}
		else
		{
				move_row_left(s->row1, BLOCK);
				move_row_left(s->row2, ' ');
				s->ticks_until_next_block = ((uint8_t)rand() & 0x03) + 3; // 3 to 6
		}
	}
	else
	{
		move_row_left(s->row1, ' ');
		move_row_left(s->row2, ' ');
		++s->ticks_since_last_block;
	}
	
    s->ticks_played++;
    display_game(s);
}

void move_row_left(char *screen, char new_column)
{
    for (int i = 0; i < ROW_SIZE - 1; ++i)
        if (screen[i] != PLAYER)
            screen[i] = screen[i + 1];

    screen[ROW_SIZE - 1] = new_column;
}

bool detect_player_block_collision(struct state *s)
{
    if (s->row1[0] == PLAYER) // top row
    {
        return s->row1[1] == BLOCK;
    }
    if (s->row2[0] == PLAYER) // bottom row
    {
        return s->row2[1] == BLOCK;
    }
}

void display_game(struct state *s)
{
    pos_lcd(0, 0);
    puts_lcd2(s->row1);

    pos_lcd(1, 0);
    puts_lcd2(s->row2);
}
