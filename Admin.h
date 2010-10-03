/* 
 * File:   Admin.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 14:29
 */

#ifndef ADMIN_H
#define	ADMIN_H

#include "Vendedor.h"
#include "Venta.h"
#include "ListaEnlazada.h"

using namespace std;

class Admin : public Vendedor{
public:
    //Otras Funciones
    int ingresaVendedor();
    int modificaVendedor(Vendedor *vendedor);
    int eliminaVendedor(Vendedor *vendedor);
    ListaEnlazada *verVentas(Vendedor *vendedor); //ventaSS, los vendedores hacen varias ventas
    string verInfoVendedor(Vendedor *vendedor);
    //////////////////////////////////
};


#endif	/* ADMIN_H */

