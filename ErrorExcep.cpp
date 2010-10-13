/*
 * File:   ErrorExcep.c
 * Author: AirZs
 *
 * Creado el 12 de octubre de 2010, 16:19
 */

#include "ErrorExcep.h"

ErrorExcep::ErrorExcep(int m){
    this->motivo = m;
}
ErrorExcep::ErrorExcep(int m, string strNombre){
    this->motivo = m;
    this->nombreInstancia = strNombre;
}

ErrorExcep::ErrorExcep(int m, string strNombre, int id){
    this->motivo = m;
    this->nombreInstancia = strNombre;
    this->idObjetoError = id;

}

const char* ErrorExcep::descError() const throw(){
    switch (this->motivo){
        case E_REFERT:
            return "Error en la creacion de las referencias"; break;

        default:
            return "Error desconocido;"; break;
    }
}



