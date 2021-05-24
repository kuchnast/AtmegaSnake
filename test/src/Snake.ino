/*
 Name:		Snake.ino
*/

#include "snake.h"

Snake sn;

void setup() {
	pinMode(PAUSE, INPUT);
	randomSeed(analogRead(15));
	Serial.begin(9600);
  sn.init();
  sn.addScore(0);
}

void loop() {
  sn.menu();
	snake s = sn.dSnake();
	apple a = sn.dApple();

	while (sn.frameCollision(s) && sn.snakeCollision(s)) {
		if (!digitalRead(PAUSE)) {
			sn.gamePause();
			delay(300);
		}

		byte cside = sn.aRead();

		if (cside == 0) {
			sn.moveBlock(s, a);
			continue;
		}
		else if (s.x.size() > 1 && (cside == s.side - 2 || cside == s.side + 2)) {
			sn.moveBlock(s, a);
			continue;
		}
		else if (cside == LEFT || cside == RIGHT) {
			while (s.y[0] % 4) {
				sn.moveBlock(s, a);
			}
		}
		else {
			while (s.x[0] % 4) {
				sn.moveBlock(s, a);
			}
		}
		s.side = cside;
		sn.moveBlock(s, a);
	}
	sn.gameOver(s.x.size());
}
