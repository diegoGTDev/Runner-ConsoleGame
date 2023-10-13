#include "UI.h"
#include <iostream>
#include "../functions.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "../../Profile_System/ProfileRepository/ProfileRepository.h"
UI *UI::_instance = nullptr;
void UI::drawFrame(int x, int y, int max_x, int max_y)
{
    max_x -= 8;
    max_y -= 8;

    for (int i = 0; i < max_x; i++)
    {
        imprimir(x, y, 205);
        x++;
    }

    for (int i = 0; i < max_y; i++)
    {
        imprimir(x, y + 1, 186);
        y++;
    }

    for (int i = 0; i < max_x; i++)
    {
        imprimir(x, y, 205);
        x--;
    }
    for (int i = 0; i < max_y; i++)
    {
        imprimir(x, y, 186);
        y--;
    }
    imprimir(4, 2, 201);
    imprimir(max_x + 4, y, 187);
    imprimir(max_x + 4, max_y + 2, 188);
    imprimir(4, max_y + 2, 200);
    // if (x <= 4 && y <= 2){
    //     dibujarMargen(x+1,y+1,max_x-2, max_y-2);
    // }
    return;
}

int UI::drawMenu()
{
start:
    bool isValid = false;
    cleanAndDrawFrame();
    fflush(stdin);
    int option = 0;
    gotoxy(_max_x_marco / 2, _max_y_marco / 2);
    cout << "Runner Game";
    gotoxy(_max_x_marco / 2, _max_y_marco / 2 + 1);
    cout << "[1] Jugar ";
    gotoxy(_max_x_marco / 2, _max_y_marco / 2 + 2);
    cout << "[2] Ver punteos";
    gotoxy(_max_x_marco / 2, _max_y_marco / 2 + 3);
    cout << "[3] Instrucciones";
    gotoxy(_max_x_marco / 2, _max_y_marco / 2 + 4);
    cout << "[4] Salir";
    gotoxy(_max_x_marco / 2, _max_y_marco / 2 + 5);
    cout << "Ingrese una opcion: ";
    option = getch();
    fflush(stdin);

    switch (option)
    {
    case '1':
        cleanAndDrawFrame();
        isValid = true;
        return 0;
    case '2':
        cleanAndDrawFrame();
        drawHighestScores();
        isValid = true;
        break;
    case '3':
        cleanAndDrawFrame();
        gotoxy(_max_x_marco / 2 -20, _max_y_marco / 2);
        cout << "Las instrucciones del juego son las siguientes";
        gotoxy(_max_x_marco / 2 -20, _max_y_marco / 2 + 1);
        cout << "Presione la tecla 'SPACE' para saltar y esquivar los obstaculos.";
        gotoxy(_max_x_marco / 2 -20, _max_y_marco / 2 + 2);
        cout << "Si el jugador choca contra un obstaculo, pierde.";
        gotoxy(_max_x_marco / 2 -20, _max_y_marco / 2 + 3);
        cout << "Presione la tecla 'ESC' para salir del juego.";
        isValid = true;
        break;
    case '4':
        return 1;
    }
    if (isValid)
    {
        gotoxy(_max_x_marco / 2 - 8, _max_y_marco / 2 + 6);
        std::cout << "Presione ENTER para continuar";
        getch();
    }
    goto start;
}

void UI::drawGameOver(int score, char *name)
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    gotoxy(x / 2, y / 2);
    std::cout << "GAME OVER";
    gotoxy(x / 2, y / 2 + 1);
    std::cout << "\033[1;36m" << name << "\033[0m";
    gotoxy(x / 2 - 1, y / 2 + 2);
    cout << " HAS PERDIDO";
    gotoxy(x / 2 - 1, y / 2 + 3);
    std::cout << " Punteo: " << std::to_string(score);
}
int UI::drawEndMenu()
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    gotoxy(x / 2 - 5, y / 2 + 5);
    std::cout << "1. Volver al menu principal";
    gotoxy(x / 2 - 5, y / 2 + 6);
    std::cout << "2. \033[1;31mSalir\033[0m";
    gotoxy(x / 2 - 5, y / 2 + 7);
    std::cout << ">> ";
    switch (getch())
    {
    case '1':
        return 1;
    case '2':
        return 0;
    default:
        drawEndMenu();
    }
}
void UI::drawScore(Profile &profile)
{
    gotoxy(15 + strlen(profile.getName()), 1);
    std::cout << "Score: " << std::to_string(profile.getScore());
}

void UI::drawPlayerName(Profile profile)
{
    gotoxy(4, 1);
    std::cout << "Player: " << profile.getName();
}
Profile UI::drawProfileRegister()
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    Profile profile;
    gotoxy(x / 2 - 5, y / 2);
    std::cout << "REGISTRO DE PERFIL";
    gotoxy(x / 2 - 5, y / 2 + 1);
    char tempName[10];
    std::cout << "Nombre: ";
    std::cin.getline(tempName, 30);
    //*Validation
    if (strlen(tempName) > 10 || strlen(tempName) == 0){
        gotoxy(x / 2 - 5, y / 2 + 2);
        std::cout << "El nombre no puede tener mas de 10 caracteres y no puede estar vacio";
        Sleep(1000);
        cleanAndDrawFrame();
        return drawProfileRegister();
    }
    fflush(stdin);
    profile.setName(tempName);
    ProfileRepository::GetInstance()->addProfile(profile);
    gotoxy(x / 2 - 2, y / 2 + 4);
    std::cout << "\033[1;33mSTART GAME\033[0m";
    getch();
    return profile;
}

void UI::drawHighestScores()
{
    int x = MAX_X_MARCO;
    int y = MAX_Y_MARCO;
    vector<Profile> profiles = ProfileRepository::GetInstance()->getProfiles();
    gotoxy(x / 2 - 2, y / 2 - 1);
    cout << "PUNTEOS MAS ALTOS";
    if (profiles.size() == 0)
    {
        gotoxy(x / 2 - 2, y / 2);
        std::cout << "No hay puntuaciones";
        gotoxy(x / 2 - 5, y / 2 + 1);
        std::cout << "Presione ENTER para continuar";
        getch();
        return;
    }
    for (int i = 0; i < profiles.size(); i++)
    {
        for (int j = 0; j < profiles.size() - 1; j++)
        {
            if (profiles[j].getScore() < profiles[j + 1].getScore())
            {
                Profile temp = profiles[j];
                profiles[j] = profiles[j + 1];
                profiles[j + 1] = temp;
            }
        }
    }
    gotoxy(x / 2 - 10 + 2, y / 2);
    std::cout << "\033[1;33mNombres\033[0m";
    gotoxy(x / 2 + 10 + 2, y / 2);
    std::cout << "\033[1;32mPunteos\033[0m";
    for (int i = 0; i < profiles.size(); i++)
    {

        gotoxy(x / 2 - 10 + 2, y / 2 + i + 1);
        std::cout << profiles[i].getName();
        gotoxy(x / 2 + 10 + 2, y / 2 + i + 1);
        std::cout << profiles[i].getScore();
        if (i == 5)
        {
            break;
        }
    }
}

void UI::cleanAndDrawFrame()
{
    system("cls");
    drawFrame(4, 2, _max_x, _max_y);
}
