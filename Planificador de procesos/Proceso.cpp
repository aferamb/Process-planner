#include "Proceso.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Inicializamos el contador estático
int Proceso::contador_PID = 0;

// Constructor
Proceso::Proceso(){
  PID = -1;
  PPID = -1;
  inicio = -1;
  tiempoDeVida = -1;
  prioridad = -1;
  nucleoAsignado = -1;
  tiempoEjecucion = -1;
}

// Constructor con parametros
Proceso::Proceso(int ppid, int inicio, int tiempoDeVida, int prioridad){
  this->PID = ++contador_PID;
  this->PPID = ppid;
  this->inicio = inicio;
  this->tiempoDeVida = tiempoDeVida;
  this->prioridad = prioridad;
  nucleoAsignado = -1;  // El núcleo asignado comienza como -1 ya que no se asigna hasta que el proceso entre en ejecución.
  tiempoEjecucion = -1; // El tiempo de ejecución comienza como -1 ya que no se ejecuta hasta que el proceso entre en ejec
}

// Destructor
Proceso::~Proceso() {}

// Getters
int Proceso::get_PID() const {
  return PID;
}

int Proceso::get_PPID() const {
  return PPID;
}

int Proceso::get_inicio() const {
  return inicio;
}

int Proceso::get_tiempo_de_vida() const {
  return tiempoDeVida;
}

int Proceso::get_prioridad() const {
  return prioridad;
}

int Proceso::get_nucleo_asignado() const {
  return nucleoAsignado;
}

int Proceso::get_tiempo_ejecucion() const {
  return tiempoEjecucion;
}

// Setters
void Proceso::set_PPID(int ppid) {
  PPID = ppid;
}

void Proceso::set_inicio(int inicio) {
  this->inicio = inicio;
}

void Proceso::set_tiempo_de_vida(int tiempoDeVida) {
  this->tiempoDeVida = tiempoDeVida;
}

void Proceso::set_prioridad(int prioridad) {
  this->prioridad = prioridad;
}

void Proceso::set_nucleo_asignado(int nucleoAsignado) {
  this->nucleoAsignado = nucleoAsignado;
}

void Proceso::set_tiempo_ejecucion(int tiempoEjecucion) {
  this->tiempoEjecucion = tiempoEjecucion;
}

// Mostrar 
void Proceso::mostrar() const {
    if (PID == -1){
      cout<< "Proceso vacio" << endl;
    } else {
      cout << "PID: " << PID << " PPID: " << PPID << " Inicio: " << inicio << " Tiempo de vida: " << tiempoDeVida << " Prioridad: " << prioridad << " Núcleo asignado: " << nucleoAsignado << endl;
    }
}
