#include "jugador.h"
#include "../roca/roca.h"
#include "../General/gotoxy.h"
#include <iostream>
#include "../Game/Game.h"
#include "../General/constantes.h"
#include <windows.h>
#include<conio.h>


void JUGADOR::dibujar(){
    char* jugador[2] = {"|","O"};
    for (int j = 0; j<2; j++){
        gotoxy(x,y-j);
        std::cout << jugador[j];
        
    }

}

void JUGADOR::mover(){
    for (int k = 0; k<2; k++){
        std::cout << " ";
    }
    x++;
    dibujar();
}

void JUGADOR::caer(){

    if(estaEnElAire){
        for (int k = 0; k<2; k++){
            gotoxy(x,y-k);
            std::cout << " ";
        }
        y += dy;
        dibujar();
        dy += 1;
        if (y >= NIVEL_TIERRA){
            y = NIVEL_TIERRA;
            dy = 0;
            estaEnElAire = false;
                    for (int k = 0; k<2; k++){
            gotoxy(x,y-k);
            std::cout << " ";
        }         
            dibujar();
        }
    }


}

void JUGADOR::saltar(){
    if (!estaEnElAire){      
        dy = -3;
        estaEnElAire = true;
    }
}
void JUGADOR::colision(struct ROCA &ROCA){
    
    if (x >= ROCA.getX() && x <= ROCA.getX() && y >= ROCA.getY() && y <= ROCA.getY()){
        this->GameOver();
    }
}

void JUGADOR::GameOver()
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    system("cls");
    system("color 4e");
    gotoxy(x/2,y/2);
    std::cout << "GAME OVER";
    std::cout << " Punteo: "<<this->getPunteo();
    Sleep(1000);
    exit(0);
}

int JUGADOR::getPunteo(){
    return this->punteo;
}

int JUGADOR::setPunteo(int punteo){
    this->punteo = punteo;
}