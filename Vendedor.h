/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include <string>
#include <sstream>
#include <iostream>
#include "Cliente.h"
#include "Libro.h"

class Venta;

using namespace std;

class Vendedor{
public:

    //Iniciadores y obligatorios
    Vendedor(int intRut);
    Vendedor(const Vendedor& orig);
    ~Vendedor();
    bool operator<(Vendedor *otroVend);
    bool operator>(Vendedor *otroVend);
    bool operator==(Vendedor *otroVend);
    //////////////////////////////////

    //Setters
    void setNombre(string strNombre);
    void setEdad(int intEdad);
    void setDireccion(string strDireccion);
    int setEmail(string strEmail);
    void addTelefono(int telefonoAgregado);
    void addVenta(Venta *ventaAgregada);
    void setIdCont(int intId);
    //////////////////////////////////

    //Getters
    int getId();
    int getRut();
    string getResumen();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica *getTelefonos();
    ListaEnlazada *getVentas();
    int getIdCont();
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
    static int ORD_RUT;
    static int ORD_NOM;
    static int ORD_EDAD;
    static int ORD_CANTVENT;
    int id;
    int rut;
    string nombre;
    int edad;
    string direccion;
    string email;
    ListaEstatica *telefonos; 
    ListaEnlazada *ventas;
};

#endif	/* VENDEDOR_H */
