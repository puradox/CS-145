#ifndef AUDIO_H
#define AUDIO_H

#include <stdint.h>

void audio_on(void);
void audio_off(void);
void play_freq(uint16_t freq, uint16_t volume);

#endif
