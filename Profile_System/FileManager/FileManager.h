#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include <typeinfo>
#include<vector>
#include"../Profile/Profile.h"
using namespace std;
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

class FileManager
{
private:
    char nombre_archivo[50] = "profiles.dat";
    FILE *archivo;
    FileManager(){}; 
    static FileManager* m_instance;


public:
    static FileManager* GetInstance(){
        return m_instance = (m_instance != nullptr) ? m_instance : new FileManager();
    }
    void escribir(Profile registro);
    void eliminar(Profile registro);
    void modificarP(Profile registro);
    void modificarCFG(int registro);
    vector<Profile> leerTodo();
    Profile leer();
    Profile obtenerObjeto(char name[11]);
    int existeObjeto(char name[30]);
    bool existeArchivo();
    FILE *getArchivo();
    void setNombreArchivo(char nombre_archivo[50]);
    bool finalArchivo();
    void cerrar();
};

#endif