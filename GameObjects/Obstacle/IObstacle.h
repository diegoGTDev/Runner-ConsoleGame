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

private:
    int _inLimit = 0;
    int x, y;
    int _id;
};