/**
 * @file main2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
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
    Lista lista;
    lista.insertar_nucleo();// mirar a ver
    Global::tiempoTranscurrido = 0;
    //int horas = Global::tiempoTranscurrido/60;  
    //int minutos = Global::tiempoTranscurrido%60;

    do {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << "              MENU PRINCIPAL\n\n";
        cout << "1. Crear pila de procesos. (datos creados manualmente en el codigo)\n";
        cout << "2. Mostrar todos los procesos en la pila de procesos.\n";
        cout << "3. Borrar pila de procesos del sistema.\n"; 
        cout << "4. Aumentar tiempo del sistema (n minutos).\n";    // Cambiar
        cout << "5. Mostrar estado de los nucleos.\n";              // Crear
        cout << "6. Consulta nucleo con menos carga, nucleo con mas carga.\n";
        cout << "7. Consulta numero de nucleos operativos.\n";              // Cambiar
        cout << "8. Simular ejecucion de procesos.\n"; // Al finalizar se mostrara el tiempo meio de estancia en el sistema operativo
        cout << "9. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

        switch (opcion) {
            case 1: {
                Proceso p1=Proceso(1, 0, 4, 0);
                Proceso p2=Proceso(1, 0, 5, 1);
                Proceso p3=Proceso(1, 1, 4, 3);
                Proceso p4=Proceso(2, 4, 3, 7);
                Proceso p5=Proceso(2, 6, 2, 2);
                Proceso p6=Proceso(3, 9, 5, 1);
                Proceso p7=Proceso(3, 10, 3, 4);
                Proceso p8=Proceso(4, 12, 2, 6);
                Proceso p9=Proceso(7, 13, 1, 8);
                Proceso p10=Proceso(5, 15, 4, 2);
                Proceso p11=Proceso(4, 16, 3, 3);
                Proceso p12=Proceso(5, 18, 2, 5);
                Proceso p13=Proceso(6, 18, 1, 1);
                Proceso p14=Proceso(6, 18, 2, 4);
                Proceso p15=Proceso(7, 19, 5, 0);
                Proceso p16=Proceso(8, 19, 3, 6);
                Proceso p17=Proceso(10, 20, 2, 7);
                Proceso p18=Proceso(8, 21, 1, 8);
                Proceso p19=Proceso(9, 21, 4, 2);

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
                cout << endl;
                cout << endl;
                // Ordenar la pila de procesos y mostrarla
                pila.ordenarPorTiempoInicio();
                break;
            }

            case 2: {
                // Mostrar todos los procesos en la pila
                pila.mostrarTodos();
                cout << endl;
                cout << endl;
                break;
            }

            case 3: {
                // Borrar pila de procesos
                if (pila.esVacia()) {
                    cout << "La pila de procesos ya está vacía.\n";
                    cout << endl;
                    cout << endl;
                } else {
                    //pila.~Pila();
                    while (!pila.esVacia()) {
                        pila.desapilar();
                    }
                    cout << "Pila de procesos eliminada correctamente.\n";
                    cout << endl;
                    cout << endl;
                }
                break;
            }

            case 4: {       // Aumentar tiempo del sistema y simular ejecución de procesos hasta tiempo dado
                int n;
                cout << "Ingrese el numero de minutos a aumentar: ";
                cin >> n;
                n--;   //Depende de la interpretacion del enunciado, aumetar 0 minutos puede der no hacer nada o terminar la ejecucion de los procesos designados al minuto actual
                if (n <= 0){
                    cout << endl;
                    cout << "El tiempo no puede ser cero o negativo.\n";
                    break;
                }
                cout << endl;
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
                        cout << endl;
                        cout << endl;
                        break;
                    }
                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;
                    cout << endl;
                    if(!pila.esVacia()){
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            //cola.insertar_por_prioridad(p);
                            cola.encolar(p);
                            cola.ordenar_por_prioridad();
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                // Igual poner un delete p;
                                break; // Si no hay mas procesos en la pila que inicien ahora, salir del bucle
                            }
                        }
                    }

                    

                    cout << endl;
                    nucleo1.detalles_proceso();
                    nucleo2.detalles_proceso();
                    nucleo3.detalles_proceso();
                    cout << endl;
                    cout << endl;
                }
                break;
            }

            case 5: {
                // Mostrar estado de los nucleos
                cout << "Estado de los nucleos: " << endl;
                cout << endl;
                
                cout << endl;
                break;
            }

            case 6: {
                // Consulta nucleo con menos carga, nucleo con mas carga
                cout << "Nucleo con menos carga: " << endl;
                cout << "Nucleo con mas carga: " << endl;
                cout << endl;
                break;
            }

            case 7: {
                // Consulta numero de nucleos operativos
                cout << "Numero de nucleos operativos: " << endl;
                cout << endl;
                break;
            }

            case 8: {
                // Simular ejecucion de proceso
                cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;

                while (!(pila.esVacia() && cola.es_vacia() && (nucleo1.get_proceso().get_PID() == -1) && (nucleo2.get_proceso().get_PID() == -1))){
                    
                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;
                    cout << endl;
                    if(!pila.esVacia()){
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            //cola.insertar_por_prioridad(p);
                            cola.encolar(p);
                            cola.ordenar_por_prioridad();
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                // Igual poner un delete p;
                                break; // Si no hay mas procesos en la pila que inicien ahora, salir del bucle
                            }
                        }
                    }

                    

                    cout << endl;
                    nucleo1.detalles_proceso();
                    nucleo2.detalles_proceso();
                    nucleo3.detalles_proceso();
                    cout << endl;
                    cout << endl;
                    Global::tiempoTranscurrido++;
                    this_thread::sleep_for(chrono::seconds(1)); // Esperar 1 segundo
                }
                cout << endl;
                cout << "Ejecucion de procesos finalizada." << endl; 
                cout << endl;
                cout << "Tiempo medio de estancia en el sistema operativo: " << contador_tiempo_estancia/19 << " minutos." << endl; // Dividir entre el numero de procesos
                cout << endl;
                break;
            }

            case 9:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida, intentelo nuevamente.\n";
        }
    } while (opcion != 9);  // El menú sigue hasta que el usuario seleccione la opción 8 para salir
    return 0;
}