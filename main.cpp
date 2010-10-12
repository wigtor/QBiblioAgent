/*
 * File:   main.cpp
 * Author: victor
 *
 * Created on 11 de septiembre de 2010, 20:38
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include "Nodo.h"
#include "ListaEnlazada.h"
#include "ListaEstatica.h"
#include "Vendedor.h"
#include "Venta.h"
#include "CapaIO.h"

using namespace std;


//#pragma GCC visibility push(default)

int main(int argc, char *argv[]) {
    //*
    // Pruebas entrada

    CapaIO *entrada = new CapaIO;
    int i;
    //Se setean los contadores de id iniciales:
    Libro::setIdCont(entrada->leeIdFile(CapaIO::LIBRO));
    Cliente::setIdCont(entrada->leeIdFile(CapaIO::CLIENTE));
    Vendedor::setIdCont(entrada->leeIdFile(CapaIO::USUARIO));
    Venta::setIdCont(entrada->leeIdFile(CapaIO::VENTA));

    // Libros
    ListaEnlazada<Libro> *libros = entrada->leeLibros();
    cout << "LIBROS:" << endl;

    for (i = 0; i < libros->longitud(); i++) {
        cout << "Autor: " << libros->recuperar(i)->getAutor() << endl;
        cout << "ID: " << libros->recuperar(i)->getId() << endl;
        cout << "ISBN: " << libros->recuperar(i)->getIsbn() << endl;
        cout << "Nombre: " << libros->recuperar(i)->getNombre() << endl;
        cout << "Paginas: " << libros->recuperar(i)->getPaginas() << endl;
        cout << "Peso: " << libros->recuperar(i)->getPeso() << endl;
        cout << "Precio: " << libros->recuperar(i)->getPrecio() << endl;
        cout << "Stock: " << libros->recuperar(i)->getStock() << endl;
        cout << "" << endl;
    }

    // Ventas

    ListaEnlazada<Venta> *ventas = entrada->leeVentas();
    cout << "VENTAS:" << endl;

    for (i = 0; i < ventas->longitud(); i++) {
        cout << "ID: " << ventas->recuperar(i)->getId() << endl;
        cout << "Correlativo: " << ventas->recuperar(i)->getCorrelativo() << endl;
        cout << "ID Libro: " << ventas->recuperar(i)->getIdLibro() << endl;
        cout << "ID Cliente: " << ventas->recuperar(i)->getIdCliente() << endl;
        cout << "Cantidad Libros: " << ventas->recuperar(i)->getCantidadLibros() << endl;
        cout << "Monto Total: " << ventas->recuperar(i)->getMontoTotal() << endl;
        cout << "ID Vendedor: " << ventas->recuperar(i)->getIdVendedor() << endl;
        cout << "" << endl;
    }

    // Clientes

    ListaEnlazada<Cliente> *clientes = entrada->leeClientes();
    cout << "CLIENTES:" << endl;

    for (i = 0; i<clientes->longitud(); i++) {
        cout << "ID: " << clientes->recuperar(i)->getId() << endl;
        cout << "RUT: " << clientes->recuperar(i)->getRut() << endl;
        cout << "Nombre: " << clientes->recuperar(i)->getNombre() << endl;
        cout << "Edad: " << clientes->recuperar(i)->getEdad() << endl;
        cout << "Direccion: " << clientes->recuperar(i)->getDireccion() << endl;
        for (int j = 0; j<clientes->recuperar(i)->getTelefonos()->longitud(); j++)
            cout << "Telefono " << j << " : " << clientes->recuperar(i)->getTelefonos()->recuperar(j) << endl;
            cout << "Email: " << clientes->recuperar(i)->getEmail() << endl;
        for (int j = 0; j<clientes->recuperar(i)->getListIdCompras()->longitud(); j++)
            cout << "ID Compra " << j << " : " << clientes->recuperar(i)->getListIdCompras()->recuperar(j) << endl;
            cout << "" << endl;
    }

    // Usuarios

    ListaEstatica<Vendedor> *usuarios = entrada->leeUsuarios();
    cout << "USUARIOS:" << endl;

    for (i = 0; i<usuarios->longitud(); i++) {
        cout << "ID: " << usuarios->recuperar(i)->getId() << endl;
        cout << "RUT: " << usuarios->recuperar(i)->getRut() << endl;
        cout << usuarios->recuperar(i)->getResumen();
        for (int j = 0; j<usuarios->recuperar(i)->getTelefonos()->longitud(); j++)
            cout << "Telefono " << j << " : " << *(usuarios->recuperar(i)->getTelefonos()->recuperar(j)) << endl;
        for (int j = 0; j<usuarios->recuperar(i)->getListIdVentas()->longitud(); j++)
            cout << "ID Venta " << j << " : " << *(usuarios->recuperar(i)->getListIdVentas()->recuperar(j)) << endl;
        cout << "" << endl;
    }

    //Se prueba la escritua de la capaIO
    entrada->escribeClientes(clientes);
    entrada->escribeLibros(libros);
    entrada->escribeUsuarios(usuarios);
    entrada->escribeVentas(ventas);

    return 0;
}

