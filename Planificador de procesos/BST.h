#ifndef BST_H
#define BST_H
#include "NodoBST.h"
#include <vector>

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
        int contarNodos(); // Cuenta los nodos del árbol
        void insertar(Proceso proc); // Inserta un proceso en el árbol
        NodoBST* get_raiz();
        bool esVacio();

        void buscar(int prioridad); // Muestra procesos en el arbol de una prioridad dada
        void buscar(int prioridad, NodoBST *nodo);

        void mostrarNiveles(); // Muestra los niveles del árbol
        void mostrarNiveles(NodoBST *nodo);

        void nivelesMayorMenorProcesos();
        void nivelesMayorMenorProcesos(NodoBST* nodo, vector<NodoBST*>& nodosMayor, vector<NodoBST*>& nodosMenor, int& maxProcesos, int& minProcesos);

        float tiempoPromedioProcesos(int prioridad); // Devuelve tiempo promedio de ejecución de los procesos de una prioridad dada
        float tiempoPromedioProcesos(int prioridad, NodoBST *nodo);

        void mostrar_tiempo_promedio_procesos_prioridad(); // Muestra el tiempo promedio de ejecución de los procesos de una prioridad dada
        void mostrar_tiempo_promedio_procesos_prioridad(NodoBST *nodo);

    protected:
        void verInorden(NodoBST *nodo); 
        void insertar_arbol(Proceso proc, NodoBST *&arb); // Inserta un proceso en el árbol
};

#endif // BST_