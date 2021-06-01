#pragma once

#include <avr/io.h>
#include <util/delay.h>

#include "AnalogInputPin.hpp"
#include "DigitalPin.hpp"

#ifdef DEBUG
#include <HardwareSerial.h>
#endif

enum class RUCH
{
    NONE = 0b00,
    UP = 0b1,
    DOWN = 0b10,
    LEFT = 0b100,
    RIGHT = 0b1000
};

bool czyRuch(const RUCH &r1, const RUCH &r2)
{
    //dla dwóch tych samych sygnałów - ruch
    if(r1 == r2)
        return true;

    //dla przeciwnych ruchów w pionie, brak ruchu
    if ((r1 == RUCH::UP || r1 == RUCH::DOWN) && (r2 == RUCH::UP || r2 == RUCH::DOWN))
        return false;

    //dla przeciwnych ruchów w poziomie, brak ruchu
    if ((r1 == RUCH::LEFT || r1 == RUCH::RIGHT) && (r2 == RUCH::LEFT || r2 == RUCH::RIGHT))
        return false;

    //dla dowolnych innych konfiguracji - ruch
    return true;
}

class Joystick
{
    private:
        AnalogInputPin x_axis_;
        AnalogInputPin y_axis_;
        DigitalPin button_;

    public:
        Joystick(uint8_t analog_pin_x, uint8_t analog_pin_y, uint8_t button_pin) : x_axis_(analog_pin_x), y_axis_(analog_pin_y), button_(button_pin, MODE::PULL_UP) {}

        RUCH sprawdzRuch()
        {
            uint16_t x = x_axis_.read();
            uint16_t y = y_axis_.read();

            //Serial.print("mx: ");
            //Serial.print(x);
            //Serial.print("my: ");
            //Serial.print(y);

            if (x > 800)
                return RUCH::UP;
            else if (x < 200 )
                return RUCH::DOWN;
            else if (y > 800)
                return RUCH::LEFT;
            else if (y < 200)
                return RUCH::RIGHT;
            else
                return RUCH::NONE;
        }

        bool sprawdzPrzycisk()
        {
            return button_.read();
        }
};