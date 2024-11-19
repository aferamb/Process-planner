/**
 * @file main2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
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
    Pila pila;
    Proceso p;
    Lista lista;
    Cola colatemp;
    int contador = 0;
    lista.insertar_nucleo();// mirar a ver
    lista.insertar_nucleo();// mirar a ver
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
                Proceso pd1=Proceso(0, 0, 5, 1);
                Proceso pd2=Proceso(1, 0, 3, 2);
                Proceso pd3=Proceso(1, 0, 6, 9);
                Proceso pd4=Proceso(1, 0, 7, 5);
                Proceso pd5=Proceso(1, 0, 6, 1);
                Proceso pd6=Proceso(1, 0, 8, 3);

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

                pila.apilar(pd1);
                pila.apilar(pd2);
                pila.apilar(pd3);
                pila.apilar(pd4);
                pila.apilar(pd5);
                pila.apilar(pd6);

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
                if (n < 0){
                    cout << endl;
                    cout << "El tiempo no puede ser cero o negativo.\n";
                    break;
                }
                cout << endl;
                /**
                 * @brief Al principio, y solo al principio, inserta los procesos de la pila qu ese inician en el tiempo actual en los nucleos, luego en bucle
                 * comprueva si hay procesos en los nucleos que han terminado y los elimina. Si hay nucleos vacios y sin carga los elimina,
                 * y para finalizar el ciclo comprueva si hay procesos en la pila que se inician en el tiempo actual y los inserta en nucleos disponibles o sus colas.
                 * 
                 */

                for(int i = Global::tiempoTranscurrido; Global::tiempoTranscurrido <= i+n; Global::tiempoTranscurrido++){

                    if (pila.esVacia() && lista.get_longitud() == 1 && lista.coger(0).get_proceso().get_PID() == -1 && lista.coger(0).get_cola_procesos().es_vacia()){
                        cout << "No hay procesos en la pila ni en la cola de espera, y ambos nucleos estan libres.\n";
                        cout << "Ejecucion de procesos finalizada." << endl; 
                        cout << endl;
                        cout << "Tiempo medio de estancia en el sistema operativo: " << Global::contadorTiempoEstancia/contador << " minutos." << endl; // Dividir entre el numero de procesos
                        cout << endl;
                        cout << endl;
                        break;
                    }

                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;
                    cout << endl;

                    // Al principio, insertar los procesos de la pila que se inician en el tiempo actual
                    if(!pila.esVacia() && Global::tiempoTranscurrido == 0){ 
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;

                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            colatemp.insertar_por_prioridad(p);
                            cout << endl;
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                break;
                            }
                        }
                        while (!colatemp.es_vacia()){
                            lista.insertar_proceso(colatemp.desencolar(), lista.nucleo_menos_carga());
                            contador++;
                        }
                    }

                    // hacer en forma funcion, eliminar procesos que han terminado
                    for (int i = 0; i < lista.get_longitud(); i++){
                        if (lista.coger(i).get_proceso().get_PID() != -1 && lista.coger(i).get_tiempo_fin() == Global::tiempoTranscurrido){ // aqui falla la ejecucion, PROBLEMAS creo en coger()
                            lista.eliminar_proceso(i);
                        }
                    }

                    // hacer en forma funcion, eliminar nucleos vacios y sin carga
                    for (int i = 0; i < lista.get_longitud(); i++){
                        if (lista.get_longitud() > 1 && lista.coger(i).get_proceso().get_PID() == -1 && lista.coger(i).get_cola_procesos().es_vacia()){
                            lista.eliminar(i);
                        }
                    }

                    if(!pila.esVacia()){ // Al final, insertar los procesos de la pila que se inician en el tiempo actual
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            lista.insertar_proceso(p, lista.nucleo_menos_carga()); // terminar funcion de nucleo menos carga, para que añada un nucleo si es necesario
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                break;
                            }
                        }
                    }

                    cout << endl;
                    lista.mostrar_estado_nucleos();
                    cout << endl;
                    cout << endl;
                }
                break;
            }

            case 5: {
                // Mostrar estado de los nucleos
                cout << "Estado de los nucleos: " << endl;
                cout << endl;
                lista.mostrar_estado_nucleos();
                cout << endl;
                break;
            }

            case 6: {
                // Consulta nucleo con menos carga, nucleo con mas carga
                lista.nucleo_menos_carga(true);
                lista.nucleo_mas_carga(true);
                break;
            }

            case 7: {
                // Consulta numero de nucleos operativos
                cout << "Numero de nucleos operativos: " << lista.get_longitud() << endl; // La longitud de la lista de nucleos es igual al numero de nucleos operativos
                cout << endl;
                break;
            }

            case 8: {
                // Simular ejecucion de proceso
                cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;

                while (!(pila.esVacia() && lista.get_longitud() == 1 && lista.coger(0).get_proceso().get_PID() == -1 && lista.coger(0).get_cola_procesos().es_vacia())){
                    
                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;
                    cout << endl;

                    // Al principio, insertar los procesos de la pila que se inician en el tiempo actual
                    if(!pila.esVacia() && Global::tiempoTranscurrido == 0){ 
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;

                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            colatemp.insertar_por_prioridad(p);
                            cout << endl;
                            //lista.mostrar_estado_nucleos(); // para ver si mete el proceso
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                break;
                            }
                        }
                        while (!colatemp.es_vacia()){
                            lista.insertar_proceso(colatemp.desencolar(), lista.nucleo_menos_carga());
                            contador++;
                        }
                    }

                    // hacer en forma funcion, eliminar procesos que han terminado
                    for (int i = 0; i < lista.get_longitud(); i++){
                        if (lista.coger(i).get_proceso().get_PID() != -1 && lista.coger(i).get_tiempo_fin() == Global::tiempoTranscurrido){ // aqui falla la ejecucion, PROBLEMAS creo en coger()
                            lista.eliminar_proceso(i);
                        }
                    }

                    // hacer en forma funcion, eliminar nucleos vacios y sin carga

                    for (int i = 0; i < lista.get_longitud(); i++){
                        if (lista.get_longitud() > 1 && lista.coger(i).get_proceso().get_PID() == -1 && lista.coger(i).get_cola_procesos().es_vacia()){
                            lista.eliminar(i);
                        }
                    }

                    if(!pila.esVacia()){ // Al final, insertar los procesos de la pila que se inician en el tiempo actual
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;
                        while(p.get_inicio() == Global::tiempoTranscurrido){
                            lista.insertar_proceso(p, lista.nucleo_menos_carga()); // terminar funcion de nucleo menos carga, para que añada un nucleo si es necesario
                            pila.desapilar();
                            if(!pila.esVacia()){
                                p = pila.mostrar();
                            } else {
                                break;
                            }
                        }
                    }
                    cout << endl;
                    lista.mostrar_estado_nucleos();
                    cout << endl;
                    cout << endl;
                    Global::tiempoTranscurrido++;
                    this_thread::sleep_for(chrono::seconds(1)); // Esperar 1 segundo
                }
                cout << endl;
                cout << "Ejecucion de procesos finalizada." << endl; 
                cout << endl;
                cout << "Tiempo medio de estancia en el sistema operativo: " << Global::contadorTiempoEstancia/contador << " minutos." << endl; // Dividir entre el numero de procesos
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