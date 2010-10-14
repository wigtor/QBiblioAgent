/*
 * File:   AdminListas.h
 * Author: AirZs
 *
 * Creado el 11 de octubre de 2010, 22:11
 */

#ifndef ADMINLISTAS_H
#define ADMINLISTAS_H

#include <ctime>
#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Venta.h"
#include "Libro.h"
#include "Vendedor.h"
#include "ErrorExcep.h"

class AdminListas{

public:
    //Iniciadores y obligatorios
    AdminListas( ListaEnlazada<Venta> *listVentas, ListaEnlazada<Libro> *listLibros, ListaEstatica<Vendedor> *listVendedor, ListaEnlazada<Cliente> *listClientes);
    virtual ~AdminListas();
    //////////////////////////////////

    //Getters
    ListaEnlazada<Libro> *getListaLibros();
    ListaEnlazada<Venta> *getListaVentas();
    ListaEnlazada<Cliente> *getListaClientes();
    ListaEstatica<Vendedor> *getListaVendedores();
    //////////////////////////////////

    //Setters
    void agregarLibro(string strNombre, string isbn, string strAutor, string paginas, string peso, string precio, string stock);
    void agregarVenta(string boolCorrelativo, int posLibro, int posCliente, int posVendedor, string cantLibros);
    void agregarCliente(string rut, string nombre, string edad, string direccion, string listTelefonos, string email);
    void agregarVendedor(string strRut, string nombre, string direccion, string edad, string strEmail, string telefonos);
    //////////////////////////////////

    //Funciones adicionales
    void editarLibro(int idOrig ,string precio, string stock);
    void editarCliente(int idOrig, string rut, string nombre, string edad, string direccion, string listTelefonos, string email);
    void editarVendedor(int idOrig, string strRut, string nombre, string direccion, string edad, string strEmail, string telefonos);
    string quitarEspacioExtremos(string texto);
    //////////////////////////////////

private:
    ListaEnlazada<Libro> *listBaseLibros;
    ListaEnlazada<Venta> *listBaseVentas;
    ListaEnlazada<Cliente> *listBaseClientes;
    ListaEstatica<Vendedor> *listBaseVendedores;

};

#endif // ADMINLISTAS_H
