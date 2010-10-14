#include "Menu.h"

Menu::Menu(AdminListas *adminListas) {
    this->adminListas = adminListas;
}

void Menu::ejecutar() {
    menuAcceso();
}

string Menu::getNrosTelVend(int pos) { // REVISAR FUNCIONAMIENTO
    stringstream strStream;
    for (int i=0; i<this->adminListas->getListaVendedores()->recuperar(pos)->getTelefonos()->longitud(); i++)
        strStream << this->adminListas->getListaVendedores()->recuperar(pos)->getTelefonos()->recuperar(i) << " ";
    return strStream.str();
}

string Menu::getNrosTelClient(int pos) { // REVISAR FUNCIONAMIENTO
    stringstream strStream;
    for (int i=0; i<this->adminListas->getListaClientes()->recuperar(pos)->getTelefonos()->longitud(); i++)
        strStream << this->adminListas->getListaClientes()->recuperar(pos)->getTelefonos()->recuperar(i) << " ";
    return strStream.str();
}

string Menu::intAString(int i) {
    stringstream strStream;
    strStream << i;
    return strStream.str();
}

bool Menu::compruebaUsuario(string user, string pass) {
    int i;
    Vendedor *vendTemp;
    stringstream rutStream;
    string rutStr;
    for (i = 0; i < this->adminListas->getListaVendedores()->longitud(); i++) {
        vendTemp = this->adminListas->getListaVendedores()->recuperar(i);
        rutStream << vendTemp->getRut();
        rutStr = rutStream.str();
        if (rutStr == user) {
            if (((rutStr.substr(rutStr.length()-3, 3)) == pass) && (vendTemp->getEsActivo() == true)) //quizas esta mal cortado
                return true;
            else
                return false;
        }
        rutStream.str("");
    }
    return false;
}

//esta funcion encuentra la posicion en la lista de un vendedor, sea por nombre o por rut
int Menu::encuentraUsuario(string linea) {
    int i;
    Vendedor *vendTemp;
    stringstream rutStream;
    string rutStr;
    for (i = 0; i < this->adminListas->getListaVendedores()->longitud(); i++) {
        vendTemp = this->adminListas->getListaVendedores()->recuperar(i);
        if (vendTemp->getNombre() == linea)
            return i;
        rutStream << vendTemp->getRut();
        rutStr = rutStream.str();
        if (rutStr == linea)
            return i;
        rutStream.str("");
    }
    return -1;
}

int Menu::encuentraCliente(string nombre) {
    int i;
    Cliente *clienteTemp;
    stringstream nombreStream;
    string nombreStr;
    for (i = 0; i < this->adminListas->getListaClientes()->longitud(); i++) {
        clienteTemp = this->adminListas->getListaClientes()->recuperar(i);
        nombreStream << clienteTemp->getNombre();
        nombreStr = nombreStream.str();
        if (nombreStr == nombre)
            return i;
        nombreStream.str("");
    }
    return -1;
}

bool Menu::verificarOpcion(string entrada, int nroOpciones) {
    bool valido = true;
    for (int i = 1; i <= nroOpciones; i++) {
        if (entrada == intAString(i)) {
            valido = false;
            return valido;
        }
    }
    return valido;
}

void Menu::menuAcceso() {
    char *opcionAcceso, *user, *pass;
    string opcionAccesoStr = "0";
    string userStr, passStr;
    int contPass = 0;

    while (opcionAccesoStr ==  "0") {
        cout << "QBiblioAgent" << endl;
        cout << "============" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Ingresar como administrador" << endl;
        cout << "2. Ingresar como vendedor" << endl;
        cout << "3. Salir" << endl << endl;
        cout << ">> ";
        opcionAcceso = Menu::leeString(stdin, opcionAcceso);
        opcionAccesoStr = *(new string(opcionAcceso));
        cout << "" << endl;

        if (this->verificarOpcion(opcionAccesoStr, 3)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
            opcionAccesoStr = "0";
        }

        while (opcionAccesoStr == "1") {
            if (contPass++ >= 3){
                cout << "Demasiados intentos de contrasena..." << endl;
                opcionAccesoStr = "0";
                contPass = 0;
                continue;
            }
            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            user = Menu::leeString(stdin, user);
            userStr = *(new string(user));
            cout << endl;

            cout << "Ingrese su contrasena:" << endl;
            cout << ">> ";
            pass = Menu::leeString(stdin, pass);
            passStr = *(new string(pass));
            cout << endl;

            // Verificar usuario
            if ((userStr == "admin") && (passStr == "123")) {
                opcionAccesoStr = "0";
                menuAdmin();
                contPass = 0;
            }
            else
                cout << "Usuario o contrasena incorrectos. Intente de nuevo por favor." << endl << endl;
        }

        while (opcionAccesoStr == "2") {
            if (contPass++ >= 3){
                opcionAccesoStr = "0";
                contPass = 0;
                continue;
            }

            cout << "Ingrese su nombre de usuario:" << endl;
            cout << ">> ";
            user = Menu::leeString(stdin, user);
            userStr = *(new string(user));
            cout << endl;

            cout << "Ingrese su contrasena:" << endl;
            cout << ">> ";
            pass = Menu::leeString(stdin, pass);
            passStr = *(new string(pass));
            cout << endl;

            if ((compruebaUsuario(user, pass)) == true) {
                opcionAccesoStr = "0";
                menuVend();
                contPass = 0;
            }
            else
                cout << "Usuario o contrasena incorrectos. Intente de nuevo por favor." << endl << endl;
        }
        if (opcionAccesoStr == "3")
            return ;
    }
}

