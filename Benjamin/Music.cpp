#include"Music.h"

Music::Music(uint8_t pin) {
    _pin = pin;
}

void Music::tone2(uint16_t frequency, uint32_t duration) {
    if (!isPlay) return;
    tone(_pin, frequency);
    delay(duration);
    noTone(_pin);
    delay(1);
}

void Music::DarthVader() {
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_B3, DarthVader_E * 1.5);
    tone2(NOTE_F4, DarthVader_S);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_B3, DarthVader_E * 1.5);
    tone2(NOTE_F4, DarthVader_S);
    tone2(NOTE_D4, DarthVader_Q);
    delay(DarthVader_Q);
    tone2(NOTE_AS4, DarthVader_Q);
    tone2(NOTE_AS4, DarthVader_Q);
    tone2(NOTE_AS4, DarthVader_Q);
    tone2(NOTE_B4, DarthVader_E * 1.5);
    tone2(NOTE_F4, DarthVader_S);
    tone2(NOTE_CS4, DarthVader_Q);
    tone2(NOTE_B3, DarthVader_E * 1.5);
    tone2(NOTE_F4, DarthVader_S);
    tone2(NOTE_D4, DarthVader_H);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_D3, DarthVader_E * 1.5);
    tone2(NOTE_D3, DarthVader_S);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_CS4, DarthVader_E * 1.5);
    tone2(NOTE_C4, DarthVader_S);
    tone2(NOTE_B3, DarthVader_S);
    tone2(NOTE_B3, DarthVader_S);
    tone2(NOTE_B3, DarthVader_E);
    delay(DarthVader_E + DarthVader_S);
    tone2(NOTE_E3, DarthVader_S);
    tone2(NOTE_A3, DarthVader_Q);
    tone2(NOTE_G3, DarthVader_E * 1.5);
    tone2(NOTE_FS3, DarthVader_S);
    tone2(NOTE_F3, DarthVader_S);
    tone2(NOTE_E3, DarthVader_S);
    tone2(NOTE_F3, DarthVader_E);
    delay(DarthVader_E + DarthVader_S);
    tone2(NOTE_B2, DarthVader_S);
    tone2(NOTE_CS3, DarthVader_Q);
    tone2(NOTE_B2, DarthVader_E * 1.5);
    tone2(NOTE_CS3, DarthVader_S);
    tone2(NOTE_F3, DarthVader_Q);
    tone2(NOTE_D3, DarthVader_E * 1.5);
    tone2(NOTE_F3, DarthVader_S);
    tone2(NOTE_AS3, DarthVader_H);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_D3, DarthVader_E * 1.5);
    tone2(NOTE_D3, DarthVader_S);
    tone2(NOTE_D4, DarthVader_Q);
    tone2(NOTE_CS4, DarthVader_E * 1.5);
    tone2(NOTE_C4, DarthVader_S);
    tone2(NOTE_B3, DarthVader_S);
    tone2(NOTE_B3, DarthVader_S);
    tone2(NOTE_B3, DarthVader_E);
    delay(DarthVader_E + DarthVader_S);
    tone2(NOTE_E3, DarthVader_S);
    tone2(NOTE_A3, DarthVader_Q);
    tone2(NOTE_G3, DarthVader_E * 1.5);
    tone2(NOTE_FS3, DarthVader_S);
    tone2(NOTE_F3, DarthVader_S);
    tone2(NOTE_E3, DarthVader_S);
    tone2(NOTE_F3, DarthVader_E);
    delay(DarthVader_E + DarthVader_S);
    tone2(NOTE_B2, DarthVader_S);
    tone2(NOTE_CS3, DarthVader_Q);
    tone2(NOTE_B2, DarthVader_E * 1.5);
    tone2(NOTE_FS3, DarthVader_S);
    tone2(NOTE_E3, DarthVader_Q);
    tone2(NOTE_B2, DarthVader_E * 1.5);
    tone2(NOTE_FS3, DarthVader_S);
    tone2(NOTE_E3, DarthVader_Q);
}

