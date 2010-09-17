/*
 * File:   ListaEnlazada.cpp
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 11:50
 */

#include "ListaEnlazada.h"

//#pragma GCC visibility push(default)

//Constructor de una lista vacia.
ListaEnlazada::ListaEnlazada(void) {
    this->cabecera = NULL;
    this->cantidadElems = 0;
}

ListaEnlazada::ListaEnlazada(const ListaEnlazada& orig) {
    this->cabecera = NULL;
    int i;
    Nodo *nodoTemp = new Nodo((orig.cabecera)->getDato());
    Nodo *nodoNew = NULL;
    Nodo *nodoOrig = orig.cabecera;
    for (i = 1; i < orig.cantidadElems; i++)
    {   nodoNew = new Nodo(nodoOrig->getDato());
        nodoTemp->setNodoSig(nodoNew);
        nodoOrig = nodoOrig->getNodoSig();
    }
    this->cantidadElems = orig.cantidadElems;
}

ListaEnlazada::~ListaEnlazada(void) {
    this->anular();
}

int ListaEnlazada::agregar(void *elem) {
    return this->insertar(elem, this->longitud());
}

int ListaEnlazada::insertar(void *elem, int pos){
    Nodo *nodoNuevo = new Nodo(elem);
    Nodo *nodoTemp = this->cabecera;
        //Se comprueba que el índice el válido
        if ((pos > this->cantidadElems) || (pos < 0))
            return 1;
        //Si se desea insertar en la primera posicion
        if (pos == 0)
        {   nodoNuevo->setNodoSig(this->cabecera);
            this->cabecera = nodoNuevo;
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

int ListaEnlazada::localizar(void *elem){
    int i;
    Nodo *nodoTemp = this->cabecera;
    for (i=0;i<this->cantidadElems;i++)
    {   //devuelve la posicion de la busqueda si el dato es el mismo(misma direccion de memoria). NO si tiene los mismos atributos!
        if (nodoTemp->getDato() == elem)
            return i;
        nodoTemp = nodoTemp->getNodoSig();
    }
    
    //si el elemento no es encontrado retorna -1
    return -1;
}

void *ListaEnlazada::recuperar(int pos){
    if ((pos > this->cantidadElems) || (pos < 0))
        return NULL;
    Nodo *temp = this->cabecera;
    int i;
    for(i=0;i<pos;i++)
    {   temp = temp->getNodoSig();
    }
    return temp->getDato();
}

int ListaEnlazada::eliminar(int pos) {
    Nodo *temp = this->cabecera;
    Nodo *anterior = NULL;
    if ((pos >= this->cantidadElems) || (pos < 0))
        return 1;
    int i = 0;
    while ((temp->getNodoSig()!=NULL) && (i < pos)){
        anterior = temp;
        temp = temp->getNodoSig();
        i++;
    }
    anterior = temp;
    temp = temp->getNodoSig();
    if (i==0) //en caso de ser el primer elemento el que se elimina
        this->cabecera = this->cabecera->getNodoSig();
    else {
	if (temp->getNodoSig() == NULL) //en caso del ser el ultimo elemento el que se elimina
            anterior->setNodoSig(NULL);
        else
            anterior->setNodoSig(temp->getNodoSig());
	}
    this->cantidadElems--;
    return 0;
}

int ListaEnlazada::anular(){
    Nodo *nodoTemp = this->cabecera;
    Nodo *nodoSig = NULL;
    int i;
    for (i=0; i<this->cantidadElems;i++)
    {   nodoSig = nodoTemp->getNodoSig();
        //libero memoria de cada nodo
        free(nodoTemp);
        nodoTemp = nodoSig;
    }
    this->cabecera = NULL;
    this->cantidadElems = 0;
    return 0;
}

int ListaEnlazada::longitud() {
    return this->cantidadElems;
}


