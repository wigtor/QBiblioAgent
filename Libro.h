/* 
 * File:   Libro.h
 * Author: victor
 *
 * Created on 30 de septiembre de 2010, 15:18
 */

#ifndef LIBRO_H
#define	LIBRO_H

#include <string>
using namespace std;

class Libro {
public:
    // Constructores y obligatorios
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    ///////////////////////////////

    //Setters
    void setPrecio(int intPrecio);
    void setAutor(string strAutor);
    void setPaginas(int intPaginas);
    void setPeso(int intPeso);
    void setStock(int intStock);
    ///////////////////////////////

    //Getters
    int getId();
    int getIsbn();
    int getPrecio();
    string getNombre();
    string getAutor();
    int getPaginas();
    int getPeso();
    int getStock();
    ///////////////////////////////

    //Otras funciones
    ///////////////////////////////

private:
    static int idCont;
    int id;
    int isbn;
    int precio;
    string nombre;
    string autor;
    int paginas;
    int peso; //gramos
    int stock;
};

#endif	/* LIBRO_H */


