#ifndef TIMER_H
#define TIMER_H

#define XTAL_FRQ 8000000lu

//
// The ATMega32 contains 3 timers at our disposal.
// Use the corresponding functions to configure them.
//

enum timer_frequency {
    TIMER_OFF = 1,
    CLK_DIVIDED_BY_8,
    CLK_DIVIDED_BY_64,
    CLK_DIVIDED_BY_256,
    CLK_DIVIDED_BY_1024,
};

void ini_timers(void);
void stop_timers(void);

// 8-bit Timer/Counter 0
// Recommended to set the timer between 1 and 2047 microseconds.
// Set the timer in multiples of 8 for the best accuracy.
void ini_timer0(void);
void reset_timer0(unsigned short us);
void wait_timer0(void);
void stop_timer0(void);
void sleep_timer0(unsigned short us);

// 16-bit Timer/Counter 1
// Recommended to set the timer between 1 and 524 milliseconds.
void ini_timer1(void);
void reset_timer1(unsigned short ms);
void wait_timer1(void);
void stop_timer1(void);
void sleep_timer1(unsigned short ms);

// 8-bit Timer/Counter 2
// Recommended to set the timer between 1 and 2047 microseconds.
// Set the timer in multiples of 8 for the best accuracy.
void ini_timer2(void);
void reset_timer2(unsigned short us);
void wait_timer2(void);
void stop_timer2(void);
void sleep_timer2(unsigned short us);

#endif
