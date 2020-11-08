/* Include & Define */
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include<SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE    //Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation is used in I2Cdev.h
#include "Wire.h"
#endif
#include "Music.h"

#define MAXPOWER 255 * 0.35  //モーターの最大パワー
#define MINPOWER 50         //モーターの最小パワー (動き始める値)
#define GYRO_INT    PA10    //ジャイロの割り込みピン
#define CAMERA_SS   PB6     //カメラのSS
#define PSD_PIN     PC5     //距離センサ(PSD)のアナログ入力ピン
#define CATCH_PIN   PC4     //ボール捕捉センサのアナログ入力ピン
#define KICK_PIN    PH1     //HIGH:KICK LOW:NOT KICK
#define BUTTON_PIN  PB13    //押しボタン（タクトスイッチ）ピン
#define SWITCH_PIN  PB12    //トグルスイッチピン
#define OLED_DC     PB15    //ディスプレイのMISO ハードウェアのMISO以外の任意のピンを選ぶ
#define OLED_CS     PB1     //ディスプレイのSS 任意のピン
#define OLED_RST    PB14    //ディスプレイのRESET任意のピン
#define MUSIC_PIN   PA9     //スピーカーのピン
#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF

/* クラス */
MPU6050 mpu;
Quaternion q;           // [w, x, y, z] quaternion container
VectorFloat gravity;    // [x, y, z]    gravity vector
Adafruit_SSD1331 oled = Adafruit_SSD1331(&SPI, OLED_CS, OLED_DC, OLED_RST); //use the hardware SPI pins
SPISettings spi = SPISettings(SPI_CLOCK_DIV16, MSBFIRST, SPI_MODE0);
Music music(MUSIC_PIN);

/* プロトタイプ宣言 */
void getBall();
bool judgeIsHoldBall();
void getLine();
bool judgeIsLine();
void startGyro();
float getGyro();
float getGyroPID();
byte getPSD();
void getCamera();
void kick();
void stop();
void faceTarget();
void move(double deg, float diff = 0);
void setPosition();
void wrapAroundBall();
void avoidLine(double lineDeg);
void startDisplay();
void displayText(char* text, byte x = 0, byte y = 0, uint16_t color = WHITE);
void displayFirstScene();
void displaySecondScene();
void displayMusicMenu();
byte displayButton(); //ボタンを 0:押してない 1;短押し 2:長押し

/* グローバル変数 */
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
// ---割り込み検出ルーチン---
volatile bool mpuInterrupt = false; // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

const uint8_t dirPin[4] = { PC10, PC12, PC11, PD2 }; //MDのDIRピン
const uint8_t pwmPin[4] = { PC8, PC6, PC9, PB8 };    //MDのPWMピン
const uint8_t ballPin[12] = {PC7, PB9, PA12, PA11, PB2, PA8, PB5, PB4, PB7, PA15, PA14, PA13};
const uint8_t linePin[8] = {PA1, PA0, PB0, PA4, PC2, PC1, PC3, PC0};  //ラインセンサーのピン
double power = MINPOWER, moveDeg = 1000.0, pre_moveDeg = 1000.0;    //モーターのパワー(0～255)
bool isLine[8] = {false}, isKick = false;
bool isDisplay_ball = false, isDisplay_line = false, isDisplay_gyro = false, isDisplay_psd = false, isDisplay_camera = false;
byte y_space = 12, triangleSize = 7;    //（OLEDのスタート画面の）行間, 三角形の辺の長さ（奇数がオススメ）
float target = 0;
double ballDeg = 1000.0;
int ballDistance = 0, goalDeg = 1000, goalDistance = 0;
byte lineState = 0, goalState = 0;  //lineState 0:コート内 1:ラインを踏み止まろうとしている 2:ラインから離れようとしている
uint32_t kickTime;
/*---------------------------------------------------------------------------------------------*/

