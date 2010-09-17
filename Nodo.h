/*
 * File:   Nodo.h
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 15:06
 */

#ifndef NODO_H
#define	NODO_H 1
#include <cstdlib>


class Nodo {
public:
    Nodo();
    Nodo(void *dato);
    virtual ~Nodo();
    void *getDato();
    void setDato(void *dato);
    Nodo *getNodoSig();
    void setNodoSig(Nodo *sig);

private:
    void *dato;
    Nodo *nodoSig;
};

#endif	/* NODO_H */

