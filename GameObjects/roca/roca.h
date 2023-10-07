#include "../../Console/functions.h"
#include "../../General/constantes.h"
#ifndef ROCA_H
#define ROCA_H
class ROCA{ 
  public:
    
    ROCA(int _x, int _y){
      x = _x;
      y = _y;
      inicialX = _x;
      inicialY = _y;

    }
    void Render();
    void Update(double elapsedSeconds);
    void HandleEvents();


    int getX();
    int getY();
    private:
      int velocity = 2;
      int x, y;
      int inicialX, inicialY;
      void estaEnLimite();
      

};
#endif