void setup() {
    pinMode(CAMERA_SS, OUTPUT); //カメラのSS用のピンを出力に設定
    pinMode(KICK_PIN, OUTPUT); //キッカーのピンを出力に設定
    for (byte i = 0; i < 4; i++) { //モータードライバー用のピンを出力に設定
        pinMode(dirPin[i], OUTPUT);
        analogWrite(pwmPin[i], 0);
    }
    pinMode(BUTTON_PIN, INPUT);
    pinMode(SWITCH_PIN, INPUT);
    pinMode(PSD_PIN, INPUT_ANALOG);
    pinMode(CATCH_PIN, INPUT_ANALOG);
    for (byte i = 0; i < 12; i++) { //ボールセンサー用のピンをデジタル入力に設定
        pinMode(ballPin[i], INPUT);
    }
    for (int i = 0; i < 8; i++) { //ラインセンサー用のピンをアナログ入力に設定
        pinMode(linePin[i], INPUT_ANALOG);
    }
    digitalWrite(CAMERA_SS, HIGH); //LOWで通信されるのでHIGHにしておく
    digitalWrite(KICK_PIN, LOW); //HIGHでキックされるのでLOWにしておく
    SPI.begin(); // SPI開始
    oled.begin();
    startGyro(); //ジャイロ開始
    startDisplay();
}

void loop() {
    if (lineState == 0 || lineState == 3) {
        getBall();
        wrapAroundBall();
    }
    getLine();
    avoidLine();
    move(moveDeg, getGyroPID());
    if (moveDeg != 1000.0) pre_moveDeg = moveDeg;
    //    oled.fillScreen(BLACK);
    //    oled.setCursor(0, 0);
    //    oled.print(pre_moveDeg);
    //    oled.print(moveDeg);
}

void getBall() {
    const int sensorDeg[12] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330}; //センサーの付いてる角度
    static int value[12] = {0}; //安定した値を入れる変数
    int pulseWidth[12] = {0};   //生の値を入れる変数
    double x = 0, y = 0;
    uint32_t startTime = micros();
    do {
        for (byte i = 0; i < 12; i++) {
            if (digitalRead(ballPin[i]) == LOW) { //センサーが反応してる(LOW)時
                pulseWidth[i] += 1;
            }
        }
    } while ((micros() - startTime) < 833);
    for (byte i = 0; i < 12; i++) {
        value[i] = (value[i] * 0.7) + (pulseWidth[i] * 0.3); //値を安定させる
        x += value[i] * cos(radians(sensorDeg[i]));
        y += value[i] * sin(radians(sensorDeg[i]));
        ballDistance += value[i];
    }
    if ((x == 0) && (y == 0)) { // ボールが見つからない場合
        ballDeg = 1000.0;
        ballDistance = 0;
    } else {
        ballDeg = degrees(atan2(y, x));
        //ballDeg = round(ballDeg / 5.0) * 5.0;   //値を安定させるために5°単位にする
        ballDistance = (int)(round(ballDistance / 120) * 10);   //平均をとって10単位にする
    }
    if (isDisplay_ball) {
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.printf("%3d %3d %3d %3d\r\n", value[0], value[1], value[2], value[3]); //1行で書けるが、分かりやすさのために\r\nで区切った
        oled.printf("%3d %3d %3d %3d\r\n", value[4], value[5], value[6], value[7]);
        oled.printf("%3d %3d %3d %3d\r\n", value[8], value[9], value[10], value[11]);
        oled.print("\r\nDeg= ");
        oled.println(ballDeg, 1);
        oled.printf("Distance= %3d", ballDistance);
    }
}

bool judgeIsHoldBall() {
    if (analogRead(CATCH_PIN) < 300) {
        return true;
    } else {
        return false;
    }
}

void getLine() {
    const int threshold = 750;
    int line[8] = {0};
    for (byte i = 0; i < 8; i++) {
        line[i] = analogRead(linePin[i]);
        if (line[i] > threshold) {
            isLine[i] = true;
        } else {
            isLine[i] = false;
        }
    }
    if (isDisplay_line) {
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.printf("Front:%4d %4d\r\n", line[0], line[1]); //1行で書けるが、分かりやすさのために\r\nで区切った
        oled.printf("Right:%4d %4d\r\n", line[2], line[3]);
        oled.printf("BACK :%4d %4d\r\n", line[4], line[5]);
        oled.printf("Left :%4d %4d\r\n", line[6], line[7]);
        oled.printf("F&R:");
        for (byte i = 0; i < 8; i++) {
            if (i == 4) oled.print("\r\nB&L:");
            oled.print(' ');
            oled.print(isLine[i]);
        }
    }
}

