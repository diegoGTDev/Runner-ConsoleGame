#include "./roca.h"
#include "conio.h"
#include<iostream>
#include "roca.h"
void ROCA::Render(){
    gotoxy(x, y);
    printf("\033[31m%c%c\033[0m", 219, 220);

}

void ROCA::Update()
{
    this->mover();
}

void ROCA::HandleEvents()
{
    estaEnLimite();
}
void ROCA::mover(){
    gotoxy(x, y);
    std::cout<<"   ";
    x--;
    Render();
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
    if (x >=limite && x <= limite){
        gotoxy(x, y);
        std::cout<<"  ";
        if (x== limite){

            x = inicialX;
        }
    }
}

