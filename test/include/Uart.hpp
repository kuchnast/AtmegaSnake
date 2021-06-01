#pragma once

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

void UART_init(unsigned int baud, bool RX, bool TX)
{
    // ustawienie prędkości
    unsigned int ubrr;
    ubrr = (((F_CPU / (baud * 16UL))) - 1);
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    // ustawienie bitów parzystości
    UCSR0C |= 1 << UPM01; // 1 bit parzystości
    // ustawienie ilości bitów danych
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
    // ustawienie bitów stopu
    // domyślnie jest 1

    if (RX)
    {
        UCSR0B |= 1 << RXEN0;
    }
    if (TX)
    {
        UCSR0B |= 1 << TXEN0;
    }
}

void UART_send(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}
