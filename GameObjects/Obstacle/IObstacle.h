#pragma once

class IObstacle
{
public:
    virtual void Update(double elapsedSeconds) = 0;
    virtual void Render() = 0;
    virtual void HandleEvents() = 0;
    virtual void Release() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getId() = 0;
    virtual inline int isInLimit() { return _inLimit; };
    virtual inline int getObstacleSize() { return _obstacle_size; };
    virtual inline int getInitialX() { return initialX; };
private:
    int _inLimit = 0;
    int x, y;
    int _id;
    int velocity;
    int _obstacle_size;
    int initialX, initialY;
};