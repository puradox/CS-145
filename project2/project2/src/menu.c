#include "menu.h"

void menu_start(struct state *s)
{
    s->editing = 0;
    s->next_menu = menu_controller;
}

void menu_controller(struct state *s)
{
    switch (s->key_pressed)
    {
        case KEY_A : advance_option(s);
        case KEY_B : increment_selected(s);
        case KEY_C : decrement_selected(s);
        case KEY_D : turn_menu_off(s);
        default: ;
    }
}

void advance_option(struct state *s)
{
    s->editing += 1;
    s->editing %= 7;
}

void increment_selected(struct state *s)
{
    switch (s->editing)
    {
        case 0: ;
        case 1: increment_month(s);
        case 2: increment_day(s);
        case 3: increment_year(s);
        case 4: increment_hour(s);
        case 5: increment_minute(s);
        case 6: increment_second(s);
    }
}

void turn_menu_off(struct state *s)
{
    s->editing =0;
}

void increment_month(struct state *s)
{
    s->month++;
    if (s->month >= 12) {
        increment_year(s);
        s->month -= 11;
    }
}

void increment_day(struct state *s)
{
    s->day++;
    int days_month = days_in_month(s->month, s->year);
    if (s->day >= days_month) {
        increment_month(s);
        s->day -= days_month;
    }
}

void increment_year(struct state *s)
{
    s->year++;
}

void increment_hour(struct state *s)
{
    s->hour++;
    if (s->hour >= 24) {
        increment_day(s);
        s->hour -= 24;
    }
}

void increment_minute(struct state *s)
{
    s->minute++;
    if (s->minute >= 60) {
        increment_hour(s);
        s->minute -= 60;
    }
}

void increment_second(struct state *s)
{
    s->second++;
    if (s->minute >= 60) {
        increment_minute(s);
        s->second -= 60;
    }
}