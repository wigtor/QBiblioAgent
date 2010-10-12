#ifndef MENU_H
#define MENU_H

#include <string>
#include <stdio.h>
#include <string.h>
#include "AdminListas.h"

class Menu
{
public:
    Menu(AdminListas *adminListas);
    void ejecutar();

    char *leeString(FILE *flujo, char *punteroString);
    static int TAM_DEFAULT;
    static int TAM_REDIM;

private:
    void menuAcceso();
    void menuAdmin();
    void menuVend();
    AdminListas *adminListas;
};

#endif // MENU_H
