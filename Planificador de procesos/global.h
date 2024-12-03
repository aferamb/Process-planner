#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctime>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include "BST.h"



/**
 * @brief Namespace Global para variables globales
 * 
 */
namespace Global {
    // Variables globales
    extern int opcion;
    extern Pila pila;
    extern Proceso p;
    extern Lista lista;
    extern Cola colatemp;
    extern int contador;
    extern ListaProcesos lproc;
    extern BST arbolProcesos;

    extern int tiempoTranscurrido; 
    extern float contadorTiempoEstancia; 
    void aumentar_tiempo(); 
    void aumentar_tiempo(int n); 
    void mostrar_tiempo(); 

    // Funciones main
    void cargar_procesos(); //hecho
    void introducir_proceso(); //leido de teclado, con condicion de que tiempo de inicio sea mas que el actual
    void mostrar_procesos(); //hecho
    void borrar_procesos(); //hecho
    void aumentar_tiempo_sistema(int n);
    void mostrar_estado_nucleos(); //hecho
    void nucleo_menos_mas_carga(); //hecho
    void numero_nucleos_operativos(); //hecho

    void introducir_proceso_BST(); // insertar proceso en el arbol, si el nivel de prioridad no existe, se crea
    void mostrar_procesos_BST(); //mostrar todos los procesos del arbol ordenados por prioridad
    void mostrar_procesos_BST_prioridad(int prioridad); //mostrar los procesos de una prioridad concreta
    void mostrar_niveles_BST(); //mostrar los niveles de prioridad registrados que tienen al menos un proceso (no mostrar los procesos)
    void mostrar_niveles_BST_mayor_menor(); //mostrar el nivel de prioridad con mayor y menor numero de procesos (no mostrar los procesos)
    void mostrar_tiempo_promedio_procesos_prioridad(int prioridad); //mostrar el tiempo promedio de ejecucion de procesos con prioridad n
    void mostrar_tiempo_promedio_procesos_prioridad(); //mostrar el tiempo promedio de ejecucion de procesos en cada nivel de prioridad

    void simular_ejecucion_procesos();
}

#endif // GLOBAL_H