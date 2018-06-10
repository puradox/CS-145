#include "audio.h"
#include "lcd.h"
#include "musical_notes.h"
#include "player.h"

uint16_t duration_to_ms(uint8_t bpm, uint8_t duration)
{
    // SEC_IN_MIN * MS_IN_SEC / BPM / 64 * 1/64 notes = duration
    return (1875.0 * (double)duration) / (2.0 * (double)bpm);
}

void player_start(struct state *s)
{
    s->note_index = 0;
	musical_song song = s->song;
	musical_note note = song.notes[s->note_index];

    s->duration_curr = 0;
    s->duration_max = duration_to_ms(song.tempo, note.duration);
    s->next_player = player_playing;

    audio_on();
    play_freq(note.freq, 255);
}

void player_playing(struct state* s)
{
	if (s->duration_curr < s->duration_max)
	{
		s->duration_curr += 4; // each tick is 16ms
	}
	else
	{
        musical_song song = s->song;
        s->note_index++;

		if (s->note_index < song.length)
		{
            musical_note note = song.notes[s->note_index];

			s->duration_curr = 0;
            s->duration_max = duration_to_ms(song.tempo, note.duration);

			play_freq(note.freq, 255);
		}
		else
		{
            audio_off();
		}
	}
}


