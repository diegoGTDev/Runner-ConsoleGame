#include "ObstacleManager.h"
#include "../GameObjects/Obstacle/IObstacle.h"
#include "../GameObjects/roca/roca.h"
#include "../GameObjects/bird/bird.h"
#include <iostream>
#include <windows.h>
#include <random>
#include <typeinfo>
ObstacleManager *ObstacleManager::_instance = nullptr;
std::vector<IObstacle *> ObstacleManager::obstacles;
int ObstacleManager::_max_x_marco = MAX_X_MARCO;
int ObstacleManager::_max_y_marco = MAX_Y_MARCO;
int ObstacleManager::_gap[22] = {19, 23, 32, 21, 23, 40, 31, 32, 77, 22, 43, 50, 25, 16, 30, 20, 35, 40, 21, 64, 17, 33};
int ObstacleManager::_gapIndex = 0;
int ObstacleManager::_max_birds = 0;
int ObstacleManager::_max_rocks = 0;
int ObstacleManager::_rocks_counter = 0;
int ObstacleManager::_birds_counter = 0;
int ObstacleManager::_last_obs_x_rock = 0;
int ObstacleManager::_last_obs_x_bird = 0;
double ObstacleManager::_currentTime = 0;
int ObstacleManager::_limitOfObstacles = 0;

/**
 * Creates a new rock obstacle at the specified position and adds it to the list of obstacles.
 * Increment rocks counter by 1.
 * @param x The x-coordinate of the obstacle.
 * @param y The y-coordinate of the obstacle.
 */
void ObstacleManager::CreateRock(int x, int y)
{
    ROCA *obs = new ROCA(x, y);
    obstacles.push_back(obs);
    _rocks_counter++;
}
/**
 * Creates a new Bird obstacle at the specified position and adds it to the list of obstacles.
 * Increments birds counter by 1.
 * @param x The x-coordinate of the obstacle's position.
 * @param y The y-coordinate of the obstacle's position.
 */
void ObstacleManager::CreateBird(int x, int y)
{
    Bird *obs = new Bird(x, y);
    obstacles.push_back(obs);
    _birds_counter++;
}
/**
 * @brief Updates all obstacles in the manager.
 *
 * @param elapsedSeconds The elapsed time since the last update.
 */
void ObstacleManager::Update(double elapsedSeconds)
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Update(elapsedSeconds);
    }
}

/**
 * Renders all obstacles in the ObstacleManager.
 * Calls the Render() function for each obstacle in the obstacles vector.
 */
void ObstacleManager::Render()
{
    gotoxy(70, 1);
    std::cout << "last: " << _last_obs_x_rock << "  max: ";
    std::cout << _max_x_marco << " size: " << obstacles.size() << "  ";
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Render();
    }
}

/**
 * Initializes the ObstacleManager object by setting the maximum x and y coordinates of the game screen.
 * Determines the maximum number of birds, rocks, and total obstacles based on the maximum x coordinate.
 * If the maximum x coordinate is greater than or equal to 130, the maximum number of birds is 3, the maximum number of rocks is 6, and the limit of obstacles is 9.
 * Otherwise, the maximum number of rocks is 4, the maximum number of birds is 2, and the limit of obstacles is 6.
 */
void ObstacleManager::Init()
{
    _max_x_marco = MAX_X_MARCO;
    _max_y_marco = MAX_Y_MARCO;

    if (_max_x_marco >= 130)
    {
        _max_birds = 3;
        _max_rocks = 6;
        _limitOfObstacles = 9;
    }
    else
    {
        _max_rocks = 4;
        _max_birds = 2;
        _limitOfObstacles = 6;
    }
}

/**
 * @brief Releases all obstacles and clears the obstacles vector.
 * Also resets the birds and rocks counters.
 */
