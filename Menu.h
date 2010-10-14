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
    static char *leeString(FILE *flujo, char *punteroString);
    static int TAM_DEFAULT;
    static int TAM_REDIM;
    int menuOrden();
    string intAString(int i);
    string getNrosTelVend(int pos);
    string getNrosTelClient(int pos);
    bool verificarOpcion(string entrada, int nroOpciones);

private:
    void menuAcceso();
    void menuAdmin();
    void menuVend();
    void menuListClientes();
    void menuListVendedores();
    void menuListVentas();
    void menuModCliente();
    void menuModVend();
    void menuModLibro();
    bool compruebaUsuario(string user, string pass);
    int encuentraUsuario(string nombre);
    int encuentraCliente(string nombre);
    int encuentraLibro(string nombre);
    AdminListas *adminListas;

};

#endif // MENU_H
