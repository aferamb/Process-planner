#include "Proceso.h"

// Constructor
Proceso::Proceso() {} // Esto hay que revisarlo, no se si es correcto. Un proceso no deberia crearse sin parametros
// Constructor with parameters
Proceso::Proceso(int pid, int ppid, std::time_t inicio, int tiempoDeVida, int prioridad)
    : PID(pid), PPID(ppid), inicio(inicio), tiempoDeVida(tiempoDeVida), prioridad(prioridad), nucleoAsignado(nucleoAsignado) {}

// Alternative constructor implementation
/*
{
    this->PID = pid; Esto no creo que este bien, el PID habria que generarlo automaticamente, que se incremente en 1 cada vez que se crea un proceso
    this->PPID = ppid;
    this->inicio = inicio;
    this->tiempoDeVida = tiempoDeVida;
    this->prioridad = prioridad;
    this->nucleoAsignado = nucleoAsignado;  Esto no creo que este bien, el nucleo se asigna al entrar en el nucleo y no se cambia, Inicia en NULL
}
*/

// Getters
int Proceso::get_PID() const { return PID; }
int Proceso::get_PPID() const { return PPID; }
std::time_t Proceso::get_inicio() const { return inicio; }
int Proceso::get_tiempo_de_vida() const { return tiempoDeVida; }
int Proceso::get_prioridad() const { return prioridad; }
int Proceso::get_nucleo_asignado() { return nucleoAsignado; }

// Setters
void Proceso::set_PPID(int ppid) { PPID = ppid; }
void Proceso::set_inicio(std::time_t inicio) { this->inicio = inicio; }
void Proceso::set_tiempo_de_vida(int tiempoDeVida) { this->tiempoDeVida = tiempoDeVida; }
void Proceso::set_prioridad(int prioridad) { this->prioridad = prioridad; }
void Proceso::set_nucleo_asignado(int nucleoAsignado) { this->nucleoAsignado = nucleoAsignado; } // esta creo que no se puede modificar, se asigna al entrar en el nucleo y no se cambia