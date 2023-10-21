#include "CloudManager.h"
#include "windows.h"
#include"../Console/functions.h"
#include<iostream>
using namespace std;
CloudManager* CloudManager::m_instance = nullptr;
void CloudManager::Init()
{
    _max_x_marco = MAX_X_MARCO;
    _max_y_marco = MAX_Y_MARCO;
    _min_x_marco = MIN_X_MARCO;
    _min_y_marco = MIN_Y_MARCO;

}

void CloudManager::Update()
{
    int i = 0;
    while (i < _collection.size())
    {
        _collection[i]->Update();
        i++;
    }
}

void CloudManager::Render()
{
    int i = 0;
    while (i < _collection.size())
    {
        _collection[i]->Render();
        i++;
    }
}

void CloudManager::Release()
{
    int i = 0;
    while (i < _collection.size())
    {
        _collection[i]->Release();
        delete _collection[i];
        i++;
    }
    _collection.clear();
}

void CloudManager::HandleEvents()
{
    int i =0;
    while (i < _collection.size())
    {
        _collection[i]->HandleEvents();
        i++;
    }
}

void CloudManager::CreateCloud(int x, int y)
{
    Cloud* cloud = new Cloud(x, y);
    _collection.push_back(cloud);
}

void CloudManager::DeleteCloud(int index)
{
    delete _collection[index];
    _collection.erase(_collection.begin() + index);
}

void CloudManager::CloudGenerator()
{
    int x = _max_x_marco-9;
    int y = _min_y_marco;
    int x_posibble_values[3] = {x-40, x-70, x-60};
    int i = 0;
    while (i < determCloudAmount()){
        if (i == 0){
            CreateCloud(x, y);
            CreateCloud(x_posibble_values[i], y);
        }
        else{
            CreateCloud(x_posibble_values[i], y+5*i);
            CreateCloud(x-15*i, y+5*i);
        }
        i++;
    }
}

int CloudManager::determCloudAmount()
{
    if (_max_y_marco >= 22 && _max_y_marco <= 29)
    {
        return 1;
    }
    else if (_max_y_marco >= 29 && _max_y_marco <= 33)
    {
        return 2;
    }
    else if (_max_y_marco >= 33){

        return 3;
    }
}
