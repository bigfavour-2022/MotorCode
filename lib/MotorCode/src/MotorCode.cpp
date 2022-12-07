#include "MotorCode.h"
#include <Arduino.h>




MOTOR::MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin, const uint8_t &btn1, const uint8_t &btn2, const uint8_t &btn3) :_speedpin (speedpin), _directpin (directpin), _signalpin (signalpin), btn1pin (btn1), btn2pin (btn2), btn3pin(btn3)
{
  btn1Last = pulseIn(btn1pin, HIGH, 25000);
  delay(200);
  btn2Last = pulseIn(btn2pin, HIGH, 25000);
  delay(200);
  btn3Last = pulseIn(btn3pin, HIGH, 25000);
}

void MOTOR::init()
{
  pinMode(_directpin, OUTPUT);
  pinMode(_signalpin, OUTPUT);
  pinMode(_speedpin, OUTPUT);
  pinMode(btn1pin, INPUT);
  pinMode(btn2pin, INPUT);
  pinMode(btn3pin, INPUT);
}

bool MOTOR::btn1chk()
{
    return ((btn1Last != pulseIn(btn1pin, HIGH, 25000)) ? true : false);
}

bool MOTOR::btn2chk()
{
    return ((btn2Last != pulseIn(btn2pin, HIGH, 25000)) ? true : false);
}

bool MOTOR::btn3chk()
{
  return ((btn3Last != pulseIn(btn3pin, HIGH, 25000)) ? true : false);
}

bool MOTOR::moveForward()
{
  digitalWrite(_signalpin, HIGH);
  digitalWrite(_directpin, front);
  analogWrite(_speedpin, 160);
}


bool MOTOR::moveBackward()
{

  digitalWrite(_signalpin, HIGH);
  digitalWrite(_directpin, back);
  analogWrite(_speedpin, 160);
}

void MOTOR::stopMOTOR()
{
  digitalWrite(_signalpin, 0);
  digitalWrite(_directpin, 0);
  analogWrite(_speedpin, 0);
}


// const uint8_t& MOTOR::speedCal(int64_t& chData, const direction_t& dir)
// {
//   if(chData >= UP && chData > ch2Last)
//   {
//     digitalWrite(_signalpin, 1);
//     digitalWrite(_directpin, dir);
//     analogWrite(_speedpin, START);
//     lastSpeed = (uint8_t) map(chData, 1800, 1350, 0, 255);
//     lastSpeed = constrain(lastSpeed, START, 255);
//     delayMicroseconds(200);
//     for(; ch2Last <= chData; ch2Last += 10)
//     {
//       lastSpeed = (uint8_t) map(chData, 1800, 1350, lastSpeed, 254);
//       analogWrite(_speedpin, lastSpeed + START);
//       delayMicroseconds(200);
//     }

//     return ((uint8_t)map(ch2Last, 1800, 1350, START, 254));
//   }

//   else if(chData >= UP && chData < ch2Last)
//   {
//     digitalWrite(_signalpin, 1);
//     digitalWrite(_directpin, dir);
//     analogWrite(_speedpin, START);
//     lastSpeed = (int8_t) map(chData, 1350, 1800, START, 254);
//     delayMicroseconds(200);
//     for(; ch2Last >= chData; ch2Last -= 10)
//     {
//       lastSpeed = (int8_t) map(chData, 1350, 1800, lastSpeed, 254);
//       analogWrite(_speedpin, lastSpeed - START);
//       delayMicroseconds(200);
//     }

//     return ((uint8_t)map(ch2Last, 1350, 1800, START, 254));
//   }
//     else if(chData <= DOWN && chData < ch2Last)
//     {
//       digitalWrite(_signalpin, 1);
//       digitalWrite(_directpin, dir);
//       analogWrite(_speedpin, START);
//       lastSpeed = (int8_t) map(chData, 1300, 890, START, 254);
//       delayMicroseconds(200);
//       for(; ch2Last >= chData; ch2Last -= 10)
//       {
//         lastSpeed = (int8_t) map(chData, 1300, 890, lastSpeed, 254);
//         analogWrite(_speedpin, lastSpeed - START);
//         delayMicroseconds(200);
//       }

//       return ((uint8_t)map(ch2Last, 1300, 890, START, 254));
//     }

//     else if(chData <= DOWN && chData > ch2Last)
//     {
//       digitalWrite(_signalpin, 1);
//       digitalWrite(_directpin, dir);
//       analogWrite(_speedpin, START);
//       lastSpeed = (int8_t) map(chData, 1300, 890, START, 254);
//       delayMicroseconds(200);
//       for(; ch2Last <= chData; ch2Last += 10)
//       {
//         lastSpeed = (int8_t) map(chData, 1300, 890, lastSpeed, 254);
//         analogWrite(_speedpin, lastSpeed + START);
//         delayMicroseconds(200);
//       }

//       return ((uint8_t)map(ch2Last, 1300, 890, START, 254));
//     }

//     else
//     {
//       ch2Last = 0;
//       stopMOTOR();
//       delayMicroseconds(200);
//       return (0x00);
//     }
// }
