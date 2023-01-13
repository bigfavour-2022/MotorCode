////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Header file for RClib library.
//*FILE VERSION:    0.3.2 rev 2
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 8 December, 2022 16:11
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __RCLIB_H__
#define __RCLIB_H__

//X and Y values of joystick(s) on remote control, measured using pulseIn()
#define XMIN    952
#define XMAX    1863
#define YMIN    890
#define YMAX    1800


#include <Arduino.h>

using ulong = unsigned long;
namespace RClib
{
    template <typename T>
        const long &mapX(const long &num, const T *rem, const long &outMin, const long &outMax)
        {
            static long temp { };
            temp = (num - rem->xMin) * (outMax - outMin) / (rem->xMax - rem->xMin) + outMin;
            return (temp);
        }


    template <typename T>
        const long &mapY(const long &num, const T *rem, const long &outMin, const long &outMax)
        {
            static long temp { };
            temp = (num - rem->yMin) * (outMax - outMin) / (rem->yMax - rem->yMin) + outMin;
            return (temp);
        }
}


enum axis_t { X = 0, Y = 1 };

class RC
{
   public:
    //Constructors:
    RC() = default;

    explicit RC(const uint8_t &numChannels, const uint8_t *channelPins);        //To use default X and Y values

     //To define X and Y values


    ~RC();

    //Methods:
    long &readJoystick(const uint8_t &ch, const axis_t &axis);
    bool &readButton(const uint8_t &ch);

    template <typename T>
    friend const long& RClib::mapX(const uint8_t &num, T &rem, const long &outMin, const long &outMax);
    template <typename T>
    friend const long& RClib::mapY(const uint8_t &num, T &rem, const long &outMin, const long &outMax);

    long xMin, xMax, yMin, yMax;


    private:
    //Attributes:
    uint8_t *chPins;
    bool *btncurrent, *btnlast;

    //Methods:
    inline bool &btnMap(const long& val)
    {
        static bool temp;
        if (val > 1000)
            temp = true;
        else if (val < 1000)
            temp = false;
        return (temp);
    }

};
#endif
