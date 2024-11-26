#include "BST.h"
#include "NodoBST.h"

BST::BST() {
    raiz = NULL;
}

BST::BST(NodoBST *raiz) {
    this->raiz = raiz;
}

BST::BST(ListaProcesos lproc, NodoBST *hIz, NodoBST *hDer, int prioridad) {

        // hacer un try catch para asegurar que la prioridad pasada y la de la lista sean iguales

    raiz = new NodoBST(lproc, hIz, hDer, prioridad);
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

void BST::insertar(ListaProcesos lproc) {
    insertar(lproc, raiz);
}

void BST::insertar(ListaProcesos lproc, NodoBST *nodo) {
    if ((nodo->prioridad < lproc.coger(0).get_prioridad()) || (nodo->prioridad == lproc.coger(0).get_prioridad()))
    {
        cout << "Es mayor " << nodo->prioridad << " que " << lproc.coger(0).get_prioridad() << endl;
        if (nodo->hd == NULL)
        {
            NodoBST *nuevo = new NodoBST(lproc);
            nodo->hd = nuevo;
        }else{
            insertar(lproc, nodo->hd);
        }
    }
    else 
    {
        cout << "Es menor " << nodo->prioridad << " que " << lproc.coger(0).get_prioridad() << endl;
        if (nodo->hi == NULL)
        {
            NodoBST *nuevo = new NodoBST(lproc);
            nodo->hi = nuevo;
        }else{
            insertar(lproc, nodo->hi);
        }
    }
    
    
}