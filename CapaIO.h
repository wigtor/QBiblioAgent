/* 
 * File:   CapaIO.h
 * Author: victor
 *
 * Created on 30 de septiembre de 2010, 21:51
 */

#ifndef CAPAIO_H
#define	CAPAIO_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ListaEstatica.h>
#include <ListaEnlazada.h>
#include <Cliente.h>
#include <Venta.h>
#include <Libro.h>
#include <Vendedor.h>

using namespace std;

class CapaIO {
public:
    CapaIO();
    CapaIO(const CapaIO& orig);
    virtual ~CapaIO();
    ListaEstatica *leeUsuarios();
    ListaEnlazada *leeVentas();
    ListaEnlazada *leeClientes();
    ListaEnlazada *leeLibros();
    int escribeUsuarios(ListaEstatica *listaUsuarios);
    int escribeVentas(ListaEnlazada *listaVentas);
    int escribeClientes(ListaEnlazada *listaClientes);
    int escribeLibros(ListaEnlazada *listaLibros);
    int leeIdUsuarios();
    int leeIdVentas();
    int leeIdClientes();
    int leeIdLibros();
    int escribeIdUsuarios(int contId);
    int escribeIdVentas(int contId);
    int escribeIdClientes(int contId);
    int escribeIdLibros(int contId);

private:
    static string archVentas;
    static string archClientes;
    static string archUsuarios;
    static string archLibros;
    static int VENTA;
    static int CLIENTE;
    static int USUARIO;
    static int LIBRO;
    fstream *fVentas;
    fstream *fClientes;
    fstream *fUsuarios;
    fstream *fLibros;
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

