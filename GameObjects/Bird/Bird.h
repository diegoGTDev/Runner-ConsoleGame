#ifndef BIRD_H
#define BIRD_H
#include"../Obstacle/IObstacle.h"
#pragma once

class Bird: public IObstacle
{
public:
    Bird(int x, int y) : _x(x), _y(y){};
    void Update(double elapsedSeconds);
    void Render();
    void HandleEvents();
    void Release();
    inline int isInLimit(){ return _inLimit;};
    void DetectLimit();
    int getX();
    int getY();
    int getId() {return _id;};
    inline int getObstacleSize() override { return _obstacle_size; };
    


private:
    int _x, _y;
    int _inLimit = 0;
    int velocity = 1;
    int _id = 1;
    int _obstacle_size = 5;
};

#endif


