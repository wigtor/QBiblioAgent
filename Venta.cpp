/* 
 * File:   Venta.cpp
 * Author: Mateo
 * 
 * Created on 24 de septiembre de 2010, 11:33 PM
 */

#include "Venta.h"

// Terminar:
// · Constructor copia
// · Destructor

int Venta::idCont = 1;

Venta::Venta() {
    this->id = Venta::idCont;
    setIdCont(getIdCont() + 1);
    this->correlativo = false;
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

Venta::Venta(bool correlativo, Libro *libro, Cliente *cliente, int cantidadLibros, int montoTotal, Vendedor *vendedor, Fecha *fecha) {
    this->id = Venta::idCont;
    setIdCont(getIdCont() + 1);
    this->correlativo = correlativo;
    this->idLibro = libro->getId();
    this->libro = libro;
    this->idCliente = cliente->getId();
    this->cliente = cliente;
    this->cantidadLibros = cantidadLibros;
    this->montoTotal = montoTotal;
    this->vendedor = vendedor;
    this->fecha = fecha;
    this->idVendedor = vendedor->getID();
}

Venta::Venta(const Venta& orig) {
}

Venta::~Venta() {
}

int Venta::getIdCont() {
    return idCont;
}

void Venta::setIdCont(int idCont) {
    Venta::idCont = idCont;
}

int Venta::getId() {
    return this->id;
}

void Venta::setId(int id) {
    this->id = id;
}

bool Venta::getCorrelativo() {
    return this->correlativo;
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
