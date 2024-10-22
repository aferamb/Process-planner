#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include "global.h"
//#include <ctime>
#include <iostream>
#include <string>
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
    time_t tiempo_inicio = Global::tiempoTranscurrido;
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
    this->tiempo_inicio = Global::tiempoTranscurrido;
    this->tiempo_fin = tiempo_inicio + proceso.get_tiempo_de_vida();    
}

void Nucleo::set_cola_procesos(Cola cola_procesos){
    this->cola_procesos = &cola_procesos;
    // modificar el atributo nucleo_asignado de los procesos en la cola
}

void Nucleo::add_proceso(Proceso proceso){
    if ((cola_procesos == NULL)&(proceso_en_ejecucion == NULL)){
        set_proceso(proceso);
    } else {
        proceso.set_nucleo_asignado(id);
        cola_procesos->encolar(proceso);
    }
    // igual hacer que al llamar esta funcion se ordene la cola de procesos interna por prioridad
    // igual hacer que al llamar esta funcion se actualice si el proceso en ejecucion ha terminado

}

int Nucleo::get_id() const {
    return id;
}

int Nucleo::get_tiempo_inicio() const {
    return tiempo_inicio;
}

int Nucleo::get_tiempo_fin() const {
    return tiempo_fin;
}

/**
 * @brief Obtiene el proceso en ejecución.
 *
 * Esta función devuelve el proceso que actualmente está en ejecución en el núcleo.
 * Si no hay ningún proceso en ejecución, se devuelve un proceso vacío y se muestra
 * un mensaje en la consola indicando que no hay proceso en ejecución.
 *
 * @return Proceso El proceso en ejecución o un proceso vacío si no hay ninguno en ejecución.
 */
Proceso Nucleo::get_proceso() const {
    if (proceso_en_ejecucion == NULL){
        cout << "No hay proceso en ejecucion, devuelve un proceso vacio" << endl;
        return Proceso(); //?
    } else {
        return *proceso_en_ejecucion;
    }
}

Cola Nucleo::get_cola_procesos() const {
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
    }
}

// Esta función se puede usar para mostrar los detalles de un proceso en ejecución.
void Nucleo::detalles_proceso() const {
    if (proceso_en_ejecucion == NULL){
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | Nucleo " << id << ": No hay proceso en ejecucion" << endl;
    } else {
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "Proceso en nucleo: " << id << ", PID: " << proceso_en_ejecucion->get_PID() << ", PPID: " << proceso_en_ejecucion->get_PPID() << ", Inicio: " << proceso_en_ejecucion->get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion->get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion->get_prioridad() << endl;
    }
}

// Esta función se puede usar para mostrar los detalles de un proceso Iniciado o de un proceso Terminado.
void Nucleo::detalles_proceso(bool i) const {
    string saux;
    if (i){
        saux = " | Proceso iniciado: ";
    } else {
        saux = " | Proceso terminado: ";
    }
    if (proceso_en_ejecucion == NULL){
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "No hay proceso en ejecucion" << endl;
    } else {
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << saux << "Nucleo: " << id << ", PID: " << proceso_en_ejecucion->get_PID() << ", PPID: " << proceso_en_ejecucion->get_PPID() << ", Inicio: " << proceso_en_ejecucion->get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion->get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion->get_prioridad() << endl;
    }
}

void Nucleo::detalles_nucleo() const {
    if (proceso_en_ejecucion == NULL){
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "Nucleo: " << id << " No hay proceso en ejecucion" << endl;
    } else {
        detalles_proceso();
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "Tiempo de inicio ejecucion: " << tiempo_inicio << ", Tiempo de finalizacion: " << tiempo_fin << endl;
    }
    if (cola_procesos == NULL){
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "No hay cola de procesos" << endl;
    } else {
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "Cola de procesos: " << endl;
        cola_procesos->mostrarCola();
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