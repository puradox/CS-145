#include "date_utils.h"

char is_leap_year(int year)
{
    // A leap year extends February to 29 days, rather than the normal 28 days.
    // These extra days occur in years which are multiples of four
    // (with the exception of years divisible by 100 but not by 400).
    if (year % 100 == 0 && year % 400 != 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    else
        return 0;
}

char days_in_month(int month, int year)
{
    if (is_leap_year(year))
        return DAYS_PER_MONTH_LEAP_YEAR[month];
    else
        return DAYS_PER_MONTH[month];
}
