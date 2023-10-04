#pragma once

/// ObstacleManager class is in charge about the obstacles in the game, it will create, update and delete them.
class ObstacleManager{
    private:
        static ObstacleManager* _instance;
        ObstacleManager(){}
    public:
        static ObstacleManager* GetInstance(){
            return _instance = (_instance != nullptr) ? _instance : new ObstacleManager();
        }
};