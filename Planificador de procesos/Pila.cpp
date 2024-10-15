#include "Pila.h"
#include <iostream>
using namespace std;

Pila::Pila()
    {cima = NULL;}

Pila::~Pila()
    {while (cima) desapilar();}

bool Pila::esVacia()
    {return cima == NULL;}

void Pila::apilar(int v)
{
    pnodo nuevo = new NodoPila(v, cima);   
    // comienzo de la pila nuevo nodo
    cima = nuevo;
}

void Pila::desapilar()
{
    if (cima != NULL) {
        pnodo aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
}

int Pila::mostrar()
{
    if (esVacia()) {
        cout << "Pila vacia" << endl;
        return 0;
    } else {
        cout << "Cima pila: " << cima->valor << endl;
        return cima->valor;
    }
}

int Pila::contar()
{
    Pila pAux;
    int aux = 0;
    while(!esVacia())
    {
        pAux.apilar(cima->valor);
        desapilar();
        aux++;
    }
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->valor);
        pAux.desapilar();
    }
    cout << "Num elementos: " << aux << endl;
    return aux;
}

int Pila::fondo()
{
    Pila pAux;
    int aux = 0;
    while(!esVacia())
    {
        pAux.apilar(cima->valor);
        desapilar();
    }
    aux = pAux.cima->valor;
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->valor);
        pAux.desapilar();
    }
    cout << "Fondo pila: " << aux << endl;
    return aux;
}

void Pila::montar(Pila p)
{
    Pila pAux;
    while(!p.esVacia())
    {
        pAux.apilar(p.cima->valor);
        p.desapilar();
    }
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->valor);
        pAux.desapilar();
    }
}

void Pila::quitar(int v)
{
    for (int i = 0; i <= v; i++)
    {
        desapilar();
    }
}

void Pila::invertir()  
{
    Pila pAux;
    Pila pAux2;
    while (!esVacia()) 
    {
        pAux.apilar(cima->valor);
        desapilar();
    }

while (!pAux.esVacia()) 
    {
        pAux2.apilar(pAux.cima->valor);
        pAux.desapilar();
    }

    while (!pAux2.esVacia()) 
    {
        apilar(pAux2.cima->valor);
        pAux2.desapilar();
    }
}

Pila Pila::inversa()
{
    Pila pAux;
    while (!esVacia()) 
    {
        pAux.apilar(cima->valor);
        desapilar();
    }
    return pAux;
}

void Pila::eliminarFondo()
{
    Pila pAux;
    while(!esVacia())
    {
        pAux.apilar(cima->valor);
        desapilar();
    }
    pAux.desapilar();
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->valor);
        pAux.desapilar();
    }
}

bool Pila::ordenadoMayorMenor()
{
    Pila pAux;
    bool ordenado = true;
    while (!esVacia()) 
    {
        int aux = cima->valor;
        pAux.apilar(cima->valor);
        desapilar();
        if (aux > cima->valor) ordenado = false;
    }
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->valor);
        pAux.desapilar();
    }
    if (ordenado) cout << "Pila ordenada de mayor a menor" << endl;
    else cout << "Pila no ordenada de mayor a menor" << endl;
    return ordenado;
}