#pragma once

#include "Config.hpp"
#include "EEPROMCell.hpp"

class SingleRecord
{
    private:
        uint16_t start_addr_;

    public:
        SingleRecord(uint16_t start_addr) : start_addr_(start_addr) {}

        void showRecord(Display &display, uint8_t x, uint8_t y)
        {
            char nick[5];
            char score_temp[2];
            uint16_t score;

            for (uint8_t i = 0; i < 5; ++i)
            {
                nick[i] = read(start_addr_ + i);
            }

            for (uint8_t i = 0; i < 2; ++i)
            {
                score_temp[i] = read(start_addr_ + 5 + i);
            }

            score = (score_temp[1] << 8) | score_temp[0];

            Serial.println(nick);
            Serial.println(uint8_t(score_temp[0]));
            Serial.println(uint8_t(score_temp[1]));
            Serial.println(score);

            if(score < 256)
            {
                String s = String(score);
                char c[3];
                s.toCharArray(c, 3);

                display.setFont(u8g2_font_6x12_me);
                display.firstPage();
                do
                {
                    display.drawStr(x, y, nick);
                    display.drawStr(x + 30, y, " ");
                    display.drawStr(x + 36, y, c);

                } while (display.nextPage());
            }
            else
            {
                String s = String(score);
                char c[5];
                s.toCharArray(c, 5);

                display.setFont(u8g2_font_6x12_me);
                display.firstPage();
                do
                {
                    display.drawStr(x, y, nick);
                    display.drawStr(x + 30, y, " ");
                    display.drawStr(x + 36, y, c);

                } while (display.nextPage());
            }

            
            
        }

        void setRecord(char * nick, uint16_t score)
        {
            for (uint8_t i = 0; i < 5; ++i)
            {
                write(start_addr_ + i, nick[i]);
            }

            write(start_addr_ + 5, (uint8_t(score & 0xff)));
            write(start_addr_ + 6, (uint8_t(score >> 8)));

            Serial.println((uint8_t(score & 0xff)));
            Serial.println((uint8_t(score >> 8)));
        }
};