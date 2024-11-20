
#ifndef NODOABB_H
#define NODOABB_H

#include "ListaProcesos.h"

class NodoABB{
private:
    int prioridad;
    
    ListaProcesos elemento;
    NodoABB *izquierda;
    NodoABB *derecha;

public:
    NodoABB();
    NodoABB(int prioridad);
    
    ListaProcesos get_ListaProcesos();
    void set_ListaProcesos(ListaProcesos);
    
    NodoABB* get_izquierda();
    void set_izquierda(NodoABB*);
    
    NodoABB* get_derecha();
    void set_derecha(NodoABB*);

    int get_prioridad();
    void set_prioridad(int prioridad);

    ~NodoABB();
};

#endif
