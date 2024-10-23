#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Proceso.h"
#include <iostream>

class NodoCola 
{
friend class Cola;
private:
    NodoCola *siguiente;
    Proceso proceso;
    int prioridad;
    //friend class Cola;
public:
    NodoCola();
    NodoCola(Proceso proceso, int prioridad, NodoCola*sig = NULL);
    ~NodoCola();
};
#endif // NODOCOLA_H