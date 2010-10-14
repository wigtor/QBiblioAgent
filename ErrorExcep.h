/*
 * File:   ErrorExcep.h
 * Author: AirZs
 *
 * Creado el 12 de octubre de 2010, 16:19
 */

#ifndef ERROREXCEP_H
#define ERROREXCEP_H
#include <string>

using namespace std;

//Codigos de error

/*Sigan la siguiente nomenclatura: son 2 digitos,
  son para identificar el tipo de error.
  La tabla es la siguiente:

     ---------------------------------------------------------------------------------------------
    /    Clase    |codClase|CodError|       Constante       |              TipoError              \
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |    Admin    |   0    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |             |        |        |                       ||
    | AdminListas |   1    |   0    |E_PAGINAS              |Error debido a que el nº de paginas   |
    |             |        |        |                       |introducidas no es convertibles a int.|
    |             |        |   1    |E_EDAD                 |Error debido a que el rut no es       |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   2    |E_RUT                  |Error debido a que el rut no es       |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   3    |E_ISBN                 |Error debido a que el isbn no es      |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   4    |E_PRECIO               |Error debido a que el precio no es    |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   5    |E_PESO                 |Error debido a que el peso no es      |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   6    |E_STOCK                |Error debido a que el stock no es     |
    |             |        |        |                       |convertible a int.                    |
    |             |        |   7    |E_POSLIBRO_NO_EXIST    |Error debido a que la posicion del    |
    |             |        |        |                       |libro no corresponde.                 |
    |             |        |   8    |E_POS_CLIENTE_NO_EXISTE|Error debido a que la posicion del    |
    |             |        |        |                       |cliente no corresponde.               |
    |             |        |   9    |E_POS_VEND_NO_EXISTE   |Error debido a que la posicion del    |
    |             |        |        |                       |vendedor no corresponde.              |
    |             |        |   A    |E_CANT_LIBROS          |Error debido a que en la venta no se  |
    |             |        |        |                       |transa ningun libro.                  |
    |             |        |   B    |E_NOMB_REP             |Error debido a que el nombre ya existe|
    |             |        |        |                       |en la base.                           |
    |             |        |   C    |E_ISBN_REP             |Error debido a que el isbn ya existe  |
    |             |        |        |                       |en la base.                           |
    |             |        |   D    |E_MONTO                |Error debido a que el monto de la     |
    |             |        |        |                       |venta es cero.                        |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |   CapaIO    |   2    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |   Cliente   |   3    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |    Fecha    |   4    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |    Libro    |   5    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |ListaEnlazada|   6    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |ListaEstatica|   7    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |    Nodo     |   8    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    | ReferListas |   9    |   0    |E_REFERT               |Error debido a la no realizacion      |
    |             |        |        |                       |completa de las referencias.          |
    |             |        |   1    |E_VENTASINREFERENCIAS  |Error debido a que la venta no tiene  |
    |             |        |        |                       |el cliente ni el vendedor existentes  |
    |             |        |        |                       |en la base.                           |
    |             |        |   2    |E_VENTASINCLIENTE      |Error debido a que la venta no tiene  |
    |             |        |        |                       |un cliente existente en la base.      |
    |             |        |   3    |E_VENTASINVENDEDOR     |Error debido a que la venta no tiene  |
    |             |        |        |                       |un vendedor existente en la base.     |
    |             |        |   4    |E_VENDSINVENTA         |Error debido a que el vendedor tiene  |
    |             |        |        |                       |una venta inexistente en la base.     |
    |             |        |   5    |E_CLIENTESINVENTA      |Error debido a que el cliente tiene   |
    |             |        |        |                       |una venta inexistente en la base.     |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |   Vendedor  |   A    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |    Venta    |   B    |        |                       |                                      |
    |-------------|--------|--------|-----------------------|--------------------------------------|
    |             |        |        |||
    |             |        |        |                       ||
    \-------------|--------|--------|-----------------------|-------------------------------------/

*/
//Constantes AdminListas
#define E_PAGINAS               0x10
#define E_EDAD                  0x11
#define E_RUT                   0x12
#define E_ISBN                  0x13
#define E_PRECIO                0x14
#define E_PESO                  0x15
#define E_STOCK                 0x16
#define E_CANT_LIBROS           0x17

#define E_POS_LIBRO_NO_EXISTE   0x18
#define E_POS_CLIENTE_NO_EXISTE 0x19
#define E_POS_VEND_NO_EXISTE    0x1A

#define E_NOMB_REP              0x1B
#define E_RUT_REP               0x1C
#define E_ISBN_REP              0x1D
#define E_MONTO                 0x1E
#define E_TELEFONO              0x1F
#define E_MAIL                  0x20
#define E_NOMB_VAC              0x21
#define E_TEL_REP               0x22
#define E_TEL_NO_EXISTE         0x23

//Constantes ReferListas
#define E_REFERT                0x90
#define E_VENTASINREFERENCIAS   0x91
#define E_VENTASINCLIENTE       0x92
#define E_VENTASINVENDEDOR      0x93
#define E_VENDSINVENTA          0x94
#define E_CLIENTESINVENTA       0x95


class ErrorExcep{
public:
    ErrorExcep();
    ErrorExcep(int m);
    ErrorExcep(int m, string strNombre);
    ErrorExcep(int m, string strNombre, int id);
    int getMotivo();
    const char* descError() const throw();

private:
    int motivo;
    string nombreInstancia;
    int idObjetoError;
};

#endif // ERROREXCEP_H


