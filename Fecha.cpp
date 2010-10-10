
#include "Fecha.h"

/****************************************
 CONSTRUCTORES, COPIAS, DESTRUCTORES
 ****************************************/

Fecha::Fecha(int dia, int mes, int anno) {

        if (dia < 1 || dia > 31)
            throw dia;
        else if (mes < 1 || mes > 12)
            throw mes;
        else if (anno < 2000 || anno > 2100)
            throw anno;
        else {
            this->dia = dia;
            this->mes = mes;
            this->anno = anno;
        }

}

Fecha::Fecha(const Fecha& orig) {
    this->dia = orig.dia;
    this->mes = orig.mes;
    this->anno = orig.anno;
}

Fecha::~Fecha() {
}

/****************************************
 SETTERS
 ****************************************/

void Fecha::setDia(int dia) {

        if (dia < 1 || dia > 31)
            throw dia;
        else
            this->dia = dia;

}

void Fecha::setMes(int mes) {
        if (mes < 1 || mes > 12)
            throw mes;
        else
            this->mes = mes;

}

void Fecha::setAnno(int anno) {

        if (anno < 2000 || anno > 2100)
            throw anno;
        else
            this->anno = anno;

}

/****************************************
 GETTERS
 ****************************************/

int Fecha::getDia() {
    return this->dia;
}

int Fecha::getMes() {
    return this->mes;
}

int Fecha::getAnno() {
    return this->anno;
}

string Fecha::toString(){
    stringstream linea;
    linea << this->dia << "|"<<this->mes << "|" <<this->anno;
    return linea.str();
}
