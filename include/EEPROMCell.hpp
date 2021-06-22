#pragma once

#include "Config.hpp"

void write(uint16_t address, uint8_t data)
{
    while (bit_is_set(EECR, 1))
    {
    } //Czekaj aż zakończy się poprzedni zapis i bit EEWE zmieni stan na 0

    EEAR = address; //ustaw adres komórki pamięci
    EEDR = data;    //umieść dane w rejestrze

    sbi(EECR, 2); //Ustaw bit EEMWE na 1, aby aktywować operację zapisu
    sbi(EECR, 1); //Ustaw bit EEWE na 1, aby rozpocząć operację zapisu
}

uint8_t read(uint16_t address)
{
    while (bit_is_set(EECR, 1))
    {
    } //Czekaj aż zakończy się poprzedni zapis i bit EEWE zmieni stan na 0

    EEAR = address; //ustaw adres komórki pamięci
    sbi(EECR, 0);   //Ustaw bit EEMRE na 1, aby aktywować operację odczytu

    _delay_ms(1); //Zaczekaj na wynik opercji odczytu

    return EEDR; //Zwróć dane jako zawartość rejestru EEDR
}