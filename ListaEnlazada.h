/*
 * File:   ListaEnlazada.h
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 11:50
 */

#ifndef LISTAENLAZADA_H
#define	LISTAENLAZADA_H 1

#include "Nodo.h"
using namespace std;
//#pragma GCC visibility push(default)


template <class tipo>
class ListaEnlazada {
public:
    ListaEnlazada(void);
    ListaEnlazada(const ListaEnlazada& orig);
    virtual ~ListaEnlazada();
    int agregar(tipo *elem);
    int insertar(tipo *elem, int pos);
    int localizar(tipo *elem);
    tipo *recuperar(int pos);
    tipo *eliminar(int pos);
    int anular();
    int longitud();
    int ordenar(int critOrden); // critOrden: 1 = ascendente, -1 = descendente

private:
    //Se hizo un cambio en el diseño de listaEnlazada
    //El primer nodo cabecera no contiene datos y su puntero al nodoSiguiente es ahora el primer elemento,
    //Esto para seguir el diseño descrito en los pdf de la materia de EDA
    //Avisar por errores producidos con este cambio
    Nodo<tipo> *cabecera;
    int cantidadElems;
};


//Constructor de una lista vacia.
template <class tipo>
ListaEnlazada<tipo>::ListaEnlazada(void) {
    this->cabecera = new Nodo<tipo>(); //hago que la cabezera tenga un primer nodo sin datos
    this->cantidadElems = 0;
}

template <class tipo>
ListaEnlazada<tipo>::ListaEnlazada(const ListaEnlazada& orig) {
    //no probado si funciona.
    this->cabecera = new Nodo<tipo>();
    int i;
    Nodo<tipo> *nodoTemp = new Nodo<tipo>((orig.cabecera)->getDato());
    Nodo<tipo> *nodoNew = NULL;
    Nodo<tipo> *nodoOrig = orig.cabecera->getNodoSig();
    for (i = 1; i < orig.cantidadElems; i++)
    {   nodoNew = new Nodo<tipo>(nodoOrig->getDato());
        nodoTemp->setNodoSig(nodoNew);
        nodoOrig = nodoOrig->getNodoSig();
    }
    this->cantidadElems = orig.cantidadElems;
}

template <class tipo>
ListaEnlazada<tipo>::~ListaEnlazada() {
    this->anular();
}

template <class tipo>
int ListaEnlazada<tipo>::agregar(tipo *elem) {
    return this->insertar(elem, this->longitud());
}

template <class tipo>
int ListaEnlazada<tipo>::insertar(tipo *elem, int pos){
    Nodo<tipo> *nodoNuevo = new Nodo<tipo>(elem);
    Nodo<tipo> *nodoTemp = this->cabecera->getNodoSig();
        //Se comprueba que el índice el válido
        if ((pos > this->cantidadElems) || (pos < 0))
            return 1;
        //Si se desea insertar en la primera posicion
        if (pos == 0)
        {   nodoNuevo->setNodoSig(this->cabecera->getNodoSig());
            this->cabecera->setNodoSig(nodoNuevo);
        }
        else
        {   int i = 1;
            while (i < pos)
            {   nodoTemp = nodoTemp->getNodoSig();
                i++;
            }
            nodoNuevo->setNodoSig(nodoTemp->getNodoSig());
            nodoTemp->setNodoSig(nodoNuevo);
        }
    this->cantidadElems++;
    return 0;
}

template <class tipo>
int ListaEnlazada<tipo>::localizar(tipo *elem){
    int i;
    Nodo<tipo> *nodoTemp = this->cabecera->getNodoSig();
    for (i=0;i<this->cantidadElems;i++)
    {   //devuelve la posicion de la busqueda si el dato es el mismo(misma direccion de memoria). NO si tiene los mismos atributos!
        if (nodoTemp->getDato() == elem)
            return i;
        nodoTemp = nodoTemp->getNodoSig();
    }

    //si el elemento no es encontrado retorna -1
    return -1;
}

