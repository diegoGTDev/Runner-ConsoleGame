#include"ProfileRepository.h"
ProfileRepository* ProfileRepository::_instance = nullptr;
vector<Profile> ProfileRepository::_collection;
void ProfileRepository::addProfile(Profile profile){
    if (FileManager::GetInstance()->existeObjeto(profile.getName())){
        modifyProfile(profile);
        for (int i = 0; i < _collection.size(); i++){
            if (strcmp(_collection[i].getName(), profile.getName()) == 0){
                _collection[i] = profile;
            }
        }
        return;
    }
    return FileManager::GetInstance()->escribir(profile); _collection.push_back(profile);
}
vector<Profile> ProfileRepository::getProfiles(){
    return ProfileRepository::GetInstance()->_collection; 
}
Profile ProfileRepository::getProfile(char name[10]){
    return FileManager::GetInstance()->obtenerObjeto(name);
}
void ProfileRepository::deleteProfile(Profile profile){
    FileManager::GetInstance()->eliminar(profile);
}
void ProfileRepository::modifyProfile(Profile profile){
    FileManager::GetInstance()->modificarP(profile);
    _collection = FileManager::GetInstance()->leerTodo();
}