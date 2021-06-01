#pragma once

#include <U8g2lib.h>

#define DEBUG

#define J1_X_AXIS_PIN 1
#define J1_Y_AXIS_PIN 2
#define J1_BUTTON_PIN 7

#define MAX_X 128
#define MAX_Y 64

typedef U8G2_SH1106_128X64_NONAME_F_HW_I2C Display;

/**
 * @brief Sprawdź czy bit rejestru jest ustawiony na 1
 * 
 */
#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))

/**
 * @brief Sprawdź czy bit rejestru jest ustawiony na 0
 * 
 */
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))

/**
 * @brief Przesunięcie bitowe 1 o x miejsc w lewo 
 * 
 */
#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

/**
 * @brief Ustawienie 1 na wybranym bicie rejestru
 * 
 */
#ifndef sbi
#define sbi(reg, bit) reg |= (_BV(bit))
#endif

/**
 * @brief Ustawienie 0 na wybranym bicie rejestru
 * 
 */
#ifndef cbi
#define cbi(reg, bit) reg &= ~(_BV(bit))
#endif

/**
 * @brief Negacja wybranego bitu rejestru
 * 
 */
#ifndef tbi
#define tbi(reg, bit) reg ^= (_BV(bit))
#endif

