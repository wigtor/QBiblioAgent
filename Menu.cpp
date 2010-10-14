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
        strStream << *(this->adminListas->getListaClientes()->recuperar(pos)->getTelefonos()->recuperar(i)) << " ";
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

int Menu::encuentraCliente(string linea) {
    int i;
    Cliente *clienteTemp;
    stringstream rutStream;
    string rutStr;
    for (i = 0; i < this->adminListas->getListaClientes()->longitud(); i++) {
        clienteTemp = this->adminListas->getListaClientes()->recuperar(i);
        if (clienteTemp->getNombre() == linea)
            return i;
        rutStream << clienteTemp->getRut();
        rutStr = rutStream.str();
        if (rutStr == linea)
            return i;
        rutStream.str("");
    }
    return -1;
}

int Menu::encuentraLibro(string nombre) {
    int i;
    Libro *libroTemp;
    stringstream nombreStream;
    string nombreStr;
    for (i = 0; i < this->adminListas->getListaLibros()->longitud(); i++) {
        libroTemp = this->adminListas->getListaLibros()->recuperar(i);
        nombreStream << libroTemp->getNombre();
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
    char *opcionAdmin=NULL, *nombre=NULL, *direccion=NULL, *edad=NULL, *nrosTel=NULL, *email=NULL;
    string opcionAdminStr = "0", nombreStr, direccionStr, nrosTelStr;
    char *charTemp=NULL, *cliente=NULL, *libro=NULL, *isbn=NULL, *autor=NULL, *paginas=NULL;
    char *precio=NULL, *stock=NULL, *rut=NULL, *dir=NULL, *nroTel=NULL;
    char *peso=NULL, *corr=NULL, *cantLib=NULL, *vendedor=NULL;
    int posCliente, posLibro, posVendedor, i, pos = -1;
    ListaEnlazada<Libro> *lLibros;
    string clienteStr, libroStr, isbnStr, autorStr, paginasStr, precioStr, stockStr, rutStr, edadStr, dirStr;
    string nroTelStr, pesoStr, corrStr, emailStr, cantLibStr, vendedorStr;

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
        cout << "7. Lista de clientes" << endl;
        cout << "8. Ver cliente" << endl;
        cout << "9. Ingresar cliente" << endl;
        cout << "10. Modificar cliente" << endl;
        cout << "11. Ver listado completo de libros" << endl;
        cout << "12. Ingresar libro" << endl;
        cout << "13. Modificar un libro" << endl;
        cout << "14. Realizar una venta" << endl;
        cout << "15. Volver" << endl << endl;
        cout << ">> ";
        opcionAdmin = Menu::leeString(stdin, opcionAdmin);
        opcionAdminStr = *(new string(opcionAdmin));
        cout << endl;

        if (this->verificarOpcion(opcionAdminStr, 15)) {
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
            catch (ErrorExcep &e){
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
                    opcionAdminStr = "";
                    break;
                }
                pos = encuentraUsuario(nombreStr);
            }
            if (pos!=-1) {
                opcionAdminStr = "0";
                this->adminListas->getListaVendedores()->recuperar(pos)->setActivo(false);
                cout << "Se ha eliminado el vendedor." << endl;
                cout << endl;
            }
        }

        if (opcionAdminStr == "6") {
            menuListVentas();
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "7") {
            menuListClientes();
            opcionAdminStr = "0";
        }

        while (opcionAdminStr == "8") {
            posCliente = -1;
            cout << "Ingrese el nombre del cliente o su rut:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;
            posCliente = this->encuentraCliente(clienteStr);
            while (posCliente == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del cliente" << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                cliente = Menu::leeString(stdin, cliente);
                clienteStr = *(new string(cliente));
                cout << endl;
                if (clienteStr == ""){
                    opcionAdminStr = "0";
                    break ;
                }
                posCliente = this->encuentraCliente(clienteStr);
            }
            if (posCliente != -1) {
                opcionAdminStr = "0";
                cout << (this->adminListas->getListaClientes()->recuperar(posCliente)->getResumen());
            }
        }

        while (opcionAdminStr == "9") {
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;

            cout << "Ingrese el RUT del cliente:" << endl;
            cout << ">> ";
            rut = Menu::leeString(stdin, rut);
            rutStr = *(new string(rut));
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
                this->adminListas->agregarCliente(rutStr, clienteStr, edadStr, dirStr, nroTelStr, emailStr);
                cout << "Se ha agregado un nuevo cliente.";
                cout << endl;
            }
            catch (ErrorExcep &e){
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
            }

            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "10") {
            menuModCliente();
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "11") {
            lLibros = this->adminListas->getListaLibros();
            cout << "Se va a mostrar un listado de los libros: " <<endl;
            for (i = 0; i < lLibros->longitud(); i++) {
                cout << endl << "Nombre :" << lLibros->recuperar(i)->getNombre() << endl;
                cout << "Autor :" << lLibros->recuperar(i)->getAutor() << endl;
                cout << "ISBN :" << lLibros->recuperar(i)->getIsbn() << endl;
                cout << "Stock disponible :" << lLibros->recuperar(i)->getStock() << endl;
            }
            opcionAdminStr = "0";
        }
        while (opcionAdminStr == "12") {
            cout << "Ingrese el nombre del libro:" << endl;
            cout << ">> ";
            libro = Menu::leeString(stdin, libro);
            libroStr = *(new string(libro));
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
                this->adminListas->agregarLibro(libroStr, isbnStr, autorStr, paginasStr, pesoStr, precioStr, stockStr);
                cout << "Se ha agregado correctamente el libro: " << endl << this->adminListas->getListaLibros()->recuperar(this->adminListas->getListaLibros()->longitud()-1)->getResumen() << endl;
            }
            catch (ErrorExcep &e) {
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
            }
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "13") {
                    menuModLibro();
                    opcionAdminStr = "0";
                }

        if (opcionAdminStr == "14") {
            posLibro = -1;
            cout << "Ingrese el nombre del libro:" << endl;
            cout << ">> ";
            libro = Menu::leeString(stdin, libro);
            libroStr = *(new string(libro));
            cout << endl;
            posLibro = this->encuentraLibro(libroStr);
            while (posLibro == -1) {
                cout << "Libro no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del libro:" << endl;
                cout << ">> ";
                libro = Menu::leeString(stdin, libro);
                libroStr = *(new string(libro));
                cout << endl;
                posLibro = this->encuentraLibro(libroStr);
            }

            posCliente = -1;
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;
            posCliente = this->encuentraCliente(clienteStr);
            while (posCliente == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                cliente = Menu::leeString(stdin, cliente);
                clienteStr = *(new string(cliente));
                cout << endl;
                posCliente = this->encuentraCliente(clienteStr);
            }

            cout << "Ingrese el valor del correlativo (SI = 1, NO = cualquier otro valor):" << endl;
            cout << ">> ";
            corr = Menu::leeString(stdin, corr);
            corrStr = *(new string(corr));
            cout << endl;

            cout << "Ingrese la cantidad de libros:" << endl;
            cout << ">> ";
            cantLib = Menu::leeString(stdin, cantLib);
            cantLibStr = *(new string(cantLib));
            cout << endl;

            posVendedor = -1;
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            vendedor = Menu::leeString(stdin, vendedor);
            vendedorStr = *(new string(vendedor));
            cout << endl;
            posVendedor = this->encuentraUsuario(vendedorStr);
            while (posVendedor == -1) {
                cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del vendedor:" << endl;
                cout << ">> ";
                vendedor = Menu::leeString(stdin, vendedor);
                vendedorStr = *(new string(vendedor));
                cout << endl;
                posVendedor = this->encuentraUsuario(vendedorStr);
            }

            try {
                this->adminListas->agregarVenta(corrStr, posLibro, posCliente, posVendedor, cantLibStr);
                cout << "Se ha agregado la siguiente venta: " << endl << this->adminListas->getListaVentas()->recuperar(this->adminListas->getListaVentas()->longitud() -1)->getResumen() << endl;

            }
            catch (ErrorExcep &e) {
                if (e.getMotivo() == E_CANT_LIBROS)
                    cout << "La cantidad de libros introducida no es valida, intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_SIN_STOCK)
                    cout << "No hay stock suficiente de libros para realizar la venta, intente de nuevo por favor." << endl;
            }
            opcionAdminStr = "0";
        }

        if (opcionAdminStr == "15")
            return ;
        cout << "Presione ENTER para volver al menu de administrador" << endl;
        Menu::leeString(stdin, charTemp);
        cout << endl;
    }
}

