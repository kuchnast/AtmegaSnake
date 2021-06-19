#include "SnakeGame.hpp"
#include "DigitalPin.hpp"
#include "Keyboard.hpp"
#include "Menu.hpp"

SH1106 display;
SnakeGame s_game;
Joystick j(J1_X_AXIS_PIN, J1_Y_AXIS_PIN, J1_BUTTON_PIN);
Keyboard4x4 keyboard(pin_rows, pin_columns);
Menu menu(display.getU8G2());

void setup(void)
{
  Serial.begin(9600);
  display.init();
  s_game.draw(display.getU8G2());

  menu.showWelcomeScrean(1);
  _delay_ms(2000);
  menu.showWelcomeScrean(0);
  _delay_ms(2000);

  uint8_t highlight = 0;
  do
  {
    if (j.sprawdzRuch() == RUCH::DOWN || keyboard.read() == '8')
    {
      while (j.sprawdzRuch() == RUCH::DOWN || keyboard.read() == '8') {}
      if(highlight == 3)
        highlight = 0;
      else
        ++highlight;
    }

    if (j.sprawdzRuch() == RUCH::UP || keyboard.read() == '2')
    {
      while (j.sprawdzRuch() == RUCH::UP || keyboard.read() == '2'){}
      if (highlight)
        --highlight;
      else
        highlight = 3;
    }

    menu.ShowMainMenu(highlight);
  }
  while (j.sprawdzPrzycisk() && keyboard.read() != '5');

  if(highlight == 0)
  {
    menu.showSnakeScrean();
    while (j.sprawdzPrzycisk() && !keyboard.read() && j.sprawdzRuch() == RUCH::NONE){}
  }
}

void loop(void)
{

  if (j.sprawdzPrzycisk() == false)
  {
    s_game.gamePause(display.getU8G2());
    _delay_ms(1000);
    while (j.sprawdzPrzycisk() == true)
    {
      _delay_ms(50);
    }
    _delay_ms(1000);
  }

  s_game.makeMove(j.sprawdzRuch());
  s_game.draw(display.getU8G2());
  if(s_game.checkCollisions())
    s_game.gameOver(display.getU8G2());

  s_game.eatApple();

  //char temp = keyboard.read();
}