#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "lcd.h"

#define MAX_VOLTAGE 5.0  // maximum voltage obtained by the ADC
#define MAX_ADC 1023.0   // maximum value of the ADC return value
#define VOLTAGES_SIZE 10 // how many voltages should be stored for avg, min, max

#define TO_VOLTS(value) MAX_VOLTAGE * (double)(value) / MAX_ADC

void display_start(struct state *s)
{
    s->voltages = calloc(VOLTAGES_SIZE, sizeof(unsigned short));
    s->cursor = 0;
    s->count = 0;
    s->sum = 0;
    s->next_display = display_update;
}

void display_update(struct state *s)
{
    uint16_t curr = s->measured_voltage;
    uint16_t prev = s->voltages[s->cursor];

    s->sum += curr - prev;
    s->voltages[s->cursor] = curr;
    s->cursor += (s->cursor + 1) % VOLTAGES_SIZE;

    if (s->count < VOLTAGES_SIZE)
        s->count++;

    // Calcuate statistics
    double avg = (double)s->sum / (double)s->count;
    uint16_t min = s->voltages[0];
    uint16_t max = s->voltages[0];
    for (int i = 1; i < s->count; ++i)
    {
        if (s->voltages[i] < min)
            min = s->voltages[i];
        if (s->voltages[i] > max)
            max = s->voltages[i];
    }

    // Print to the LCD
    char row_text[16];

    pos_lcd(0, 0);
    sprintf(row_text, "Cur %3.1f Avg %3.1f", TO_VOLTS(curr), TO_VOLTS(avg));
    puts_lcd2(row_text);

    pos_lcd(1, 0);
    sprintf(row_text, "Min %3.1f Max %3.1f", TO_VOLTS(min), TO_VOLTS(max));
    puts_lcd2(row_text);
}
