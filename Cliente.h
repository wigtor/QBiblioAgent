/* 
 * File:   Cliente.h
 * Author: Mateo
 *
 * Created on 23 de septiembre de 2010, 9:51
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <string>
#include "ListaEnlazada.h"
#include "ListaEstatica.h"
#include "Venta.h"

using namespace std;

class Cliente {
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Cliente();
    Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email);
    Cliente(int id, int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email, ListaEnlazada *comprasHechas);
    Cliente(const Cliente& orig);
    virtual ~Cliente();

    // SETTERS
    void Cliente::setIdCont(int idCont);
    void setId(int id);
    void setRut(int rut);
    void setNombre(string nombre);
    void setEdad(int edad);
    void setDireccion(string direccion);
    void setEmail(string email);

    // GETTERS
    int getId();
    int getRut();
    string getNombre();
    int getEdad();
    string getDireccion();
    ListaEstatica *getTelefonos();
    string getEmail();
    ListaEnlazada *getComprasHechas();

    // OPERADORES
    bool operator <(Cliente *otroCliente);
    bool operator >(Cliente *otroCliente);
    bool operator ==(Cliente *otroCliente);

    // OTROS METODOS
    void addCompra(Venta *compra);

private:
    static int idCont;
    static int numOrder;
    int id;
    int rut;
    string nombre;
    int edad;
    string direccion;
    ListaEstatica *telefonos;
    string email;
    ListaEnlazada *comprasHechas;

};

#endif	/* CLIENTE_H */

