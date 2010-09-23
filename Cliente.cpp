/* 
 * File:   Cliente.cpp
 * Author: victor
 * 
 * Created on 23 de septiembre de 2010, 9:51
 */

#include "Cliente.h"

Cliente::Cliente() {
    this->id = 0;

}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    comprasHechas.~ListaEnlazada();
}

int Cliente::getId() {
    return id;
}

