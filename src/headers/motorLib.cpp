#include "motorLib.h"

motor::motor(int stepPin, int dirPin, int microStep = 1, int speed=500)
{
    motor::stepPin = stepPin;
    motor::dirPin = dirPin;
    motor::microStep = microStep;
    motor::speed = map(speed*motor::microStep, 0, 1000, 1, 100);
    motor::time = 100 / motor::speed;
    digitalWrite(motor::dirPin, motor::curDir);
}   

motor::~motor()
{
}



void motor::runContinously(){
    digitalWrite(motor::stepPin,HIGH); 
    delayMicroseconds(motor::time);  
    digitalWrite(motor::stepPin, LOW); 
    delayMicroseconds(motor::time); 
}

void motor::changeDirection(){
    if(motor::curDir == forward)
        motor::curDir = backward;
    else
        motor::curDir = forward;

    digitalWrite(motor::dirPin, motor::curDir);
}

void motor::changeSpeed(int newSpeed){
    motor::speed = map(newSpeed*motor::microStep, 0, 1000, 1, 100);
}