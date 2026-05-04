#include <LedControl.h>

#define DIN 11
#define CS 10
#define CLK 13

#define JOY_X A0
#define JOY_Y A1
#define JOY_SW 4
#define BUZZER 3

LedControl lc = LedControl(DIN, CLK, CS, 1);

// Game state
int paddleX = 2; // 5-pixel wide paddle starts at col 2
int ballX = 3, ballY = 5;
int ballDirX = 1, ballDirY = -1;
int ballSpeed = 350;

// To Do 1
byte bricks[4]; // 4 rows of 8 bricks

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int melodyLength = sizeof(melody) / sizeof(melody[0]);

// Faces
byte smiley[8] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

byte sad[8] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

void setup() {
  // To Do 2
  pinMode(JOY_SW, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  initBricks();
}

void loop() {
  // To Do 3
  drawGame();
  playMusic();
  moveBall();
  readJoystick();
  delay(ballSpeed);
  checkWin();
}

void showSmiley() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, smiley[i]);
  }
  delay(3000);
  lc.clearDisplay(0);
}

void showSad() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, sad[i]);
  }
  tone(BUZZER, 110, 500);
  delay(3000);
  lc.clearDisplay(0);
  resetGame();
}

void resetGame() {
  paddleX = 2;
  ballX = 3;
  ballY = 5;
  ballDirX = 1;
  ballDirY = -1;
  ballSpeed = 400;
  initBricks();
}

void initBricks() {
  for (int i = 0; i < 4; i++) {
    bricks[i] = B11111111;
  }
}

void drawGame() {
  lc.clearDisplay(0);

  for (int row = 0; row < 4; row++) {
    lc.setRow(0, row, bricks[row]);
  }

  for (int i = 0; i < 5; i++) {
    if (paddleX + i < 8) {
      lc.setLed(0, 7, paddleX + i, true);
    }
  }

  lc.setLed(0, ballY, ballX, true);
}

void readJoystick() {
  int xVal = analogRead(JOY_X);
  if (xVal < 400 && paddleX > 0) {
    paddleX--;
    delay(50);
  } else if (xVal > 600 && paddleX < (8 - 5)) {
    paddleX++;
    delay(50);
  }
}

void moveBall() {
  int nextX = ballX + ballDirX;
  int nextY = ballY + ballDirY;

  if (nextX < 0 || nextX > 7) {
    ballDirX *= -1;
    nextX = ballX + ballDirX;
  }

  if (nextY < 0) {
    ballDirY *= -1;
    nextY = ballY + ballDirY;
  }

  if (nextY < 4 && bitRead(bricks[nextY], nextX)) {
    bitClear(bricks[nextY], nextX);
    ballDirY *= -1;
    ballSpeed = max(100, ballSpeed - 20);
    tone(BUZZER, 880, 100);
    nextY = ballY + ballDirY;
  }

  if (nextY == 7 && nextX >= paddleX && nextX <= paddleX + 4) {
    ballDirY *= -1;
    tone(BUZZER, 660, 80);
    nextY = ballY + ballDirY;
  }

  if (nextY >= 8) {
    showSad();
    return;
  }

  ballX = nextX;
  ballY = nextY;
}

void checkWin() {
  for (int i = 0; i < 4; i++) {
    if (bricks[i] != 0) return;
  }

  showSmiley();
  resetGame();
}

void playMusic() {
  static unsigned long lastToneTime = 0;
  static int noteIndex = 0;

  if (millis() - lastToneTime > 200) {
    tone(BUZZER, melody[noteIndex], 100);
    noteIndex = (noteIndex + 1) % melodyLength;
    lastToneTime = millis();
  }
}