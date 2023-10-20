#include "../../General/constantes.h"
#include "nube.h"
#include <iostream>
void Cloud::Render()
{
    Release();
    char *cloud[4] = {"\033[1;36m   __   _",
                      " _(  )_( )_",
                      "(_   _    _)",
                      "  (_) (__)\033[0m"};
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        std::cout << cloud[i];
    }
}

void Cloud::HandleEvents()
{
    estaEnLimite();
}

void Cloud::Update()
{
    this->x--;
}

void Cloud::Release()
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(x, y + i);
        std::cout << "             ";
    }
}

void Cloud::estaEnLimite()
{
    const int limite = MIN_X_MARCO;
    if (x >= limite && x <= limite)
    {
        Release();
        if (x == limite)
        {

            x = inicialX;
        }
    }
}
