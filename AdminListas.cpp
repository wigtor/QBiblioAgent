/*
 * File:   AdminListas.h
 * Author: AirZs
 *
 * Creado el 11 de octubre de 2010, 22:11
 */

#include "AdminListas.h"

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/


AdminListas::AdminListas( ListaEnlazada<Venta> *listVentas, ListaEnlazada<Libro> *listLibros, ListaEstatica<Vendedor> *listVendedores, ListaEnlazada<Cliente> *listClientes){
    this->listBaseLibros = listLibros;
    this->listBaseVentas = listVentas;
    this->listBaseClientes = listClientes;
    this->listBaseVendedores =listVendedores;
}

AdminListas::~AdminListas(){

}

/****************************************
 *
 * Funciones Getters
 *
 ****************************************/

ListaEnlazada<Libro> *AdminListas::getListaLibros(){
    return this->listBaseLibros;
}

ListaEnlazada<Venta> *AdminListas::getListaVentas(){
    return this->listBaseVentas;
}

ListaEnlazada<Cliente> *AdminListas::getListaClientes(){
    return this->listBaseClientes;
}

ListaEstatica<Vendedor> *AdminListas::getListaVendedores(){
    return this->listBaseVendedores;
}


/****************************************
 *
 * Funciones Setters
 *
 ****************************************/

void AdminListas::agregarLibro(string strNombre, string isbn, string strAutor, string paginas, string peso, string precio, string stock){
    int i, intIsbn, intPrecio, intPaginas, intPeso, intStock;
    //Se debe comprobar que los datos introducidos son convertibles a entero
    if ((intIsbn = atoi(isbn.c_str())) == 0){
        throw ErrorExcep(E_ISBN);
    }
    if ((intPaginas = atoi(paginas.c_str())) == 0){
        throw ErrorExcep(E_PAGINAS);
    }
    if ((intPeso = atoi(peso.c_str())) == 0){
        throw ErrorExcep(E_PESO);
    }
    if ((intPrecio = atoi(precio.c_str())) == 0){
        throw ErrorExcep(E_PRECIO);
    }
    if ((intStock = atoi(stock.c_str())) == 0){
        throw ErrorExcep(E_STOCK);
    }

    //Compruebo que no se repite el nombre del libro
    for (i = 0; i < this->listBaseLibros->longitud();i++){
        if (listBaseLibros->recuperar(i)->getNombre() == strNombre){
            throw ErrorExcep(E_NOMB_REP);
        }
    }

    //Compruebo que no se repite el isbn con otro libro
    for (i = 0; i < this->listBaseLibros->longitud();i++){
            if (listBaseLibros->recuperar(i)->getIsbn() == intIsbn){
                throw ErrorExcep(E_ISBN_REP);
            }
        }

    Libro *nuevoLibro = new Libro(Libro::getIdCont(), intIsbn, strNombre, strAutor, intPrecio, intPaginas, intPeso, intStock);
    this->listBaseLibros->agregar(nuevoLibro);
}

void AdminListas::agregarVenta(string correlativo, int posLibro, int posCliente, int posVendedor, string cantLibros, string montoTotal){
    int intCantLibros, intMontoTotal;
    if ((intCantLibros = atoi(cantLibros.c_str())) == 0)
        throw ErrorExcep(E_CANT_LIBROS);

    if ((intMontoTotal = atoi(montoTotal.c_str())) == 0)
        throw ErrorExcep(E_MONTO);

    Cliente *tempCliente = this->listBaseClientes->recuperar(posCliente);
    if (tempCliente == NULL)
        throw ErrorExcep(E_POS_CLIENTE_NO_EXISTE);

    Vendedor *tempVendedor = this->listBaseVendedores->recuperar(posVendedor);
    if (tempVendedor ==NULL)
        throw ErrorExcep(E_POS_VEND_NO_EXISTE);

    Libro *tempLibro = this->listBaseLibros->recuperar(posLibro);
    if (tempLibro == NULL)
        throw ErrorExcep(E_POS_LIBRO_NO_EXISTE);

    bool boolCorrelativo;
    if (correlativo == "1"){
        boolCorrelativo = true;
    }
    else {
        boolCorrelativo = false;
    }

    time_t tSac = time(NULL);
    struct tm *tmP = localtime(&tSac);
    Fecha *tempFecha = new Fecha(tmP->tm_mday, tmP->tm_mon, tmP->tm_year);//se cambia por la fecha actual

    Venta *nuevaVenta = new Venta(boolCorrelativo, tempLibro->getId(), tempLibro, tempCliente->getId(), tempCliente, tempVendedor->getId(), tempVendedor, intCantLibros, intMontoTotal, tempFecha);
    this->listBaseVentas->agregar(nuevaVenta);

    //referencio la venta en el cliente y en el vendedor
    tempCliente->addCompra(nuevaVenta);
    tempCliente->addIdCompra(nuevaVenta->getId());
    tempVendedor->addVenta(nuevaVenta);
    tempVendedor->addIdVenta(nuevaVenta->getId());
}

