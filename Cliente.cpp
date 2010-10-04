/* 
 * File:   Cliente.cpp
 * Author: Mateo
 * 
 * Created on 23 de septiembre de 2010, 9:51
 */

#include "Cliente.h"

// Hacer:
// · Destructor

int Cliente::idCont = 1;

Cliente::Cliente() {
    this->id = Cliente::idCont;
    setIdCont(getIdCont() + 1);
    this->rut = 0;
    this->nombre = "";
    this->edad = 0;
    this->direccion = "";
    this->telefonos = new ListaEstatica;
    this->email = "";
    this->comprasHechas = new ListaEnlazada;
}

Cliente::Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email) {
    this->id = Cliente::idCont;
    setIdCont(getIdCont() + 1);
    this->rut = rut;
    this->nombre = nombre;
    this->edad = edad;
    this->direccion = direccion;
    this->telefonos = telefonos;
    this->email = email;
    this->comprasHechas = new ListaEnlazada;
}

Cliente::Cliente(const Cliente& orig) {
    this->id = orig.id;
    this->rut = orig.rut;
    this->nombre = orig.nombre;
    this->edad = orig.edad;
    this->direccion = orig.direccion;
    this->telefonos = new ListaEstatica;
    for (int i=0; i<orig.telefonos->longitud(); i++) {
        this->telefonos->agregar(orig.telefonos->recuperar(i));
    }
    this->email = orig.email;
    this->comprasHechas = new ListaEnlazada;
    for (int i=0; i<orig.comprasHechas->longitud(); i++) {
        this->comprasHechas->agregar(orig.comprasHechas->recuperar(i));
    }
}

Cliente::~Cliente() {
    comprasHechas.~ListaEnlazada();
}

int Cliente::getIdCont() {
    return idCont;
}

void Cliente::setIdCont(int idCont) {
    Cliente::idCont = idCont;
}

int Cliente::getId() {
    return this->id;
}

void Cliente::setId(int id) {
    this->id = id;
}

int Cliente::getRut() {
    return this->rut;
}

void Cliente::setRut(int rut) {
    this->rut = rut;
}

string Cliente::getNombre() {
    return this->nombre;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

int Cliente::getEdad() {
    return this->edad;
}

void Cliente::setEdad(int edad) {
    this->edad = edad;
}

string Cliente::getDireccion() {
    return this->direccion;
}

void Cliente::setDireccion(string direccion) {
    this->direccion = direccion;
}

ListaEstatica *Cliente::getTelefonos() {
    return this->telefonos;
}

string Cliente::getEmail() {
    return this->email;
}

void Cliente::setEmail(string email) {
    this->email = email;
}

ListaEnlazada *Cliente::getComprasHechas() {
    return this->comprasHechas;
}

void Cliente::addCompra(Venta *compra) {
    this->comprasHechas->agregar(compra);
}