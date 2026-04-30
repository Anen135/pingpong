#pragma once
#include "controller.h"
#include <conio.h>

class KeyboardController : public Controller {
private:
    short* minY;
    short* maxY;
    short* paddleY;
    int upKey;
    int downKey;

public:
    KeyboardController(int upKey = 87, int downKey = 83) : upKey(upKey), downKey(downKey), minY(nullptr), maxY(nullptr), paddleY(nullptr) {}

    void setBounds(short* minY, short* maxY, short* paddleY) override {
        this->minY = minY;
        this->maxY = maxY;
        this->paddleY = paddleY;
    }

    short getMoveDirection() override {
        if (_kbhit()) {
            int key = _getch();
            if (key == 0 || key == 224) key = _getch();
            if ((key == upKey || key == upKey - 32) && minY && paddleY && *paddleY > *minY) {
                return -1;
            }
            else if ((key == downKey || key == downKey - 32) && maxY && paddleY && *paddleY < *maxY - 2) {
                return 1;
            }
        }
        return 0;
    }
};