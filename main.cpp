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
//#include "Nodo.cpp"
//#include "ListaEnlazada.cpp"

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
        std::cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<std::endl;
    }

    //eliminando un elemento
    std::cout << "eliminando un elemento"<<std::endl;
    lst->eliminar(0);
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        std::cout <<"elemento N° " << i+1<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<std::endl;
    }

    //insertando un elemento
    std::cout << "insertando un elemento"<<std::endl;
    lst->insertar(new entero(24), 4);
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        std::cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<std::endl;
    }

    std::cout <<"ahora a probar la lista estática" <<std::endl;
    ListaEstatica *lst2 = new ListaEstatica();
    //copio los elementos de la lista enlazada a la lista estática
    for (i = 0; i < lst->longitud(); i++)
        lst2->insertar(lst->recuperar(i), i);

    //Mostrando los elementos de la lista estática
    for (i = 0;i<lst2->longitud();i++) {
        std::cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst2->recuperar(i)))->getVal() <<std::endl;
    }

    //elimino un elemento de la lista estática
    std::cout << "elimiando un elemento de la lista estática" << std::endl;
    lst2->eliminar(lst2->longitud());
    //Mostrando los elementos de la lista estática
    for (i = 0;i<lst2->longitud();i++) {
        std::cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst2->recuperar(i)))->getVal() <<std::endl;
    }


    //vaciando la lista
    std::cout <<"vaciando la lista"<<std::endl;
    lst->anular();
    //mostrando los elementos de listaEnlazada
    for (i=0;i<lst->longitud();i++) {
        std::cout <<"elemento N° " << i<< " de la lista: "<< (static_cast<entero *> (lst->recuperar(i)))->getVal() <<std::endl;
    }
    if (lst->longitud() == 0)
        std::cout <<"la lista está vacía"<<std::endl;

}

