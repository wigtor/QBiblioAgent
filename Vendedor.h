/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 10:42
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include "Cliente.h"
#include "Libro.h"
#include "Venta.h"
//#include "Telefonos.h" //borrado mejor que los telefonos sean solo enteros, manejados mediante una listaEstatica

#include <string>

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
    //funcion para ver las ventas??
    //////////////////////////////////

    //Otras Funciones
    Cliente *ingresaCliente();
    string verInfoCliente(Cliente *Cliente);
    Venta *verHistorialCliente(Cliente *cliente); //todo retorno o argumento que sea dato compuesto (una clase) debe ser puntero a...
    Cliente *editarCliente(Cliente *cliente);
    Libro *ingresaLibro(); //acá por ejemplo, le agregué el * de puntero al tipo de retorno
    void realizarVenta();
    //////////////////////////////////

private:
    int id;
    int RUT;
    string nombre;
    int edad;
    string direccion;
    string email;
    ListaEstatica *telefonos; //los telefonos son una lista estatica de enteros
    ListaEnlazada *ventas;
};

#endif	/* VENDEDOR_H */