void Menu::menuListVendedores() {
    char *opcionListVend = NULL, *charTemp = NULL, *nombre=NULL;
    string nombreStr;
    int critOrden, i, pos;
    string opcionListVendStr = "0";
    Vendedor *vendedorAct;
    ListaEstatica<Vendedor> *lVendedoresTemp;
    ListaEnlazada<Venta> *lVentasTemp;

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
        cout << "6. Mostrar ventas de un determinado vendedor" << endl;
        cout << "7. Volver" << endl << endl;
        cout << ">> ";
        opcionListVend = Menu::leeString(stdin, opcionListVend);
        opcionListVendStr = *(new string(opcionListVend));
        cout << endl;

        if (this->verificarOpcion(opcionListVendStr, 7)) {
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

        if (opcionListVendStr == "6") {
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
                    opcionListVendStr = "0";
                    break;
                }
                pos = encuentraUsuario(nombreStr);
            }
            if (pos !=-1) {
                pos = encuentraUsuario(nombreStr);
                lVentasTemp = this->adminListas->getListaVentas();
                vendedorAct = this->adminListas->getListaVendedores()->recuperar(pos);
                cout << "Se va a mostrar un listado de las ventas del vendedor: " <<endl;
                cout << vendedorAct->getNombre() << endl;
                for (i = 0; i < lVentasTemp->longitud(); i++) {
                    if (lVentasTemp->recuperar(i)->getVendedor()->getId() == vendedorAct->getId())
                        cout << lVentasTemp->recuperar(i)->getResumen() << endl;
                }
                opcionListVendStr = "0";
            }
        }

        if (opcionListVendStr == "7")
            return ;
        cout << "Presione ENTER para volver al menu de vendedores" << endl;
        charTemp = Menu::leeString(stdin, charTemp);
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
    string opModVendStr = "0";
    string nombreStr, nvoNombreStr, nvoTelStr, borrTelStr, nvoRutStr, nvaDirStr;
    string nvaEdadStr, nvoEmailStr, nrosTelStr;
    stringstream srtTel, streamTemp;
    bool nombreValido = false;
    int pos, id;

    while (nombreValido == false) {
        cout << "Ingrese el nombre del vendedor:" << endl;
        cout << ">> ";
        nombre = Menu::leeString(stdin, nombre);
        nombreStr = *(new string(nombre));
        cout << endl;

        if ((pos = encuentraUsuario(nombreStr)) != -1) {
            nombreValido = true;
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
        cout << "8. Volver" << endl << endl;
        cout << ">> ";
        opModVend = Menu::leeString(stdin, opModVend);
        opModVendStr = *(new string(opModVend));
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
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelVend(pos);
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "2") {
            cout << "Ingrese el nuevo rut del vendedor:";
            cout << ">> ";
            nvoRut = Menu::leeString(stdin, nvoRut);
            nvoRutStr = *(new string(nvoRut));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "3") {
            cout << "Ingrese la nueva direccion del vendedor:";
            cout << ">> ";
            nvaDir = Menu::leeString(stdin, nvaDir);
            nvaDirStr = *(new string(nvaDir));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "4") {
            cout << "Ingrese la nueva edad del vendedor:";
            cout << ">> ";
            nvaEdad = Menu::leeString(stdin, nvaEdad);
            nvaEdadStr = *(new string(nvaEdad));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "5") { // REVISAR
            cout << "Ingrese el numero de telefono a agregar:";
            cout << ">> ";
            stringstream strTel;
            nvoTel = Menu::leeString(stdin, nvoTel);
            nvoTelStr = *(new string(nvoTel));
            srtTel << getNrosTelVend(pos) << nvoTelStr;
            nrosTelStr = strTel.str();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "6") { // REVISAR
            cout << "Ingrese el numero de telefono a eliminar:";
            cout << ">> ";
            stringstream strTel;
            borrTel = Menu::leeString(stdin, borrTel);
            borrTelStr = *(new string(borrTel));
            srtTel << getNrosTelVend(pos) << borrTelStr;
            nrosTelStr = strTel.str();
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaVendedores()->recuperar(pos)->getEmail();
            cout << endl;
            opModVendStr = "0";
        }

        if (opModVendStr == "7") {
            cout << "Ingrese el nuevo email del vendedor:";
            cout << ">> ";
            nvoEmail = Menu::leeString(stdin, nvoEmail);
            nvoEmailStr = *(new string(nvoEmail));
            nvoNombreStr = adminListas->getListaVendedores()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            nvaDirStr = adminListas->getListaVendedores()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaVendedores()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nrosTelStr = Menu::getNrosTelVend(pos);
            cout << endl;
            opModVendStr = "0";
        }
        try {
            this->adminListas->editarVendedor(id, nvoRutStr, nvoNombreStr, nvaDirStr, nvaEdadStr, nvoEmailStr, nrosTelStr);
            cout << "Se ha modificado el vendedor." << endl;
            cout << endl;
            cout << "Presione ENTER para volver al menu de administrador" << endl;
            cout << endl;
            charTemp = Menu::leeString(stdin, charTemp);
            return ;
        }
        catch (ErrorExcep &e) {
            if (e.getMotivo() == E_NOMB_REP)
                cout << "El nombre del vendedor esta repetido; intente ingresar otro nombre." << endl;
            if (e.getMotivo() == E_EDAD)
                cout << "La edad no es valida; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_RUT)
                cout << "El rut no es valido; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_TEL_NO_EXISTE)
                cout << "El telefono no existe; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_TELEFONO)
                cout << "El telefono no es valido; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_MAIL)
                cout << "El mail no es valido; intente de nuevo por favor." << endl;
        }

    }
}

