/* 
 * File:   Libro.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 21:16
 */

#ifndef LIBRO_H
#define	LIBRO_H


#include <string>
using namespace std;


class Libro{
public:
    //Iniciadores y obligatorios
    Libro();
    Libro(int intIsbn, string strNombre, string strAutor);
    Libro(const Libro& orig);
    ~Libro();
    //////////////////////////////////

    //Setters
    void setIsbn(int intIsbn);
    void setPrecio(int intPrecio);
    void setNombre(string strNombre);
    void setAutor(string strAutor);
    void setPaginas(int intPaginas);
    void setPeso(int peso);
    void setStock(int intStock);
    //LOS METODOS NECESITAN UN VALOR DE RETORNO, VOID SI NO DEVUELVEN VALOR
    //SE PUEDE OMITIR EL "VOID" EN LAS FUNCIONES SIN ARGUMENTOS
    //////////////////////////////////

    //Getters
    int getId();
    int getIsbn();
    int getPrecio();
    string getNombre();
    string getAutor();
    int getPaginas();
    int getPeso();
    int getStock();
    //////////////////////////////////

    //Otras funciones

    //////////////////////////////////

private:
    int id;
    int isbn;
    int precio;
    string nombre;
    string autor;
    int paginas;
    int peso;
    int stock;
};

#endif	/* LIBRO_H */

