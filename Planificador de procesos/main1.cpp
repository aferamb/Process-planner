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
    int tiempoTranscurrido = 0;
    int horas = 0;
    int minutos = 0;

    do {
        cout << "\nTiempo transcurrido: " << (horas < 10 ? "0" : "") << horas << ":" << (minutos < 10 ? "0" : "") << minutos << endl;

        cout << "\nMENU PRINCIPAL\n\n";
        cout << "1. Crear 10 procesos en pila de procesos.\n";
        cout << "2. Mostrar todos los procesos en la pila de procesos.\n";
        cout << "3. Borrar pila de procesos del sistema.\n"; // 
        cout << "4. Mostrar cola de espera de procesos.\n";
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
                Proceso p3=Proceso(1, 1, 2, 3);
                Proceso p4=Proceso(2, 7, 1, 7);
                Proceso p5=Proceso(2, 8, 2, 2);
                Proceso p6=Proceso(2, 15, 5, 1);
                Proceso p7=Proceso(3, 20, 3, 4);
                Proceso p8=Proceso(3, 22, 2, 6);
                Proceso p9=Proceso(3, 25, 1, 8);
                Proceso p10=Proceso(3, 26, 4, 2);
                Proceso p11=Proceso(3, 30, 3, 3);
                cout << "Pila de procesos creada correctamente.\n";
                break;
            }
            case 2: {
                // Mostrar todos los procesos en la pila
                pila.mostrarTodos();
                break;
            }
            case 3: {
                // Desapilar el proceso en la cima
                if (!pila.esVacia()) {
                    pila.desapilar();
                    cout << "Proceso desapilado.\n";
                } else {
                    cout << "No se puede desapilar, la pila está vacía.\n";
                }
                break;
            }
            case 4: {
                // Aumentar tiempo del sistema
                int n;
                cout << "Ingrese el numero de minutos a aumentar: ";
                cin >> n;

                // Actualizar horas y minutos
                minutos += n; // Aumentar los minutos
                if (minutos >= 60) { // Si los minutos son 60 o más
                    horas += minutos / 60; // Aumentar horas
                    minutos = minutos % 60; // Actualizar minutos
                }
                // Actualizar tiempo transcurrido
                tiempoTranscurrido += n;

                cout << "Tiempo actualizado: " << (horas < 10 ? "0" : "") << horas << ":"
                    << (minutos < 10 ? "0" : "") << minutos << endl;
                break;
            }
            case 5: {
                cout << "Saliendo del programa...\n";
                break;
            }
            default:
                cout << "Opcion no valida, intentelo nuevamente.\n";
            break;
        }
    } while (opcion != 8);  // El menú sigue hasta que el usuario seleccione la opción 5 para salir
    return 0;
}