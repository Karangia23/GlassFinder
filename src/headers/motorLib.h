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