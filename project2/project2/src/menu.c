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
        s->next_menu = edit_month_pressed;
        break;
    case KEY_D:
        s->next_menu = edit_second_pressed;
        break;
    }
}

void edit_none_pressed(struct state *s)
{
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
            s->next_menu = edit_day_pressed(s);
            increment_day(s);
            break;
        case KEY_C:
            s->next_menu = edit_day_pressed(s);
            decrement_day(s);
            break;
        case KEY_D:
            s->next_menu = edit_month_pressed;
            break;
    }
}

void edit_day_pressed(struct state *s)
{
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
        s->next_menu = edit_year_pressed(s);
        increment_year(s);
        break;
    case KEY_C:
        s->enxt_menu = edit_year_pressed(s);
        decrement_year(s);
        break;
    case KEY_D:
        s->next_menu = edit_day_pressed;
        break;
    }
}

void edit_year_pressed(struct state *s)
{
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
        s->next_menu = edit_hour_pressed(s);
        increment_hour(s);
        break;
    case KEY_C:
        s->next_menu = edit_hour_pressed(s);
        decrement_hour(s);
        break;
    case KEY_D:
        s->next_menu = edit_year_pressed;
        break;
    }
}

void edit_hour_pressed(struct state *s)
{
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
    switch(s->key_pressed)
    {
        case KEY_NONE:
            s->next_menu = edit_second;
            break;
    }
}