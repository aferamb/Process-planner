#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include "global.h"
//#include <ctime>
#include <iostream>
using namespace std;

Nucleo::Nucleo(){
    id = 0; // en la segunda parte el id se asigna automaticamente en base a la cantidad de nucleos en la lista de nucleos
    proceso_en_ejecucion = NULL;
    cola_procesos   = NULL;
    tiempo_inicio = 0; //podria ser NULL
    tiempo_fin = 0;
}

Nucleo::Nucleo(int id, Proceso proceso, Cola cola_procesos){
    this->id = id;
    this->proceso_en_ejecucion = &proceso;
    this->cola_procesos = &cola_procesos;
    time_t tiempo_inicio = time(nullptr);
    this->tiempo_inicio = tiempo_inicio;
    time_t tiempo_fin = tiempo_inicio + proceso.get_tiempo_de_vida();
    this->tiempo_fin = tiempo_fin;
    
}

Nucleo::~Nucleo() {}

void Nucleo::set_id(int id){
    this->id = id;
}

void Nucleo::set_proceso(Proceso proceso){
    this->proceso_en_ejecucion = &proceso;
    proceso.set_nucleo_asignado(id);
    this->tiempo_inicio = time(nullptr);
}

void Nucleo::set_cola_procesos(Cola cola_procesos){
    this->cola_procesos = &cola_procesos;
    // modificar el atributo nucleo_asignado de los procesos en la cola
}

void Nucleo::add_proceso(Proceso proceso){
    if ((cola_procesos == NULL)&(proceso_en_ejecucion == NULL)){
        set_proceso(proceso);
    } else {
        cola_procesos->encolar(proceso);
    }
    proceso.set_nucleo_asignado(id);
}

int Nucleo::get_id(){
    return id;
}

void Nucleo::detalles_proceso(){
    if (proceso_en_ejecucion == NULL){
        cout << "No hay proceso en ejecucion" << endl;
    } else {
        cout << "PID: " << proceso_en_ejecucion->get_PID() << ", PPID: " << proceso_en_ejecucion->get_PPID() << ", Inicio: " << proceso_en_ejecucion->get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion->get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion->get_prioridad() << ", Nucleo: " << proceso_en_ejecucion->get_nucleo_asignado() << endl;
    }
}

Proceso Nucleo::get_proceso(){
    if (proceso_en_ejecucion == NULL){
        cout << "No hay proceso en ejecucion, devuelve un proceso vacio" << endl;
        return Proceso();
    } else {
        return *proceso_en_ejecucion;
    }
}

Cola Nucleo::get_cola_procesos(){
    if (cola_procesos == NULL){
        cout << "No hay cola de procesos, devuelve una cola vacia" << endl;
        return Cola();
    } else {
        return *cola_procesos;
    }
}

void Nucleo::eliminar_proceso(){
    if (proceso_en_ejecucion == NULL){
        cout << "No hay proceso en ejecucion" << endl;
    }
    else if ((proceso_en_ejecucion != NULL) & (cola_procesos->es_vacia())){
        delete proceso_en_ejecucion;
        proceso_en_ejecucion = NULL;
        //eliminar nucleo de la lista de nucleos y liberar memoria, if no es el ultimo nucleo, cambiar id de los siguientes nucleos?
    }
    else if ((proceso_en_ejecucion != NULL) & (!cola_procesos->es_vacia())) {
        delete proceso_en_ejecucion;
        set_proceso(cola_procesos->inicio());
        cola_procesos->desencolar();
    } else {
        // si no hay proceso en ejecucion???
    }
}

//nooooooooooooooo se si esta bien
void Nucleo::actualizar_estado(){
    if (proceso_en_ejecucion != NULL){
        if (time(nullptr) == tiempo_fin){
            delete proceso_en_ejecucion;
            if (cola_procesos->es_vacia()){
                proceso_en_ejecucion = NULL;
            } else {
                set_proceso(cola_procesos->inicio());
                cola_procesos->desencolar();
            }
        }
    }
}