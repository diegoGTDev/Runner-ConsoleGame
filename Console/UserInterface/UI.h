#pragma once
#include"../../Profile_System/Profile/Profile.h"
class UI{
    public:
    static UI* GetInstance(){
        return _instance = (_instance != nullptr) ? _instance : new UI();
    };
        void drawFrame(int x, int y, int max_x, int max_y);
        void drawMenu();
        void drawGameOver(int score, char* name);
        void drawPlayerName(Profile profile);
        void drawScore(int score);
        void drawStartMenu();
        void drawHighestScores();
        Profile drawProfileRegister();
    
    private:
        UI(){};
        static UI * _instance;
};