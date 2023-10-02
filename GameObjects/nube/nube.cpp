#include "../../General/constantes.h"
#include "nube.h"
#include<iostream>
void NUBE::Render(){
    for (int i = 0; i < 4; i++) {
        gotoxy(x,y+i);
        std::cout<<"             ";
    }
     char* cloud[4] ={"   __   _",
                        " _(  )_( )_",
                        "(_   _    _)",
                        "  (_) (__)"};
    for (int i = 0; i < 4; i++) {
        gotoxy(x, y+i);
        std::cout<<cloud[i];
    }
}

void NUBE::HandleEvents()
{
    estaEnLimite();
}

void NUBE::Update()
{
    this->x--;
}


void NUBE::estaEnLimite(){
    const int limite = MIN_X_MARCO;
    if (x >=limite && x <= limite){
        for (int i = 0; i < 4; i++) {
            gotoxy(x,y+i);
            std::cout<<"            ";
        }
        if (x== limite){

            x = inicialX;
        }
    }
}
