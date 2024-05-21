#ifndef STATECLASS_H
#define STATECLASS_H

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "motorLib.h"
#include <stdlib.h>

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif

#define stepsFor1mili 100;

class stateClass
{
private:
    // Enums for class, one for current state, another for direction in which machine is supposed to be spinning
    enum state{
        IDLE = 0,
        RUN = 1,
        LOOKFORGLASS = 2,
        POUR = 3
    };

    enum directionOfSpinning{
        CLOCKWISE = 1,
        COUNTER_CLOCKWISE = 0
    };

    // Declaration of these enums
    state currentState = IDLE;
    directionOfSpinning rotDirection = CLOCKWISE;

    //Helper members
    int currentPosition = 0;
    int stepsForFullRotation;
    float maxDistance;

    /*Accelstepper objects for the rotational movment of robot and
    linear movment of its arm
    */
    motor LinMotor;
    motor RotMotor;

    int sensorEchoPin;
    int sensorTrigPin;

    void transistionToRun();
    void transistionToIdle();
    void transistionToPour();

    int convertDistanceToSteps(float distance);
    float getDistance();
    bool checkForGlass();
public:
    stateClass::stateClass(int rotorEnginePin, int rotorDirPin, int rotorMicroStep, int linearEnginePin, int linearDirPin, int linearMicroStep, int sensorEchoPin, int sensorTrigPin, int stepsForFullRotation=200, float maxDistance=20.0f);
    ~stateClass();

    void startRunning();
    void stopRunning();
    void doCurrentState();
    void resetPosition();
};

#endif STATECLASS_H