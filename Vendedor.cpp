/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 10:42
 */

#include "Vendedor.h"

//#pragma GCC visibility push(default)

/****************************************
 *
 * Variables Estaticas
 * 
 ****************************************/

int Vendedor::idCont = 1;
int Vendedor::numOrder = 3;
/*
int Vendedor::ORD_RUT = 1;
int Vendedor::ORD_NOM = 2;
int Vendedor::ORD_EDAD = 3;
int Vendedor::ORD_CANTVENT = 4;
*/

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/
 
Vendedor::Vendedor(int idObj, bool esActivo, int rut, string nombre, int edad, string email, string direccion, ListaEstatica<int> *telefonos, ListaEnlazada<int> *idsVentasHechas){
    this->id= idObj;
    this->rut = rut;
    this->activo = true;
    this->nombre = nombre;
    this->activo = esActivo;
    this->email = email;
    this->edad = edad;
    this->direccion = direccion;
    this->telefonos = telefonos;
    this->listIdVentas = idsVentasHechas;
    this->ventas = new ListaEnlazada<Venta>();
}

Vendedor::Vendedor(int numRut, string nombre, string direccion){
    this->id = Vendedor::idCont++;
    this->rut = numRut;
    this->activo = true;
    this->telefonos = NULL;
    this->ventas = new ListaEnlazada<Venta>();
    this->listIdVentas = new ListaEnlazada<int>();
    this->nombre = nombre;
    this->direccion = direccion;
    stringstream password;
    password << numRut;
    int pos;
    pos = (password.str()).length();
    this->pass = (password.str()).substr(pos-3);
}

Vendedor::~Vendedor(){
    //Revisar despues
}

bool Vendedor::operator <(const Vendedor& otroVend){
    switch(Vendedor::numOrder){ // Codigos: 1->Rut / 2->Nombre / 3-> Edad / 4-> Cantidad de Ventas
    case 1:
        if (this->rut < otroVend.rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend.nombre) < 0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad < otroVend.edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud() < otroVend.ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Vendedor::operator >(const Vendedor& otroVend){
    switch(Vendedor::numOrder){
    case 1:
        if (this->rut > otroVend.rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend.nombre) > 0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad > otroVend.edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud() > otroVend.ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Vendedor::operator ==(const Vendedor& otroVend){
    switch(Vendedor::numOrder){
    case 1:
        if (this->rut == otroVend.rut){
            return true;
        }
        else
            return false;
    case 2:
        if (this->nombre.compare(otroVend.nombre) == 0){
            return true;
        }
        else
            return false;
    case 3:
        if (this->edad == otroVend.edad){
            return true;
        }
        else
            return false;
    case 4:
        if (this->ventas->longitud() == otroVend.ventas->longitud()){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

/****************************************
 *
 * Funciones Setters
 *
 ****************************************/

void Vendedor::setNombre(string strNombre){
    this->nombre = strNombre;
}

void Vendedor::setEdad(int intEdad){
    this->edad = intEdad;
}

void Vendedor::setDireccion(string strDireccion){
    this->direccion = strDireccion;
}

int Vendedor::setEmail(string strEmail){
    size_t pos;
    if (strEmail[0] == '@'){
        this->email = "";
        return 1;
    }
    pos = strEmail.find("@");
    if (pos == string::npos){
        this->email = "";
        return 1;
    }
    pos = strEmail.find("@", pos+1);
    if (pos != string::npos){
        this->email = "";
        return 1;
    }
    this->email = strEmail;
    return 0;
}

void Vendedor::setNumOrder(int numOrder){
    Vendedor::numOrder = numOrder;
}

void Vendedor::setActivo(bool activo){
    this->activo = activo;
}

void Vendedor::setListaTelefonos(ListaEstatica<int> *listaTelefonos){
    this->telefonos = listaTelefonos;
}

void Vendedor::addTelefono(int telefonoAgregado){
    this->telefonos->agregar(&telefonoAgregado); 
}

void Vendedor::addVenta(Venta *ventaAgregada){
    this->ventas->agregar(ventaAgregada);
}
void Vendedor::addIdVenta(int idVenta){
    this->listIdVentas->agregar(new int (idVenta));
}

void Vendedor::setIdCont(int intId){
    Vendedor::idCont=intId;
}

/****************************************
 *
 * Funciones Getters
 *
 ****************************************/

int Vendedor::getId(){
    return this->id;
}

int Vendedor::getRut(){
    return this->rut;
}

int Vendedor::getNumOrder(){
    return Vendedor::numOrder;
}

string Vendedor::getEmail(){
    return this->email;
}

bool Vendedor::getEsActivo(){
    return this->activo;
}

string Vendedor::getResumen(){
    stringstream resumen;
    int i;
    resumen << "Nombre: " << this->nombre << endl;
    resumen << "Rut: " << this->rut << endl;
    resumen << "Direccion: " << this->direccion << endl;
    resumen << "Edad: " << this->edad << endl;
    resumen << "E-Mail: " << this->email << endl;
    //resumen << "Password: " << this->pass << endl;
    resumen << "Telefonos: ";
    for (i = 0; i < this->telefonos->longitud(); i++)
        resumen << *(this->telefonos->recuperar(i)) << ", ";
    resumen << endl << "Cantidad de compras: " << this->ventas->longitud() << endl;
    return resumen.str();
}

string Vendedor::getNombre(){
    return this->nombre;
}

int Vendedor::getEdad(){
    return this->edad;
}

string Vendedor::getDireccion(){
    return this->direccion;
}

ListaEstatica<int> *Vendedor::getTelefonos(){
    return this->telefonos;
}

ListaEnlazada<Venta> *Vendedor::getVentas(){
    return this->ventas;
}

ListaEnlazada<int> *Vendedor::getListIdVentas(){
    return this->listIdVentas;
}


int Vendedor::getIdCont(){
    return Vendedor::idCont;
}
