#include <stdio.h>

#include "menu.h"
#include "lcd.h"

// Song FSM

void render_song_title(char title[16])
{
    pos_lcd(0, 0);
    puts_lcd2(title);
}

void song_start(struct state *s)
{
    render_song_title(s->song_list[s->song_index].title);
    s->next_song = song_none_pressed;
}
void song_none_pressed(struct state *s)
{
    if (s->pound)
    {
        s->next_song = song_next_pressed;
        s->song_index = (s->song_index + 1) % s->song_list_len;
        render_song_title(s->song_list[s->song_index].title);

        s->note_index = 0;
        s->note_duration_played = 0;
    }
    else if (s->star)
    {
        s->next_song = song_prev_pressed;
        s->song_index = (s->song_index - 1) % s->song_list_len;
        render_song_title(s->song_list[s->song_index].title);

        s->note_index = 0;
        s->note_duration_played = 0;
    }
}
void song_next_pressed(struct state *s)
{
    if (!s->pound)
        s->next_song = song_none_pressed;
}
void song_prev_pressed(struct state *s)
{
    if (!s->star)
        s->next_song = song_none_pressed;
}

// Volume FSM

char volume_text[8];

void render_volume(uint16_t volume)
{
    sprintf(volume_text, "Vol %d", volume);
    pos_lcd(1, 0);
    puts_lcd2(volume_text);
}

void volume_start(struct state *s)
{
    render_volume(s->volume);
    s->next_volume = volume_none_pressed;
}
void volume_none_pressed(struct state *s)
{
    if (s->A)
    {
        render_volume(++s->volume);
        s->next_volume = volume_up_pressed;
    }
    else if (s->B)
    {
        render_volume(--s->volume);
        s->next_volume = volume_down_pressed;
    }
}
void volume_up_pressed(struct state *s)
{
    if (!s->A)
        s->next_volume = volume_none_pressed;
}
void volume_down_pressed(struct state *s)
{
    if (!s->B)
        s->next_volume = volume_none_pressed;
}

// Tempo

char tempo_text[8];

void render_tempo(uint16_t tempo)
{
    sprintf(tempo_text, "BPM %d", tempo);
    pos_lcd(1, 7);
    puts_lcd2(tempo_text);
}

void tempo_start(struct state *s)
{
    render_tempo(s->tempo);
    s->next_tempo = tempo_none_pressed;
}
void tempo_none_pressed(struct state *s)
{
    if (s->C)
    {
        render_tempo(++s->tempo);
        s->next_tempo = tempo_up_pressed;
    }
    else if (s->D)
    {
        render_tempo(--s->tempo);
        s->next_tempo = tempo_down_pressed;
    }
}
void tempo_up_pressed(struct state *s)
{
    if (!s->C)
        s->next_tempo = tempo_none_pressed;
}
void tempo_down_pressed(struct state *s)
{
    if (!s->D)
        s->next_tempo = tempo_none_pressed;
}
