#include "UI.h"
#include <iostream>
#include "../functions.h"
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

void UI::drawScore(int score){
    gotoxy(4, 1);
    std::cout<<"Score: "<<std::to_string(score);
}