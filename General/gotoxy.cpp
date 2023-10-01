#include"gotoxy.h"
#ifndef GOTOXY_H
#define GOTOXY_H
void gotoxy(int x,int y)
{ HANDLE hcon;

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos; dwPos.X = x; dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);

}

int* obtenerMedidasConsola(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left ;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top ;

    return new int[2]{consoleWidth, consoleHeight};
}

#endif