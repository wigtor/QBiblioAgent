/*
 * File:   Libro.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 21:16
 */

#include "Libro.h"

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

Libro::Libro(int intIsbn, string strNombre, string strAutor){
    this->isbn = intIsbn;
    this->nombre = strNombre;
    this->autor = strAutor;
}

Libro::Libro(const Libro& orig){

}

Libro::~Libro(){

}


/****************************************
 *
 * Funciones Setters
 *
 ****************************************/

void Libro::setIsbn(int intIsbn){
    this->isbn = intIsbn;
}

void Libro::setPrecio(int intPrecio){
    this->precio = intPrecio;
}

void Libro::setNombre(string strNombre){
    this->nombre = strNombre;
}

void Libro::setAutor(string strAutor){
    this->autor = strAutor;
}

void Libro::setPaginas(int intPaginas){
    this->paginas = intPaginas;
}

void Libro::setPeso(int peso){
    this->peso = peso;
}

void Libro::setStock(int intStock){
    this->stock = intStock;
}

/****************************************
 *
 * Funciones Getters
 *
 ****************************************/

int Libro::getId(){
    return this->id;
}

int Libro::getIsbn(){
    return this->isbn;
}

int Libro::getPrecio(){
    return this->precio;
}

string Libro::getNombre(){
    return this->nombre;
}

string Libro::getAutor(){
    return this->autor;
}

int Libro::getPaginas(){
    return this->paginas;
}

int Libro::getPeso(){
    return this->peso;
}

int Libro::getStock(){
    return this->stock;
}

/****************************************
 *
 * Funciones Adicionales
 *
 ****************************************/