void Menu::menuAdmin() {
    char *opcionAdmin=NULL, *charTemp = NULL, *nombre=NULL, *rut=NULL, *direccion=NULL, *edad=NULL, *nrosTel=NULL, *email=NULL;
    string opcionAdminStr = "0", emailStr, nombreStr, rutStr, direccionStr, edadStr, nrosTelStr;
    int pos;

    while (opcionAdminStr == "0") {
        cout << "Administrador" << endl;
        cout << "=============" << endl << endl;
        cout << "Escoja una opcion:" << endl << endl;
        cout << "1. Lista de vendedores" << endl;
        cout << "2. Ver vendedor" << endl;
        cout << "3. Ingresar vendedor" << endl;
        cout << "4. Modificar vendedor" << endl;
        cout << "5. Eliminar vendedor" << endl;
        cout << "6. Lista de ventas" << endl;
        cout << "7. Volver" << endl << endl;
        cout << ">> ";
        opcionAdmin = Menu::leeString(stdin, opcionAdmin);
        opcionAdminStr = *(new string(opcionAdmin));
        cout << endl;

        if (this->verificarOpcion(opcionAdminStr, 7)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "1") {
            menuListVendedores();
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "2") {
            pos = -1;
            cout << "Ingrese el nombre del vendedor o rut:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;
            pos = encuentraUsuario(nombreStr);
            while (pos == -1) {
                cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del vendedor" << endl;
                cout << "Ingrese el nombre del vendedor:" << endl;
                cout << ">> ";
                nombre = Menu::leeString(stdin, nombre);
                nombreStr = *(new string(nombre));
                cout << endl;
                if (nombreStr == ""){
                    opcionAdminStr = "0";
                    break;
                }
                pos = encuentraUsuario(nombreStr);
            }
            opcionAdminStr = "0";
            cout << (this->adminListas->getListaVendedores()->recuperar(pos)->getResumen());
            cout << endl;
        }

        while (opcionAdminStr == "3") { // CONTROLAR DATOS, FALTA GESTIONAR CON CATCH LOS ERRORES LANZADOS DESDE ADMINLISTAS
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;

            cout << "Ingrese el RUT del vendedor:" << endl;
            cout << ">> ";
            rut =Menu::leeString(stdin, rut);
            rutStr = *(new string(rut));
            cout << "" << endl;

            cout << "Ingrese la direccion del vendedor:" << endl;
            cout << ">> ";
            direccion =Menu::leeString(stdin, direccion);
            direccionStr = *(new string(direccion));
            cout << "" << endl;

            cout << "Ingrese la edad del vendedor:" << endl;
            cout << ">> ";
            edad = Menu::leeString(stdin, edad);
            edadStr = *(new string(edad));
            cout << endl;

            cout << "Ingrese el email del vendedor:" << endl;
            cout << ">> ";
            email = Menu::leeString(stdin, edad);
            emailStr = *(new string(email));
            cout << endl;

            cout << "Ingrese los numeros de telefono del vendedor, separados por espacios:" << endl;
            cout << ">> ";
            nrosTel = Menu::leeString(stdin, nrosTel);
            nrosTelStr = *(new string(nrosTel));
            cout << endl;
            try {
                this->adminListas->agregarVendedor(rutStr, nombreStr, direccionStr, edadStr, emailStr, nrosTelStr);
                cout << "Se ha agregado un nuevo vendedor." << endl;
                cout << endl;
            }
            catch (ErrorExcep e){
                if (e.getMotivo() == E_NOMB_REP)
                    cout << "El nombre del vendedor esta repetido; intente ingresar otro nombre." << endl;
                if (e.getMotivo() == E_RUT)
                    cout << "El rut del vendedor contiene caracteres no validos; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_RUT_REP)
                    cout << "El rut del vendedor ya existe; intente ingresar otro rut." << endl;
                if (e.getMotivo() == E_EDAD)
                    cout << "La edad introducida no es valida; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_TELEFONO) {
                    cout << "Los numeros de telefono introducidos no son validos; deben ser solo" << endl;
                    cout << "numeros y estar separados por espacios; intente de nuevo por favor." << endl;
                }
                if (e.getMotivo() == E_MAIL)
                    cout << "El mail introducido no es valido; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de administrador" << endl;
                Menu::leeString(stdin, charTemp);
                cout << endl;
            }

            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "4") {
            menuModVend();
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "5") {
            pos = -1;
            cout << "Ingrese el nombre del vendedor o rut:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;
            pos = encuentraUsuario(nombreStr);
            while (pos == -1) {
                cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del vendedor" << endl;
                cout << "Ingrese el nombre del vendedor:" << endl;
                cout << ">> ";
                nombre = Menu::leeString(stdin, nombre);
                nombreStr = *(new string(nombre));
                cout << endl;
                if (nombreStr == ""){
                    opcionAdminStr = "0";
                    break;
                }
                pos = encuentraUsuario(nombreStr);
            }
            opcionAdminStr = "0";
            cout << (this->adminListas->getListaVendedores()->eliminar(pos));
            cout << "Se ha eliminado el vendedor." << endl;
            cout << endl;
        }

        if (opcionAdminStr == "6") {
            menuListVentas();
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "7")
            return ;
    }
}

