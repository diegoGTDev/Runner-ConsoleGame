#ifndef CLOUDMANAGER_H
#define CLOUDMANAGER_H

#pragma once
#include<vector>
#include"../General/constantes.h"
#include"../GameObjects\nube\nube.h"
class CloudManager
{
public:
    static CloudManager* GetInstance(){
        if(m_instance == nullptr){
            m_instance = new CloudManager();
        }
        return m_instance;
    };
    void Init();
    void Update();
    void Render();
    void Release();
    void HandleEvents();
    void CreateCloud(int x,int y);
    void DeleteCloud(int index);
    void CloudGenerator();
    int determCloudAmount();
    

private:
    static CloudManager* m_instance;
    CloudManager(){};
    std::vector<Cloud*> _collection;
    int _max_x_marco;
    int _max_y_marco;
    int _min_x_marco;
    int _min_y_marco;
};

#endif