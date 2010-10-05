/* 
 * File:   Venta.h
 * Author: Mateo
 *
 * Created on 24 de septiembre de 2010, 11:33 PM
 */


#ifndef VENTA_H
#define	VENTA_H

#include "Cliente.h"
#include "Libro.h"
#include "Vendedor.h"
#include "Fecha.h"

using namespace std;

class Venta {
public:
    Venta();
    Venta(bool correlativo, int idLibro, Libro *libro, int idCliente, Cliente *cliente, int idVendedor, Vendedor *vendedor, int cantidadLibros, int montoTotal, Fecha *fecha);
    Venta(int id, bool correlativo, int idLibro, int idCliente, int idVendedor, int cantidadLibros, int montoTotal, Fecha *fecha);
    Venta(const Venta& orig);
    virtual ~Venta();
    bool getCorrelativo();
    void setCorrelativo(bool correlativo);
    int getIdLibro();
    void setIdLibro(int idLibro);
    Libro *getLibro();
    void setLibro(Libro *libro);
    int getIdCliente();
    int getId();
    void setIdCliente(int idCliente);
    Cliente *getCliente();
    void setCliente(Cliente *cliente);
    int getCantidadLibros();
    void setCantidadLibros(int cantidadLibros);
    int getMontoTotal();
    void setMontoTotal(int montoTotal);
    Vendedor *getVendedor();
    void setVendedor(Vendedor *vendedor);
    Fecha *getFecha();
    void setFecha(Fecha *fecha);
    int getIdVendedor();
    void setIdVendedor(int idVendedor);
private:
    static int idCont;
    bool correlativo;
    int id;
    int idLibro;
    Libro *libro;
    int idCliente;
    Cliente *cliente;
    int cantidadLibros;
    int montoTotal;
    Vendedor *vendedor;
    Fecha *fecha;
    int idVendedor;
};

#endif	/* VENTA_H */

