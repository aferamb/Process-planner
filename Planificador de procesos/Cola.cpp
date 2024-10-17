#include "Cola.h"
#include "Proceso.h"
#include <iostream>
using namespace std;

Cola::Cola(){
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() {}
a // para acordarme de terminar de modificar la funcion encolar
void Cola::encolar(Proceso proceso){  // Si a esta funcion se le ha pasado un puntero a proceso, se deberia cambiar a Proceso *proceso <---------------------
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
}

Proceso Cola::inicio(){
    if (!es_vacia()){
        return primero->proceso;
    }
}

Proceso Cola::fin(){
    if (!es_vacia()){
        return ultimo->proceso;
    }
}

bool Cola::es_vacia(){
    return ((primero == NULL) && (ultimo == NULL));
}

int Cola::get_longitud(){
    return longitud;
}

void Cola::mostrarCola(){
    //No es correcto, la cola solo puede verse mostrando el primero y desencolando, se implementa para comprobar código facilmente
    NodoCola *aux = primero;
    if (es_vacia())
    {cout << "La cola está vacía" << endl;}
    else{
        cout << "Datos de la cola" << endl;
        while (aux){
            cout << aux->proceso.get_PID() << " ";
            aux = aux->siguiente;
        }
    }
}