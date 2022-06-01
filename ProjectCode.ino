
#include"pitches.h"

const int trigPin = 5;
const int echoPin = 9;

float duration, distance;
int speed=90;  //higher value, slower notes

int octave[] = {NOTE_C2, NOTE_G2, NOTE_C3, NOTE_G3, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G5, NOTE_C6, NOTE_G6, NOTE_C7, NOTE_G7};
int noteDurations[] = {4,4,4,4,4,4,4,4,4,4,4,4};

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 5000;  //the value is a number of milliseconds

void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  startMillis = millis();  //initial start time


//testing notes, this plays the unlock sound from legend of zelda
  int noteDuration = speed*2.5;
  tone(3, NOTE_G5,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_FS5,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_DS5,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_A4,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_GS4,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_E5,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_GS5,noteDuration);
  delay(noteDuration);
  tone(3, NOTE_C6,noteDuration);
  delay(noteDuration);
  
}

void loop() {

  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;

//while (currentMillis - startMillis >= period)  //test whether the period has elapsed
// {
  
  Serial.print("Distance: ");
  Serial.print(distance);


int noteDuration = speed;
  if (distance < 5) {
   tone(3, octave[1],noteDuration);
} else if (distance >= 5 && distance < 7) {
   tone(3, octave[2],noteDuration);
}
else if (distance >= 7 && distance < 9) {
   tone(3, octave[3],noteDuration);
}
else if (distance >= 9 && distance < 11) {
   tone(3, octave[4],noteDuration);
}
else if (distance >= 11 && distance < 13) {
   tone(3, octave[5],noteDuration);
}
else if (distance >= 13 && distance < 15) {
   tone(3, octave[6],noteDuration);
}
else if (distance >= 15 && distance < 17) {
   tone(3, octave[7],noteDuration);
}
else if (distance >= 17 && distance < 19) {
   tone(3, octave[8],noteDuration);
}
else if (distance >= 19 && distance < 21) {
   tone(3, octave[9],noteDuration);
}
else if (distance >= 21 && distance < 23) {
   tone(3, octave[10],noteDuration);
}
else if (distance >= 23 && distance < 25) {
   tone(3, octave[11],noteDuration);
}
else if (distance >= 25 && distance < 27) {
   tone(3, octave[12],noteDuration);
}
else{
  //no tone
}
//}
}
