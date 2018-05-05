#include "military.h"

void military_start(struct state *s)
{
    s->next_military = military_off_up;
}

void military_off_down(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_NONE:
        s->next_military = military_off_up;
        break;
    default:
        break;
    }
}

void military_off_up(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_POUND:
        s->is_military_time = 1;
        s->next_military = military_on_down;
        break;
    default:
        break;
    }
}

void military_on_down(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_NONE:
        s->next_military = military_on_up;
        break;
    default:
        break;
    }
}

void military_on_up(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_POUND:
        s->is_military_time = 0;
        s->next_military = military_off_down;
        break;
    default:
        break;
    }
}
