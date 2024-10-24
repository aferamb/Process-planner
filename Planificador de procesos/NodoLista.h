#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Nucleo.h"

class NodoLista {
friend class Lista;
private:
    Nucleo nucleo;
    NodoLista* siguiente;
    NodoLista* anterior;
public:
    NodoLista();
    NodoLista(Nucleo nucleo, NodoLista*siguiente = NULL, NodoLista*anterior = NULL);
    ~NodoLista();
};

#endif // NODOLISTA_H