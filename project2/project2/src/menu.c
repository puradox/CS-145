#include "menu.h"
#include "date_utils.h"

void menu_start(struct state *s)
{
    s->is_menu_on = 0;
    s->next_menu = edit_none;
}

void edit_none(struct state *s)
{
    if (s->A)
    {
        s->next_menu = edit_month_pressed;
        s->is_menu_on = 1;
    }
    if (s->D)
    {
        s->next_menu = edit_second_pressed;
        s->is_menu_on = 1;
    }
}

void edit_none_pressed(struct state *s)
{
    s->is_menu_on = 0;

    if (!s->A && !s->B)
        s->next_menu = edit_none;
}

void edit_month(struct state *s)
{
    if (s->A)
        s->next_menu = edit_day_pressed;
    if (s->B)
        increment_month(s);
    if (s->C)
        decrement_month(s);
    if (s->D)
        s->next_menu = edit_none_pressed;
}

void edit_month_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 2;

    if (!s->A && !s->B)
        s->next_menu = edit_month;
}

void edit_day(struct state *s)
{
    if (s->A)
        s->next_menu = edit_year_pressed;
    if (s->B)
        increment_day(s);
    if (s->C)
        decrement_day(s);
    if (s->D)
        s->next_menu = edit_month_pressed;
}

void edit_day_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 5;

    if (!s->A && !s->B)
        s->next_menu = edit_day;
}

void edit_year(struct state *s)
{
    if (s->A)
        s->next_menu = edit_hour_pressed;
    if (s->B)
        increment_year(s);
    if (s->C)
        decrement_year(s);
    if (s->D)
        s->next_menu = edit_day_pressed;
}

void edit_year_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 11;

    if (!s->A && !s->B)
        s->next_menu = edit_year;
}

void edit_hour(struct state *s)
{
    if (s->A)
        s->next_menu = edit_minute_pressed;
    if (s->B)
        increment_hour(s);
    if (s->C)
        decrement_hour(s);
    if (s->D)
        s->next_menu = edit_year_pressed;
}

void edit_hour_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 1;

    if (!s->A && !s->B)
        s->next_menu = edit_hour;
}

void edit_minute(struct state *s)
{
    if (s->A)
        s->next_menu = edit_second_pressed;
    if (s->B)
        increment_minute(s);
    if (s->C)
        decrement_minute(s);
    if (s->D)
        s->next_menu = edit_hour_pressed;
}

void edit_minute_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 4;

    if (!s->A && !s->B)
        s->next_menu = edit_minute;
}

void edit_second(struct state *s)
{
    if (s->A)
        s->next_menu = edit_none_pressed;
    if (s->B)
        increment_second(s);
    if (s->C)
        decrement_second(s);
    if (s->D)
        s->next_menu = edit_minute_pressed;
}

void edit_second_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 7;

    if (!s->A && !s->B)
        s->next_menu = edit_second;
}
