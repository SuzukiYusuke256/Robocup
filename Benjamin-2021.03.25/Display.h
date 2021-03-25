#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define MUSIC_PIN   PA9     //スピーカーのピン
#define main_num 8
#define music_num 9

class Display : public Adafruit_SSD1331 {
    private:
        //const byte main_num = 8, music_num = 9;
        const char* main_title[main_num] = {"play", "ball", "line", "gyro", "psd", "camera", "kicker", "music"}; //解決案1：サイズ宣言後に代入
        const char* music_title[music_num] = {"back", "DarthVader", "Doremi", "DraQue_LevelUP", "DraQue_Main", "Pokemon", "StarWars", "Mario", "Zelda"};
        const byte y_space = 12, triSize = 7;    //（OLEDのスタート画面の）行間, 三角形の辺の長さ（奇数がオススメ）
        byte triX = 0, triY = 0, num = 0;   // 三角形のx,y座標、選択中の番号（メニュー）
        int nowColor = WHITE;
        
    public:
        bool isMusic = false;
        void buttonState(uint16_t color);
        void text(char* text, byte x = 0, byte y = 0, uint16_t color = WHITE);
        void moveTriangle_main();
        void moveTriangle_music();
        void mainMenu();
        void musicMenu(byte buttonState);
        void readyToPlay(uint8_t pin);
        
};
#endif  //DISPLAY_H
