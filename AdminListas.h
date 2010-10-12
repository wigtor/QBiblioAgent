/*
 * File:   AdminListas.h
 * Author: AirZs
 *
 * Creado el 11 de octubre de 2010, 22:11
 */

#ifndef ADMINLISTAS_H
#define ADMINLISTAS_H

#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Venta.h"
#include "Libro.h"
#include "Vendedor.h"

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
    void agregarVenta(bool boolCorrelativo, Libro *libro, Cliente *cliente, Vendedor *vendedor, string cantLibros, string montoTotal, Fecha *fecha);
    void agregarCliente(string rut, string nombre, string edad, string direccion, ListaEstatica<int> *telefonos, string email);
    void agregarVendedor(string rutStr, string nombre, string direccion);
    //////////////////////////////////

    //Funciones adicionales
    void editarLibro();
    void editarVenta();
    void editarCliente();
    void editarVendedor();

    void eliminarLibro();
    void eliminarVenta();
    void eliminarCliente();
    void eliminarVendedor();
    //////////////////////////////////

private:
    ListaEnlazada<Libro> *listBaseLibros;
    ListaEnlazada<Venta> *listBaseVentas;
    ListaEnlazada<Cliente> *listBaseClientes;
    ListaEstatica<Vendedor> *listBaseVendedores;

};

#endif // ADMINLISTAS_H
