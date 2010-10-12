/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */


#ifndef REFERLISTAS_H
#define REFERLISTAS_H

#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Venta.h"
#include "Libro.h"
#include "Vendedor.h"
#include "Cliente.h"

class ReferListas{
public:
    //Iniciadores y obligatorios
    ReferListas(ListaEnlazada<Venta> *listaVentas, ListaEnlazada<Libro> *listaLibros, ListaEstatica<Vendedor> *listaVendedores, ListaEnlazada<Cliente> *listaClientes);
    virtual ~ReferListas();

    //Otras Funciones
    int crearReferencias();

private:
    //Atributos
    ListaEnlazada<Venta> *listVentas;
    ListaEnlazada<Libro> *listLibros;
    ListaEstatica<Vendedor> *listVendedores;
    ListaEnlazada<Cliente> *listClientes;

    //Otras Funciones
    int crearReferenciasVentas();
    int crearReferenciasVendedores();
    int crearReferenciasClientes();

    //////////////////////////////////
};

#endif	/* REFERLISTAS_H */
