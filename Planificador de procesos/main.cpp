//     std::time_t startTime = std::time(nullptr);
// Usando esta funcion optenemos el tiempo en el que el programa se inicio, se utilizara de referencia
// para calcular el rtiempo tra es inicio del programa, restamos el tiempo actual con el tiempo de inicio y nos dara el tiempo transcurrido desde el inicio del programa
// la referencia de tiempo se establece unicamente al inicio del programa, por que si se vuelve a llamar la funcion time() se obtendra un nuevo tiempo de referencia que 
// no sera el mismo que el tiempo de inicio del programa.

#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Proceso.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(){
    // Inicializamos tiempo de inicio/referencia del programa
    Global::tiempoReferencia = time(nullptr);
    cout << "Tiempo de inicio del programa: " << Global::tiempoReferencia << endl;
// El formateo de la fecha a hh:mm:ss lo ha hecho copilot, funciona, pero hay que saber explicarlo
    tm* timeInfo = localtime(&Global::tiempoReferencia);
    char buffer[9]; // hh:mm:ss is 8 characters + null terminator
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeInfo);
    cout << "Tiempo de inicio del programa en formato hh:mm:ss :  " << buffer << endl;


// DANGER ZONE apartir de aqui es generado por copilot y no esta revisado, es para visuyalizar una posible estructura de un programa de planificacion de procesos

    // Creación de un proceso
    Proceso proceso1 = Proceso(1, 5, 10, 20, 1);
    Proceso proceso2 = Proceso(2, 5, 10, 20, 2);
    Proceso proceso3 = Proceso(3, 5, 10, 20, 3);
    Proceso proceso4 = Proceso(4, 5, 10, 20, 4);
    Proceso proceso5 = Proceso(5, 5, 10, 20, 5);

    // Creación de una cola de procesos
    Cola cola_procesos = Cola();
    cola_procesos.encolar(proceso1);
    cola_procesos.encolar(proceso2);
    cola_procesos.encolar(proceso3);
    cola_procesos.encolar(proceso4);
    cola_procesos.encolar(proceso5);

    // Creación de un núcleo
    Nucleo nucleo = Nucleo(1, proceso1, cola_procesos);

    // Mostrar la cola de procesos
    cout << "Cola de procesos:" << endl;
    cola_procesos.mostrarCola();

    // Mostrar el proceso en ejecución
    cout << "Proceso en ejecución:" << endl;
    cout << "ID: " << nucleo.get_proceso()->get_PID() << endl;
    cout << "Prioridad: " << nucleo.get_proceso()->get_prioridad() << endl;
    cout << "Tiempo de vida: " << nucleo.get_proceso()->get_tiempo_de_vida() << endl;

    // Mostrar la cola de procesos
    cout << "Cola de procesos:" << endl;
    cola_procesos.mostrarCola();

    // Mostrar el proceso en ejecución
    cout << "Proceso en ejecución:" << endl;
    cout << "ID: " << nucleo.get_proceso()->get_PID() << endl;
    cout << "Prioridad: " << nucleo.get_proceso()->get_prioridad() << endl;
    cout << "Tiempo de vida: " << nucleo.get_proceso()->get_tiempo_de_vida() << endl;

    // Mo