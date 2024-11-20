/*
    Main no probado hasta que ListaProcesos este implementada
    Para imprimir en postorden falta función en ListaProcesos -> imprimir_procesos();
    para mostrar procesos insertados en el arbol
*/

#include "ABBProcesos.h"
#include "Proceso.h"
#include "NodoABB.h"
#include "ListaProcesos.h"
#include <iostream>

using namespace std;

int main() {
    // Crear el árbol
    ABBProcesos arbol;

    // Crear procesos con diferentes prioridades
    Proceso p1(1, 10, 20, 1); // Prioridad 1
    Proceso p2(2, 15, 30, 2); // Prioridad 2
    Proceso p3(3, 20, 25, 3); // Prioridad 3
    Proceso p4(4, 12, 22, 4); // Prioridad 4
    Proceso p5(5, 18, 28, 5); // Prioridad 5
    Proceso p6(6, 25, 35, 6); // Prioridad 6
    Proceso p7(7, 30, 40, 7); // Prioridad 7
    Proceso p8(8, 35, 45, 8); // Prioridad 8
    Proceso p9(9, 40, 50, 9); // Prioridad 9

    // Insertar los procesos en el árbol
    arbol.insertarArbol(p1, arbol.get_raiz());  // Insertar proceso con prioridad 1
    arbol.insertarArbol(p2, arbol.get_raiz());  // Insertar proceso con prioridad 2
    arbol.insertarArbol(p3, arbol.get_raiz());  // Insertar proceso con prioridad 3
    arbol.insertarArbol(p4, arbol.get_raiz());  // Insertar proceso con prioridad 4
    arbol.insertarArbol(p5, arbol.get_raiz());  // Insertar proceso con prioridad 5
    arbol.insertarArbol(p6, arbol.get_raiz());  // Insertar proceso con prioridad 6
    arbol.insertarArbol(p7, arbol.get_raiz());  // Insertar proceso con prioridad 7
    arbol.insertarArbol(p8, arbol.get_raiz());  // Insertar proceso con prioridad 8
    arbol.insertarArbol(p9, arbol.get_raiz());  // Insertar proceso con prioridad 9

    // Realizar un recorrido postorden del árbol
    cout << "Recorrido postorden del árbol:" << endl;
    arbol.postorden(arbol.get_raiz());

    return 0;
}
