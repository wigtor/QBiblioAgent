/* 
 * File:   CapaIO.cpp
 * Author: victor
 * 
 * Created on 30 de septiembre de 2010, 21:51
 */

#include "CapaIO.h"

string CapaIO::archVentas = "ventas.txt";
string CapaIO::archClientes = "clientes.txt";
string CapaIO::archUsuarios = "usuarios.txt";
string CapaIO::archLibros = "libros.txt";
int CapaIO::VENTA = 1;
int CapaIO::CLIENTE = 2;
int CapaIO::USUARIO = 3;
int CapaIO::LIBRO = 4;

CapaIO::CapaIO() {
    this->fUsuarios = fopen(CapaIO::archUsuarios.c_str(), "r");
    if (this->fUsuarios == NULL)
        this->fUsuarios = fopen(CapaIO::archUsuarios.c_str(), "w");
    this->fVentas = fopen(CapaIO::archVentas.c_str(), "r");
    if (this->fVentas == NULL)
            this->fVentas = fopen(CapaIO::archVentas.c_str(), "w");
    this->fClientes = fopen(CapaIO::archClientes.c_str(), "r");
    if (this->fClientes == NULL)
            this->fClientes = fopen(CapaIO::archClientes.c_str(), "w");
    this->fLibros = fopen(CapaIO::archLibros.c_str(), "r");
    if (this->fLibros == NULL)
            this->fLibros = fopen(CapaIO::archLibros.c_str(), "w");
    fclose(this->fUsuarios);
    fclose(this->fVentas);
    fclose(this->fClientes);
    fclose(this->fLibros);
}


CapaIO::~CapaIO(){
}

ListaEstatica<Vendedor> *leeUsuarios(){
    ListaEstatica<Vendedor> *lVendedores = new ListaEstatica<Vendedor>();


    return lVendedores;
}

ListaEnlazada<Venta> *leeVentas(){
    ListaEnlazada<Venta> *lVentas = new ListaEnlazada<Venta>();


    return lVentas;
}
ListaEnlazada<Cliente> *leeClientes(){
    ListaEnlazada<Cliente> *lClientes = new ListaEnlazada<Cliente>();


    return lClientes;
}
ListaEnlazada<Libro> *leeLibros(){
    ListaEnlazada<Libro> *lLibros = new ListaEnlazada<Libro>();


    return lLibros;
}

int escribeIdFile(int contId, int tipoId){

    return 0;
}

int CapaIO::leeIdFile(int tipoId)
{   int idInicial = 0;
    if (tipoId == CapaIO::USUARIO)
        this->file = fopen(CapaIO::archUsuarios.c_str(), "r");
    if (tipoId == CapaIO::LIBRO)
        this->file = fopen(CapaIO::archLibros.c_str(), "r");
    if (tipoId == CapaIO::VENTA)
            this->file = fopen(CapaIO::archVentas.c_str(), "r");
    if (tipoId == CapaIO::CLIENTE)
            this->file = fopen(CapaIO::archClientes.c_str(), "r");;
        stringstream lineaDatos;
        char caracterLeido = 0;
        unsigned long long i, j;
        for (i = 0; (caracterLeido != EOF) && idInicial == 0; i++)
        {       caracterLeido = getc(this->fUsuarios);
                /**Comienza a leer datos desde que encuentra un caracter '<' */
                if (caracterLeido == '<')
                {	for (j = 0; ((caracterLeido != -1) && (caracterLeido != '>')); j++) //ver que el -1 que se almacena si llego al final del archivo. en teoria no debe ocurrir se antes compruebo sintaxis.
                        {	lineaDatos << caracterLeido;
                                caracterLeido = getc(this->fUsuarios);
                        }
                        lineaDatos << caracterLeido;//agrego el caracter '>' que no fue agregado en el bucle
                        i += j; //sumo los caracteres que ya se han leido a i, aun no se si esto pueda ser necesario a futuro.
                }
                // Como se ha encontrado una linea con una especificacion de un objeto, ahora proceso esa linea y agrego el objeto que retorna el metodo analizaLinea */
                idInicial = this->stringToId(lineaDatos.str());
                lineaDatos.str("");
        }
        fclose(this->file);
        return idInicial;
}

