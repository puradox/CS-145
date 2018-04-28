#ifndef TIMER_H
#define TIMER_H

#define XTAL_FRQ 8000000lu

void ini_timer();
void reset_timer(double ms);
void wait_timer();
void stop_timer();

#endif
