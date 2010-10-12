/*
 * File:   main.cpp
 * Author: victor
 *
 * Created on 11 de septiembre de 2010, 20:38
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include "CapaIO.h"
#include "ListaEnlazada.h"
#include "ListaEstatica.h"
#include "Vendedor.h"
#include "Venta.h"
#include "Cliente.h"
#include "Admin.h"
#include "Libro.h"
#include "ReferListas.h"
#include "AdminListas.h"
#include "Menu.h"

using namespace std;


//#pragma GCC visibility push(default)

int main(int argc, char *argv[]) {

    //Se crea una instancia de la clase CapaIO
    CapaIO *entrada = new CapaIO();

    //Se setean los contadores de id iniciales desde los ficheros de entrada:
    Libro::setIdCont(entrada->leeIdFile(CapaIO::LIBRO));
    Cliente::setIdCont(entrada->leeIdFile(CapaIO::CLIENTE));
    Vendedor::setIdCont(entrada->leeIdFile(CapaIO::USUARIO));
    Venta::setIdCont(entrada->leeIdFile(CapaIO::VENTA));

    //Se leen las listas de objetos desde los ficheros de entrada
    ListaEnlazada<Libro> *listaLibros = entrada->leeLibros();
    ListaEnlazada<Venta> *listaVentas = entrada->leeVentas();
    ListaEnlazada<Cliente> *listaClientes = entrada->leeClientes();
    ListaEstatica<Vendedor> *listaVendedores = entrada->leeUsuarios();

    //Se llama la clase ReferListas para realizar las conexiones entre objetos de las listas
    ReferListas *referenciador = new ReferListas( listaVentas, listaLibros, listaVendedores, listaClientes);
    referenciador->crearReferencias();

    //Se instancia el administrador de listas
    AdminListas *administradorListas = new AdminListas( listaVentas, listaLibros, listaVendedores, listaClientes);

    //Se ejecuta la interfaz de usuario
    Menu *interfazUsuario = new Menu(administradorListas);
    interfazUsuario->ejecutar();

    //Se escriben las listas al finalizar la ejecución del programa
    entrada->escribeClientes(listaClientes);
    entrada->escribeLibros(listaLibros);
    entrada->escribeUsuarios(listaVendedores);
    entrada->escribeVentas(listaVentas);

    cout << "Presione una tecla para salir"<< endl;
    char *unChar = NULL;
    interfazUsuario->leeString(stdin, unChar);
    return 0;
}

