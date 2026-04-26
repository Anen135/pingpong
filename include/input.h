#pragma once
class InputProvider {
public:
static bool* gameOver;
static short* paddleLeftY, *paddleRightY;
static short* height, *width;
static void input();
};