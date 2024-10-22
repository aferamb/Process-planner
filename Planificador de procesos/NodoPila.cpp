#include "NodoPila.h"


/**
 * @brief Construct a new Nodo Pila:: Nodo Pila object
 * 
 * @param p 
 * @param sig 
 */
NodoPila::NodoPila(Proceso p, NodoPila *sig) {
    proceso = p;
    siguiente = sig;
}


/**
 * @brief Destroy the Nodo Pila:: Nodo Pila object
 * 
 */
NodoPila::~NodoPila()
{
    //dtor
}
