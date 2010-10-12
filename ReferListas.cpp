/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */

#include "ReferListas.h"

using namespace std;

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

ReferListas::ReferListas(ListaEnlazada<Venta> *listaVentas, ListaEnlazada<Libro> *listaLibros, ListaEstatica<Vendedor> *listaVendedores, ListaEnlazada<Cliente> *listaClientes){
    this->listVentas = listaVentas;
    this->listLibros = listaLibros;
    this->listVendedores = listaVendedores;
    this->listClientes = listaClientes;
}

ReferListas::~ReferListas(){

}

/****************************************
 *
 * Funciones Adicionales (Public)
 *
 ****************************************/

int ReferListas::crearReferencias(){
    int cont = 0;
    cont += this->crearReferenciasClientes();
    cont += this->crearReferenciasVendedores();
    cont += this->crearReferenciasVentas();
    if (cont != 3){
        return -1;
    }
    return 0;
}

/****************************************
 *
 * Funciones Adicionales (Private)
 *
 ****************************************/

int ReferListas::crearReferenciasVentas(){
    Venta *ventActual;
    Cliente *cActual;
    Vendedor *vendActual;
    int id, valid=-1;
    for (int i = 0; i < this->listVentas->longitud(); i++){
        ventActual = this->listVentas->recuperar(i);
        id = ventActual->getIdCliente();
        for (int j = 0; j < this->listClientes->longitud();j++){
            cActual = listClientes->recuperar(j);
            if (cActual->getId() == id){
                ventActual->setCliente(cActual);
                valid -= 2;
                break;
            }
        }
        id = ventActual->getIdVendedor();
        for (int k = 0; k < this->listVendedores->longitud();k++){
            vendActual = listVendedores->recuperar(k);
            if (vendActual->getId() == id){
                ventActual->setVendedor(vendActual);
                valid--;
                break; //Si no quieres break avisame !!!!!!!!!!
            }
        }
    }
    if (valid == -4){
        return 0; //Referencias Correctas
    }
    else{
        return valid; //Codigos de Error: -1 -> No existen ninguna de las referencias, -2 -> No existe el cliente, -3 -> No existe el vendedor;
    }

}

int ReferListas::crearReferenciasVendedores(){
    Vendedor *vendActual;
    ListaEnlazada<int> *listIdVentActual;
    int idVentActual;
    Venta *ventActual;
    int validTotal = 0, validParcial = 0;
    for (int i = 0; i < this->listVendedores->longitud(); i++){ //Recorremos todos los ventedores
        vendActual = this->listVendedores->recuperar(i);
        listIdVentActual = vendActual->getListIdVentas(); //Sacamos la lista de id de ventas del vendedor
        for (int j = 0; j < listIdVentActual->longitud(); j++){ //Recorremos todos los id de ventas
            idVentActual = *listIdVentActual->recuperar(j);
            for (int k = 0; k < this->listVentas->longitud();k++){ //Buscamos en la lista de ventas global el id actual
                ventActual = listVentas->recuperar(k);
                if (ventActual->getId() == idVentActual){
                    vendActual->addVenta(ventActual);
                    validParcial++;
                    break;
                }
            }
        }
        if (validParcial == listIdVentActual->longitud()){
            validTotal++;
        }
    }
    if (validTotal == this->listVendedores->longitud()){
        return 0; //Sin errores
    }

    return -1; //Codigos de Error: -1 -> No existe alguna de las referencias
}

int ReferListas::crearReferenciasClientes(){
    Cliente *cActual;
    Venta *vActual;
    ListaEnlazada<int> *listIdVentActual;
    int idVentActual;
    int validTotal = 0, validParcial = 0;
    for (int i = 0; i < this->listClientes->longitud();i++){//Recorremos todos los clientes de la base
        cActual = this->listClientes->recuperar(i);
        listIdVentActual = cActual->getListIdCompras();
        for (int j=0; j < listIdVentActual->longitud(); j++){ //Recorremos los id de ventas de cada cliente
            idVentActual = *listIdVentActual->recuperar(j);
            for (int k=0; k < this->listVentas->longitud(); k++){//Recorremos las ventas en la base
                vActual = this->listVentas->recuperar(k);
                if (vActual->getId() == idVentActual){
                    cActual->addCompra(vActual);
                    validParcial++;
                    break;
                }
            }
        }
        if (validParcial == listIdVentActual->longitud()){
            validTotal++;
        }
    }
    if (validTotal == this->listClientes->longitud()){
        return 0; //Sin errores
    }

    return -1; //Codigos de Error: -1 -> No existe alguna de las referencias
}

