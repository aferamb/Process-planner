#include "NodoBST.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include <iostream>

using namespace std;

NodoBST::NodoBST(ListaProcesos lproc, NodoBST *izq, NodoBST *der, int prio){
    // hacer un try catch para asegurar que la prioridad pasada y la de la lista sean iguales

    listaProc = lproc;
    hi = izq;
    hd = der;
    try { // try catch para asegurar que la prioridad pasada y la de la lista sean iguales, si la lista es vacíano se compara
        if ((!lproc.es_vacia()) && (prio != lproc.coger(0).get_prioridad())) {
            throw "La prioridad del nodo no coincide con la prioridad de la lista de procesos; no crea NodoBST";
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
    prioridad = prio; // = lproc.coger(0).get_prioridad() cuidado al insertar listas vacías ✨Violacion de segmento✨
}

NodoBST::~NodoBST(){
    
}

