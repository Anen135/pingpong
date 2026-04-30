#include "input.h"
#include "logic.h"
#include "draw.h"
#include <conio.h>
#include <iostream>

static short minBound = 1;
static short maxBound = 17;  // default, will be updated

void InputProvider::input() {
    if (_kbhit()) {
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();
        if (key == 27) *gameOver = true;
    }

    // Update bounds based on current terminal height
    if (height) {
        maxBound = *height - 3;  // paddle is 2 units tall, leave 1 for border
    }

    if (leftController) {
        leftController->setBounds(&minBound, &maxBound, paddleLeftY);
        short dir = leftController->getMoveDirection();
        if (dir != 0) {
            clearObject(1, *paddleLeftY + (dir > 0 ? 0 : 1));
            (*paddleLeftY) += dir;
            drawPaddle(1, *paddleLeftY);
            drawPaddle(1, *paddleLeftY + 1);
        }
    }

    if (rightController) {
        rightController->setBounds(&minBound, &maxBound, paddleRightY);
        short dir = rightController->getMoveDirection();
        if (dir != 0) {
            clearObject(*width - 2, *paddleRightY + (dir > 0 ? 0 : 1));
            (*paddleRightY) += dir;
            drawPaddle(*width - 2, *paddleRightY);
            drawPaddle(*width - 2, *paddleRightY + 1);
        }
    }
}

bool* InputProvider::gameOver = nullptr;
short* InputProvider::paddleLeftY = nullptr;
short* InputProvider::paddleRightY = nullptr;
short* InputProvider::height = nullptr;
short* InputProvider::width = nullptr;
Controller* InputProvider::leftController = nullptr;
Controller* InputProvider::rightController = nullptr;
short* InputProvider::ballY = nullptr;