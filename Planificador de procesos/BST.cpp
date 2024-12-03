#include "BST.h"
#include "global.h"
#include <iostream>

/**
 * @brief Constructor por defecto de la clase BST
 * 
 */
BST::BST() {
    raiz = nullptr;
}


/**
 * @brief Constructor de la clase BST, con un nodo raíz
 * 
 * @param raiz Nodo raíz
 */
BST::BST(NodoBST *raiz) {
    this->raiz = raiz;
}


/**
 * @brief Constructor de la clase BST, con una lista de procesos, un nodo hijo izquierdo, un nodo hijo derecho y una prioridad
 * 
 * @param lproc Lista de procesos
 * @param hIz Nodo hijo izquierdo
 * @param hDer Nodo hijo derecho
 * @param prio Prioridad del nodo
 */
BST::BST(ListaProcesos lproc, NodoBST *hIz, NodoBST *hDer, int prio) {
    try { // try catch para asegurar que la prioridad pasada y la de la lista sean iguales, si la lista es vacíano se compara
        if ((!lproc.es_vacia()) && (prio != lproc.coger(0).get_prioridad())) {
            throw "La prioridad del nodo no coincide con la prioridad de la lista de procesos; no crea Arbol";
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
    raiz = new NodoBST(lproc, hIz, hDer, prio);
}


/**
 * @brief Destructor de la clase BST
 * 
 */
BST::~BST() {
}


/**
 * @brief Muestra el árbol en inorden
 * 
 */
void BST::verInorden() {
    if (raiz == nullptr) {
        cout << "El árbol está vacío" << endl;
    } else {
        verInorden(raiz);
    }
}


/**
 * @brief Recorre el árbol en inorden y muestra los nodos de manera recursiva
 * 
 * @param nodo 
 */
void BST::verInorden(NodoBST* nodo) {
    if (nodo != nullptr) {
        // Recorrer subárbol izquierdo
        verInorden(nodo->hi);

        // Imprimir la prioridad del nodo
        cout << "Nodo con prioridad: " << nodo->prioridad << endl;

        // Imprimir los procesos de la lista asociada al nodo
        cout << "Procesos en la lista:" << endl;
        nodo->listaProc.mostrar(); // Acceso directo al miembro listaProc

        // Recorrer subárbol derecho
        verInorden(nodo->hd);
    }
}


/**
 * @brief Inserta un proceso en el árbol, en el nodo correspondiente a su prioridad
 * Si no existe un nodo con la prioridad del proceso, se crea uno nuevo
 * Función recursiva
 * 
 * @param proc 
 * @param nodo 
 */
void BST::insertar_arbol(Proceso proc, NodoBST*& nodo) {
    if (nodo == nullptr) {
        // Crear un nuevo nodo si no existe uno con la prioridad
        ListaProcesos nuevaLista;
        nodo = new NodoBST(nuevaLista, nullptr, nullptr, proc.get_prioridad());
        Global::mostrar_tiempo();
        cout << " | Nodo creado con prioridad: " << proc.get_prioridad() << endl;
        nodo->listaProc.insertar_proceso(proc);
        Global::mostrar_tiempo();
        cout << " | Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
        return;
    }

    if (proc.get_prioridad() == nodo->prioridad) {
        // Insertar en la lista si ya existe un nodo con la misma prioridad
        nodo->listaProc.insertar_proceso(proc);
        Global::mostrar_tiempo();
        cout << " | Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
    } else if (proc.get_prioridad() < nodo->prioridad) {
        // Recorrer hacia la izquierda si la prioridad del proceso es menor
        insertar_arbol(proc, nodo->hi);
    } else {
        // Recorrer hacia la derecha si la prioridad del proceso es mayor
        insertar_arbol(proc, nodo->hd);
    }
}


/**
 * @brief Inserta un proceso en el árbol
 * 
 * @param proc 
 */
void BST::insertar(Proceso proc) {
    insertar_arbol(proc, raiz);
}


/**
 * @brief Devuelve la raíz del árbol
 * 
 * @return NodoBST* 
 */
NodoBST* BST::get_raiz() {
    return raiz;
}

/*
void BST::set_raiz(NodoBST *raiz) {
    this->raiz = raiz;
}

bool BST::buscar(int prioridad, NodoBST *nodo) {
    if (nodo == NULL) {
        return false;
    } else if (nodo->prioridad == prioridad) {
        return true;
    } else if (nodo->prioridad < prioridad) {
        return buscar(prioridad, nodo->hd);
    } else {
        return buscar(prioridad, nodo->hi);
    }
}

bool BST::arbolVacio(NodoBST *nodo) {
    return nodo == NULL;
}

NodoBST* BST::insertarArbol(Proceso proc, NodoBST *nodo) {
    if (nodo == NULL) {
        ListaProcesos nuevaLista;
        nuevaLista.insertar_proceso(proc);
        return new NodoBST(nuevaLista, NULL, NULL, proc.get_prioridad());
    } else if (proc.get_prioridad() < nodo->prioridad) {
        nodo->hi = insertarArbol(proc, nodo->hi);
    } else if (proc.get_prioridad() > nodo->prioridad) {
        nodo->hd = insertarArbol(proc, nodo->hd);
    } else {
        nodo->lproc.insertar_proceso(proc);
    }
    return nodo;
}

void BST::postorden(NodoBST *nodo) {
    if (nodo != NULL) {
        postorden(nodo->hi);
        postorden(nodo->hd);
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

BST::~BST() {
    delete raiz;
}

*/