void Menu::menuListVentas() {
    char *opcionListVent = NULL, *charTemp = NULL;
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
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
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
        cout << "Presione ENTER para volver al menu" << endl;
        charTemp = Menu::leeString(stdin, charTemp);
    }
}

//////////////////////////////////////////////////////////////////

void Menu::menuVend() {
    char *opcionVend=NULL, *charTemp=NULL, *cliente=NULL, *libro=NULL, *isbn=NULL, *autor=NULL, *paginas=NULL;
    char *precio=NULL, *stock=NULL, *rut=NULL, *edad=NULL, *dir=NULL, *email=NULL, *nroTel=NULL;
    char *peso=NULL, *corr=NULL, *cantLib=NULL, *vendedor=NULL;
    int posCliente, posLibro, posVendedor, i, pos = -1;
    ListaEnlazada<Libro> *lLibros;
    string opcionVendStr = "0";
    string clienteStr, libroStr, isbnStr, autorStr, paginasStr, precioStr, stockStr, rutStr, edadStr, dirStr;
    string nroTelStr, pesoStr, corrStr, emailStr, cantLibStr, vendedorStr;

    while (opcionVendStr == "0") {
        cout << "Vendedor" << endl;
        cout << "=============" << endl << endl;
        cout << "Escoja una opcion:" << endl << endl;
        cout << "1. Lista de clientes" << endl;
        cout << "2. Ver cliente" << endl;
        cout << "3. Ingresar cliente" << endl;
        cout << "4. Modificar cliente" << endl;
        cout << "5. Ver listado completo de libros" << endl;
        cout << "6. Ingresar libro" << endl;
        cout << "7. Modificar un libro" << endl;
        cout << "8. Realizar una venta" << endl;
        cout << "9. Volver" << endl;
        cout << endl;
        cout << ">> ";
        opcionVend = Menu::leeString(stdin, opcionVend);
        opcionVendStr = *(new string(opcionVend));
        cout << endl;

        if (this->verificarOpcion(opcionVendStr, 9)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor." << endl;
            opcionVendStr = "0";
        }

        if (opcionVendStr == "1") {
            menuListClientes();
            opcionVendStr = "0";
        }

        while (opcionVendStr == "2") {
            posCliente = -1;
            cout << "Ingrese el nombre del cliente o su rut:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;
            posCliente = this->encuentraCliente(clienteStr);
            while (posCliente == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del cliente" << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                cliente = Menu::leeString(stdin, cliente);
                clienteStr = *(new string(cliente));
                cout << endl;
                if (clienteStr == ""){
                    opcionVendStr = "";
                    break ;
                }
                posCliente = this->encuentraCliente(clienteStr);
            }
            if (pos == -1) {
                opcionVendStr = "0";
                cout << (this->adminListas->getListaClientes()->recuperar(posCliente)->getResumen());
            }
            cout << "Presione ENTER para volver al menu de vendedor" << endl;
            charTemp = Menu::leeString(stdin, charTemp);
            cout << endl;
        }

        while (opcionVendStr == "3") {
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;

            cout << "Ingrese el RUT del cliente:" << endl;
            cout << ">> ";
            rut = Menu::leeString(stdin, rut);
            rutStr = *(new string(rut));
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
                this->adminListas->agregarCliente(rutStr, clienteStr, edadStr, dirStr, nroTelStr, emailStr);
                cout << "Se ha agregado un nuevo cliente.";
                cout << endl;
            }
            catch (ErrorExcep &e){
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
            }

            opcionVendStr = "0";
        }

        if (opcionVendStr == "4") {
            menuModCliente();
            opcionVendStr = "0";
        }

        if (opcionVendStr == "5") {
            lLibros = this->adminListas->getListaLibros();
            cout << "Se va a mostrar un listado de los libros: " <<endl;
            for (i = 0; i < lLibros->longitud(); i++) {
                lLibros->recuperar(i)->getResumen();
            }
            opcionVendStr = "0";
        }
        while (opcionVendStr == "6") {
            cout << "Ingrese el nombre del libro:" << endl;
            cout << ">> ";
            libro = Menu::leeString(stdin, libro);
            libroStr = *(new string(libro));
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
                this->adminListas->agregarLibro(libroStr, isbnStr, autorStr, paginasStr, pesoStr, precioStr, stockStr);
                cout << "Se ha agregado correctamente el libro: " << endl << this->adminListas->getListaLibros()->recuperar(this->adminListas->getListaLibros()->longitud()-1)->getResumen() << endl;
            }
            catch (ErrorExcep &e) {
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
            }
            opcionVendStr = "0";
        }

        if (opcionVendStr == "9") {
            menuModLibro();
            opcionVendStr = "0";
        }

        if (opcionVendStr == "8") {
            posLibro = -1;
            cout << "Ingrese el nombre del libro:" << endl;
            cout << ">> ";
            libro = Menu::leeString(stdin, libro);
            libroStr = *(new string(libro));
            cout << endl;
            posLibro = this->encuentraLibro(libroStr);
            while (posLibro == -1) {
                cout << "Libro no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del libro:" << endl;
                cout << ">> ";
                libro = Menu::leeString(stdin, libro);
                libroStr = *(new string(libro));
                cout << endl;
                posLibro = this->encuentraLibro(libroStr);
            }

            posCliente = -1;
            cout << "Ingrese el nombre del cliente:" << endl;
            cout << ">> ";
            cliente = Menu::leeString(stdin, cliente);
            clienteStr = *(new string(cliente));
            cout << endl;
            posCliente = this->encuentraCliente(clienteStr);
            while (posCliente == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                cliente = Menu::leeString(stdin, cliente);
                clienteStr = *(new string(cliente));
                cout << endl;
                posCliente = this->encuentraCliente(clienteStr);
            }

            cout << "Ingrese el valor del correlativo (SI = 1, NO = cualquier otro valor):" << endl;
            cout << ">> ";
            corr = Menu::leeString(stdin, corr);
            corrStr = *(new string(corr));
            cout << endl;

            cout << "Ingrese la cantidad de libros:" << endl;
            cout << ">> ";
            cantLib = Menu::leeString(stdin, cantLib);
            cantLibStr = *(new string(cantLib));
            cout << endl;

            posVendedor = -1;
            cout << "Ingrese el nombre del vendedor:" << endl;
            cout << ">> ";
            vendedor = Menu::leeString(stdin, vendedor);
            vendedorStr = *(new string(vendedor));
            cout << endl;
            posVendedor = this->encuentraUsuario(vendedorStr);
            while (posVendedor == -1) {
                cout << "Vendedor no encontrado. Intente de nuevo por favor." << endl;
                cout << "Ingrese el nombre del vendedor:" << endl;
                cout << ">> ";
                vendedor = Menu::leeString(stdin, vendedor);
                vendedorStr = *(new string(vendedor));
                cout << endl;
                posVendedor = this->encuentraUsuario(vendedorStr);
            }

            try {
                this->adminListas->agregarVenta(corrStr, posLibro, posCliente, posVendedor, cantLibStr);
                cout << "Se ha agregado la siguiente venta: " << endl << this->adminListas->getListaVentas()->recuperar(this->adminListas->getListaVentas()->longitud() -1)->getResumen() << endl;

            }
            catch (ErrorExcep &e) {
                if (e.getMotivo() == E_CANT_LIBROS)
                    cout << "La cantidad de libros introducida no es valida, intente de nuevo por favor." << endl;
                if (e.getMotivo() == E_SIN_STOCK)
                    cout << "No hay stock suficiente de libros para realizar la venta, intente de nuevo por favor." << endl;
            }
            opcionVendStr = "0";
        }

        if (opcionVendStr == "9")
            return ;
        cout << "Presione ENTER para volver al menu de vendedor" << endl;
        charTemp = Menu::leeString(stdin, charTemp);
        cout << endl;
    }
}

