#include "./roca.h"
#include "conio.h"
#include <iostream>
#include "roca.h"
#include "../../Console/functions.h"
#include <cmath>
// Fordebug
#include <windows.h>
void ROCA::Render()
{
    Release();
    gotoxy(x, y);
    printf("\033[31m%c%c\033[0m", 219, 220);
    //*For Debug
    // gotoxy(4, 0);
    // std::cout << "x: " << x << " y: " << y << "       ";
    // gotoxy(60, 0);
    // std::cout << "MIN_X: " << MIN_X_MARCO;
    // std::cout << " MAX_X: " << MAX_X_MARCO;
    //**End for debug
    //Sleep(1000);
}

void ROCA::Update(double elapsedSeconds)
{

    x -= velocity;
    //estaEnLimite();
}

void ROCA::HandleEvents()
{
    estaEnLimite();
}

void ROCA::Release()
{
    gotoxy(x, y);
    std::cout << "    ";
}

int ROCA::getX()
{
    return x;
}

int ROCA::getY()
{
    return y;
}
void ROCA::estaEnLimite()
{
    int limite = MIN_X_MARCO;
    const int _max_x_marco = MAX_X_MARCO - 1;

    if (!isOdd(_max_x_marco)){
        limite -= 1;
    }
    if (x >= limite && x <= limite || x <= limite)
    {
        Sleep(500);
        _inLimit = 1;
        // gotoxy(x, y);
        // std::cout << "   ";
        // x = inicialX;
    }
}
