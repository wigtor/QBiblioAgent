/*
 * File:   Admin.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 14:29
 */

#include "Admin.h"

/****************************************
 *
 * Funciones Adicionales
 *
 ****************************************/

int ingresaVendedor(int intRut){
    Vendedor* vendedorTemp;
    vendedorTemp = new Vendedor(intRut);
    // INCOMPLETA faltan detalles

    return 0;
}

int Admin::modificaVendedor(Vendedor *vendedor){
    return 0;
}

int Admin::eliminaVendedor(Vendedor *vendedor){
    return 0;
}

ListaEnlazada<Vendedor> *Admin::verVentas(Vendedor *vendedor){
    return NULL;
}

string Admin::verInfoVendedor(Vendedor *vendedor){
    return "";
}
