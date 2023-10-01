#include "../General/gotoxy.h"
#include "../General/constantes.h"
#ifndef ROCA_H
#define ROCA_H
class ROCA{ 
  public:
    
    ROCA(int _x, int _y){
      x = _x;
      y = _y;
      inicialX = MAX_X_MARCO;
      inicialY = _y;

    }
    void dibujar();
    void mover();
    void estaEnLimite();
    int getX();
    int getY();
    private:
      int x, y;
      int inicialX, inicialY;
      

};
#endif