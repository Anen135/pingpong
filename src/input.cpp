#include "input.h"
#include "logic.h"
#include "draw.h"
#include <conio.h>
#include <iostream>

void InputProvider::input() {
    if (_kbhit()) {
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();
        if ((key == 'w' || key == 'W') && *paddleLeftY > 1) {
            clearObject(1, *paddleLeftY + 1);
            (*paddleLeftY)--;
            drawPaddle(1, *paddleLeftY + 0);
        }
        else if ((key == 's' || key == 'S') && *paddleLeftY < *height - 3){
            clearObject(1, *paddleLeftY + 0);
            (*paddleLeftY)++;
            drawPaddle(1, *paddleLeftY + 1);
        }
        else if (key == 72 && *paddleRightY > 1) {
            clearObject(*width - 2, *paddleRightY + 1);
            (*paddleRightY)--;
            drawPaddle(*width - 2, *paddleRightY + 0);
        }
        else if (key == 80 && *paddleRightY < *height - 3) {
            clearObject(*width - 2, *paddleRightY + 0);
            (*paddleRightY)++;
            drawPaddle(*width - 2, *paddleRightY + 1);
        }
        else if (key == 27) *gameOver = true;   
    }
}

bool* InputProvider::gameOver = nullptr;
short* InputProvider::paddleLeftY = nullptr;
short* InputProvider::paddleRightY = nullptr;
short* InputProvider::height = nullptr;
short* InputProvider::width = nullptr;