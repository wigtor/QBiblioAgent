/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */

#include "ReferListas.h"

using namespace std;

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

ReferListas::ReferListas(ListaEnlazada<Venta> *listaVentas, ListaEnlazada<Libro> *listaLibros, ListaEstatica<Vendedor> *listaVendedores, ListaEnlazada<Cliente> *listaClientes){
    this->listVentas = listaVentas;
    this->listLibros = listaLibros;
    this->listVendedores = listaVendedores;
    this->listClientes = listaClientes;
}

//ReferListas::ReferListas(const ReferListas& orig){
//
//}

ReferListas::~ReferListas(){

}

/****************************************
 *
 * Funciones Adicionales (Public)
 *
 ****************************************/

int ReferListas::crearReferencias(){
    int cont = 0;
    cont += this->crearReferenciasClientes();
    cont += this->crearReferenciasLibros();
    cont += this->crearReferenciasVendedores();
    cont += this->crearReferenciasVentas();
    if (cont != 4){
        return -1;
    }
    return 0;
}

/****************************************
 *
 * Funciones Adicionales (Private)
 *
 ****************************************/

int ReferListas::crearReferenciasVentas(){
    Venta *actual;
    for (int i = 0; i < this->listVentas->longitud(); i++){
        actual = listVentas->recuperar(i);

    }

    return 1;
}

int ReferListas::crearReferenciasLibros(){

    return 1;
}

int ReferListas::crearReferenciasVendedores(){

    return 1;
}

int ReferListas::crearReferenciasClientes(){

    return 1;
}

