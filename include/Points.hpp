#pragma once

#include <avr/io.h>

class Points
{
private:
    uint16_t points_;

public:
    Points() : points_(0) {}

    void AddPoint()
    {
        ++points_;
    }

    void Add(uint16_t points)
    {
        points_ += points;
    }

    uint16_t GetScore() const
    {
        return points_;
    }
};