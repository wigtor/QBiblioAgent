/* 
 * File:   Venta.h
 * Author: Mateo
 *
 * Created on 24 de septiembre de 2010, 11:33 PM
 */

#ifndef VENTA_H
#define	VENTA_H

#include "Cliente.h"
#include "Vendedor.h"
#include "Libro.h"
#include "Fecha.h"

class Vendedor;
class Cliente;

using namespace std;
//#pragma GCC visibility push(default)

class Venta {
public:
    // CONSTRUCTORES, COPIAS, DESTRUCTORES
    Venta();
    Venta(int id, bool correlativo, int idLibro, int idCliente, int idVendedor, int cantidadLibros, int montoTotal, Fecha *fecha);
    Venta(bool correlativo, int idLibro, Libro *libro, int idCliente, Cliente *cliente, int idVendedor, Vendedor *vendedor, int cantidadLibros, int montoTotal, Fecha *fecha);
    Venta(const Venta& orig);
    virtual ~Venta();

    // SETTERS
    static void setIdCont(int idCont);
    static void setNumOrder(int numOrder);
    void setId(int id);
    void setCorrelativo(bool correlativo);
    void setIdLibro(int idLibro);
    void setLibro(Libro *libro);
    void setIdCliente(int idCliente);
    void setCliente(Cliente *cliente);
    void setCantidadLibros(int cantidadLibros);
    void setMontoTotal(int montoTotal);
    void setVendedor(Vendedor *vendedor);
    void setFecha(Fecha *fecha);
    void setIdVendedor(int idVendedor);

    // GETTERS
    static int getIdCont();
    int getId();    
    bool getCorrelativo();    
    int getIdLibro();    
    Libro *getLibro();    
    int getIdCliente();    
    Cliente *getCliente();    
    int getCantidadLibros();   
    int getMontoTotal();   
    Vendedor *getVendedor();   
    Fecha *getFecha();   
    int getIdVendedor();

    // OPERADORES
    bool operator <(const Venta& otraVenta) const;
    bool operator >(const Venta& otraVenta) const;
    bool operator ==(const Venta& otraVenta) const;
    
private:
    static int idCont;
    static int numOrder;
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

