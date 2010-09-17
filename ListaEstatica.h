/* 
 * File:   ListaEstatica.h
 * Author: victor
 *
 * Created on 14 de septiembre de 2010, 16:22
 */

#ifndef LISTAESTATICA_H
#define	LISTAESTATICA_H

class ListaEstatica {
public:
    ListaEstatica();
    ListaEstatica(const ListaEstatica& orig);
    virtual ~ListaEstatica();
    static int tamDefault;
    int agregar(void *elem);
    int insertar(void * elem, int pos);
    int localizar(void * elem);
    void *recuperar(int pos);
    int eliminar(int pos);
    int anular(void);
    int longitud(void);
private:
    //una lista de punteros
    void **datos;
    //un contador del último elemento agregado
    int cantidadElems;
    //un tamaño por defecto
};

#endif	/* LISTAESTATICA_H */

