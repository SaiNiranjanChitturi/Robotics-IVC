int buzzer = 3;

// Notes
#define NOTE_E5 659
#define NOTE_G5 784
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_F5 698
#define NOTE_A5 880
#define NOTE_B5 988

// Melody (main + verse)
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,

  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5,

  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5,

  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5,
  NOTE_G5, NOTE_F5, NOTE_D5, NOTE_C5
};

// Note durations (smaller = faster)
int noteDurations[] = {
  4,4,2,
  4,4,2,
  4,4,4,4,1,

  4,4,4,4,
  4,4,4,8,8,
  4,4,4,4,2,2,

  4,4,2,
  4,4,2,
  4,4,4,4,1,

  4,4,4,4,
  4,4,4,8,8,
  4,4,4,4
};

void setup() {}

void loop() {
  int size = sizeof(melody) / sizeof(int);

  for (int i = 0; i < size; i++) {
    int duration = 1000 / noteDurations[i];
    tone(buzzer, melody[i], duration);

    int pause = duration * 1.3;
    delay(pause);
    noTone(buzzer);
  }

  delay(3000); // pause before repeating
}