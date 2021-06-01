#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "Joystick.hpp"
#include "Config.hpp"

#ifdef DEBUG
#include <HardwareSerial.h>
#endif

int main()
{
    Serial.begin(9600);

    Joystick j1(J1_X_AXIS_PIN, J1_Y_AXIS_PIN, J1_BUTTON_PIN);

    while (1)
    {
        RUCH RUCH_j1 = j1.sprawdzRuch();

        switch (RUCH_j1)
        {
        case RUCH::UP:
            Serial.println("J1 UP");
            Serial.flush();
            break;

        case RUCH::DOWN:
            Serial.println("J1 DOWN");
            Serial.flush();
            break;

        case RUCH::LEFT:
            Serial.println("J1 LEFT");
            Serial.flush();
            break;

        case RUCH::RIGHT:
            Serial.println("J1 RIGHT");
            Serial.flush();
            break;

        default:
            break;
        }

        _delay_ms(100);
    }

    return 0;
}