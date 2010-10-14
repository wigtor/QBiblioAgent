/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

//Constantes
#define ORD_VEND_RUT 1
#define ORD_VEND_NOM 2
#define ORD_VEND_EDAD 3
#define ORD_VEND_CANTVENT 4


#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Libro.h"
#include "ListaEstatica.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Venta.h"

class Venta;
class Cliente;

using namespace std;
#pragma GCC visibility push(default)

class Vendedor{
public:

    //Iniciadores y obligatorios
    Vendedor(int intRut, string nombre, string direccion);
    Vendedor(int idObj, bool esActivo, int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, ListaEnlazada<int> *ventasHechas);
    virtual ~Vendedor();
    bool operator<(const Vendedor& otroVend);
    bool operator>(const Vendedor& otroVend);
    bool operator==(const Vendedor& otroVend);
    //////////////////////////////////

    //Setters
    void setNombre(string strNombre);
    static void setNumOrder(int numOrder);
    void setEdad(int intEdad);
    void setDireccion(string strDireccion);
    int setEmail(string strEmail);
    void setActivo(bool activo);
    void setListaTelefonos(ListaEstatica<int> *listaTelefonos);
    void addTelefono(int telefonoAgregado);
    void addVenta(Venta *ventaAgregada);
    void addIdVenta(int idVenta);
    static void setIdCont(int intId);
    //////////////////////////////////

    //Getters
    int getId();
    int getRut();
    static int getNumOrder();
    string getResumen();
    bool getEsActivo();
    string getNombre();
    int getEdad();
    string getEmail();
    string getDireccion();
    ListaEstatica<int> *getTelefonos();
    ListaEnlazada<Venta> *getVentas();
    ListaEnlazada<int> *getListIdVentas();
    static int getIdCont();
    //////////////////////////////////

private:

    static int idCont;
    static int numOrder;    // Codigos: 1->Rut / 2->Nombre / 3-> Edad / 4-> Cantidad de Ventas
    int id;
    bool activo;
    int rut;
    string nombre;
    int edad;
    string direccion;
    string email;
    ListaEstatica<int> *telefonos;
    ListaEnlazada<Venta> *ventas;
    ListaEnlazada<int> *listIdVentas;
    string pass;
};

#endif	/* VENDEDOR_H */
