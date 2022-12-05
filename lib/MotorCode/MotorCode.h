#ifndef MOTORCODE
#define MOTORCODE
#define UP 1350
#define DOWN 1309
#include <stdint.h>
#include <Arduino.h>

class MOTOR
{
    public:
    MOTOR() = default;
    MOTOR(const int &speedpin, const int &directpin, const int &signalpin, const int &ch1pin, const int &ch2pin);

    // Methods for the motor
    void init();
    bool moveForward();
    bool moveBackward();
    // bool moveLeft();
    // bool moveRight();
    void stopMOTOR();

    // Methods for the remote control
   int16_t ch1Data();
   int16_t ch2Data();
   int16_t _ch2Data, _ch1Data;

    private:
    int  _speedpin, _directpin, _signalpin;
    int _ch1pin, _ch2pin;
 
    

};

enum direction_t {forward = (int) 0xFF, backward = (int) 0x00 };

#endif