void Menu::menuListVendedores() {
    char *opcionListVend = NULL;
    int critOrden, i;
    string opcionListVendStr = "0";
    ListaEstatica<Vendedor> *lVendedoresTemp;

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
        cout << "6. Volver" << endl << endl;
        cout << ">> ";
        opcionListVend = Menu::leeString(stdin, opcionListVend);
        opcionListVendStr = *(new string(opcionListVend));
        cout << endl;

        if (this->verificarOpcion(opcionListVendStr, 6)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << endl;
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "1") {
            lVendedoresTemp = this->adminListas->getListaVendedores();
            cout << "Se va a mostrar un listado de las vendedores: " <<endl;
            for (i = 0; i < lVendedoresTemp->longitud(); i++) {
                cout << endl << lVendedoresTemp->recuperar(i)->getResumen() << endl;
            }
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "2") {
            critOrden = menuOrden();
            Vendedor::setNumOrder(ORD_VEND_NOM);
            this->adminListas->getListaVendedores()->ordenar(critOrden);
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "3") {
            critOrden = menuOrden();
            Vendedor::setNumOrder(ORD_VEND_RUT);
            this->adminListas->getListaVendedores()->ordenar(critOrden);
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "4") {
            critOrden = menuOrden();
            Vendedor::setNumOrder(ORD_VEND_EDAD);
            this->adminListas->getListaVendedores()->ordenar(critOrden);
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "5") {
            critOrden = menuOrden();
            Vendedor::setNumOrder(ORD_VEND_CANTVENT);
            this->adminListas->getListaVendedores()->ordenar(critOrden);
            opcionListVendStr = "0";
        }

        if (opcionListVendStr == "6")
            return ;
    }
}

