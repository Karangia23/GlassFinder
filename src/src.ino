#include "./headers/stateClass.h"
#include "./headers/motorLib.h"

#define INFDISTANCE 20.0f
#define trigPin 4
#define echoPin 5
#define interruptPin 6

stateClass robot;

void setup() {
  Serial.begin (9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), changeStop, CHANGE);
}

void loop() {
    robot.startRunning();
}

void changeStop()
{
  robot.switchEmergencyStop();
}
