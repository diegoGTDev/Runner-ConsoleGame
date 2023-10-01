#include "Game.h"
#include <iostream>
#include "../General/constantes.h"
#include "../General/gotoxy.h"
using namespace std;

void Game::maximizarConsola(){
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
}

void Game::escribirAlgoritmos(){
    const char* palabra[11] = {
        "          $$\\                               $$\\   $$\\                                ",
"          $$ |                              \\__|  $$ |         ",  
" $$$$$$\\  $$ | $$$$$$\\   $$$$$$\\   $$$$$$\\  $$\\ $$$$$$\\   $$$$$$\\$$$$\\   $$$$$$\\   $$$$$$$\\ ",   
" \\____$$\\ $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ $$ |\\_$$  _|  $$  _$$  _$$\\ $$  __$$\\ $$  _____|",  
" $$$$$$$ |$$ |$$ /  $$ |$$ /  $$ |$$ |  \\__|$$ |  $$ |    $$ / $$ / $$ |$$ /  $$ |\\$$$$$$\\  ", 
"$$  __$$ |$$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$\\ $$ | $$ | $$ |$$ |  $$ | \\____$$\\ ",
"\\$$$$$$$ |$$ |\\$$$$$$$ |\\$$$$$$  |$$ |      $$ |  \\$$$$  |$$ | $$ | $$ |\\$$$$$$  |$$$$$$$  |",
" \\_______|\\__| \\____$$ | \\______/ \\__|      \\__|   \\____/ \\__| \\__| \\__| \\______/ \\_______/ ",
"              $$\\   $$ |                                                                    ",
"              \\$$$$$$  |                                                                    ",
"               \\______/  "
    };
    //Escribir la palabra en consola con gotoxy
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    x = x/2-45;
    y = y/2;
    for(int i = 0; i <= 10; i++){
        gotoxy(x,y);
        cout<<palabra[i];
        y++;
    }


}


//Funcion para imprimir el margen
void Game::imprimir(int x, int y, char* w){
    const int _TIME = 0.999;
    gotoxy(x,y);
    //cout<<w;
    //Print ascii character 177
    printf("%c", w);
    Sleep(_TIME);
}

//Dibujamos un margen al rededor de la consola
void Game::dibujarMargen(int x,int y, int max_x, int max_y){
    char* c = "\100";
    for(int i = 0; i < max_x; i++){
        imprimir(x,y, c);
        x++;
    }
    for(int i = 0; i < max_y; i++){
        imprimir(x,y, c);
        y++;
    }
    for(int i = 0; i < max_x; i++){
        imprimir(x,y, c);
        x--;
    }
    for(int i = 0; i < max_y; i++){
        imprimir(x,y, c);
        y--;
    }

    if (x <= 4 && y <= 2){
        dibujarMargen(x+1,y+1,max_x-2, max_y-2);
    }
    return;
}
