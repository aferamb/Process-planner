#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
class Pila
{
    private:
        pnodo cima;
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(int v);
        void desapilar();
        int mostrar();
        int contar();
        int fondo();
        void montar(Pila p);
        void quitar(int v);
        void invertir();
        Pila inversa();
        void eliminarFondo();
        bool ordenadoMayorMenor();
};

#endif // PILA_H
