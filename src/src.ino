#include "../lib/AccelStepper.h"
#include "../lib/MultiStepper.h"
#define INFDISTANCE 20.0f
#define trigPin 4
#define echoPin 5
#define stepsFor1mili 100

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // if(digitalRead())
  if(getDistance()<INFDISTANCE)
  {
    float distanceToCup = getDistance();
    findGlass();
    moveArms();
    pourLiqour();
  }
}

float getDistance(){
  float distanceConstans = 0.017, duration_us;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration_us = pulseIn(echoPin, HIGH);
  return distanceConstans * duration_us;
}

// int moveToTheMiddleOfCupAndGetNumberOfStepsFromEdge(float highestDistance)
// {
//   float prevVal = highestDistance;
//   int numberOfSteps = 1;
//   float newDistance = getDistance();

//   while(prevVal>newDistance)
//   {
//     prevVal = newDistance;
//     newDistance = getDistance();
//     numberOfSteps++;
//   }

//   return numberOfSteps;
// }

int convertDistanceToSteps(float distance)
{
  return (int)(distance / 0.1) * stepsFor1mili;
}

void pourLiqour()
{
  //todo
}

void findGlass()
{
  //todo
}

void moveArms()
{
  
}
