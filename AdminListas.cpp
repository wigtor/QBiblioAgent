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

void AdminListas::agregarLibro(string strNombre, int intIsbn, string strAutor, int intPaginas, int intPeso, int intPrecio, int intStock){
    //Comprobacion de repeticion por nombre
    for (int i = 0; i < this->listBaseLibros->longitud();i++){
        if (listBaseLibros->recuperar(i)->getNombre() == strNombre){
            //Error de repeticion
        }
    }
    //Libro::setIdCont(Libro::getIdCont()+1); no es necesario aumentar el idcont, se hace internamente en la clase del objeto
    Libro *nuevoLibro = new Libro(Libro::getIdCont(), intIsbn, strNombre, strAutor, intPrecio, intPaginas, intPeso, intStock);
    this->listBaseLibros->agregar(nuevoLibro);
}

void AdminListas::agregarVenta(bool boolCorrelativo, Libro *libro, Cliente *cliente, Vendedor *vendedor, int cantLibros, int montoTotal, Fecha *fecha){
    Venta *nuevaVenta = new Venta(boolCorrelativo, libro->getId(), libro, cliente->getId(), cliente, vendedor->getId(), vendedor, cantLibros, montoTotal, fecha);
    this->listBaseVentas->agregar(nuevaVenta);
}

void AdminListas::agregarCliente(){

}

void AdminListas::agregarVendedor(){

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

