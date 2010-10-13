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
        throw new ErrorExcep(E_ISBN);
    }
    if ((intPaginas = atoi(paginas.c_str())) == 0){
        throw new ErrorExcep(E_PAGINAS);
    }
    if ((intPeso = atoi(peso.c_str())) == 0){
        throw new ErrorExcep(E_PESO);
    }
    if ((intPrecio = atoi(precio.c_str())) == 0){
        throw new ErrorExcep(E_PRECIO);
    }
    if ((intStock = atoi(stock.c_str())) == 0){
        throw new ErrorExcep(E_STOCK);
    }

    //Compruebo que no se repite el nombre del libro
    for (i = 0; i < this->listBaseLibros->longitud();i++){
        if (listBaseLibros->recuperar(i)->getNombre() == strNombre){
            throw new ErrorExcep(E_NOMB_REP);
        }
    }

    //Compruebo que no se repite el isbn con otro libro
    for (i = 0; i < this->listBaseLibros->longitud();i++){
            if (listBaseLibros->recuperar(i)->getIsbn() == intIsbn){
                throw new ErrorExcep(E_ISBN_REP);
            }
        }

    Libro *nuevoLibro = new Libro(Libro::getIdCont(), intIsbn, strNombre, strAutor, intPrecio, intPaginas, intPeso, intStock);
    this->listBaseLibros->agregar(nuevoLibro);
}

void AdminListas::agregarVenta(string correlativo, int posLibro, int posCliente, int posVendedor, string cantLibros, string montoTotal){
    int intCantLibros, intMontoTotal;
    if ((intCantLibros = atoi(cantLibros.c_str())) == 0)
        throw new ErrorExcep(E_CANT_LIBROS);

    if ((intMontoTotal = atoi(montoTotal.c_str())) == 0)
        throw new ErrorExcep(E_MONTO);

    Cliente *tempCliente = this->listBaseClientes->recuperar(posCliente);
    if (tempCliente == NULL)
        throw new ErrorExcep(E_POS_CLIENTE_NO_EXISTE);

    Vendedor *tempVendedor = this->listBaseVendedores->recuperar(posVendedor);
    if (tempVendedor ==NULL)
        throw new ErrorExcep(E_POS_VEND_NO_EXISTE);

    Libro *tempLibro = this->listBaseLibros->recuperar(posLibro);
    if (tempLibro == NULL)
        throw new ErrorExcep(E_POS_LIBRO_NO_EXISTE);

    //SE DEBE COMPROBAR QUE CANTLIBROS Y MONTO TOTAL SON VALORES ENTEROS
    bool boolCorrelativo;
    if (correlativo == "1"){
        boolCorrelativo = true;
    }
    else{
        boolCorrelativo = false;
    }

    Fecha *tempFecha = new Fecha(1, 2, 3);//se debe cambiar por la fecha y hora actuales

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
    if ((intEdad = atoi(rut.c_str())) == 0)
        throw new ErrorExcep(E_EDAD);
    if ((intRut = atoi(edad.c_str())) == 0)
        throw new ErrorExcep(E_RUT);
    for (i = 0; i < this->listBaseLibros->longitud();i++){
        if (this->listBaseLibros->recuperar(i)->getNombre() == strNombre){
            throw new ErrorExcep(E_NOMB_REP);
        }
    }

    string strTel;
    int intTel;
    int pos = 0; //WTF!
    ListaEstatica<int> *tempListTelefonos = new ListaEstatica<int>();

    pos = listTelefonos.find_first_not_of(' ',pos);
    while(listTelefonos.length() != 0){
        pos = listTelefonos.find_first_not_of(' ',pos);
        strTel = listTelefonos.substr(0,pos);
        intTel = atoi(strTel.substr(0,pos).c_str());
        tempListTelefonos->agregar(new int (intTel));
    }

    //Se debe comrpobar que edad y rut son convertibles a entero
    //Se debe comprobar que el rut no esté repetido y que el nombre no esté repetido

    Cliente *nuevoCliente = new Cliente(intRut, strNombre, intEdad, direccion, tempListTelefonos, email);
    this->listBaseClientes->agregar(nuevoCliente);
}

void AdminListas::agregarVendedor(string strRut, string nombre, string direccion){
    int rut;

    if ((rut = atoi(strRut.c_str())) == 0)
        throw new ErrorExcep(E_RUT);

    //Se debe comprobar que el rut y el nombre del vendedor no esten repetidos
    Vendedor *nuevoVendedor = new Vendedor(rut, nombre, direccion);
    this->listBaseVendedores->agregar(nuevoVendedor);
}


/****************************************
 *
 * Funciones adicionales
 *
 ****************************************/

void AdminListas::editarLibro(){

}

void AdminListas::editarVenta(){

}

void AdminListas::editarCliente(){

}

void AdminListas::editarVendedor(){

}

void AdminListas::eliminarLibro(int id){
    int pos = -1;
    for (int i; i < this->listBaseLibros->longitud(); i++){
        if (this->listBaseLibros->recuperar(i)->getId() == id){
            pos = i;
        }
    }
    this->listBaseLibros->eliminar(pos);
}

void AdminListas::eliminarVenta(int id){

}

void AdminListas::eliminarCliente(int id){

}

void AdminListas::eliminarVendedor(int id){

}

