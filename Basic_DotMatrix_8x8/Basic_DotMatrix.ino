#include <LedControl.h>

LedControl djBoard = LedControl(10, 12, 11, 1);

const long delayTime1 = 200;
const long delayTime2 = 50;

void setup() {
  djBoard.shutdown(0, false);
  djBoard.setIntensity(0, 3);
  djBoard.clearDisplay(0);
}

void randomBars() {
  djBoard.clearDisplay(0);

  byte Column1[] = {B00011111, B00000111, B01111111, B00000001};
  byte Column2[] = {B00111111, B01111111, B00001111, B00001111};
  byte Column3[] = {B01111111, B00000011, B00000001, B00111111};
  byte Column4[] = {B00001111, B00000001, B00011111, B11111111};

  for (int i = 0; i < 4; i++) {
    djBoard.setColumn(0, 0, Column1[i]);
    djBoard.setColumn(0, 1, Column2[i]);
    djBoard.setColumn(0, 2, Column3[i]);
    djBoard.setColumn(0, 3, Column4[i]);
    djBoard.setColumn(0, 4, Column1[i]);
    djBoard.setColumn(0, 5, Column2[i]);
    djBoard.setColumn(0, 6, Column3[i]);
    djBoard.setColumn(0, 7, Column4[i]);
    delay(delayTime1);
  }
}

void fillUp() {
  djBoard.clearDisplay(0);

  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      djBoard.setLed(0, row, col, true);
      delay(delayTime2);
    }
  }
}

void rowstrobeLight() {
  djBoard.clearDisplay(0);

  byte RowLight[4] = {B00011000, B00100100, B01000010, B10000001};

  for (int g = 0; g < 8; g++) {
    for (int f = 0; f < 4; f++) {
      djBoard.setRow(0, g, RowLight[f]);
      delay(50);
      djBoard.clearDisplay(0);
      delay(50);
    }
  }
}

void crossstrobeLight() {
  djBoard.clearDisplay(0);

  byte RowLight[4] = {B00011000, B00100100, B01000010, B10000001};

  int j = 0;
  int k = 4;
  int z = 3;

  for (int p = 0; p < 4; p++) {
    djBoard.clearDisplay(0);
    djBoard.setRow(0, k, RowLight[j]);
    djBoard.setRow(0, z, RowLight[j]);
    delay(50);
    djBoard.clearDisplay(0);
    delay(50);
    k++;
    z--;
    j++;
  }

  k = 7;
  z = 0;
  j = 3;

  for (int m = 0; m < 4; m++) {
    djBoard.clearDisplay(0);
    djBoard.setRow(0, k, RowLight[j]);
    djBoard.setRow(0, z, RowLight[j]);
    delay(50);
    djBoard.clearDisplay(0);
    delay(50);
    k--;
    z++;
    j--;
  }
}

void Arrow() {
  byte ArrowLight1[] = {
    0, 0, 0, 0, 0, 0, 0,
    B00010000, B00111000, B01010100, B00010000,
    B00010000, B00010000, B00010000, B00010000
  };

  for (int i = 0; i < 8; i++) {
    djBoard.clearDisplay(0);
    djBoard.setColumn(0, 7, ArrowLight1[i + 7]);
    djBoard.setColumn(0, 6, ArrowLight1[i + 6]);
    djBoard.setColumn(0, 5, ArrowLight1[i + 5]);
    djBoard.setColumn(0, 4, ArrowLight1[i + 4]);
    djBoard.setColumn(0, 3, ArrowLight1[i + 3]);
    djBoard.setColumn(0, 2, ArrowLight1[i + 2]);
    djBoard.setColumn(0, 1, ArrowLight1[i + 1]);
    djBoard.setColumn(0, 0, ArrowLight1[i]);
    delay(500);
  }

  byte ArrowLight2[] = {
    B00010000, B00111000, B01010100, B00010000,
    B00010000, B00010000, B00010000, B00010000,
    0, 0, 0, 0, 0, 0, 0, 0
  };

  for (int i = 1; i < 9; i++) {
    djBoard.clearDisplay(0);
    djBoard.setColumn(0, 7, ArrowLight2[i + 7]);
    djBoard.setColumn(0, 6, ArrowLight2[i + 6]);
    djBoard.setColumn(0, 5, ArrowLight2[i + 5]);
    djBoard.setColumn(0, 4, ArrowLight2[i + 4]);
    djBoard.setColumn(0, 3, ArrowLight2[i + 3]);
    djBoard.setColumn(0, 2, ArrowLight2[i + 2]);
    djBoard.setColumn(0, 1, ArrowLight2[i + 1]);
    djBoard.setColumn(0, 0, ArrowLight2[i]);
    delay(500);
  }
}

void birdFlap() {
  byte Column1[] = {B10000000, B00100000, B00001000, B10000000};
  byte Column2[] = {B01000000, B00100000, B00001000, B01000000};
  byte Column3[] = {B00100000, B00010000, B00001000, B00100000};
  byte Column4[] = {B00010000, B00010000, B00010000, B00010000};

  for (int i = 0; i < 4; i++) {
    djBoard.clearDisplay(0);
    djBoard.setColumn(0, 0, Column1[i]);
    djBoard.setColumn(0, 1, Column2[i]);
    djBoard.setColumn(0, 2, Column3[i]);
    djBoard.setColumn(0, 3, Column4[i]);
    djBoard.setColumn(0, 4, Column4[i]);
    djBoard.setColumn(0, 5, Column3[i]);
    djBoard.setColumn(0, 6, Column2[i]);
    djBoard.setColumn(0, 7, Column1[i]);
    delay(200);
  }
}

void PacMan() {
  byte Column1 = B00111100;
  byte Column2 = B01111110;
  byte Column3 = B11111111;
  byte Column4 = B11111111;
  byte Column5[] = {B11111111, B11100111};
  byte Column6[] = {B11111111, B11000011};
  byte Column7[] = {B01111110, B10000001};
  byte Column8[] = {B00111100, B00000000};

  for (int i = 0; i < 2; i++) {
    djBoard.clearDisplay(0);
    djBoard.setColumn(0, 0, Column1);
    djBoard.setColumn(0, 1, Column2);
    djBoard.setColumn(0, 2, Column3);
    djBoard.setColumn(0, 3, Column4);
    djBoard.setColumn(0, 4, Column5[i]);
    djBoard.setColumn(0, 5, Column6[i]);
    djBoard.setColumn(0, 6, Column7[i]);
    djBoard.setColumn(0, 7, Column8[i]);
    delay(500);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    randomBars();
  }

  fillUp();
  rowstrobeLight();

  for (int k = 0; k < 3; k++) {
    crossstrobeLight();
  }

  Arrow();

  for (int m = 0; m < 4; m++) {
    birdFlap();
  }

  for (int m = 0; m < 4; m++) {
    PacMan();
  }
}