// Matias
#include "NodoABB.h"

class ABBProcesos
{
    public:
        ABBProcesos();
        NodoABB* get_raiz();
        void set_raiz(NodoABB*);
        bool buscar(int prioridad, NodoABB*);// Busca un proceso en el árbol
        bool arbolVacio(NodoABB*); // Verifica si el árbol está vacío
        NodoABB* insertarArbol(Proceso, NodoABB*); // Realiza un recorrido postorden del árbol
        void postorden(NodoABB*); // Realiza un recorrido postorden del árbol
        ~ABBProcesos();
/*
        ABB();
        ABB(NodoABB *raiz);
        ABB(string nom, NodoABB *hIz=NULL, NodoABB *hDe=NULL);
        virtual ~ABB();
        void verInorden();
        void verPreorden(NodoABB *arb);
*/
        // void verInorden();
        void insertar(Proceso p);


    private:
        NodoABB *raiz;
};