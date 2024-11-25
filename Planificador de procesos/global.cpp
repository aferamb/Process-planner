#include "global.h"
#include <iostream>

using namespace std;

/**
 * @brief Inicializa el tiempo de referencia y el tiempo transcurrido
 * 
 */ 
namespace Global {
    
    int tiempoTranscurrido = 0; // Definición de la variable en el namespace
    float contadorTiempoEstancia = 0; // Definición de la variable en el namespace

    void mostrar_tiempo() {
        cout << (tiempoTranscurrido/60 < 10 ? "0" : "") << tiempoTranscurrido/60 << ":" << (tiempoTranscurrido%60 < 10 ? "0" : "") << tiempoTranscurrido%60;
    }

    void aumentar_tiempo() {
        tiempoTranscurrido++;
    }

    void aumentar_tiempo(int n) {
        tiempoTranscurrido += n;
    }


}