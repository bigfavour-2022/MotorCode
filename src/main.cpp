////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Source file for MotorCode.
//*FILE VERSION:    0.1.3 rev 1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 8 December, 2022 16:11
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <hoverboard.h>
#include <RClib.h>

//Motor driver connections to Arduino:
#define motor1Dir 8   //White
#define motor1Sig 9   //Red
#define motor1Spd 10  //Yellow

#define motor2Dir 12
#define motor2Sig 13
#define motor2Spd 11

#define UP        3
#define DOWN      4
#define STOP      5


uint8_t *speed { new uint8_t (190) };    //Stores the current value of the motor (*speed)

uint8_t chPins [] {2, A0, 4, 5, 6, 7} /* Stores the connectors for the receiver */, start { };

RC remote (6, chPins);

HMotor motor1(motor1Sig, motor1Spd, motor1Dir);
HMotor motor2(motor2Sig, motor2Spd, motor2Dir);

void setup();
void loop();


void setup()
{
    motor1.stop();
    motor2.stop();
}

void loop()
{
    if(!start)        //Ensures that the motor starts stopped
    {
      motor1.stop();
      motor2.stop();
      start++;
    }


    while(remote.readButton(UP))
    {
        delay(200);
        motor1.move(forward, (*speed));
        delay(200);
        motor2.move(backward, (*speed));


        if(remote.readButton(STOP) || remote.readButton(DOWN))
          break;
    }

    while(remote.readButton(DOWN))
    {
        delay(200);
        motor1.move(backward, (*speed));
        delay(200);
        motor2.move(forward, (*speed));

        if(remote.readButton(STOP) || remote.readButton(UP))
          break;
    }

    while(remote.readButton(STOP))
    {
        motor1.stop();
        delay(100);
        motor2.stop();
        delay(100);
        (*speed) = 145;

        if(remote.readButton(UP) || remote.readButton(DOWN))
          break;
    }

    delay(200);
}
