#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "Proceso.h"

class NodoPila
{
    private:
        Proceso proceso; // Ahora se almacenamos un proceso
        NodoPila *siguiente;
        friend class Pila;
    public:
        NodoPila();
        NodoPila(Proceso p, NodoPila *sig = NULL);
        ~NodoPila();
};

typedef NodoPila *pnodo;
#endif // NODOPILA_H