void AdminListas::agregarCliente(string rut, string strNombre, string edad, string direccion, string listTelefonos, string email){
    int intEdad, intRut, i;
    Cliente *clienteTemp;
    if ((intEdad = atoi(edad.c_str())) == 0)
        throw ErrorExcep(E_EDAD);
    if ((intRut = atoi(rut.c_str())) == 0)
        throw ErrorExcep(E_RUT);
    for (i = 0; i < this->listBaseClientes->longitud();i++){
        clienteTemp = this->listBaseClientes->recuperar(i);
        if (clienteTemp->getNombre() == strNombre){
            throw ErrorExcep(E_NOMB_REP);
        }
        if (clienteTemp->getRut() == intRut)
            throw ErrorExcep(E_RUT_REP);
    }
    ListaEstatica<int> *tempListTelefonos = new ListaEstatica<int>();
        int intTel;
        int posInicio = 0, posFinal;
        listTelefonos = AdminListas::quitarEspacioExtremos(listTelefonos);
        posFinal = listTelefonos.find(" ", posInicio+1);
        while (listTelefonos != "") //REVISAR SI ESTA BUENO
        {   posFinal = listTelefonos.find(" ", posInicio+1);
            if ((intTel = atoi(listTelefonos.substr(posInicio, posFinal - posInicio).c_str())) == 0)
                throw ErrorExcep(E_TELEFONO);
            if (posFinal == -1)
                         listTelefonos = "";
            tempListTelefonos->agregar(new int (intTel));
            listTelefonos = listTelefonos.substr(posFinal - posInicio+1, listTelefonos.length()-(posFinal - posInicio-1));
        }

    Cliente *nuevoCliente = new Cliente(intRut, strNombre, intEdad, direccion, tempListTelefonos);
    if ((nuevoCliente->setEmail(email)) != 0)
            throw ErrorExcep(E_MAIL);
    this->listBaseClientes->agregar(nuevoCliente);
}

void AdminListas::agregarVendedor(string strRut, string strNombre, string direccion, string strEdad, string strEmail, string listTelefonos){
    int i, intRut, intEdad;
    Vendedor *vendedorTemp;
    if ((intRut = atoi(strRut.c_str())) == 0)
        throw ErrorExcep(E_RUT);
    if ((intEdad = atoi(strEdad.c_str())) == 0)
            throw ErrorExcep(E_EDAD);
    for (i = 0; i < this->listBaseVendedores->longitud();i++){
        vendedorTemp = this->listBaseVendedores->recuperar(i);
        if (vendedorTemp->getNombre() == strNombre){
            throw ErrorExcep(E_NOMB_REP);
        }
        if (vendedorTemp->getRut() == intRut)
            throw ErrorExcep(E_RUT_REP);
    }

    ListaEstatica<int> *tempListTelefonos = new ListaEstatica<int>();
    int intTel;
    int posInicio = 0, posFinal;
    listTelefonos = AdminListas::quitarEspacioExtremos(listTelefonos);
    posFinal = listTelefonos.find(" ", posInicio+1);
    while (listTelefonos != "") //REVISAR SI ESTA BUENO
    {   posFinal = listTelefonos.find(" ", posInicio+1);
        if ((intTel = atoi(listTelefonos.substr(posInicio, posFinal - posInicio).c_str())) == 0)
            throw ErrorExcep(E_TELEFONO);
        if (posFinal == -1)
                     listTelefonos = "";
        tempListTelefonos->agregar(new int (intTel));
        listTelefonos = listTelefonos.substr(posFinal - posInicio+1, listTelefonos.length()-(posFinal - posInicio-1));
    }

    Vendedor *nuevoVendedor = new Vendedor(intRut, strNombre, direccion);
    nuevoVendedor->setEdad(intEdad);

    if ((nuevoVendedor->setEmail(strEmail)) != 0)
        throw ErrorExcep(E_MAIL);
    nuevoVendedor->setListaTelefonos(tempListTelefonos);
    this->listBaseVendedores->agregar(nuevoVendedor);
}


/****************************************
 *
 * Funciones adicionales
 *
 ****************************************/

void AdminListas::editarLibro(int idOrig ,string precio, string stock){


}

void AdminListas::editarCliente(int idOrig, string rut, string nombre, string edad, string direccion, string listTelefonos, string email){

}

void AdminListas::editarVendedor(int idOrig, string strRut, string nombre, string direccion, string edad, string strEmail, string telefonos){

}

string AdminListas::quitarEspacioExtremos(string texto){
    int izq = 0, der = texto.length(), j;
    stringstream strStream;
    const char *textoC = texto.c_str();
    while (textoC[izq] == ' ') {
        izq++;
    }
    while (textoC[der-1] == ' ') {
        der--;
    }
    for (j = izq; j < der; j++)
        strStream << textoC[j];
    return strStream.str();
}

