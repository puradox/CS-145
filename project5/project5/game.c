#include "game.h"

void game_menu(struct state *s)
{
    // TODO: print("press 1 to play!")
    if (is_key_pressed(KEY_1))
    {
        //s->next_game = game_play;
    }
}

void game_play(struct state *s)
{
    if (detect_player_block_collision(s))
    {
        s->next_game = game_over;
    }

    move_row_left(s->row1, ' ');

    if (decide_if_block(s->ticks_since_last_block))
    {
        move_row_left(s->row2, 'B');
        s->ticks_since_last_block = 0;
    }
    else
    {
        move_row_left(s->row2, ' ');
        ++s->ticks_since_last_block;
    }

    s->ticks_played++;
    display_game(s);
}

void game_over(struct state *s)
{
    char buffer[16];
    sprintf(buffer, "GG");
    pos_lcd(0, 0);
    puts_lcd2(buffer);

    char buffer2[16];
    sprintf(buffer2, "u ran %3i steps!", s->ticks_played);
    pos_lcd(1, 0);
    puts_lcd2(buffer2);
}

void move_row_left(char *screen, char new_column)
{
    for (int i = 0; i < ROW_SIZE - 1; ++i)
        if (screen[i] != 'P')
            screen[i] = screen[i + 1];

    screen[ROW_SIZE - 1] = new_column;
}

bool decide_if_block(int ticks_since_block)
{
    return ticks_since_block == 7;
}

bool detect_player_block_collision(struct state *s)
{
    if (s->row1[0] == 'P') // top row
    {
        return s->row1[1] == 'B';
    }
    if (s->row2[0] == 'P') // bottom row
    {
        return s->row2[1] == 'B';
    }
}

void display_game(struct state *s)
{
    pos_lcd(0, 0);
    puts_lcd2(s->row1);

    pos_lcd(1, 0);
    puts_lcd2(s->row2);
}
