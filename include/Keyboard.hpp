#pragma once

#include "Config.hpp"

enum class KEY
{
    ONE,
    TWO,
    THREE,
    A,
    FOUR,
    FIVE,
    SIX,
    B,
    SEVEN,
    EIGHT,
    NINE,
    C,
    STAR,
    NUL,
    HASH,
    D
};

const uint8_t keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const uint8_t rows[] = {31, 33, 35, 37};
const uint8_t columns[] = {23, 25, 27, 29};

class Keyboard
{
    private:
        
    public:
};