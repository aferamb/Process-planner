#include "NodoListaProcesos.h"
#include "Proceso.h"


/**
 * @brief Constructor por defecto de la clase NodoListaProcesos
 * 
 */
NodoListaProcesos::NodoListaProcesos(){
    Proceso proceso;
    siguiente = NULL;
    anterior = NULL;
}


/**
 * @brief Constructor de la clase NodoListaProcesos
 * 
 * @param Proceso 
 * @param sig 
 * @param ant 
 */
NodoListaProcesos::NodoListaProcesos(Proceso proceso, NodoListaProcesos* sig, NodoListaProcesos* ant){
    this->proceso = proceso;
    this->siguiente = sig;
    this->anterior = ant;
}


/**
 * @brief Destructor de la clase NodoListaProcesos
 * 
 */
NodoListaProcesos::~NodoListaProcesos(){
    //dtor
}
