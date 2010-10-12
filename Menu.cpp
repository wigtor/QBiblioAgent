#include "Menu.h"

Menu::Menu( AdminListas *adminListas) {
    this->adminListas = adminListas;
}

void Menu::ejecutar() {
    menuAcceso();
}

void Menu::menuAcceso() {
    int opcionAcceso = 0;
    string user, pass;

    while (opcionAcceso < 1 || opcionAcceso > 3) {
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
        cin >> opcionAcceso;

        // Si la opcion es invalida:
        // cout << "Opcion invalida. Intente de nuevo por favor." << endl;

        while (opcionAcceso == 1) {
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

        while (opcionAcceso == 2) {
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


