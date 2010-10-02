/* 
 * File:   CapaIO.cpp
 * Author: victor
 * 
 * Created on 30 de septiembre de 2010, 21:51
 */

#include "CapaIO.h"

CapaIO::CapaIO() {
    this->fVentas = *(new fstream(CapaIO.archVentas, fstream::in));
    this->fClientes = *(new fstream(CapaIO.archClientes, fstream::in));
    this->fUsuarios = *(new fstream(CapaIO.archUsuarios, fstream::in));
    this->fLibros = *(new fstream(CapaIO.archLibros, fstream::in));
    
}

CapaIO::CapaIO(const CapaIO& orig) {
}

CapaIO::~CapaIO(){
    this->fVentas.close();
    this->fClientes.close();
    this->fUsuarios.close();
    this->fLibros.close();
}

string CapaIO::archVentas = "ventas.txt";
string CapaIO::archClientes = "clientes.txt";
string CapaIO::archUsuarios = "usuarios.txt";
string CapaIO::archLibros = "libros.txt";