#ifndef TIMER_H
#define TIMER_H

#define CPU_FREQ 8000000lu

//
// The ATMega32 contains 3 timers at our disposal.
// Use the corresponding functions to configure them.
//

enum timer_frequency
{
    TIMER_OFF = 1,
    CLK_DIVIDED_BY_8,
    CLK_DIVIDED_BY_64,
    CLK_DIVIDED_BY_256,
    CLK_DIVIDED_BY_1024,
};

// TODO(Sam): Finish this when you need to use this timer.
//
// 8-bit Timer/Counter 0
// Recommended to set the timer between 1 and 2047 microseconds.
// Set the timer in multiples of 8 for the best accuracy.
//
// timer0_start(unsigned short us);
// timer0_stop();
//
// #define TIMER0_TICK() ISR(TIMER0_COMPA_vect)
//

//
// 16-bit Timer/Counter 1
// STRONGLY recommended to keep the timer between 1-524 milliseconds.
//
void timer1_start(unsigned short ms);
void timer1_stop(void);

#define TIMER1_TICK() ISR(TIMER1_COMPA_vect)

// TODO(Sam): Finish this when you need to use this timer.
//
// 8-bit Timer/Counter 2
// Recommended to set the timer between 1 and 2047 microseconds.
// Set the timer in multiples of 8 for the best accuracy.
//
// timer2_start(unsigned short us);
// timer2_stop();
//
// #define TIMER2_TICK() ISR(TIMER2_COMPA_vect)
//

#endif
