/* 
 * File:   Cliente.h
 * Author: victor
 *
 * Created on 23 de septiembre de 2010, 9:51
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include<string>

#include "ListaEnlazada.h"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    int getId();
private:
    int id;
    int rut;
    ListaEnlazada comprasHechas;
};

#endif	/* CLIENTE_H */

