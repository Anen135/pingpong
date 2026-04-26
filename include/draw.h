#pragma once
#include <windows.h>
#include <iostream>
#define setCursor(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
#define clearObject(x, y) {SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y}); std::cout<<" ";}
#define drawBall(x, y) {SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y}); std::cout<<"O";}
#define drawPaddle(x, y) {SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y}); std::cout<<"|";}
#define drawBorder(width, height) {\
    for (short x = 0; x < width; x++) {\
        setCursor(x, 0); std::cout << "-";\
        setCursor(x, height - 1); std::cout << "-";\
    }\
}

#define hideCursor() {\
    CONSOLE_CURSOR_INFO cursorInfo;\
    cursorInfo.dwSize = 1;\
    cursorInfo.bVisible = FALSE;\
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);\
}