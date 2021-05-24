#pragma once

#include <avr/io.h>
#include <stdbool.h>
#include <stdlib.h>
#include <util/delay.h>

class Joystick
{
    private:
        int analog_pin_x_;
        int analog_pin_y_;
        int button_pin_;

        int x_axis_;
        int y_axis_;
        bool button_;

    public:

    Joystick(int analog_pin_x, int analog_pin_y, int button_pin) : analog_pin_x_(analog_pin_x), analog_pin_y_(analog_pin_y), button_pin_(button_pin) 
    {
        if(analog_pin_x_ >= 0 && analog_pin_x_ < 8)
            DDRF += (1 << analog_pin_x_);
        else if(analog_pin_x_ >= 8 && analog_pin_x_ < 16)
            DDRK += (1 << (analog_pin_x_ % 8));
        
    }

};