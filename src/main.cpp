#include <Arduino.h>
#include <hoverboard.h>
#include <RClib.h>

#define motor1Dir 8
#define motor1Sig 9
#define motor1Spd 10
#define motor2Dir 12
#define motor2Sig 13
#define motor2Spd 11

#define SPEED 255

uint8_t chPins [] {2, 3, 4, 5, 6, 7}, start { };

void setup();
void loop();


RC remote (6, chPins);

HMotor motor1(motor1Sig, motor1Spd, motor1Dir);
HMotor motor2(motor2Sig, motor2Spd, motor2Dir);

void setup()
{
    motor1.stop();
    motor2.stop();
}

void loop()
{
    if(!start)
    {
      motor1.stop();
      motor2.stop();
      start++;
    }

    while(remote.readButton(3))
    {
        delay(200);
        motor1.move(forward, SPEED);
        delay(200);
        motor2.move(forward, SPEED);

        if(remote.readButton(5))
          break;
    }

    while(remote.readButton(4))
    {
        delay(200);
        motor1.move(backward, SPEED);
        delay(200);
        motor2.move(backward, SPEED);

        if(remote.readButton(5))
          break;
    }

    while(remote.readButton(5))
    {
        motor1.stop();
        delay(100);
        motor2.stop();
        delay(100);

        if(remote.readButton(3) || remote.readButton(4))
          break;
    }

    delay(200);
}
