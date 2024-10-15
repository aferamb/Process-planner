#include "Proceso.h"

Proceso::Proceso(int pid, int ppid, std::time_t inicio, int tiempoDeVida, int prioridad, int nucleoAsignado)
    : PID(pid), PPID(ppid), inicio(inicio), tiempoDeVida(tiempoDeVida), prioridad(prioridad), nucleoAsignado(nucleoAsignado) {}

// Getters
int Proceso::getPID() const { return PID; }
int Proceso::getPPID() const { return PPID; }
std::time_t Proceso::getInicio() const { return inicio; }
int Proceso::getTiempoDeVida() const { return tiempoDeVida; }
int Proceso::getPrioridad() const { return prioridad; }
int Proceso::getNucleoAsignado() const { return nucleoAsignado; }

// Setters
void Proceso::setPPID(int ppid) { PPID = ppid; }
void Proceso::setInicio(std::time_t inicio) { this->inicio = inicio; }
void Proceso::setTiempoDeVida(int tiempoDeVida) { this->tiempoDeVida = tiempoDeVida; }
void Proceso::setPrioridad(int prioridad) { this->prioridad = prioridad; }
void Proceso::setNucleoAsignado(int nucleoAsignado) { this->nucleoAsignado = nucleoAsignado; }