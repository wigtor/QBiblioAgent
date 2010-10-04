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

class Venta {
public:
    Venta();
    Venta(bool correlativo, Libro *libro, Cliente *cliente, int cantidadLibros, int montoTotal, Vendedor *vendedor, Fecha *fecha);
    Venta(const Venta& orig);
    virtual ~Venta();
    int getIdCont();
    void setIdCont(int idCont);
    int getId();
    void setId(int id);
    bool getCorrelativo();
    void setCorrelativo(bool correlativo);
    int getIdLibro();
    void setIdLibro(int idLibro);
    Libro *getLibro();
    void setLibro(Libro *libro);
    int getIdCliente();
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
    int id;
    bool correlativo;
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

