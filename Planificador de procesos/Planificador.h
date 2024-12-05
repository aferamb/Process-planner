#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

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
 * @brief Namespace Planificador para variables globales y funciones del programa
 * 
 */
namespace Planificador {
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
    void cargar_procesos(); 
    void introducir_proceso(); 
    void mostrar_procesos(); 
    void borrar_procesos(); 
    void aumentar_tiempo_sistema(int n); // hacer
    void mostrar_estado_nucleos(); 
    void nucleo_menos_mas_carga(); 
    void numero_nucleos_operativos(); 

    void introducir_proceso_BST(); // insertar proceso en el arbol, si el nivel de prioridad no existe, se crea
    void mostrar_procesos_BST(); //mostrar todos los procesos del arbol ordenados por prioridad
    void mostrar_procesos_BST_prioridad(); //mostrar los procesos de una prioridad concreta
    void mostrar_niveles_BST(); //mostrar los niveles de prioridad registrados que tienen al menos un proceso (no mostrar los procesos)
    void mostrar_niveles_BST_mayor_menor(); //mostrar el nivel de prioridad con mayor y menor numero de procesos (no mostrar los procesos)
    void mostrar_tiempo_promedio_procesos_prioridad_insertada(); //mostrar el tiempo promedio de ejecucion de procesos con prioridad n
    void mostrar_tiempo_promedio_procesos_prioridad(); //mostrar el tiempo promedio de ejecucion de procesos en cada nivel de prioridad

    void simular_ejecucion_procesos();
}

#endif // PLANIFICADOR_H