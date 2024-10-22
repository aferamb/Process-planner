#include "Pila.h"
#include <iostream>
using namespace std;


/**
 * @brief Construct a new Pila:: Pila object
 * 
 */
Pila::Pila() {
    cima = NULL;
}


/**
 * @brief Destroy the Pila:: Pila object
 * 
 */
Pila::~Pila() {
    while (cima) desapilar();
}


/**
 * @brief Comprueba si la pila está vacía
 * 
 * @return true Si la pila está vacía
 * @return false Si la pila no está vacía
 */
bool Pila::esVacia() {
    return cima == NULL;
}


/**
 * @brief Apila un proceso en la pila
 * 
 * @param p Proceso a apilar
 */
void Pila::apilar(Proceso p) {
    pnodo nuevo = new NodoPila(p, cima);
    // comienzo de la pila nuevo nodo
    cima = nuevo;
}


/**
 * @brief Desapila un proceso de la pila
 * 
 */
void Pila::desapilar() {
    if (cima != NULL) {
        pnodo aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
}


/**
 * @brief Muestra el proceso que está en la cima de la pila
 * 
 * @return Proceso Proceso en la cima de la pila
 */
Proceso Pila::mostrar() {
    if (esVacia()) {
        cout << "Pila vacia" << endl;
        return Proceso();   // Retornamos un proceso vacío, no debería ser un 0 o nullptr o algo asi
    } else {
        //cout << "Cima pila: " << cima->proceso.get_PID() << endl;
        return cima->proceso;
    }
}


/**
 * @brief Cuenta la cantidad de elementos en la pila
 * 
 * @return int Cantidad de elementos en la pila
 */
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


/**
 * @brief Devuelve el proceso que está en el fondo de la pila
 * 
 * @return Proceso Proceso en el fondo de la pila
 */
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


/**
 * @brief Monta una pila en otra
 * 
 * @param p Pila a montar
 */
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


/**
 * @brief Quita un proceso de la pila
 * 
 * @param p Proceso a quitar
 */
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


/**
 * @brief Invierte la pila
 * 
 */
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


/**
 * @brief Devuelve la pila inversa
 * 
 * @return Pila Pila inversa
 */
Pila Pila::inversa() {
    Pila pAux;
    while (!esVacia()) {
        pAux.apilar(cima->proceso);
        desapilar();
    }
    return pAux;
}


/**
 * @brief Elimina el proceso que está en el fondo de la pila
 * 
 */
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


/**
 * @brief Comprueba si la pila está ordenada de mayor a menor en base al tiempo de inicio
 * 
 * @return true Si la pila está ordenada de mayor a menor
 * @return false Si la pila no está ordenada de mayor a menor
 */
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


/**
 * @brief Ordena la pila de menor a mayor en base al tiempo de inicio
 * 
 */
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


/**
 * @brief Muestra todos los procesos de la pila
 * 
 */
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
