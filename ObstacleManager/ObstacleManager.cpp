#include "ObstacleManager.h"
#include "../GameObjects/Obstacle/IObstacle.h"
#include "../GameObjects/roca/roca.h"
#include <iostream>
#include <windows.h>
#include <random>
ObstacleManager *ObstacleManager::_instance = nullptr;
std::vector<IObstacle *> ObstacleManager::obstacles;
int ObstacleManager::_max_x_marco = MAX_X_MARCO;
int ObstacleManager::_max_y_marco = MAX_Y_MARCO;
int ObstacleManager::_gap[20] = {15, 23, 32, 21, 20, 40, 31, 32, 77, 22, 43, 50, 25, 16, 30, 20, 35, 40, 20};
int ObstacleManager::_gapIndex = 0;
int ObstacleManager::_last_obs_x = 0;
void ObstacleManager::CreateRock(int x, int y)
{
    ROCA *obs = new ROCA(x, y);
    obstacles.push_back(obs);
}

void ObstacleManager::Update(double elapsedSeconds)
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Update(elapsedSeconds);
    }
}

void ObstacleManager::Render()
{
    gotoxy(70, 1);
    std::cout << "last: " << _last_obs_x << "  max: ";
    std::cout << _max_x_marco << " size: " << obstacles.size() << "  ";
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Render();
    }
}

void ObstacleManager::Release()
{
    gotoxy(70, 5);
    std::cout << "Obstacles: " << obstacles.size();
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Release();
        delete obstacles[i];
    }
    obstacles.clear();
}

void ObstacleManager::DeleteObstacle(int index)
{
    delete obstacles[index];
    obstacles.erase(obstacles.begin() + index);
}

void ObstacleManager::DeleteAllObstacles()
{
    obstacles.clear();
}

void ObstacleManager::HandleEvents()
{
    if (obstacles.size() == 0)
    {
        return;
    }
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->HandleEvents();
        if (obstacles[i]->isInLimit())
        {
            obstacles[i]->Release();
            DeleteObstacle(i);
        }
    }
    if (obstacles.size() != 0)
    {
        _last_obs_x = obstacles.back()->getX();
    }
}

std::vector<IObstacle *> ObstacleManager::GetObstacles()
{
    return obstacles;
}

void ObstacleManager::SetGap(int gap)
{
}

int ObstacleManager::GetGap()
{
}

void ObstacleManager::ObstacleGenerator()
{

    int x = _max_x_marco - 1;

    if (obstacles.size() != 4)
    {
        if (obstacles.size() == 0)
        {
            CreateRock(x - 2, _max_y_marco);
            newGap();
        }
        else
        {

            // Give a new value of gap
            // We get the location in X of the last obstacle.
            // gotoxy(70, 1);
            // std::cout << "last: " << _last_obs_x << "  max: ";
            // std::cout << _max_x_marco << " size: " << obstacles.size() << "  ";
            // Sleep(1000);
            //  The operation _max_x_marco - lastX will give us the distance between the last obstacle and the end of the screen.
            //  We check into the if if this distance is equal to gap, if it is, we create a new obstacle.

            if (_max_x_marco - _last_obs_x >= _gap[_gapIndex] && _max_x_marco - _last_obs_x <= _gap[_gapIndex] + 2)
            {
                newGap();
                // Sleep(1000);
                gotoxy(50, 1);
                std::cout << "Gap: " << _gap[_gapIndex] << " ";
                //_gap = getRandomNumber(15, 25);
                CreateRock(x - 2, _max_y_marco);
            }
        }
    }
}

void ObstacleManager::newGap()
{
    // Sleep(1000);
    if (_gapIndex >= sizeof(_gap) / sizeof(_gap[0]) - 1)
    {
        _gapIndex = 0;
        // Sleep(1000);
    }
    else
    {
        // Sleep(1000);
        _gapIndex += 1;
    }
}
