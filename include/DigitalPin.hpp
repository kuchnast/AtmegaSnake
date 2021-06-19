#pragma once

#include <avr/io.h>
#include "Config.hpp"

enum class REGISTER
{
    PA,
    PB,
    PC,
    PD,
    PE,
    PF,
    PG,
    PH,
    PJ,
    PK,
    PL
};

const REGISTER digital_reg[] = {
    REGISTER::PE,
    REGISTER::PE,
    REGISTER::PE,
    REGISTER::PE,
    REGISTER::PG,
    REGISTER::PE,
    REGISTER::PH,
    REGISTER::PH,
    REGISTER::PH,
    REGISTER::PH,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PJ,
    REGISTER::PJ,
    REGISTER::PH,
    REGISTER::PH,
    REGISTER::PD,
    REGISTER::PD,
    REGISTER::PD,
    REGISTER::PD,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PA,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PC,
    REGISTER::PD,
    REGISTER::PG,
    REGISTER::PG,
    REGISTER::PG,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PL,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PB,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PF,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
    REGISTER::PK,
};

const uint8_t digital_pin[] = {
    0,
    1,
    4,
    5,
    5,
    3,
    3,
    4,
    5,
    6,
    4,
    5,
    6,
    7,
    1,
    0,
    1,
    0,
    3,
    2,
    1,
    0,
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    7,
    6,
    5,
    4,
    3,
    2,
    1,
    0,
    7,
    2,
    1,
    0,
    7,
    6,
    5,
    4,
    3,
    2,
    1,
    0,
    3,
    2,
    1,
    0,
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,

};

enum class MODE
{
    IN,
    OUT,
    PULL_UP
};

class DigitalPin
{
private:
    uint8_t pin_;
    MODE curr_mode_;

    void setDDR_(bool bit)
    {
        switch (digital_reg[pin_])
        {
        case REGISTER::PA:
            if (bit)
                sbi(DDRA, digital_pin[pin_]);
            else
                cbi(DDRA, digital_pin[pin_]);
            break;
        case REGISTER::PB:
            if (bit)
                sbi(DDRB, digital_pin[pin_]);
            else
                cbi(DDRB, digital_pin[pin_]);
            break;
        case REGISTER::PC:
            if (bit)
                sbi(DDRC, digital_pin[pin_]);
            else
                cbi(DDRC, digital_pin[pin_]);
            break;
        case REGISTER::PD:
            if (bit)
                sbi(DDRD, digital_pin[pin_]);
            else
                cbi(DDRD, digital_pin[pin_]);
            break;
        case REGISTER::PE:
            if (bit)
                sbi(DDRE, digital_pin[pin_]);
            else
                cbi(DDRE, digital_pin[pin_]);
            break;
        case REGISTER::PF:
            if (bit)
                sbi(DDRF, digital_pin[pin_]);
            else
                cbi(DDRF, digital_pin[pin_]);
            break;
        case REGISTER::PG:
            if (bit)
                sbi(DDRG, digital_pin[pin_]);
            else
                cbi(DDRG, digital_pin[pin_]);
            break;
        case REGISTER::PH:
            if (bit)
                sbi(DDRH, digital_pin[pin_]);
            else
                cbi(DDRH, digital_pin[pin_]);
            break;
        case REGISTER::PJ:
            if (bit)
                sbi(DDRJ, digital_pin[pin_]);
            else
                cbi(DDRJ, digital_pin[pin_]);
            break;
        case REGISTER::PK:
            if (bit)
                sbi(DDRK, digital_pin[pin_]);
            else
                cbi(DDRK, digital_pin[pin_]);
            break;
        case REGISTER::PL:
            if (bit)
                sbi(DDRL, digital_pin[pin_]);
            else
                cbi(DDRL, digital_pin[pin_]);
            break;
        default:
            break;
        }
    }

    void setPORTR_(bool bit)
    {
        switch (digital_reg[pin_])
        {
        case REGISTER::PA:
            if (bit)
                sbi(PORTA, digital_pin[pin_]);
            else
                cbi(PORTA, digital_pin[pin_]);
            break;
        case REGISTER::PB:
            if (bit)
                sbi(PORTB, digital_pin[pin_]);
            else
                cbi(PORTB, digital_pin[pin_]);
            break;
        case REGISTER::PC:
            if (bit)
                sbi(PORTC, digital_pin[pin_]);
            else
                cbi(PORTC, digital_pin[pin_]);
            break;
        case REGISTER::PD:
            if (bit)
                sbi(PORTD, digital_pin[pin_]);
            else
                cbi(PORTD, digital_pin[pin_]);
            break;
        case REGISTER::PE:
            if (bit)
                sbi(PORTE, digital_pin[pin_]);
            else
                cbi(PORTE, digital_pin[pin_]);
            break;
        case REGISTER::PF:
            if (bit)
                sbi(PORTF, digital_pin[pin_]);
            else
                cbi(PORTF, digital_pin[pin_]);
            break;
        case REGISTER::PG:
            if (bit)
                sbi(PORTG, digital_pin[pin_]);
            else
                cbi(PORTG, digital_pin[pin_]);
            break;
        case REGISTER::PH:
            if (bit)
                sbi(PORTH, digital_pin[pin_]);
            else
                cbi(PORTH, digital_pin[pin_]);
            break;
        case REGISTER::PJ:
            if (bit)
                sbi(PORTJ, digital_pin[pin_]);
            else
                cbi(PORTJ, digital_pin[pin_]);
            break;
        case REGISTER::PK:
            if (bit)
                sbi(PORTK, digital_pin[pin_]);
            else
                cbi(PORTK, digital_pin[pin_]);
            break;
        case REGISTER::PL:
            if (bit)
                sbi(PORTL, digital_pin[pin_]);
            else
                cbi(PORTL, digital_pin[pin_]);
            break;
        default:
            break;
        }
    }

    bool getPIN_()
    {
        switch (digital_reg[pin_])
        {
        case REGISTER::PA:
            return PINA & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PB:
            return PINB & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PC:
            return PINC & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PD:
            return PIND & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PE:
            return PINE & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PF:
            return PINF & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PG:
            return PING & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PH:
            return PINH & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PJ:
            return PINJ & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PK:
            return PINK & _BV(digital_pin[pin_]);
            break;
        case REGISTER::PL:
            return PINL & _BV(digital_pin[pin_]);
            break;
        default:
            break;
        }

        return false;
    }

public:
    DigitalPin(uint8_t pin, MODE mode) : pin_(pin % 70), curr_mode_(mode)
    {
        switch (curr_mode_)
        {
        case MODE::IN:
            setDDR_(0);
            break;
        case MODE::OUT:
            setDDR_(1);
            break;
        case MODE::PULL_UP:
            setDDR_(0);
            setPORTR_(1);
            break;

        default:
            break;
        }
    }

    bool read()
    {
        /**
        bool temp = getPIN_();
        Serial.print("READ: ");
        if (temp)
        {
            Serial.println("ON");
        }
        else
        {
            Serial.println("OFF");
        }

        return temp;
        **/
        return getPIN_();
    }

    void write(bool bit)
    {
        setPORTR_(bit);
    }

    void print()
    {
        Serial.print("Pin ");
        Serial.print(pin_);
        Serial.print(" mode ");
        if(curr_mode_ == MODE::IN)
            Serial.print("IN\n");
        if (curr_mode_ == MODE::OUT)
            Serial.print("OUT\n");
        if (curr_mode_ == MODE::PULL_UP)
            Serial.print("PULL_UP\n");
    }
};