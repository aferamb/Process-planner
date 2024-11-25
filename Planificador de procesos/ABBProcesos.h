// Matias
#include "NodoABB.h"

class ABBProcesos
{
private:
    NodoABB *raiz;

public:
    ABBProcesos();
    NodoABB* get_raiz();
    void set_raiz(NodoABB*);
    bool buscar(int prioridad, NodoABB*);// Busca un proceso en el árbol
    bool arbolVacio(NodoABB*); // Verifica si el árbol está vacío
    NodoABB* insertarArbol(Proceso, NodoABB*); // Realiza un recorrido postorden del árbol
    void postorden(NodoABB*); // Realiza un recorrido postorden del árbol
    ~ABBProcesos();
};