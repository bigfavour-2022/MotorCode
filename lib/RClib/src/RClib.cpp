#include <Arduino.h>
#include "RClib.h"


RC::RC(const uint8_t &numChannels, const uint8_t *channelPins)
  :xMin {XMIN}, xMax {XMAX}, yMin {YMIN}, yMax {YMAX}, chPins { new uint8_t[numChannels]}, btncurrent { new bool[4]}, btnlast { new bool[4]}
{
  for(int i = 0; i < numChannels; ++i)
  {
    chPins[i] = channelPins [i];
    pinMode(chPins[i], INPUT);
    btncurrent[i] = false;
    btnlast[i] = false;
  }
}


RC::~RC()
{
  delete chPins;
  delete btncurrent;
  delete btnlast;

  chPins = nullptr;
  btncurrent = nullptr;
  btnlast = nullptr;
}

long RC::readJoystick(const uint8_t &ch, const axis_t &axis)
{
  using namespace RClib;
  static long temp;
  temp = pulseIn(chPins[ch-1], HIGH, 25000);
  delay(100);

  if(axis == X)
  {
    temp = (RClib::mapX<RC>(temp, this, -256, 255));

    return (temp);
  }
  else
  {
    temp = (RClib::mapY<RC>(temp, this, 255, -256));

    return (temp);
  }
}

bool RC::readButton(const uint8_t &ch)
{
  static bool temp;
  btncurrent[ch - 3] = btnMap(pulseIn(chPins[ch-1], HIGH, 25000));
  delay(100);

  if (btnlast[ch - 3] != (btncurrent[ch - 3]))
  {
    btnlast[ch - 3] = btncurrent[ch - 3];
    temp = true;
  }

  else
  {
    temp = false;
  }

  return (temp);
}
