#pragma once

#include <SPI.h>
#include <U8g2lib.h>

#include "Config.hpp"

class SH1106
{
private:
    Display u8g2_;

public:
    SH1106() : u8g2_(U8G2_R0, U8X8_PIN_NONE) 
    {
        u8g2_.setBusClock(400000);
    }

    Display & getU8G2()
    {
        return u8g2_;
    }

    void init()
    {
        u8g2_.begin();
    }

};