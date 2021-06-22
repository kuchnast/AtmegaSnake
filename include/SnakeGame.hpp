#pragma once

#include "AnalogInputPin.hpp"
#include "SH1106.hpp"
#include "Snake.hpp"
#include "Frame.hpp"
#include "Apple.hpp"
#include "Points.hpp"
#include "SingleRecord.hpp"

class SnakeGame
{
private:
    Frame frame_;
    Snake snake_;
    Apple apple_;
    Points points_;

public:
    SnakeGame() : frame_(3), snake_(), apple_(), points_()
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
        points_.AddPoint();
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
        points_.Add(100);
        return true;
    }

    void gameOver(Display & display)
    {
        SingleRecord t(10);
        char *nick = new char[5];
        nick[0] = 'L';
        nick[1] = 'A';
        nick[2] = 'S';
        nick[3] = 'T';
        nick[4] = ' ';
        t.setRecord(nick, points_.GetScore());
        delete nick;

        display.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf);
        display.drawStr(6, 22, "GAME OVER");
        String s = "SCORE: " + String(points_.GetScore());
        char c[12];
        s.toCharArray(c, 12);
        display.drawStr(6, 42, c);
        display.nextPage();
        delay(2000);
    }

    void gamePause(Display &display)
    {
        display.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf);
        display.drawStr(10, 32, "PAUSE");
        display.nextPage();
    }

    void counter(Display &display)
    {
        display.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf);
        display.drawStr(30, 42, "3");
        display.nextPage();
        _delay_ms(1000);
        display.drawStr(30, 42, "2");
        display.nextPage();
        _delay_ms(1000);
        display.drawStr(30, 42, "1");
        display.nextPage();
        _delay_ms(1000);
        display.drawStr(30, 42, "GO!");
        display.nextPage();
        _delay_ms(1000);
    }

    uint8_t getSnakeSize() const
    {
        return snake_.getSize();
    }

    void gameSpeed(uint8_t max_size)
    {
        if (getSnakeSize() < max_size)
        {
            for (uint8_t i = 0; i < max_size - getSnakeSize(); ++i)
            {
                _delay_ms(20);
            }
        }
                
    }

};

