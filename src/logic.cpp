#include "logic.h"
#include "terminal.h"
#include <iostream>

Game::Game(short ballX, short ballY, short paddleLeftY, short paddleRightY, short ballVelX, short ballVelY)
    : ballX(ballX),
      ballY(ballY),
      paddleLeftY(paddleLeftY),
      paddleRightY(paddleRightY),
      ballVelX(ballVelX),
      ballVelY(ballVelY) {
    Terminal::getTerminalSize(width, height);
    InputProvider::gameOver = &this->gameOver;
    InputProvider::paddleLeftY = &this->paddleLeftY;
    InputProvider::paddleRightY = &this->paddleRightY;
    InputProvider::height = &this->height;
    InputProvider::width = &this->width;
}

Game::Game() {
    Terminal::getTerminalSize(width, height);
    InputProvider::gameOver = &gameOver;
    InputProvider::paddleLeftY = &paddleLeftY;
    InputProvider::paddleRightY = &paddleRightY;
    InputProvider::height = &height;
    InputProvider::width = &width;
}

void Game::logic() {
    clearBall
    ballX += ballVelX;
    ballY += ballVelY;
    if (ballY <= 1 || ballY >= height - 2) REVERSE(ballVelY);
    if ((ballX == 2 && (ballY == paddleLeftY || ballY == paddleLeftY + 1)) || (ballX == width - 3 && (ballY == paddleRightY || ballY == paddleRightY + 1))) REVERSE(ballVelX);
    if (ballX <= 0 || ballX >= width - 1) { resetBall }
    drawBall(ballX, ballY)
}

void Game::gameLoop() {
    hideCursor();
    while (!gameOver) {
        Terminal::getTerminalSize(width, height);
        drawBorder(width, height);
        // draw(width, height, ballX, ballY, paddleLeftY, paddleRightY);
        Sleep(timedelay);
        // clearFrame
        InputProvider::input();
#ifdef DEBUG
        std::cout << "Ball: (" << ballX << ", " << ballY << ") | Paddles: (" << *InputProvider::paddleLeftY << ", " << *InputProvider::paddleRightY << ")" << std::endl;
        std::cout << (InputProvider::paddleLeftY == &paddleLeftY ? "Left Paddle OK" : "Left Paddle NOT OK") << " | " << " " << (InputProvider::paddleRightY == &paddleRightY ? "Right Paddle OK" : "Right Paddle NOT OK") << " | " << (InputProvider::gameOver == &gameOver ? "Game Over OK" : "Game Over NOT OK") << " | " << (InputProvider::height == &height ? "Height OK" : "Height NOT OK") << " | " << (InputProvider::width == &width ? "Width OK" : "Width NOT OK") << std::endl;
#endif
        logic();
    }
}