void Music::Doremi() {
    tone2(NOTE_C5, Doremi_Q * 1.5); //ド
    tone2(NOTE_D5, Doremi_E);       //は
    tone2(NOTE_E5, Doremi_Q * 1.5); //ドー
    tone2(NOTE_C5, Doremi_E);       //ナ
    tone2(NOTE_E5, Doremi_Q);       //ツ
    tone2(NOTE_C5, Doremi_Q);       //の
    tone2(NOTE_E5, Doremi_H);       //ド
    delay(10);
    tone2(NOTE_D5, Doremi_Q * 1.5); //レ
    tone2(NOTE_E5, Doremi_E);       //は
    tone2(NOTE_F5, Doremi_E);       //レ
    tone2(NOTE_F5, Doremi_E);       //モ
    tone2(NOTE_E5, Doremi_E);       //ン
    tone2(NOTE_D5, Doremi_E);       //の
    tone2(NOTE_F5, Doremi_W);       //レ
    delay(10);
    tone2(NOTE_E5, Doremi_Q * 1.5); //ミ
    tone2(NOTE_F5, Doremi_E);       //は
    tone2(NOTE_G5, Doremi_Q * 1.5); //み
    tone2(NOTE_E5, Doremi_E);       //ん
    tone2(NOTE_G5, Doremi_Q);       //な
    tone2(NOTE_E5, Doremi_Q);       //の
    tone2(NOTE_G5, Doremi_H);       //ミ
    delay(10);
    tone2(NOTE_F5, Doremi_Q * 1.5); //ファ
    tone2(NOTE_G5, Doremi_E);       //は
    tone2(NOTE_A5, Doremi_E);       //ファ
    tone2(NOTE_A5, Doremi_E);       //イ
    tone2(NOTE_G5, Doremi_E);       //ト
    tone2(NOTE_F5, Doremi_E);       //の
    tone2(NOTE_A5, Doremi_W);       //ファ
    delay(10);
    tone2(NOTE_G5, Doremi_Q * 1.5); //ソ
    tone2(NOTE_C5, Doremi_E);       //は
    tone2(NOTE_D5, Doremi_E);       //あ
    tone2(NOTE_E5, Doremi_E);       //お
    tone2(NOTE_F5, Doremi_E);       //い
    tone2(NOTE_G5, Doremi_E);       //そ
    tone2(NOTE_A5, Doremi_H + Doremi_Q);    //ら
    delay(Doremi_Q);
    tone2(NOTE_A5, Doremi_Q * 1.5); //ラ
    tone2(NOTE_D5, Doremi_E);       //は
    tone2(NOTE_E5, Doremi_E);       //ラ
    tone2(NOTE_FS5, Doremi_E);      //ッ
    tone2(NOTE_G5, Doremi_E);       //パ
    tone2(NOTE_A5, Doremi_E);       //の
    tone2(NOTE_B5, Doremi_H + Doremi_Q);    //ラ
    delay(Doremi_Q);
    tone2(NOTE_B5, Doremi_Q * 1.5); //シ
    tone2(NOTE_E5, Doremi_E);       //は
    tone2(NOTE_FS5, Doremi_E);      //し
    tone2(NOTE_GS5, Doremi_E);      //あ
    tone2(NOTE_A5, Doremi_E);       //わ
    tone2(NOTE_B5, Doremi_E);       //せ
    tone2(NOTE_C6, Doremi_H + Doremi_Q);    //よ
    tone2(NOTE_B5, Doremi_E);       //さ
    tone2(NOTE_AS5, Doremi_E);      //あ
    tone2(NOTE_A5, Doremi_Q);       //う
    tone2(NOTE_F5, Doremi_Q);       //た
    tone2(NOTE_B5, Doremi_Q);       //い
    tone2(NOTE_G5, Doremi_Q);       //ま
    tone2(NOTE_C6, Doremi_W);       //しょう
    delay(Doremi_Q);
    tone2(NOTE_C5, Doremi_Q);   //ド
    tone2(NOTE_D5, Doremi_Q);   //レ
    tone2(NOTE_E5, Doremi_Q);   //ミ
    tone2(NOTE_F5, Doremi_Q);   //ファ
    tone2(NOTE_G5, Doremi_Q);   //ソ
    tone2(NOTE_A5, Doremi_Q);   //ラ
    tone2(NOTE_B5, Doremi_Q);   //シ
    tone2(NOTE_C6, Doremi_Q);   //ド
    tone2(NOTE_C6, Doremi_Q);   //ド
    tone2(NOTE_B5, Doremi_Q);   //シ
    tone2(NOTE_A5, Doremi_Q);   //ラ
    tone2(NOTE_G5, Doremi_Q);   //ソ
    tone2(NOTE_F5, Doremi_Q);   //ファ
    tone2(NOTE_E5, Doremi_Q);   //ミ
    tone2(NOTE_D5, Doremi_Q);   //レ
    tone2(NOTE_C5, Doremi_Q);   //ド
    tone2(NOTE_E5, Doremi_Q);   //ミ
    tone2(NOTE_E5, Doremi_H);   //ミ
    delay(10);
    tone2(NOTE_E5, Doremi_Q);   //ミ
    tone2(NOTE_G5, Doremi_Q);   //ソ
    tone2(NOTE_G5, Doremi_H);   //ソ
    delay(10);
    tone2(NOTE_D5, Doremi_Q);   //レ
    tone2(NOTE_F5, Doremi_Q);   //ファ
    tone2(NOTE_F5, Doremi_H);   //ファ
    delay(10);
    tone2(NOTE_A5, Doremi_Q);   //ラ
    tone2(NOTE_B5, Doremi_Q);   //シ
    tone2(NOTE_B5, Doremi_H);   //シ
    delay(10);
    tone2(NOTE_C5, Doremi_E);   //ド
    tone2(NOTE_E5, Doremi_E);   //ミ
    tone2(NOTE_E5, Doremi_E);   //ミ
    delay(Doremi_E);
    tone2(NOTE_E5, Doremi_E);   //ミ
    tone2(NOTE_G5, Doremi_E);   //ソ
    tone2(NOTE_G5, Doremi_E);   //ソ
    delay(Doremi_E);
    tone2(NOTE_D5, Doremi_E);   //レ
    tone2(NOTE_F5, Doremi_E);   //ファ
    tone2(NOTE_F5, Doremi_E);   //ファ
    delay(Doremi_E);
    tone2(NOTE_A5, Doremi_E);   //ラ
    tone2(NOTE_B5, Doremi_E);   //シ
    tone2(NOTE_B5, Doremi_E);   //シ
    delay(Doremi_E);
    tone2(NOTE_G5, Doremi_H);   //ソ
    tone2(NOTE_C5, Doremi_H);   //ド
    tone2(NOTE_A5, Doremi_H);   //ラ
    tone2(NOTE_F5, Doremi_H);   //ファ
    tone2(NOTE_E5, Doremi_H);   //ミ
    tone2(NOTE_C5, Doremi_H);   //ド
    tone2(NOTE_D5, Doremi_W);   //レ
    delay(10);
    tone2(NOTE_G5, Doremi_H);   //ソ
    tone2(NOTE_C5, Doremi_H);   //ド
    tone2(NOTE_A5, Doremi_H);   //ラ
    tone2(NOTE_B5, Doremi_H);   //シ
    tone2(NOTE_C6, Doremi_H);   //ド
    tone2(NOTE_D6, Doremi_H);   //レ
    tone2(NOTE_C6, Doremi_H);   //ド
}

