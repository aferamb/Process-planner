#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H
#include "NodoListaProcesos.h"
#include "Proceso.h"

class ListaProcesos
{
private:
    NodoListaProcesos*primero;
    NodoListaProcesos*ultimo;
    int longitud;
public:
    ListaProcesos();
    ~ListaProcesos();
    //void resto(); // Elimina el primer elemento
    //void eult(); // Elimina el último elemento
    Proceso primP() const;
    Proceso ultP() const; 
    bool es_vacia() const; 
    bool ordenada_menor_mayor() const; 
    void ordenar_menor_mayor(); 
    int get_longitud() const; 
    void insertar_proceso_vacio(); // se puede eliminar si no se utiliza
    void insertar_proceso(Proceso proceso, int posicion = 0); 
    void sustituir_proceso(Proceso proceso, int posicion);
    void eliminar_proceso(int posicion);      
    void mostrar() const;        
    
    Proceso coger(int n); // Devuelve el proceso en la posición n

private:
    NodoListaProcesos* obtener_nodo(int posicion); // Método auxiliar para obtener un nodo
};

#endif // LISTAPROCESOS_H