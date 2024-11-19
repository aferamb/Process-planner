#ifndef NODOLISTAPROCESOS_H
#define NODOLISTAPROCESOS_H
#include "Nucleo.h"

class NodoListaProcesos {
friend class ListaProcesos;
private:
    Proceso proceso;
    NodoListaProcesos* siguiente;
    NodoListaProcesos* anterior;
public:
    NodoListaProcesos();
    NodoListaProcesos(Proceso proceso, NodoListaProcesos*siguiente = NULL, NodoListaProcesos*anterior = NULL);
    ~NodoListaProcesos();
};

#endif // NODOLISTAPROCESOS_H