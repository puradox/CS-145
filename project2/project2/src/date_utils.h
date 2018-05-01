#ifndef DATE_UTILS_H
#define DATE_UTILS_H

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

char is_leap_year(int year);
char days_in_month(int month, int year);

#endif
