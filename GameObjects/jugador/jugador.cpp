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
#include<vector>
#include"../Obstacle/IObstacle.h"

#include<windows.h>

void JUGADOR::Render(){
    char* jugador[3] = {"\033[1;34m/ \\","/|\\", " O\033[0m"};
    for (int j = 0; j<3; j++){
        gotoxy(x,y-j);
        std::cout << jugador[j];
        
    }
    gotoxy(30, 0);
    std::cout<<"x: "<<x<<" y: "<<y<<"       ";

}

void JUGADOR::HandleEvents(char tecla, std::vector<IObstacle*> &obstacles)
{
    if (tecla == 32){
        this->saltar();
    }
    //Leer todos los obstaculos y verificar si hay colision
    for (int i = 0; i<obstacles.size(); i++){
        if (this->colision(*obstacles[i])){
            this->colisionado = 1;
        }
    }
}
void JUGADOR::Update(Profile& profile){
    this->caer();
    this->setPunteo(this->getPunteo()+1);
    profile.setScore(this->getPunteo());

}
void JUGADOR::Release()
{
    for(int i = 0; i < 3; i++){
        gotoxy(x,y-i);
        std::cout << "   ";
    }
}
void JUGADOR::mover()
{
    x++;
}

void JUGADOR::caer(){

    if(estaEnElAire){
        Release();
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
            Release();
        }         
            // Render();
        
    }


}

void JUGADOR::saltar(){
    if (!estaEnElAire){      
        dy = -2;
        estaEnElAire = true;
    }
}
int JUGADOR::colision(IObstacle &obs){
    
    if ((x>= obs.getX() && x <= obs.getX() && y >= obs.getY() && y <= obs.getY() )
    ||(x-1>= obs.getX() && x-1 <= obs.getX() && y >= obs.getY() && y <= obs.getY() )|| 
    (x+2>= obs.getX()+1 && x+2 <= obs.getX()+1 && y >= obs.getY() && y <= obs.getY()) || 
    (x+2>= obs.getX() && x+2 <= obs.getX() && y >= obs.getY() && y <= obs.getY() )){
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