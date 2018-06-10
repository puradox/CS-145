#include <stdio.h>
#include "screen.h"
#include "lcd.h"
#include "player.h"
#include "song_list.h"

char buffer[16];

void print_intro()
{
    sprintf(buffer, "  @Mega Mario   ");
    pos_lcd(0, 0);
    puts_lcd2(buffer);

    sprintf(buffer, " by David & Sam ");
    pos_lcd(1, 0);
    puts_lcd2(buffer);
}

void print_controls()
{
    sprintf(buffer, "    Controls    ");
    pos_lcd(0, 0);
    puts_lcd2(buffer);

    sprintf(buffer, "Jump A | Pause B");
    pos_lcd(1, 0);
    puts_lcd2(buffer);
}

void print_pause(int score)
{
    sprintf(buffer, "     Pause      ");
    pos_lcd(0, 0);
    puts_lcd2(buffer);

    sprintf(buffer, "Score: %9i", score);
    pos_lcd(1, 0);
    puts_lcd2(buffer);
}

void print_game_over(int score)
{
    sprintf(buffer, "   Game over!   ");
    pos_lcd(0, 0);
    puts_lcd2(buffer);

    sprintf(buffer, "Score: %9i", score);
    pos_lcd(1, 0);
    puts_lcd2(buffer);
}

void screen_start(struct state *s)
{
    print_intro();
    player_change_song(s, song_mario_theme);
    s->next_screen = screen_intro;
}

void screen_intro(struct state *s)
{
    if (s->key_A)
        s->next_screen = screen_intro_down;
}

void screen_intro_down(struct state *s)
{
    if (!s->key_A)
    {
        print_controls();
        s->next_screen = screen_controls;
    }
}

void screen_controls(struct state *s)
{
    if (s->key_A)
        s->next_screen = screen_controls_down;
}

void screen_controls_down(struct state *s)
{
    if (!s->key_A)
    {
        s->next_game(s); // initialize game FSM state
        s->next_screen = screen_game;
    }
}

void screen_game(struct state *s)
{
    if (s->key_B)
    {
        print_pause(s->ticks_played);
        s->next_screen = screen_pause;
    }
    else
    {
        s->ticks_since_last_frame++;

        if (s->ticks_since_last_frame == 50)
        {
            s->next_jump(s); // check for jump
            s->next_game(s); // game logic

            if (s->game_over)
            {
                print_game_over(s->ticks_played);
                player_change_song(s, song_mario_game_over);
                s->next_screen = screen_game_over;
            }

            s->ticks_since_last_frame = 0;
        }
    }
}

void screen_pause(struct state *s)
{
    if (s->key_A)
        s->next_screen = screen_pause_down;
}

void screen_pause_down(struct state *s)
{
    if (!s->key_A)
        s->next_screen = screen_game;
}

void screen_game_over(struct state *s)
{
    if (s->key_A)
        s->next_screen = screen_game_over_down;
}

void screen_game_over_down(struct state *s)
{
    if (!s->key_A)
    {
        print_intro();
        player_change_song(s, song_mario_theme);
        s->next_screen = screen_intro;
    }
}
