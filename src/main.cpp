#include <Arduino.h>
#include "MotorCode.h"
#define button1 22
#define button2 23
#define button3 24

#define motor1Dir 8
#define motor1Sig 7
#define motor1Spd 11
#define motor2Dir 4
#define motor2Sig 2
#define motor2Spd 10

void setup();
void loop();

MOTOR Motor1(motor1Spd,motor1Dir, motor1Sig, button1, button2, button3);
MOTOR Motor2(motor2Spd, motor2Dir,motor2Sig, button1, button2, button3);

void setup()
{
    Motor1.init();
    Motor2.init();
    Motor1.stopMOTOR();
    Motor2.stopMOTOR();
}

void loop()
{
    if(Motor1.btn1chk())
    {
        Motor1.moveForward();
        Motor2.moveForward();
        delay(50);
    }

    else if(Motor1.btn2chk())
    {
        Motor1.moveForward();
        Motor2.moveBackward();
        delay(50);
    }

    else if(Motor2.btn3chk())
    {
        Motor1.stopMOTOR();
        Motor2.stopMOTOR();
        delay(200);
    }
    delayMicroseconds(200);
}
