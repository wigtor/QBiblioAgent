/*
 * File:   vendedor.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 10:42
 */

#include "Vendedor.h"
#pragma GCC visibility push(default)

/****************************************
 *
 * Variables Auxiliares
 * 
 ****************************************/

int Vendedor::idCont = 1;

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

Vendedor::Vendedor(int numRut){
    this->id = Vendedor::idCont++;
    this->RUT = numRut;
    this->telefonos = new ListaEstatica();
    this->nombre = "";
    this->direccion = "";
}

Vendedor::Vendedor(const Vendedor& orig){

}

Vendedor::~Vendedor(){
    //Revisar despues
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

void Vendedor::setEmail(string strEmail){
    this->email = strEmail;
}

void Vendedor::addTelefono(int telefonoAgregado){
    this->telefonos->agregar(&telefonoAgregado); 
}

void Vendedor::addVenta(Venta *ventaAgregada){
    this->ventas->agregar(ventaAgregada);
}

/****************************************
 *
 * Funciones Getters
 *
 ****************************************/

int Vendedor::getID(){
    return this->id;
}

int Vendedor::getRut(){
    return this->RUT;
}

string Vendedor::getResumen(){
    //en c++ no existe el operador + para strings, acá voy a cambiarlo...
    //return this->nombre + "||" + str(this->edad) + "||" + this->direccion + str(this->telefonos)"||" + this->email;
    return "wea de prueba";
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

ListaEstatica *Vendedor::getTelefonos(){
    return this->telefonos;
}

ListaEnlazada *Vendedor::getVentas(){
    return this->ventas;
}

/****************************************
 *
 * Funciones Adicionales
 *
 ****************************************/

Cliente *Vendedor::ingresaCliente(){

    return NULL;
}

string Vendedor::verInfoCliente(Cliente *cliente){

    return NULL;
}

Venta *Vendedor::verHistorialCliente(Cliente  *cliente){

    return NULL;
}

Cliente *Vendedor::editarCliente(Cliente *cliente){

    return NULL;
}

Libro *Vendedor::ingresaLibro(){

    return NULL;
}

void Vendedor::realizarVenta(){

}


