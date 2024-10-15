#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>

class NodoCola 
{
friend class Cola;
private:
    NodoCola *siguiente;
    char elemento;
    int prioridad;
public:
    NodoCola();
    NodoCola(char e, int prioridad, NodoCola*sig = NULL);
    ~NodoCola();
};
#endif // NODOCOLA_H