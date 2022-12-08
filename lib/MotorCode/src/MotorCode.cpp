#include "MotorCode.h"
#include <Arduino.h>




MOTOR::MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin) :_speedpin (speedpin), _directpin (directpin), _signalpin (signalpin)
{

}

void MOTOR::init()
{
  pinMode(_directpin, OUTPUT);
  pinMode(_signalpin, OUTPUT);
  pinMode(_speedpin, OUTPUT);

  delay(1000);
  digitalWrite(_directpin, LOW);
  digitalWrite(_signalpin, LOW);
  analogWrite(_speedpin, LOW);
}


void MOTOR::moveForward()
{
  digitalWrite(_signalpin, HIGH);
  digitalWrite(_directpin, HIGH);
  analogWrite(_speedpin, SPEED);
}


void MOTOR::moveBackward()
{

  digitalWrite(_signalpin, HIGH);
  digitalWrite(_directpin, LOW);
  analogWrite(_speedpin, SPEED);
}

void MOTOR::stopMOTOR()
{
  digitalWrite(_signalpin, );
  digitalWrite(_directpin, 0);
  analogWrite(_speedpin, 0);
}
