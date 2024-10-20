#include "Proceso.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Inicializamos el contador estático
int Proceso::contador_PID = 0;

// Constructor
Proceso::Proceso(){
  PID = ++contador_PID;
  PPID = 1;
  inicio = 0;
  tiempoDeVida = 0;
  prioridad = 9;
  nucleoAsignado = -1;
}

// Constructor con parametros
Proceso::Proceso(int ppid, int inicio, int tiempoDeVida, int prioridad){
  this->PID = ++contador_PID;  
  this->PPID = ppid;
  this->inicio = inicio;
  this->tiempoDeVida = tiempoDeVida;
  this->prioridad = prioridad;
  nucleoAsignado = -1;  // El núcleo asignado comienza como -1 ya que no se asigna hasta que el proceso entre en ejecución.
}

void Proceso::generarProceso(int tiempoActual) {
  PPID = 1;  // Asumimos que todos los procesos son hijos de init (PPID = 1) (para los primeros 10) aun falta para los demas procesos que no son = 1
  inicio = tiempoActual;  // Aqui todavia no he implemntado el ctime, los genero al azar provisionalmente
  tiempoDeVida = rand() % 30; // Supongamos que el proceso tiene un tiempo de vida maximo de 30 min
  prioridad = rand() % 10;  // Prioridad entre 0 (máxima prioridad) y 9 (menor prioridad)
}

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