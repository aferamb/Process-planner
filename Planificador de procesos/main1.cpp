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
#include <chrono>

using namespace std;


int main() {
    int opcion;
    Pila pila;
    Proceso p;
    Cola cola;
    Nucleo nucleo1;
    Nucleo nucleo2;
    Global::tiempoTranscurrido = 0;
    int horas = 0;
    int minutos = 0;

    do {
        cout << "\nTiempo transcurrido: " << (horas < 10 ? "0" : "") << horas << ":" << (minutos < 10 ? "0" : "") << minutos << endl;

        cout << "\nMENU PRINCIPAL\n\n";
        cout << "1. Crear pila de procesos. (datos creados manualmente en el codigo)\n";
        cout << "2. Mostrar todos los procesos en la pila de procesos.\n";
        cout << "3. Borrar pila de procesos del sistema.\n"; 
        cout << "4. Mostrar cola de espera de procesos.\n"; // Cambiar la funcion
        cout << "5. Mostrar procesos en nucleos.\n";
        cout << "6. Aumentar tiempo del sistema (n minutos).\n";
        cout << "7. Simular ejecucion de procesos.\n"; // Al finalizar se mostrara el tiempo meio de estancia en el sistema operativo
        cout << "8. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                /*
                // Creamos 10 procesos y apilamos en la pila de procesos
                for (int i = 1; i <= 10; i++) {
                    p.generarProceso(tiempoTranscurrido);
                    pila.apilar(p);
                }
                */

                Proceso p1=Proceso(1, 0, 4, 0);
                Proceso p2=Proceso(1, 0, 5, 1);
                Proceso p3=Proceso(1, 1, 4, 3);
                Proceso p4=Proceso(2, 7, 3, 7);
                Proceso p5=Proceso(2, 8, 2, 2);
                Proceso p6=Proceso(3, 15, 5, 1);
                Proceso p7=Proceso(3, 20, 3, 4);
                Proceso p8=Proceso(4, 22, 2, 6);
                Proceso p9=Proceso(7, 25, 1, 8);
                Proceso p10=Proceso(5, 26, 4, 2);
                Proceso p11=Proceso(4, 29, 3, 3);
                Proceso p12=Proceso(5, 31, 2, 5);
                Proceso p13=Proceso(6, 33, 1, 1);
                Proceso p14=Proceso(6, 34, 2, 4);
                Proceso p15=Proceso(7, 36, 5, 0);
                Proceso p16=Proceso(8, 41, 3, 6);
                Proceso p17=Proceso(10, 44, 2, 7);
                Proceso p18=Proceso(8, 46, 1, 8);
                Proceso p19=Proceso(9, 47, 4, 2);

                pila.apilar(p7);
                pila.apilar(p11);
                pila.apilar(p13);
                pila.apilar(p9);
                pila.apilar(p18);
                pila.apilar(p15);
                pila.apilar(p6);
                pila.apilar(p17);
                pila.apilar(p2);
                pila.apilar(p1);
                pila.apilar(p12);
                pila.apilar(p10);
                pila.apilar(p4);
                pila.apilar(p8);
                pila.apilar(p14);
                pila.apilar(p5);
                pila.apilar(p16);
                pila.apilar(p3);
                pila.apilar(p19);

                cout << "Pila de procesos creada correctamente.\n";
                // Ordenar la pila de procesos y mostrarla
                pila.ordenarPorTiempoInicio();
                break;
            }

            case 2: {
                // Mostrar todos los procesos en la pila
                pila.mostrarTodos();
                break;
            }

            case 3: {
                // Borrar pila de procesos
                if (pila.esVacia()) {
                    cout << "La pila de procesos ya está vacía.\n";
                } else {
                    //pila.~Pila();
                    while (!pila.esVacia()) {
                        pila.desapilar();
                    }
                    cout << "Pila de procesos eliminada correctamente.\n";
                }
                break;
            }

            case 4: {
                // Mostrar cola de espera de procesos
                cout << "Cola de espera de procesos:\n";
                cola.mostrarCola();
                break;
            }

            case 5: {
                // Mostrar procesos en nucleos
                cout << "Procesos en nucleos:\n";
                cout << "Nucleo 1: ";
                nucleo1.detalles_proceso();
                cout << "Nucleo 2: ";
                nucleo2.detalles_proceso();
                break;
            }

            case 6: {       // Aumentar tiempo del sistema y simular ejecución de procesos hasta tiempo dado
                int n;
                cout << "Ingrese el numero de minutos a aumentar: ";
                cin >> n;

                // Actualizar horas y minutos
                minutos += n; // Aumentar los minutos
                if (minutos >= 60) { // Si los minutos son 60 o más
                    horas += minutos / 60; // Aumentar horas
                    minutos = minutos % 60; // Actualizar minutos
                }

                // Simular ejecución de procesos          
                // Comprobar si hay procesos en la pila de procesos y meter en cola los procesos que tengan tiempo de inicio igual al tiempo actual/tiempo transcurrido
                // Ordenar la cola de procesos por prioridad
                // Comprobar si hay procesos en la cola de procesos y meter los procesos en los núcleos libres, sino, seguir con la ejecución de los procesos en los núcleos
                // Cuando entren procesos en los núcleos, imprimir los detalles de los procesos en los núcleos cuando entran, y eliminar e imprimir los procesos que terminen su ejecución
                // ademas de guardar el tiempo en el que el proceso salio de la pila (tiempo de inicio) y el tiempo en el que termino su ejec para calcular el tiempo de estancia en el sistema operativo
                // actualizar dentro del bucle Global::tiempoTranscurrido += n;  


                cout << "Tiempo actualizado: " << (horas < 10 ? "0" : "") << horas << ":" << (minutos < 10 ? "0" : "") << minutos << endl;
                break;
            }

            case 7: {
                // Simular ejecucion de proceso
                cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;
                cout << "Simulando ejecucion de procesos...\n";
                // Simulamos la ejecución de los procesos
                // Necesario modificar tiempo transcurrido en name space Global
                break;
            }

            case 8:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida, intentelo nuevamente.\n";
            break;
        }
    } while (opcion != 8);  // El menú sigue hasta que el usuario seleccione la opción 5 para salir
    return 0;
}