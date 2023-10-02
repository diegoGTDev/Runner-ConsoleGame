#include "functions.h"
#include <iostream>
#include "../General/constantes.h"
#include<windows.h>
using namespace std;

void maximizarConsola(){
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
}

void escribirAlgoritmos(){
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
void imprimir(int x, int y, char w){
    const int _TIME = 0;
    gotoxy(x,y);
    //cout<<w;
    //Print ascii character 177
    printf("%c", w);
    Sleep(_TIME);
}

//Dibujamos un margen al rededor de la consola
void dibujarMargen(int x,int y, int max_x, int max_y){
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


void gotoxy(int x,int y)
{ HANDLE hcon;

    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos; dwPos.X = x; dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);

}

int* obtenerMedidasConsola(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left ;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top ;

    return new int[2]{consoleWidth, consoleHeight};
}