void ObstacleManager::Release()
{
    gotoxy(70, 5);
    std::cout << "Obstacles: " << obstacles.size();
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->Release();
        if (obstacles[i]->getId() == 1)
        {
            _birds_counter--;
        }
        else
        {
            _rocks_counter--;
        }
        delete obstacles[i];
    }
    _birds_counter = 0;
    _rocks_counter = 0;
    obstacles.clear();
}

/**
 * @brief Deletes an obstacle from the obstacles vector and frees its memory.
 * 
 * @param index The index of the obstacle to be deleted.
 */
void ObstacleManager::DeleteObstacle(int index)
{
    delete obstacles[index];
    obstacles.erase(obstacles.begin() + index);
}

inline void ObstacleManager::setCurrentTime(int currentTime)
{
    _currentTime = currentTime;
}

void ObstacleManager::DeleteAllObstacles()
{
    obstacles.clear();
}

/**
 * @brief Handles events for all obstacles in the ObstacleManager.
 * 
 * This function iterates through all obstacles in the ObstacleManager and calls their HandleEvents() function.
 * If an obstacle is out of the screen limits, it is released and removed from the ObstacleManager.
 * Additionally, it updates the _last_obs_x_rock and _last_obs_x_bird variables with the x position of the last rock and bird obstacles, respectively.
 * 
 * @return void
 */
void ObstacleManager::HandleEvents()
{

    gotoxy(30, 1);
    if (obstacles.size() != 0){

    std::cout<<"firstX: "<<obstacles[0]->getX()<<"  ";
    }
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
            if (obstacles[i]->getId() == 1)
            {
                _birds_counter--;
            }
            else
            {
                _rocks_counter--;
            }
            DeleteObstacle(i);
        }
    }
    if (obstacles.size() != 0)
    {

        // Crear una busqueda dentro de obstacles del ultimo obstaculo tipo ROCA
        //  y asignarle el valor de su posicion en x a _last_obs_x_rock

        for (int i = 0; i < obstacles.size(); i++)
        {
            if (obstacles[i]->getId() == 0)
            {

                _last_obs_x_rock = obstacles[i]->getX();
            }
            else
            {
                _last_obs_x_bird = obstacles[i]->getX();
            }
        }
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

void ObstacleManager::ObstacleGenerator(double elapsedSeconds)
{
    bool isCreated = false;
    gotoxy(50, 1);
    // std::cout << "Gap: " << _gap[_gapIndex] << "  ";
    std::cout << "birds: " << _birds_counter << "  ";
    gotoxy(50, 2);
    std::cout << "rocks: " << _rocks_counter << "  ";
    _currentTime += elapsedSeconds;
    gotoxy(50, 0);
    std::cout << "time: " << int(_currentTime) << "  ";
    int x = _max_x_marco - 1;
    if (obstacles.size() != _limitOfObstacles)
    {

        if (_rocks_counter == 0)
        {

            CreateRock(x - 2, _max_y_marco);
            isCreated = true;
        }

        if (_birds_counter == 0)
        {
            if ((int(_currentTime) >= 15 && (int(_currentTime) % 5) == 0) && _birds_counter <= _max_birds)
            {
                CreateBird(x - 5, _max_y_marco - 5);
                isCreated = true;
            }
        }
        if (obstacles.size() >= 1)
        {

            if ((int(_currentTime) % 5 == 0) && (_birds_counter <= _max_birds) && (_max_x_marco - _last_obs_x_bird >= _gap[_gapIndex]) && (_max_x_marco - _last_obs_x_bird <= _gap[_gapIndex] + 2))
            {
                CreateBird(x - 5, _max_y_marco - 5);
                isCreated = true;
            }
            else if (_max_x_marco - _last_obs_x_rock >= _gap[_gapIndex] && _max_x_marco - _last_obs_x_rock <= _gap[_gapIndex] + 2 && _rocks_counter < _max_rocks)
            {

                // Sleep(1000);

                CreateRock(x - 2, _max_y_marco);
                isCreated = true;
            }
        }
        if (isCreated)
        {
            newGap();
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
