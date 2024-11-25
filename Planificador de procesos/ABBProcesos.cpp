// Matias
#include "ABBProcesos.h"
#include "Proceso.h"
#include "NodoABB.h"


ABBProcesos::ABBProcesos() {
    raiz = new NodoABB(0); // Nodo raíz con prioridad P0 (según el enunciado)
}

NodoABB* ABBProcesos::get_raiz() {
    return raiz;
}

void ABBProcesos::set_raiz(NodoABB* nodo) {
    raiz = nodo;
}

bool ABBProcesos::buscar(int prioridad, NodoABB* nodo) {
    if (arbolVacio(nodo)) {
        return false;
    }
    if (prioridad < nodo->get_prioridad()) {
        return buscar(prioridad, nodo->get_izquierda());
    } else if (prioridad > nodo->get_prioridad()) {
        return buscar(prioridad, nodo->get_derecha());
    } else {
        return true;
    }
}

bool ABBProcesos::arbolVacio(NodoABB* nodo) {
    return nodo == nullptr;
}

NodoABB* ABBProcesos::insertarArbol(Proceso proceso, NodoABB* nodo) {
    if (arbolVacio(nodo)) {
        NodoABB* nuevo = new NodoABB(proceso.get_prioridad());
        nuevo->get_ListaProcesos().insertar_proceso(proceso);
        return nuevo;
    }

    if (proceso.get_prioridad() < nodo->get_prioridad()) {
        nodo->set_izquierda(insertarArbol(proceso,nodo->get_izquierda()));
    } else if (proceso.get_prioridad() > nodo->get_prioridad()) {
        nodo->set_derecha(insertarArbol(proceso, nodo->get_derecha()));
    } else {
        nodo->get_ListaProcesos().insertar_proceso(proceso);
    }
    return nodo;
}

void ABBProcesos::postorden(NodoABB* nodo) { // Prueba para mostrar contenido del arbol (no probado aún)
    if (!arbolVacio(nodo)) {
        postorden(nodo->get_izquierda());
        postorden(nodo->get_derecha());
        cout << "Prioridad: " << nodo->get_prioridad() << endl;
        // nodo->get_ListaProcesos().imprimir_procesos(); // imprimir_procesos() no está definido en ListaProcesos
    }
}

ABBProcesos::~ABBProcesos(){
    delete raiz;
}
