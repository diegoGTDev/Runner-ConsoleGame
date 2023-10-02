#include "../../Console/functions.h"
#include "../../General/constantes.h"
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
    void Render();
    void Update();
    void HandleEvents();


    int getX();
    int getY();
    private:
      int x, y;
      int inicialX, inicialY;
      void mover();
      void estaEnLimite();
      

};
#endif