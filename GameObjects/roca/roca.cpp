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
    gotoxy(x, y);
    std::cout << "      ";
    gotoxy(x, y);
    printf("\033[31m%c%c\033[0m", 219, 220);
    //*For Debug
    gotoxy(4, 0);
    std::cout << "x: " << x << " y: " << y << "       ";
    gotoxy(60, 0);
    std::cout << "MIN_X: " << MIN_X_MARCO;
    std::cout << " MAX_X: " << MAX_X_MARCO;
    //**End for debug
}

void ROCA::Update(double elapsedSeconds)
{

    x -= velocity;
}

void ROCA::HandleEvents()
{
    estaEnLimite();
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
    // Si 5 es mayor o igual que 6 y 8 es menor o igual que 6
    const int _max_x_marco = MAX_X_MARCO - 1;
    // if (!isOdd(_max_x_marco))
    // {
    //     if (x >= limite-1 && x <= limite-1)
    //     {
    //         gotoxy(x, y);
    //         std::cout << "   ";
    //         x = inicialX;
    //         Sleep(1000);
    //     }
    // }else{
    //     if (x >= limite && x <= limite)
    //     {
    //         gotoxy(x, y);
    //         std::cout << "   ";
    //         x = inicialX;
    //         Sleep(1000);
    //     }
    // }

    if (!isOdd(_max_x_marco)){
        limite -= 1;
    }
    if (x >= limite && x <= limite)
    {
        gotoxy(x, y);
        std::cout << "   ";
        x = inicialX;
        Sleep(1000);
    }
}
