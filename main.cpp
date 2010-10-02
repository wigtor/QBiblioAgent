/*
 * File:   main.cpp
 * Author: victor
 *
 * Created on 11 de septiembre de 2010, 20:38
 */

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Nodo.h"
#include "entero.h"
#include "ListaEnlazada.h"
#include "ListaEstatica.h"

using namespace std;


//#pragma GCC visibility push(default)

int main(int argc, char *argv[]) {
    //probando la clase listaEnlazada
    int i;
    ListaEnlazada *lst = new ListaEnlazada();
    entero *num;

    //agregando elementos a la ListEnlazada
    for (i=0;i<10;i++) {
        num = new entero(10+i);
        lst->agregar(num);
    }

    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<endl;
    }

    //eliminando un elemento
    cout << "eliminando un elemento"<<endl;
    lst->eliminar(0);
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        cout <<"elemento N° " << i+1<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<endl;
    }

    //insertando un elemento
    cout << "insertando un elemento"<<endl;
    lst->insertar(new entero(24), 4);
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<endl;
    }

    cout <<"ahora a probar la lista estática" <<endl;
    ListaEstatica *lst2 = new ListaEstatica();
    //copio los elementos de la lista enlazada a la lista estática
    for (i = 0; i < lst->longitud(); i++)
        lst2->insertar(lst->recuperar(i), i);

    //Mostrando los elementos de la lista estática
    for (i = 0;i<lst2->longitud();i++) {
        cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst2->recuperar(i)))->getVal() <<endl;
    }

    //elimino un elemento de la lista estática
    cout << "elimiando un elemento de la lista estática" << endl;
    lst2->eliminar(lst2->longitud());
    //Mostrando los elementos de la lista estática
    for (i = 0;i<lst2->longitud();i++) {
        cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst2->recuperar(i)))->getVal() <<endl;
    }
    
    //vaciando la lista
    cout <<"vaciando la lista"<<endl;
    lst->anular();
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<endl;
    }
    if (lst->longitud() == 0)
        cout <<"la lista está vacía"<<endl;
}

