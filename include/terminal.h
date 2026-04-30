#include <windows.h>
#include <iostream>

namespace Terminal {
   void getTerminalSize(short& columns, short& rows);
   void PrintStartScreen(short& width, short& heigh);
}