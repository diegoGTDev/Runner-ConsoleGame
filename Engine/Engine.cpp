#include "Engine.h"
#include "../GameObjects/jugador/jugador.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#include"../GameObjects/roca/roca.h"
#include"../GameObjects/nube/nube.h"
#include"../Console/functions.h"
#include"../Console/UserInterface/UI.h"
#include"../Profile_System/Profile/Profile.h"
#include"../Profile_System/ProfileRepository/ProfileRepository.h"
using namespace std;
Engine* Engine::_instance = nullptr;
JUGADOR *_jugador;
ROCA* _roca;
NUBE * _nube;
bool Engine::Init()
{
    //Init
    ocultarCursor();
    maximizarConsola();
    system("Runner UMG");
    system("cls");
    UI::GetInstance()->drawMenu();
    _profile = UI::GetInstance()->drawProfileRegister();
    system("cls");
    UI::GetInstance()->drawFrame(4, 2, _MAX_X, _MAX_Y);
    UI::GetInstance()->drawPlayerName(_profile);
    //*For debug
    // _profile.setName("Jugador");
    // _profile.setScore(1000);
    //**End for debug
    int xPosPlayer = (isOdd(_MAX_X_MARCO-1)) ? _MIN_X_MARCO + 29  : _MIN_X_MARCO + 30;
    _roca = new ROCA(_MAX_X_MARCO-1, _MAX_Y_MARCO);
    _jugador = new JUGADOR (xPosPlayer, _MAX_Y_MARCO); 
    _nube = new NUBE(_MAX_X_MARCO-9, _MIN_Y_MARCO); 
    return _isRunning=true;
}

void Engine::Update(double elapsedSeconds)
{
    UI::GetInstance()->drawScore(_profile.getScore());
    _roca->Update(elapsedSeconds);   
    _nube->Update();
    _jugador->Update(_profile);

}

void Engine::Release()
{
    _isRunning = false;
}


void Engine::HandleEvents()
{
    char tecla = 0;
    if (_kbhit()){
        tecla = getch();
    }
    if (tecla == 27){
        this->_isRunning = false;
    }

    _jugador->HandleEvents(tecla, _roca);
    _roca->HandleEvents();
    _nube->HandleEvents();

    //GameOver Event
            if (_jugador->getColisionado()){
        ProfileRepository::GetInstance()->modifyProfile(_profile);
        UI::GetInstance()->drawGameOver(_profile.getScore(), _profile.getName());
        this->_isRunning = false;
    }
}

void Engine::Render()
{
    //Render
    _jugador->Render();
    _roca->Render();
    _nube->Render();
    Sleep(TIME);
}
