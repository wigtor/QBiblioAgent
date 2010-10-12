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
    //Comprobacion de repeticion por nombre
    for (int i = 0; i < this->listBaseLibros->longitud();i++){
        if (listBaseLibros->recuperar(i)->getNombre() == strNombre){
            //Error de repeticion
        }
    }
    int intIsbn, intPrecio, intPaginas, intPeso, intStock;
    intIsbn = atoi(isbn.c_str());
    intPaginas = atoi(paginas.c_str());
    intPeso = atoi(peso.c_str());
    intPrecio = atoi(precio.c_str());
    intStock = atoi(stock.c_str());
    //Se debe comprobar que son convertibles a entero

    //Libro::setIdCont(Libro::getIdCont()+1); no es necesario aumentar el idcont, se hace internamente en la clase del objeto
    Libro *nuevoLibro = new Libro(Libro::getIdCont(), intIsbn, strNombre, strAutor, intPrecio, intPaginas, intPeso, intStock);
    this->listBaseLibros->agregar(nuevoLibro);
}

void AdminListas::agregarVenta(bool boolCorrelativo, Libro *libro, Cliente *cliente, Vendedor *vendedor, string cantLibros, string montoTotal, Fecha *fecha){

    int intCantLibros = atoi(cantLibros.c_str()), intMontoTotal = atoi(montoTotal.c_str());
    //SE DEBE COMPROBAR QUE CANTLIBROS Y MONTO TOTAL SON VALORES ENTEROS
    Venta *nuevaVenta = new Venta(boolCorrelativo, libro->getId(), libro, cliente->getId(), cliente, vendedor->getId(), vendedor, intCantLibros, intMontoTotal, fecha);
    this->listBaseVentas->agregar(nuevaVenta);
    //referencio la venta en el cliente y en el vendedor
    cliente->addCompra(nuevaVenta);
    cliente->addIdCompra(nuevaVenta->getId());
    vendedor->addVenta(nuevaVenta);
    vendedor->addIdVenta(nuevaVenta->getId());
}

void AdminListas::agregarCliente(string rutStr, string nombre, string edadStr, string direccion, ListaEstatica<int> *telefonos, string email){

    int edad = atoi(rutStr.c_str()), rut = atoi(edadStr.c_str());
    //Se debe comrpobar que edad y rut son convertibles a entero
    //Se debe comprobar que el rut no esté repetido y que el nombre no esté repetido
    Cliente *nuevoCliente = new Cliente( rut, nombre, edad, direccion, telefonos, email);
    this->listBaseClientes->agregar(nuevoCliente);
}

void AdminListas::agregarVendedor(string rutStr, string nombre, string direccion){
    int rut;
    rut = atoi(rutStr.c_str());
    //Se debe comprobar que el rut y el nombre del vendedor no esten repetidos
    Vendedor *nuevoVendedor = new Vendedor( rut, nombre, direccion);
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

void AdminListas::eliminarLibro(){

}

void AdminListas::eliminarVenta(){

}

void AdminListas::eliminarCliente(){

}

void AdminListas::eliminarVendedor(){

}

