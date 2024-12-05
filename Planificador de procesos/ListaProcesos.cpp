#include "ListaProcesos.h"
#include "Proceso.h"
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Lista:: Lista object
 * 
 */
ListaProcesos::ListaProcesos() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}


/**
 * @brief Destroy the Lista:: Lista object
 * 
 */
ListaProcesos::~ListaProcesos() {
    while (primero) {
        NodoListaProcesos* aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}


/**
 * @brief Devuelve el primer proceso de la lista
 * 
 * @return Proceso 
 */
Proceso ListaProcesos::primP() const {
    if (!es_vacia()) {
        return primero->proceso;
    } else {
        cout << "La lista está vacía" << endl;
        return Proceso(); // Devuelve un proceso vacío
    }
}


/**
 * @brief Devuelve el último proceso de la lista
 * 
 * @return Proceso 
 */
Proceso ListaProcesos::ultP() const {
    if (!es_vacia()) {
        return ultimo->proceso;
    } else {
        cout << "La lista está vacía" << endl;
        return Proceso(); // Devuelve un proceso vacío
    }
}


bool ListaProcesos::es_vacia() const {
    return (primero == nullptr);
}


bool ListaProcesos::ordenada_menor_mayor() const {
    if (es_vacia() || primero == ultimo) {
        return true; // Una lista vacía o con un solo elemento está ordenada
    }
    NodoListaProcesos* actual = primero;
    while (actual->siguiente != nullptr) {
        if (actual->proceso.get_prioridad() > actual->siguiente->proceso.get_prioridad()) {
            return false;
        }
        actual = actual->siguiente;
    }
    return true;
}



void ListaProcesos::ordenar_menor_mayor() { // corregir, falta asignar los punteros de anterior y manejar accesos de memoria vacia, NO USAR HASTA QUE SE CORRIJA
    if (es_vacia() || primero == ultimo) {
        return; 
    }
    int posicion = 0;
    bool intercambiado;
    do {
        intercambiado = false;
        NodoListaProcesos* actual = primero;

        while (actual->siguiente != nullptr && posicion < longitud) {
            if (actual->proceso.get_prioridad() > actual->siguiente->proceso.get_prioridad()) {
                // Intercambiar procesos
                Proceso temp = actual->proceso;
                actual->proceso = actual->siguiente->proceso;
                actual->siguiente->proceso = temp;
                intercambiado = true;
            }
            posicion++;
            actual = actual->siguiente;
        }
    } while (intercambiado);
}



int ListaProcesos::get_longitud() const {
    return longitud;
}



void ListaProcesos::insertar_proceso_vacio() { 
    Proceso nuevoProceso;
    NodoListaProcesos* nuevoNodo = new NodoListaProcesos(nuevoProceso, nullptr);

    if (es_vacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }
    longitud++;
}



void ListaProcesos::insertar_proceso(Proceso proc, int posicion) {
    if (posicion < 0 || posicion > longitud) {
        cout << "Posición inválida" << endl;
        return;
    }
    NodoListaProcesos* nuevoNodo = new NodoListaProcesos(proc, nullptr);
    if (posicion == 0) {
        nuevoNodo->siguiente = primero;
        primero->anterior = nuevoNodo;
        primero = nuevoNodo;
    } else if (posicion == longitud) {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    } else {
        NodoListaProcesos* anterior = obtener_nodo(posicion - 1);
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
        NodoListaProcesos* siguiente = nuevoNodo->siguiente;
        siguiente->anterior = nuevoNodo;
        nuevoNodo->anterior = anterior;
    }
    longitud++;
}


void ListaProcesos::insertar_proceso(Proceso proc) {
    NodoListaProcesos* nuevoNodo = new NodoListaProcesos(proc, nullptr);
    if (es_vacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }
    longitud++;
}


void ListaProcesos::sustituir_proceso(Proceso proc, int posicion) {
    NodoListaProcesos* nodo = obtener_nodo(posicion);
    if (nodo != nullptr) {
        nodo->proceso = proc;
    } else {
        cout << "Posición inválida" << endl;
    }
}



void ListaProcesos::eliminar_proceso(int posicion) {
    if (posicion < 0 || posicion >= longitud) {
        cout << "Posición inválida" << endl;
        return;
    }
    NodoListaProcesos* nodoAEliminar;
    if (posicion == 0) {
        nodoAEliminar = primero;
        primero = primero->siguiente;
        if (primero != nullptr) {
            primero->anterior = nullptr; // he añadido que actualice el puntero anterior del primer nodo, para que no apunte a cossas raras
        }
    } else if (posicion == longitud - 1) { // esto esta para que si se elimina el ultimo nodo, no de  SIGSEGV, Segmentation fault al intentar acceder a un puntero nulo
        nodoAEliminar = ultimo;
        ultimo = ultimo->anterior;
        if (ultimo != nullptr) {
            ultimo->siguiente = nullptr; // he añadido que actualice el puntero siguiente del ultimo nodo, para que no sae null
        }
    } else {
        NodoListaProcesos* anterior = obtener_nodo(posicion - 1); // esto hace que no se pueda eliminar el ultimo nodo
        nodoAEliminar = anterior->siguiente;
        anterior->siguiente = nodoAEliminar->siguiente;
        NodoListaProcesos* siguiente = nodoAEliminar->siguiente;
        siguiente->anterior = anterior; // he añadido que actualice el puntero anterior del siguiente nodo, para que no sae null    
    }

    delete nodoAEliminar;
    longitud--;
}



void ListaProcesos::mostrar() const {
    if (es_vacia()) {
        cout << "La lista está vacía" << endl;
        return;
    }

    NodoListaProcesos* actual = primero;
    while (actual != nullptr) {
        cout << "PID: " << actual->proceso.get_PID() 
            << ", PPID: " << actual->proceso.get_PPID()
            << ", Inicio: " << actual->proceso.get_inicio()
            << ", Tiempo de vida: " << actual->proceso.get_tiempo_de_vida()
            << ", Prioridad: " << actual->proceso.get_prioridad()
            << ", Tiempo de ejecucion: " << actual->proceso.get_tiempo_ejecucion()
            << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}


/**
 * @brief Devuelve el proceso en la posición n
 * 
 * @param n 
 * @return Proceso 
 */
Proceso ListaProcesos::coger(int n) { // esta igual deveria devolvel un puntero al nucleo por si se quieren hacer modificaciones
    NodoListaProcesos* nodo = obtener_nodo(n);
    //__asm__("int $3");
    if (nodo != nullptr) {
        Proceso paux = nodo->proceso;
        return paux;
    } else {
        cout << "Posición inválida" << endl;
        return Proceso(); // Devuelve un proceso vacío
    }
}


NodoListaProcesos* ListaProcesos::obtener_nodo(int posicion) {
    if (posicion < 0 || posicion >= longitud) {
        cout << "Posición inválida, funcion obtener_nodo devuelve nullptr" << endl;
        return nullptr;
    }
    NodoListaProcesos* actual = primero;
    for (int i = 0; i < posicion; ++i) {
        actual = actual->siguiente;
    }
    return actual; 
}

