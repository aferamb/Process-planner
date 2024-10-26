#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctime>


/**
 * @brief Namespace Global para variables globales
 * 
 */
namespace Global {
    extern time_t tiempoReferencia;  // Declaración de la variable dentro del namespace
    extern int tiempoTranscurrido; // Declaración de la variable dentro del namespace
    extern float contadorTiempoEstancia; // Declaración de la variable dentro del namespace
    //extern int tiempoEstanciaMedio; // Declaración de la variable dentro del namespace
}

#endif // GLOBAL_H