#ifndef MOTORCODE
#define MOTORCODE
#define SPEED 255

#include <stdint.h>
#include <Arduino.h>

enum direction_t { back = (uint8_t)0x0, front = (uint8_t)0x1 };

class MOTOR
{
    public:
    MOTOR() = default;
    MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin);

    void init();                //To initialise motor
    void moveForward();         //Move motor forward
    void moveBackward();        //Move motor backwards
    void stopMOTOR();           //Stop motor

    // Methods for the remote control

    private:
    const uint8_t& speedCal(int64_t& ch2data, const direction_t& dir);
    uint8_t  _speedpin, _directpin, _signalpin;
};


#endif
