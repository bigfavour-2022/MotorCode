#include "MotorCode.h"
#include <Arduino.h>




MOTOR::MOTOR(const int &speedpin, const int &directpin, const int &signalpin, const int &ch1pin, const int &ch2pin)
 :_speedpin {speedpin}, _directpin {directpin}, _signalpin {signalpin}, _ch1pin {ch1pin}, _ch2pin {ch2pin}
{
    
}

void MOTOR::init()
{
  pinMode(_directpin, OUTPUT);
  pinMode(_signalpin, OUTPUT);
  pinMode(_speedpin, OUTPUT);
}

int16_t MOTOR::ch1Data()

{
    _ch1Data= constrain(pulseIn(_ch1pin, HIGH, 25000),970,1870);
    return _ch1Data;
}

int16_t MOTOR::ch2Data()
{
    _ch2Data = constrain(pulseIn(_ch2pin, HIGH, 25000),890,1800);
    return _ch2Data;
}

bool MOTOR::moveForward()
{
  if (_ch2Data >= 1350)
  {
    ch2Data();
    digitalWrite(_signalpin, 1);
    digitalWrite(_directpin, 1);
    analogWrite(_speedpin, map(_ch2Data, 1350,1800,51,255));
    if(_ch2Data >= 1310 && _ch2Data <=1349)
    { 
      stopMOTOR();
    }
    return 1;
  }
  return 0;
}
bool MOTOR::moveBackward()
{
  
  if(_ch2Data <= 1309)
  {
  ch2Data();
  digitalWrite(_signalpin, 1);
  digitalWrite(_directpin, 0);
  analogWrite(_speedpin, map(_ch2Data, 1300,890,51,255));
   if(_ch2Data >= 1310 && _ch2Data <=1349 )
  {
    stopMOTOR();
  }
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



