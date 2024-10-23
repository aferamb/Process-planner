#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Proceso.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;


int main() {
    int opcion;
    float contador_tiempo_estancia = 0; // Contador para calcular el tiempo medio de estancia en el sistema operativo, se hace float para que el resultado de la division sea float
    Pila pila;
    Proceso p;
    Cola cola;
    Nucleo nucleo1;
    Nucleo nucleo2;
    Global::tiempoTranscurrido = 0;
    //int horas = Global::tiempoTranscurrido/60;  
    //int minutos = Global::tiempoTranscurrido%60;

    Proceso p1=Proceso(1, 0, 4, 0);
    Proceso p2=Proceso(1, 0, 5, 1);
    Proceso p3=Proceso(1, 1, 4, 3);
    Proceso p4=Proceso(2, 7, 3, 7);
    Proceso p5=Proceso(2, 8, 2, 2);
    Proceso p6=Proceso(3, 15, 5, 1);
    Proceso p7=Proceso(3, 20, 3, 4);
    Proceso p8=Proceso(4, 22, 2, 6);
    Proceso p9=Proceso(7, 25, 1, 8);
    Proceso p10=Proceso(5, 26, 4, 2);

    pila.apilar(p2);
    pila.apilar(p1);
    pila.apilar(p7);
    pila.apilar(p10);
    pila.apilar(p9);
    pila.apilar(p5);
    pila.apilar(p8);
    pila.apilar(p4);
    pila.apilar(p3);
    pila.apilar(p6);
    pila.mostrarTodos();

    cola.encolar(p1);
    cola.inicio();
    cola.mostrarCola();


}