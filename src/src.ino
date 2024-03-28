#include "./headers/stateClass.h"

#define INFDISTANCE 20.0f
#define trigPin 4
#define echoPin 5

stateClass robot;

void setup() {
  Serial.begin (9600);
}

void loop() {
    robot.doCurrentState();
}