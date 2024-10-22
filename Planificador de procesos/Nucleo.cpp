#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include "global.h"
//#include <ctime>
#include <iostream>
#include <string>
using namespace std;



/**
 * @brief Construct a new Nucleo:: Nucleo object (Constructor por defecto)
 * 
 */
Nucleo::Nucleo(){
    id = 0; // en la segunda parte el id se asigna automaticamente en base a la cantidad de nucleos en la lista de nucleos
    proceso_en_ejecucion = NULL;
    cola_procesos   = NULL;
    tiempo_inicio = 0; //podria ser NULL
    tiempo_fin = 0;
}


/**
 * @brief Construct a new Nucleo:: Nucleo object
 * 
 * @param id Identificador del núcleo
 * @param proceso Proceso en ejecución
 * @param cola_procesos Cola de procesos en espera
 */
Nucleo::Nucleo(int id, Proceso proceso, Cola cola_procesos){
    this->id = id;
    this->proceso_en_ejecucion = &proceso;
    this->cola_procesos = &cola_procesos;
    time_t tiempo_inicio = Global::tiempoTranscurrido;
    this->tiempo_inicio = tiempo_inicio;
    time_t tiempo_fin = tiempo_inicio + proceso.get_tiempo_de_vida();
    this->tiempo_fin = tiempo_fin;
    
}


/**
 * @brief Destroy the Nucleo:: Nucleo object
 * 
 */
Nucleo::~Nucleo() {}


/**
 * @brief Asigna un identificador al núcleo
 * 
 * @param id Identificador del núcleo
 */
void Nucleo::set_id(int id){
    this->id = id;
}


/**
 * @brief Asigna un proceso al núcleo
 * 
 * @param proceso Proceso a asignar
 */
void Nucleo::set_proceso(Proceso proceso){
    this->proceso_en_ejecucion = &proceso;
    proceso.set_nucleo_asignado(id);
    this->tiempo_inicio = Global::tiempoTranscurrido;
    this->tiempo_fin = tiempo_inicio + proceso.get_tiempo_de_vida();    
}


/**
 * @brief Asigna una cola de procesos al núcleo
 * 
 * @param cola_procesos Cola de procesos a asignar
 */
void Nucleo::set_cola_procesos(Cola cola_procesos){
    this->cola_procesos = &cola_procesos;
    // modificar el atributo nucleo_asignado de los procesos en la cola
}


/**
 * @brief Añade un proceso a la cola de procesos del núcleo
 * 
 * @param proceso Proceso a añadir
 */
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


/**
 * @brief Obtiene el identificador del núcleo
 * 
 * @return int Identificador del núcleo
 */
int Nucleo::get_id() const {
    return id;
}


/**
 * @brief Obtiene el tiempo de inicio del proceso en el núcleo
 * 
 * @return int Tiempo de inicio del proceso en el núcleo
 */
int Nucleo::get_tiempo_inicio() const {
    return tiempo_inicio;
}


/**
 * @brief Obtiene el tiempo de finalización del proceso en el núcleo
 * 
 * @return int Tiempo de finalización del proceso en el núcleo
 */
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


/**
 * @brief Obtiene la cola de procesos en espera.
 *
 * Esta función devuelve la cola de procesos en espera del núcleo.
 * Si no hay cola de procesos, se devuelve una cola vacía y se muestra
 * un mensaje en la consola indicando que no hay cola de procesos.
 *
 * @return Cola La cola de procesos en espera o una cola vacía si no hay cola de procesos.
 */
Cola Nucleo::get_cola_procesos() const {
    if (cola_procesos == NULL){
        cout << "No hay cola de procesos, devuelve una cola vacia" << endl;
        return Cola();
    } else {
        return *cola_procesos;
    }
}


/**
 * @brief Elimina el proceso en ejecución.
 *
 * Esta función elimina el proceso que actualmente está en ejecución en el núcleo, e inserta el siguiente proceso
 * si es que hay alguno en la cola de procesos en espera. Si no hay ningún proceso en ejecución y tampoco hay procesos
 * en la cola de procesos, se muestra un mensaje en la consola indicando que no hay proceso en ejecución
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola
 * indicando que no hay proceso en ejecución.
 */
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


/**
 * @brief Muestra los detalles del proceso en ejecución.
 *
 * Esta función muestra los detalles del proceso que actualmente está en ejecución en el núcleo.
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola indicando que no hay proceso en ejecución.
 */
void Nucleo::detalles_proceso() const {
    if (proceso_en_ejecucion == NULL){
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | Nucleo " << id << ": No hay proceso en ejecucion" << endl;
    } else {
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << " | " << "Proceso en nucleo: " << id << ", PID: " << proceso_en_ejecucion->get_PID() << ", PPID: " << proceso_en_ejecucion->get_PPID() << ", Inicio: " << proceso_en_ejecucion->get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion->get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion->get_prioridad() << endl;
    }
}


/**
 * @brief Muestra los detalles del proceso en ejecución.
 *
 * Esta función muestra los detalles del proceso que actualmente está en ejecución en el núcleo.
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola indicando que no hay proceso en ejecución.
 *
 * @param i Indica si el proceso se ha iniciado o terminado
 */
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


/**
 * @brief Muestra los detalles del núcleo.
 *
 * Esta función muestra los detalles del núcleo, incluyendo el proceso en ejecución y la cola de procesos en espera.
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola indicando que no hay proceso en ejecución.
 * Si no hay cola de procesos en espera, se muestra un mensaje en la consola indicando que no hay cola de procesos.
 */
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