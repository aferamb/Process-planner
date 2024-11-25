#include "NodoABB.h"
#include <iostream>

NodoABB::NodoABB(){
    this->prioridad = -1;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

NodoABB::NodoABB(int prioridad){
    this->prioridad = prioridad;
    this->elemento = ListaProcesos();
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

ListaProcesos NodoABB::get_ListaProcesos(){
    return elemento;
}

void NodoABB::set_ListaProcesos(ListaProcesos elemento){
    this->elemento = elemento;
}

NodoABB* NodoABB::get_izquierda(){
    return izquierda;
}

void NodoABB::set_izquierda(NodoABB* izquierda){
    this->izquierda = izquierda;
}

NodoABB* NodoABB::get_derecha(){
    return derecha;
}

void NodoABB::set_derecha(NodoABB* derecha){
    this->derecha = derecha;
}

int NodoABB::get_prioridad(){
    return prioridad;
}

void NodoABB::set_prioridad(int prioridad){
    this->prioridad = prioridad;
}

NodoABB::~NodoABB(){
}