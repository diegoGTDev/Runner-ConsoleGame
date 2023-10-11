#include "Player.h"
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

void Player::Render(){
    Release();
    char* jugador[3] = {"\033[1;34m/ \\","/|\\", " O\033[0m"};
    for (int j = 0; j<3; j++){
        gotoxy(x,y-j);
        std::cout << jugador[j];
        
    }


}

void Player::HandleEvents(char tecla, std::vector<IObstacle*> &obstacles)
{
    if (tecla == 32){
        this->jump();
    }
    // else if (tecla == 65){
    //     this->moveLeft();
    // }
    // else if (tecla == 68){
    //     this->moveRight();
    // }
    //Read all the obstacles and check if  collides with the player.
    for (int i = 0; i<obstacles.size(); i++){
        if (this->collides(*obstacles[i])){
            this->colisionado = 1;
        }
    }
}
void Player::Update(Profile& profile){
    this->fall();
    this->setPunteo(this->getPunteo()+1);
    profile.setScore(this->getPunteo());

}
void Player::Release()
{
    for (int j = 0; j<3; j++){
        gotoxy(x-1,y-j);
        std::cout <<"     ";
    }
}
void Player::moveRight()
{
    x++;
}

void Player::moveLeft(){
    x--;
}

void Player::fall(){

    if(estaEnElAire){
        Release();
        y += round(dy);
        //Debug 
        //** Sleep(1000);
        //End for debug
        //Render();
        dy += 0.9;
        if (y >= NIVEL_TIERRA){
            y = NIVEL_TIERRA;
            dy = 0;
            estaEnElAire = false;
            Release();
        }         
            // Render();
        
    }


}

void Player::jump(){
    if (!estaEnElAire){      
        dy = -4;
        estaEnElAire = true;
    }
}
/**
 * @brief Check if the player collides with the obstacle.
 *
 * @param obs The obstacle to check.
 * 
 * @return 1 if the player collides with the obstacles, 0 otherwise.
 */
int Player::collides(IObstacle &obs){
    


    if (
    
    (x+1 >= obs.getX() && x+1 <= obs.getX() + obs.getObstacleSize()) && y >= obs.getY() && y <= obs.getY() ||
    (x+2 >= obs.getX() && x+2 <= obs.getX() + obs.getObstacleSize()) && y >= obs.getY() && y <= obs.getY() 
    )
    {
        return 1;
    }
    return 0;
}

void Player::GameOver()
{
}

int Player::getPunteo(){
    return this->punteo;
}

int Player::setPunteo(int punteo){
    this->punteo = punteo;
}