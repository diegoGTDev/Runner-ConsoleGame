#include "./roca.h"
#include "conio.h"
#include<iostream>
#include "roca.h"
#include<cmath>
//Fordebug
#include<windows.h>
void ROCA::Render(){
    gotoxy(x, y);
    std::cout<<"    ";
    gotoxy(x, y);
    printf("\033[31m%c%c\033[0m", 219, 220);
    gotoxy(4, 0);
    std::cout<<"x: "<<x<<" y: "<<y<<"       ";
    gotoxy(4, 0);

}

void ROCA::Update(double elapsedSeconds)
{

    x -= velocity;   
}

void ROCA::HandleEvents()
{
    estaEnLimite();
}


int ROCA::getX(){
    return x;
}

int ROCA::getY()
{
    return y;
}
void ROCA::estaEnLimite(){
    const int limite = MIN_X_MARCO;
    if (x+velocity >=limite && x<= limite){
        gotoxy(x, y);
        std::cout<<"   ";
        x = inicialX;
    }
}

