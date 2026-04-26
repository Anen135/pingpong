#include "logic.h"
#define width 40
#define height 20
#define TIMEDALAY 50

constexpr short initBallX = width / 2, initBallY = height / 2;
constexpr short initPaddleLeftY  = height / 2 - 1, initPaddleRightY = initPaddleLeftY;
constexpr short initBallVelX = 1, initBallVelY = initBallVelX;

int main() {
    Game game = Game(width, height, initBallX, initBallY, initPaddleLeftY, initPaddleRightY, initBallVelX, initBallVelY);
    game.gameLoop();
    return 0;
}