template <class tipo>
tipo *ListaEnlazada<tipo>::recuperar(int pos){
    if ((pos > this->cantidadElems) || (pos < 0))
        return NULL;
    Nodo<tipo> *temp = this->cabecera->getNodoSig();
    int i;
    for(i=0;i<pos;i++)
    {   temp = temp->getNodoSig();
    }
    return static_cast<tipo *>(temp->getDato());
}

template <class tipo>
tipo *ListaEnlazada<tipo>::eliminar(int pos) {
    Nodo<tipo> *temp = this->cabecera->getNodoSig();
    Nodo<tipo> *anterior = NULL;
    if ((pos >= this->cantidadElems) || (pos < 0))
        return NULL;
    int i = 0;
    while ((temp->getNodoSig()!=NULL) && (i < pos)){
        anterior = temp;
        temp = temp->getNodoSig();
        i++;
    }
    anterior = temp;
    temp = temp->getNodoSig();
    if (i==0) //en caso de ser el primer elemento el que se elimina
        this->cabecera->setNodoSig(this->cabecera->getNodoSig()->getNodoSig());
    else {
        if (temp->getNodoSig() == NULL) //en caso del ser el ultimo elemento el que se elimina
            anterior->setNodoSig(NULL);
        else
            anterior->setNodoSig(temp->getNodoSig());
        }
    this->cantidadElems--;
    return static_cast<tipo *>(temp->getDato());
}

template <class tipo>
int ListaEnlazada<tipo>::anular(){
    Nodo<tipo> *nodoTemp = this->cabecera->getNodoSig();
    Nodo<tipo> *nodoSig = NULL;
    int i;
    for (i=0; i<this->cantidadElems;i++)
    {   nodoSig = nodoTemp->getNodoSig();
        //libero memoria de cada nodo
        free(nodoTemp);
        nodoTemp = nodoSig;
    }
    this->cabecera = new Nodo<tipo>();
    this->cantidadElems = 0;
    return 0;
}

template <class tipo>
int ListaEnlazada<tipo>::longitud() {
    return this->cantidadElems;
}

template <class tipo>
int ListaEnlazada<tipo>::ordenar(int critOrden) {  // critOrden: 1 = ascendente, -1 = descendente
    int n = this->cantidadElems;
    int m;
    Nodo<tipo> *nodoAnt = this->cabecera;
    Nodo<tipo> *nodoSig = this->cabecera->getNodoSig();
    tipo *datoTemp;
    if (critOrden == 1) { // Orden ascendente
        while (n > 1) {
            m = 0;
            for (int i = 0; i < n-1; i++) {
                nodoAnt = nodoAnt->getNodoSig();
                nodoSig = nodoSig->getNodoSig();
                if (*(nodoAnt->getDato()) > *(nodoSig->getDato())) { // REVISAR
                    datoTemp = nodoAnt->getDato();
                    nodoAnt->setDato(nodoSig->getDato());
                    nodoSig->setDato(datoTemp);
                    m = i + 1;
                }
            }
            n = m;
            nodoAnt = this->cabecera;
            nodoSig = this->cabecera->getNodoSig();
        }
        return 1;
    }
    else if (critOrden == -1) { // Orden descendente
        while (n > 1) {
            m = 0;
            for (int i = 0; i < n-1; i++) {
                nodoAnt = nodoAnt->getNodoSig();
                nodoSig = nodoSig->getNodoSig();
                if (*(nodoAnt->getDato()) < *(nodoSig->getDato())) { // REVISAR
                    datoTemp = nodoAnt->getDato();
                    nodoAnt->setDato(nodoSig->getDato());
                    nodoSig->setDato(datoTemp);
                    m = i + 1;
                }
            }
            n = m;
            nodoAnt = this->cabecera;
            nodoSig = this->cabecera->getNodoSig();
        }
        return 1;
    }
    return -1;
}

#endif	/* LISTAENLAZADA_H */

