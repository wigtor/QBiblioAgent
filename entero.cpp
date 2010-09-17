/*
 * File:   entero.cpp
 * Author: victor
 *
 * Created on 12 de septiembre de 2010, 18:48
 */



//CLASE DE PRUEBA PARA USARLA COMO ELEMENTOS DE LISTAENLAZADA
#include "entero.h"

entero::entero() {
	this->valor = 0;
}

entero::entero(int val) {
	this->valor = val;
}

void entero::setVal(int val) {
	this->valor = val;
}

int entero::getVal() {
	return this->valor;
}

