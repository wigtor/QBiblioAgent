/*
 * File:   ReferListas.h
 * Author: AirZs
 *
 * Creado el 10 de octubre de 2010, 2:36
 */

#include "ReferListas.h"
#include "ErrorExcep.h"

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
    try{
        cont += this->crearReferenciasClientes();
        cont += this->crearReferenciasVendedores();
        cont += this->crearReferenciasVentas();
        if (cont != 3)
            throw (new ErrorExcep(E_REFERT));
    }
    catch(ErrorExcep *e){
        /*e.descError() con esto se describe el error, se supone que es un string, pero se le pasa
        a la parte de interfaz*/
    }


    return 0;
}

/****************************************
 *
 * Funciones Adicionales (Private)
 *
 ****************************************/

int ReferListas::crearReferenciasVentas(){
    try{
        Venta *ventActual;
        Cliente *cActual;
        Vendedor *vendActual;
        Libro *libroActual;
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
            id = ventActual->getIdLibro();
            for (int k = 0; k < this->listLibros->longitud(); k++){
                libroActual = listLibros->recuperar(k);
                if (libroActual->getId() == id){
                    ventActual->setLibro(libroActual);
                    break; //Si no quieres break avisame !!!!!!!!!!
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


        if (valid == -1) throw ErrorExcep(E_VENTASINREFERENCIAS);
        if (valid == -2) throw ErrorExcep(E_VENTASINCLIENTE);
        if (valid == -3) throw ErrorExcep(E_VENTASINVENDEDOR);
    }

    catch(ErrorExcep *e){
        /*e.descError() con esto se describe el error, se supone que es un string, pero se le pasa
        a la parte de interfaz*/
    }
    return 1;
}

int ReferListas::crearReferenciasVendedores(){
    try {
        Vendedor *vendActual;
        ListaEnlazada<int> *listIdVentActual;
        int idVentActual, i, j, k, encontrado;
        Venta *ventActual;
        for (i = 0; i < this->listVendedores->longitud(); i++){ //Recorremos todos los ventedores
            vendActual = this->listVendedores->recuperar(i);
            listIdVentActual = vendActual->getListIdVentas(); //Sacamos la lista de id de ventas del vendedor
            for (j = 0; j < listIdVentActual->longitud(); j++){ //Recorremos todos los id de ventas
                idVentActual = *listIdVentActual->recuperar(j);
                encontrado = -1;
                for (k = 0; k < (this->listVentas->longitud()); k++){ //Buscamos en la lista de ventas global el id actual
                    ventActual = listVentas->recuperar(k);
                    if (ventActual->getId() == idVentActual){
                        vendActual->addVenta(ventActual);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == -1) throw (ErrorExcep(E_VENDSINVENTA, vendActual->getNombre(), ventActual->getId()));
            }
        }
    }
    catch (ErrorExcep *e){
        /*e.descError() con esto se describe el error, se supone que es un string, pero se le pasa
        a la parte de interfaz*/
    }
    return 1;
}

int ReferListas::crearReferenciasClientes(){
    try{
        Cliente *cActual;
        Venta *vActual;
        ListaEnlazada<int> *listIdVentActual;
        int idVentActual;
        int encontrado;
        for (int i = 0; i < this->listClientes->longitud();i++){//Recorremos todos los clientes de la base
            cActual = this->listClientes->recuperar(i);
            listIdVentActual = cActual->getListIdCompras();
            for (int j=0; j < listIdVentActual->longitud(); j++){ //Recorremos los id de ventas de cada cliente
                idVentActual = *listIdVentActual->recuperar(j);
                encontrado = -1;
                for (int k=0; k < this->listVentas->longitud(); k++){//Recorremos las ventas en la base
                    vActual = this->listVentas->recuperar(k);
                    if (vActual->getId() == idVentActual){
                        cActual->addCompra(vActual);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == -1) throw (ErrorExcep(E_CLIENTESINVENTA,cActual->getNombre(),vActual->getId()));
            }
        }
    }
    catch (ErrorExcep *e){
        /*e.descError() con esto se describe el error, se supone que es un string, pero se le pasa
        a la parte de interfaz*/
    }
    return 1;

}

