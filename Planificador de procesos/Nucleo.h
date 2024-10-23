#ifndef NUCLEO_H
#define NUCLEO_H
#include "Cola.h"
#include "Proceso.h"
#include <ctime>

class Nucleo
{
private:
    int id;
    Proceso proceso_en_ejecucion; // Proceso en ejecución
    Cola cola_procesos; // Cola de procesos en espera
    time_t tiempo_inicio; // Tiempo cuando el proceso entra en el núcleo
    time_t tiempo_fin; // Calculado con el tiempo de vida del proceso y el tiempo de entrada/inicio del proceso en el núcleo
public:
    Nucleo();
    Nucleo(int id, Proceso proceso);
    ~Nucleo();

    // Getters
    int get_id() const;
    int get_tiempo_inicio() const;
    int get_tiempo_fin() const;
    Proceso get_proceso() const; 
    Cola get_cola_procesos() const;
    void detalles_proceso() const;
    void detalles_proceso(bool i) const;
    void detalles_nucleo(); // Como mostrar cola no es const esta tampoco puede serlo

    // Setters
    void set_id(int id);
    void set_proceso(Proceso proceso);
    void set_cola_procesos(Cola cola_procesos);
    void add_proceso(Proceso proceso);

    void eliminar_proceso();
    void actualizar_estado();
};;
#endif // NUCLEO_H
