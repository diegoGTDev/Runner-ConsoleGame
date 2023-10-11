#pragma once

/// ObstacleManager class is in charge about the obstacles in the game, it will create, update and delete them.
#include <vector>
#include "../GameObjects/Obstacle/IObstacle.h"
#include<stdlib.h>
#include "../General/constantes.h"
class ObstacleManager{
    private:
        static ObstacleManager* _instance;
        ObstacleManager(){}
        static std::vector<IObstacle*> obstacles;
        static int _gap[22];
        static int _gapIndex;
        static int _last_obs_x_rock;
        static int _last_obs_x_bird;
        static int _max_x_marco;
        static int _max_y_marco;
        static int _max_birds;
        static int _max_rocks;
        static int _birds_counter;
        static int _rocks_counter;
        static double _currentTime;
        static int _limitOfObstacles;
    public:
        static ObstacleManager* GetInstance(){
            return _instance = (_instance != nullptr) ? _instance : new ObstacleManager();
        }
        static void CreateRock(int x, int y);
        static void CreateBird(int x, int y);
        static void Init();
        static void Update(double elapsedSeconds);
        static void Render();
        static void Release();
        static  void DeleteObstacle(int index);
        static void setCurrentTime(int currentTime);
        static double getCurrentTime();
        static void DeleteAllObstacles();
        static void HandleEvents();
        static std::vector<IObstacle*> GetObstacles();
        static void newGap();
        static void ObstacleGenerator(double elapsedSeconds);
};