#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include "Planificador.h"
#include "ListaProcesos.h"
#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

int Nucleo::Contador_ID = 0;

/**
 * @brief Construct a new Nucleo:: Nucleo object (Constructor por defecto)
 * 
 */
Nucleo::Nucleo(){
    id = Contador_ID++; // mirar por que salen pares
    proceso_en_ejecucion;
    cola_procesos;
    tiempo_inicio = -1; //podria ser NULL
    tiempo_fin = -1;
}


/**
 * @brief Construct a new Nucleo:: Nucleo object
 * 
 * @param id Identificador del núcleo
 * @param proceso Proceso en ejecución
 * @param cola_procesos Cola de procesos en espera
 */
Nucleo::Nucleo(int id, Proceso proceso){
    this->id = id;
    this->proceso_en_ejecucion = proceso;
    time_t tiempo_inicio = Planificador::tiempoTranscurrido;
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
 * @brief Asigna un proceso al núcleo directamente
 * 
 * @param proceso Proceso a asignar
 */
void Nucleo::set_proceso(Proceso proceso){
    this->proceso_en_ejecucion = proceso;
    proceso_en_ejecucion.set_nucleo_asignado(id);
    this->tiempo_inicio = Planificador::tiempoTranscurrido;
    this->tiempo_fin = tiempo_inicio + proceso.get_tiempo_de_vida();    
    detalles_proceso(true);
}


/**
 * @brief Asigna una cola de procesos al núcleo
 * 
 * @param cola_procesos Cola de procesos a asignar
 */
void Nucleo::set_cola_procesos(Cola cola_procesos){
    this->cola_procesos = cola_procesos;
    // modificar el atributo nucleo_asignado de los procesos en la cola
}


/**
 * @brief Añade un proceso al nucleo si este esta vacio(proceso vacio) o lo encola si no lo esta
 * 
 * @param proceso Proceso a añadir
 */
void Nucleo::add_proceso(Proceso proceso){
    if ((cola_procesos.es_vacia()) && (proceso_en_ejecucion.get_PID() == -1)){
        set_proceso(proceso);
        //cout << "Proceso asignado al nucleo " << id << endl; // para pruevas
    } else if (proceso_en_ejecucion.get_PID() != -1){
        proceso.set_nucleo_asignado(id);
        cola_procesos.insertar_por_prioridad(proceso); 
        // si el prodceso en nucleo termian ahora, se mete en ejecucion el siguiente proceso y el nuevo a la cola
    }
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
        return proceso_en_ejecucion;
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
    if (cola_procesos.es_vacia()){
        //cout << "Cola de procesos vacia" << endl;
        //cout << endl;
        return cola_procesos;
    } else {
        return cola_procesos;
    }
}


/**
 * @brief Elimina el proceso en ejecución.
 *
 * Esta función elimina el proceso que actualmente está en ejecución en el núcleo solo si este ha terminado su ejecucion, e inserta el siguiente proceso
 * si es que hay alguno en la cola de procesos en espera. Si no hay proceso inserta un proceso de la cola de procesos,
 * y si la cola esta vacia, inserta un proceso vacio.
 * 
 * Cuando se elimina un proceso se muestra un mensaje en la consola indicando que el proceso ha terminado.
 * Si el proceso es nulo y la cola de procesos esta vacia no hace nada. ()
 * 
 */
void Nucleo::eliminar_proceso(){
    if ((proceso_en_ejecucion.get_PID() != -1) && (!cola_procesos.es_vacia()) && (tiempo_fin == Planificador::tiempoTranscurrido)){ 
        Planificador::contadorTiempoEstancia += get_tiempo_fin() - get_proceso().get_inicio();
        proceso_en_ejecucion.set_tiempo_ejecucion(get_tiempo_fin() - get_proceso().get_inicio());
        detalles_proceso(false);
        Planificador::arbolProcesos.insertar(proceso_en_ejecucion);
        set_proceso(cola_procesos.desencolar());
    }
    else if ((proceso_en_ejecucion.get_PID() == -1) && (!cola_procesos.es_vacia())){
        set_proceso(cola_procesos.desencolar());
    } 
    else if ((proceso_en_ejecucion.get_PID() != -1) && (cola_procesos.es_vacia()) && (tiempo_fin == Planificador::tiempoTranscurrido)){
        Planificador::contadorTiempoEstancia += get_tiempo_fin() - get_proceso().get_inicio();
        proceso_en_ejecucion.set_tiempo_ejecucion(get_tiempo_fin() - get_proceso().get_inicio());
        detalles_proceso(false);
        Planificador::arbolProcesos.insertar(proceso_en_ejecucion);
        Proceso paux;
        proceso_en_ejecucion = paux;
        //eliminar nucleo de la lista de nucleos y liberar memoria, if no es el ultimo nucleo, cambiar id de los siguientes nucleos?
    }
}


/**
 * @brief Muestra los detalles del proceso en ejecución.
 *
 * Esta función muestra los detalles del proceso que actualmente está en ejecución en el núcleo.
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola indicando que no hay proceso en ejecución.
 */
void Nucleo::detalles_proceso() const {
    if (proceso_en_ejecucion.get_PID() == -1){
        Planificador::mostrar_tiempo();
        cout << " | Nucleo " << id << ": No hay proceso en ejecucion" << endl;
    } else {
        Planificador::mostrar_tiempo();
        cout << " | " << "Proceso en nucleo " << id << " PID: " << proceso_en_ejecucion.get_PID() << ", PPID: " << proceso_en_ejecucion.get_PPID() << ", Inicio: " << proceso_en_ejecucion.get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion.get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion.get_prioridad() << endl;
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
        saux = " | Proceso iniciado en nucleo ";
    } else {
        saux = " | Proceso terminado en nucleo ";
    }
    if (proceso_en_ejecucion.get_PID() == -1){
        Planificador::mostrar_tiempo();
        cout << " | " << "No hay proceso en ejecucion" << endl;
    } else {
        Planificador::mostrar_tiempo();
        cout << saux << id << ": " << "PID: " << proceso_en_ejecucion.get_PID() << ", PPID: " << proceso_en_ejecucion.get_PPID() << ", Inicio: " << proceso_en_ejecucion.get_inicio() << ", Tiempo de vida: " << proceso_en_ejecucion.get_tiempo_de_vida() << ", Prioridad: " << proceso_en_ejecucion.get_prioridad();
        if (!i){
            cout << ", Tiempo de estancia: " << proceso_en_ejecucion.get_tiempo_ejecucion() << " minutos" << endl;
        } else {
            cout << endl;
            cout << endl;
        }
    }
}


/**
 * @brief Muestra los detalles del núcleo.
 *
 * Esta función muestra los detalles del núcleo, incluyendo el proceso en ejecución y la cola de procesos en espera.
 * Si no hay ningún proceso en ejecución, se muestra un mensaje en la consola indicando que no hay proceso en ejecución.
 * Si no hay cola de procesos en espera, se muestra un mensaje en la consola indicando que no hay cola de procesos.
 */
void Nucleo::detalles_nucleo(){
    if (proceso_en_ejecucion.get_PID() == -1){
        Planificador::mostrar_tiempo();
        cout << " | " << "Nucleo: " << id << " No hay proceso en ejecucion" << endl;
    } else {
        detalles_proceso();
    }
    Planificador::mostrar_tiempo();
    cout << " | " << "Tiempo de inicio ejecucion: " << tiempo_inicio << ", Tiempo de finalizacion: " << tiempo_fin << endl;
    Planificador::mostrar_tiempo();
    cout << " | " << "Tiempo de ejecucion restante: " << tiempo_fin-Planificador::tiempoTranscurrido << " minutos" << endl;
    if (cola_procesos.es_vacia()){
        Planificador::mostrar_tiempo();
        cout << " | " << "Cola de procesos vacia" << endl;
    } else {
        Planificador::mostrar_tiempo();
        cout << " | " << "Cola de procesos: " << endl;
        cola_procesos.mostrarCola();
    }
}
