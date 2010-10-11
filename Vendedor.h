/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

//Constantes
#define ORD_V_RUT = 1;
#define ORD_V_NOM = 2;
#define ORD_V_EDAD = 3;
#define ORD_V_CANTVENT = 4;


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
    Vendedor(int intRut);
    Vendedor(int idObj, int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, ListaEnlazada<int> *ventasHechas);
    Vendedor(const Vendedor& orig);
    virtual ~Vendedor();
    bool operator<(const Vendedor& otroVend);
    bool operator>(const Vendedor& otroVend);
    bool operator==(const Vendedor& otroVend);
    //////////////////////////////////

    //Setters
    void setNombre(string strNombre);
    void setEdad(int intEdad);
    void setDireccion(string strDireccion);
    int setEmail(string strEmail);
    void addTelefono(int telefonoAgregado);
    void addVenta(Venta *ventaAgregada);
    static void setIdCont(int intId);
    //////////////////////////////////

    //Getters
    int getId();
    int getRut();
    string getResumen();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica<int> *getTelefonos();
    ListaEnlazada<Venta> *getVentas();
    ListaEnlazada<int> *getListIdVentas();
    static int getIdCont();
    //////////////////////////////////

    //Otras Funciones
    Cliente *ingresaCliente();
    string verInfoCliente(Cliente *Cliente);
    Venta *verHistorialCliente(Cliente *cliente); 
    Cliente *editarCliente(Cliente *cliente);
    Libro *ingresaLibro(); 
    void realizarVenta();
    //////////////////////////////////

private:

    static int idCont;
    static int numOrder;    // Codigos: 1->Rut / 2->Nombre / 3-> Edad / 4-> Cantidad de Ventas
    int id;
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
