/*
 * File:   ListaEstatica.h
 * Author: victor
 *
 * Created on 14 de septiembre de 2010, 16:22
 */

#ifndef LISTAESTATICA_H
#define	LISTAESTATICA_H

#include <cstdlib>
using namespace std;
//#pragma GCC visibility push(default)


template <class tipo>
class ListaEstatica {
public:
    static int tamDefault;
    ListaEstatica();
    ListaEstatica(const ListaEstatica& orig);
    virtual ~ListaEstatica();
    int agregar(tipo *elem);
    int insertar(tipo * elem, int pos);
    int localizar(tipo * elem);
    tipo *recuperar(int pos);
    tipo *eliminar(int pos);
    int anular();
    int longitud();
    int ordenar(int critOrden); // critOrden: 1 = ascendente, -1 = descendente



private:
    //una lista de punteros
    tipo **datos;
    //un contador del último elemento agregado
    int cantidadElems;
    //un tamaño por defecto
};

template <class tipo>
int ListaEstatica<tipo>::tamDefault = 20;

template <class tipo>
ListaEstatica<tipo>::ListaEstatica() {
    this->datos = (tipo **)malloc(tamDefault * sizeof(tipo *));
    this->cantidadElems = 0;
}

template <class tipo>
ListaEstatica<tipo>::ListaEstatica(const ListaEstatica& orig) {
    this->datos = (tipo **)malloc(tamDefault * sizeof(tipo *));
    this->cantidadElems = orig.cantidadElems;
    int i;
    for (i = 0; i < this->cantidadElems; i++)
        this->datos[i] = orig.datos[i];
}

template <class tipo>
ListaEstatica<tipo>::~ListaEstatica() {
    free(this->datos);
    this->datos = NULL;
    this->cantidadElems = 0;
}


template <class tipo>
int ListaEstatica<tipo>::agregar(tipo *elem){
    return this->insertar(elem, this->longitud());
}

template <class tipo>
int ListaEstatica<tipo>::insertar(tipo *elem, int pos){
    //si la posicion no es válida o si la posicion es mas grande que la capacidad de la lista
    if ((pos < 0) || (pos > this->cantidadElems) || (pos > tamDefault))
        return 1;
    int i;
    //Recorro la lista de atras hacia adelante desplazando los elementos hacia la derecha
    for (i = this->cantidadElems; i > pos; i--)
    {   this->datos[i] = this->datos[i-1];
    }
    this->cantidadElems++;
    this->datos[pos] = elem;
    return 0;
}

template <class tipo>
int ListaEstatica<tipo>::localizar(tipo * elem){
    int i;
    for (i = 0; i < this->cantidadElems; i++)
        if (elem == this->datos[i])
            return i;
    //Retorno -1 si el elemento no es encontrado
    return -1;
}

template <class tipo>
tipo *ListaEstatica<tipo>::recuperar(int pos){
    if ((pos < 0) || (pos > this->cantidadElems))
        return NULL;
    else
        return this->datos[pos];
}

template <class tipo>
tipo *ListaEstatica<tipo>::eliminar(int pos){
    int i;
    if ((pos < 0) || (pos >= this->cantidadElems))
        return NULL;
    for (i = pos; i < this->cantidadElems; i++)
        this->datos[i] = this->datos[i+1];
    this->cantidadElems--;
    return static_cast<tipo *>(this->datos[i]);
}

template <class tipo>
int ListaEstatica<tipo>::anular(){
    free(this->datos);
    this->cantidadElems = 0;
    return 0;
}

template <class tipo>
int ListaEstatica<tipo>::longitud(){
    return this->cantidadElems;
}

template <class tipo>
int ListaEstatica<tipo>::ordenar(int critOrden) {  // critOrden: 1 = ascendente, -1 = descendente
    int n = this->cantidadElems;
    int m;
    tipo *datoTemp;
    if (critOrden == 1) { // Orden ascendente
        while (n > 1) {
            m = 0;
            for (int i = 0; i < n-1; i++) {
                if (*(datos[i]) > *(datos[i+1])) {
                    datoTemp = datos[i];
                    datos[i] = datos[i+1];
                    datos[i+1] = datoTemp;
                    m = i + 1;
                }
            }
            n = m;
        }
        return 1;
    }
    else if (critOrden == -1) { // Orden descendente
        while (n > 1) {
            m = 0;
            for (int i = 0; i < n-1; i++) {
                if (*(datos[i]) < *(datos[i+1])) {
                    datoTemp = datos[i];
                    datos[i] = datos[i+1];
                    datos[i+1] = datoTemp;
                    m = i + 1;
                }
            }
            n = m;
        }
        return 1;
    }
    return -1;
}

#endif	/* LISTAESTATICA_H */

