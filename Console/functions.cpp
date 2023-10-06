#include "functions.h"
#include <iostream>
#include "../General/constantes.h"
#include<windows.h>
using namespace std;

void maximizarConsola(){
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
}

//Funcion para imprimir el margen
void imprimir(int x, int y, char w){
    const int _TIME = 0;
    gotoxy(x,y);
    //cout<<w;
    //Print ascii character 177
    printf("%c", w);
    Sleep(_TIME);
}

int isOdd(int n){
    return n%2;
}

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

void ocultarCursor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursoInfo;
    CursoInfo.dwSize = 1;
    CursoInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &CursoInfo);
}