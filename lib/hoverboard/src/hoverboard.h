////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       main.cpp
//*FILE DESC:       Header file for hoverboard library.
//*FILE VERSION:    0.1.1
//*FILE AUTHOR:     Chimaroke Okwara
//*LAST MODIFIED:   Thursday, 8 December, 2022 16:11
//*LICENSE:         Academic Free License
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __HOVERBOARD_H__
#define __HOVERBOARD_H__


enum direction_t { forward = (uint8_t) true, backward = (uint8_t) false };

class HMotor
{
    public:
    //Constructors:
    HMotor() = default;
    explicit HMotor(const uint8_t &signalPin, const uint8_t &speedPin, const uint8_t &directionPin);

    //Destructors:
    ~HMotor();

    //Methods:
    bool move(const direction_t &direction, const uint8_t &speed);
    bool move(const bool &direction, const uint8_t &speed) { return (this->move((direction_t) direction, speed)) ? 1 : 0; }
    void stop(void);

    private:
    //Attributes:
    uint8_t _speed, _signal, _direction;
};


#endif
