#include "menu.h"
#include "keypad.h"
#include "date_utils.h"

void menu_start(struct state *s)
{
    s->editing = 0;
    s->next_menu = edit_none;
}

void edit_none(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_month;
        default: break;
    }
}

void edit_month(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_day;
        case KEY_B : increment_month(s);
        case KEY_C : decrement_month(s);
        case KEY_D : s->next_menu = edit_none;
        default: break;
    }
}

void edit_day(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_year;
        case KEY_B : increment_day(s);
        case KEY_C : decrement_day(s);
        case KEY_D : s->next_menu = edit_none;
        default: break;
    }
}

void edit_year(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_hour;
        case KEY_B : increment_year(s);
        case KEY_C : decrement_year(s);
        case KEY_D : s->next_menu = edit_none;
        default: break;
    }
}

void edit_hour(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_minute;
        case KEY_B : increment_hour(s);
        case KEY_C : decrement_hour(s);
        case KEY_D : s->next_menu = edit_second;
        default: break;
    }
}

void edit_second(struct state *)
{
    switch (s->key_pressed)
    {
        case KEY_A : s->next_menu = edit_none;
        case KEY_B: increment_second(s);
        case KEY_C: decrement_second(s);
        case KEY_D: s->next_menu = edit_none;
        default: break;
    }
}
