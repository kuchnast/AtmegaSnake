#pragma once

#include <avr/io.h>
#include "Config.hpp"

class AnalogInputPin
{
    private:
        uint8_t pin_;

    public:
    /**
     * @brief Construct a new Analog Input Pin object
     * 
     * @param analog_pin numer pinu (dostępne 0-15)
     */
        AnalogInputPin(uint8_t analog_pin): pin_(analog_pin % 16)
        {
            // aktywuj przetwornik analogowo-cyfrowy
            sbi(ADCSRA, ADEN);
        }

        uint16_t read()
        {
            uint8_t low, high;

            // ustaw bit na 0 odpowiedniego pinu ADC w rejestrze DIDR0 lub DIDR1, aby go załączyć
            if (pin_ < 8)
                cbi(DIDR0, pin_);
            else
                cbi(DIDR1, pin_);

            // ustaw bit MUX5 na 1 dla pinów 8-15, 0 dla pinów 0-7
            if (pin_ < 8) 
                cbi(ADCSRB, MUX5);
            else
                sbi(ADCSRB, MUX5);

            ADMUX = 0x40 | (pin_ & 0x07); // ustaw źródło referencyjne na VCC oraz wybierz pin do konwersji

            sbi(ADCSRA, ADSC); // rozpocznij konwersję

            while(bit_is_set(ADCSRA, ADSC)); // czekaj aż wartość zostanie odczytana i flaga będzie wyczyszczona

            low = ADCL; 
            high = ADCH;

            if (pin_ < 8)
                sbi(DIDR0, pin_);
            else
                sbi(DIDR1, pin_);

            return (high << 8) | low;
        }
};