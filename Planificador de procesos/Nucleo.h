#ifndef NUCLEO_H
#define NUCLEO_H
#include "Cola.h"
#include "Proceso.h"
#include <ctime>

class Nucleo
{
private:
    int id;
    Proceso* proceso_en_ejecucion; // Proceso en ejecución
    Cola* cola_procesos; // Cola de procesos en espera
    time_t tiempo_inicio; // Tiempo cuando el proceso entra en el núcleo
    time_t tiempo_fin; // Calculado con el tiempo de vida del proceso y el tiempo de entrada/inicio del proceso en el núcleo
public:
    Nucleo();
    Nucleo(int id, Proceso proceso, Cola cola_procesos);
    ~Nucleo();

    void set_id(int id);
    void set_proceso(Proceso proceso);
    void set_cola_procesos(Cola cola_procesos);
    void add_proceso(Proceso proceso);
    int get_id();
    Proceso get_proceso();
    Cola get_cola_procesos();
    void eliminar_proceso();
};;
#endif // NUCLEO_H
