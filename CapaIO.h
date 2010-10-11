/* 
 * File:   CapaIO.h
 * Author: victor
 *
 * Created on 30 de septiembre de 2010, 21:51
 */

#ifndef CAPAIO_H
#define	CAPAIO_H

#include <string>
#include <sstream>
#include <stdio.h>
#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Venta.h"
#include "Libro.h"
#include "Vendedor.h"

using namespace std;
//#pragma GCC visibility push(default)

class CapaIO {
public:
    CapaIO();
    virtual ~CapaIO();
    ListaEstatica<Vendedor> *leeUsuarios();
    ListaEnlazada<Venta> *leeVentas();
    ListaEnlazada<Cliente> *leeClientes();
    ListaEnlazada<Libro> *leeLibros();
    int leeIdFile(int tipoId);
    int escribeUsuarios(ListaEstatica<Vendedor> *listaUsuarios);
    int escribeVentas(ListaEnlazada<Venta> *listaVentas);
    int escribeClientes(ListaEnlazada<Cliente> *listaClientes);
    int escribeLibros(ListaEnlazada<Libro> *listaLibros);

    static int VENTA;
    static int CLIENTE;
    static int USUARIO;
    static int LIBRO;

private:
    static string archVentas;
    static string archClientes;
    static string archUsuarios;
    static string archLibros;

    FILE *fUsuarios;
    FILE *fVentas;
    FILE *fLibros;
    FILE *fClientes;
    FILE *file;
    int stringToId(string linea);
    Venta *stringToVenta(string linea);
    Cliente *stringToCliente(string linea);
    Vendedor *stringToVendedor(string linea);
    Libro *stringToLibro(string linea);
    string idToString(int id, int tipoId);
    string ventaToString(Venta *venta);
    string clienteToString(Cliente *cliente);
    string vendedorToString(Vendedor *vendedor);
    string libroToString(Libro *libro);

};

#endif	/* CAPAIO_H */