void Menu::menuListClientes() {
    char *opcionListCliente = NULL, *charTemp=NULL, *nombre=NULL;
    string nombreStr;
    int critOrden, i, pos;
    string opcionListClienteStr = "0";
    Cliente *clienteAct;
    ListaEnlazada<Cliente> *lClienteTemp;
    ListaEnlazada<Venta> *lVentasTemp;

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
        cout << "5. Mostrar compras de un determinado cliente" << endl;
        cout << "6. Volver" << endl << endl;
        cout << ">> ";
        opcionListCliente = Menu::leeString(stdin, opcionListCliente);
        opcionListClienteStr = *(new string(opcionListCliente));
        cout << "" << endl;

        if (this->verificarOpcion(opcionListClienteStr, 6)) {
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
        if (opcionListClienteStr == "5") {
            pos = -1;
            cout << "Ingrese el nombre del cliente o rut:" << endl;
            cout << ">> ";
            nombre = Menu::leeString(stdin, nombre);
            nombreStr = *(new string(nombre));
            cout << endl;
            pos = encuentraCliente(nombreStr);
            while (pos == -1) {
                cout << "Cliente no encontrado. Intente de nuevo por favor." << endl;
                cout << "Si desea volver atras presione ENTER en lugar de ingresar el nombre del cliente" << endl;
                cout << "Ingrese el nombre del cliente:" << endl;
                cout << ">> ";
                nombre = Menu::leeString(stdin, nombre);
                nombreStr = *(new string(nombre));
                cout << endl;
                if (nombreStr == ""){
                    opcionListClienteStr = "0";
                    break;
                }
                pos = encuentraCliente(nombreStr);
            }
            if (pos != -1) {
                lVentasTemp = this->adminListas->getListaVentas();
                clienteAct = this->adminListas->getListaClientes()->recuperar(pos);
                cout << "Se va a mostrar un listado de las compras del cliente: " <<endl;
                cout << clienteAct->getNombre() << endl;
                for (i = 0; i < lVentasTemp->longitud(); i++) {
                    if (lVentasTemp->recuperar(i)->getIdCliente() == clienteAct->getId())
                        cout << lVentasTemp->recuperar(i)->getResumen() << endl;
                }
                opcionListClienteStr = "0";
            }
        }
         if (opcionListClienteStr == "6") {
             return ;
         }
        cout << "Presione ENTER para volver al menu" << endl;
        charTemp = Menu::leeString(stdin, charTemp);
    }
}

