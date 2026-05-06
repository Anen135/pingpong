#pragma once
#include "draw.h"
#include "input.h"
#include "controller.h"
#define REVERSE(X) (X *= -1)
#define clearBall clearObject(ballX, ballY)
#define resetBall { ballX = width / 2; ballY = rand() % (height - 2) + 2; REVERSE(ballVelX); }
#define clearPaddles {\
    clearObject(1, paddleLeftY + 0);\
    clearObject(width - 2, paddleRightY + 0);\
    clearObject(1, paddleLeftY + 1);\
    clearObject(width - 2, paddleRightY + 1);\
}
#define clearFrame { clearBall; clearPaddles; }
class Game {
public:
short ballX = 20;
short ballY = 10;
short paddleLeftY, paddleRightY = 9;
short ballVelX, ballVelY = 1;
short width = 40;
short height = 20;
short timedelay = 50;
bool gameOver = false;
Controller* leftController = nullptr;
Controller* rightController = nullptr;


Game(short ballX, short ballY, short paddleLeftY, short paddleRightY, short ballVelX, short ballVelY);
Game();
void logic();
void gameLoop();
};