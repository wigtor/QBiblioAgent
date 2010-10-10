/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */


#ifndef REFERLISTAS_H
#define REFERLISTAS_H

#import "ListaEstatica.h"
#import "ListaEnlazada.h"
#import "Venta.h"
#import "Libro.h"
#import "Vendedor.h"
#import "Cliente.h"

class ReferListas{
public:
    //Iniciadores y obligatorios
    ReferListas(ListaEnlazada<Venta> *listaVentas, ListaEnlazada<Libro> *listaLibros, ListaEstatica<Vendedor> *listaVendedores, ListaEnlazada<Cliente> *listaClientes);
    ReferListas(const ReferListas& orig);
    ~ReferListas();

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
    int crearReferenciasLibros();
    int crearReferenciasVendedores();
    int crearReferenciasClientes();

    //////////////////////////////////
};

#endif // REFERLISTAS_H
