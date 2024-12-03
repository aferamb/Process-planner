/*
1. Crear la pila de procesos que se iniciarán en el sistema. Los datos se crearán manualmente en el código.
2. Mostrar los procesos que se iniciarán (pila de procesos).
3. Borrar la pila de procesos que se van a ejecutar en el sistema operativo.
4. Simular que han pasado N minutos (N leído de teclado). Se simulará el paso del tiempo, escribiendo en pantalla los datos de los eventos de llegada y/o salida de procesos que vayan realizándose (minuto, PID, PPID, id del núcleo que ejecuta el proceso, estado de los distintos núcleos en ese momento). Los procesos que son ejecutados se insertan en el ABBProcesos (según se ha descrito).
5. Mostrar los detalles de los procesos que se encuentran en ejecución en cada uno de los núcleos. (PID del proceso, PPID del proceso, y tiempo)
6. Consultar en cualquier momento qué núcleo tiene menos procesos y cuál es el más ocupado.
7. Consultar en cualquier momento el número de núcleos operativos.
8. Añadir un proceso directamente al ABBProcesos, leyendo sus datos de teclado.
9. Mostrar los datos almacenados en el ABBProcesos, ordenados por prioridad. Para cada nivel de prioridad se mostrará el PID del proceso y la lista de procesos con la misma prioridad (PID del proceso y tiempo que ha vivo en el sistema operativo).
10. Mostrar los procesos con la prioridad dada: Permite consultar y mostrar todos los procesos que tienen un nivel de prioridad específico.
11. Mostrar todos los niveles de prioridad que han tenido al menos un proceso ejecutado, en orden numérico: Lista todos los niveles de prioridad en los que ha habido al menos un proceso atendido, ordenados de menor a mayor prioridad.
12. Calcular y mostrar el nivel de prioridad con el mayor número de procesos y el de menor número: Permite identificar los niveles de prioridad que han tenido la mayor y menor cantidad de procesos atendidos.
13. Calcular y mostrar el tiempo promedio de ejecución de los procesos con una prioridad específica: Calcula el tiempo medio que los procesos de un nivel de prioridad dado han estado en ejecución.
14. Calcular y mostrar el tiempo promedio de ejecución de los procesos en cada nivel de prioridad, recorriendo el árbol en preorden

-- meter en global las funciones del main, para que sea mas limpio
*/

#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include "BST.h"

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace Global;


