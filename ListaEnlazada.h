/*
 * File:   ListaEnlazada.h
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 11:50
 */

#ifndef LISTAENLAZADA_H
#define	LISTAENLAZADA_H 1

#include "Nodo.h"


class ListaEnlazada {
public:
    ListaEnlazada(void);
    ListaEnlazada(const ListaEnlazada& orig);
    ~ListaEnlazada();
    int agregar(void *elem);
    int insertar(void * elem, int pos);
    int localizar(void * elem);
    void *recuperar(int pos);
    int eliminar(int pos);
    int anular(void);
    int longitud(void);

private:
    Nodo *cabecera;
    int cantidadElems;
};

#endif	/* LISTAENLAZADA_H */

