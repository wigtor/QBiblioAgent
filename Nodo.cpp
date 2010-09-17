/*
 * File:   Nodo.cpp
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 15:06
 */

#include "Nodo.h"

//#pragma GCC visibility push(default)


Nodo::Nodo() {
    this->dato = NULL;
    this->nodoSig = NULL;
}

Nodo::Nodo(void *_dato) {
    this->dato = _dato;
    this->nodoSig = NULL;
}


Nodo::~Nodo() {

}

void *Nodo::getDato() {
    return this->dato;
}

void Nodo::setDato(void *_dato) {
    this->dato = _dato;
}

Nodo *Nodo::getNodoSig() {
    return this->nodoSig;
}

void Nodo::setNodoSig(Nodo *sig) {
    this->nodoSig = sig;
}
