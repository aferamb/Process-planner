#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctime>


/**
 * @brief Namespace Global para variables globales
 * 
 */
namespace Global {
    extern int tiempoTranscurrido; 
    extern float contadorTiempoEstancia; 
    void aumentar_tiempo(); 
    void aumentar_tiempo(int n); 
    void mostrar_tiempo(); 

    // Funciones main
    void cargar_procesos();
    void introducir_proceso(); //leido de teclado, con condicion de que tiempo de inicio sea mas que el actual
    void mostrar_procesos();
    void borrar_procesos();
    void aumentar_tiempo_sistema(int n);
    void mostrar_estado_nucleos();
    void nucleo_menos_mas_carga();
    void numero_nucleos_operativos();

    void simular_ejecucion_procesos();
}

#endif // GLOBAL_H