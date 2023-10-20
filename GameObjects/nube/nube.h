#pragma once
#include "../../Console/functions.h"
#include "../../General/constantes.h"
class Cloud{
    int x, y;
    int max_x_marco = MAX_X_MARCO;
    int inicialX = max_x_marco-9;
    int inicialY;
    

    public:
        Cloud(int _x, int _y) : x(_x) , y(_y), inicialY(_y) {}
        void Render();
        void HandleEvents();
        void Update();
        void Release();
        void estaEnLimite();
};