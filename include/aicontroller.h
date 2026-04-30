#pragma once
#include "controller.h"

class AIController : public Controller {
private:
    short* minY;
    short* maxY;
    short* paddleY;
    short* ballY;
    float reactionSpeed;

public:
    AIController(float speed = 0.5f) : reactionSpeed(speed) {}

    void setBounds(short* minY, short* maxY, short* paddleY) override {
        this->minY = minY;
        this->maxY = maxY;
        this->paddleY = paddleY;
    }

    void setBallTarget(short* ballY) {
        this->ballY = ballY;
    }

    short getMoveDirection() override {
        if (ballY == nullptr) return 0;

        short top = *paddleY;
        short bottom = *paddleY + 1;

        if (*ballY > bottom && bottom < *maxY)
            return 1;

        if (*ballY < top && top > *minY)
            return -1;

        return 0;
    }
};