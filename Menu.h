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
    static int NRO_OP_ACCESO_ORDEN;
    static int NRO_OP_ADMIN_VEND_LISTVEND;
    static int NRO_OP_CRITORD;
    static int NRO_OP_LISTVEND_MODVEND;
    static int NRO_OP_ADMIN;
    static int NRO_OP_VEND;
    int menuOrden();
    string intAString(int i);
    bool verificarOpcion(string entrada, int nroOpciones);

private:
    void menuAcceso();
    void menuAdmin();
    void menuVend();
    void menuListVendedores();
    void menuListVentas();
    void modificarVend();
    bool compruebaUsuario( string user, string pass);
    AdminListas *adminListas;
    string userStr, passStr; // SI NO ES NECESARIO, ESTAN VOLVERAN A SER LOCALES EN LOS METODOS

};

#endif // MENU_H
