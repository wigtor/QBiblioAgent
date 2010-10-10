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
    int ordenar(int critOrden); // critOrden: 1 = ascendente, -1 = descendente

private:
    //Se hizo un cambio en el diseño de listaEnlazada
    //El primer nodo cabecera no contiene datos y su puntero al nodoSiguiente es ahora el primer elemento,
    //Esto para seguir el diseño descrito en los pdf de la materia de EDA
    //Avisar por errores producidos con este cambio
    Nodo *cabecera;
    int cantidadElems;
};

#endif	/* LISTAENLAZADA_H */

