#pragma once

class ObstacleManager{
    private:
        static ObstacleManager* _instance;
        ObstacleManager(){}
    public:
        static ObstacleManager* GetInstance(){
            return _instance = (_instance != nullptr) ? _instance : new ObstacleManager();
        }
};