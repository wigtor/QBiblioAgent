/* 
 * File:   Libro.h
 * Author: AirZs
 *
 * Created on 25 de septiembre de 2010, 21:16
 */

#ifndef LIBRO_H
#define	LIBRO_H

//Constantes
#define	ORD_L_ISBN = 1;
#define	ORD_L_PRECIO = 2;
#define	ORD_L_NOM = 3;
#define	ORD_L_AUTOR = 4;
#define	ORD_L_PAG = 5;
#define	ORD_L_PESO = 6;
#define	ORD_L_STOCK = 7;



#include <string>

using namespace std;
//#pragma GCC visibility push(default)

class Libro{
public:
    //Iniciadores y obligatorios
    Libro(int id, int isbn, string nombre, string autor, int precio, int paginas, int peso, int stock); //constructor para CapaIO
    Libro(int intIsbn, string strNombre, string strAutor);
    Libro(const Libro& orig);
    virtual ~Libro();
    bool operator<(const Libro& otroLibro);
    bool operator>(const Libro& otroLibro);
    bool operator==(const Libro& otroLibro);
    //////////////////////////////////

    //Setters
    void setIsbn(int intIsbn);
    void setPrecio(int intPrecio);
    void setNombre(string strNombre);
    void setAutor(string strAutor);
    void setPaginas(int intPaginas);
    void setPeso(int peso);
    void setStock(int intStock);
    static void setIdCont(int intId);
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
    static int getIdCont();
    //////////////////////////////////

    //Otras funciones

    //////////////////////////////////

private:
    static int idCont;
    static int numOrder; // Codigos: 1->Isbn / 2->Precio / 3->Nombre / 4->Autor / 5->Paginas / 6->Peso / 7->Stock
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

