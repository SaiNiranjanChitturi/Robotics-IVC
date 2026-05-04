int buzzer = 3;

// Note definitions
#define NOTE_E5 659
#define NOTE_DS5 622
#define NOTE_B4 494
#define NOTE_D5 587
#define NOTE_C5 523
#define NOTE_A4 440
#define NOTE_E4 330
#define NOTE_A3 220

// Melody (extended main theme)
int melody[] = {
  // Main motif
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5,
  NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4,

  // Response
  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_E5,
  NOTE_A4, NOTE_C5, NOTE_E5,

  // Repeat variation
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5,
  NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4,

  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_E5,
  NOTE_C5, NOTE_A4, NOTE_E4,

  // Bridge-like phrase
  NOTE_A3, NOTE_E4, NOTE_A4, NOTE_C5,
  NOTE_E5, NOTE_C5, NOTE_A4,
  NOTE_E4, NOTE_A4, NOTE_C5, NOTE_E5,

  // Ending phrase
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5,
  NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4
};

// Rhythm (lower = longer note)
int durations[] = {
  8,8,8,8,8,
  8,8,8,4,

  8,8,8,4,
  8,8,4,

  8,8,8,8,8,
  8,8,8,4,

  8,8,8,4,
  8,8,4,

  4,8,8,8,
  4,8,4,
  8,8,8,4,

  8,8,8,8,8,
  8,8,8,2
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int size = sizeof(melody) / sizeof(int);

  for (int i = 0; i < size; i++) {
    int duration = 1000 / durations[i];

    tone(buzzer, melody[i], duration);

    int pause = duration * 1.3;
    delay(pause);

    noTone(buzzer);
  }

  delay(5000); // pause before repeating
}