void Music::DraQue_LevelUP() {
    tone2(NOTE_F5, DraQue_LevelUP_S);
    tone2(NOTE_F5, DraQue_LevelUP_S);
    tone2(NOTE_F5, DraQue_LevelUP_S);
    tone2(NOTE_F5, DraQue_LevelUP_E);
    tone2(NOTE_DS5, DraQue_LevelUP_E);
    tone2(NOTE_G5, DraQue_LevelUP_E);
    tone2(NOTE_F5, DraQue_LevelUP_S + DraQue_LevelUP_E + DraQue_LevelUP_Q);
}

void Music::DraQue_Main() {
    tone2(NOTE_E4, Draque_Main_Q1 * 1.5);
    tone2(NOTE_E4, Draque_Main_S1);
    delay(Draque_Main_S1);
    for (int i = 0; i < (sizeof(Draque_Main_notes1) / sizeof(uint16_t)); i++)
    {
        tone2(Draque_Main_notes1[i], Draque_Main_E1);
        delay(Draque_Main_E1);
    }
    tone2(NOTE_D4, Draque_Main_Q1 + Draque_Main_E1);
    tone2(NOTE_D4, Draque_Main_S1);
    delay(Draque_Main_S1);
    tone2(NOTE_D4, Draque_Main_E1);
    delay(Draque_Main_E1);
    tone2(NOTE_E4, Draque_Main_Q1 * 1.5);
    tone2(NOTE_E4, Draque_Main_S1);
    delay(Draque_Main_S1);
    tone2(NOTE_E4, Draque_Main_E1);
    delay(Draque_Main_E1);
    tone2(NOTE_E4, Draque_Main_E);
    delay(Draque_Main_E1);
    tone2(NOTE_C4, Draque_Main_E);
    delay(Draque_Main_E1);
    tone2(NOTE_E4, Draque_Main_Q);
    tone2(NOTE_D4, Draque_Main_W1 * 2); //楽譜ではDraque_Main_H + Draque_Main_W
    delay(Draque_Main_Q);
    for (int i = 0; i < 2; i++)
    {
        tone2(NOTE_G4, Draque_Main_E * 1.5);
        tone2(NOTE_G4, Draque_Main_S);
        tone2(NOTE_C5, Draque_Main_Q);
        tone2(NOTE_D5, Draque_Main_Q);
        tone2(NOTE_E5, Draque_Main_Q);
        tone2(NOTE_F5, Draque_Main_Q);
        tone2(NOTE_G5, Draque_Main_E);
        delay(Draque_Main_E);
        tone2(NOTE_C6, Draque_Main_Q * 2);
        tone2(NOTE_B5, Draque_Main_E * 1.5);
        tone2(NOTE_A5, Draque_Main_S);
        tone2(NOTE_A5, Draque_Main_Q * 1.5);
        tone2(NOTE_G5, Draque_Main_E * 2);
        tone2(NOTE_FS5, Draque_Main_S);
        delay(Draque_Main_S);
        tone2(NOTE_FS5, Draque_Main_E);
        tone2(NOTE_A5, Draque_Main_E);
        tone2(NOTE_G5, Draque_Main_Q);
        tone2(NOTE_E5, Draque_Main_Q * 2);
        if (i == 0)
        {
            tone2(NOTE_E4, Draque_Main_E * 1.5);
            tone2(NOTE_E4, Draque_Main_S);
            tone2(NOTE_E4, Draque_Main_Q);
            tone2(NOTE_E4, Draque_Main_Q);
            tone2(NOTE_FS4, Draque_Main_Q);
            tone2(NOTE_GS4, Draque_Main_Q);
            tone2(NOTE_A4, Draque_Main_H + Draque_Main_E);
            tone2(NOTE_A4, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_B4, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_C5, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_D5, Draque_Main_H + Draque_Main_E);
            tone2(NOTE_A4, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_A4, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_C5, Draque_Main_S);
            delay(Draque_Main_S);
            tone2(NOTE_C5, Draque_Main_Q);
            tone2(NOTE_B4, Draque_Main_Q);
            tone2(NOTE_A4, Draque_Main_Q);
            tone2(NOTE_G4, Draque_Main_Q);
        } else if (i == 1)
        {
            tone2(NOTE_E5, Draque_Main_E * 1.5);
            tone2(NOTE_E5, Draque_Main_S);
            tone2(NOTE_E5, Draque_Main_Q);
            tone2(NOTE_E5, Draque_Main_Q);
            tone2(NOTE_FS5, Draque_Main_Q);
            tone2(NOTE_GS5, Draque_Main_Q);
            tone2(NOTE_A5, Draque_Main_H + Draque_Main_E);
            tone2(NOTE_A5, Draque_Main_E);
            tone2(NOTE_B5, Draque_Main_E);
            tone2(NOTE_C6, Draque_Main_E);
            tone2(NOTE_D6, Draque_Main_H + Draque_Main_E);
            tone2(NOTE_A5, Draque_Main_E);
            tone2(NOTE_A5, Draque_Main_E);
            tone2(NOTE_C6, Draque_Main_E);
            tone2(NOTE_C6, Draque_Main_Q);
            tone2(NOTE_B5, Draque_Main_Q);
            tone2(NOTE_A5, Draque_Main_Q);
            tone2(NOTE_G5, Draque_Main_Q);
        }
        for (int n = 0; n < 4; n++)
        {
            tone2(Draque_Main_notes2[i][n][0], Draque_Main_H + Draque_Main_E);
            tone2(Draque_Main_notes2[i][n][1], Draque_Main_E);
            tone2(Draque_Main_notes2[i][n][2], Draque_Main_E);
            tone2(Draque_Main_notes2[i][n][3], Draque_Main_E);
            if (n == 2)continue;
            tone2(Draque_Main_notes2[i][n][4], Draque_Main_H);
            if (n == 3)
            {
                tone2(Draque_Main_notes2[i][n][5], Draque_Main_H);
                tone2(Draque_Main_notes2[i][n][6], Draque_Main_H + Draque_Main_S);
            } else
            {
                tone2(Draque_Main_notes2[i][n][5], Draque_Main_Q);
                tone2(Draque_Main_notes2[i][n][6], Draque_Main_Q);
            }
        }
        delay(Draque_Main_S + Draque_Main_E);
    }
    tone2(NOTE_G4, Draque_Main_Q2);
    tone2(NOTE_G5, Draque_Main_E2);
    tone2(NOTE_CS5, Draque_Main_E2);
    tone2(NOTE_D5, Draque_Main_E2);
    tone2(NOTE_E5, Draque_Main_E2);
    tone2(NOTE_F5, Draque_Main_E2);
    tone2(NOTE_E5, Draque_Main_E2);
    tone2(NOTE_F5, Draque_Main_E2);
    tone2(NOTE_G5, Draque_Main_E2);
    tone2(NOTE_A5, Draque_Main_W); //楽譜ではDraque_Main_H+Draque_Main_E
    delay(Draque_Main_E);
    tone2(NOTE_A5, Draque_Main_Q2);
    tone2(NOTE_B5, Draque_Main_Q2);
    tone2(NOTE_C6, Draque_Main_Q2);
    tone2(NOTE_F6, Draque_Main_W2);
    tone2(NOTE_E6, Draque_Main_H2);
    tone2(NOTE_E6, Draque_Main_H2);
    tone2(NOTE_C6, Draque_Main_W + Draque_Main_W + Draque_Main_H);
}

