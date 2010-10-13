#include "Menu.h"

int Menu::NRO_OP_ACCESO_ORDEN = 3;
int Menu::NRO_OP_ADMIN_VEND_LISTVEND = 7;
int Menu::NRO_OP_CRITORD = 2;
int Menu::NRO_OP_LISTVEND_MODVEND = 6;
int Menu::NRO_OP_ADMIN = 10;
int Menu::NRO_OP_VEND = 10;

Menu::Menu(AdminListas *adminListas) {
    this->adminListas = adminListas;
}

void Menu::ejecutar() {
    menuAcceso();
}

string Menu::intAString(int i) {
    stringstream strStream;
    string s;
    strStream << i;
    s = strStream.str();
    return s;
}

bool Menu::verificarOpcion(string entrada, int nroOpciones) {
    bool valido = true;
    for (int i = 0; i <= nroOpciones; i++) {
        if (entrada.compare(intAString(i)) == 0) {
            valido = false;
            break;
        }
    }
    return valido;
}

void Menu::menuAcceso() {
    char *opcionAcceso, *user, *pass;
    int contPass;
    string opcionAccesoStr = "0";

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
        cout << "" << endl;

        if (this->verificarOpcion(opcionAcceso, Menu::NRO_OP_ACCESO_ORDEN) == false) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
            opcionAccesoStr = "0"; //vuelvo al comienzo del menu
        }

        while (opcionAccesoStr == "1") {
            //Esto hace que despues de 3 intentos de la contraseña se vuelva al menu principal
            if (contPass++ == 3){
                opcionAccesoStr = "0";
                continue;
            }
            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            user = leeString(stdin, user);
            this->userStr = *(new string(user));
            cout << "" << endl;

            cout << "Ingrese su contrasena:" << endl;
            cout << ">> ";
            pass = leeString(stdin, pass);
            this->passStr = *(new string(pass));
            cout << "" << endl;

            // Verificar usuario
            if ((compruebaUsuario(user, pass)) == true) {
                opcionAccesoStr = "0";
                menuVend();
                contPass = 0;
            }
            else {
                cout << "Usuario o contrasena incorrectos. Intente de nuevo por favor." << endl;
                cout << endl;
            }
        }

        while (opcionAccesoStr == "2") {
            //Esto hace que despues de 3 intentos de la contraseña se vuelva al menu principal
            if (contPass++ == 3){
                opcionAccesoStr = "0";
                continue;
            }
            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            user = leeString(stdin, user);
            this->userStr = *(new string(user));
            cout << "" << endl;

            cout << "Ingrese su contrasena:" << endl;
            cout << ">> ";
            pass = leeString(stdin, pass);
            this->passStr = *(new string(pass));
            cout << "" << endl;

            // Verificar usuario
            if ((compruebaUsuario(user, pass)) == true) {
                opcionAccesoStr = "0";
                menuAdmin();
                contPass = 0;
            }
            else {
                cout << "Usuario o contrasena incorrectos. Intente de nuevo por favor" << endl;
                cout << endl;
            }

        }
    }
    if (opcionAccesoStr ==  "3")
        return ;
}

