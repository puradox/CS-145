#ifndef MENU_H
#define MENU_H

#include "state.h"

void menu_start(struct state *);

void edit_none(struct state *);
void edit_month(struct state *);
void edit_day(struct state *);
void edit_year(struct state *);
void edit_hour(struct state *);
void edit_minute(struct state *);
void edit_second(struct state *);

#endif
