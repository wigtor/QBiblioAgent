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
    // Pruebas Mateo

    // Ordenamiento de listas

    Cliente *c1 = new Cliente(3, 17691423, "Juan", 85, "Avenida", new ListaEstatica<int>(), "juan@gmail.com", new ListaEnlazada<int>());
    Cliente *c2 = new Cliente(5, 17643433, "Pedro", 21, "Calle", new ListaEstatica<int>(), "pedro@gmail.com", new ListaEnlazada<int>());
    Cliente *c3 = new Cliente(1, 21212121, "Diego", 43, "Depto.", new ListaEstatica<int>(), "diego@gmail.com", new ListaEnlazada<int>());

    ListaEstatica<Cliente> *L1 = new ListaEstatica<Cliente>();
    L1->agregar(c1);
    L1->agregar(c2);
    L1->agregar(c3);

    cout <<"L1 (ESTATICA) SEGUN ID"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getId()<<endl;

    L1->ordenar(-1); // Decreciente

    cout <<"L1 (ESTATICA) DECRECIENTE SEGUN ID"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getId()<<endl;

    L1->ordenar(1); // Creciente

    cout <<"L1 (ESTATICA) CRECIENTE SEGUN ID"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getId()<<endl;

    Cliente::setNumOrder(3);

    cout <<"L1 (ESTATICA) SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getNombre()<<endl;

    L1->ordenar(-1); // Decreciente

    cout <<"L1 (ESTATICA) DECRECIENTE SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getNombre()<<endl;

    L1->ordenar(1); // Creciente

    cout <<"L1 (ESTATICA) CRECIENTE SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L1->longitud(); i++)
        cout <<L1->recuperar(i)->getNombre()<<endl;

    ListaEnlazada<Cliente> *L2 = new ListaEnlazada<Cliente>();
    L2->agregar(c1);
    L2->agregar(c2);
    L2->agregar(c3);

    Cliente::setNumOrder(1);

    cout <<"L2 (ENLAZADA) ORIGINAL SEGUN ID"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getId()<<endl;

    L2->ordenar(-1); // Decreciente

    cout <<"L2 (ENLAZADA) DECRECIENTE SEGUN ID"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getId()<<endl;

    L2->ordenar(1); // Creciente

    cout <<"L2 (ENLAZADA) CRECIENTE SEGUN ID"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getId()<<endl;

    Cliente::setNumOrder(3);

    cout <<"L2 (ENLAZADA) SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getNombre()<<endl;

    L2->ordenar(-1); // Decreciente

    cout <<"L2 (ENLAZADA) DECRECIENTE SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getNombre()<<endl;

    L2->ordenar(1); // Creciente

    cout <<"L2 (ENLAZADA) CRECIENTE SEGUN NOMBRE"<<endl;
    for (int i = 0; i < L2->longitud(); i++)
        cout <<L2->recuperar(i)->getNombre()<<endl;

    return 0;
}

