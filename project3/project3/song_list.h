#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "musical_notes.h"

static const musical_note song_overwatch_theme[] = {
    HD_NOTE(A4),
    Q__NOTE(E4),
    Q__NOTE(A4),
    HD_NOTE(B4),
    Q__NOTE(E4),
    Q__NOTE(B4),
    W__NOTE(CS5),
};

static const musical_note song_mario_theme[] = {
    Q__NOTE(E5),
    H__NOTE(E5),
    H__NOTE(E5),
    Q__NOTE(C5),
    H__NOTE(E5),
    W__NOTE(G5),
    Q__NOTE(G4),
};

static const musical_note song_mario_gameover[] = {
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

static const musical_note song_doom[] = {
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(E4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(D4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(C4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(BF3),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(B3),
    Q__NOTE(C4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(E4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(D4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    Q__NOTE(C4),
    Q__NOTE(E3),
    Q__NOTE(E3),
    H__NOTE(BF3),
};

static const musical_note song_disney[] = {
    H__NOTE(G3),
    H__NOTE(G4),
    H__NOTE(F4),
    H__NOTE(E4),
    H__NOTE(CS4),
    H__NOTE(D4),
    W__NOTE(A4),
    H__NOTE(B3),
    H__NOTE(B4),
    H__NOTE(A4),
    H__NOTE(G4),
    H__NOTE(FS4),
    H__NOTE(G4),
    W__NOTE(C5),
    H__NOTE(D5),
    H__NOTE(C5),
    H__NOTE(B4),
    H__NOTE(A4),
    H__NOTE(G4),
    H__NOTE(F4),
    H__NOTE(E4),
    H__NOTE(D4),
    W__NOTE(A4),
    W__NOTE(B3),
    W__NOTE(C4),
};

static const musical_note song_number_one[] = {
    HD_NOTE(F4),
    Q__NOTE(C5),
    E__NOTE(B4),
    E__NOTE(C5),
    E__NOTE(B4),
    E__NOTE(C5),
    Q__NOTE(B4),
    Q__NOTE(C5),
    H__NOTE(AF4),
    HD_NOTE(F4),
    Q__NOTE(F4),
    Q__NOTE(AF4),
    Q__NOTE(C5),
    H__NOTE(DF5),
    H__NOTE(AF4),
    H__NOTE(DF5),
    H__NOTE(EF5),
    Q__NOTE(C5),
    Q__NOTE(DF5),
    Q__NOTE(C5),
    Q__NOTE(DF5),
    H__NOTE(C5),
};

static const musical_song song_list[] = {
    SONG("Mario", song_mario_theme),
    SONG("Game over", song_mario_gameover),
    SONG("Overwatch", song_overwatch_theme),
    SONG("Doom", song_doom),
    SONG("Disney", song_disney),
    SONG("#1", song_number_one),
};

#endif
