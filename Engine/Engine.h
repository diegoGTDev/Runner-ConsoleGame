#ifndef ENGINE_H

#define ENGINE_H
#include"../General/constantes.h"
#include"../Profile_System/Profile/Profile.h"
#include<vector>
#define CONSOLE_WIDTH MAX_X
#define CONSOLE_HEIGHT MAX_Y
#define TIME 15
class IObstacle;
class Engine
{
public:
    static Engine* GetInstance(){
        return _instance = (_instance != nullptr) ? _instance : new Engine();
    };
    bool Init();
    void Update(double elapsedSeconds);
    void Release();
    void HandleEvents();
    void Render();
    inline bool isRunning(){ return _isRunning; };
private:
    Engine(){};
    static Engine* _instance;
    bool _isRunning;
    Profile _profile;
    std::vector<IObstacle*> _obstacles;
    
    //---
    int _MAX_X = MAX_X;
    int _MAX_Y = MAX_Y;
    int _MAX_X_MARCO = MAX_X_MARCO;
    int _MAX_Y_MARCO = MAX_Y_MARCO;
    int _MIN_X_MARCO = MIN_X_MARCO;
    int _MIN_Y_MARCO = MIN_Y_MARCO;
};


#endif