bool judgeIsLine() {
    for (byte i = 0; i < 8; i++) {
        if (isLine[i]) return true;
    }
    return false;
}

void startGyro() {
    // I2Cバスに参加（I2Cdevライブラリはこれを自動的に行わない）
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.setSCL(PB10); // I2Cのピン設定
    Wire.setSDA(PB3);
    Wire.begin();
    Wire.setClock(400000); // コンパイルが困難な場合はこの行をコメント化
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif
    // Serial通信を初期化
    Serial.begin(9600);
    // デバイスを初期化
    mpu.initialize();
    pinMode(GYRO_INT, INPUT);

    // 接続を確認
    oled.fillScreen(BLACK);
    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.println("MPU connection");
    oled.println(mpu.testConnection() ? F("successful") : F("failed"));

    // DMPをロード&設定
    devStatus = mpu.dmpInitialize();

    // 最小感度に合わせてスケーリングされた、独自のジャイロオフセットを指定
    mpu.setXGyroOffset(-84);
    mpu.setYGyroOffset(-31);
    mpu.setZGyroOffset(8);
    mpu.setZAccelOffset(2242);

    //機能したことを確認（機能する場合は0を返す）
    if (devStatus == 0) {
        // オフセットを生成し、MPU6050を校正する
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        // DMPをオンにして準備完了
        mpu.setDMPEnabled(true);

        // Arduino割り込み検出を有効にする
        attachInterrupt(digitalPinToInterrupt(GYRO_INT), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        // DMP Readyフラグを設定、loop()関数がこれを使用して良いことを認識する
        oled.println("DMP ready!");
        dmpReady = true;
        // ここら辺にdelay()関数を入れると最初のgetGyro()が失敗する
        // 後で比較するために予想されるDMPパケットサイズを取得する
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        //エラー！
        // 1 = 初期メモリの読み込みに失敗
        // 2 = DMP構成の更新に失敗
        //（壊れる場合、通常1になる）
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.printf("DMP Initialization failed (code %d)", devStatus);
        delay(5000);
        target = 0;
        return;
    }
    Serial.end();   //今後はSerialを使わない

    float gyro = getGyro();
    if (gyro == 1000.0) {
        displayText("dmpReady = false", 0, 32, RED);
        delay(5000);
    } else if (gyro == 2000.0) {
        displayText("getGyro() failed", 0, 32, RED);
        delay(5000);
    } else {
        target = gyro; //ターゲット設定
        oled.println("\r\ngetGyro()\r\n successful");
        delay(1000);
    }
}

float getGyro() {
    // プログラムが失敗した場合は何もしない
    if (!dmpReady) return 1000.0;

    // MPU割り込みまたは利用可能な追加パケットを待つ
    while (!mpuInterrupt && fifoCount < packetSize) {
        if (mpuInterrupt && fifoCount < packetSize) {
            // 無限ループから抜け出そうとする
            fifoCount = mpu.getFIFOCount();
        }
        // 本当に偏執的である場合は他のものとの間で頻繁に
        // テストして、mpuInterruptがtrueであるかどうかを確認できる。
        // trueの場合はwhile()ループからbreak;してMPUデータをすぐに処理する。
    }

    // 割り込みフラグをリセットし、INT_STATUSバイトを取得
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // 現在のFIFOカウントを取得
    fifoCount = mpu.getFIFOCount();
    if (fifoCount < packetSize) {
        // 戻って別の割り込みを待つ。別のイベントから割り込みを受けている状態であるから、ここに入るべきでない。
        // これはブロックしているからwhile (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();の間は行わないで
    } else if ((mpuIntStatus & (0x01 << MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024) {  // オーバーフローをチェック（コードが非効率的でない限りこれは発生しない）
        // 正常に続行できるようにリセットする
        mpu.resetFIFO();
        // fifoCount = mpu.getFIFOCount();  // リセット後0になるだろうから、問う(?)必要はない
    } else if (mpuIntStatus & (0x01 << MPU6050_INTERRUPT_DMP_INT_BIT)) {    // それ以外の場合はDMPデータ準備割り込みを確認（これは頻繁に発生する）
        // FIFOからパケットを読み取る
        while (fifoCount >= packetSize) { // 今に追いつこう、恐ろしいdelay()を使用している！
            mpu.getFIFOBytes(fifoBuffer, packetSize);
            // 利用可能なパケットが1つ以上ある場合は、ここでFIFOカウントを追跡する
            //（これにより割り込みを待たずにすぐに続きを読むことができる）
            fifoCount -= packetSize;
        }
        //オイラー角を度数で表す
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        return degrees(ypr[0]);
    }
    return 2000.0;    //最後のelse ifに入らなかった場合
}

float getGyroPID() {
    const float Kp = 1.2, Ki = 0.2, Kd = 0.05, Imax = 80;
    static float pre_diff = 0, I = 0;
    static uint32_t pre_time = 0;
    float gyro = getGyro();             // 現在の角度を取得
    uint32_t now_time = micros();  // 現在の時間を取得
    // エラーの時
    if (gyro >= 1000) {
        return 0;
    }
    float diff = gyro - target; // 偏差を計算
    //-179 <= diff <= 180にする
    if (diff > 180) {
        diff -= 360;
    } else if (diff < -179) {
        diff += 360;
    }

    float dt = (float)(now_time - pre_time) * 1.0e-6;   // 経過時間を計算
    float P = Kp * diff;                    // Pを計算
    I += Ki * ((diff + pre_diff) / 2) * dt; // Iを計算
    I = constrain(I, -Imax, Imax);          // Iは大きくなりすぎないようにする
    float D = Kd * (diff - pre_diff) / dt;  // Dを計算
    pre_time = now_time;    // 現在の時間を保存
    pre_diff = diff;        // 現在の偏差を保存

    if (isDisplay_gyro) {
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.print("target= ");
        oled.println(target);
        oled.print("gyro=   ");
        oled.println(gyro);
        oled.print("diff=   ");
        oled.println(diff);
        oled.print("P=   ");
        oled.println(P);
        oled.print("I=   ");
        oled.println(I);
        oled.print("D=   ");
        oled.println(D);
        oled.print("PID= ");
        oled.print(P + I + D);
    }
    return P + I + D;
}

byte getPSD() {
    int cm;
    cm = analogRead(PSD_PIN);       // アナログ値を読む
    cm = map(cm, 0, 1023, 0, 330);  // 生値から電圧値に変換する(0~1023 -> 0~3.3V)
    cm = map(cm, 55, 225, 50, 4);   // 電圧値から距離に変換する(0.5~2.2V -> 50~4cm)
    if ((cm < 4) || (50 < cm)) cm = 0;

    if (isDisplay_psd) {
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.printf("psd = %2d cm", cm);
    }
    return (byte)cm;
}

void getCamera() {
    const int16_t char_buf = 10;
    int16_t temp = 0;
    char buff[char_buf] = {0};
    String str;
    static int32_t data;
    static uint32_t startTime;
    static bool update = false;
    SPI.beginTransaction(spi);
    digitalWrite(CAMERA_SS, LOW);
    delayMicroseconds(30); //Give the OpenMV Cam some time to setup to send data.
    if (SPI.transfer(1) == 85) { //saw sync char?
        SPI.transfer(&temp, 4); //get length
        int zero_legnth = 4 + ((temp + 1) % 4);
        if (temp) {
            SPI.transfer(&buff, min(temp, char_buf));
            temp -= min(temp, char_buf);
        }
        while (temp--) SPI.transfer(0); //eat any remaining bytes
        while (zero_legnth--) SPI.transfer(0); //eat zeros.
    }
    digitalWrite(CAMERA_SS, HIGH);
    SPI.endTransaction();
    str = buff;
    if (str.toInt() == 0) { //ゴールが見つからない時
        if (update) { //1回前までゴールが見えていた時
            startTime = millis();
            update = false;
        }
        if ((millis() - startTime) > 500) { //500msの間、値が更新されなかったら0にする
            data = 0;
        }
    } else {
        update = true;
        data = str.toInt();
    }
    if (data == 0) {
        goalState = 0;
        goalDistance = 0;
        goalDeg = 1000;
    } else {
        goalState = data / 1000000;
        goalDistance = (data % 1000000) / 1000;
        goalDeg = (data % 1000) - 90;
        if (goalDeg > 180) { //-179 <= goalDeg <= 180にする
            goalDeg -= 360;
        } else if (goalDeg < -179) {
            goalDeg += 360;
        }
    }
    if (isDisplay_camera) {
        oled.fillScreen(BLACK);
        oled.setCursor(0, 0);
        oled.printf("Deg = %4d \r\nDistance = %4d", goalDeg, goalDistance);
    }
}

void kickTest() {
    bool preValue = HIGH, value;  //ピンの状態
    oled.fillScreen(BLACK);
    displayText("Kicker", 0, 0);
    oled.setTextSize(3);
    displayText("OFF", (oled.width() / 2) - 23, (oled.height() / 2) - 8, BLUE);
    while (true) {
        switch (displayButton()) {
            case 0:
                value = LOW;
                break;
            case 1:
                value = HIGH;
                break;
            case 2:
                goto out;
        }
        if ((value != preValue) && (value == HIGH)) { //ピンが LOW -> HIGH になったとき
            displayText("OFF", (oled.width() / 2) - 23, (oled.height() / 2) - 8, BLACK);
            displayText("ON", (oled.width() / 2) - 15, (oled.height() / 2) - 8, RED);
            digitalWrite(KICK_PIN, HIGH);
            delay(300); //安全のため300msだけONにする
            digitalWrite(KICK_PIN, LOW);
            displayText("ON", (oled.width() / 2) - 15, (oled.height() / 2) - 8, BLACK);
            displayText("OFF", (oled.width() / 2) - 23, (oled.height() / 2) - 8, BLUE);
        }
        preValue = value;
        delay(100);
    }
out:
    oled.setTextSize(1);
}

void kick() {
    if (!isKick) {
        digitalWrite(KICK_PIN, HIGH);
        kickTime = millis();
        isKick = true;
    }
}

void stop() {
    for (byte i = 0; i < 4; i++) {
        analogWrite(pwmPin[i], 0);
    }
}

void faceTarget() {
    float diff = getGyroPID();
    diff = constrain(diff, -255, 255);
    if (digitalRead(SWITCH_PIN) == HIGH) {
        for (byte i = 0; i < 4; i++) {
            if (diff >= 0) {
                digitalWrite(dirPin[i], LOW);
                analogWrite(pwmPin[i], (byte)diff);
            } else {
                digitalWrite(dirPin[i], HIGH);
                analogWrite(pwmPin[i], (byte)(-diff));
            }
        }
    } else {
        stop();
    }
}

void move(double deg, float diff) {
    const double powerChange = 2.0, MDeg[4] = {50.0, 130.0, 230.0, 310.0};  //パワーの変化率、モーターの付いてる角度
    static bool isStart = true;     // モーターを回し始めたかどうか
    double maxpower = 0.0, Mpower_fabs = 0.0, Mpower[4] = {0.0};    //最大パワー, 各モーターのパワー
    if (deg == 1000.0) {
        if (fabs(diff) < 10.0) {
            stop();
        } else {
            faceTarget();
        }
    } else {
        for (byte i = 0; i < 4; i++) {
            Mpower[i] = sin(radians(MDeg[i] - deg)) + (diff / 50.0);    //各モーターのパワーを計算 動きながら向きを直す
            Mpower_fabs = fabs(Mpower[i]);
            //最大パワーを求める
            if (Mpower_fabs > maxpower) {
                maxpower = Mpower_fabs;
            }
        }
        if ((digitalRead(SWITCH_PIN) == HIGH) && (maxpower != 0.0)) {
            if (isStart) {
                if (power < MAXPOWER) power += powerChange;
                else isStart = false;
            }
            for (byte i = 0; i < 4; i++) {
                Mpower[i] = Mpower[i] * power / maxpower;       // 比率をpowerに合わせる
                if (Mpower[i] >= 0) {
                    digitalWrite(dirPin[i], LOW);               // 向きを指定
                    analogWrite(pwmPin[i], (byte)Mpower[i]);    // パワーを指定
                } else {
                    digitalWrite(dirPin[i], HIGH);              // 向きを指定
                    analogWrite(pwmPin[i], (byte)(-Mpower[i])); // パワーを指定
                }
            }
        } else {
            if (!isStart) isStart = true;
            if (power > MINPOWER) power -= powerChange;
            else stop();
        }
    }
}

void wrapAroundBall() {
    const double plusDeg = 42.0, goForwardDeg = 5.0;
    if (ballDeg == 1000.0) {
        moveDeg == 1000.0;
    } else if (judgeIsHoldBall() || (fabs(ballDeg) <= goForwardDeg)) {
        moveDeg = 0;
    } else if (ballDeg > goForwardDeg) {
        moveDeg = ballDeg + sqrt((ballDeg * plusDeg) + 540);
    } else if (ballDeg < -goForwardDeg) {
        moveDeg = ballDeg - sqrt((-ballDeg * plusDeg) + 540);
    } else {
        moveDeg = 1000.0;
    }
}

void avoidLine() {
    const double powerChange = 5.0;
    static uint32_t pre_time;
    static bool isWait = false, isGoForward = false;
    double x = 0.0, y = 0.0;
    if (judgeIsLine() || lineState != 0) {
        switch (lineState) {
            case 0:
                if (moveDeg == 0.0) isGoForward = true;
                else isGoForward = false;
                moveDeg = 1000.0;   // 止める
                lineState = 1;      // 1に進む
                break;
            case 1:
                /*  if (power > MINPOWER) power -= powerChange;  // モーターの負担を減らすためpowerを徐々に下げてく
                    else {
                    stop();*/
                lineState = 2;  // 2に進む
                /*}*/
                break;
            case 2:
                // ライン上にいる場合
                if (judgeIsLine()) {
                    if (power < MAXPOWER) power += powerChange; // モーターの負担を減らすためpowerを徐々に上げてく
                    if (isGoForward) x -= 1.5;
                    if (isLine[1]) x -= 1.5;
                    else if (isLine[0]) x -= 1.0;
                    if (isLine[3]) y -= 1.5;
                    else if (isLine[2]) y -= 1.0;
                    if (isLine[5]) x += 1.5;
                    else if (isLine[4]) x += 1.0;
                    if (isLine[7]) y += 1.5;
                    else if (isLine[6]) y += 1.0;
                    moveDeg = degrees(atan2(y, x));
                    if (fabs(moveDeg - pre_moveDeg) > 60) {
                        isWait = false;
                        lineState = 1;  // 1に戻る
                    }
                } else {    // コート内にいる場合
                    getBall();
                    double degDiff = fabs(pre_moveDeg - ballDeg);   // 動いた角度とボールの角度の差の絶対値をとる
                    if (degDiff > 180) degDiff = 360 - degDiff;
                    if (degDiff < 90) { // 差の絶対値が90°未満だったらボールを追いかける
                        if (isWait) isWait = false; //もしisWaitがtrueになってたらfalseに戻す
                        lineState = 3;  // 3に進む
                    } else {            // 差の絶対値が90°以上だったら待つ
                        if (power > MINPOWER) power -= powerChange; // モーターの負担を減らすためpowerを徐々に下げてく
                        else {
                            if (!isWait) {
                                pre_time = millis();
                                moveDeg = 1000.0;
                                isWait = true;
                            } else if ((millis() - pre_time) > 2000) {
                                isWait = false;
                                lineState = 3; // 2秒待って、3に進む
                            }
                        }
                    }
                }
                break;
            case 3:
                if (judgeIsLine()) lineState = 1;   // 1に戻る
                else {
                    if (power < MAXPOWER) power += powerChange; // モーターの負担を減らすためpowerを徐々に上げてく
                    else lineState = 0;                         // 0にする (コート内に戻り、powerも元通りになった)
                }
                break;
        }
    }
}

void startDisplay() {
    byte triX = 0, triY = 0, num = 0;  //三角形の位置
    bool isPlay = false, isLoop = true;
    byte buttonState = 0, title_num = 8;
    oled.setTextSize(1);
    displayFirstScene();
    //辺の長さに0を含んだり、割った時に切り捨てられたりすることを考えると下の引数が丁度良い
    oled.fillTriangle(0, 0, 0, triangleSize - 1, (byte)(triangleSize * sqrt(3) / 2), (byte)(triangleSize / 2), WHITE); //頂点1,頂点2,頂点3,色
    while (isLoop) {
        buttonState = displayButton();
        if (buttonState == 1) {  //ボタン短押しのとき　三角形の移動
            oled.fillTriangle(triX, triY, triX, triangleSize - 1 + triY, (byte)(triangleSize * sqrt(3) / 2) + triX, (byte)(triangleSize / 2) + triY, BLACK);  //前の三角形を消す
            num = (num + 1) % title_num;
            if (num <= 4)  triX = 0;
            else triX = oled.width() / 2;
            triY = y_space * (num % 5);
            oled.fillTriangle(triX, triY, triX, triangleSize - 1 + triY, (byte)(triangleSize * sqrt(3) / 2) + triX, (byte)(triangleSize / 2) + triY, WHITE);
        } else if (buttonState == 2) { //ボタン長押しのとき
            switch (num) {
                case 0:
                    if (isPlay) isLoop = false;
                    else {
                        isPlay = true;
                        title_num = 7;
                    }
                    break;
                case 1:
                    isDisplay_ball = true;
                    if (isPlay) {
                        isLoop = false;
                    } else {
                        while (displayButton() != 2) {
                            getBall();
                            delay(50);
                        }
                        isDisplay_ball = false;
                    }
                    break;
                case 2:
                    isDisplay_line = true;
                    if (isPlay) {
                        isLoop = false;
                    } else {
                        while (displayButton() != 2) {
                            getLine();
                            delay(50);
                        }
                        isDisplay_line = false;
                    }
                    break;
                case 3:
                    isDisplay_gyro = true;
                    if (isPlay) {
                        isLoop = false;
                    } else {
                        while (displayButton() != 2) {
                            getGyroPID();
                            delay(50);
                        }
                        isDisplay_gyro = false;
                    }
                    break;
                case 4:
                    isDisplay_psd = true;
                    if (isPlay) {
                        isLoop = false;
                    } else {
                        while (displayButton() != 2) {
                            getPSD();
                            delay(50);
                        }
                        isDisplay_psd = false;
                    }
                    break;
                case 5:
                    isDisplay_camera = true;
                    if (isPlay) {
                        isLoop = false;
                    } else {
                        while (displayButton() != 2) {
                            getCamera();
                            delay(100);
                        }
                        isDisplay_camera = false;
                    }
                    break;
                case 6:
                    if (isPlay) {
                        isPlay = false;
                        title_num = 8;
                    }
                    else kickTest();
                    break;
                case 7:
                    displayMusicMenu();
                    break;
            }
            if (isLoop) {
                if (!isPlay) displayFirstScene();
                else displaySecondScene();
                oled.fillTriangle(triX, triY, triX, triangleSize - 1 + triY, (byte)(triangleSize * sqrt(3) / 2) + triX, (byte)(triangleSize / 2) + triY, WHITE);
            } else {
                oled.fillScreen(BLACK);
                if (digitalRead(SWITCH_PIN) == HIGH) {
                    displayText("Worning!\r\n\nMOTOR SWITCH IS ON", 0, 0);
                    while (digitalRead(SWITCH_PIN) == HIGH);    // SWITCH_PINをLOWにするまで待つ
                    oled.fillScreen(BLACK);
                }
                oled.setTextSize(2);
                displayText("PLAY!", (oled.width() / 2) - 25, (oled.height() / 2) - 5, GREEN);
                oled.setTextSize(1);
                oled.setTextColor(WHITE);
                delay(2000);
                oled.fillScreen(BLACK);
            }
        }
        delay(100);
    }
}

void displayText(char* text, byte x, byte y, uint16_t color) {
    oled.setTextColor(color);
    oled.setCursor(x, y);
    oled.print(text);
}

void displayFirstScene() {
    byte x = 10;
    oled.fillScreen(BLACK);
    displayText("play", x, 0, GREEN);
    displayText("ball", x, y_space);
    displayText("line", x, y_space * 2);
    displayText("gyro", x, y_space * 3);
    displayText("psd", x, y_space * 4);
    displayText("camera", (oled.width() / 2) + x, 0);
    displayText("kicker", (oled.width() / 2) + x, y_space);
    displayText("music", (oled.width() / 2) + x, y_space * 2);
}

void displaySecondScene() {
    byte x = 10;
    oled.fillScreen(BLACK);
    displayText("none", x, 0, GREEN);
    displayText("ball", x, y_space);
    displayText("line", x, y_space * 2);
    displayText("gyro", x, y_space * 3);
    displayText("psd", x, y_space * 4);
    displayText("camera", (oled.width() / 2) + x, 0);
    displayText("back", (oled.width() / 2) + x, y_space, MAGENTA);
    oled.setTextColor(WHITE);
}

void displayMusicMenu() {
    char* title[] = {"back", "DarthVader", "Doremi", "DraQue_LevelUP", "DraQue_Main", "Pokemon", "StarWars", "Mario", "Zelda"};
    byte triX = 0, triY = 0, num = 0, prenum = 0;  //三角形の位置
    byte buttonState = 0, title_num = 9;
    bool isMusic = true;
    oled.fillScreen(BLACK);
    displayText(title[0], 10, 0, MAGENTA);
    for (byte i = 1; i < 5; i++) {
        displayText(title[i], 10, y_space * i);
    }
    oled.fillTriangle(0, 0, 0, triangleSize - 1, (byte)(triangleSize * sqrt(3) / 2), (byte)(triangleSize / 2), WHITE); // 頂点1,頂点2,頂点3,色
    while (isMusic) {
        buttonState = displayButton();
        if (buttonState == 1) {  // ボタン短押しのとき　三角形の移動
            // 前の三角形を消す
            oled.fillTriangle(triX, triY, triX, triangleSize - 1 + triY, (byte)(triangleSize * sqrt(3) / 2) + triX, (byte)(triangleSize / 2) + triY, BLACK);
            num = (num + 1) % title_num;
            triY = y_space * (num % 5);
            if (num != prenum && (num % 5) == 0) {
                oled.fillScreen(BLACK);
                for (byte i = 0; i < 5; i++) {
                    if (num == 0 && i == 0) displayText(title[0], 10, 0, MAGENTA);
                    else displayText(title[i + num], 10, y_space * i);

                    if (num == 5 && i == 3) break;  // 後半は4曲しかないためbreak;する
                }
            }
            oled.fillTriangle(triX, triY, triX, triangleSize - 1 + triY, (byte)(triangleSize * sqrt(3) / 2) + triX, (byte)(triangleSize / 2) + triY, WHITE);
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
        prenum = num;
    }
}

byte displayButton() {  //ボタンを 0:押してない 1;短押し(1秒未満) 2:長押し
    uint32_t preTime;
    const int rectX = oled.width() - 10, rectY = oled.height() - 10, rectWidth = 10, rectHeight = 10;
    if (digitalRead(BUTTON_PIN) == HIGH) {
        preTime = millis();
        while (digitalRead(BUTTON_PIN) == HIGH) {
            if ((millis() - preTime) < 1000) oled.fillRect(rectX, rectY, rectWidth, rectHeight, YELLOW);
            else oled.fillRect(rectX, rectY, rectWidth, rectHeight, RED);
            delay(20);
        }
        if ((millis() - preTime) < 1000) return 1;  //短押しのとき
        else return 2;  //長押しのとき
    } else {
        oled.fillRect(rectX, rectY, rectWidth, rectHeight, BLUE);
        return 0;
    }
}
