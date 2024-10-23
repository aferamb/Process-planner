#include "NodoCola.h"
#include "Proceso.h"


/**
 * @brief Construct a new Nodo Cola:: Nodo Cola object
 * 
 */
NodoCola::NodoCola(){
    Proceso proceso;
    siguiente=NULL;
    prioridad=0; //prioridad por defecto
}


/**
 * @brief Construct a new Nodo Cola:: Nodo Cola object
 * 
 * @param proceso 
 * @param prioridad 
 * @param sig 
 */
NodoCola::NodoCola(Proceso proceso, int prioridad, NodoCola*sig){
    this->proceso = proceso;
    this->siguiente = sig;
    this->prioridad = prioridad;
}


/**
 * @brief Destroy the Nodo Cola:: Nodo Cola object
 * 
 */
NodoCola::~NodoCola(){
 //dtor
}