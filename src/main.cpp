#include "SnakeGame.hpp"
#include "DigitalPin.hpp"
#include "Keyboard.hpp"
#include "Menu.hpp"

SH1106 display;
SnakeGame s_game;
Joystick j(J1_X_AXIS_PIN, J1_Y_AXIS_PIN, J1_BUTTON_PIN);
Keyboard4x4 keyboard(pin_rows, pin_columns);
Menu menu(display.getU8G2());

void (*resetFunc)(void) = 0;

void setup(void)
{
  Serial.begin(9600);
  display.init();
  s_game.draw(display.getU8G2());

  //menu.showWelcomeScrean(1);
  //_delay_ms(2000);
  //menu.showWelcomeScrean(0);
  //_delay_ms(2000);

  while (1)
  {
    uint8_t highlight = menu.MainMenu(j, keyboard);

    if (highlight == 0)
    {
      menu.showSnakeScrean();
      while (j.sprawdzPrzycisk() && !keyboard.read() && j.sprawdzRuch() == RUCH::NONE)
      {
      }
      _delay_ms(200);
      break;
    }
    else if (highlight == 1)
    {
      _delay_ms(200);
      menu.ScoreMenu(j, keyboard);
      _delay_ms(200);
    }
    else if (highlight == 2)
    {
      _delay_ms(200);
      while (1)
      {
        uint8_t highlight_setings = menu.SetingsMenu(j, keyboard);
        if (highlight_setings == 0)
        {
          _delay_ms(200);
          if (keyboard.getIsActive())
          {
            keyboard.setIsActive(false);
            j.setIsActive(true);
          }
          else
          {
            keyboard.setIsActive(true);
            j.setIsActive(false);
          }
        }
        else if (highlight_setings == 1)
        {
          _delay_ms(200);
          if (j.getIsActive())
          {
            keyboard.setIsActive(true);
            j.setIsActive(false);
          }
          else
          {
            keyboard.setIsActive(false);
            j.setIsActive(true);
          }
        }
        else
        {
          _delay_ms(200);
          break;
        }
      }
    }
    else
    {
      resetFunc();
    }
  }
}

void loop(void)
{
  s_game.gameSpeed(20);

  if(j.getIsActive())
  {
    if (j.sprawdzPrzycisk() == false)
    {
      s_game.gamePause(display.getU8G2());
      _delay_ms(1000);
      while (j.sprawdzPrzycisk() == true)
      {
        _delay_ms(50);
      }
      s_game.counter(display.getU8G2());
    }
  }
  else
  {
    if (keyboard.read() == '5')
    {
      s_game.gamePause(display.getU8G2());
      _delay_ms(1000);
      while (keyboard.read() != '5')
      {
        _delay_ms(50);
      }
      s_game.counter(display.getU8G2());
    }
  }

  if (j.getIsActive())
    s_game.makeMove(j.sprawdzRuch());
  else
  {
    switch (keyboard.read())
    {
    case '2':
      s_game.makeMove(RUCH::UP);
      break;

    case '4':
      s_game.makeMove(RUCH::LEFT);
      break;

    case '6':
      s_game.makeMove(RUCH::RIGHT);
      break;

    case '8':
      s_game.makeMove(RUCH::DOWN);
      break;

    default:
      s_game.makeMove(RUCH::NONE);
      break;
    }
  }

  s_game.draw(display.getU8G2());
  if (s_game.checkCollisions())
  {
    s_game.gameOver(display.getU8G2());
    resetFunc();
  }

  s_game.eatApple();

  //char temp = keyboard.read();
}