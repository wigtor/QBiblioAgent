#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;
//#pragma GCC visibility push(default)

class Fecha
{
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Fecha(int dia, int mes, int anno);
    Fecha(const Fecha& orig);
    virtual ~Fecha();

    // SETTERS
    void setDia(int dia);
    void setMes(int mes);
    void setAnno(int anno);

    // GETTERS
    int getDia();
    int getMes();
    int getAnno();

private:
    int dia;
    int mes;
    int anno;

};

#endif // FECHA_H
