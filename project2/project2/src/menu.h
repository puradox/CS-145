#ifndef MENU_H
#define MENU_H

#include "state.h"

void menu_start(struct state *);
void menu_controller(struct state *);
void advance_option(struct state *);
void increment_selected(struct state *);
void decrement_selected(struct state *);
void turn_menu_off(struct state *);

void increment_month(struct state *);
void increment_day(struct state *);
void increment_year(struct state *);
void increment_hour(struct state *);
void increment_minute(struct state *);
void increment_second(struct state *);

// TODO (David): Complete the rest of the states


#endif
