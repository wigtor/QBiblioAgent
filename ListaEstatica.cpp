/* 
 * File:   ListaEstatica.cpp
 * Author: victor
 * 
 * Created on 14 de septiembre de 2010, 16:22
 */

#include "ListaEstatica.h"
#include <cstdlib>

int ListaEstatica::tamDefault = 10;

ListaEstatica::ListaEstatica() {
    this->datos = (void **)malloc(ListaEstatica::tamDefault * sizeof(void *));
    this->cantidadElems = 0;
}

ListaEstatica::ListaEstatica(const ListaEstatica& orig) {
    this->datos = (void **)malloc(ListaEstatica::tamDefault * sizeof(void *));
    this->cantidadElems = orig.cantidadElems;
    int i;
    for (i = 0; i < this->cantidadElems; i++)
        this->datos[i] = orig.datos[i];
}

ListaEstatica::~ListaEstatica() {
    free(this->datos);
    this->datos = NULL;
    this->cantidadElems = 0;
}

int ListaEstatica::agregar(void *elem){
    return insertar(elem, this->longitud());
}
int ListaEstatica::insertar(void * elem, int pos){
    //si la posicion no es válida o si la posicion es mas grande que la capacidad de la lista
    if ((pos < 0) || (pos > this->cantidadElems) || (pos > ListaEstatica::tamDefault))
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
int ListaEstatica::localizar(void * elem){
    int i;
    for (i = 0; i < this->cantidadElems; i++)
        if (elem == this->datos[i])
            return i;
    //Retorno -1 si el elemento no es encontrado
    return -1;
}
void *ListaEstatica::recuperar(int pos){
    if ((pos < 0) || (pos > this->cantidadElems))
        return NULL;
    else
        return this->datos[pos];
}
int ListaEstatica::eliminar(int pos){
    int i;
    if ((pos < 0) || (pos >= this->cantidadElems))
        return 1;
    for (i = pos; i < this->cantidadElems; i++)
        this->datos[i] = this->datos[i+1];
    this->cantidadElems--;
    return 0;
}
int ListaEstatica::anular(void){
    free(this->datos);
    this->cantidadElems = 0;
    return 0;
}
int ListaEstatica::longitud(void){
    return this->cantidadElems;
}

int ListaEstatica::ordenar(int critOrden) {  // critOrden: 1 = ascendente, -1 = descendente
    int n = this->cantidadElems;
    int m;
    void *datoTemp;
    if (critOrden == 1) { // Orden ascendente
        while (n > 1) {
            m = 0;
            for (int i = 0; i < n-1; i++) {
                if (datos[i] > datos[i+1]) { // REVISAR
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
                if (datos[i] < datos[i+1]) { // REVISAR
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