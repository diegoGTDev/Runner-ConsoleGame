#include "UI.h"
#include <iostream>
#include "../functions.h"
#include "../../General/constantes.h"
#include<string>
#include<windows.h>
#include<conio.h>
#include<vector>
#include"../../Profile_System/ProfileRepository/ProfileRepository.h"
UI* UI::_instance = nullptr;
void UI::drawFrame(int x, int y, int max_x, int max_y)
{
       max_x -= 8;
    max_y -= 8;
    char c = 223;

    for(int i = 0; i < max_x; i++){
        imprimir(x,y, 205);
        x++;
    }
    
    for(int i = 0; i < max_y; i++){
        imprimir(x,y+1, 186);
        y++;
    }
    
    for(int i = 0; i < max_x; i++){
        imprimir(x,y, 205);
        x--;
    }
    for(int i = 0; i < max_y; i++){
        imprimir(x,y, 186);
        y--;
    }
    imprimir(4,2, 201);
    imprimir(max_x+4,y, 187);
    imprimir(max_x+4,max_y+2, 188);
    imprimir(4,max_y+2, 200);
    // if (x <= 4 && y <= 2){
    //     dibujarMargen(x+1,y+1,max_x-2, max_y-2);
    // }
    return;
}

void UI::drawGameOver(int score, char *name)
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    gotoxy(x/2,y/2);
    std::cout << "GAME OVER";
    gotoxy(x/2-5,y/2+1);
    std::cout<<name<<" HAS PERDIDO";
    gotoxy(x/2-1,y/2+2);
    std::cout << " Punteo: "<<std::to_string(score);
    Sleep(1000);
    //exit(0);
}

void UI::drawScore(int score){
    gotoxy(4, 1);
    std::cout<<"Score: "<<std::to_string(score);
    
}

void UI::drawPlayerName(Profile profile){
    gotoxy(4, 0);
    std::cout<<"Player: "<<profile.getName();
}
Profile UI::drawProfileRegister(){
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    Profile profile;
    gotoxy(x/2-5,y/2);
    std::cout << "REGISTRO DE PERFIL";
    gotoxy(x/2-5,y/2+1);
    char tempName[30];
    std::cout << "Nombre: ";std::cin.getline(tempName, 30);
    fflush(stdin);
    profile.setName(tempName);
    ProfileRepository::GetInstance()->addProfile(profile);
    gotoxy(x/2-5,y/2+2);
    std::cout << "Presione ENTER para continuar";
    getch();
    return profile;
}

void UI::drawHighestScores(){
    system("cls");
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    vector<Profile> profiles = ProfileRepository::GetInstance()->getProfiles();
    gotoxy(x/2-5,y/2);
    cout<<"PUNTEOS MAS ALTOS";
    if (profiles.size() == 0){
        gotoxy(x/2-5,y/2+1);
        std::cout << "No hay puntuaciones";
        gotoxy(x/2-5,y/2+2);
        std::cout << "Presione ENTER para continuar";
        getch();
        return;
    }
    for(int i = 0; i<profiles.size();i++){
        for(int j = 0; j<profiles.size()-1;j++){
            if (profiles[j].getScore() < profiles[j+1].getScore()){
                Profile temp = profiles[j];
                profiles[j] = profiles[j+1];
                profiles[j+1] = temp;
            }
        }
    }
    for(int i = 0; i<profiles.size(); i++){
        gotoxy(x/2-5,y/2+i+1);
        std::cout<< profiles[i].getName()<<"---->"<<profiles[i].getScore();
        if (i == 5){
            break;
        }
    }
    gotoxy(x/2-5,y/2+6);
    std::cout << "Presione ENTER para continuar";
    getch();
}