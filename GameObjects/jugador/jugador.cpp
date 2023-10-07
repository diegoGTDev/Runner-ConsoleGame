#include "jugador.h"
#include "../roca/roca.h"
#include "../../Console/functions.h"
#include <iostream>
#include "../../General/constantes.h"
#include <windows.h>
#include<math.h>
#include<conio.h>
#include"../../Console/UserInterface/UI.h"
#include"../../Profile_System/ProfileRepository/ProfileRepository.h"
#include"../../Profile_System/Profile/Profile.h"

#include<windows.h>

void JUGADOR::Render(){
    char* jugador[2] = {"|","O"};
    for (int j = 0; j<2; j++){
        gotoxy(x,y-j);
        std::cout << jugador[j];
        
    }
    gotoxy(30, 0);
    std::cout<<"x: "<<x<<" y: "<<y<<"       ";

}

void JUGADOR::HandleEvents(char tecla, ROCA* roca)
{
    if (tecla == 32){
        this->saltar();
    }
    this->colisionado = this->colision(*roca);
}
void JUGADOR::Update(Profile& profile){
    this->caer();
    this->setPunteo(this->getPunteo()+1);
    profile.setScore(this->getPunteo());

}
void JUGADOR::mover(){
    x++;
}

void JUGADOR::caer(){

    if(estaEnElAire){
        for (int k = 0; k<2; k++){
            gotoxy(x,y-k);
            std::cout << " ";
        }
        y += round(dy);
        //Debug 
        //** Sleep(1000);
        //End for debug
        //Render();
        dy += 0.30;
        if (y >= NIVEL_TIERRA){
            y = NIVEL_TIERRA;
            dy = 0;
            estaEnElAire = false;
                    for (int k = 0; k<2; k++){
            gotoxy(x,y-k);
            std::cout << " ";
        }         
            // Render();
        }
    }


}

void JUGADOR::saltar(){
    if (!estaEnElAire){      
        dy = -2;
        estaEnElAire = true;
    }
}
int JUGADOR::colision(struct ROCA &ROCA){
    
    if (x>= ROCA.getX() && x <= ROCA.getX() && y >= ROCA.getY() && y <= ROCA.getY()){
        return 1;
    }
    return 0;
}

void JUGADOR::GameOver()
{
}

int JUGADOR::getPunteo(){
    return this->punteo;
}

int JUGADOR::setPunteo(int punteo){
    this->punteo = punteo;
}