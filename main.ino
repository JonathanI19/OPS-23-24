// Songs taken from https://github.com/robsoncouto/arduino-songs

#include "pitches.h"

#define PotPin 14
#define LEDPin 7
#define SpeakerPin 4
#define NoteDuration 140

// Prototypes
void song1();
void song2();
void song3();
void i(int);

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(PotPin, INPUT);
  pinMode(SpeakerPin, OUTPUT);
  
}

void loop() {
  int v = analogRead(PotPin);
  if (v <= 10){
    indicator(1);
  }
  else if (v >= 1013) {
    indicator(3);
  }
  else {
    indicator(2);
  }

}

void indicator(int val) {
  for (int i = 0; i < val; i++) {
    digitalWrite(LEDPin, HIGH);
    delay(1500);
    digitalWrite(LEDPin, LOW);
    delay(500);
  }

  // Call relevant song after finished indicating song choice
  switch(val){
    case 1:
      song1();
      break;
    case 2:
      song2();
      break;
    case 3:
      song3();
      break;
  }
  
}

// Cantina Band
void song1(){
  int tempo = 140;
  int melody[] = {
  
  // Cantina BAnd - Star wars 
  // Score available at https://musescore.com/user/6795541/scores/1606876
  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8, 
  NOTE_B4,8,  NOTE_AS4,8, NOTE_B4,8, NOTE_A4,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_G4,8,
  NOTE_G4,4,  NOTE_E4,-2, 
  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,

  NOTE_A4,-4, NOTE_A4,-4, NOTE_GS4,8, NOTE_A4,-4,
  NOTE_D5,8,  NOTE_C5,-4, NOTE_B4,-4, NOTE_A4,-4,
  NOTE_B4,-4, NOTE_E5,-4, NOTE_B4,-4, NOTE_E5,-4, 
  NOTE_B4,8,  NOTE_E5,-4, NOTE_B4,8, REST,8,  NOTE_AS4,8, NOTE_B4,8,
  NOTE_D5,4, NOTE_D5,-4, NOTE_B4,8, NOTE_A4,-4,
  NOTE_G4,-4, NOTE_E4,-2,
  NOTE_E4, 2, NOTE_G4,2,
  NOTE_B4, 2, NOTE_D5,2,
  
  NOTE_F5, -4, NOTE_E5,-4, NOTE_AS4,8, NOTE_AS4,8, NOTE_B4,4, NOTE_G4,4, 
  };

  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  
  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 2) / tempo;
  
  int divider = 0, noteDuration = 0;
  // iterate over the notes of the melody. 
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } 
    else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(SpeakerPin, melody[thisNote], noteDuration*0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
  
    // stop the waveform generation before the next note.
    noTone(SpeakerPin);
  }
}

// Game of Thrones Theme
void song2(){
  // change this to make the song slower or faster
  int tempo = 85;
  
  // notes of the moledy followed by the duration.
  // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
  // !!negative numbers are used to represent dotted notes,
  // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
  int melody[] = {
  
    // Game of Thrones
    // Score available at https://musescore.com/user/8407786/scores/2156716
  
    NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
    NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
    NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
    NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
    NOTE_G4,-4, NOTE_C4,-4,//5
  
    NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
    NOTE_D4,-1, //7 and 8
    NOTE_F4,-4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
  
    //repeats from 5
    NOTE_G4,-4, NOTE_C4,-4,//5
  
    NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
    NOTE_D4,-1, //7 and 8
    NOTE_F4,-4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
    NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
    NOTE_G4,-4, NOTE_C4,-4,
    NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,
  
    NOTE_D4,-2,//15
    NOTE_F4,-4, NOTE_AS3,-4,
    NOTE_D4,-8, NOTE_DS4,-8, NOTE_D4,-8, NOTE_AS3,-8,
    NOTE_C4,-1,
    NOTE_C5,-2,
    NOTE_AS4,-2,
    NOTE_C4,-2,
    NOTE_G4,-2,
    NOTE_DS4,-2,
    NOTE_DS4,-4, NOTE_F4,-4, 
    NOTE_G4,-1,
    
    NOTE_C5,-2,//28
    NOTE_AS4,-2,
    NOTE_C4,-2,
    NOTE_G4,-2, 
    NOTE_DS4,-2,
    NOTE_DS4,-4, NOTE_D4,-4,
    NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
    NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
    
    REST,4, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,
    NOTE_C6,8, NOTE_G5,16, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,  
  };
  
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  
  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;
  
  int divider = 0, noteDuration = 0;
  
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
  
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(SpeakerPin, melody[thisNote], noteDuration * 0.9);
  
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
  
    // stop the waveform generation before the next note.
    noTone(SpeakerPin);
  }

}

void song3(){
  // change this to make the song slower or faster
  int tempo = 140;
  
  // notes of the moledy followed by the duration.
  // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
  // !!negative numbers are used to represent dotted notes,
  // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
  int melody[] = {
  
    // Take on me, by A-ha
    // Score available at https://musescore.com/user/27103612/scores/4834399
    // Arranged by Edward Truong
  
    NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
    REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
    NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
    REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
    NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
    
    REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
    NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
    REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
    NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
    REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
    
    NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
    REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
    
  };
  
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  
  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;
  
  int divider = 0, noteDuration = 0;
  
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(SpeakerPin, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(SpeakerPin);
  }
}
