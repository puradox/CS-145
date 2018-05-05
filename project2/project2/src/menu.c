#include "menu.h"
#include "keypad.h"
#include "date_utils.h"

void menu_start(struct state *s)
{
    s->next_menu = edit_none;
}

void edit_none(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_month;
        break;
    }
}

void edit_year(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_hour;
        break;
    case KEY_B:
        increment_year(s);
        break;
    case KEY_C:
        decrement_year(s);
        break;
    case KEY_D:
        s->next_menu = edit_none;
        break;
    }
}

void edit_month(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_day;
        break;
    case KEY_B:
        increment_month(s);
        break;
    case KEY_C:
        decrement_month(s);
        break;
    case KEY_D:
        s->next_menu = edit_none;
        break;
    }
}

void edit_day(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_month;
        break;
    case KEY_B:
        increment_day(s);
        break;
    case KEY_C:
        decrement_day(s);
        break;
    case KEY_D:
        s->next_menu = edit_hour;
        break;
    }
}

void edit_hour(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_day;
        break;
    case KEY_B:
        increment_hour(s);
        break;
    case KEY_C:
        decrement_hour(s);
        break;
    case KEY_D:
        s->next_menu = edit_minute;
        break;
    }
}

void edit_minute(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_hour;
        break;
    case KEY_B:
        increment_minute(s);
        break;
    case KEY_C:
        decrement_minute(s);
        break;
    case KEY_D:
        s->next_menu = edit_second;
        break;
    }
}

void edit_second(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_minute;
        break;
    case KEY_B:
        increment_second(s);
        break;
    case KEY_C:
        decrement_second(s);
        break;
    case KEY_D:
        s->next_menu = edit_none;
        break;
    }
}
