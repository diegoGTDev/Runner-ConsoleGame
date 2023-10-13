#include <iostream>
#include <conio.h>
#include "Console/functions.h"
#include "General/constantes.h"
#include <stdlib.h>
#include "GameObjects/roca/roca.h"
#include "GameObjects/nube/nube.h"
#include "GameObjects/Player/Player.h"
#include <windows.h>
#include "Engine/Engine.h"
#include <chrono>
#include "Console/UserInterface/UI.h"
#include "ObstacleManager/ObstacleManager.h"
using namespace std;

int main()
{

    maximizarConsola();
    system("Runner UMG");
    system("cls");

inicio:
    if (UI::GetInstance()->drawMenu())
    {
        Engine::GetInstance()->Release();
        return 0;
    };
    auto lastTime = chrono::system_clock::now();
    Engine::GetInstance()->Init();
    UI::GetInstance()->Init();
    while (Engine::GetInstance()->isRunning())
    {
        auto current = std::chrono::system_clock::now();                   // Tiempo inicial
        std::chrono::duration<double> elapsedSeconds = current - lastTime; // Duracion
        Engine::GetInstance()->HandleEvents();
        if (Engine::GetInstance()->isRunning())
        {
            Engine::GetInstance()->Update(elapsedSeconds.count());
            Engine::GetInstance()->Render();
        }
        lastTime = current; // Tiempo final
    }

    if (UI::GetInstance()->drawEndMenu())
    {
        Engine::GetInstance()->Release();
        goto inicio;
    }
    Engine::GetInstance()->Release();
    return 0;
}