void Menu::menuModCliente() {
    char *opModCliente=NULL, *nombre=NULL, *nvoNombre=NULL, *nvoRut=NULL, *nvaDir=NULL;
    char *nvoTel=NULL, *borrTel=NULL, *nvoEmail=NULL, *nvaEdad=NULL;
    string opModClienteStr = "0", nombreStr, nvoNombreStr;
    string nvoRutStr, nvaDirStr, nvoTelStr, borrTelStr, nvaEdadStr, nvoEmailStr, nrosTelStr;
    stringstream srtTel, streamTemp;
    bool nombreValido = false;
    int pos, id;

    while (nombreValido == false) {
        cout << "Ingrese el nombre o rut del cliente a modificar:" << endl;
        cout << ">> ";
        nombre = Menu::leeString(stdin, nombre);
        nombreStr = *(new string(nombre));
        cout << "" << endl;

        if ((pos = encuentraCliente(nombreStr)) != -1) {
            nombreValido = true;
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
        opModClienteStr = *(new string(opModCliente));
        cout << endl;

        if (this->verificarOpcion(opModClienteStr, 8)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "1") {
            cout << "Ingrese el nuevo nombre del cliente:";
            cout << endl;
            cout << ">> ";
            nvoNombre = Menu::leeString(stdin, nvoNombre);
            nvoNombreStr = *(new string(nvoNombre));
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "2") {
            cout << "Ingrese el nuevo rut del cliente:";
            cout << endl;
            cout << ">> ";
            nvoRut = Menu::leeString(stdin, nvoNombre);
            nvoRutStr = *(new string(nvoRut));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "3") {
            cout << "Ingrese la nueva direccion del cliente:";
            cout << endl;
            cout << ">> ";
            nvaDir = Menu::leeString(stdin, nvaDir);
            nvaDirStr = *(new string(nvaDir));
            nvoNombre = Menu::leeString(stdin, nvoNombre);
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "4") {
            cout << "Ingrese la nueva edad del cliente:";
            cout << endl;
            cout << ">> ";
            nvaEdad = Menu::leeString(stdin, nvaEdad);
            nvaEdadStr = *(new string(nvaEdad));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "5") { // REVISAR
            cout << "Ingrese el numero de telefono a agregar:";
            cout << ">> ";
            stringstream strTel;
            nvoTel = Menu::leeString(stdin, nvoTel);
            nvoTelStr = *(new string(nvoTel));
            srtTel << getNrosTelVend(pos) << nvoTelStr;
            nrosTelStr = strTel.str();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "6") { // REVISAR
            cout << "Ingrese el numero de telefono a eliminar:";
            cout << ">> ";
            stringstream strTel;
            borrTel = Menu::leeString(stdin, borrTel);
            borrTelStr = *(new string(borrTel));
            srtTel << getNrosTelVend(pos) << borrTelStr;
            nrosTelStr = strTel.str();
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvoEmailStr = adminListas->getListaClientes()->recuperar(pos)->getEmail();
            cout << endl;
            opModClienteStr = "0";
        }

        if (opModClienteStr == "7") {
            cout << "Ingrese el nuevo email del cliente:";
            cout << endl;
            cout << ">> ";
            nvoEmail = Menu::leeString(stdin, nvoEmail);
            nvoEmailStr = *(new string(nvoEmail));
            nvoNombreStr = adminListas->getListaClientes()->recuperar(pos)->getNombre();
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getRut();
            nvoRutStr = streamTemp.str(); streamTemp.str("");
            streamTemp << adminListas->getListaClientes()->recuperar(pos)->getEdad();
            nvaEdadStr = streamTemp.str(); streamTemp.str("");
            nvaDirStr = adminListas->getListaClientes()->recuperar(pos)->getDireccion();
            nrosTelStr = getNrosTelClient(pos);
            cout << endl;
            opModClienteStr = "0";
        }

        try {
            this->adminListas->editarCliente(id, nvoRutStr, nvoNombreStr, nvaEdadStr, nvaDirStr, nrosTelStr, nvoEmailStr);
            cout << "Se ha modificado el cliente." << endl;
            cout << endl;
            return ;
        }
        catch (ErrorExcep &e) {
            if (e.getMotivo() == E_NOMB_REP)
                cout << "El nombre del cliente esta repetido; intente ingresar otro nombre." << endl;
            if (e.getMotivo() == E_RUT)
                cout << "El rut del cliente no es valido; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_MAIL)
                cout << "El mail introducido no es valido; intente ingresar otro mail." << endl;
            if (e.getMotivo() == E_TEL_NO_EXISTE) // FALTA EXCEPCION
                cout << "El telefono no existe; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_TELEFONO) // FALTA EXCEPCION
                cout << "El telefono no es valido; intente de nuevo por favor." << endl;
            if (e.getMotivo() == E_EDAD)
                cout << "La edad del cliente no es valida; intente de nuevo por favor." << endl;
        }
    }
}

void Menu::menuModLibro(){
    char *opModLibro=NULL, *libro=NULL, *stock=NULL, *precio=NULL;
    int newStock, posLibro, newPrecio;
    Libro *libroTemp;
    string opModLibroStr = "0", libroStr, stockStr, precioStr;
    while (opModLibroStr == "0") {
        cout << "Que atributo desea modificar del libro? Escoja una opcion:" << endl;
        cout << endl;
        cout << "1. Stock" << endl;
        cout << "2. Precio" << endl;
        cout << endl;
        cout << ">> ";
        opModLibro = Menu::leeString(stdin, opModLibro);
        opModLibroStr = *(new string(opModLibro));
        cout << endl;
        if (this->verificarOpcion(opModLibroStr, 2)) {
            cout << "Opcion incorrecta. Intente de nuevo por favor.";
            cout << endl;
            opModLibroStr = "0";
        }
    }

    posLibro = -1;
    cout << "Ingrese el nombre del libro que desea modificar:" << endl;
    cout << ">> ";
    libro = Menu::leeString(stdin, libro);
    libroStr = *(new string(libro));
    cout << endl;
    posLibro = this->encuentraLibro(libroStr);
    while (posLibro == -1) {
        cout << "libro no encontrado. Intente de nuevo por favor." << endl;
        cout << "Ingrese el nombre del libro que desea modificar:" << endl;
        cout << "O presione ENTER para volver al menu" << endl;
        cout << ">> ";
        libro = Menu::leeString(stdin, libro);
        libroStr = *(new string(libro));
        cout << endl;
        if (libroStr == "")
            break ;
        posLibro = this->encuentraLibro(libroStr);
    }
    if (posLibro!=-1) {
        libroTemp = this->adminListas->getListaLibros()->recuperar(posLibro);
        if (opModLibroStr == "1") {
            cout << "Cual es el nuevo stock que tiene este libro: " << endl;
            cout << ">> ";
            stock = Menu::leeString(stdin, stock);
            stockStr = *(new string(stock));
            cout << endl;
            newStock = atoi(stockStr.c_str());
            while (newStock <= 0) {
                cout << "stock no valido, intentelo denuevo: " <<endl;
                cout << ">> ";
                stock = Menu::leeString(stdin, stock);
                stockStr = *(new string(stock));
                cout << endl;
                newStock = atoi(stockStr.c_str());
            }
            libroTemp->setStock(newStock);
            cout << "Se ha modificado el stock del libro: " << endl << libroTemp->getResumen() <<endl;
        }


        if (opModLibroStr == "2"){
            cout << "Cual es el nuevo precio que tiene este libro: " << endl;
            cout << ">> ";
            precio = Menu::leeString(stdin, precio);
            precioStr = *(new string(precio));
            cout << endl;
            newPrecio = atoi(precioStr.c_str());
            while (newPrecio <= 0) {
                cout << "precio no valido, intentelo denuevo: " <<endl;
                cout << ">> ";
                precio = Menu::leeString(stdin, precio);
                precioStr = *(new string(precio));
                cout << endl;
                newPrecio = atoi(precioStr.c_str());
            }
            libroTemp->setPrecio(newPrecio);
            cout << "Se ha modificado el precio del libro: " << endl << libroTemp->getResumen() <<endl;
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

