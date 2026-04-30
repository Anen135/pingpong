#include "terminal.h"
#define STARTSCREEN "Ping Pong v1.0"

namespace Terminal {
    void getTerminalSize(short& columns, short& rows) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        } else {
            columns = 40;
            rows = 20;
        }
    }

    void PrintStartScreen(short& width, short& height) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD pos;
        pos.X = width / 2 - strlen(STARTSCREEN);
        pos.Y = height / 2 - 2;

        SetConsoleCursorPosition(hConsole, pos);

        std::cout << STARTSCREEN << "." << height << "." << width << std::endl;
    }
}