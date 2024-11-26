#include "BST.h"


BST::BST() {
    raiz = NULL;
}

BST::BST(NodoBST *raiz) {
    this->raiz = raiz;
}

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

BST::~BST() {
}

void BST::verInorden() {
    verInorden(raiz);
}

void BST::verInorden(NodoBST *arb) {
    if (arb != NULL)
    {
        verInorden(arb->hi);
        cout << "Prioridad: " << arb->prioridad << endl;
        verInorden(arb->hd);
    }
}

void BST::insertar(Proceso proc) {
    insertar(proc, raiz); 
}

// modificar pasar parametros de proceso y arbol
void BST::insertar(Proceso proc, NodoBST *nodo) {  
    int priorProceso = proc.get_prioridad();
    if (nodo->prioridad <= priorProceso) {
        cout << "Es mayor " << nodo->prioridad << " que " << priorProceso << endl;
        if (nodo->hd == NULL) {
            ListaProcesos nuevaLista;
            nuevaLista.insertar_proceso(proc);
            NodoBST *nuevo = new NodoBST(nuevaLista, nullptr, nullptr, priorProceso);
            nodo->hd = nuevo;
        } else {
            insertar(proc, nodo->hd);
        }
    } else {
        cout << "Es menor " << nodo->prioridad << " que " << priorProceso << endl;
        if (nodo->hi == NULL) {
            ListaProcesos nuevaLista;
            nuevaLista.insertar_proceso(proc);
            NodoBST *nuevo = new NodoBST(nuevaLista, nullptr, nullptr, priorProceso);// terminar creaccion de nodo bien
            nodo->hi = nuevo;
        } else {
            insertar(proc, nodo->hi);
        }
    }
}