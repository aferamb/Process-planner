#include "Cola.h"
#include "Proceso.h"
#include <iostream>
using namespace std;


/**
 * @brief Construct a new Cola:: Cola object
 * 
 */
Cola::Cola(){
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}


/**
 * @brief Destroy the Cola:: Cola object
 * 
 */
Cola::~Cola() {
    while (primero) {
        NodoCola* aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}


/**
 * @brief Encola un proceso en la cola
 * 
 * @param proceso Proceso a encolar
 */
void Cola::encolar(Proceso proceso){  
    NodoCola *nuevo_nodo = new NodoCola(proceso, proceso.get_prioridad());
    if (es_vacia()){
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else{
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}


/**
 * @brief Desencola un proceso de la cola
 * 
 * @return Proceso Proceso desencolado
 */
Proceso Cola::desencolar(){
    if (!es_vacia()){
        Proceso proceso = primero->proceso;
        NodoCola *aux = primero;

        if ((primero == ultimo) && (primero -> siguiente == NULL)){
            primero = NULL;
            ultimo = NULL;
            aux -> siguiente = NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        
        longitud--;
        return proceso;
    }
    return Proceso();
}


/**
 * @brief  Devuelve el proceso que está en el inicio de la cola
 * 
 * @return Proceso Proceso en el inicio de la cola
 */
Proceso Cola::inicio(){
    if (!es_vacia()){
        return primero->proceso;
    }
    //return Proceso();
}


/**
 * @brief Devuelve el proceso que está al final de la cola
 * 
 * @return Proceso Proceso al final de la cola
 */
Proceso Cola::fin(){ //no se si es correcto
    if (!es_vacia()){
        return ultimo->proceso;
    }
    return Proceso();
}


/**
 * @brief Comprueba si la cola está vacía
 * 
 * @return true Si la cola está vacía
 * @return false Si la cola no está vacía
 */
bool Cola::es_vacia(){
    return ((primero == NULL) && (ultimo == NULL));
}


/**
 * @brief Devuelve la longitud de la cola
 * 
 * @return int Longitud de la cola
 */
int Cola::get_longitud(){
    return longitud;
}


/**
 * @brief Muestra la cola
 * 
 */
void Cola::mostrarCola(){
    //No es correcto, la cola solo puede verse mostrando el primero y desencolando, se implementa para comprobar código facilmente
    NodoCola *aux = primero;
    if (es_vacia())
    {cout << "La cola está vacía" << endl;}
    else{
        cout << "| PID | PPID | Inicio | Tiempo vida | Prioridad | Nucleo |" << endl;
        while (aux){
            cout << "| " << aux->proceso.get_PID() << " | " << aux->proceso.get_PPID() << " | " << aux->proceso.get_inicio() << " | " << aux->proceso.get_tiempo_de_vida() << " | " << aux->proceso.get_prioridad() << " | " << aux->proceso.get_nucleo_asignado() << " |" << endl;
            aux = aux->siguiente;
        }
        cout << endl;
    }
}


// Función para ordenar la cola según la prioridad de menor a mayor
void Cola::ordenar_por_prioridad_no_provada() {
    if (primero == nullptr || primero->siguiente == nullptr) {
        // Si la cola está vacía o solo tiene un elemento, no es necesario ordenar
        return;
    }

    bool swapped;
    do {
        swapped = false;
        NodoCola** current = &primero;
        NodoCola* prev = nullptr; // Puntero al nodo anterior
        while ((*current)->siguiente != nullptr) {
            NodoCola* next = (*current)->siguiente;
            if ((*current)->prioridad > next->prioridad) {
                // Intercambiar los nodos
                (*current)->siguiente = next->siguiente;
                next->siguiente = *current;
                if (prev != nullptr) {
                    prev->siguiente = next;
                } else {
                    primero = next;
                }
                *current = next;
                swapped = true;
            }
            prev = *current;
            current = &(*current)->siguiente;
        }
    } while (swapped);

    // Actualizar el puntero 'ultimo'
    NodoCola* temp = primero;
    while (temp->siguiente != nullptr) {
        temp = temp->siguiente;
    }
    ultimo = temp;
}


/**
 * @brief Ordena la cola según la prioridad de menor a mayor
 * 
 */
void Cola::ordenar_por_prioridad() {
    if (primero == nullptr || primero->siguiente == nullptr) {
        // Si la cola está vacía o solo tiene un elemento, no es necesario ordenar
        return;
    }

    NodoCola* actual;
    NodoCola* siguiente;
    Proceso tempProceso;
    int tempPrioridad;

    // Usamos un algoritmo de burbuja para ordenar
    for (actual = primero; actual != nullptr; actual = actual->siguiente) {
        for (siguiente = actual->siguiente; siguiente != nullptr; siguiente = siguiente->siguiente) {
            if (actual->prioridad > siguiente->prioridad) {
                // Intercambiar elementos y prioridades si la prioridad es menor en el siguiente nodo
                tempProceso = actual->proceso;
                tempPrioridad = actual->prioridad;

                actual->proceso = siguiente->proceso;
                actual->prioridad = siguiente->prioridad;

                siguiente->proceso = tempProceso;
                siguiente->prioridad = tempPrioridad;
            }
        }
    }
}