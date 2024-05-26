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

//state machine methods

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
            if (stopRunning == false)
            {
                if(stateClass::checkForGlass())
                {
                    transistionToSearch();
                    break;
                }

                stateClass::LinMotor.runContinously();
            }
            break;
        }

        case LOOKFORGLASS:
        {
            if (stopRunning == false)
            {
                //check 3 last values of saved distance
                //if the latest vale is gettings bigger take middle value
            }
            

            break;
        }

        case POUR:
        {
            if (stopRunning == false)
            {
                //pour liquid and transistion to run 
            }
            break;
        }
    }
}

void stateClass::transistionToRun()
{
    currentState = RUN;

    if(currentPosition != 0)
        resetRotorPosition();
}

void stateClass::transistionToPour()
{
    currentState = POUR;
}

void stateClass::transistionToIdle()
{
    resetRotorPosition();
    currentState = IDLE;
}

void stateClass::transistionToSearch()
{
    currentState = LOOKFORGLASS;
}

bool stateClass::checkForGlass()
{
    if(getDistance() < maxDistance)
    {
        return true;
    }

    else
        return false;
}

// ultrasound sensor methods

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



void stateClass::resetRotorPosition()
{

}

void stateClass::switchEmergencyStop()
{
    stopRunning = !stopRunning;
}


