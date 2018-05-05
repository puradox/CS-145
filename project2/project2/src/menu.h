#ifndef MENU_H
#define MENU_H

#include "state.h"
#include "keypad.h"
#include "clock.h"

void menu_start(struct state *);

void edit_none(struct state *);
void edit_month(struct state *);
void edit_day(struct state *);
void edit_year(struct state *);
void edit_hour(struct state *);
void edit_minute(struct state *);
void edit_second(struct state *);

void increment_month(struct state *);
void increment_day(struct state *);
void increment_year(struct state *);
void increment_hour(struct state *);
void increment_minute(struct state *);
void increment_second(struct state *);

void decrement_month(struct state *);
void decrement_day(struct state *);
void decrement_year(struct state *);
void decrement_hour(struct state *);
void decrement_minute(struct state *);
void decrement_second(struct state *);

#endif
