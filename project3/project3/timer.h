#ifndef TIMER_H
#define TIMER_H

#include <avr/interrupt.h>

#define CPU_FREQ 8000000lu

//
// 8-bit Timer/Counter 0
//
// Clocked at 16ms per tick
//

enum timer0_frequency
{
    TIMER0_OFF = 0,
    TIMER0_CLK_1,
    TIMER0_CLK_8,
    TIMER0_CLK_64,
    TIMER0_CLK_256,
    TIMER0_CLK_1024,
};

void timer0_start(void);
void timer0_stop(void);

#define TIMER0_TICK() ISR(TIMER0_COMP_vect)


//
// 16-bit Timer/Counter 1
// STRONGLY recommended to keep the timer between 1-524 milliseconds.
//

enum timer1_frequency
{
    TIMER1_OFF = 0,
    TIMER1_CLK_1,
    TIMER1_CLK_8,
    TIMER1_CLK_64,
    TIMER1_CLK_256,
    TIMER1_CLK_1024,
};

void timer1_start(unsigned short ms);
void timer1_stop(void);

#define TIMER1_TICK() ISR(TIMER1_COMPA_vect)

// TODO(Sam): Finish this when you need to use this timer.
//
// 8-bit Timer/Counter 2
// Recommended to set the timer between 1 and 2047 microseconds.
// Set the timer in multiples of 8 for the best accuracy.
//

enum timer2_frequency
{
    TIMER2_OFF = 0,
    TIMER2_CLK_1,
    TIMER2_CLK_8,
    TIMER2_CLK_32,
    TIMER2_CLK_64,
    TIMER2_CLK_128,
    TIMER2_CLK_256,
    TIMER2_CLK_1024,
};

void timer2_start(void);
void timer2_stop(void);

#define TIMER2_TICK() ISR(TIMER2_COMP_vect)


#endif
