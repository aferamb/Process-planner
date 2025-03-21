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



void Lista::ordenar_menor_mayor() { // corregir, falta asignar los punteros de anterior y manejar accesos de memoria vacia, NO USAR HASTA QUE SE CORRIJA
    if (es_vacia() || primero == ultimo) {
        return; 
    }
    int posicion = 0;
    bool intercambiado;
    do {
        intercambiado = false;
        NodoLista* actual = primero;

        while (actual->siguiente != nullptr && posicion < longitud) {
            if (actual->nucleo.get_id() > actual->siguiente->nucleo.get_id()) {
                // Intercambiar núcleos
                Nucleo temp = actual->nucleo;
                actual->nucleo = actual->siguiente->nucleo;
                actual->siguiente->nucleo = temp;
                intercambiado = true;
            }
            posicion++;
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
        nuevoNodo->anterior = ultimo; // he añadido que actualice el puntero anterior del siguiente nodo, para que no sae null
        ultimo = nuevoNodo;
    }
    longitud++;
}



void Lista::estado_nucleo(int posicion) {
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
        cout << endl;
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
        if (primero != nullptr) {
            primero->anterior = nullptr; 
        }
    } else if (posicion == longitud - 1) { // esto esta para que si se elimina el ultimo nodo, no de  SIGSEGV, Segmentation fault al intentar acceder a un puntero nulo
        nodoAEliminar = ultimo;
        ultimo = ultimo->anterior;
        if (ultimo != nullptr) {
            ultimo->siguiente = nullptr; 
        }
    } else {
        NodoLista* anterior = obtener_nodo(posicion - 1); 
        nodoAEliminar = anterior->siguiente;
        anterior->siguiente = nodoAEliminar->siguiente;
        NodoLista* siguiente = nodoAEliminar->siguiente;
        siguiente->anterior = anterior; 
    }

    delete nodoAEliminar;
    longitud--;
}



void Lista::insertar_proceso(Proceso proceso, int posicion) {
    NodoLista* nodo = obtener_nodo(posicion);
    if (nodo != nullptr) {
        nodo->nucleo.add_proceso(proceso);
    } else {
        cout << "Posición inválida" << endl;
    }
}



void Lista::eliminar_proceso(int posicion) {
    NodoLista* nodo = obtener_nodo(posicion);
    if (nodo != nullptr) {
        nodo->nucleo.eliminar_proceso();
    } else {
        cout << "Posición inválida" << endl;
    }
}


/**
 * @brief Devuelve la posición del núcleo con menos carga de procesos , o con ninguna carga. Si imprimir es true, muestra la información del nucleo.
 * Y si todos los nucleos tienen mas de dos procesos en espera crea un nuevo nucleo, lo inserta en la lista, 
 * y muestra la información del nuevo nucleo al ser el nucleo con menos carga
 * 
 * @param imprimir 
 * @return int 
 */
int Lista::nucleo_menos_carga(bool imprimir) { // creo qu efunciona bien, cambiar comentarios
    if (es_vacia()) return -1;

    bool nuceloEncontrado = false;  

    int posicion = 0, posicionMenosCarga = 0;
    int pid = primero->nucleo.get_proceso().get_PID();
    int menorCarga = primero->nucleo.get_cola_procesos().get_longitud();
    NodoLista* actualx = primero;
    NodoLista* actual = primero->siguiente;

    while (actualx != nullptr && !nuceloEncontrado && posicion < longitud) {
        if (pid == -1) {
            posicionMenosCarga = posicion;
            menorCarga = 0;
            nuceloEncontrado = true;
        }
        else {
            posicion++;
            actualx = actualx->siguiente; // si es el ultimo nodo, el siguiente es nullptr, y no se puede acceder a la propiedad nucleo
            if (actualx != nullptr && posicion < longitud){
                pid = actualx->nucleo.get_proceso().get_PID();
            }
        }
    }

    if (!nuceloEncontrado) {
        posicion = 0;
    }

    while (actual != nullptr && !nuceloEncontrado && posicion < longitud) {
        posicion++;
        int cargaActual = actual->nucleo.get_cola_procesos().get_longitud();
        if (cargaActual < menorCarga) {
            menorCarga = cargaActual;
            posicionMenosCarga = posicion;
        }
        actual = actual->siguiente;
    }

    // Si todos los núcleos tienen más de dos procesos en espera, crea un nuevo núcleo
    if (menorCarga > 2) {
        insertar_nucleo();
        posicionMenosCarga = nucleo_menos_carga();
    }

    if (imprimir) {
        cout << "Nucleo con menos carga de procesos: " << endl;
        estado_nucleo(posicionMenosCarga);
        cout << endl;
    }
    return posicionMenosCarga;
}



int Lista::nucleo_mas_carga(bool imprimir) {
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

    if (imprimir) {
        cout << "Nucleo con mas carga de procesos: " << endl;
        estado_nucleo(posicionMasCarga);
        cout << endl;
    }
    return posicionMasCarga;
}


Nucleo Lista::coger(int n) { 
    NodoLista* nodo = obtener_nodo(n);
    //__asm__("int $3");
    if (nodo != nullptr) {
        Nucleo nucleoaux = nodo->nucleo;
        return nucleoaux;
    } else {
        cout << "Posición inválida" << endl;
        return Nucleo(); // Devuelve un núcleo vacío
    }
}


NodoLista* Lista::obtener_nodo(int posicion) {
    if (posicion < 0 || posicion >= longitud) {
        cout << "Posición inválida, funcion obtener_nodo devuelve nullptr" << endl;
        return nullptr;
    }

    NodoLista* actual = primero;
    for (int i = 0; i < posicion; ++i) {
        actual = actual->siguiente;
    }
    return actual; 
}

