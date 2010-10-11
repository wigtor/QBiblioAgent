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

CapaIO::CapaIO()
{   this->fUsuarios = fopen(CapaIO::archUsuarios.c_str(), "r");
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


CapaIO::~CapaIO()
{
}


int CapaIO::escribeUsuarios(ListaEstatica<Vendedor> *listaUsuarios)
{

    return 0;
}

int CapaIO::escribeVentas(ListaEnlazada<Venta> *listaVentas)
{

    return 0;
}

int CapaIO::escribeClientes(ListaEnlazada<Cliente> *listaClientes)
{

    return 0;
}

int CapaIO::escribeLibros(ListaEnlazada<Libro> *listaLibros)
{

    return 0;
}

int CapaIO::escribeIdFile(int contId, int tipoId)
{

    return 0;
}

ListaEstatica<Vendedor> *CapaIO::leeUsuarios()
{
    ListaEstatica<Vendedor> *lVendedores = new ListaEstatica<Vendedor>();
    this->fUsuarios = fopen(CapaIO::archUsuarios.c_str(), "r");
    stringstream lineaDatos;
    char caracterLeido = 0;
    unsigned long long i, j;
    /** Leo el archivo de usuarios hasta el final */
    for (i = 0; caracterLeido != -1; i++)
    {	caracterLeido = getc(this->fUsuarios);
    /**Comienza a leer datos desde que encuentra un caracter '<' */
    if (caracterLeido == '<')
    {	for (j = 0; ((caracterLeido != EOF) && (caracterLeido != '>')); j++) //ver que el -1 que se almacena si llego al final del archivo. en teoria no debe ocurrir se antes compruebo sintaxis.
        {   lineaDatos << caracterLeido;
            caracterLeido = getc(this->fUsuarios);
        }
        caracterLeido = getc(this->fUsuarios);//agrego el caracter '>' que no fue agregado en el bucle
        i += j; //sumo los caracteres que ya se han leido a i, aun no se si esto pueda ser necesario a futuro.
    }
    /** Como se ha encontrado una linea con una especificacion de un objeto, ahora proceso esa linea y agrego el objeto que retorna el metodo analizaLinea */
    Vendedor *vendedorEncontrado = this->stringToVendedor(lineaDatos.str());
    if (vendedorEncontrado != NULL)
        lVendedores->agregar(vendedorEncontrado);
    lineaDatos.str("");
    }
    /** Cierro el archivo*/
    fclose(this->fUsuarios);
    return lVendedores;
}

ListaEnlazada<Venta> *CapaIO::leeVentas()
{   ListaEnlazada<Venta> *lVentas = new ListaEnlazada<Venta>();
    this->fVentas = fopen(CapaIO::archVentas.c_str(), "r");
    stringstream lineaDatos;
    char caracterLeido = 0;
    unsigned long long i, j;
    /** Leo el archivo de ventas hasta el final */
    for (i = 0; caracterLeido != -1; i++)
    {	caracterLeido = getc(this->fVentas);
    /**Comienza a leer datos desde que encuentra un caracter '<' */
    if (caracterLeido == '<')
    {	for (j = 0; ((caracterLeido != EOF) && (caracterLeido != '>')); j++) //ver que el -1 que se almacena si llego al final del archivo. en teoria no debe ocurrir se antes compruebo sintaxis.
        {   lineaDatos << caracterLeido;
            caracterLeido = getc(this->fVentas);
        }
        caracterLeido = getc(this->fVentas);//agrego el caracter '>' que no fue agregado en el bucle
        i += j; //sumo los caracteres que ya se han leido a i, aun no se si esto pueda ser necesario a futuro.
    }
    /** Como se ha encontrado una linea con una especificacion de un objeto, ahora proceso esa linea y agrego el objeto que retorna el metodo analizaLinea */
    Venta *ventaEncontrada = this->stringToVenta(lineaDatos.str());
    if (ventaEncontrada != NULL)
        lVentas->agregar(ventaEncontrada);
    lineaDatos.str("");
    }
    /** Cierro el archivo*/
    fclose(this->fVentas);
    return lVentas;
}

ListaEnlazada<Cliente> *CapaIO::leeClientes()
{   ListaEnlazada<Cliente> *lClientes = new ListaEnlazada<Cliente>();
    this->fClientes = fopen(CapaIO::archClientes.c_str(), "r");
    stringstream lineaDatos;
    char caracterLeido = 0;
    unsigned long long i, j;
    /** Leo el archivo de clientes hasta el final */
    for (i = 0; caracterLeido != -1; i++)
    {	caracterLeido = getc(this->fClientes);
    /**Comienza a leer datos desde que encuentra un caracter '<' */
    if (caracterLeido == '<')
    {	for (j = 0; ((caracterLeido != EOF) && (caracterLeido != '>')); j++) //ver que el -1 que se almacena si llego al final del archivo. en teoria no debe ocurrir se antes compruebo sintaxis.
        {   lineaDatos << caracterLeido;
            caracterLeido = getc(this->fClientes);
        }
        caracterLeido = getc(this->fClientes);//agrego el caracter '>' que no fue agregado en el bucle
        i += j; //sumo los caracteres que ya se han leido a i, aun no se si esto pueda ser necesario a futuro.
    }
    /** Como se ha encontrado una linea con una especificacion de un objeto, ahora proceso esa linea y agrego el objeto que retorna el metodo analizaLinea */
    Cliente *clienteEncontrado = this->stringToCliente(lineaDatos.str());
    if (clienteEncontrado != NULL)
        lClientes->agregar(clienteEncontrado);
    lineaDatos.str("");
    }
    /** Cierro el archivo*/
    fclose(this->fClientes);

    return lClientes;
}

ListaEnlazada<Libro> *CapaIO::leeLibros()
{   ListaEnlazada<Libro> *lLibros = new ListaEnlazada<Libro>();
    this->fLibros = fopen(CapaIO::archLibros.c_str(), "r");
    stringstream lineaDatos;
    char caracterLeido = 0;
    unsigned long long i, j;
    /** Leo el archivo de libros hasta el final */
    for (i = 0; caracterLeido != -1; i++)
    {	caracterLeido = getc(this->fLibros);
    /**Comienza a leer datos desde que encuentra un caracter '<' */
    if (caracterLeido == '<')
    {	for (j = 0; ((caracterLeido != EOF) && (caracterLeido != '>')); j++) //ver que el -1 que se almacena si llego al final del archivo. en teoria no debe ocurrir se antes compruebo sintaxis.
        {   lineaDatos << caracterLeido;
            caracterLeido = getc(this->fLibros);
        }
        caracterLeido = getc(this->fLibros);//agrego el caracter '>' que no fue agregado en el bucle
        i += j; //sumo los caracteres que ya se han leido a i, aun no se si esto pueda ser necesario a futuro.
    }
    /** Como se ha encontrado una linea con una especificacion de un objeto, ahora proceso esa linea y agrego el objeto que retorna el metodo analizaLinea */
    Libro *LibroEncontrado = this->stringToLibro(lineaDatos.str());
    if (LibroEncontrado != NULL)
        lLibros->agregar(LibroEncontrado);
    lineaDatos.str("");
    }
    /** Cierro el archivo*/
    fclose(this->fLibros);
    return lLibros;
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
    return NULL;
}

Cliente *CapaIO::stringToCliente(string linea)
{   if (linea.find("<Cliente") != string::npos)
    {   int idObj, rut, edad;
        string nombre, direccion, email, stringTemp;
        //Busco el valor del idObj
        size_t posInicioId = linea.find("idObj", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        size_t posFinalId = linea.find("\"", posInicioId+1);
        idObj = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor del rut
        posInicioId = linea.find("rut", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        rut = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor de la edad
        posInicioId = linea.find("edad", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        edad = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco la direccion
        posInicioId = linea.find("direccion", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        direccion = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        //Busco el email
        posInicioId = linea.find("email", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        direccion = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        //Busco los telefonos
        ListaEstatica<int> *listaTelefonos = new ListaEstatica<int>();
        posInicioId = linea.find("telefonos", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        stringTemp = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        posInicioId = 0;
        while (stringTemp != "") //REVISAR SI ESTA BUENO
        {   posFinalId = stringTemp.find("|", posInicioId+1);
            listaTelefonos->agregar(new int(atoi(stringTemp.substr(posInicioId+1, posFinalId - posInicioId-1).c_str())));
            stringTemp = stringTemp.substr(posFinalId - posInicioId-1, stringTemp.length()-(posFinalId - posInicioId-1));
        }
        //Busco los id de las ventas hechas
        ListaEnlazada<int> *listaIdsCompras = new ListaEnlazada<int>();
        posInicioId = linea.find("ventas", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        stringTemp = linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str();
        posInicioId = 0;
        while (stringTemp != "") //REVISAR SI ESTA BUENO
        {   posFinalId = stringTemp.find("|", posInicioId+1);
            listaIdsCompras->agregar(new int(atoi(stringTemp.substr(posInicioId+1, posFinalId - posInicioId-1).c_str())));
            stringTemp = stringTemp.substr(posFinalId - posInicioId-1, stringTemp.length()-(posFinalId - posInicioId-1));
        }

        Cliente *clienteCreado = new Cliente( idObj, rut, nombre, edad, direccion, listaTelefonos, email, listaIdsCompras);
        return clienteCreado;
    }
    return NULL;
}

Vendedor *CapaIO::stringToVendedor(string linea)
{   if (linea.find("<Vendedor") != string::npos)
    {   int idObj, rut, edad;
        string nombre, direccion, stringTemp;
        //Busco el valor del idObj
        size_t posInicioId = linea.find("idObj", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        size_t posFinalId = linea.find("\"", posInicioId+1);
        idObj = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el valor del rut
        posInicioId = linea.find("rut", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        rut = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco el nombre
        posInicioId = linea.find("nombre", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        nombre = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        //Busco el valor de la edad
        posInicioId = linea.find("edad", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        edad = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
        //Busco la direccion
        posInicioId = linea.find("direccion", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        direccion = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        //Busco los telefonos
        ListaEstatica<int> *listaTelefonos = new ListaEstatica<int>();
        posInicioId = linea.find("telefonos", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        stringTemp = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
        posInicioId = 0;
        while (stringTemp != "") //REVISAR SI ESTA BUENO
        {   posFinalId = stringTemp.find("|", posInicioId+1);
            listaTelefonos->agregar(new int(atoi(stringTemp.substr(posInicioId+1, posFinalId - posInicioId-1).c_str())));
            stringTemp = stringTemp.substr(posFinalId - posInicioId-1, stringTemp.length()-(posFinalId - posInicioId-1));
        }
        //Busco los id de las ventas hechas
        ListaEnlazada<int> *listaIdsVentas = new ListaEnlazada<int>();
        posInicioId = linea.find("ventas", 0);
        posInicioId = linea.find("\"", posInicioId+1);
        posFinalId = linea.find("\"", posInicioId+1);
        stringTemp = linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str();
        posInicioId = 0;
        while (stringTemp != "") //REVISAR SI ESTA BUENO
        {   posFinalId = stringTemp.find("|", posInicioId+1);
            listaIdsVentas->agregar(new int(atoi(stringTemp.substr(posInicioId+1, posFinalId - posInicioId-1).c_str())));
            stringTemp = stringTemp.substr(posFinalId - posInicioId-1, stringTemp.length()-(posFinalId - posInicioId-1));
        }
        return new Vendedor(idObj, rut, nombre, edad, direccion, listaTelefonos, listaIdsVentas);
    }
    return NULL;
}

Libro *CapaIO::stringToLibro(string linea)
{   if (linea.find("<Libro") != string::npos)
    {       int idObj, isbn, precio, paginas, peso, stock;
            string nombre, autor;
            //Busco el valor del idObj
            size_t posInicioId = linea.find("idObj", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            size_t posFinalId = linea.find("\"", posInicioId+1);
            idObj = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco el valor del isbn
            posInicioId = linea.find("isbn", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            isbn = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco el valor del precio
            posInicioId = linea.find("precio", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            precio = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco las paginas
            posInicioId = linea.find("ipaginas", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            paginas = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco el valor de cantidadLibros
            posInicioId = linea.find("peso", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            peso = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco el valor de montoTotal
            posInicioId = linea.find("stock", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            stock = atoi(linea.substr(posInicioId+1, posFinalId - posInicioId-1).c_str());
            //Busco el nombre
            posInicioId = linea.find("nombre", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            nombre = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
            //Busco el autor
            posInicioId = linea.find("autor", 0);
            posInicioId = linea.find("\"", posInicioId+1);
            posFinalId = linea.find("\"", posInicioId+1);
            autor = linea.substr(posInicioId+1, posFinalId - posInicioId-1);
            return new Libro(idObj, isbn, nombre, autor, precio, paginas, peso, stock);
    }
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
    linea << "fecha=\"" << (venta->getFecha())->toString();
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

