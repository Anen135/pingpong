#include "logic.h"
#include "terminal.h"
#define TIMEDALAY 50
int main() {
    short width, height;
    Terminal::getTerminalSize(width, height);
    Game game = Game(width / 2, height / 2, height / 2 - 1, height / 2 - 1, 1, 1);
    game.gameLoop();
    return 0;
}