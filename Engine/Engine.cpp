#ifndef ENGINE_H

#define ENGINE_H

//Create a singleton for engine
class Engine
{
public:
    static Engine* GetInstance(){
        return _instance = (_instance == nullptr ? new Engine() : _instance);
    };
    void Init();
    void Update();
    void Release();
    void HandleEvents();
    inline bool isRunning(){ return _isRunning; };
private:
    Engine(){};
    static Engine *_instance;
    bool _isRunning;
    static Engine* m_instance;
};


#endif