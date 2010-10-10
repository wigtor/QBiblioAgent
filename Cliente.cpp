/* 
 * File:   Cliente.cpp
 * Author: Mateo
 * 
 * Created on 23 de septiembre de 2010, 9:51
 */

#include "Cliente.h"

/* Hacer:
 * Destructor
 */

/****************************************
 VARIABLES ESTATICAS
 ****************************************/

int Cliente::idCont = 1;
int Cliente::numOrder = 1;

/****************************************
 CONSTRUCTORES, COPIAS, DESTRUCTORES
 ****************************************/

Cliente::Cliente() {
    this->id = Cliente::idCont++;
    this->rut = 0;
    this->nombre = "";
    this->edad = 0;
    this->direccion = "";
    this->telefonos = new ListaEstatica;
    this->email = "";
    this->comprasHechas = new ListaEnlazada;
}

Cliente::Cliente(int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email) {
    this->id = Cliente::idCont++;
    this->rut = rut;
    this->nombre = nombre;
    this->edad = edad;
    this->direccion = direccion;
    this->telefonos = telefonos;
    this->email = email;
    this->comprasHechas = new ListaEnlazada;
}

Cliente::Cliente(int id, int rut, string nombre, int edad, string direccion, ListaEstatica *telefonos, string email, ListaEnlazada *comprasHechas) {
    this->id = id;
    this->rut = rut;
    this->nombre = nombre;
    this->edad = edad;
    this->direccion = direccion;
    this->telefonos = telefonos;
    this->email = email;
    this->comprasHechas = comprasHechas;
}

Cliente::Cliente(const Cliente& orig) {
    this->id = orig.id;
    this->rut = orig.rut;
    this->nombre = orig.nombre;
    this->edad = orig.edad;
    this->direccion = orig.direccion;
    this->telefonos = orig.telefonos;
    this->comprasHechas = orig.comprasHechas;
    this->email = orig.email;
}

Cliente::~Cliente() {
    comprasHechas.~ListaEnlazada();
}

/****************************************
 SETTERS
 ****************************************/

void Cliente::setIdCont(int idCont) {
    Cliente::idCont = idCont;
}

void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setRut(int rut) {
    this->rut = rut;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setEdad(int edad) {
    this->edad = edad;
}

void Cliente::setDireccion(string direccion) {
    this->direccion = direccion;
}

void Cliente::setEmail(string email) {
    this->email = email;
}

/****************************************
 GETTERS
 ****************************************/

int Cliente::getId() {
    return this->id;
}

int Cliente::getRut() {
    return this->rut;
}

string Cliente::getNombre() {
    return this->nombre;
}

int Cliente::getEdad() {
    return this->edad;
}

string Cliente::getDireccion() {
    return this->direccion;
}

ListaEstatica *Cliente::getTelefonos() {
    return this->telefonos;
}

string Cliente::getEmail() {
    return this->email;
}

ListaEnlazada *Cliente::getComprasHechas() {
    return this->comprasHechas;
}

/****************************************
 OPERADORES
 ****************************************/

/* Codigos numOrder:
 * 1 = ID
 * 2 = RUT
 * 3 = Nombre
 * 4 = Cantidad de compras hechas
 */

bool Cliente::operator <(Cliente *otroCliente) {
    switch(Cliente::numOrder) {
        case 1:
            if (this->id < otroCliente->id)
                return true;
            else
                return false;
        case 2:
            if (this->rut < otroCliente->rut)
                return true;
            else
                return false;
        case 3:
            if (this->nombre.compare(otroCliente->nombre) < 0)
                return true;
            else
                return false;
        case 4:
            if (this->comprasHechas->longitud() < otroCliente->comprasHechas->longitud())
                return true;
            else
                return false;
        default:
            return false;
    }
}

bool Cliente::operator >(Cliente *otroCliente) {
    switch(Cliente::numOrder) {
        case 1:
            if (this->id > otroCliente->id)
                return true;
            else
                return false;
        case 2:
            if (this->rut > otroCliente->rut)
                return true;
            else
                return false;
        case 3:
            if (this->nombre.compare(otroCliente->nombre) > 0)
                return true;
            else
                return false;
        case 4:
            if (this->comprasHechas->longitud() > otroCliente->comprasHechas->longitud())
                return true;
            else
                return false;
        default:
            return false;
    }
}

bool Cliente::operator ==(Cliente *otroCliente) {
    switch(Cliente::numOrder) {
        case 1:
            if (this->id == otroCliente->id)
                return true;
            else
                return false;
        case 2:
            if (this->rut == otroCliente->rut)
                return true;
            else
                return false;
        case 3:
            if (this->nombre.compare(otroCliente->nombre) == 0)
                return true;
            else
                return false;
        case 4:
            if (this->comprasHechas->longitud() == otroCliente->comprasHechas->longitud())
                return true;
            else
                return false;
        default:
            return false;
    }
}

/****************************************
 OTROS METODOS
 ****************************************/

void Cliente::addCompra(Venta *compra) {
    this->comprasHechas->agregar(compra);
}