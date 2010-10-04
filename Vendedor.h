/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include <string>
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
    //////////////////////////////////

    //Setters
    void setNombre(string strNombre);
    void setEdad(int intEdad);
    void setDireccion(string strDireccion);
    void setEmail(string strEmail);
    void addTelefono(int telefonoAgregado);
    void addVenta(Venta *ventaAgregada);
    //////////////////////////////////

    //Getters
    int getID();
    int getRut();
    string getResumen();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica *getTelefonos();
    ListaEnlazada *getVentas();
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
    int id;
    int RUT;
    string nombre;
    int edad;
    string direccion;
    string email;
    ListaEstatica *telefonos; 
    ListaEnlazada *ventas;
};

#endif	/* VENDEDOR_H */
