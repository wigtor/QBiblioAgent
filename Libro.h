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
    bool operator<(Libro *otroLibro);
    bool operator>(Libro *otroLibro);
    bool operator==(Libro *otroLibro);
    //////////////////////////////////

    //Setters
    void setIsbn(int intIsbn);
    void setPrecio(int intPrecio);
    void setNombre(string strNombre);
    void setAutor(string strAutor);
    void setPaginas(int intPaginas);
    void setPeso(int peso);
    void setStock(int intStock);
    void setIdCont(int intId);
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
    int getIdCont();
    //////////////////////////////////

    //Otras funciones

    //////////////////////////////////

private:
    static int idCont;
    static int numOrder; // Codigos: 1->Isbn / 2->Precio / 3->Nombre / 4->Autor / 5->Paginas / 6->Peso / 7->Stock
    static int ORD_ISBN;
    static int ORD_PRECIO;
    static int ORD_NOM;
    static int ORD_AUTOR;
    static int ORD_PAG;
    static int ORD_PESO;
    static int ORD_STOCK;
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

