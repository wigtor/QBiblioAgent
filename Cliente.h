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

using namespace std;

class Cliente {
public:
    Cliente();
    Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email);
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    int getIdCont();
    void setIdCont(int idCont);
    int getId();
    void setId(int id);
    int getRut();
    void setRut(int rut);
    string getNombre();
    void setNombre(string nombre);
    int getEdad();
    void setEdad(int edad);
    string getDireccion();
    void setDireccion(string direccion);
    ListaEstatica *getTelefonos();
    string getEmail();
    void setEmail(string email);
    ListaEnlazada *getComprasHechas();
private:
    static int idCont;
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

