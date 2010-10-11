/*
 * File:   Cliente.h
 * Author: Mateo
 *
 * Created on 23 de septiembre de 2010, 9:51
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#include <string>
#include "Venta.h"
#include "ListaEnlazada.h"
#include "ListaEstatica.h"

class Venta;

using namespace std;
//#pragma GCC visibility push(default)

class Cliente {
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Cliente();
    Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, string email);
    Cliente(int id, int rut, string nombre, int edad, string direccion, ListaEstatica<int> *telefonos, string email, ListaEnlazada<int> *idsComprasHechas);
    Cliente(const Cliente& orig);
    virtual ~Cliente();

    // SETTERS
    static void setNumOrder(int numOrder);
    static void setIdCont(int idCont);
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
    ListaEstatica<int> *getTelefonos();
    ListaEnlazada<int> *getListIdCompras();
    string getEmail();
    ListaEnlazada<Venta> *getComprasHechas();

    // OPERADORES
    bool operator <(const Cliente& c) const;
    bool operator >(const Cliente& c) const;
    bool operator ==(const Cliente& c) const;

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
    ListaEstatica<int> *telefonos;
    string email;
    ListaEnlazada<Venta> *comprasHechas;
    ListaEnlazada<int> *idComprasHechas;

};

#endif	/* CLIENTE_H */
