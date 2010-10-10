#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;

class Fecha
{
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Fecha(int dia, int mes, int anno);
    Fecha(const Fecha& orig);
    virtual ~Fecha();

    // SETTERS
    void Fecha::setDia(int dia);
    void Fecha::setMes(int mes);
    void Fecha::setAnno(int anno);

    // GETTERS
    int Fecha::getDia();
    int Fecha::getMes();
    int Fecha::getAnno();

private:
    int dia;
    int mes;
    int anno;

};

#endif // FECHA_H
