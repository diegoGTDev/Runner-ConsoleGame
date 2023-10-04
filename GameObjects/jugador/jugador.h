#pragma once
class ROCA;
class Profile;
class JUGADOR{
    int x, y;
    int dy;
    int punteo = 0;
    char* nombre;
    bool estaEnElAire = false;
    int NIVEL_TIERRA;
    public:
        JUGADOR(int _x, int _y){
            x = _x;
            y = _y;
            NIVEL_TIERRA = _y;
        }
        void HandleEvents(char tecla, ROCA* roca);
        void Render();
        void Update(Profile profile);
        void mover();
        void saltar();
        void caer();
        int colision(struct ROCA &ROCA);
        void GameOver();
        int getPunteo();
        int setPunteo(int punteo);
    private:
        int colisionado = 0;
};