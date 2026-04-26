#include "input.h"
#include "logic.h"
#include <conio.h>

void InputProvider::input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'w' && *paddleLeftY > 1) (*paddleLeftY)--;
        else if (key == 's' && *paddleLeftY < *height - 3) (*paddleLeftY)++;
        else if (key == 72 && *paddleRightY > 1) (*paddleRightY)--;
        else if (key == 80 && *paddleRightY < *height - 3) (*paddleRightY)++;
        else if (key == 27) *gameOver = true;
    }
}

bool* InputProvider::gameOver = nullptr;
short* InputProvider::paddleLeftY = nullptr;
short* InputProvider::paddleRightY = nullptr;
short* InputProvider::height = nullptr;
short* InputProvider::width = nullptr;