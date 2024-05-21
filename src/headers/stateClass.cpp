#include "stateClass.h"
#include "motorLib.h"

stateClass::stateClass(int rotorEnginePin, int rotorDirPin, int rotorMicroStep, int linearEnginePin, int linearDirPin, int linearMicroStep, int sensorEchoPin, int sensorTrigPin, int stepsForFullRotation=200, float maxDistance=20.0f)
{
    stateClass::LinMotor = motor(linearEnginePin, linearDirPin, linearMicroStep, 100);
    stateClass::RotMotor = motor(rotorEnginePin, rotorDirPin, rotorMicroStep, 50);

    stateClass::sensorEchoPin = sensorEchoPin;
    stateClass::sensorTrigPin = sensorTrigPin;
    
    stateClass::stepsForFullRotation = stepsForFullRotation;
    
    stateClass::maxDistance = maxDistance;
}

stateClass::~stateClass()
{
    //TODO deconstrcutor
}

void stateClass::doCurrentState()
{
    switch (currentState)
    {
        case IDLE:
        {
            break;
        }

        case RUN:
        {
            //constantly changing positions value
            break;
        }

        case LOOKFORGLASS:
        {
            break;
        }

        case POUR:
        {
            break;
        }
    }
}

void stateClass::transistionToRun()
{
    currentState = RUN;

    if(currentPosition != 0)
        resetPosition();
}

void stateClass::transistionToPour()
{
    currentState = POUR;
}

void stateClass::transistionToIdle()
{
    currentState = IDLE;
}

bool stateClass::checkForGlass()
{
    if(getDistance() < maxDistance)
    {
        transistionToPour();
    }
}

float stateClass::getDistance(){

  float distanceConstans = 0.017, duration_us;

  digitalWrite(sensorEchoPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrigPin, LOW);

  duration_us = pulseIn(sensorEchoPin, HIGH);
  
  return distanceConstans * duration_us;
}

int stateClass::convertDistanceToSteps(float distance)
{
    return (int)(distance / 0.1) * stepsFor1mili;
}



void stateClass::resetPosition()
{

}



