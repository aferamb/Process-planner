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

Nucleo Lista::prim() const {
    if (!es_vacia()) {
        return primero->nucleo;
    } else {
        // Manejo de error si la lista está vacía
        cout << "La lista está vacía" << endl;
        return Nucleo(); // Retorna un núcleo vacío
    }
}

Nucleo Lista::ult() const {
    if (!es_vacia()) {
        return ultimo->nucleo;
    } else {
        cout << "La lista está vacía" << endl;
        return Nucleo(); // Retorna un núcleo vacío
    }
}


bool Lista::es_vacia() const {
    return (primero == nullptr);
}


bool Lista::ordenada_menor_mayor() const {
    if (es_vacia() || primero == ultimo) {
        return true; // Una lista vacía o con un solo elemento está ordenada
    }
    NodoLista* actual = primero;
    while (actual->siguiente != nullptr) {
        if (actual->nucleo.get_id() > actual->siguiente->nucleo.get_id()) {
            return false;
        }
        actual = actual->siguiente;
    }
    return true;
}


void Lista::ordenar_menor_mayor() {
    if (es_vacia() || primero == ultimo) {
        return; // No es necesario ordenar si la lista está vacía o tiene un solo elemento
    }

    bool intercambiado;
    do {
        intercambiado = false;
        NodoLista* actual = primero;

        while (actual->siguiente != nullptr) {
            if (actual->nucleo.get_id() > actual->siguiente->nucleo.get_id()) {
                // Intercambiar núcleos
                Nucleo temp = actual->nucleo;
                actual->nucleo = actual->siguiente->nucleo;
                actual->siguiente->nucleo = temp;
                intercambiado = true;
            }
            actual = actual->siguiente;
        }
    } while (intercambiado);
}


int Lista::get_longitud() const {
    return longitud;
}


void Lista::insertar_nucleo() {
    Nucleo nuevoNucleo;
    NodoLista* nuevoNodo = new NodoLista(nuevoNucleo, nullptr);

    if (es_vacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }
    longitud++;
}


void Lista::estado_nucleo(int posicion) const {
    NodoLista* nodo = obtener_nodo(posicion);
    if (nodo != nullptr) {
        nodo->nucleo.detalles_nucleo();
    } else {
        cout << "Posición inválida" << endl;
    }
}


void Lista::mostrar_estado_nucleos() const {
    NodoLista* actual = primero;
    int pos = 0;
    while (actual != nullptr) {
        cout << "Nucleo en posicion " << pos << ":" << endl;
        actual->nucleo.detalles_nucleo();
        actual = actual->siguiente;
        pos++;
    }
}


void Lista::eliminar(int posicion) {
    if (posicion < 0 || posicion >= longitud) {
        cout << "Posición inválida" << endl;
        return;
    }

    NodoLista* nodoAEliminar;
    if (posicion == 0) {
        nodoAEliminar = primero;
        primero = primero->siguiente;
    } else {
        NodoLista* anterior = obtener_nodo(posicion - 1);
        nodoAEliminar = anterior->siguiente;
        anterior->siguiente = nodoAEliminar->siguiente;
    }

    delete nodoAEliminar;
    longitud--;
}


void Lista::insertar(Proceso proceso, int posicion) {
    NodoLista* nodo = obtener_nodo(posicion);
    if (nodo != nullptr) {
        nodo->nucleo.add_proceso(proceso);
    } else {
        cout << "Posición inválida" << endl;
    }
}


int Lista::nucleo_menos_carga() const {
    if (es_vacia()) return -1;

    int posicion = 0, posicionMenosCarga = 0;
    int menorCarga = primero->nucleo.get_cola_procesos().get_longitud();
    NodoLista* actual = primero->siguiente;

    while (actual != nullptr) {
        posicion++;
        int cargaActual = actual->nucleo.get_cola_procesos().get_longitud();
        if (cargaActual < menorCarga) {
            menorCarga = cargaActual;
            posicionMenosCarga = posicion;
        }
        actual = actual->siguiente;
    }
    return posicionMenosCarga;
}

int Lista::nucleo_mas_carga() const {
    if (es_vacia()) return -1;

    int posicion = 0, posicionMasCarga = 0;
    int mayorCarga = primero->nucleo.get_cola_procesos().get_longitud();
    NodoLista* actual = primero->siguiente;

    while (actual != nullptr) {
        posicion++;
        int cargaActual = actual->nucleo.get_cola_procesos().get_longitud();
        if (cargaActual > mayorCarga) {
            mayorCarga = cargaActual;
            posicionMasCarga = posicion;
        }
        actual = actual->siguiente;
    }
    return posicionMasCarga;
}


Nucleo Lista::coger(int n) const {
    NodoLista* nodo = obtener_nodo(n);
    if (nodo != nullptr) {
        return nodo->nucleo;
    } else {
        cout << "Posición inválida" << endl;
        return Nucleo(); // Devuelve un núcleo vacío
    }
}


NodoLista* Lista::obtener_nodo(int posicion) const {
    if (posicion < 0 || posicion >= longitud) {
        return nullptr;
    }

    NodoLista* actual = primero;
    for (int i = 0; i < posicion; ++i) {
        actual = actual->siguiente;
    }
    return actual;
}

