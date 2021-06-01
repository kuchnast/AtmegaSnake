#pragma once

#include "Config.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>

struct AppleNode : public XYNode
{
    void findRandom()
    {
        x = rand() % (MAX_X - 11) + 3;
        y = rand() % (MAX_Y - 11) + 3;
    }
};

class Apple
{
private:
    AppleNode apple_;

public:
    Apple() : apple_()
    {
        apple_.findRandom();
    }

    void draw(Display &display)
    {
        display.drawBox(apple_.x, apple_.y, 4, 4);
    }

    XYNode getNode() const
    {
        return apple_;
    }
};

