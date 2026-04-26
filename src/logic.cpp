#include "logic.h"

Game::Game(short width, short height, short ballX, short ballY, short paddleLeftY, short paddleRightY, short ballVelX, short ballVelY)
    : width(width),
      height(height),
      ballX(ballX),
      ballY(ballY),
      paddleLeftY(paddleLeftY),
      paddleRightY(paddleRightY),
      ballVelX(ballVelX),
      ballVelY(ballVelY) {
    InputProvider::gameOver = &gameOver;
    InputProvider::paddleLeftY = &paddleLeftY;
    InputProvider::paddleRightY = &paddleRightY;
    InputProvider::height = &height;
    InputProvider::width = &width;
}

Game::Game() {
    InputProvider::gameOver = &gameOver;
    InputProvider::paddleLeftY = &paddleLeftY;
    InputProvider::paddleRightY = &paddleRightY;
    InputProvider::height = &height;
    InputProvider::width = &width;
}

void Game::logic() {
    ballX += ballVelX;
    ballY += ballVelY;
    if (ballY <= 1 || ballY >= height - 2) REVERSE(ballVelY);
    if ((ballX == 2 && (ballY == paddleLeftY || ballY == paddleLeftY + 1)) || (ballX == width - 3 && (ballY == paddleRightY || ballY == paddleRightY + 1))) REVERSE(ballVelX);
    if (ballX <= 0 || ballX >= width - 1) { resetBall; }
}

void Game::gameLoop() {
    hideCursor();
    drawBorder(width, height);
    while (!gameOver) {
        draw(width, height, ballX, ballY, paddleLeftY, paddleRightY);
        Sleep(timedelay);
        clearFrame;
        logic();
        InputProvider::input();
    }
}