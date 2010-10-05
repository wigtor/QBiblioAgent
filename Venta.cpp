/*
 * File:   Venta.cpp
 * Author: Mateo
 * 
 * Created on 24 de septiembre de 2010, 11:33 PM
 */


#include "Venta.h"

Venta::Venta() {
    this->correlativo = false;
    this->id = Venta::idCont++;
    this->idLibro = 0;
    this->libro = NULL;
    this->idCliente = 0;
    this->cliente = NULL;
    this->cantidadLibros = 0;
    this->montoTotal = 0;
    this->vendedor = NULL;
    this->fecha = NULL;
    this->idVendedor = 0;
}

Venta::Venta(int id, bool correlativo, int idLibro, int idCliente, int idVendedor, int cantidadLibros, int montoTotal, Fecha *fecha) {
    this->correlativo = correlativo;
    this->id = id;
    this->idLibro = idLibro;
    this->libro = NULL;
    this->idCliente = idCliente;
    this->cliente = NULL;
    this->cantidadLibros = cantidadLibros;
    this->montoTotal = montoTotal;
    this->vendedor = NULL;
    this->fecha = fecha;
    this->idVendedor = idVendedor;
}

Venta::Venta(bool correlativo, int idLibro, Libro *libro, int idCliente, Cliente *cliente, int idVendedor, Vendedor *vendedor, int cantidadLibros, int montoTotal, Fecha *fecha) {
    this->correlativo = correlativo;
    this->id = Venta::idCont++;
    this->idLibro = idLibro;
    this->libro = libro;
    this->idCliente = idCliente;
    this->cliente = cliente;
    this->cantidadLibros = cantidadLibros;
    this->montoTotal = montoTotal;
    this->vendedor = vendedor;
    this->fecha = fecha;
    this->idVendedor = idVendedor;
}

Venta::Venta(const Venta& orig) { // ¿Se necesita esto? Las ventas son unicas, y si se borra una, ListaEnlazada::eliminar
}                                 // se encargara de los nodos, así que no veo el sentido de una copia.

Venta::~Venta() {
}

bool Venta::getCorrelativo() {
    return this->correlativo;
}

int Venta::getId() {
    return this->id;
}

void Venta::setCorrelativo(bool correlativo) {
    this->correlativo = correlativo;
}

int Venta::getIdLibro() {
    return this->idLibro;
}

void Venta::setIdLibro(int idLibro) {
    this->idLibro = idLibro;
}

Libro *Venta::getLibro() {
    return this->libro;
}

void Venta::setLibro(Libro *libro) {
    this->libro = libro;
}

int Venta::getIdCliente() {
    return this->idCliente;
}

void Venta::setIdCliente(int idCliente) {
    this->idCliente = idCliente;
}

Cliente *Venta::getCliente() {
    return this->cliente;
}

void Venta::setCliente(Cliente *cliente) {
    this->cliente = cliente;
}

int Venta::getCantidadLibros() {
    return this->cantidadLibros;
}

void Venta::setCantidadLibros(int cantidadLibros) {
    this->cantidadLibros = cantidadLibros;
}

int Venta::getMontoTotal() {
    return this->montoTotal;
}

void Venta::setMontoTotal(int montoTotal) {
    this->montoTotal = montoTotal;
}

Vendedor *Venta::getVendedor() {
    return this->vendedor;
}

void Venta::setVendedor(Vendedor *vendedor) {
     this->vendedor = vendedor;
}

Fecha *Venta::getFecha() {
    return this->fecha;
}

void Venta::setFecha(Fecha *fecha) {
    this->fecha = fecha;
}

int Venta::getIdVendedor() {
    return this->idVendedor;
}

void Venta::setIdVendedor(int idVendedor) {
    this->idVendedor = idVendedor;
}

int Venta::idCont = 1;
