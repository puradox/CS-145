#include "player.h"

int note_duration_to_ms(int bpm, int scaler)
{
	return ((bpm/60) / scaler) * 1000
}

bool end_of_song(struct state* s)
{
	return (s->note_index + 1) >= s->mario_length
}

void player_start(struct state* s)
{
	s->note_index = 0;
	play_freq(MUSICAL_NOTE(NOTE_A4, 1).freq);
}



void play_song(struct state* s)
{
	musical_note current_note = s->mario[s->note_index];
	if (s->note_duration_played < note_duration_to_ms(s->tempo, current_note.time_scaler))
	{
		play_freq(current_note.freq);
		s->note_duration_played += 16;
	}
	else
	{
		if (!end_of_song())
		{
			s->note_index++;
			play_freq(current_note.freq);
			s->note_duration_played = 16;
		}
		else
		{
			s->next_player = player_start;
		}
	}
}


