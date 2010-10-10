#-------------------------------------------------
#
# Project created by QtCreator 2010-10-02T21:34:52
#
#-------------------------------------------------

#QT       += core

QT       -= gui \
    core

TARGET = QBiblioAgent
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Venta.cpp \
    Nodo.cpp \
    Cliente.cpp \
    Libro.cpp \
    CapaIO.cpp \
    Vendedor.cpp \
    Admin.cpp \
    Fecha.cpp \
    ReferListas.cpp

HEADERS += \
    ListaEstatica.h \
    Nodo.h \
    Venta.h \
    Libro.h \
    ListaEnlazada.h \
    CapaIO.h \
    Cliente.h \
    Vendedor.h \
    Admin.h \
    Fecha.h \
    ReferListas.h
