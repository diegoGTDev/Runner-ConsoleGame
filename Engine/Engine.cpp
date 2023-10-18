#include "Engine.h"
#include "../GameObjects/Player/Player.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#include"../GameObjects/roca/roca.h"
#include"../GameObjects/nube/nube.h"
#include"../Console/functions.h"
#include"../Console/UserInterface/UI.h"
#include"../Profile_System/Profile/Profile.h"
#include"../Profile_System/ProfileRepository/ProfileRepository.h"
#include"../ObstacleManager/ObstacleManager.h"
#include<vector>
#include"../GameObjects/Obstacle/IObstacle.h"
using namespace std;
Engine* Engine::_instance = nullptr;
Player *_player;
NUBE * _nube;
bool Engine::Init()
{
    //Init
    _MAX_X = MAX_X;
    _MAX_Y = MAX_Y;
    _MIN_X_MARCO = MIN_X_MARCO;
    _MAX_X_MARCO = MAX_X_MARCO;
    _MIN_Y_MARCO = MIN_Y_MARCO;
    ocultarCursor();
    ObstacleManager::GetInstance()->Init();
    _profile = UI::GetInstance()->drawProfileRegister();
    system("cls");
    UI::GetInstance()->drawFrame(4, 2, _MAX_X, _MAX_Y);
    UI::GetInstance()->drawPlayerName(_profile);
    int xPosPlayer = (isOdd(_MAX_X_MARCO-1)) ? _MIN_X_MARCO + 29  : _MIN_X_MARCO + 30;
    _player = new Player (xPosPlayer, _MAX_Y_MARCO); 
    _nube = new NUBE(_MAX_X_MARCO-9, _MIN_Y_MARCO); 
    return _isRunning=true;
}

void Engine::Update(double elapsedSeconds)
{
    
    ObstacleManager::GetInstance()->ObstacleGenerator(elapsedSeconds); // Genera obstáculos aleatorios
    ObstacleManager::GetInstance()->Update(elapsedSeconds);

    _nube->Update();
    _player->Update(_profile);
    UI::GetInstance()->drawScore(_profile);

}

void Engine::Release()
{
    _isRunning = false;
    ObstacleManager::GetInstance()->Release();
    delete _player;
    delete _nube;
    system("cls");
}


void Engine::HandleEvents()
{
    _obstacles = ObstacleManager::GetInstance()->GetObstacles();
    char tecla = 0;
    if (_kbhit()){
        tecla = getch();
    }
    if (tecla == 27){
        this->_isRunning = false;
    }
    fflush(stdin);
    _player->HandleEvents(tecla, _obstacles, _MIN_X_MARCO, _MAX_X_MARCO);

    ObstacleManager::GetInstance()->HandleEvents();
    _nube->HandleEvents();

    //GameOver Event
    if (_player->getColisionado()){
        ProfileRepository::GetInstance()->modifyProfile(_profile);
        UI::GetInstance()->drawGameOver(_profile.getScore(), _profile.getName());
        this->_isRunning = false;
    }

}

void Engine::Render()
{
    //Render
    _player->Render();

    ObstacleManager::GetInstance()->Render();
    _nube->Render();
    Sleep(TIME);
}
