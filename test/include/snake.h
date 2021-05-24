#ifndef SNAKE_H_
#define SNAKE_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <EEPROM.h>

#define NO_MOVE 0
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define PAUSE 51

struct snake {
	vector<byte> x;
	vector<byte> y;
	byte side;
};

struct apple {
	byte x;
	byte y;
};

class Snake
{
public:
	void gamePause();
	byte aRead();
	void dFrame();
	apple dApple();
	snake dSnake();
	void dSnakePath(snake s);
	void dApplePath(apple a);
	void moveSnakePath(snake& s);
	bool frameCollision(snake s);
	void gameOver(unsigned int score);
	void showAS(snake s, apple a);
	void eat(snake& s, apple& a);
	void moveBlock(snake& s, apple& a);
	bool snakeCollision(snake s);
	void menu();
  void init();
  void showScore();
  void addScore(unsigned int score);
};


int freeRam();
#endif
