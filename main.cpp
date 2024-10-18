#include <iostream>
#include "Planificador de procesos/Proceso.h"
#include "Planificador de procesos/Pila.h"
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
        cout << "3. Desapilar el proceso de la cima.\n";
        cout << "4. Aumentar tiempo del sistema (n minutos).\n";
        cout << "5. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Creamos 10 procesos y apilamos en la pila de procesos
                for (int i = 1; i <= 10; i++) {
                    p.generarProceso(tiempoTranscurrido);
                    pila.apilar(p);
                }
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
    } while (opcion != 5);  // El menú sigue hasta que el usuario seleccione la opción 5 para salir
    return 0;
}