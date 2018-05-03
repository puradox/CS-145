#ifndef TIMER_H
#define TIMER_H

#define XTAL_FRQ 8000000lu

//
// The ATMega32 contains 3 timers at our disposal.
// Use the corresponding functions to configure them.
//

void ini_timers(void);
void stop_timers(void);

// 8-bit Timer/Counter 0
void ini_timer0(void);
void reset_timer0(double ms);
void wait_timer0(void);
void stop_timer0(void);

// 16-bit Timer/Counter 1
void ini_timer1(void);
void reset_timer1(double ms);
void wait_timer1(void);
void stop_timer1(void);

// 8-bit Timer/Counter 2
void ini_timer2(void);
void reset_timer2(double ms);
void wait_timer2(void);
void stop_timer2(void);

#endif
