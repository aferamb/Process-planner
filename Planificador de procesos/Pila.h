#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila {
    private:
        pnodo cima;
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(Proceso p);
        void desapilar();
        Proceso mostrar();
        int contar();
        Proceso fondo();
        void montar(Pila s);
        void quitar(Proceso p);
        void invertir();
        Pila inversa();
        void eliminarFondo();
        bool ordenadoMayorMenor();
        void mostrarTodos();
};

#endif // PILA_H
