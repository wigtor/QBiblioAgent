/* 
 * File:   Admin.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 14:29
 */

#ifndef ADMIN_H
#define	ADMIN_H

#include "Vendedor.h"
#include "Venta.h"
#include "ListaEnlazada.h"

using namespace std;
//#pragma GCC visibility push(default)


class Admin : public Vendedor{
public:
    //Otras Funciones
    int ingresaVendedor();
    int modificaVendedor(Vendedor *vendedor);
    int eliminaVendedor(Vendedor *vendedor);
    ListaEnlazada<Vendedor> *verVentas(Vendedor *vendedor);
    string verInfoVendedor(Vendedor *vendedor);
    //////////////////////////////////
};


#endif	/* ADMIN_H */

