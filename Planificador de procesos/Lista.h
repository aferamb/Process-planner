#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Proceso.h"
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
    //void resto(); // Elimina el primer elemento
    //void eult(); // Elimina el último elemento
    Nucleo prim() const; // Devuelve el primer elemento
    Nucleo ult() const; // Devuelve el último elemento
    bool es_vacia() const; // Devuelve si la lista está vacía
    bool ordenada_menor_mayor() const; // Comprueba si está ordenada
    void ordenar_menor_mayor(); // Ordena la lista de menor a mayor
    int get_longitud() const; // Devuelve la longitud de la lista, que tambien es el numero de nucleos operativos
    void insertar_nucleo(); // Crea un nucleo y lo inserta en la lista
    void estado_nucleo(int posicion); // Muestra la información del nucleo en una posición
    void mostrar_estado_nucleos() const; // Muestra la información de todos los nucleos en la lista
    void eliminar(int posicion); // Elimina un nucleo en una posición
    void insertar_proceso(Proceso proceso, int posicion = 0); // Inserta un proceso en un nucleo dado     
    void eliminar_proceso(int posicion); // Elimina un proceso en un nucleo dado               
    int nucleo_menos_carga(bool imprimir=false); // Devuelve posdicion del nucleo con menos carga, o con ninguna carga. Si imprimir es true, muestra la información del nucleo.
    // y si todos los nucleos tienen mas de dos procesos en espera crea un nuevo nucleo, lo inserta en la lista, y muestra la información del nuevo nucleo al ser el nucleo con menos carga
    int nucleo_mas_carga(bool imprimir=false); // Devuelve posición del nucleo con más carga, ademas si imprimir es true, muestra la información del nucleo
    
    Nucleo coger(int n); // Devuelve el nucleo en la posición n


private:
    NodoLista* obtener_nodo(int posicion); // Método auxiliar para obtener un nodo
};

#endif // LISTA_H