int Menu::menuOrden() { // MENU GENERAL PARA DETERMINAR EL CRITERIO DE ORDENAMIENTO
    char *opcionOrd = NULL;
    int critOrden;
    string opcionOrdStr = "0";

    while (opcionOrdStr == "0") {
        cout << "Escoja una opcion:" << endl << endl;
        cout << "1. Orden creciente" << endl;
        cout << "2. Orden decreciente" << endl << endl;
        cout << ">> ";
        opcionOrd = Menu::leeString(stdin, opcionOrd);
        opcionOrdStr = *(new string(opcionOrd));
        cout << endl;

        if (this->verificarOpcion(opcionOrdStr, 2)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
            opcionOrdStr = "0";
        }

        if (opcionOrdStr == "1") {
            // Ordenar crecientemente
            cout << "Se ha ordenado crecientemente." << endl << endl;
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

void Menu::menuModVend() {
    char *opModVend=NULL, *nombre=NULL, *nvoNombre=NULL, *nvoRut=NULL, *nvaDir=NULL;
    char *nvoTel=NULL, *borrTel=NULL, *nvoEmail=NULL, *nvaEdad=NULL, *charTemp=NULL;
    string opModVendStr = "0", direccionStr, rutStr, edadStr, emailStr;
    string nombreStr, nvoNombreStr, nvoTelStr, borrTelStr, nvoRutStr, nvaDirStr;
    string nvaEdadStr, nvoEmailStr, nrosTelStr;
    bool nombreValido = false;
    int pos, id;

    while (nombreValido == false) {
        cout << "Ingrese el nombre del vendedor:" << endl;
        cout << ">> ";
        nombre = Menu::leeString(stdin, nombre);
        nombreStr = *(new string(nombre));
        cout << "" << endl;

        if (encuentraUsuario(nombreStr) != -1) {
            nombreValido = true;
            pos = encuentraUsuario(nombreStr);
            id = adminListas->getListaVendedores()->recuperar(pos)->getId();
        }
        else {
            cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
            cout << "" << endl;
        }
    }

    while (opModVendStr == "0") {
        cout << "Que atributo desea modificar? Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Rut" << endl;
        cout << "3. Direccion" << endl;
        cout << "4. Edad" << endl;
        cout << "5. Agregar telefono" << endl;
        cout << "6. Quitar telefono" << endl;
        cout << "7. Email" << endl;
        cout << "8. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opModVend = Menu::leeString(stdin, opModVend);
        opModVendStr = *(new string(opModVendStr));
        cout << endl;

        if (this->verificarOpcion(opModVendStr, 8)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "1") {
            cout << "Ingrese el nuevo nombre del vendedor:";
            cout << endl;
            cout << ">> ";
            nvoNombre = Menu::leeString(stdin, nvoNombre);
            nvoNombreStr = *(new string(nvoNombre));
            nvoRutStr = adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvaEdadStr = adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelVend(pos);
            cout << endl;
            try {
                this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado el nombre del vendedor." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_NOMB_REP)
                    cout << "El nombre del vendedor esta repetido; intente ingresar otro nombre." << endl;
                cout << "Presione ENTER para volver al menu de administrador" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModVendStr = "0";
        }

        if (opModVendStr == "2") {
            cout << "Ingrese el nuevo rut del vendedor:";
            cout << ">> ";
            nvoRut = Menu::leeString(stdin, nvoRut);
            nvoRutStr = *(new string(nvoRut));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvaEdadStr = adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            try {
                this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado el rut del vendedor." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_RUT)
                    cout << "El rut no es valido; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de administrador" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModVendStr = "0";
        }

        if (opModVendStr == "3") {
            cout << "Ingrese la nueva direccion del vendedor:";
            cout << ">> ";
            nvaDir = Menu::leeString(stdin, nvaDir);
            nvaDirStr = *(new string(nvaDir));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            nvoRutStr = adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvaEdadStr = adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
            opModVendStr = "0";
            cout << endl;
            cout << "Se ha modificado la direccion del vendedor." << endl;
            cout << endl;
        }

        if (opModVendStr == "4") {
            cout << "Ingrese la nueva edad del vendedor:";
            cout << ">> ";
            nvaEdad = Menu::leeString(stdin, nvaEdad);
            nvaEdadStr = *(new string(nvaEdad));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            nvoRutStr = adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            try {
                this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado la edad del vendedor." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_EDAD)
                    cout << "La edad no es valida; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de administrador" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModVendStr = "0";
        }

        if (opModVendStr == "5") { // TERMINAR
            cout << "Ingrese el numero de telefono a agregar:";
            cout << ">> ";
            nvoTel = Menu::leeString(stdin, nvoTel);
            nvoTelStr =
            direccionStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            rutStr = adminListas->getListaVendedores()->recuperar(pos)->getRut();
            edadStr = adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            emailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            this->adminListas->editarVendedor(id, rutStr, nombreStr, nvaDirStr, edadStr, emailStr, nrosTelStr);
        }

        if (opModVendStr == "6") { // TERMINAR
            cout << "Ingrese el numero de telefono a eliminar:";
            cout << "" << endl;
            cout << ">> ";
            borrTel = Menu::leeString(stdin, borrTel);
            borrTelStr = *(new string(borrTel));
        }

        if (opModVendStr == "7") {
            cout << "Ingrese el nuevo email del vendedor:";
            cout << ">> ";
            nvoEmail = Menu::leeString(stdin, nvoEmail);
            nvoEmailStr = *(new string(nvoEmail));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvaEdadStr = adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
            cout << "Se ha modificado el email del vendedor." << endl;
            cout << endl;
            opModVendStr = "0";
        }
    }
}

void Menu::menuListVentas() {
    char *opcionListVent;
    int critOrden, i;
    string opcionListVentStr = "0";
    ListaEnlazada<Venta> *lVentasTemp;

    while (opcionListVentStr == "0") {
        cout << "Lista de ventas" << endl;
        cout << "===============" << endl << endl;
        cout << "Escoja una opcion:" << endl << endl;
        cout << "1. Ver lista" << endl;
        cout << "2. Ordenar por nombre del libro" << endl;
        cout << "3. Ordenar por nombre del cliente" << endl;
        cout << "4. Ordenar por cantidad de libros" << endl;
        cout << "5. Ordenar por monto total" << endl;
        cout << "6. Ordenar por nombre del vendedor" << endl;
        cout << "7. Volver" << endl << endl;
        cout << ">> ";
        opcionListVent = Menu::leeString(stdin, opcionListVent);
        opcionListVentStr = *(new string(opcionListVent));
        cout << "" << endl;

        if (this->verificarOpcion(opcionListVentStr, 7)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << "" << endl;
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "1") {
            lVentasTemp = this->adminListas->getListaVentas();
            cout << "Se va a mostrar un listado de las ventas: " <<endl;
            for (i = 0; i < lVentasTemp->longitud(); i++) {
                cout << endl << lVentasTemp->recuperar(i)->getResumen() << endl;
            }
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "2") {
            critOrden = menuOrden();
            Venta::setNumOrder(ORD_VENT_NOMBRELIB);
            this->adminListas->getListaVentas()->ordenar(critOrden);
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "3") {
            critOrden = menuOrden();
            Venta::setNumOrder(ORD_VENT_CLIENTE);
            this->adminListas->getListaVentas()->ordenar(critOrden);
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "4") {
            critOrden = menuOrden();
            Venta::setNumOrder(ORD_VENT_LIBRO);
            this->adminListas->getListaVentas()->ordenar(critOrden);
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "5") {
            critOrden = menuOrden();
            Venta::setNumOrder(ORD_VENT_MONTO);
            this->adminListas->getListaVentas()->ordenar(critOrden);
            opcionListVentStr = "0";
        }

        if (opcionListVentStr == "6") {
            critOrden = menuOrden();
            Venta::setNumOrder(ORD_VENT_VENDEDOR);
            this->adminListas->getListaVentas()->ordenar(critOrden);
            opcionListVentStr = "0";
        }
    }
}

//////////////////////////////////////////////////////////////////

void Menu::menuVend() {
    char *opcionVend=NULL, *charTemp=NULL,*nombre=NULL, *isbn=NULL, *autor=NULL, *paginas=NULL, *direccion=NULL;
    char *precio=NULL, *stock=NULL, *rut=NULL, *edad=NULL, *dir=NULL, *email=NULL, *nroTel=NULL, *peso = NULL;
    int pos;
    string opcionVendStr = "0";
    string nombreStr, isbnStr, autorStr, paginasStr, precioStr, stockStr, rutStr, edadStr, dirStr, emailStr, nroTelStr, pesoStr;

    while (opcionVendStr == "0") {
        cout << "Vendedor" << endl;
        cout << "=============" << endl << endl;
        cout << "Escoja una opcion:" << endl << endl;
        cout << "1. Lista de clientes" << endl;
        cout << "2. Ver cliente" << endl;
        cout << "3. Ingresar cliente" << endl;
        cout << "4. Modificar cliente" << endl;
        cout << "5. Ingresar libro" << endl;
        cout << "6. Realizar una venta" << endl;
        cout << "7. Volver" << endl;
        cout << endl;
        cout << ">> ";
        opcionVend = Menu::leeString(stdin, opcionVend);
        opcionVendStr = *(new string(opcionVendStr));
        cout << endl;

        if (this->verificarOpcion(opcionVendStr, 7)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
            opcionVendStr = "0";
        }

        if (opcionVendStr == "1") {
            menuListClientes();
            opcionVendStr = "0";
        }

        while (opcionVendStr == "2") {
            pos = -1;
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;
            pos = this->encuentraCliente(nombreStr);
            while (pos == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del cliente" << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                nombre = Menu::leeString(stdin, nombre);
                nombreStr = *(new string(nombre));
                cout << endl;
                if (nombreStr == ""){
                    opcionVendStr = "";
                    break ;
                }
                pos = this->encuentraCliente(nombreStr);
            }
            opcionVendStr = "0";
            cout << (this->adminListas->getListaClientes()->recuperar(pos)->getResumen());
            cout << endl;
        }

        while (opcionVendStr == "3") {
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;

            cout << "Ingrese el RUT del cliente:" << endl;
            cout << ">> ";
            rut = Menu::leeString(stdin, rut);
            rutStr = *(new string(rutStr));
            cout << endl;

            cout << "Ingrese la edad del cliente:" << endl;
            cout << ">> ";
            edad = Menu::leeString(stdin, edad);
            edadStr = *(new string(edad));
            cout << endl;

            cout << "Ingrese la direccion del cliente:" << endl;
            cout << ">> ";
            dir = Menu::leeString(stdin, dir);
            dirStr = *(new string(dir));
            cout << "" << endl;

            cout << "Ingrese el numero de telefono del cliente:" << endl;
            cout << ">> ";
            nroTel = Menu::leeString(stdin, nroTel);
            nroTelStr = *(new string(nroTel));
            cout << endl;

            cout << "Ingrese el email del cliente:" << endl;
            cout << ">> ";
            email = Menu::leeString(stdin, email);
            emailStr = *(new string(email));
            cout << endl;

            try {
                this->adminListas->agregarCliente(rutStr, nombreStr, edadStr, direccion, nroTelStr, emailStr);
                cout << "Se ha agregado un nuevo cliente.";
                cout << endl;
            }
            catch (ErrorExcep e){
                if (e.getMotivo() == E_NOMB_REP)
                    cout << "El nombre del cliente esta repetido; intente ingresar otro nombre." << endl;
                if (e.getMotivo() == E_RUT)
                    cout << "El rut del cliente contiene caracteres no validos; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_RUT_REP)
                    cout << "El rut del cliente ya existe; intente ingresar otro rut." << endl;
                if (e.getMotivo() == E_EDAD)
                    cout << "La edad introducida no es valida; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_TELEFONO) {
                    cout << "Los numeros de telefono introducidos no son validos; deben ser solo" << endl;
                    cout << "numeros y estar separados por espacios; intente de nuevo por favor." << endl;
                }
                if (e.getMotivo() == E_MAIL)
                    cout << "El mail introducido no es valido; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de vendedor" << endl;
                charTemp = Menu::leeString(stdin, charTemp);
                cout << endl;
            }

            opcionVendStr = "0";
        }

        if (opcionVendStr == "4") {
            menuModCliente();
            opcionVendStr = "0";
        }

        while (opcionVendStr == "5") {
            cout << "Ingrese el nombre del libro:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;

            cout << "Ingrese el ISBN del libro:" << endl;
            cout << ">> ";
            isbn = Menu::leeString(stdin, isbn);
            isbnStr = *(new string(isbn));
            cout << endl;

            cout << "Ingrese el autor del libro:" << endl;
            cout << ">> ";
            autor = Menu::leeString(stdin, autor);
            autorStr = *(new string(autor));
            cout << endl;

            cout << "Ingrese el precio del libro:" << endl;
            cout << ">> ";
            precio = Menu::leeString(stdin, precio);
            precioStr = *(new string(precio));
            cout << endl;

            cout << "Ingrese el numero de paginas del libro:" << endl;
            cout << ">> ";
            paginas = Menu::leeString(stdin, paginas);
            paginasStr = *(new string(paginas));
            cout << endl;

            cout << "Ingrese el peso del libro:" << endl;
            cout << ">> ";
            peso = Menu::leeString(stdin, peso);
            pesoStr = *(new string(peso));
            cout << endl;

            cout << "Ingrese el stock del libro:" << endl;
            cout << ">> ";
            stock = Menu::leeString(stdin, stock);
            stockStr = *(new string(stock));
            cout << endl;

            try {
                this->adminListas->agregarLibro(nombreStr, isbnStr, autorStr, paginasStr, pesoStr, precioStr, stockStr);
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_NOMB_REP)
                    cout << "El nombre del libro esta repetido; intente ingresar otro nombre." << endl;
                if (e.getMotivo() == E_ISBN_REP)
                    cout << "El isbn del libro esta repetido; intente con otro." << endl;
                if (e.getMotivo() == E_ISBN)
                    cout << "El numero isbn introducido no es valido; intente con otro." << endl;
                if (e.getMotivo() == E_PAGINAS)
                    cout << "El numero de paginas introducido no es valido; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_PESO)
                    cout << "El peso introducido no es valido; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_PRECIO)
                    cout << "El precio introducido no es valido; intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_STOCK)
                    cout << "El stock introducido no es valido; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de vendedor" << endl;
                charTemp = Menu::leeString(stdin, charTemp);
            }

            opcionVendStr = "0";
        }

        if (opcionVendStr == "6") {
            this->menuRealizarVenta(); //NO REALIZADA TRAZA DE ESTA LLAMADA AUN
            opcionVendStr = "0";
        }
        if (opcionVendStr == "7")
            return ;
    }
}

void Menu::menuRealizarVenta(){

    //FALTA IMPLEMENTAR
}

void Menu::menuListClientes() {
    char *opcionListCliente;
    int critOrden, i;
    string opcionListClienteStr = "0";
    ListaEnlazada<Cliente> *lClienteTemp;

    while (opcionListClienteStr == "0") {
        cout << "Lista de clientes" << endl;
        cout << "=================" << endl;
        cout << "" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "" << endl;
        cout << "1. Ver lista" << endl;
        cout << "2. Ordenar por nombre del cliente" << endl;
        cout << "3. Ordenar por RUT del cliente" << endl;
        cout << "4. Ordenar por cantidad de compras del cliente" << endl;
        cout << "5. Volver" << endl;
        cout << "" << endl;
        cout << ">> ";
        opcionListCliente =Menu::leeString(stdin, opcionListCliente);
        opcionListClienteStr = *(new string(opcionListCliente));
        cout << "" << endl;

        if (this->verificarOpcion(opcionListClienteStr, 5)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
            opcionListClienteStr = "0";
        }

        if (opcionListClienteStr == "1") {
            lClienteTemp = this->adminListas->getListaClientes();
            cout << "Se va a mostrar un listado de los clientes: " <<endl;
            for (i = 0; i < lClienteTemp->longitud(); i++) {
                cout << endl << lClienteTemp->recuperar(i)->getResumen() << endl;
            }
            opcionListClienteStr = "0";
        }

        if (opcionListClienteStr == "2") {
            critOrden = menuOrden();
            Cliente::setNumOrder(ORD_CLIENT_NOMBRE);
            this->adminListas->getListaClientes()->ordenar(critOrden);
            opcionListClienteStr = "0";
        }

        if (opcionListClienteStr == "3") {
            critOrden = menuOrden();
            Cliente::setNumOrder(ORD_CLIENT_RUT);
            this->adminListas->getListaClientes()->ordenar(critOrden);
            opcionListClienteStr = "0";
        }

        if (opcionListClienteStr == "4") {
            critOrden = menuOrden();
            Cliente::setNumOrder(ORD_CLIENT_CANTCOMPRAS);
            this->adminListas->getListaClientes()->ordenar(critOrden);
            opcionListClienteStr = "0";
        }
    }
}

void Menu::menuModCliente() {
    char *opModCliente=NULL, *nombre=NULL, *nvoNombre=NULL, *nvoRut=NULL, *nvaDir=NULL;
    char *nvoTel=NULL, *borrTel=NULL, *nvoEmail=NULL, *nvaEdad=NULL, *charTemp=NULL;
    string opModVendStr = "0", opModClienteStr;
    string nombreStr, nvoNombreStr, nvoRutStr, nvaDirStr, nvoTelStr, borrTelStr, nvaEdadStr, nvoEmailStr, nrosTelStr;
    bool nombreValido = false;
    int pos, id;

    while (nombreValido == false) {
        cout << "Ingrese el nombre del cliente:" << endl;
        cout << ">> ";
        nombre = Menu::leeString(stdin, nombre);
        nombreStr = *(new string(nombre));
        cout << "" << endl;

        if (encuentraCliente(nombreStr) != -1) {
            nombreValido = true;
            pos = encuentraUsuario(nombreStr);
            id = adminListas->getListaClientes()->recuperar(pos)->getId();
        }
        else {
            cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
            cout << "" << endl;
        }
    }

    while (opModClienteStr == "0") {
        cout << "Que atributo desea modificar? Escoja una opcion:" << endl;
        cout << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Rut" << endl;
        cout << "3. Direccion" << endl;
        cout << "4. Edad" << endl;
        cout << "5. Agregar telefono" << endl;
        cout << "6. Quitar telefono" << endl;
        cout << "7. Email" << endl;
        cout << "8. Volver" << endl;
        cout << endl;
        cout << ">> ";
        opModCliente = Menu::leeString(stdin, opModCliente);
        opModClienteStr = *(new string(opModClienteStr));
        cout << endl;

        if (this->verificarOpcion(opModClienteStr, 8)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModVendStr == "1") {
            cout << "Ingrese el nuevo nombre del cliente:";
            cout << endl;
            cout << ">> ";
            nvoNombre = Menu::leeString(stdin, nvoNombre);
            nvoNombreStr = *(new string(nvoNombre));
            nvoRutStr = adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nvaEdadStr = adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            try {
                this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado el nombre del cliente." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_NOMB_REP)
                    cout << "El nombre del cliente esta repetido; intente ingresar otro nombre." << endl;
                cout << "Presione ENTER para volver al menu de vendedor" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModClienteStr = "0";
        }

        if (opModVendStr == "2") {
            cout << "Ingrese el nuevo rut del cliente:";
            cout << endl;
            cout << ">> ";
            nvoRut = Menu::leeString(stdin, nvoNombre);
            nvoRutStr = *(new string(nvoRut));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nvaEdadStr = adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            try {
                this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado el rut del cliente." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_RUT)
                    cout << "El rut del cliente no es valido; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de vendedor" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModClienteStr = "0";
        }

        if (opModClienteStr == "3") {
            cout << "Ingrese la nueva direccion del cliente:";
            cout << endl;
            cout << ">> ";
            nvaDir = Menu::leeString(stdin, nvaDir);
            nvaDirStr = *(new string(nvaDir));
            nvoNombre = Menu::leeString(stdin, nvoNombre);
            nvoRutStr = adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvaEdadStr = adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
            cout << "Se ha modificado la direccion del cliente." << endl;
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModVendStr == "4") {
            cout << "Ingrese la nueva edad del cliente:";
            cout << endl;
            cout << ">> ";
            nvaEdad = Menu::leeString(stdin, nvaEdad);
            nvaEdadStr = *(new string(nvaEdad));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nvoRutStr = adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            try {
                this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
                cout << "Se ha modificado la edad del cliente." << endl;
                cout << endl;
            }
            catch (ErrorExcep e) {
                if (e.getMotivo() == E_EDAD)
                    cout << "La edad del cliente no es valida; intente de nuevo por favor." << endl;
                cout << "Presione ENTER para volver al menu de vendedor" << endl;
                cout << endl;
                Menu::leeString(stdin, charTemp);
            }

            opModClienteStr = "0";
        }

        while (opModClienteStr == "5") { // TERMINAR
            cout << "Ingrese el numero de telefono a agregar:";
            cout << endl;
            cout << ">> ";
            nvoTel = Menu::leeString(stdin, nvoTel);
            nvoTelStr = *(new string(nvoTel));

            // Verificar telefono
            // Si es valido (no existe y esta compuesto de numeros) {
            //     opModClienteStr = "0";
            //     agregar telefono
            // }
            // Sino {
            //     cout << "Numero de telefono no valido. Intente de nuevo por favor." << endl;
            //     cout << "" << endl;
            // }
        }

        while (opModClienteStr == "6") { // TERMINAR
            cout << "Ingrese el numero de telefono a eliminar:";
            cout << endl;
            cout << ">> ";
            borrTel = Menu::leeString(stdin, borrTel);
            borrTelStr = *(new string(borrTel));

            // Verificar telefono
            // Si es valido (existe) {
            //     opModClienteStr = "0";
            //     quitar telefono
            // }
            // Sino {
            //     cout << "No se encuentra el numero de telefono. Intente de nuevo por favor." << endl;
            //     cout << "" << endl;
            // }
        }

        if (opModClienteStr == "7") {
            cout << "Ingrese el nuevo email del cliente:";
            cout << endl;
            cout << ">> ";
            nvoEmail = Menu::leeString(stdin, nvoEmail);
            nvoEmailStr = *(new string(nvoEmail));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            nvoRutStr = adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvaEdadStr = adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
            cout << "Se ha modificado el email del cliente." << endl;
            cout << endl;
            opModClienteStr = "0";
        }
    }
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

