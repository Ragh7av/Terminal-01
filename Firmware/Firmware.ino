// Don't forget to put your Wi-Fi name and password in the `ssid` and `password` variables at the top!

// ====== WiFi & Time config ======
#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "time.h"

// ====== WiFi & Time config ======
const char* ssid      = "Your_wifi"; 
const char* password  = "pass";      
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec      = 19800;   // IST is UTC+5:30 (5.5 * 3600)
const int   daylightOffset_sec = 0;       

// ====== Optimized Pins for ESP32-C3 Super Mini ======
#define TFT_SCLK  4   
#define TFT_MOSI  6   
#define TFT_CS    7   
#define TFT_DC    10  
#define TFT_RST   20  

#define TFT_SCLK     4   
#define TFT_MOSI     6   
#define TFT_CS       7   
#define TFT_DC       10  
#define TFT_RST      20  
#define ENC_A_PIN    21  
#define ENC_B_PIN    8   
#define ENC_BTN_PIN  9   

#define SPEAKER_PIN  3   // Re-added the speaker pin!
#define SPEAKER_PIN  3   // Audio pin

// ====== TFT ======
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
@@ -193,7 +191,8 @@ void drawClockTime(String hourStr, String minStr, String secStr) {
  int x = (160 - w) / 2;
  int y = 50;

  tft.fillRect(0, y, 160, h + 2, CYBER_BG);
  // FIX 1: Removed fillRect here to prevent screen flickering. 
  // setTextColor with the background parameter completely overwrites old text flawlessly.
  tft.setTextColor(CYBER_ACCENT, CYBER_BG);
  tft.setCursor(x, y);
  tft.print(cur);
@@ -264,7 +263,6 @@ void drawPomodoroScreen(bool forceStatic) {
    drawAlarmIcon();
  }

  // Visual Flashing Alert when Done
  if (pomoState == POMO_DONE) {
     if ((millis() / 500) % 2 == 0) {
         tft.fillScreen(CYBER_RED);
@@ -275,7 +273,7 @@ void drawPomodoroScreen(bool forceStatic) {
     } else {
         tft.fillScreen(CYBER_BG);
     }
     return; // Skip normal drawing
     return; 
  }

  tft.setTextSize(1);
@@ -375,7 +373,9 @@ void checkAlarmTrigger() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return;

  if (timeinfo.tm_hour == alarmHour && timeinfo.tm_min == alarmMinute && timeinfo.tm_sec == 0) {
  // FIX 2: Added lastAlarmDayTriggered check to prevent the alarm from triggering 
  // repeatedly in an infinite loop during the exact minute it fires.
  if (timeinfo.tm_hour == alarmHour && timeinfo.tm_min == alarmMinute && timeinfo.tm_sec == 0 && lastAlarmDayTriggered != timeinfo.tm_mday) {
    alarmRinging = true;
    lastAlarmDayTriggered = timeinfo.tm_mday;
    currentMode = MODE_ALARM;
@@ -388,17 +388,14 @@ const int COURT_W = 144; const int COURT_H = 96;
const int PADDLE_W = 18; const int PADDLE_H = 4;
const int PADDLE_Y = COURT_Y + COURT_H - 8;
const int ALIEN_ROWS = 3; const int ALIEN_COLS = 8;

bool alienAlive[ALIEN_ROWS][ALIEN_COLS];
int  alienOffsetX = 0; int alienDir = 1;   
unsigned long lastAlienMoveMs = 0;
unsigned long alienMoveInterval = 250;

bool  bulletActive = false;
int   bulletX = 0, bulletY = 0;
unsigned long lastBulletMoveMs = 0;
unsigned long bulletInterval = 25;

int  playerX = COURT_X + (COURT_W - PADDLE_W) / 2;
int  gameScore = 0;
bool gameOver  = false;
@@ -456,6 +453,8 @@ void drawBullet() {

void updateGameLogic(int encStep, bool firePressed, bool backPressed) {
  if (backPressed) {
    // FIX 3: Added missing noTone command ensuring audio cleanup before exiting modes.
    noTone(SPEAKER_PIN); 
    gameInited = false; currentMode = MODE_MENU; drawMenu(); return;
  }
  if (gameOver) {
@@ -476,7 +475,7 @@ void updateGameLogic(int encStep, bool firePressed, bool backPressed) {
    bulletActive = true;
    bulletX = playerX + PADDLE_W / 2;
    bulletY = PADDLE_Y - 2;
    tone(SPEAKER_PIN, 1800, 40); // Game Pew Pew Sound
    tone(SPEAKER_PIN, 1800, 40); 
  }

  unsigned long now = millis();
@@ -494,8 +493,13 @@ void updateGameLogic(int encStep, bool firePressed, bool backPressed) {
        if (x > rightMost) rightMost = x;
      }
    }
    if (leftMost + 4 < 0)  alienDir = 1;
    if (rightMost + 12 > COURT_W) alienDir = -1;
    
    // FIX 4: Implemented absolute bounds logic to prevent the game matrix from clipping boundaries.
    int absoluteLeft = COURT_X + 4 + leftMost;
    int absoluteRight = COURT_X + 4 + rightMost + 8;
    if (absoluteLeft <= COURT_X + 2) alienDir = 1;
    if (absoluteRight >= COURT_X + COURT_W - 2) alienDir = -1;
    
    drawAliens();
  }

@@ -514,7 +518,7 @@ void updateGameLogic(int encStep, bool firePressed, bool backPressed) {
          if (bulletX >= alienX && bulletX <= alienX + 8 && bulletY >= alienY && bulletY <= alienY + 6) {
            alienAlive[r][c] = false; bulletActive = false;
            gameScore += 10; drawScore();
            tone(SPEAKER_PIN, 2200, 60); // Alien hit sound
            tone(SPEAKER_PIN, 2200, 60); 
          }
        }
      }
@@ -565,6 +569,7 @@ void initDvd() {
void updateDvd(int encStep, bool encPressed, bool backPressed) {
  (void)encPressed;
  if (backPressed) {
    noTone(SPEAKER_PIN); // Safety cleanup
    dvdInited = false; currentMode = MODE_MENU; drawMenu(); return;
  }
  if (encStep != 0) {
@@ -603,7 +608,7 @@ void setup() {
  pinMode(ENC_A_PIN,   INPUT_PULLUP);
  pinMode(ENC_B_PIN,   INPUT_PULLUP);
  pinMode(ENC_BTN_PIN, INPUT_PULLUP);
  pinMode(SPEAKER_PIN, OUTPUT); // Speaker output
  pinMode(SPEAKER_PIN, OUTPUT); 

  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
  tft.initR(INITR_BLACKTAB);
@@ -626,8 +631,6 @@ void loop() {

  int encStep = readEncoderStep();
  updateEncoderButton(); 
  // encShortPressed = Select / Fire
  // encLongPressed  = Back / Exit

  checkAlarmTrigger();

@@ -668,14 +671,17 @@ void loop() {
          drawClockTime(getTimeStr('H'), getTimeStr('M'), getTimeStr('S'));
        }
      }
      if (encLongPressed || encShortPressed) { currentMode = MODE_MENU; drawMenu(); }
      if (encLongPressed || encShortPressed) { 
        noTone(SPEAKER_PIN); // Safety cleanup
        currentMode = MODE_MENU; 
        drawMenu(); 
      }
      break;
    }

    case MODE_POMODORO: {
      if (pomoState == POMO_DONE) {
        drawPomodoroScreen(false); 
        // Beep loudly when done
        if ((millis() / 500) % 2 == 0) {
          tone(SPEAKER_PIN, 2000, 250);
        }
@@ -712,14 +718,17 @@ void loop() {
          if (remainSec != prevPomoRemainSec) { prevPomoRemainSec = remainSec; drawPomodoroScreen(false); }
        }
      }
      if (encLongPressed) { noTone(SPEAKER_PIN); currentMode = MODE_MENU; drawMenu(); }
      if (encLongPressed) { 
        noTone(SPEAKER_PIN); 
        currentMode = MODE_MENU; 
        drawMenu(); 
      }
      break;
    }

    case MODE_ALARM: {
      if (alarmRinging) {
        drawAlarmRingingScreen();
        // Ring the speaker!
        if ((millis() / 500) % 2 == 0) {
           tone(SPEAKER_PIN, 2000, 400); 
        }
@@ -742,7 +751,12 @@ void loop() {
        if (changed) lastAlarmDayTriggered = -1;
      }
      if (encShortPressed) { alarmSelectedField = (alarmSelectedField + 1) % 3; changed = true; }
      if (encLongPressed) { currentMode = MODE_MENU; drawMenu(); break; }
      if (encLongPressed) { 
        noTone(SPEAKER_PIN); 
        currentMode = MODE_MENU; 
        drawMenu(); 
        break; 
      }
      if (changed) { drawAlarmScreen(false); drawAlarmIcon(); }
      break;
    }