#include "menu.h"
#include "keypad.h"
#include "date_utils.h"

void menu_start(struct state *s)
{
    s->is_menu_on = 0;
    s->next_menu = edit_none;
}

void edit_none(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_month_pressed;
        s->is_menu_on = 1;
        break;
    case KEY_D:
        s->next_menu = edit_second_pressed;
        s->is_menu_on = 1;
        break;
    }
}

void edit_none_pressed(struct state *s)
{
    s->is_menu_on = 0;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_none;
            break;
    }
}

void edit_month(struct state *s)
{
    switch (s->key_pressed)
    {
        case KEY_A:
            s->next_menu = edit_day_pressed;
            break;
        case KEY_B:
            s->next_menu = edit_month_pressed;
            increment_month(s);
            break;
        case KEY_C:
            s->next_menu = edit_month_pressed;
            decrement_month(s);
            break;
        case KEY_D:
            s->next_menu = edit_none_pressed;
            break;
    }
}

void edit_month_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 2;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_month;
            break;
    }
}

void edit_day(struct state *s)
{
    switch (s->key_pressed)
    {
        case KEY_A:
            s->next_menu = edit_year_pressed;
            break;
        case KEY_B:
            s->next_menu = edit_day_pressed;
            increment_day(s);
            break;
        case KEY_C:
            s->next_menu = edit_day_pressed;
            decrement_day(s);
            break;
        case KEY_D:
            s->next_menu = edit_month_pressed;
            break;
    }
}

void edit_day_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 5;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_day;
            break;
    }
}

void edit_year(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_hour_pressed;
        break;
    case KEY_B:
        s->next_menu = edit_year_pressed;
        increment_year(s);
        break;
    case KEY_C:
        s->next_menu = edit_year_pressed;
        decrement_year(s);
        break;
    case KEY_D:
        s->next_menu = edit_day_pressed;
        break;
    }
}

void edit_year_pressed(struct state *s)
{
    s->cursor_row = 0;
    s->cursor_col = 11;

    switch (s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_year;
            break;
    }
}

void edit_hour(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_minute_pressed;
        break;
    case KEY_B:
        s->next_menu = edit_hour_pressed;
        increment_hour(s);
        break;
    case KEY_C:
        s->next_menu = edit_hour_pressed;
        decrement_hour(s);
        break;
    case KEY_D:
        s->next_menu = edit_year_pressed;
        break;
    }
}

void edit_hour_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 1;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_hour;
            break;
    }
}

void edit_minute(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_second_pressed;
        break;
    case KEY_B:
        s->next_menu = edit_minute_pressed;
        increment_minute(s);
        break;
    case KEY_C:
        s->next_menu = edit_minute_pressed;
        decrement_minute(s);
        break;
    case KEY_D:
        s->next_menu = edit_hour_pressed;
        break;
    }
}

void edit_minute_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 4;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_minute;
            break;
    }
}

void edit_second(struct state *s)
{
    switch (s->key_pressed)
    {
    case KEY_A:
        s->next_menu = edit_none_pressed;
        break;
    case KEY_B:
        s->next_menu = edit_second_pressed;
        increment_second(s);
        break;
    case KEY_C:
        s->next_menu = edit_second_pressed;
        decrement_second(s);
        break;
    case KEY_D:
        s->next_menu = edit_minute_pressed;
        break;
    }
}

void edit_second_pressed(struct state *s)
{
    s->cursor_row = 1;
    s->cursor_col = 7;

    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_second;
            break;
    }
}
