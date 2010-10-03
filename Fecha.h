#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;

class Fecha
{
public:
    Fecha(int dia, int mes, int anno);
    Fecha(const Fecha& orig);
    virtual ~Fecha();

private:
    int dia;
    int mes;
    int anno;
};

#endif // FECHA_H
