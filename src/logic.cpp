#include "logic.h"
#include "terminal.h"
#include "keyboardcontroller.h"
#include "aicontroller.h"
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
    InputProvider::ballY = &this->ballY;
    InputProvider::leftController = leftController;
    InputProvider::rightController = rightController;
}

Game::Game() {
    Terminal::getTerminalSize(width, height);
    InputProvider::gameOver = &gameOver;
    InputProvider::paddleLeftY = &paddleLeftY;
    InputProvider::paddleRightY = &paddleRightY;
    InputProvider::height = &height;
    InputProvider::width = &width;
    InputProvider::ballY = &ballY;
    InputProvider::leftController = leftController;
    InputProvider::rightController = rightController;
}

void Game::logic() {
    clearBall
    ballX += ballVelX;
    ballY += ballVelY;
    if (ballY <= 1 || ballY >= height - 2) REVERSE(ballVelY);
    if ((ballX <= 2 && (ballY == paddleLeftY || ballY == paddleLeftY + 1)) || (ballX == width - 3 && (ballY == paddleRightY || ballY == paddleRightY + 1))) REVERSE(ballVelX);
    if (ballX <= 0 || ballX >= width - 1) { resetBall }
    drawBall(ballX, ballY)
}

void Game::gameLoop() {
    InputProvider::leftController = this->leftController;
    InputProvider::rightController = this->rightController;
    hideCursor()
    drawPaddle(1, paddleLeftY + 0)
    drawPaddle(1, paddleLeftY + 1)
    drawPaddle(width - 2, paddleRightY + 1)
    drawPaddle(width - 2, paddleRightY + 0)
    while (!gameOver) {
        Terminal::getTerminalSize(width, height);
        drawBorder(width, height)
        Sleep(timedelay);
        InputProvider::input();
#ifdef DEBUG
        std::cout << "Ball: (" << ballX << ", " << ballY << ") | Paddles: (" << *InputProvider::paddleLeftY << ", " << *InputProvider::paddleRightY << ")" << std::endl;
        std::cout << (InputProvider::paddleLeftY == &paddleLeftY ? "Left Paddle OK" : "Left Paddle NOT OK") << " | " << " " << (InputProvider::paddleRightY == &paddleRightY ? "Right Paddle OK" : "Right Paddle NOT OK") << " | " << (InputProvider::gameOver == &gameOver ? "Game Over OK" : "Game Over NOT OK") << " | " << (InputProvider::height == &height ? "Height OK" : "Height NOT OK") << " | " << (InputProvider::width == &width ? "Width OK" : "Width NOT OK") << std::endl;
#endif
        logic();
    }
}