#pragma once

#include "Config.hpp"
#include "LinkedList.hpp"
#include "SH1106.hpp"
#include "Joystick.hpp"
#include "Frame.hpp"
#include "Apple.hpp"

#include <stdlib.h>

struct SnakeNode : public XYNode
{
    void findRandom()
    {
        srand(AnalogInputPin(1).read());
        x = (rand() % (MAX_X - 9)) + 5;
        y = (rand() % (MAX_Y - 5)) + 3;
    }
};

class Snake
{
private:
    LinkedList<SnakeNode> body_;
    uint8_t size_;
    RUCH curr_side_;


public:
    Snake()
    {
        SnakeNode temp;
        temp.findRandom();
        body_.addFront(temp);
        ++size_;

        curr_side_ = RUCH::RIGHT;
    }

    void draw(Display &display)
    {
        auto temp = body_.getHead();
        while (temp != nullptr)
        {
            display.drawBox(temp->getElement().x, temp->getElement().y, 4, 4);
            temp = temp->getNext();
        }
    }

    void expandTail()
    {
        SnakeNode temp = body_.getLast();

        switch (curr_side_)
        {
        case RUCH::DOWN:
            temp.y += 8;
            break;
        case RUCH::UP:
            temp.y -= 8;
            break;
        case RUCH::LEFT:
            temp.x += 8;
            break;
        case RUCH::RIGHT:
            temp.x -= 8;
            break;
        default:
            break;
        }

        body_.addLast(temp);
        ++size_;
    }

    void move(const RUCH &r)
    {
        //Serial.print("Before: ");
        //LinkedList<SnakeNode>::print(body_.getHead());
        //Serial.println();

        if (size_ == 1 || czyRuch(curr_side_, r))
        {
            if (r != RUCH::NONE && r != curr_side_)
                curr_side_ = r;
        }

            auto temp = body_.getFront();
            switch (curr_side_)
            {
            case RUCH::DOWN:

                temp.y -= 4;
                break;
            case RUCH::UP:
                temp.y += 4;
                break;
            case RUCH::LEFT:
                temp.x -= 4;
                break;
            case RUCH::RIGHT:
                temp.x += 4;
                break;
            default:
                break;
            }
            body_.addFront(temp);

            //Serial.print("AddFront: ");
            //LinkedList<SnakeNode>::print(body_.getHead());
            //Serial.println();

            body_.removeLast();

            //Serial.print("After: ");
            //LinkedList<SnakeNode>::print(body_.getHead());
            //Serial.println();
    }

    bool isCollisionTail()
    {
        if (size_ == 1)
            return false;

        if (body_.search(body_.getFront(), body_.getHead()->getNext()) == nullptr)
            return false;
        return true;
    }

    bool isCollisionFrame(const Frame &F)
    {
        auto head = body_.getFront();
        if (head.x > 118 || head.x < 3 || head.y > 57 || head.y < 3)
            return true;
        return false;
    }

    bool isCollisionApple(const Apple &A)
    {
        int delta_x = (A.getNode().x > body_.getFront().x ? A.getNode().x - body_.getFront().x : body_.getFront().x - A.getNode().x); //odleglosc x jablka od weza
        int delta_y = (A.getNode().y > body_.getFront().y ? A.getNode().y - body_.getFront().y : body_.getFront().y - A.getNode().y); //odleglosc y jablka od weza

        if (delta_y < 4 && delta_x < 4)
            return true;

        return false;
    }
};