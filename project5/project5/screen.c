#include "screen.h"
#include "game.h"

void print_intro()
{
}

void print_controls()
{
}

void print_pause()
{
}

void print_gameover()
{
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
        s->next_screen = screen_game;
}

void screen_game(struct state *s)
{
    if (s->key_D)
    {
        print_pause();
        s->next_screen = screen_pause;
    }
    else
    {
        s->next_game(s);
    }
}

void screen_pause(struct state *s);
{
    // TODO(Sam): if there is time
}

void screen_gameover(struct state *s)
{
    if (s->key_A)
        s->next_screen = screen_gameover_down;
}

void screen_gameover_down(struct state *s)
{
    if (!s->key_A)
    {
        print_intro();
        s->next_screen = screen_intro;
    }
}
