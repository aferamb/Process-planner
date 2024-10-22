/**
 * @file main1.cpp
 * @author Alejandro
 * @brief Programa principal para simular un planificador de procesos de la parte 1
 * @version 0.1
 * @date 2024-10-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Proceso.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;


int main() {
    int opcion;
    float contador_tiempo_estancia = 0; // Contador para calcular el tiempo medio de estancia en el sistema operativo, se hace float para que el resultado de la division sea float
    Pila pila;
    Proceso p;
    Cola cola;
    Nucleo nucleo1;
    Nucleo nucleo2;
    Global::tiempoTranscurrido = 0;
    //int horas = Global::tiempoTranscurrido/60;  
    //int minutos = Global::tiempoTranscurrido%60;

    do {
        cout << "\nTiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;

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
                // Simular ejecución de procesos          
                // Comprobar si hay procesos en la pila de procesos y meter en cola los procesos que tengan tiempo de inicio igual al tiempo actual/tiempo transcurrido
                // Ordenar la cola de procesos por prioridad
                // Comprobar si hay procesos en la cola de procesos y meter los procesos en los núcleos libres, sino, seguir con la ejecución de los procesos en los núcleos
                // Cuando entren procesos en los núcleos, imprimir los detalles de los procesos en los núcleos cuando entran, y eliminar e imprimir los procesos que terminen su ejecución
                // ademas de guardar el tiempo en el que el proceso salio de la pila (tiempo de inicio) y el tiempo en el que termino su ejec para calcular el tiempo de estancia en el sistema operativo
                // actualizar dentro del bucle Global::tiempoTranscurrido += n;  

                for(int i = Global::tiempoTranscurrido; Global::tiempoTranscurrido <= i+n; Global::tiempoTranscurrido++){

                    if (pila.esVacia() && cola.es_vacia() && nucleo1.get_proceso().get_PID() == -1 && nucleo2.get_proceso().get_PID() == -1){
                        cout << "No hay procesos en la pila ni en la cola de espera, y ambos nucleos estan libres.\n";
                        cout << endl;
                        cout << "Ejecucion de procesos finalizada." << endl; 
                        cout << endl;
                        cout << "Tiempo medio de estancia en el sistema operativo: " << contador_tiempo_estancia/19 << " minutos." << endl; // Dividir entre el numero de procesos
                        break;
                    }

                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;

                    if(!pila.esVacia()){
                        Proceso p = pila.mostrar();
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            cola.encolar(p);
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                // Igual poner un delete p;
                                break; // Si no hay mas procesos en la pila que inicien ahora, salir del bucle
                            }
                        }
                    }

                    cola.ordenar_por_prioridad(); // La no provada de momento no se usa
                    if(!cola.es_vacia()){

                        // Nucleo 1
                        if ((nucleo1.get_proceso().get_PID() == -1) || (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido)){
                            if (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido){
                                nucleo1.detalles_proceso(false);
                                contador_tiempo_estancia += nucleo1.get_tiempo_fin() - nucleo1.get_proceso().get_inicio();
                            }
                            nucleo1.add_proceso(cola.desencolar());
                            nucleo1.detalles_proceso(true);

                        // Nucleo 2
                        } else if (!cola.es_vacia() && ((nucleo2.get_proceso().get_PID() == -1) || (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido))){
                            if (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido){
                                nucleo2.detalles_proceso(false);
                                contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            }
                            nucleo2.add_proceso(cola.desencolar());
                            nucleo2.detalles_proceso(true);
                        
                        // Nucleo 2
                        } else if (cola.es_vacia() && (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido)){
                            nucleo2.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            nucleo2.eliminar_proceso();
                        }

                        nucleo1.detalles_proceso();
                        nucleo2.detalles_proceso();

                    } else {
                        // Nucleo 1
                        if (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido){
                            nucleo1.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo1.get_tiempo_fin() - nucleo1.get_proceso().get_inicio();
                            nucleo1.eliminar_proceso();
                        }
                        // Nucleo 2
                        if (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido){
                            nucleo2.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            nucleo2.eliminar_proceso();
                        }

                        nucleo1.detalles_proceso();
                        nucleo2.detalles_proceso();
                    }
                }
                break;
            }

            case 7: {
                // Simular ejecucion de proceso
                cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;

                while (!(pila.esVacia() && cola.es_vacia() && (nucleo1.get_proceso().get_PID() == -1) && (nucleo2.get_proceso().get_PID() == -1))){
                    
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;

                    if(!pila.esVacia()){
                        Proceso p = pila.mostrar();
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            cola.encolar(p);
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                // Igual poner un delete p;
                                break; // Si no hay mas procesos en la pila que inicien ahora, salir del bucle
                            }
                        }
                    }

                    cola.ordenar_por_prioridad(); // La no provada de momento no se usa
                    if(!cola.es_vacia()){

                        // Nucleo 1
                        if ((nucleo1.get_proceso().get_PID() == -1) || (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido)){
                            if (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido){
                                nucleo1.detalles_proceso(false);
                                contador_tiempo_estancia += nucleo1.get_tiempo_fin() - nucleo1.get_proceso().get_inicio();
                            }
                            nucleo1.add_proceso(cola.desencolar());
                            nucleo1.detalles_proceso(true);

                        // Nucleo 2
                        } else if (!cola.es_vacia() && ((nucleo2.get_proceso().get_PID() == -1) || (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido))){
                            if (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido){
                                nucleo2.detalles_proceso(false);
                                contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            }
                            nucleo2.add_proceso(cola.desencolar());
                            nucleo2.detalles_proceso(true);
                        
                        // Nucleo 2
                        } else if (cola.es_vacia() && (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido)){
                            nucleo2.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            nucleo2.eliminar_proceso();
                        }

                        nucleo1.detalles_proceso();
                        nucleo2.detalles_proceso();

                    } else {
                        // Nucleo 1
                        if (nucleo1.get_tiempo_fin() == Global::tiempoTranscurrido){
                            nucleo1.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo1.get_tiempo_fin() - nucleo1.get_proceso().get_inicio();
                            nucleo1.eliminar_proceso();
                        }
                        // Nucleo 2
                        if (nucleo2.get_tiempo_fin() == Global::tiempoTranscurrido){
                            nucleo2.detalles_proceso(false);
                            contador_tiempo_estancia += nucleo2.get_tiempo_fin() - nucleo2.get_proceso().get_inicio();
                            nucleo2.eliminar_proceso();
                        }

                        nucleo1.detalles_proceso();
                        nucleo2.detalles_proceso();
                    }
                    Global::tiempoTranscurrido++;
                    this_thread::sleep_for(chrono::seconds(1)); // Esperar 1 segundo
                }
                cout << endl;
                cout << "Ejecucion de procesos finalizada." << endl; 
                cout << endl;
                cout << "Tiempo medio de estancia en el sistema operativo: " << contador_tiempo_estancia/19 << " minutos." << endl; // Dividir entre el numero de procesos
                break;
            }

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida, intentelo nuevamente.\n";
        }
    } while (opcion != 8);  // El menú sigue hasta que el usuario seleccione la opción 8 para salir
    return 0;
}