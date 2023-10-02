#include <iostream>
#include <conio.h>
#include "Console/functions.h"
#include "General/constantes.h"
#include<stdlib.h>
#include "roca/roca.h"
#include "nube/nube.h"
#include "jugador/jugador.h"
#include <windows.h>
#include"Engine/Engine.h"
#include<chrono>
using namespace std;


int main() {
    
    auto lastTime = chrono::system_clock::now();
    Engine::GetInstance()->Init();
    while(Engine::GetInstance()->isRunning()){
        auto current = std::chrono::system_clock::now(); //Tiempo inicial
        std::chrono::duration<double> elapsedSeconds = current - lastTime; //Duracion
        Engine::GetInstance()->HandleEvents();
        Engine::GetInstance()->Update(elapsedSeconds.count());
        Engine::GetInstance()->Render();
        lastTime = current; //Tiempo final
    }
    return 0;

}
