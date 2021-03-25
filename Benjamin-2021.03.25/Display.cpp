#include"Display.h"
#include"Music.h"

Music music(MUSIC_PIN);

void buttonState(uint16_t color) {
    const int rectX = width() - 10, rectY = height() - 10, rectSize = 10;
    fillRect(rectX, rectY, rectSize, rectSize, color);
}

void Display::text(char* text, byte x, byte y, uint16_t color) {
    if (color != nowColor) {    //無駄が無いように色が変わる時だけ実行する
        setTextColor(color);
        nowColor = color;
    }
    setCursor(x, y);
    print(text);
}

void Display::moveTriangle() {
    //辺の長さに0を含んだり、割った時に切り捨てられたりすることを考えると下の引数が丁度良い
    fillTriangle(triX, triY, triX, triSize - 1 + triY, (byte)(triSize * sqrt(3) / 2) + triX, (byte)(triSize / 2) + triY, BLACK);    // 前の三角形を消す
    if (isMusic) {
        num = (num + 1) % music_num;
        triX = 0;
    } else {
        num = (num + 1) % main_num;
        if (num <= 4) triX = 0;
        else triX = width() / 2;
    }
    triY = y_space * (num % 5);
    fillTriangle(triX, triY, triX, triSize - 1 + triY, (byte)(triSize * sqrt(3) / 2) + triX, (byte)(triSize / 2) + triY, WHITE);    // 新しい三角形を描く
}

void Display::mainMenu() {
    byte x = 10;
    fillScreen(BLACK);
    fillTriangle(triX, triY, triX, triSize - 1 + triY, (byte)(triSize * sqrt(3) / 2) + triX, (byte)(triSize / 2) + triY, WHITE);
    // メインタイトル表示
    text(main_title[0], x, 0, GREEN);
    for (byte i = 1; i < main_num; i++) {
        if (i == 5) x += width() / 2;
        text(main_title[i], x, y_space * (i % 5));
    }
}

void Display::musicMenu(byte buttonState) {
    num = 0;
    if (!isMusic) {
        isMusic = true;
        fillScreen(BLACK);
        fillTriangle(0, 0, 0, triSize - 1, (byte)(triSize * sqrt(3) / 2), (byte)(triSize / 2), WHITE); // 頂点1,頂点2,頂点3,色
        // ミュージックタイトル表示
        text(music_title[i], 10, 0, MAGENTA);
        for (byte i = 1; i < 5; i++) {
            text(music_title[i], 10, y_space * i);
        }
    }
    
    if (buttonState == 1) {  // ボタン短押しのとき　三角形の移動
        moveTriangle();
        if ((num % 5) == 0) {
            fillRect(10, 0, width() - 10, height(), BLACK);
            for (byte i = 0; i < 5; i++) {
                if (num == 0 && i == 0) text(music_title[0], 10, 0, MAGENTA);
                else text(music_title[i + num], 10, y_space * i);

                if (num == 5 && i == 3) break;  // 後半は4曲しかないためbreak;する
            }
        }
    } else if (buttonState == 2) { //ボタン長押しのとき
        switch (num) {
            case 0:
                isMusic = false;
                break;
            case 1:
                music.DarthVader();
                break;
            case 2:
                music.Doremi();
                break;
            case 3:
                music.DraQue_LevelUP();
                break;
            case 4:
                music.DraQue_Main();
                break;
            case 5:
                music.Pokemon();
                break;
            case 6:
                music.StarWars();
                break;
            case 7:
                music.Mario();
                break;
            case 8:
                music.Zelda();
                break;
        }
    }
}

void Display::readyToPlay(uint8_t pin) {
    fillScreen(BLACK);
    if (digitalRead(pin) == HIGH) {
        text("Worning!\r\n\nMOTOR SWITCH IS ON", 0, 0);
        while (digitalRead(pin) == HIGH);    // pinをLOWにするまで待つ
        fillScreen(BLACK);
    }
    setTextSize(2);
    text("PLAY!", (width() / 2) - 25, (height() / 2) - 5, GREEN);
    delay(1000);
    fillScreen(BLACK);
}
