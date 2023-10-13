#pragma once
#include<vector>
class IObstacle;
class Rock;
class Profile;
class Player{
    int x, y;
    double dy;
    int punteo = 0;
    char* nombre;
    bool estaEnElAire = false;
    int NIVEL_TIERRA;
    public:
        Player(int _x, int _y){
            x = _x;
            y = _y;
            NIVEL_TIERRA = _y;
        }
        void HandleEvents(char tecla, std::vector<IObstacle*> &obstacles, int min_x_marcom, int max_x_marco);
        void Render();
        void Update(Profile& profile);
        void Release();
        void jump();
        void moveRight();
        void moveLeft();
        void fall();
        inline int getColisionado(){return colisionado;};
        int collides(IObstacle &obs);
        void GameOver();
        int getPunteo();
        int setPunteo(int punteo);
    private:
        int colisionado = 0;
};