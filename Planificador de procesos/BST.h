#ifndef BST_H
#define BST_H
#include "NodoBST.h"

class BST
{
    private:
        NodoBST *raiz;

    public:
        BST();
        BST(NodoBST *raiz);
        BST(ListaProcesos lproc, NodoBST *hIz = NULL, NodoBST *hDer = NULL, int prioridad = 5);
        virtual ~BST();
        void verInorden();
        void verInorden(NodoBST *arb);

        void insertar(ListaProcesos lproc); // si existe nodo con la misma prioridad, insertar en la lista
        void insertar(ListaProcesos lproc, NodoBST *arb);

    protected:

/*
NodoBST* get_raiz();
        void set_raiz(NodoBST*);
        bool buscar(int prioridad, NodoBST*);// Busca un proceso en el árbol
        bool arbolVacio(NodoBST*); // Verifica si el árbol está vacío
        NodoBST* insertarArbol(Proceso, NodoBST*); // Realiza un recorrido postorden del árbol
        void postorden(NodoBST*); // Realiza un recorrido postorden del árbol
        ~BST();
*/
};  
#endif // BST_H