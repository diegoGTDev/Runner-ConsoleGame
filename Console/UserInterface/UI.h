#pragma once

class UI{
    public:
    static UI* GetInstance(){
        return _instance = (_instance != nullptr) ? _instance : new UI();
    };
        void drawFrame(int x, int y, int max_x, int max_y);
        void drawMenu();
        void drawGameOver();
        void drawPlayerName();
        void drawScore(int score);
    
    private:
        UI(){};
        static UI * _instance;
};