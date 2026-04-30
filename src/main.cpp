#include "logic.h"
#include "terminal.h"
#include "aicontroller.h"
#define TIMEDALAY 50
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    short width, height;
    Terminal::getTerminalSize(width, height);
    Terminal::PrintStartScreen(width, height);
    Game game = Game(width / 2, height / 2, height / 2 - 1, height / 2 - 1, 1, 1);
    auto bot1 = new AIController();
    auto bot2 = new AIController();
    bot1->setBallTarget(&game.ballY);
    bot2->setBallTarget(&game.ballY);
    game.leftController = bot1;
    game.rightController = bot2;
    game.gameLoop();
    return 0;
}