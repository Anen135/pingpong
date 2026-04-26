#include "terminal.h"

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
}