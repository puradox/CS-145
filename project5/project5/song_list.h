#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "musical_notes.h"

static const musical_note notes_mario_theme[] = {
    Q__NOTE(E5),
    H__NOTE(E5),
    H__NOTE(E5),
    Q__NOTE(C5),
    H__NOTE(E5),
    W__NOTE(G5),
    Q__NOTE(G4),
};

static musical_song song_mario_theme = SONG(notes_mario_theme, 120);

static const musical_note notes_mario_game_over[] = {
    HD_NOTE(C5),
    HD_NOTE(G4),
    H__NOTE(E4),
    H__NOTE(A4),
    H__NOTE(B4),
    H__NOTE(A4),
    H__NOTE(AF4),
    H__NOTE(BF4),
    H__NOTE(AF4),
    WD_NOTE(G4),
};

static musical_song song_mario_game_over = SONG(notes_mario_game_over, 120);

static const musical_note notes_none[] = {};

static musical_song song_none = SONG(notes_none, 120);

#endif
