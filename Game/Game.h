//Declaramos
#ifndef GAME_H
#define GAME_H
class Game{

    public:
    Game(){

    }
    void maximizarConsola();
    void escribirAlgoritmos();
    void dibujar(char* w);
    void imprimir(int x, int y, char* w);
    void dibujarMargen(int x,int y, int max_x, int max_y);
};
#endif