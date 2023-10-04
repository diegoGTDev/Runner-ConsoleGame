#ifndef ENGINE_H

#define ENGINE_H
#include"../General/constantes.h"
#include"../Profile_System/Profile/Profile.h"
#define CONSOLE_WIDTH MAX_X
#define CONSOLE_HEIGHT MAX_Y
#define TIME 15
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
    //---
    const int _MAX_X = MAX_X;
    const int _MAX_Y = MAX_Y;
    const int _MAX_X_MARCO = MAX_X_MARCO;
    const int _MAX_Y_MARCO = MAX_Y_MARCO;
    const int _MIN_X_MARCO = MIN_X_MARCO;
    const int _MIN_Y_MARCO = MIN_Y_MARCO;
};


#endif