void Menu::menuAdmin() {
    char *opcionAdmin, *nombre, *rut, *direccion, *edad, *nroTel;
    string opcionAdminStr = "0";
    string nombreStr, rutStr, direccionStr, edadStr, nroTelStr;
    ListaEnlazada<string> *telefonos = new ListaEnlazada<string>;

    while (opcionAdminStr == "0") {
        cout << "Administrador" << endl;
        cout << "=============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Lista de vendedores" << endl;
        cout << "2. Ver vendedor" << endl;
        cout << "3. Ingresar vendedor" << endl;
        cout << "4. Modificar vendedor" << endl;
        cout << "5. Eliminar vendedor" << endl;
        cout << "6. Lista de ventas" << endl;
        cout << "7. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionAdmin = leeString(stdin, opcionAdmin);
        opcionAdminStr = *(new string(opcionAdmin));
        cout << "" << endl;

        if (verificarOpcion(opcionAdminStr, Menu::NRO_OP_ADMIN)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        while (opcionAdminStr == "1") {
            menuListVendedores();
            opcionAdminStr == "0";
        }

        while (opcionAdminStr == "2") {
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            nombre = leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << "" << endl;

            // Verificar vendedor
            // Si existe {
            //     opcionAdminStr = "0"
            //     mostrar datos (getResumen())
            // }
            // Sino {
            //     cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
            //     cout << "" << endl;
            // }
        }

        while (opcionAdminStr == "3") {
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            nombre = leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << "" << endl;

            cout << "Ingrese el RUT del vendedor:" << endl;
            cout << ">> ";
            rut = leeString(stdin, rut);
            rutStr = *(new string(rut));
            cout << "" << endl;

            cout << "Ingrese la direccion del vendedor:" << endl;
            cout << ">> ";
            direccion = leeString(stdin, direccion);
            direccionStr = *(new string(direccion));
            cout << "" << endl;

            cout << "Ingrese la edad del vendedor:" << endl;
            cout << ">> ";
            edad = leeString(stdin, edad);
            edadStr = *(new string(edad));
            cout << "" << endl;

            cout << "Ingrese el numero de telefono del vendedor:" << endl; // DESPUES SE MODIFICARA PARA AGREGAR MAS
            cout << ">> ";
            nroTel = leeString(stdin, nroTel);
            nroTelStr = *(new string(nroTel)); // TAL VEZ SEAN MUCHAS VUELTAS
            telefonos->agregar(&nroTelStr); // CUIDADO CON LA DIRECCION DE MEMORIA... EL NEW LA CAMBIA, NO?
            cout << "" << endl;
        }

        while (opcionAdminStr == "4") { // TERMINAR
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            nombre = leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << "" << endl;

            cout << "Ingrese el atributo que desea modificar:";
        }

        while (opcionAdminStr == "5") {
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            nombre = leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << "" << endl;

            // Verificar vendedor
            // Si existe {
            //     opcionAdminStr = "0"
            //     eliminar vendedor
            // }
            // Sino {
            //     cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
            //     cout << "" << endl;
            // }
        }

        while (opcionAdminStr == "6") {
            menuListVentas();
            opcionAdminStr = "0";
        }
    }
}

void Menu::menuListVendedores() {
    char *opcionListVend;
    int critOrden;
    string opcionListVendStr = "0";

    while (opcionListVendStr == "0") {
        cout << "Lista de vendedores" << endl;
        cout << "===================" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Ver lista" << endl;
        cout << "2. Ordenar por nombre" << endl;
        cout << "3. Ordenar por RUT" << endl;
        cout << "4. Ordenar por edad" << endl;
        cout << "5. Ordenar por cantidad de ventas" << endl;
        cout << "6. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionListVend = Menu::leeString(stdin, opcionListVend);
        opcionListVendStr = *(new string(opcionListVend));
        cout << "" << endl;

        if (this->verificarOpcion(opcionListVendStr, Menu::NRO_OP_LISTVEND_MODVEND)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        if (opcionListVendStr == "1") {
            // Mostrar lista
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "2") {
            critOrden = menuOrden();
            // Ordenar por nombre, pasar critOrden
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "3") {
            critOrden = menuOrden();
            // Ordenar por RUT, pasar critOrden
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "4") {
            critOrden = menuOrden();
            // Ordenar por edad, pasar critOrden
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "5") {
            critOrden = menuOrden();
            // Ordenar por cantidad de ventas, pasar critOrden
            opcionListVendStr = "0";
        }
    }
}

int Menu::menuOrden() { // MENU GENERAL PARA DETERMINAR EL CRITERIO DE ORDENAMIENTO
    char *opcionOrd;
    int critOrden;
    string opcionOrdStr = "0";

    while (opcionOrdStr == "0") {
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Orden creciente" << endl;
        cout << "2. Orden decreciente" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionOrd = leeString(stdin, opcionOrd);
        opcionOrdStr = *(new string(opcionOrdStr));
        cout << "" << endl;

        if (verificarOpcion(opcionOrdStr, Menu::NRO_OP_CRITORD)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        if (opcionOrdStr == "1") {
            // Ordenar crecientemente
            cout << "Se ha ordenado crecientemente." << endl;
            cout << "" << endl;
            opcionOrdStr=="";
            critOrden = 1;
        }

        if (opcionOrdStr == "2") {
            // Ordenar decrecientemente
            cout << "Se ha ordenado decrecientemente." << endl;
            cout << "" << endl;
            opcionOrdStr=="";
            critOrden = -1;
        }
    }

    return critOrden;
}

void Menu::modificarVend() {
    char *opModVend, *nombre;
    string opModVendStr = "0";
    string nombreStr;

    cout << "Ingrese el nombre del vendedor:" << endl;
    cout << ">> ";
    nombre = leeString(stdin, nombre);
    nombreStr = *(new string(nombre));
    cout << "" << endl;

    cout << "Ingrese el atributo que desea modificar:";

    while (opModVendStr == "0") {
        cout << "Que atributo desea modificar? Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. RUT" << endl;
        cout << "3. Direccion" << endl;
        cout << "4. Agregar telefono" << endl;
        cout << "5. Quitar telefono" << endl;
        cout << "6. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opModVend = leeString(stdin, opModVend);
        opModVendStr = *(new string(opModVendStr));
        cout << "" << endl;

        if (verificarOpcion(opcionOrdStr, Menu::NRO_OP_LISTVEND_MODVEND)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        while (opcionOrdStr == "1") {

        }
    }
}

void Menu::menuListVentas() {
    char *opcionListVent;
    int critOrden;
    string opcionListVentStr = "0";

    while (opcionListVentStr == "0") {
        cout << "Lista de ventas" << endl;
        cout << "===============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Ver lista" << endl;
        cout << "2. Ordenar por nombre del libro" << endl;
        cout << "3. Ordenar por nombre del cliente" << endl;
        cout << "4. Ordenar por cantidad de libros" << endl;
        cout << "5. Ordenar por monto total" << endl;
        cout << "6. Ordenar por nombre del vendedor" << endl;
        cout << "7. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionListVent = leeString(stdin, opcionListVent);
        opcionListVentStr = *(new string(opcionListVent));
        cout << "" << endl;

        if (verificarOpcion(opcionListVentStr, Menu::NRO_OP_LISTVEND_MODVEND)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        if (opcionListVentStr == "1") {
            // Mostrar lista
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "2") {
            critOrden = menuOrden();
            // Ordenar por nombre del libro, pasar critOrden
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "3") {
            critOrden = menuOrden();
            // Ordenar por nombre del cliente, pasar critOrden
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "4") {
            critOrden = menuOrden();
            // Ordenar por cantidad de libros, pasar critOrden
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "5") {
            critOrden = menuOrden();
            // Ordenar por monto total, pasar critOrden
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "6") {
            critOrden = menuOrden();
            // Ordenar por nombre del vendedor, pasar critOrden
            opcionListVentStr = "0";
        }
    }
}

//////////////////////////////////////////////////////////////////

void Menu::menuVend() {
    char *opcionVend;
    string opcionVendStr = "0";

    while (opcionVendStr == "0") {
        cout << "Vendedor" << endl;
        cout << "=============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Lista de clientes" << endl;
        cout << "2. Ver cliente" << endl;
        cout << "3. Ingresar cliente" << endl;
        cout << "4. Modificar cliente" << endl;
        cout << "5. Ingresar libro" << endl;
        cout << "6. Realizar una venta" << endl;
        cout << "7. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionVend = leeString(stdin, opcionVend);
        opcionVendStr = *(new string(opcionVendStr));
        cout << "" << endl;

        if (verificarOpcion(opcionVendStr, Menu::NRO_OP_VEND)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
        }

        while (opcionVend == "1") {
            // Mostrar lista de clientes
            // opcionVend = 0;
        }

        while (opcionVend == "2") {

        }
    }
}


bool Menu::compruebaUsuario( string user, string pass) {
    int i;
    Vendedor *vendTemp;
    stringstream rutStream;
    string rutStr;
    for (i = 0; i < this->adminListas->getListaVendedores()->longitud(); i++) {
        vendTemp = this->adminListas->getListaVendedores()->recuperar(i);
        rutStream << vendTemp->getRut();
        rutStr = rutStream.str();
        if (rutStr == user) {
            if ((rutStr.substr(rutStr.length()-3, 3)) == pass) //quizas esté mal cortado
                return true;
            else
                return false;
        }
        rutStrea = "";
    }
    return false;
}


/**
* Esta función se encarga de leer caracteres desde un flujo y guardarlo en un vector dinámico de caracteres
* Fue realizada pensando en que el flujo puede ser el teclado o un archivo de texto
* Guarda en el vector dinámico todos los caracteres hasta que encuentra un salto de linea o el final del flujo
* Fue realizada para no tener problemas de desbordamiento de buffer, ya que redimensiona el vector dinámico si 
es necesario
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
                {	punteroString = (char *)realloc(punteroString, (strlen(punteroString) + TAM_REDIM) * 
sizeof(char));
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

