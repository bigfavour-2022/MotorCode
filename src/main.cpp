#include <Arduino.h>
#include "MotorCode.h"
#define ch1pin 13
#define ch2pin 12
#define motor1Dir 8
#define motor1Sig 7
#define motor1Spd 11
#define motor2Dir 4
#define motor2Sig 2
#define motor2Spd 10

void setup();
void loop();

MOTOR Motor1(motor1Spd,motor1Dir, motor1Sig, ch1pin, ch2pin);
MOTOR Motor2(motor2Spd, motor2Dir,motor2Sig, ch1pin, ch2pin);

void setup()
{
    Motor1.init();
    Motor2.init();
    Motor1.stopMOTOR();
    Motor2.stopMOTOR();
}

void loop()
{
    Motor1.ch2Data();
    Motor2.ch2Data();


    Motor1.moveForward();
    Motor2.moveBackward();
    delayMicroseconds(200);
}
