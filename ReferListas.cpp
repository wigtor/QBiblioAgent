/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */

#include "ReferListas.h"

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

ReferListas(const ReferListas& orig){

}

~ReferListas(){

}

/****************************************
 *
 * Funciones Adicionales (Public)
 *
 ****************************************/

int ReferListas::crearReferencias(){
    int cont = 0;
    cont += crearReferencias(listaVentas);
    cont += crearReferencias(listaLibros);
    cont += crearReferencias(listaVendedores);
    cont += crearReferencias(listaClientes);
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
    for (int i = 0; i < this->listVentas.longitud()){
        actual = listVentas.recuperar(i);

    }
}

int crearReferencias(ListaEnlazada<Libro> listLibros);
int crearReferencias(ListaEstatica<Vendedor> listVendedores);
int crearReferencias(ListaEnlazada<Cliente> listClientes);
