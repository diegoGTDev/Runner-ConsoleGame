#pragma once
#include"../../Profile_System/Profile/Profile.h"
#include "../../General/constantes.h"
class UI{
    public:
    static UI* GetInstance(){
        return _instance = (_instance != nullptr) ? _instance : new UI();
    };
        void drawFrame(int x, int y, int max_x, int max_y);
        int drawMenu();
        void drawGameOver(int score, char* name);
        void drawPlayerName(Profile profile);
        void drawScore(Profile &profile);
        void drawStartMenu();
        void drawHighestScores();
        void cleanAndDrawFrame();
        int drawEndMenu();
        Profile drawProfileRegister();
    
    private:
        UI(){};
        static UI * _instance;
        int _max_x = MAX_X;
        int _max_y = MAX_Y;
        int _max_x_marco = MAX_X_MARCO;
        int _max_y_marco = MAX_Y_MARCO;
};