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
        void verInorden(); // Muestra el árbol en inorden
        void verInorden(NodoBST *arb); // Muestra el nodo/subarbol en inorden

        void insertar(Proceso proc); // Inserta un proceso en el árbol
        void insertar_arbol(Proceso proc, NodoBST *&arb); // Inserta un proceso en el árbol
        NodoBST* get_raiz();

        void buscar(int prioridad); // Busca un proceso en el árbol
        void buscar(int prioridad, NodoBST *nodo); // Busca un proceso en el árbol

        void mostrarNiveles(); // Muestra los niveles del árbol
        void mostrarNiveles(NodoBST *nodo); // Muestra los niveles del árbol

        void mostrarNivelesMayorMenor(); // Muestra los niveles del árbol de mayor a menor
        void mostrarNivelesMayorMenor(NodoBST *nodo); // Muestra los niveles del árbol de mayor a menor

/*    protected:
        NodoBST* get_raiz();
        void set_raiz(NodoBST*);
        bool buscar(int prioridad, NodoBST*);// Busca un proceso en el árbol
        bool arbolVacio(NodoBST*); // Verifica si el árbol está vacío
        NodoBST* insertarArbol(Proceso, NodoBST*); // Realiza un recorrido postorden del árbol
        void postorden(NodoBST*); // Realiza un recorrido postorden del árbol
        ~BST();*/
};  
#endif // BST_H