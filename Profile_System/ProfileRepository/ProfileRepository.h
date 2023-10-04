#pragma once
#include<vector>
#include"../Profile/Profile.h"
#include"../FileManager/FileManager.h"
class ProfileRepository{
    public:
        static ProfileRepository* GetInstance(){
            _collection = FileManager::GetInstance()->leerTodo();
            return _instance = (_instance != nullptr) ? _instance : new ProfileRepository();
        }
        static void addProfile(Profile profile);
        static vector<Profile> getProfiles();
        static Profile getProfile(char name[30]);
        static void deleteProfile(Profile profile);
        static vector<Profile> _collection;
        static void modifyProfile(Profile profile);
    private:
        //static vector<Profile> _collection;
        ProfileRepository(){}
        static ProfileRepository* _instance;
};