void Music::Pokemon() {
    for (int i = 0; i < 5; i++)
    {
        tone2(NOTE_DS4, Pokemon_E1);
        tone2(NOTE_DS4, Pokemon_E1);
        tone2(Pokemon_note1[i][0], Pokemon_Q1);
        tone2(NOTE_DS4, Pokemon_E1);
        tone2(NOTE_DS4, Pokemon_E1);
        tone2(Pokemon_note1[i][1], Pokemon_Q1);
        if (i == 2)
        {
            tone2(NOTE_DS5, Pokemon_H1);
            tone2(NOTE_DS4, Pokemon_H1);
            tone2(NOTE_CS5, Pokemon_H1);
            tone2(NOTE_CS4, Pokemon_H1);
        }
    }
    tone2(NOTE_DS5, Pokemon_W1);

    tone2(NOTE_DS5, Pokemon_E);
    delay(Pokemon_E + Pokemon_Q + Pokemon_Q);
    tone2(NOTE_G3, Pokemon_S);
    tone2(NOTE_B3, Pokemon_S);
    tone2(NOTE_D4, Pokemon_S);
    tone2(NOTE_FS4, Pokemon_S);
    tone2(NOTE_G4, Pokemon_E);
    delay(Pokemon_E);
    tone2(NOTE_G4, Pokemon_E);
    delay(Pokemon_E + Pokemon_S);
    tone2(NOTE_G4, Pokemon_S);
    tone2(NOTE_G4, Pokemon_S);
    tone2(NOTE_G4, Pokemon_E);
    delay(Pokemon_E);
    tone2(NOTE_G4, Pokemon_E);
    delay(Pokemon_E);
    tone2(NOTE_G4, Pokemon_E);
    delay(Pokemon_E);
    tone2(NOTE_F4, (Pokemon_E * 2) / 3);
    tone2(NOTE_F4, (Pokemon_E * 2) / 3);
    tone2(NOTE_F4, (Pokemon_E * 2) / 3);
    tone2(NOTE_F4, (Pokemon_E * 2) / 3);
    tone2(NOTE_F4, (Pokemon_E * 2) / 3);
    tone2(NOTE_FS4, (Pokemon_E * 2) / 3);

    while (isPlay)
    {
        for (int i = 0; i < 2; i++)
        {
            tone2(NOTE_G4, Pokemon_Q * 1.5);
            tone2(NOTE_B4, Pokemon_E);
            tone2(NOTE_D5, Pokemon_H);
            tone2(NOTE_C4, Pokemon_E);
            delay(Pokemon_E);
            tone2(NOTE_C4, Pokemon_E);
            if (i == 0) tone2(NOTE_A4, Pokemon_E);
            else if (i == 1) tone2(NOTE_F4, Pokemon_E);
            tone2(NOTE_F5, Pokemon_Q * 1.5);
            tone2(NOTE_E5, Pokemon_S);
            tone2(NOTE_DS5, Pokemon_S);
            if (i == 0) tone2(NOTE_D5, Pokemon_W);
            else if (i == 1)
            {
                tone2(NOTE_D5, Pokemon_H);
                delay(Pokemon_E);
                tone2(NOTE_D4, Pokemon_S);
                tone2(NOTE_D4, Pokemon_S);
                tone2(NOTE_D4, Pokemon_E);
                delay(Pokemon_E);
            }
            tone2(NOTE_D4, Pokemon_E);
            delay(Pokemon_E);
            tone2(NOTE_D4, Pokemon_E);
            delay(Pokemon_E);
            tone2(NOTE_C4, (Pokemon_Q * 2) / 3);
            tone2(NOTE_B3, (Pokemon_Q * 2) / 3);
            tone2(NOTE_C4, (Pokemon_Q * 2) / 3);
            tone2(NOTE_G4, Pokemon_Q * 1.5);
            tone2(NOTE_B4, Pokemon_E);
            tone2(NOTE_D5, Pokemon_H);
            tone2(NOTE_C4, Pokemon_E);
            delay(Pokemon_E);
            tone2(NOTE_C4, Pokemon_E);
            delay(Pokemon_E);
            if (i == 0)
            {
                tone2(NOTE_C5, (Pokemon_Q * 2) / 3);
                tone2(NOTE_A4, (Pokemon_Q * 2) / 3);
                tone2(NOTE_C5, (Pokemon_Q * 2) / 3);
                tone2(NOTE_D5, Pokemon_H);
                delay(Pokemon_E);
                tone2(NOTE_D4, Pokemon_S);
                tone2(NOTE_D4, Pokemon_S);
                tone2(NOTE_D4, Pokemon_E);
                delay(Pokemon_E);
                tone2(NOTE_D4, Pokemon_E);
                delay(Pokemon_E);
                tone2(NOTE_D4, Pokemon_E);
                delay(Pokemon_E + Pokemon_E);
                tone2(NOTE_B3, Pokemon_E);
                tone2(NOTE_C4, Pokemon_E);
                tone2(NOTE_D4, Pokemon_E);
            } else if (i == 1)
            {
                tone2(NOTE_F5, (Pokemon_Q * 2) / 3);
                tone2(NOTE_E5, (Pokemon_Q * 2) / 3);
                tone2(NOTE_F5, (Pokemon_Q * 2) / 3);
                tone2(NOTE_G5, Pokemon_Q * 1.5);
                tone2(NOTE_AS5, Pokemon_E);
                tone2(NOTE_G5, Pokemon_H);
            }
        }
        tone2(NOTE_D4, Pokemon_E);
        delay(Pokemon_E);
        tone2(NOTE_D4, Pokemon_E);
        delay(Pokemon_E);
        tone2(NOTE_A5, Pokemon_H);
        tone2(NOTE_AS5, Pokemon_Q * 1.5);
        tone2(NOTE_F5, Pokemon_E);
        tone2(NOTE_F5, Pokemon_H);
        tone2(NOTE_AS2, Pokemon_E);
        tone2(NOTE_D3, Pokemon_E);
        tone2(NOTE_F3, Pokemon_E);
        tone2(NOTE_AS3, Pokemon_E);
        tone2(NOTE_AS5, Pokemon_Q);
        tone2(NOTE_B5, Pokemon_Q);
        tone2(NOTE_C6, Pokemon_Q * 1.5);
        tone2(NOTE_G5, Pokemon_E);
        tone2(NOTE_G5, Pokemon_H);
        tone2(NOTE_C3, Pokemon_E);
        tone2(NOTE_E3, Pokemon_E);
        tone2(NOTE_G3, Pokemon_E);
        tone2(NOTE_C4, Pokemon_E);
        tone2(NOTE_C6, Pokemon_Q);
        tone2(NOTE_CS6, Pokemon_Q);
        tone2(NOTE_D6, Pokemon_W);
        tone2(NOTE_D3, Pokemon_E);
        tone2(NOTE_A3, Pokemon_E);
        tone2(NOTE_D3, Pokemon_E);
        tone2(NOTE_A4, Pokemon_E);
        tone2(NOTE_C6, (Pokemon_Q * 2) / 3);
        tone2(NOTE_C6, (Pokemon_Q * 2) / 3);
        tone2(NOTE_CS6, (Pokemon_Q * 2) / 3);
        tone2(NOTE_D6, Pokemon_W);
        tone2(NOTE_D3, Pokemon_E);
        tone2(NOTE_A3, Pokemon_E);
        tone2(NOTE_D3, Pokemon_E);
        tone2(NOTE_A4, Pokemon_E);
        tone2(NOTE_C6, (Pokemon_Q * 2) / 3);
        tone2(NOTE_C6, (Pokemon_Q * 2) / 3);
        tone2(NOTE_B5, (Pokemon_Q * 2) / 3);
    }
}

