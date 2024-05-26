// ----------------------------------------------------------------------------
// motorLib.h
//  
// Description:
// Library used to control 2 pin stepper motors.
// It is supposed to be as simple as possible.
// The machine cycle consists of 4 states 
//
// Authors:
// Karangia23
// ----------------------------------------------------------------------------
#ifndef MOTORLIB_H
#define MOTORLIB_H

class motor
{
private:
    int stepPin;
    int dirPin;
    int speed;
    int time;
    int microStep;
    int distance = 0;
    enum direction {
        backward,
        forward
    };
    direction curDir = forward;
public:
    motor(int stepPin, int dirPin, int microStep = 1, int speed=500);
    ~motor();
    void runContinously();
    void changeDirection();
    void changeSpeed(int newSpeed);
};



#endif MOTORLIB_H