int main() {
    int opcion;
    Global::lista.insertar_nucleo();// mirar a ver
    Global::lista.insertar_nucleo();// mirar a ver
    Global::lista.insertar_nucleo();// mirar a ver
    Global::tiempoTranscurrido = 0;

    do {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        Global::mostrar_tiempo(); cout << "              MENU PRINCIPAL\n\n";
        cout << "1. Crear pila de procesos. (datos creados manualmente en el codigo)\n";
        cout << "2. Crear e introducir proceso en la pila de procesos.\n";
        cout << "3. Mostrar todos los procesos en la pila de procesos.\n";
        cout << "4. Borrar pila de procesos del sistema.\n"; 
        cout << "5. Aumentar tiempo del sistema (n minutos).\n";    // Cambiar
        cout << "6. Mostrar estado de los nucleos.\n";              
        cout << "7. Consulta nucleo con menos carga, nucleo con mas carga.\n";
        cout << "8. Consulta numero de nucleos operativos.\n";              

        cout << "9. Añadir un proceso directamente al ABBProcesos, leyendo sus datos de teclado.\n"; // Hacer
        cout << "10. Mostrar los datos almacenados en el ABBProcesos, ordenados por prioridad.\n"; // Hacer
        cout << "11. Mostrar los procesos con la prioridad n.\n"; // Hacer
        cout << "12. Niveles de prioridad registrados.\n"; // Hacer y cambiar enunciado
        cout << "13. Nivel de prioridad con mayor y menor numero de procesos.\n"; // Hacer
        cout << "14. Tiempo promedio de ejecucion de procesos con prioridad n.\n"; // Hacer
        cout << "15. Tiempo promedio de ejecucion de procesos en cada nivel de prioridad.\n"; // Hacer

        cout << "16. Simular ejecucion de procesos.\n"; // tiempo meio de estancia en el sistema operativo
        cout << "17. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

        switch (opcion) {
            case 1: {
                Global::cargar_procesos();
                break;
            }

            case 2: {
                // Mostrar todos los procesos en la pila
                Global::introducir_proceso();
                break;
            }

            case 3: {
                // Mostrar todos los procesos en la pila
                Global::mostrar_procesos();
                break;
            }

            case 4: {
                // Borrar pila de procesos
                Global::borrar_procesos();
                break;
            }

            case 5: {   // añadir arboles binarios 
                int n;
                cout << "Ingrese el numero de minutos a aumentar: ";
                cin >> n;
                n--;   //Depende de la interpretacion del enunciado, aumetar 0 minutos puede ser no hacer nada o terminar la ejecucion de los procesos designados al minuto actual
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
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << "Tiempo actual: " << (Global::tiempoTranscurrido/60 < 10 ? "0" : "") << Global::tiempoTranscurrido/60 << ":" << (Global::tiempoTranscurrido%60 < 10 ? "0" : "") << Global::tiempoTranscurrido%60 << endl;
                    cout << endl;

                    // Al principio, insertar los procesos de la pila que se inician en el tiempo actual
                    if(!pila.esVacia() && Global::tiempoTranscurrido == 0){ 
                        Proceso p = pila.mostrar();
                        cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                        cout << endl;

                        while(p.get_inicio() == Global::tiempoTranscurrido){ // poner <= por si se meten procesos con inicio menor al tiempo actual
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

            case 6: {
                // Mostrar estado de los nucleos
                Global::mostrar_estado_nucleos();
                break;
            }

            case 7: {
                // Consulta nucleo con menos carga, nucleo con mas carga
                Global::nucleo_menos_mas_carga();
                break;
            }

            case 8: {
                // Consulta numero de nucleos operativos
                Global::numero_nucleos_operativos();
                break;
            }

            case 9: {
                // Añadir un proceso directamente al ABBProcesos, leyendo sus datos de teclado
                Global::introducir_proceso_BST();
                break;
            }

            case 10: {
                // Mostrar los datos almacenados en el ABBProcesos, ordenados por prioridad
                Global::mostrar_procesos_BST();
                break;
            }

            case 11: {
                // Mostrar los procesos con la prioridad n
                // modificar para que lea la prioridad de teclado
                Global::mostrar_procesos_BST_prioridad(4);
                break;
            }

            case 12: {
                // Niveles de prioridad registrados
                Global::mostrar_niveles_BST();
                break;
            }

            case 13: {
                // Nivel de prioridad con mayor y menor numero de procesos
                Global::mostrar_niveles_BST_mayor_menor();
                break;
            }

            case 14: {
                // Tiempo promedio de ejecucion de procesos con prioridad n
                cout << "Funcion no implementada.\n";
                break;
            }

            case 15: {
                // Tiempo promedio de ejecucion de procesos en cada nivel de prioridad
                cout << "Funcion no implementada.\n";
                break;
            }

            case 16: {
                // Simular ejecucion de proceso
                cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;

                while (!(pila.esVacia() && lista.get_longitud() == 1 && lista.coger(0).get_proceso().get_PID() == -1 && lista.coger(0).get_cola_procesos().es_vacia())){
                    
                    cout << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
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
                    this_thread::sleep_for(chrono::milliseconds(500)); // Esperar 0,5 segundos
                }
                cout << endl;
                cout << "Ejecucion de procesos finalizada." << endl; 
                cout << endl;
                cout << "Tiempo medio de estancia en el sistema operativo: " << Global::contadorTiempoEstancia/contador << " minutos." << endl; // Dividir entre el numero de procesos
                cout << endl;
                break;
            }

            case 17:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida, intentelo nuevamente.\n";
        }
    } while (opcion != 17);  // El menú sigue hasta que el usuario seleccione la opción 17 para salir
    return 0;
}