void Music::StarWars() {
    tone2(NOTE_C6, StarWars_Q * 1.5);
    for (int i = 0; i < 3; i++) tone2(NOTE_C5, StarWars_E / 3);
    tone2(NOTE_C5, StarWars_Q * 1.5);
    for (int i = 0; i < 3; i++) tone2(NOTE_C5, StarWars_E / 3);
    for (int i = 0; i < 3; i++) {
        tone2(NOTE_C5, StarWars_Q / 3);
        tone2(NOTE_G4, StarWars_Q / 3);
        tone2(NOTE_F5, StarWars_Q / 3);
        tone2(NOTE_G5, StarWars_Q / 3);
        tone2(NOTE_F5, StarWars_Q / 3);
        tone2(NOTE_C5, StarWars_Q / 3);
    }
    tone2(NOTE_C5, StarWars_E);
    tone2(NOTE_C5, StarWars_S);
    tone2(NOTE_C5, StarWars_S);
    for (int i = 0; i < 3; i++) tone2(NOTE_G4, StarWars_Q / 3);

    for (int i = 0; i < 2; i++) {
        tone2(NOTE_C5, StarWars_H);
        tone2(NOTE_G5, StarWars_H);
        for (int j = 0; j < 2; j++) {
            tone2(NOTE_F5, StarWars_Q / 3);
            tone2(NOTE_E5, StarWars_Q / 3);
            tone2(NOTE_D5, StarWars_Q / 3);
            tone2(NOTE_C6, StarWars_H);
            if ((i == 1) && (j == 1)) goto out;
            tone2(NOTE_G5, StarWars_Q);
        }
        tone2(NOTE_F5, StarWars_Q / 3);
        tone2(NOTE_E5, StarWars_Q / 3);
        tone2(NOTE_F5, StarWars_Q / 3);
        tone2(NOTE_D5, StarWars_H);
        tone2(NOTE_G4, StarWars_E * 1.5);
        tone2(NOTE_G4, StarWars_S);
    }
out:
    tone2(NOTE_G4, StarWars_Q / 3);
    tone2(NOTE_C5, StarWars_Q / 3);
    tone2(NOTE_G5, StarWars_Q / 3);
    tone2(NOTE_F5, StarWars_Q / 3);
    tone2(NOTE_D5, StarWars_Q / 3);
    tone2(NOTE_F5, StarWars_Q / 3);
    tone2(NOTE_D5, StarWars_Q);
    delay(StarWars_Q);

    for (int i = 0; i < 3; i++) {
        tone2(NOTE_G4, StarWars_E * 1.5);
        tone2(NOTE_G4, StarWars_S);
        tone2(NOTE_A4, StarWars_Q * 1.5);
        tone2(NOTE_A4, StarWars_E);
        tone2(NOTE_F5, StarWars_E);
        tone2(NOTE_E5, StarWars_E);
        tone2(NOTE_D5, StarWars_E);
        tone2(NOTE_C5, StarWars_E);
        if ((i == 0) || (i == 2)) {
            tone2(NOTE_C5, StarWars_Q / 3);
            tone2(NOTE_D5, StarWars_Q / 3);
            tone2(NOTE_E5, StarWars_Q / 3);
            tone2(NOTE_D5, StarWars_Q * 2 / 3);
            tone2(NOTE_A4, StarWars_Q / 3);
            tone2(NOTE_B4, StarWars_Q);
        } else if (i == 1) {
            tone2(NOTE_G5, StarWars_E * 1.5);
            tone2(NOTE_D5, StarWars_S);
            tone2(NOTE_D5, StarWars_H);
        }
    }
    tone2(NOTE_G5, StarWars_E * 1.5);
    tone2(NOTE_G5, StarWars_S);

    tone2(NOTE_C6, StarWars_H / 3);
    tone2(NOTE_AS5, StarWars_Q / 3);
    tone2(NOTE_GS5, StarWars_H / 3);
    tone2(NOTE_G5, StarWars_Q / 3);
    tone2(NOTE_F5, StarWars_H / 3);
    tone2(NOTE_DS5, StarWars_Q / 3);
    tone2(NOTE_D5, StarWars_H / 3);
    tone2(NOTE_C5, StarWars_Q / 3);
    tone2(NOTE_G5, StarWars_Q);
    tone2(NOTE_G4, StarWars_Q / 3);
    tone2(NOTE_G4, StarWars_Q / 3);
    tone2(NOTE_G4, StarWars_Q / 3);
    tone2(NOTE_G4, StarWars_Q);
    tone2(NOTE_G4, StarWars_E);
    tone2(NOTE_G4, StarWars_E);
    tone2(NOTE_A4, StarWars_Q);
    tone2(NOTE_F4, StarWars_E);
    tone2(NOTE_C5, StarWars_E);
    tone2(NOTE_F5, StarWars_Q);
    tone2(NOTE_D5, StarWars_Q);
    tone2(NOTE_C5, StarWars_H);
    tone2(NOTE_G5, StarWars_H);
    for (int i = 0; i < 2; i++) {
        if (i == 0) tone2(NOTE_F5, StarWars_Q / 3);
        else if (i == 1) tone2(NOTE_G5, StarWars_Q / 3);
        tone2(NOTE_E5, StarWars_Q / 3);
        tone2(NOTE_D5, StarWars_Q / 3);
        tone2(NOTE_C6, StarWars_H);
        tone2(NOTE_G5, StarWars_Q);
    }
    tone2(NOTE_G5, StarWars_Q / 3);
    tone2(NOTE_E5, StarWars_Q / 3);
    tone2(NOTE_F5, StarWars_Q / 3);
    tone2(NOTE_D5, StarWars_H);
    tone2(NOTE_G4, StarWars_E * 1.5);
    tone2(NOTE_G4, StarWars_S);
    tone2(NOTE_C5, StarWars_H);
    tone2(NOTE_G5, StarWars_H);
    tone2(NOTE_F5, StarWars_Q / 3);
    tone2(NOTE_E5, StarWars_Q / 3);
    tone2(NOTE_D5, StarWars_Q / 3);
    tone2(NOTE_C6, StarWars_H);
    tone2(NOTE_G5, StarWars_Q);
    tone2(NOTE_C6, StarWars_Q / 3);
    tone2(NOTE_AS5, StarWars_Q / 3);
    tone2(NOTE_GS5, StarWars_Q / 3);
    tone2(NOTE_DS6, StarWars_Q);
    tone2(NOTE_C6, StarWars_Q);
    tone2(NOTE_D6, StarWars_Q);
    tone2(NOTE_C6, StarWars_E);
    delay(StarWars_E);
    tone2(NOTE_C5, StarWars_Q / 3);
    tone2(NOTE_C5, StarWars_Q / 3);
    tone2(NOTE_C5, StarWars_Q / 3);
    tone2(NOTE_C5, StarWars_Q);
}

