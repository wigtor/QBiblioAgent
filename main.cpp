/*
 * File:   main.cpp
 * Author: victor
 *
 * Created on 11 de septiembre de 2010, 20:38
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include "ListaEnlazada.h"
#include "ListaEstatica.h"
#include "Venta.h"
#include "CapaIO.h"
#include "ReferListas.h"

using namespace std;

#pragma GCC visibility push(default)

int main(int argc, char *argv[]) {
    //*
    // Pruebas AirZs

    // Vendedor

    int a;
    Vendedor *vendPrueba1 = new Vendedor(176715804);
    vendPrueba1->setNombre("Alexis");
    vendPrueba1->setDireccion("Una direccion");
    vendPrueba1->setEdad(20);
    cout << vendPrueba1->setEmail("air_memories@etc...");

    cout << vendPrueba1->getResumen();

    Vendedor *vendPrueba2 = new Vendedor(173143141);
    vendPrueba2->setNombre("Olga");
    vendPrueba2->setDireccion("Otra direccion");
    vendPrueba2->setEdad(21);
    vendPrueba2->setEmail("olgagajardo@etc...");


    cout << vendPrueba2->getResumen();

    cout << endl;

    if (vendPrueba2 < vendPrueba1){
        cout << vendPrueba2->getNombre() << "es Menor"<<endl;
    }
    else{
        cout << vendPrueba1->getNombre() << "es Menor"<<endl;
    }


    cout << "probando nuevamente la lista estatica" << endl;

    ListaEnlazada<int> lista1 = *(new ListaEnlazada<int>());
    for (a = 1; a<=10; a++)
    {   lista1.agregar(new int(a*10));

    }

    for (a = 1; a<=10; a++)
    {   cout << "mostrando el elemento con id: " << *(static_cast<int *>(lista1.recuperar(a-1))) << endl;

    }

    CapaIO *capaIO = new CapaIO();
    a = capaIO->leeIdUsuarios();

    cout << "valor leido de id: " << a<< endl;

    //cin >> a;

    return 0;
}

