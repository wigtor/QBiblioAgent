/*
 * File:   Nodo.h
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 15:06
 */

#ifndef NODO_H
#define	NODO_H 1

#include <cstdlib>

using namespace std;
//#pragma GCC visibility push(default)

template <class tipo>
class Nodo {
public:
    Nodo();
    Nodo(tipo *dato);
    virtual ~Nodo();
    tipo *getDato();
    void setDato(tipo *dato);
    Nodo<tipo> *getNodoSig();
    void setNodoSig(Nodo<tipo> *sig);

private:
    tipo *dato;
    Nodo<tipo> *nodoSig;
};

template <class tipo>
Nodo<tipo>::Nodo() {
    this->dato = NULL;
    this->nodoSig = NULL;
}

template <class tipo>
Nodo<tipo>::Nodo(tipo *_dato) {
    this->dato = _dato;
    this->nodoSig = NULL;
}

template <class tipo>
Nodo<tipo>::~Nodo() {

}

template <class tipo>
tipo *Nodo<tipo>::getDato() {
    return this->dato;
}

template <class tipo>
void Nodo<tipo>::setDato(tipo *_dato) {
    this->dato = _dato;
}

template <class tipo>
Nodo<tipo> *Nodo<tipo>::getNodoSig() {
    return this->nodoSig;
}

template <class tipo>
void Nodo<tipo>::setNodoSig(Nodo<tipo> *sig) {
    this->nodoSig = sig;
}

#endif	/* NODO_H */