void Music::Mario() {
    int repeatcount = 0;
    for (int i = 0; i < 2; i++) {
        tone2(NOTE_E6, Mario_S);
        tone2(NOTE_E6, Mario_E);
        tone2(NOTE_E6, Mario_S);
        delay(Mario_S);
        tone2(NOTE_C6, Mario_S);
        tone2(NOTE_E6, Mario_E);
        tone2(NOTE_G6, Mario_E);
        delay(Mario_E);
        tone2(NOTE_G5, Mario_E);
        delay(Mario_E);

        for (int j = 0; j < 2; j++) {
            tone2(NOTE_C6, Mario_E);
            delay(Mario_S);
            tone2(NOTE_G5, Mario_S);
            delay(Mario_E);
            tone2(NOTE_E5, Mario_E);
            delay(Mario_S);
            tone2(NOTE_A5, Mario_E);
            tone2(NOTE_B5, Mario_S);
            delay(Mario_S);
            tone2(NOTE_AS5, Mario_S);
            tone2(NOTE_A5, Mario_E);

            tone2(NOTE_G5, Mario_Q / 3);
            tone2(NOTE_E6, Mario_Q / 3);
            tone2(NOTE_G6, Mario_Q / 3);
            tone2(NOTE_A6, Mario_E);
            tone2(NOTE_F6, Mario_S);
            tone2(NOTE_G6, Mario_S);
            delay(Mario_S);
            tone2(NOTE_E6, Mario_E);
            tone2(NOTE_C6, Mario_S);
            tone2(NOTE_D6, Mario_S);
            tone2(NOTE_B5, Mario_E);
            delay(Mario_S);
        }
        if (i == 0) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    delay(Mario_E);
                    tone2(NOTE_G6, Mario_S);
                    tone2(NOTE_FS6, Mario_S);
                    tone2(NOTE_F6, Mario_S);
                    tone2(NOTE_DS6, Mario_E);
                    tone2(NOTE_E6, Mario_S);
                    delay(Mario_S);
                    if ((k == 0) || (k == 2)) {
                        tone2(NOTE_GS5, Mario_S);
                        tone2(NOTE_A5, Mario_S);
                        tone2(NOTE_C6, Mario_S);
                        delay(Mario_S);
                        tone2(NOTE_A5, Mario_S);
                        tone2(NOTE_C6, Mario_S);
                        tone2(NOTE_D6, Mario_S);
                    }
                    else {
                        tone2(NOTE_C7, Mario_E);
                        tone2(NOTE_C7, Mario_S);
                        tone2(NOTE_C7, Mario_E);
                        delay(Mario_E);
                    }
                }
                delay(Mario_E);
                tone2(NOTE_DS6, Mario_E);
                delay(Mario_S);
                tone2(NOTE_D6, Mario_E);
                delay(Mario_S);
                tone2(NOTE_C6, Mario_E);
                delay(Mario_E + Mario_Q);
            }

