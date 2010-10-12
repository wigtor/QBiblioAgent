#include "Menu.h"

Menu::Menu( AdminListas *adminListas) {
    this->adminListas = adminListas;
}

void Menu::ejecutar() {
    menuAcceso();
}

void Menu::menuAcceso() {
    char *opcionAcceso;
    string opcionAccesoStr = "0";
    string user, pass;

    while (opcionAccesoStr ==  "0") {
        cout << "QBiblioAgent" << endl;
        cout << "============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Ingresar como administrador" << endl;
        cout << "2. Ingresar como vendedor" << endl;
        cout << "3. Salir" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionAcceso = leeString(stdin, opcionAcceso);
        opcionAccesoStr = *(new string(opcionAcceso));

        // Si la opcion es invalida:
        // cout << "Opcion invalida. Intente de nuevo por favor." << endl;

        while (opcionAccesoStr == "1") {
            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            cin >> user;

            cout << "Ingrese su contrasea:" << endl;
            cout << ">> ";
            cin >> pass;

            // Verificar usuario

            // Si el usuario existe:
            // opcionAcceso = 0;
            // menuAdmin();

            // Si no:
            // cout << "Usuario o contrasea incorrectos. Intente de nuevo por favor." << endl;
        }

        while (opcionAccesoStr == "2") {
            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            cin >> user;

            cout << "Ingrese su contrasea:" << endl;
            cout << ">> ";
            cin >> pass;

            // Verificar usuario

            // Si el usuario existe:
            // opcionAcceso = 0;
            // menuVend();

            // Si no:
            // cout << "Usuario o contrasea incorrectos. Intente de nuevo por favor." << endl;
        }

        cout << "" << endl;
    }
}

void Menu::menuAdmin() {
    int opcionAdmin = 0;

    while (opcionAdmin < 1 || opcionAdmin > 7) {
        cout << "Administrador" << endl;
        cout << "=============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Listar vendedores" << endl;
        cout << "2. Ver vendedor" << endl;
        cout << "3. Ingresar vendedor" << endl;
        cout << "4. Modificar vendedor" << endl;
        cout << "5. Eliminar vendedor" << endl;
        cout << "6. Ver ventas" << endl;
        cout << "7. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        cin >> opcionAdmin;

        while (opcionAdmin == 1) {
            // Mostrar lista de vendedores
            // opcionAdmin = 0;
        }

        while (opcionAdmin == 2) {
            string nombre;

            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            cin >> nombre;

            // Si el vendedor existe:
            // opcionAdmin = 0;

            // Si no:
            // cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
        }

        while (opcionAdmin == 3) {

        }

        while (opcionAdmin == 4) {

        }

        while (opcionAdmin == 5) {

        }

        while (opcionAdmin == 6) {

        }
    }
}

void Menu::menuVend() {
    int opcionVend = 0;

    while (opcionVend < 1 || opcionVend > 7) {
        cout << "Administrador" << endl;
        cout << "=============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Listar clientes" << endl;
        cout << "2. Ver cliente" << endl;
        cout << "3. Ingresar cliente" << endl;
        cout << "4. Modificar cliente" << endl;
        cout << "5. Ingresar libro" << endl;
        cout << "6. Realizar una venta" << endl;
        cout << "7. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        cin >> opcionVend;

        while (opcionVend == 1) {
            // Mostrar lista de clientes
            // opcionVend = 0;
        }

        while (opcionVend == 2) {

        }
    }
}


/**
* Esta función se encarga de leer caracteres desde un flujo y guardarlo en un vector dinámico de caracteres
* Fue realizada pensando en que el flujo puede ser el teclado o un archivo de texto
* Guarda en el vector dinámico todos los caracteres hasta que encuentra un salto de linea o el final del flujo
* Fue realizada para no tener problemas de desbordamiento de buffer, ya que redimensiona el vector dinámico si es necesario
* @param flujo es el flujo de datos de donde se quiere leer caracteres
* @param punteroString es el puntero al vector de caracteres donde se quiere guardar los caracteres leidos
* @return punteroString es puntero al vector dinámico despues de haber guardadó caracteres en él
*/
char *Menu::leeString(FILE *flujo, char *punteroString)
{	int i = 0, espacioLibre = TAM_DEFAULT; //representa los caracteres disponibles para poner en el string
        punteroString = (char *)malloc((TAM_DEFAULT+1)*sizeof(char));
        if (flujo == stdin)
            fflush(stdin);
        punteroString[0] = '\0';
        do
        {	if (espacioLibre <= 2) //si falta espacio en el string, lo redimensiono
                {	punteroString = (char *)realloc(punteroString, (strlen(punteroString) + TAM_REDIM) * sizeof(char));
                        espacioLibre+= TAM_REDIM;
                }
                punteroString[i] = getc(flujo);
                i++;
                espacioLibre--;
        }
        while ((punteroString[i-1] != '\n') && (punteroString[i-1] != EOF));
        punteroString[i-1] = '\0'; //cambio el ultimo \n por un \0
        return punteroString;
}

int Menu::TAM_DEFAULT = 10;
int Menu::TAM_REDIM = 5;

