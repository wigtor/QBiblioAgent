/*
 * File:   Libro.h
 * Author: AirZs
 *
 * Creado el 25 de septiembre de 2010, 21:16
 */

#include "Libro.h"

/****************************************
 *
 * Variables Estaticas
 *
 ****************************************/

int Libro::idCont = 1;
int Libro::numOrder = 3;
/*
int Libro::ORD_ISBN = 1;
int Libro::ORD_PRECIO = 2;
int Libro::ORD_NOM = 3;
int Libro::ORD_AUTOR = 4;
int Libro::ORD_PAG = 5;
int Libro::ORD_PESO = 6;
int Libro::ORD_STOCK = 7;
*/

/****************************************
 *
 * Funciones Iniciadores y Obligatorios
 *
 ****************************************/

Libro::Libro(int id, int isbn, string nombre, string autor, int precio, int paginas, int peso, int stock){
    this->id=id;
    this->isbn = isbn;
    this->nombre = nombre;
    this->autor = autor;
    this->precio = precio;
    this->paginas = paginas;
    this->peso = peso;
    this->stock = stock;
}

Libro::Libro(int intIsbn, string strNombre, string strAutor){
    this->isbn = intIsbn;
    this->nombre = strNombre;
    this->autor = strAutor;
}

Libro::Libro(const Libro& orig){

}

Libro::~Libro(){

}

bool Libro::operator <(Libro *otroLibro){
    switch(Libro::numOrder){ // Codigos: 1->Isbn / 2->Precio / 3->Nombre / 4->Autor / 5->Paginas / 6->Peso / 7->Stock
    case 1:
        if (this->isbn < otroLibro->isbn){
            return true;
        }
        else
            return false;
    case 2:
        if (this->precio<otroLibro->precio){
            return true;
        }
        else
            return false;
    case 3:
        if (this->nombre.compare(otroLibro->nombre)<0){
            return true;
        }
        else
            return false;
    case 4:
        if (this->autor.compare(otroLibro->autor)<0){
            return true;
        }
        else
            return false;
    case 5:
        if (this->paginas<otroLibro->paginas){
            return true;
        }
        else
            return false;
    case 6:
        if (this->peso<otroLibro->peso){
            return true;
        }
        else
            return false;
    case 7:
        if (this->stock<otroLibro->stock){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Libro::operator >(Libro *otroLibro){
    switch(Libro::numOrder){ // Codigos: 1->Isbn / 2->Precio / 3->Nombre / 4->Autor / 5->Paginas / 6->Peso / 7->Stock
    case 1:
        if (this->isbn>otroLibro->isbn){
            return true;
        }
        else
            return false;
    case 2:
        if (this->precio>otroLibro->precio){
            return true;
        }
        else
            return false;
    case 3:
        if (this->nombre.compare(otroLibro->nombre)>0){
            return true;
        }
        else
            return false;
    case 4:
        if (this->autor.compare(otroLibro->autor)>0){
            return true;
        }
        else
            return false;
    case 5:
        if (this->paginas>otroLibro->paginas){
            return true;
        }
        else
            return false;
    case 6:
        if (this->peso>otroLibro->peso){
            return true;
        }
        else
            return false;
    case 7:
        if (this->stock>otroLibro->stock){
            return true;
        }
        else
            return false;
    default:
        return false;
    }
}

bool Libro::operator ==(Libro *otroLibro){
    switch(Libro::numOrder){ // Codigos: 1->Isbn / 2->Precio / 3->Nombre / 4->Autor / 5->Paginas / 6->Peso / 7->Stock
    case 1:
        if (this->isbn==otroLibro->isbn){
            return true;
        }
        else
            return false;
    case 2:
        if (this->precio==otroLibro->precio){
            return true;
        }
        else
            return false;
    case 3:
        if (this->nombre.compare(otroLibro->nombre)==0){
            return true;
        }
        else
            return false;
    case 4:
        if (this->autor.compare(otroLibro->autor)==0){
            return true;
        }
        else
            return false;
    case 5:
        if (this->paginas==otroLibro->paginas){
            return true;
        }
        else
            return false;
    case 6:
        if (this->peso==otroLibro->peso){
            return true;
        }
        else
            return false;
    case 7:
        if (this->stock==otroLibro->stock){
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

void Libro::setIdCont(int intId){
    Libro::idCont = intId;
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

int Libro::getIdCont(){
    return Libro::idCont;
}

/****************************************
 *
 * Funciones Adicionales
 *
 ****************************************/
