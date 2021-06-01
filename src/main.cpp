#include "SnakeGame.hpp"
#include "DigitalPin.hpp"

SH1106 display;
SnakeGame s_game;
Joystick j(J1_X_AXIS_PIN, J1_Y_AXIS_PIN, J1_BUTTON_PIN);

void setup(void)
{
  Serial.begin(9600);
  display.init();
  s_game.draw(display.getU8G2());
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
}