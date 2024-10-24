#include "Lista.h"
#include "Nucleo.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Lista:: Lista object
 * 
 */
Lista::Lista() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}


/**
 * @brief Destroy the Lista:: Lista object
 * 
 */
Lista::~Lista() {
    while (primero) {
        NodoLista* aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}


