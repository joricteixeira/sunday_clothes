#define PAUSE 0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define TEMPO 180

int buzzerPin = 13;

typedef struct {
    int note;
    int duration;
    bool tied;
} dataNode;

void playNote(dataNode x){
  Serial.print("PlayNote - Signed");
  Serial.print(x.duration);
  Serial.print(" - Actual:");
  //int actualDuration = 1000 /x.duration;

  //note duration
  double d = (60.0 * 1000.0 / (176.0 * 2)) * 4;
  int actualDuration = d / x.duration;

  Serial.println(actualDuration);
  int pauseBetweenNotes = actualDuration *1.3;
  tone(buzzerPin, x.note, actualDuration);
  delay(pauseBetweenNotes);
  //noTone(buzzerPin);
}

dataNode song2[] = {
  {NOTE_C4, 4},
  {NOTE_G3, 8},
  {NOTE_G3, 8},
  {NOTE_A3, 4},
  {NOTE_G3, 4},
  {PAUSE, 4},
  {NOTE_B3, 4}, 
  {NOTE_C4, 4}
};


// 60,000 ÷ 140 BPM = 428.57 ms per beat/quarter note.
//
//BPM   1/4   1/8   1/8T  1/16  1/32  1/64  1/128
//176   341ms 170ms 114ms 85ms  43ms  21ms  11ms
//
// 8T :: 12


dataNode song[] = {
  // Tempo: 176
  //21
  {PAUSE, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 4},
  {NOTE_D4, 4},

  //22
  {NOTE_D4, 4},
  {NOTE_E4, 4},
  {NOTE_E4, 4},
  {NOTE_G4, 4},

  //23
  {NOTE_G4, 2},
  {NOTE_FS4 , 4},
  {NOTE_A4, 4, true},

  //24
  {NOTE_A4, 1},

  //25
  {PAUSE, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 4},
  {NOTE_D4, 4},

  //26
  {NOTE_D4, 4},
  {NOTE_E4, 4},
  {NOTE_G4, 8, true},//dotted
  {NOTE_G4, 4}, //dotted
  {NOTE_FS4, 8},

  //27
  {NOTE_C4, 1, true},

  //28
  {NOTE_C4, 1} ,

  //29
  {PAUSE, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 8},
  {NOTE_D4, 4},
  {NOTE_D4, 4},

  //30
  {NOTE_D4, 4},
  {NOTE_E4, 4},
  {NOTE_E4, 4},
  {NOTE_G4, 4},

  //31
  {NOTE_G4, 2},
  {NOTE_FS4, 4},
  {NOTE_D5, 4, true},

  //32
  {NOTE_D5, 1},

  //33
  {NOTE_CS5, 4},
  {NOTE_A4, 8},
  //{NOTE_FS4, 8},
  //{NOTE_FS4, 8},
  {NOTE_FS4, 4},
  {NOTE_A4, 8},
  {NOTE_CS5, 4},

  //34
  {NOTE_B4, 4},
  {NOTE_G4, 8},
  //{NOTE_D4, 8},
  //{NOTE_D4, 8},
  {NOTE_D4, 4},
  {NOTE_G4, 8},
  {NOTE_B4, 4},

  //35
  {NOTE_CS5, 4},
  {NOTE_A4, 8},
  //{NOTE_FS4, 8},
  //{NOTE_FS4, 8},
  {NOTE_FS4, 4},
  {NOTE_A4, 8},
  {NOTE_CS5, 4},

  //36
  {NOTE_E5, 1}
};

int musicSize = (sizeof(song)/sizeof(int)/2);

int songTempo = TEMPO;
long currentNote = -1;
long lastTime = 0;
int lastNoteDuration = 0;

void play(){
  unsigned long currentTime = millis();

  Serial.print("Tied: ");
  Serial.print(song[currentNote].tied);


  if(currentTime > (lastTime + lastNoteDuration) && currentNote <= musicSize){
    Serial.print(" . . ");
    currentNote++;

    //note duration
    double d = (60.0 * 1000.0 / songTempo) * 4;
    int actualDuration = d / song[currentNote].duration;
    if(song[currentNote].tied && (song[currentNote].note == song[currentNote+1].note)){
      int nextNoteDuration = d / song[currentNote+1].duration;
      actualDuration =+ nextNoteDuration;
      currentNote++;
    }

    tone(buzzerPin, song[currentNote].note, actualDuration);
    //delay(actualDuration *1.3);
    //noTone(buzzerPin);
    lastNoteDuration = actualDuration;
    lastTime = currentTime;
  }

  if(currentNote >= musicSize)
  {
    noTone(buzzerPin);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
}

bool songFinished = false;

void loop_orig(){ 
  if(!songFinished){
    for (int i = 0; i < musicSize; i++) {
      playNote(song[i]);
    }
    songFinished = true;
  }
  delay(250);
 
}

void loop(){
  play();
}
