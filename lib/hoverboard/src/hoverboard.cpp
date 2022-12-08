////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Source file for hoverboard library.
//*FILE VERSION:    0.1.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 8 December, 2022 16:11
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "hoverboard.h"

HMotor::HMotor(const uint8_t &signalPin, const uint8_t &speedPin, const uint8_t &directionPin)
        :  _speed{speedPin}, _signal{signalPin}, _direction{directionPin}
{
    pinMode(_signal, 1);
    pinMode(_direction, 1);
    pinMode(_speed, 1);
}

bool HMotor::move(const direction_t &Direction, const uint8_t &speed)
{
    if(speed < 0 || speed > 256)
        return 0;

    digitalWrite(_signal, 1);
    digitalWrite(_direction, (Direction == true ? HIGH : LOW ));
    analogWrite(_speed, speed);
    delayMicroseconds(10);

    return 1;
}


HMotor::~HMotor()
{

}


void HMotor::stop()
{
    digitalWrite(_signal, 0);
    digitalWrite(_speed, 0);
    digitalWrite(_direction, 0);
}
