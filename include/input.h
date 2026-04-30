#pragma once
#include "controller.h"

class InputProvider {
public:
    static bool* gameOver;
    static short* paddleLeftY, *paddleRightY;
    static short* height, *width;
    static Controller* leftController;
    static Controller* rightController;
    static short* ballY;

    static void input();
};