#include "Pila.h"
#include <iostream>
using namespace std;

Pila::Pila() {
    cima = NULL;
}

Pila::~Pila() {
    while (cima) desapilar();
}

bool Pila::esVacia() {
    return cima == NULL;
}

void Pila::apilar(Proceso p) {
    pnodo nuevo = new NodoPila(p, cima);
    // comienzo de la pila nuevo nodo
    cima = nuevo;
}

void Pila::desapilar() {
    if (cima != NULL) {
        pnodo aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
}

Proceso Pila::mostrar() {
    if (esVacia()) {
        cout << "Pila vacia" << endl;
        return Proceso();   // Retornamos un proceso vacío, no debería ser un 0 o nullptr o algo asi
    } else {
        //cout << "Cima pila: " << cima->proceso.get_PID() << endl;
        return cima->proceso;
    }
}

int Pila::contar() {
    Pila pAux;
    int aux = 0;
    while(!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
        aux++;
    }

    while(!pAux.esVacia()) {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
    return aux;
}

Proceso Pila::fondo()
{
    Pila pAux;
    Proceso procesoFondo;

    while(!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
    }
    procesoFondo = pAux.cima->proceso;
    while(!pAux.esVacia()) {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
    cout << "Fondo pila: " << procesoFondo.get_PID() << endl;
    return procesoFondo;
}

void Pila::montar(Pila p)
{
    Pila pAux;
    while(!p.esVacia())
    {
        pAux.apilar(p.cima->proceso);
        p.desapilar();
    }
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
}

void Pila::quitar(Proceso p) {
    Pila pAux;
    // Buscar el proceso en la pila comparando los PID
    while (!esVacia() && cima->proceso.get_PID() != p.get_PID()) {
        pAux.apilar(cima->proceso);  // Mover el proceso actual a la pila auxiliar
        desapilar();
    }
    // Si encontramos el proceso con el mismo PID, lo quitamos
    if (!esVacia() && cima->proceso.get_PID() == p.get_PID()) {
        desapilar();
    }
    // Volver a apilar los elementos desde la pila auxiliar a la pila original
    while (!pAux.esVacia()) {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
}

void Pila::invertir() {
    Pila pAux;
    while (!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
    }
    while (!pAux.esVacia()) {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
}

Pila Pila::inversa() {
    Pila pAux;
    while (!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
    }
    return pAux;
}

void Pila::eliminarFondo()
{
    Pila pAux;
    while(!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
    }
    pAux.desapilar();
    while(!pAux.esVacia())
    {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
}

bool Pila::ordenadoMayorMenor() {
    Pila Aux;
    bool ordenado = true;
    if (!esVacia()) {
        Proceso procesoAnterior = cima->proceso;  // Guardamos el proceso de la cima

        while (!esVacia()) {
            Proceso procesoActual = cima->proceso;  // Tomamos el proceso actual
            Aux.apilar(cima->proceso);  // Apilamos el proceso en la pila auxiliar
            desapilar();  // Desapilamos de la pila original

            // Comparamos cuando inicia proceso actual con el anterior
            if (procesoActual.get_inicio() < procesoAnterior.get_inicio()) {
                ordenado = false;  // Si el tiempo de inicio actual es menor que el anterior, no está ordenado
            }
            procesoAnterior = procesoActual;  // Actualizamos el proceso anterior
        }
    }
    // Restauramos la pila original
    while (!Aux.esVacia()) {
        apilar(Aux.cima->proceso);
        Aux.desapilar();
    }
    // Mensaje sobre si la pila está ordenada o no
    if (ordenado) {
        cout << "Pila ordenada de menor a mayor en base al tiempo de inicio" << endl;
    } else {
        cout << "Pila NO está ordenada de menor a mayor en base al tiempo de inicio" << endl;
    }
    return ordenado;
}

void Pila::ordenarPorTiempoInicio() {
    Pila pAux;
    while (!esVacia()) {
        Proceso procesoActual = cima->proceso;
        desapilar();
        while (!pAux.esVacia() && pAux.cima->proceso.get_inicio() > procesoActual.get_inicio()) {
            apilar(pAux.cima->proceso);
            pAux.desapilar();
        }
        pAux.apilar(procesoActual);
    }
    while (!pAux.esVacia()) {
        apilar(pAux.cima->proceso);
        pAux.desapilar();
    }
}

void Pila::mostrarTodos() {
    if (esVacia()) {
        cout << "La pila está vacía.\n";
        return;
    }
    Pila aux;
    while (!esVacia()) {
        Proceso p = cima->proceso;
        cout << "PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Minutos de inicio: " << p.get_inicio()
             << ", Tiempo de vida: " << p.get_tiempo_de_vida() << " minutos, Prioridad: " << p.get_prioridad() << endl;
        aux.apilar(p);
        desapilar();
    }
    while (!aux.esVacia()) {
        apilar(aux.cima->proceso);
        aux.desapilar();
    }
}
