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
        if (!ballY) return 0;

        short nextBallY = *ballY + 1;
        // Или просто сделайте зону остановки ИИ более строгой:
        
        if (*ballY < *paddleY) return -1;
        if (*ballY > *paddleY) return 1; // Целимся всегда верхним краем в мяч

        return 0;
    }
};