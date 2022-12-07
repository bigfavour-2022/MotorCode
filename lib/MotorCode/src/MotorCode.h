#ifndef MOTORCODE
#define MOTORCODE

#include <stdint.h>
#include <Arduino.h>

enum direction_t { back = LOW, front = HIGH };

class MOTOR
{
    public:
    MOTOR() = default;
    MOTOR(const uint8_t &speedpin, const uint8_t &directpin, const uint8_t &signalpin, const uint8_t &btn1, const uint8_t &btn2, const uint8_t &btn3);

    void init();                //To initialise motor
    bool moveForward();         //Move motor forward
    bool moveBackward();        //Move motor backwards
    void stopMOTOR();           //Stop motor

    // Methods for the remote control
   bool btn1chk();
   bool btn2chk();
   bool btn3chk();

    private:
    const uint8_t& speedCal(int64_t& ch2data, const direction_t& dir);
    uint8_t  _speedpin, _directpin, _signalpin;
    uint8_t btn1pin, btn2pin, btn3pin;       //pin for buttons
    uint64_t btn1Last, btn2Last, btn3Last;
};


#endif
