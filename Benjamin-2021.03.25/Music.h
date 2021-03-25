#ifndef MUSIC_H
#define MUSIC_H

#include "Arduino.h"
#include"pitches.h"

//W:Whole H:Half Q:Quarter E:Eighth S:Sixteenth
#define DarthVader_W 2000
#define DarthVader_H 1000
#define DarthVader_Q 500
#define DarthVader_E 250
#define DarthVader_S 125
#define Doremi_W 1800
#define Doremi_H 900
#define Doremi_Q 450
#define Doremi_E 225
#define DraQue_LevelUP_Q 500
#define DraQue_LevelUP_E 250
#define DraQue_LevelUP_S 125
//中盤の速さ
#define Draque_Main_W 2051
#define Draque_Main_H 1026
#define Draque_Main_Q 513
#define Draque_Main_E 256
#define Draque_Main_S 128
//最初の速さ
#define Draque_Main_W1 1091
#define Draque_Main_H1 545
#define Draque_Main_Q1 273
#define Draque_Main_E1 136
#define Draque_Main_S1 68
//最後の速さ
#define Draque_Main_W2 3200
#define Draque_Main_H2 1600
#define Draque_Main_Q2 840
#define Draque_Main_E2 400
//中盤の速さ
#define Pokemon_W 1655
#define Pokemon_H 828
#define Pokemon_Q 414
#define Pokemon_E 207
#define Pokemon_S 103
//最初の速さ
#define Pokemon_W1 1263
#define Pokemon_H1 632
#define Pokemon_Q1 316
#define Pokemon_E1 158
#define StarWars_W 2400
#define StarWars_H 1200
#define StarWars_Q 600
#define StarWars_E 300
#define StarWars_S 150
#define Mario_W 2400
#define Mario_H 1200
#define Mario_Q 600
#define Mario_E 300
#define Mario_S 150
#define Zelda_W 2000
#define Zelda_H 1000
#define Zelda_Q 500
#define Zelda_E 250
#define Zelda_S 125

class Music {
    public:
        bool isPlay = true;
        Music(uint8_t pin);
        void tone2(uint16_t frequency, uint32_t duration);
        void DarthVader();
        void Doremi();
        void DraQue_LevelUP();
        void DraQue_Main();
        void Pokemon();
        void StarWars();
        void Mario();
        void Zelda();
    private:
        uint8_t _pin;
        const uint16_t Draque_Main_notes1[19] =
        {   NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4,
            NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4,
            NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5,
            NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4
        };
        const uint16_t Draque_Main_notes2[2][4][7] =
        {   {   {NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C5},
                {NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_G4},
                {NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5, 0, 0, 0},
                {NOTE_A5, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_C5}
            },
            {
                {NOTE_E6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_C6},
                {NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_G5},
                {NOTE_G6, NOTE_E6, NOTE_F6, NOTE_G6, 0, 0, 0},
                {NOTE_A6, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_F6, NOTE_E6, NOTE_C6}
            }
        };
        const uint16_t Pokemon_note1[5][2] =
        {
            {NOTE_AS4, NOTE_B4},
            {NOTE_AS4, NOTE_G4},
            {NOTE_AS4, NOTE_D5},
            {NOTE_AS4, NOTE_B4},
            {NOTE_CS5, NOTE_D5},
        };
};


#endif //MUSIC_H
