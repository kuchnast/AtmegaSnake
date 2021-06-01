#pragma once

#include <avr/io.h>
#include "Config.hpp"

class Frame
{
private:
    uint8_t r_;

public:
    Frame(uint8_t r) : r_(r) {}

    void draw(Display & D)
    {
        for (uint8_t i = 0; i < r_; ++i)
           D.drawFrame(i, i, MAX_X - 2 * (i + 1), MAX_Y - 2 * i);
    }

    uint8_t GetR() const
    {
        return r_;
    }
};