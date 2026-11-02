// week09_3_arduino_2048_three_PCM_sound

#include "PCM.h"
#include "sounddata.h" 

#define QUEUE_SIZE 15
char soundQueue[QUEUE_SIZE];
int qHead = 0;
int qTail = 0;

bool playing = false;
unsigned long soundEnd = 0;

void enqueue(char ch) {
  int nextTail = (qTail + 1) % QUEUE_SIZE;
  if (nextTail != qHead) {
    soundQueue[qTail] = ch;
    qTail = nextTail;
  }
}

char dequeue() {
  if (qHead == qTail) return '\0'; 
  char ch = soundQueue[qHead];
  qHead = (qHead + 1) % QUEUE_SIZE;
  return ch;
}

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  Serial.begin(115200);

  startPlayback(move_data, move_length);
  delay((unsigned long)move_length / 8 + 25);
  
  startPlayback(merge_data, merge_length);
  delay((unsigned long)merge_length / 8 + 25);
  
  startPlayback(spawn_data, spawn_length);
  delay((unsigned long)spawn_length / 8 + 25);
}

void loop() {
  while (Serial.available() > 0) {
    char ch = (char)Serial.read();
    if (ch == 'M' || ch == 'C' || ch == 'N') {
      enqueue(ch);
    }
  }

  if (playing && (long)(millis() - soundEnd) > 0) {
      playing = false;
      stopPlayback();
  }

  if (!playing && qHead != qTail) {
    char nextSound = dequeue();
    
    if (nextSound == 'M') {
      startPlayback(move_data, move_length);
      soundEnd = millis() + ((unsigned long)move_length / 8 + 25);
    } 
    else if (nextSound == 'C') {
      startPlayback(merge_data, merge_length);
      soundEnd = millis() + ((unsigned long)merge_length / 8 + 25);
    } 
    else if (nextSound == 'N') {
      startPlayback(spawn_data, spawn_length);
      soundEnd = millis() + ((unsigned long)spawn_length / 8 + 25);
    }
    
    playing = true;
  }
}
