#include "Engine.h"
#include "../jugador/jugador.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#include"../roca/roca.h"
#include"../nube/nube.h"
#include"../Console/functions.h"
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
    dibujarMargen(4,2, _MAX_X, _MAX_Y);
    _roca = new ROCA(_MAX_X_MARCO, _MAX_Y_MARCO);
    _jugador = new JUGADOR (_MIN_X_MARCO+30, _MAX_Y_MARCO); 
    _nube = new NUBE(_MAX_X_MARCO-9, _MIN_Y_MARCO); 
    return _isRunning=true;
}

void Engine::Update(double elapsedSeconds)
{
    _roca->Update();   
    _nube->Update();
}

void Engine::Release()
{
    _isRunning = false;
}


void Engine::HandleEvents()
{
    _jugador->HandleEvents(_roca);
    _roca->HandleEvents();
    _nube->HandleEvents();
}

void Engine::Render()
{
    //Render
    _jugador->Render();
    _roca->Render();
    _nube->Render();
    Sleep(TIME);
}
