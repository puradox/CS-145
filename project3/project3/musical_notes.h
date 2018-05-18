#ifndef MUSICAL_NOTES_H
#define MUSICAL_NOTES_H

#include <stdint.h>

// Tempo Placeholder
#define TEMPO_DEFAULT 100

typedef struct
{
    uint16_t freq; // timer1 TOP value
    uint16_t time_scaler;  // divides length of beat
} musical_note;

#define SONG(notes...) \
    {                  \
        notes          \
    }
#define MUSICAL_NOTE(note, duration) \
    musical_note { NOTE##note, duration }


// Note Types

#define WHOLE_NOTE(note) MUSICAL_NOTE(note, 1)
#define HALF_NOTE(note) MUSICAL_NOTE(note, 2)
#define QUARTER_NOTE(note) MUSICAL_NOTE(note, 4)
#define EIGHTH_NOTE(note) MUSICAL_NOTE(note, 8)
#define SIXTEENTH_NOTE(note) MUSICAL_NOTE(note, 16)


// Note Type Shortcuts
#define M__NOTE(note, duration) MUSICAL_NOTE(note, duration)
#define W__NOTE(n) WHOLE_NOTE(n)
#define H__NOTE(n) HALF_NOTE(n)
#define Q__NOTE(n) QUARTER_NOTE(n)
#define E__NOTE(n) EIGHTH_NOTE(n)
#define S__NOTE(n) SIXTEENTH_NOTE(n)
#define WD_NOTE(n) WHOLE_DOT_NOTE(n)
#define HD_NOTE(n) HALF_DOT_NOTE(n)
#define QD_NOTE(n) QUARTER_DOT_NOTE(n)
#define ED_NOTE(n) EIGHTH_DOT_NOTE(n)
#define SD_NOTE(n) SIXTEENTH_DOT_NOTE(n)

// Note Timbre
// Changes how the notes sound
#define TIMBRE_12 0.125f
#define TIMBRE_25 0.250f
#define TIMBRE_50 0.500f
#define TIMBRE_75 0.750f
#define TIMBRE_DEFAULT TIMBRE_50

// Notes - # = Octave

#define NOTE_REST 0

// freq = f_clk / (2 * prescaler * TOP)
// TOP = 62500 / freq (prescaler = 64)

#define NOTE_REST 0
#define NOTE_C0 3822
#define NOTE_CS0 3608
#define NOTE_D0 3405
#define NOTE_DS0 3214
#define NOTE_E0 3034
#define NOTE_F0 2863
#define NOTE_FS0 2703
#define NOTE_G0 2551
#define NOTE_GS0 2408
#define NOTE_A0 2273
#define NOTE_AS0 2145
#define NOTE_B0 2025
#define NOTE_C1 1911
#define NOTE_CS1 1804
#define NOTE_D1 1703
#define NOTE_DS1 1607
#define NOTE_E1 1517
#define NOTE_F1 1432
#define NOTE_FS1 1351
#define NOTE_G1 1276
#define NOTE_GS1 1204
#define NOTE_A1 1136
#define NOTE_AS1 1073
#define NOTE_B1 1012
#define NOTE_C2 956
#define NOTE_CS2 902
#define NOTE_D2 851
#define NOTE_DS2 804
#define NOTE_E2 758
#define NOTE_F2 716
#define NOTE_FS2 676
#define NOTE_G2 638
#define NOTE_GS2 602
#define NOTE_A2 568
#define NOTE_AS2 536
#define NOTE_B2 506
#define NOTE_C3 478
#define NOTE_CS3 451
#define NOTE_D3 426
#define NOTE_DS3 402
#define NOTE_E3 379
#define NOTE_F3 358
#define NOTE_FS3 338
#define NOTE_G3 319
#define NOTE_GS3 301
#define NOTE_A3 284
#define NOTE_AS3 268
#define NOTE_B3 253
#define NOTE_C4 239
#define NOTE_CS4 225
#define NOTE_D4 213
#define NOTE_DS4 201
#define NOTE_E4 190
#define NOTE_F4 179
#define NOTE_FS4 169
#define NOTE_G4 159
#define NOTE_GS4 150
#define NOTE_A4 142
#define NOTE_AS4 134
#define NOTE_B4 127
#define NOTE_C5 119
#define NOTE_CS5 113
#define NOTE_D5 106
#define NOTE_DS5 100
#define NOTE_E5 95
#define NOTE_F5 89
#define NOTE_FS5 84
#define NOTE_G5 80
#define NOTE_GS5 75
#define NOTE_A5 71
#define NOTE_AS5 67
#define NOTE_B5 63
#define NOTE_C6 60
#define NOTE_CS6 56
#define NOTE_D6 53
#define NOTE_DS6 50
#define NOTE_E6 47
#define NOTE_F6 45
#define NOTE_FS6 42
#define NOTE_G6 40
#define NOTE_GS6 38
#define NOTE_A6 36
#define NOTE_AS6 34
#define NOTE_B6 32
#define NOTE_C7 30
#define NOTE_CS7 28
#define NOTE_D7 27
#define NOTE_DS7 25
#define NOTE_E7 24
#define NOTE_F7 22
#define NOTE_FS7 21
#define NOTE_G7 20
#define NOTE_GS7 19
#define NOTE_A7 18
#define NOTE_AS7 17
#define NOTE_B7 16
#define NOTE_C8 15
#define NOTE_CS8 14
#define NOTE_D8 13
#define NOTE_DS8 13
#define NOTE_E8 12
#define NOTE_F8 11
#define NOTE_FS8 11
#define NOTE_G8 10
#define NOTE_GS8 9
#define NOTE_A8 9
#define NOTE_AS8 8
#define NOTE_B8 8

// Flat Aliases
#define NOTE_DF0 NOTE_CS0
#define NOTE_EF0 NOTE_DS0
#define NOTE_GF0 NOTE_FS0
#define NOTE_AF0 NOTE_GS0
#define NOTE_BF0 NOTE_AS0
#define NOTE_DF1 NOTE_CS1
#define NOTE_EF1 NOTE_DS1
#define NOTE_GF1 NOTE_FS1
#define NOTE_AF1 NOTE_GS1
#define NOTE_BF1 NOTE_AS1
#define NOTE_DF2 NOTE_CS2
#define NOTE_EF2 NOTE_DS2
#define NOTE_GF2 NOTE_FS2
#define NOTE_AF2 NOTE_GS2
#define NOTE_BF2 NOTE_AS2
#define NOTE_DF3 NOTE_CS3
#define NOTE_EF3 NOTE_DS3
#define NOTE_GF3 NOTE_FS3
#define NOTE_AF3 NOTE_GS3
#define NOTE_BF3 NOTE_AS3
#define NOTE_DF4 NOTE_CS4
#define NOTE_EF4 NOTE_DS4
#define NOTE_GF4 NOTE_FS4
#define NOTE_AF4 NOTE_GS4
#define NOTE_BF4 NOTE_AS4
#define NOTE_DF5 NOTE_CS5
#define NOTE_EF5 NOTE_DS5
#define NOTE_GF5 NOTE_FS5
#define NOTE_AF5 NOTE_GS5
#define NOTE_BF5 NOTE_AS5
#define NOTE_DF6 NOTE_CS6
#define NOTE_EF6 NOTE_DS6
#define NOTE_GF6 NOTE_FS6
#define NOTE_AF6 NOTE_GS6
#define NOTE_BF6 NOTE_AS6
#define NOTE_DF7 NOTE_CS7
#define NOTE_EF7 NOTE_DS7
#define NOTE_GF7 NOTE_FS7
#define NOTE_AF7 NOTE_GS7
#define NOTE_BF7 NOTE_AS7
#define NOTE_DF8 NOTE_CS8
#define NOTE_EF8 NOTE_DS8
#define NOTE_GF8 NOTE_FS8
#define NOTE_AF8 NOTE_GS8
#define NOTE_BF8 NOTE_AS8

#endif
