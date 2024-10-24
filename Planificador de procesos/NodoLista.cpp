#include "NodoLista.h"
#include "Nucleo.h"


/**
 * @brief Construct a new Nodo Lista:: Nodo Lista object
 * 
 */
NodoLista::NodoLista(){
    Nucleo nucleo;
    siguiente = NULL;
    anterior = NULL;
}


/**
 * @brief Construct a new Nodo Lista:: Nodo Lista object
 * 
 * @param nucleo 
 * @param sig 
 * @param ant 
 */
NodoLista::NodoLista(Nucleo nucleo, NodoLista* sig, NodoLista* ant){
    this->nucleo = nucleo;
    this->siguiente = sig;
    this->anterior = ant;
}


/**
 * @brief Destroy the Nodo Lista:: Nodo Lista object
 * 
 */
NodoLista::~NodoLista(){
    //dtor
}
