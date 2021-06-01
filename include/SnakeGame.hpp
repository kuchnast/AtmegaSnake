#pragma once

#include "AnalogInputPin.hpp"
#include "SH1106.hpp"
#include "Snake.hpp"
#include "Frame.hpp"
#include "Apple.hpp"

class SnakeGame
{
private:
    Frame frame_;
    Snake snake_;
    Apple apple_;

public:
    SnakeGame() : frame_(3), snake_(), apple_() 
    {
    }

    void draw(Display &display)
    {
        display.firstPage();
        do
        {
            frame_.draw(display);
            apple_.draw(display);
            snake_.draw(display);
        } while (display.nextPage());
    }

    void makeMove(const RUCH & r)
    {
        snake_.move(r);
    }

    bool checkCollisions()
    {
        if(snake_.isCollisionFrame(frame_) || snake_.isCollisionTail())
            return true;

        return false;
    }

    bool eatApple()
    {
        if (!snake_.isCollisionApple(apple_))
            return false;

        snake_.expandTail();
        apple_ = Apple();
        return true;
    }

    void gameOver(Display & display)
    {
        display.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf);
        display.drawStr(10, 22, "GAME OVER");
        String s = "SCORE: " + String(0);
        char c[11];
        s.toCharArray(c, 11);
        display.drawStr(22, 42, c);
        display.nextPage();
        delay(2000);
    }

    void gamePause(Display &display)
    {
        display.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf);
        display.drawStr(10, 22, "PAUSE");
        display.nextPage();
    }
};