int CapaIO::stringToId(string linea)
{   if (linea.find("<id") != string::npos)
    {   size_t posInicioId = linea.find("\"", 0);
        size_t posFinalId = linea.find("\"", posInicioId+1);
        string idStr = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        return atoi(idStr.c_str());
    }
    else
        return 0;
}
Venta *CapaIO::stringToVenta(string linea)
{   if (linea.find("<Venta") != string::npos)
    {   int idObj, idLibro, idCliente, idVendedor, cantidadLibros, montoTotal;
        bool correlativo = false;
        Fecha *fecha;
        //Busco el valor del idObj
        size_t posInicioId = linea.find("idObj", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        size_t posFinalId = linea.find("\"", posInicioId+1);
        idObj = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor del idLibro
        posInicioId = linea.find("idLibro", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        idLibro = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor del idCLiente
        posInicioId = linea.find("idCliente", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        idCliente = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor del idVendedor
        posInicioId = linea.find("idVendedor", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        idVendedor = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor de cantidadLibros
        posInicioId = linea.find("cantidadLibros", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        cantidadLibros = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor de montoTotal
        posInicioId = linea.find("montoTotal", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        montoTotal = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor de fecha
        posInicioId = linea.find("fecha", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("|", posInicioId+1);
        int dia = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        posInicioId = posFinalId;
        posFinalId = linea.find("|", posInicioId+1);
        int mes = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        posInicioId = posFinalId;
        posFinalId = linea.find("\"", posInicioId+1);
        int anno = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());

        fecha = new Fecha(dia, mes, anno);
        //Busco el valor de correlativo
        posInicioId = linea.find("correlativo", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        correlativo = linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str(); //MALO

        Venta *ventaCreada = new Venta(idObj, correlativo, idLibro, idCliente, idVendedor, cantidadLibros, montoTotal, fecha);
        return ventaCreada;
    }
    else
        return NULL;
}
Cliente *CapaIO::stringToCliente(string linea)
{
    return NULL;
}

Vendedor *CapaIO::stringToVendedor(string linea)
{
    return NULL;
}

Libro *CapaIO::stringToLibro(string linea)
{
    return NULL;
}
string CapaIO::idToString(int id, int tipoId)
{   stringstream lineaId;
    if (tipoId == CapaIO::CLIENTE)
    {   lineaId << "<idCliente=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::VENTA)
    {   lineaId << "<idVenta=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::USUARIO)
    {   lineaId << "<idUsuario=\"" << id << "\" >";
        return lineaId.str();
    }
    if (tipoId == CapaIO::LIBRO)
    {   lineaId << "<idLibro=\"" << id << "\" >";
        return lineaId.str();
    }
    //Si el código id indicado como argumento no es válido entonces retorno NULL
    return NULL;
}

string CapaIO::ventaToString(Venta *venta)
{   stringstream linea;
    linea << "<Venta ";
    linea << "idObj=\"" << venta->getId() << "\" ";
    linea << "correlativo=\"" << venta->getCorrelativo() << "\" ";
    linea << "idLibro=\"" << venta->getIdLibro() << "\" ";
    linea << "idCliente=\"" << venta->getIdCliente() << "\" ";
    linea << "cantidadLibros=\"" << venta->getCantidadLibros() << "\" ";
    linea << "montoTotal=\"" << venta->getMontoTotal() << "\" ";
    linea << "vendedor=\"" << venta->getIdVendedor() << "\" ";
    linea << "fecha=\"" << (venta->getFecha())->toString();//malo
    linea <<  "\" >";
    return linea.str();
}

string CapaIO::clienteToString(Cliente *cliente)
{   stringstream linea;
    int i;
    ListaEnlazada<Venta> *listaCompras;
    ListaEstatica<int> *listaTelefonos;
    linea << "<Cliente ";
    linea << "idObj=\"" << cliente->getId() <<"\" ";
    linea << "rut=\"" << cliente->getRut() << "\" ";
    linea << "nombre=\"" << cliente->getNombre() << "\" ";
    linea << "edad=\"" << cliente->getEdad() << "\" ";
    linea << "direccion=\"" << cliente->getDireccion() << "\" ";
    linea << "telefonos=\"";
    listaTelefonos = cliente->getTelefonos();
    for (i = 0; i < listaTelefonos->longitud(); i++)
        linea << *(static_cast<int *>(listaTelefonos->recuperar(i))) << "|";
    linea << "\" "<< "email=\"" << cliente->getEmail() << "\" ";
    listaCompras = cliente->getComprasHechas();
    linea << "idComprasHechas=\"";
    for (i = 0; i < listaCompras->longitud(); i++)
        linea << (static_cast<Venta *>(listaCompras->recuperar(i)))->getId() << "|";
    linea  << "\" >";
    return linea.str();
}

string CapaIO::vendedorToString(Vendedor *vendedor)
{   stringstream linea;
    int i;
    ListaEnlazada<Venta> *listaVentas;
    ListaEstatica<int> *listaTelefonos;
    linea << "Vendedor ";
    linea << "idObj=\"" << vendedor->getId() << "\" ";
    linea << "rut=\"" << vendedor->getRut() << "\" ";
    linea << "nombre=\"" << vendedor->getNombre() << "\" ";
    linea << "edad=\"" << vendedor->getEdad() << "\" ";
    linea << "direccion=\"" << vendedor->getDireccion() << "\" ";
    linea << "telefonos=\"";
    listaTelefonos = vendedor->getTelefonos();
    for (i = 0; i < listaTelefonos->longitud(); i++)
        linea << *(static_cast<int *>(listaTelefonos->recuperar(i))) << "|";
    linea << "\" "<< "ventas=\"";
    listaVentas = vendedor->getVentas();
    for (i = 0; i < listaVentas->longitud(); i++)
        linea << (static_cast<Venta *>(listaVentas->recuperar(i)))->getId() << "|";
    linea << "\" >";
    return linea.str();
}

string CapaIO::libroToString(Libro *libro)
{   stringstream linea;
    linea << "Libro ";
    linea << "idObj=\"" << libro->getId() << "\" ";
    linea << "isbn=\"" << libro->getIsbn() << "\" ";
    linea << "precio=\"" << libro->getPrecio() << "\" ";
    linea << "nombre=\"" << libro->getNombre() << "\" ";
    linea << "autor=\"" << libro->getAutor() << "\" ";
    linea << "paginas=\"" << libro->getPaginas() << "\" ";
    linea << "peso=\"" << libro->getPeso() << "\" ";
    linea << "stock=\"" << libro->getStock() << "\" ";
    linea << " >";
    return linea.str();
}

