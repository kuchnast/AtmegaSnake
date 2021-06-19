#pragma once

#include "Config.hpp"
#include "DigitalPin.hpp"
#include <stdlib.h>

#define NUM 4

const char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

class Keyboard4x4
{
private:
    DigitalPin **rows_;
    DigitalPin **columns_;
    char prev_key_;
    const uint8_t counter_;

    char checkWhatPressed_()
    {
        for (uint8_t i = 0; i < NUM; ++i)
        {
            rows_[i]->write(true);
        }

        for (uint8_t i = 0; i < NUM; ++i)
        {
            rows_[i]->write(false);
            _delay_us(20);

            for (uint8_t j = 0; j < NUM; ++j)
            {
                if (columns_[j]->read() == false)
                {
                    return keys[i][j];
                }
            }

            rows_[i]->write(true);
        }

        return '\0';
    }

public:
    Keyboard4x4(const uint8_t *rows, const uint8_t *columns) : prev_key_('\0'), counter_(NUM_COUNTER)
    {
        rows_ = new DigitalPin *[4];
        columns_ = new DigitalPin *[4];

        for (uint8_t i = 0; i < NUM; ++i)
        {
            rows_[i] = new DigitalPin(rows[i], MODE::OUT);
            columns_[i] = new DigitalPin(columns[i], MODE::PULL_UP);
        }
    }

    ~Keyboard4x4()
    {
        for (uint8_t i = 0; i < NUM; ++i)
        {
            delete rows_[i];
            delete columns_[i];
        }

        delete[] rows_;
        delete[] columns_;
    }

    char read()
    {
        char temp = checkWhatPressed_();
        if(temp == prev_key_)
            return temp;
        else
        {
            for (uint8_t i = 0; i < counter_; ++i)
            {
                if (temp != checkWhatPressed_())
                    return prev_key_;
            }

            prev_key_ = temp;
            return prev_key_;
        }
    }

    void print()
    {
        for (uint8_t i = 0; i < NUM; ++i)
        {
            rows_[i]->print();
        }

        for (uint8_t i = 0; i < NUM; ++i)
        {
            columns_[i]->print();
        }
    }
};