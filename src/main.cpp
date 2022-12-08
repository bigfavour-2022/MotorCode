#include <Arduino.h>
#include "MotorCode.h"
#define button1 12
#define button2 13
#define button3 10


#define motor1Dir 9
#define motor1Sig 8
#define motor1Spd 11
#define motor2Dir 4
#define motor2Sig 2
#define motor2Spd 10


void setup();
void loop();

bool btn1chk();
bool btn2chk();
bool btn3chk();

MOTOR Motor1(motor1Spd,motor1Dir, motor1Sig);
MOTOR Motor2(motor2Spd, motor2Dir,motor2Sig);

void setup()
{
    Motor1.init();
    Motor2.init();

    Motor1.stopMOTOR();
    Motor2.stopMOTOR();

    pinMode(btn1pin, INPUT);
    pinMode(btn2pin, INPUT);
    pinMode(btn3pin, INPUT);


    btn1Last = btnMap(pulseIn(btn1pin, HIGH, 25000));
    delay(100);
    btn2Last = btnMap(pulseIn(btn2pin, HIGH, 25000));
    delay(100);
    btn3Last = btnMap(pulseIn(btn3pin, HIGH, 25000));
    delay(100);
}

void loop()
{
    if(btn1chk())
    {
        delay(200);
        Motor1.moveForward();
        delay(200);
        Motor2.moveForward();
    }

    else if(btn2chk())
    {
        delay(200);
        Motor1.moveForward();
        delay(200);
        Motor2.moveBackward();
    }

    else if(btn3chk())
    {
        delay(200);
        Motor1.stopMOTOR();
        delay(200);
        Motor2.stopMOTOR();
    }
    delay(200);
}



bool btn1chk()
{
    btn1current = btnMap(pulseIn(btn1pin, HIGH, 25000));
    delay(100);
    if(btn1Last != btn1current)
    {
      btn1Last = btn1current;
      return true;
    }
    else
      return false;
}

bool btn2chk()
{
    btn2current = btnMap(pulseIn(btn2pin, HIGH, 25000));
    delay(100);
    if(btn2Last != btn2current)
    {
      btn2Last = btn2current;
      return true;
    }
    else
      return false;
}

bool btn3chk()
{
  btn3current = btnMap(pulseIn(btn3pin, HIGH, 25000));
  delay(100);
  if(btn3Last != btn3current)
    {
      btn3Last = btn3current;
      return true;
    }
    else
      return false;
}
