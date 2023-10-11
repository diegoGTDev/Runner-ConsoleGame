#ifndef ROCA_H
#define ROCA_H
#include "../../Console/functions.h"
#include "../../General/constantes.h"
#include "../Obstacle/IObstacle.h"
class Rock : public IObstacle{ 
  public:
    Rock(int _x, int _y){
      x = _x;
      y = _y;
      initialX = _x;
      initialY = _y;

    }
    void Render();
    void Update(double elapsedSeconds);
    void HandleEvents();
    void Release();
    inline int getObstacleSize() override { return _obstacle_size; };
    int getX() override;
    int getY();
    int getId() {return _id;};
    inline int isInLimit() { return _inLimit; };
    inline int getInitialX() { return initialX; };
    private:
      int initialX, initialY;
      int velocity = 2;
      int x, y;
      int _inLimit = 0;
      void estaEnLimite();
      int _id = 0;
      int _obstacle_size = 2;
      

};
#endif