Repeat:
            for (int j = 0; j < 3; j++) {
                tone2(NOTE_C6, Mario_S);
                tone2(NOTE_C6, Mario_E);
                tone2(NOTE_C6, Mario_S);
                delay(Mario_S);
                tone2(NOTE_C6, Mario_S);
                if ((j == 0) || (j == 2)) {
                    tone2(NOTE_D6, Mario_E);
                    tone2(NOTE_E6, Mario_S);
                    tone2(NOTE_C6, Mario_E);
                    tone2(NOTE_A5, Mario_S);
                    tone2(NOTE_G5, Mario_E);
                    delay(Mario_E);
                }
                else {
                    tone2(NOTE_D6, Mario_S);
                    tone2(NOTE_E6, Mario_S);
                    delay(Mario_H);
                }
            }
        }
        if (i == 1) {
            if (repeatcount == 1) {
                tone2(NOTE_E6, Mario_S);
                tone2(NOTE_E6, Mario_E);
                tone2(NOTE_E6, Mario_S);
                delay(Mario_S);
                tone2(NOTE_C6, Mario_S);
                tone2(NOTE_E6, Mario_E);
                tone2(NOTE_G6, Mario_Q);
                tone2(NOTE_G5, Mario_Q);
            }
            for (int j = 0; j < 4; j++) {
                if ((repeatcount == 1) && (j == 2)) break;
                tone2(NOTE_E6, Mario_S);
                tone2(NOTE_C6, Mario_E);
                tone2(NOTE_G5, Mario_S);
                delay(Mario_E);
                tone2(NOTE_GS5, Mario_E);
                tone2(NOTE_A5, Mario_S);
                tone2(NOTE_F6, Mario_E);
                tone2(NOTE_F6, Mario_S);
                tone2(NOTE_A5, Mario_E);
                delay(Mario_E);
                if ((j == 0) || (j == 2)) {
                    tone2(NOTE_B5, Mario_Q / 3);
                    tone2(NOTE_A6, Mario_Q / 3);
                    tone2(NOTE_A6, Mario_Q / 3);
                    tone2(NOTE_A6, Mario_Q / 3);
                    tone2(NOTE_G6, Mario_Q / 3);
                    tone2(NOTE_F6, Mario_Q / 3);
                    tone2(NOTE_E6, Mario_S);
                    tone2(NOTE_C6, Mario_E);
                    tone2(NOTE_A5, Mario_S);
                    tone2(NOTE_G5, Mario_E);
                    delay(Mario_E);
                }
                else {
                    tone2(NOTE_B5, Mario_S);
                    tone2(NOTE_F6, Mario_E);
                    tone2(NOTE_F6, Mario_S);
                    tone2(NOTE_F6, Mario_Q / 3);
                    tone2(NOTE_E6, Mario_Q / 3);
                    tone2(NOTE_D6, Mario_Q / 3);
                    tone2(NOTE_C6, Mario_S);
                    tone2(NOTE_E5, Mario_E);
                    tone2(NOTE_E5, Mario_S);
                    tone2(NOTE_C5, Mario_E);
                    delay(Mario_E);
                }
            }
            if (repeatcount == 0) {
                repeatcount = 1;
                goto Repeat;
            }
        }
    }
}

