#include "MotorCode.h"
#include <Arduino.h>




MOTOR::MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin, const uint8_t &ch1pin, const uint8_t &ch2pin) :_speedpin (speedpin), _directpin (directpin), _signalpin (signalpin), _ch1pin (ch1pin), _ch2pin (ch2pin)
{

}

void MOTOR::init()
{
  pinMode(_directpin, OUTPUT);
  pinMode(_signalpin, OUTPUT);
  pinMode(_speedpin, OUTPUT);
}

int64_t MOTOR::ch1Data()

{
    _ch1Data =  constrain(pulseIn(_ch1pin, HIGH, 25000),970,1870);
    return _ch1Data;
}

int64_t MOTOR::ch2Data()
{
    ch2Last = _ch2Data;
    _ch2Data = constrain(pulseIn(_ch2pin, HIGH, 25000),890,1800);
    return _ch2Data;
}

bool MOTOR::moveForward()
{
  if (_ch2Data >= 1350)
  {
    speedCal(_ch2Data, front);
    return 1;
  }
  return 0;
}


bool MOTOR::moveBackward()
{

  if(_ch2Data <= 1309)
  {
  speedCal(_ch2Data, back);
  return 1;
  }
  return 0;
}

void MOTOR::stopMOTOR()
{
  digitalWrite(_signalpin, 0);
  digitalWrite(_directpin, 0);
  analogWrite(_speedpin, 0);
}


const uint8_t& MOTOR::speedCal(int64_t& chData, const direction_t& dir)
{
  if(chData >= UP && chData > ch2Last)
  {
    digitalWrite(_signalpin, 1);
    digitalWrite(_directpin, dir);
    analogWrite(_speedpin, 155);
    delayMicroseconds(200);
    for(; ch2Last <= chData; ch2Last += 10)
    {
      analogWrite(_speedpin, map(ch2Last, 1800, 1350, 155, 254));
      delayMicroseconds(200);
    }

    return ((uint8_t)map(ch2Last, 1350, 1800, 155, 254));
  }

  else if(chData >= UP && chData < ch2Last)
  {
    digitalWrite(_signalpin, 1);
    digitalWrite(_directpin, dir);
    analogWrite(_speedpin, 155);
    delayMicroseconds(200);
    for(; ch2Last <= chData; ch2Last -= 10)
    {
      analogWrite(_speedpin, map(ch2Last, 1800, 1350, 155, 254));
      delayMicroseconds(200);
    }

    return ((uint8_t)map(ch2Last, 1350, 1800, 155, 254));
  }
    else if(chData <= DOWN && chData < ch2Last)
    {
      digitalWrite(_signalpin, 1);
      digitalWrite(_directpin, dir);
      analogWrite(_speedpin, 155);
      delayMicroseconds(200);
      for(; ch2Last >= chData; ch2Last -= 10)
      {
        analogWrite(_speedpin, map(ch2Last, 1300, 890, 155, 254));
        delayMicroseconds(200);
      }

      return ((uint8_t)map(ch2Last, 1300, 890, 155, 254));
    }

    else if(chData <= DOWN && chData > ch2Last)
    {
      digitalWrite(_signalpin, 1);
      digitalWrite(_directpin, dir);
      analogWrite(_speedpin, 155);
      delayMicroseconds(200);
      for(; ch2Last >= chData; ch2Last += 10)
      {
        analogWrite(_speedpin, map(ch2Last, 1300, 890, 155, 254));
        delayMicroseconds(200);
      }

      return ((uint8_t)map(ch2Last, 1300, 890, 155, 254));
    }

    else
    {
      stopMOTOR();
      delayMicroseconds(200);
      return (0x00);
    }
}
