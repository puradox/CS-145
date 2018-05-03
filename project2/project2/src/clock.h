#ifndef CLOCK_H
#define CLOCK_H

#include "state.h"

const int CLOCKS_PER_SEC = 1000 / MS_PER_CLOCK;

const char DAYS_PER_MONTH[12] = {
    31, // Jan
    28, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31, // Dec
};

const char DAYS_PER_MONTH_LEAP_YEAR[12] = {
    31, // Jan
    29, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31, // Dec
};

void clock_start(struct state *);
void clock_tick(struct state *);
char is_leap_year(int year);
char days_in_month(int month, int year);

#endif
