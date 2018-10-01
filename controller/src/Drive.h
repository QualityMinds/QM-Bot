#ifndef Drive_H
#define Drive_H

#include <Arduino.h>
#include "driver/ledc.h"

class Drive {
    public:
        Drive(int _in1, int _in2, int _in3, int _in4, int _motorPin1, int _motorPin2);
        void setSpeed(int xAxis, int yAxis);
    private:
        int in1;
        int in2;
        int in3;
        int in4;
        int motorPin1;
        int motorPin2;
        int motorSpeedA;
        int motorSpeedB;
};

#endif
