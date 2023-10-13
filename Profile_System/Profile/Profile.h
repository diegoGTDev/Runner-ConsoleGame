#pragma once
#include<string.h>
class Profile{
    private:
        char name[10];
        int score = 0;
    public:
        Profile(){}
        inline char* getName() {return name;};
        inline int getScore() {return score;};
        inline void setName(char* name) {strcpy(this->name, name);};
        inline void setScore(int score) {this->score = score;};
};