void Music::Zelda() {
    tone2(NOTE_A5, Zelda_H);
    for (byte i = 0; i < 3; i++) {
        delay(2 * (Zelda_Q / 3));
        tone2(NOTE_A5, Zelda_Q / 3);
        tone2(NOTE_A5, Zelda_Q / 3);
        tone2(NOTE_A5, Zelda_Q / 3);
        if (i == 2)break;
        tone2(NOTE_A5, Zelda_Q / 3);
        tone2(NOTE_A5, Zelda_H / 3);
        tone2(NOTE_G5, Zelda_Q / 3);
        tone2(NOTE_A5, Zelda_Q);
    }
    tone2(NOTE_A5, Zelda_Q);
    for (byte i = 0; i < 3; i++) {
        tone2(NOTE_E5, Zelda_S);
        tone2(NOTE_E5, Zelda_S);
        tone2(NOTE_E5, Zelda_E);
    }
    tone2(NOTE_E5, Zelda_E);
    for (byte i = 0; i < 2; i++) {
        tone2(NOTE_A5, Zelda_Q);
        tone2(NOTE_E5, Zelda_Q * 1.5);
        tone2(NOTE_A5, Zelda_E);
        tone2(NOTE_A5, Zelda_S);
        tone2(NOTE_B5, Zelda_S);
        tone2(NOTE_C6, Zelda_S);
        tone2(NOTE_D6, Zelda_S);
        tone2(NOTE_E6, Zelda_H);
        delay(Zelda_E);
        tone2(NOTE_E6, Zelda_E);
        tone2(NOTE_E6, Zelda_Q / 3);
        tone2(NOTE_F6, Zelda_Q / 3);
        tone2(NOTE_G6, Zelda_Q / 3);
        tone2(NOTE_A6, Zelda_H);
        delay(Zelda_E);
        tone2(NOTE_A6, Zelda_E);
        tone2(NOTE_A6, Zelda_Q / 3);
        tone2(NOTE_G6, Zelda_Q / 3);
        tone2(NOTE_F6, Zelda_Q / 3);
        tone2(NOTE_G6, Zelda_E * 1.5);
        tone2(NOTE_F6, Zelda_S);
        tone2(NOTE_E6, Zelda_H);
        tone2(NOTE_E6, Zelda_Q);
        tone2(NOTE_D6, Zelda_E);
        tone2(NOTE_D6, Zelda_S);
        tone2(NOTE_E6, Zelda_S);
        tone2(NOTE_F6, Zelda_H);
        tone2(NOTE_E6, Zelda_E);
        tone2(NOTE_D6, Zelda_E);
        tone2(NOTE_C6, Zelda_E);
        tone2(NOTE_C6, Zelda_S);
        tone2(NOTE_D6, Zelda_S);
        tone2(NOTE_E6, Zelda_H);
        tone2(NOTE_D6, Zelda_E);
        tone2(NOTE_C6, Zelda_E);
        tone2(NOTE_B5, Zelda_E);
        tone2(NOTE_B5, Zelda_S);
        tone2(NOTE_C6, Zelda_S);
        tone2(NOTE_D6, Zelda_H);
        tone2(NOTE_F6, Zelda_Q);
        tone2(NOTE_E6, Zelda_E);
        for (byte k = 0; k < 3; k++) {
            tone2(NOTE_E5, Zelda_S);
            tone2(NOTE_E5, Zelda_S);
            tone2(NOTE_E5, Zelda_E);
        }
        tone2(NOTE_A5, Zelda_Q);
        tone2(NOTE_E5, Zelda_Q * 1.5);
        tone2(NOTE_A5, Zelda_E);
        tone2(NOTE_A5, Zelda_S);
        tone2(NOTE_B5, Zelda_S);
        tone2(NOTE_C6, Zelda_S);
        tone2(NOTE_D6, Zelda_S);
        tone2(NOTE_E6, Zelda_H);
        delay(Zelda_E);
        tone2(NOTE_E6, Zelda_E);
        tone2(NOTE_E6, Zelda_Q / 3);
        tone2(NOTE_F6, Zelda_Q / 3);
        tone2(NOTE_G6, Zelda_Q / 3);
        tone2(NOTE_A6, Zelda_H);
        delay(Zelda_E * 2);
        tone2(NOTE_C7, Zelda_Q);
        tone2(NOTE_B6, Zelda_Q);
        tone2(NOTE_G6, Zelda_H);
        tone2(NOTE_E6, Zelda_Q);
        tone2(NOTE_F6, Zelda_H * 1.5);
        tone2(NOTE_A6, Zelda_Q);
        tone2(NOTE_G6, Zelda_Q);
        tone2(NOTE_E6, Zelda_H);
        tone2(NOTE_E6, Zelda_Q);
        tone2(NOTE_F6, Zelda_H * 1.5);
        tone2(NOTE_A6, Zelda_Q);
        tone2(NOTE_GS6, Zelda_Q);
        tone2(NOTE_E6, Zelda_H);
        tone2(NOTE_CS6, Zelda_Q);
        tone2(NOTE_D6, Zelda_H * 1.5);
        tone2(NOTE_F6, Zelda_Q);
        tone2(NOTE_E6, Zelda_Q);
        tone2(NOTE_C6, Zelda_H);
        tone2(NOTE_A5, Zelda_Q);
        tone2(NOTE_B5, Zelda_E);
        tone2(NOTE_B5, Zelda_S);
        tone2(NOTE_C6, Zelda_S);
        tone2(NOTE_D6, Zelda_H);
        tone2(NOTE_F6, Zelda_Q);
        tone2(NOTE_E6, Zelda_E);
        for (int k = 0; k < 3; k++) {
            tone2(NOTE_E5, Zelda_S);
            tone2(NOTE_E5, Zelda_S);
            tone2(NOTE_E5, Zelda_E);
        }
        tone2(NOTE_E5, Zelda_E);
    }
}
