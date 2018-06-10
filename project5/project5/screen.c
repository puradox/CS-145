#include <stdio.h>
#include "screen.h"
#include "lcd.h"

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
        if (s->game_over)
        {
            print_game_over(s->ticks_played);
            s->next_screen = screen_game_over;
        }
        else
        {
            s->next_jump(s); // check for jump
            s->next_game(s); // game logic
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
        s->next_screen = screen_intro;
    }
}
