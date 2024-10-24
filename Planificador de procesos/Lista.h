#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Nucleo.h"

class Lista
{
private:
    NodoLista*primero;
    NodoLista*ultimo;
    int longitud;
public:
    Lista();
    ~Lista();
    // Algunas igual son innecesarias
    void resto(); // Elimina el primer elemento
    void eult(); // Elimina el último elemento
    Nucleo primero() const; // Devuelve el primer elemento
    Nucleo ultimo() const; // Devuelve el último elemento
    bool es_vacia() const; // Devuelve si la lista está vacía
    bool ordenada_menor_mayor() const; // Comprueba si está ordenada
    void ordenar_menor_mayor(); // Ordena la lista de menor a mayor
    bool contiene(const Nucleo& nucleo) const; // Comprueba si un nucleo está en la lista   // 
    int buscar(const Nucleo& nucleo) const; // Devuelve la posición de un nucleo
    Nucleo coger(int n) const; // Devuelve el nucleo en la posición n
    void insertar(const Nucleo& nucleo, int posicion = 0); // Inserta un nucleo                    // Mirar a ver si esto esta bien const Nucleo& nucleo
    void modificar(int posicion, const Nucleo& nucleo); // Modifica el nucleo en una posición
    void mostrar() const; // Muestra la lista

    int nucleo_menos_carga() const; // Devuelve posdicion del nucleo con menos carga
    int nucleo_mas_carga() const; // Devuelve posición del nucleo con más carga
    Nucleo* nucleo(int posicion); // Devuelve la direccion del nucleo en una posición, para modificarlo

private:
    NodoLista* obtener_nodo(int posicion) const; // Método auxiliar para obtener un nodo
};

#endif // LISTA_H