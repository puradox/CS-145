#include "jump.h"
#include "game.h"
#include "player.h"
#include "song_list.h"

void jump_ready(struct state *s)
{
    if (s->key_A)
    {
        s->row1[0] = PLAYER;
        s->row2[0] = ' ';
        s->next_jump = jump_hover;
		player_change_song(s, song_coin);
    }
}

void jump_hover(struct state *s)
{
    if (s->jump_counter == 3)
    {
        s->row1[0] = ' ';
        s->row2[0] = PLAYER;
        s->jump_counter = 0;
        s->next_jump = jump_ready;
    }
    else
    {
        s->jump_counter++;
    }
}
