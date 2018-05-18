#include "player.h"
#include "audio.h"

uint32_t duration_to_ms(uint8_t bpm, uint8_t duration)
{
    // SEC_IN_MIN * MS_IN_SEC / BPM / 64 * 1/64 notes = duration
    return ((duration / 2) * 1875) / bpm;
}

void player_start(struct state *s)
{
    s->note_index = 0;
	musical_note note = s->song_list[s->song_index].notes[s->note_index];

    s->duration_curr = 0;
    s->duration_max = duration_to_ms(s->tempo, note.duration);
    s->next_player = player_playing;

    audio_on();
    play_freq(note.freq, s->volume);
}

void player_playing(struct state* s)
{
	if (s->duration_curr < s->duration_max)
	{
		s->duration_curr += 16; // each tick is 16ms
	}
	else
	{
        musical_song song = s->song_list[s->song_index];

		if (s->note_index < song.length)
		{
			s->note_index++;
            musical_note note = song.notes[s->note_index];

			s->duration_curr = 0;
            s->duration_max = duration_to_ms(s->tempo, note.duration);

			play_freq(note.freq, s->volume);
		}
		else
		{
            audio_off();
		}
	}
}


