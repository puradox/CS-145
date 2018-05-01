#include "menu.h"

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

void decrement_month(struct state *s)
{
    s->month--;
    if (s->month < 1) {
        decrement_year(s);
        s->month += 12;
    }
}

void decrement_day(struct state *s)
{
    s->day--;
    if (s->day < 1) {
        decrement_month(s);
        s->day = days_in_month(s->month, s->year);
    }
}

void decrement_year(struct state *)
{
    s->year--;
}

void decrement_hour(struct state *)
{
    s->hour--;
    if (s->hour < 0) { // 0 or 1?
        decrement_day(s);
        s->hour += 24;
    }
}

void decrement_minute(struct state *s)
{
    s->minute--;
    if (s->minute < 0) {
        decrement_hour(s);
        s->minute += 60;
    }
}

void decrement_second(struct state *s)
{
    s->second--;
    if (s->minute < 0) {
        decrement_minute(s);
        s->second += 60;
    }
}