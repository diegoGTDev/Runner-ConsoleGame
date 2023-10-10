#ifndef ROCA_H
#define ROCA_H
#include "../../Console/functions.h"
#include "../../General/constantes.h"
#include "../Obstacle/IObstacle.h"
class ROCA : public IObstacle{ 
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
    void Release();


    int getX() override;
    int getY();
    int getId() {return _id;};
    inline int isInLimit() { return _inLimit; };
    private:
      int velocity = 2;
      int x, y;
      int inicialX, inicialY;
      int _inLimit = 0;
      void estaEnLimite();
      int _id = 0;
      

};
#endif