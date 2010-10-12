#ifndef MENU_H
#define MENU_H

#include <string>
#include "AdminListas.h"

class Menu
{
public:
    Menu(AdminListas *adminListas);
    void ejecutar();

private:
    void menuAcceso();
    void menuAdmin();
    void menuVend();
    AdminListas *adminListas;

};

#endif // MENU_H
