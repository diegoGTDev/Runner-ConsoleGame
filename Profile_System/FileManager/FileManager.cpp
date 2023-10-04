#include"FileManager.h"
#include<vector>
#include"../Profile/Profile.h"
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include<vector>
FileManager* FileManager::m_instance = nullptr;
vector<Profile> FileManager::leerTodo(){
    vector<Profile> result;
    archivo = fopen(nombre_archivo, "rb");
    Profile registro;

    while(fread(&registro, sizeof(Profile), 1, archivo))
    {
        result.push_back(registro);
    }
    cerrar();
    return result;
}
Profile FileManager::obtenerObjeto(char name[30]){
    archivo = fopen(nombre_archivo, "rb");
    Profile registro;
    while(fread(&registro, sizeof(Profile), 1, archivo))
    {
        if(strcmp(registro.getName(), name)){
            break;
        }
    }
    cerrar();
    return registro;
}
bool FileManager::existeArchivo()
{
    archivo = fopen(nombre_archivo, "r+b");
    if (archivo == nullptr)
    {
        cerrar();
        return false;
    }
    cerrar();
    return true;
}

int FileManager::existeObjeto(char name[30])
{
    archivo = fopen(nombre_archivo, "rb");
    Profile registro;
    while(fread(&registro, sizeof(Profile), 1, archivo))
    {
        if(strcmp(registro.getName(), name) == 0){
            cerrar();
            return 1;

        }
    }
    cerrar();
    return 0;
}

FILE *FileManager::getArchivo()
{
    return archivo;
}

bool FileManager::finalArchivo()
{
    return feof(archivo);
}

void FileManager::escribir(Profile registro)
{
    if (!(existeArchivo()))
    {
        archivo = fopen(this->nombre_archivo, "w+b");
        fwrite(&registro, sizeof(registro), 1, archivo);
        cerrar();
    }
    else
    {
        archivo = fopen(this->nombre_archivo, "a+b");
        fwrite(&registro, sizeof(registro), 1, archivo);
        cerrar();
    }
}

void FileManager::modificarP(Profile registro)
{
    archivo = fopen(nombre_archivo, "r+b");

    Profile registroTemp;
    while (fread(&registroTemp, sizeof(Profile), 1, archivo))
    {
        if (strcmp(registroTemp.getName(), registro.getName()) == 0)
        {
            // Modificar los campos del registro
            registroTemp = registro;
            fseek(archivo, -sizeof(Profile), SEEK_CUR);
            fwrite(&registroTemp, sizeof(Profile), 1, archivo);
            break;
        }
    }

    cerrar();
}

void FileManager::modificarCFG(int newID){

   int id = newID;
    archivo = fopen(nombre_archivo, "r+b");
    fwrite(&id, sizeof(int), 1, archivo);
    cerrar();

}

Profile FileManager::leer()
{
    archivo = fopen(nombre_archivo, "rb");
    Profile result;
    fread(&result, sizeof(Profile), 1, archivo);
    cerrar();
    return result;
}

void FileManager::setNombreArchivo(char nombre_archivo[50])
{
    strcpy(this->nombre_archivo, nombre_archivo);
    strcat(this->nombre_archivo, ".dat");
}

void FileManager::eliminar(Profile registro)
{
    archivo = fopen(nombre_archivo, "r+b");
    FILE *archivoTemp;
    char *tempArch = "temp.dat";
    archivoTemp = fopen(tempArch, "w+b");
    Profile registroTemp;
    while (fread(&registroTemp, sizeof(Profile), 1, archivo))
    {
        if (!strcmp(registroTemp.getName(),   registro.getName()))
        {
            fwrite(&registroTemp, sizeof(Profile), 1, archivoTemp);
        }
    }
    cerrar();
    fclose(archivoTemp);
    remove(nombre_archivo);
    rename(tempArch, nombre_archivo);
}

void FileManager::cerrar()
{
    fclose(archivo);
}
