/* 
 * File:   Cliente.cpp
 * Author: Mateo
 * 
 * Created on 23 de septiembre de 2010, 9:51
 */

#include "Cliente.h"

Cliente::Cliente() {
    this->id = Cliente::idCont+1;
    this->rut = 0;
    this->nombre = "";
    this->edad = 0;
    this->direccion = "";
    this->telefonos = NULL; // ¿Correcto?
    this->email = "";
    this->comprasHechas = NULL;
}

Cliente::Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email) {
    //aunque se copie en memoria no permitir que dos clientes tengan el mismo id;
    this->id = Cliente::idCont+1;
    this->rut = rut;
    this->nombre = nombre;
    this->edad = edad;
    this->direccion = direccion;
    this->telefonos = telefonos;
    this->email=email;
    this->comprasHechas = new ListaEnlazada();
}

Cliente::Cliente(const Cliente& orig) { // ¿Se necesita esto? Los clientes son unicos, y si se borra uno, ListaEnlazada::eliminar
}                                       // se encargara de los nodos, así que no veo el sentido de una copia.

Cliente::~Cliente() {
    comprasHechas->~ListaEnlazada();
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

int Cliente::idCont = 1;
