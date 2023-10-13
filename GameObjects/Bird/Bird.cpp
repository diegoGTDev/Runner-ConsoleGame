#include "Bird.h"
#include<iostream>
#include "../../Console/functions.h"
#include "../../General/constantes.h"
using namespace std;
void Bird::Render()
{
    Release();
    char* bird[5] = {"\033[1;34m/", "^","v","^","\\\033[0m"};
    for (int j = 0; j< 5; j++){
        gotoxy(_x+j,_y);
        std::cout << bird[j];
    }
    // gotoxy(60, 0);
    // std::cout<<"bird x: "<<_x<<" y: "<<_y<<" ";
}

void Bird::HandleEvents()
{
    DetectLimit();
}

void Bird::Release()
{
    for(int i = 0; i < 5; i++){
        gotoxy(_x+i,_y);
        std::cout << "    ";
    }
}

int Bird::getX()
{
    return _x;
}

int Bird::getY()
{
    return _y;
}

void Bird::Update(double elapsedSeconds)
{
   _x -= velocity;
}

void Bird::DetectLimit(){
    int limite = MIN_X_MARCO;
    const int _max_x_marco = MAX_X_MARCO - 1;
    if (!isOdd(_max_x_marco)){
        limite -= 1;
    }
    if (_x>=limite && _x<=limite){
        _inLimit = 1;
    }
}