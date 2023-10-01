#include "../Game/Game.h"
#include "../General/gotoxy.h"
#include "../General/gotoxy.h"
#include "./roca.h"
#include "conio.h"
#include<iostream>
#include "roca.h"
void ROCA::dibujar(){
    gotoxy(x, y);
    printf("%c%c", 219, 220);

}

void ROCA::mover(){
    gotoxy(x, y);
    std::cout<<"   ";
    x--;
    dibujar();
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

