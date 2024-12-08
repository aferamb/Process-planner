#include "Planificador.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include "BST.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

/**
 * @brief Inicializa el tiempo de referencia y el tiempo transcurrido
 * 
 */ 

namespace Planificador {
    int opcion;
    Pila pila;
    Proceso p;
    Lista lista;
    Cola colatemp;
    BST arbolProcesos;

    int contador = 0;

    int tiempoTranscurrido = 0; // Definición de la variable en el namespace
    float contadorTiempoEstancia = 0; // Definición de la variable en el namespace

    void mostrar_tiempo() {
        cout << (tiempoTranscurrido/60 < 10 ? "0" : "") << tiempoTranscurrido/60 << ":" << (tiempoTranscurrido%60 < 10 ? "0" : "") << tiempoTranscurrido%60;
    }



    /**
     * @brief Inicia los nucleos
     * 
     */
    void iniciar_nucleos() {
        lista.insertar_nucleo();
        lista.insertar_nucleo();
        lista.insertar_nucleo();
    }



    /**
     * @brief Carga los procesos en la pila
     * 
     */
    void cargar_procesos() {
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
        Proceso p19=Proceso(9, 21, 2, 2);
        Proceso p20=Proceso(0, 0, 2, 1);
        Proceso p21=Proceso(1, 0, 2, 2);
        Proceso p22=Proceso(1, 0, 2, 9);
        Proceso p23=Proceso(1, 0, 2, 5);
        Proceso p24=Proceso(1, 0, 2, 1);
        Proceso p25=Proceso(1, 0, 2, 3);

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
        pila.apilar(p20);
        pila.apilar(p21);
        pila.apilar(p22);
        pila.apilar(p23);
        pila.apilar(p24);
        pila.apilar(p25);

        cout << "Pila de procesos creada correctamente.\n";
        cout << endl;
        cout << endl;
        // Ordenar la pila de procesos y mostrarla
        pila.ordenarPorTiempoInicio();
    }



    /**
     * @brief Introduce un proceso en la pila
     * 
     */
    void introducir_proceso() {
        int ppid1, inicio1, tiempoDeVida1, prioridad1;
        cout << "Introduzca el PID del proceso padre: ";
        cin >> ppid1;
        cout << "Introduzca el tiempo de inicio del proceso: ";
        cin >> inicio1;
        if (inicio1 < tiempoTranscurrido) {
            cout << "El tiempo de inicio del proceso debe ser igual o superior al tiempo actual.\n";
            cout << endl;
            cout << endl;
            return;
        }
        cout << "Introduzca el tiempo de vida del proceso: ";
        cin >> tiempoDeVida1;
        cout << "Introduzca la prioridad del proceso: ";
        cin >> prioridad1;
        if (prioridad1 < 0 || prioridad1 >= 10) {
            cout << "La prioridad del proceso debe estar entre 0 y 9.\n";
            cout << endl;
            cout << endl;
            return;
        }
        Proceso p = Proceso(ppid1, inicio1, tiempoDeVida1, prioridad1);

        pila.apilar(p);
        pila.ordenarPorTiempoInicio();
        cout << "Proceso introducido correctamente.\n";
        cout << endl;
        cout << endl;
    }



    /**
     * @brief Muestra los procesos de la pila
     * 
     */
    void mostrar_procesos() {
        pila.mostrarTodos();
        cout << endl;
        cout << endl;
    }



    /**
     * @brief Borra los procesos de la pila
     * 
     */
    void borrar_procesos() {
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
    }



    /**
     * @brief Aumenta el tiempo del sistema
     * 
     */
    void aumentar_tiempo_sistema() {
        int n;
        cout << "Ingrese el numero de minutos a aumentar: ";
        cin >> n;
        n--;   //Depende de la interpretacion del enunciado, aumetar 0 minutos puede ser no hacer nada o terminar la ejecucion de los procesos designados al minuto actual
        if (n < 0){
            cout << endl;
            cout << "El tiempo no puede ser cero o negativo.\n";
            return;
        }
        cout << endl;
        /**
         * @brief Al principio, y solo al principio, inserta los procesos de la pila qu ese inician en el tiempo actual en los nucleos, luego en bucle
         * comprueva si hay procesos en los nucleos que han terminado y los elimina. Si hay nucleos vacios y sin carga los elimina,
         * y para finalizar el ciclo comprueva si hay procesos en la pila que se inician en el tiempo actual y los inserta en nucleos disponibles o sus colas.
         */

        for(int i = Planificador::tiempoTranscurrido; Planificador::tiempoTranscurrido <= i+n; Planificador::tiempoTranscurrido++){

            if (pila.esVacia() && lista.get_longitud() == 1 && lista.coger(0).get_proceso().get_PID() == -1 && lista.coger(0).get_cola_procesos().es_vacia()){
                cout << "No hay procesos en la pila ni en la cola de espera, y ambos nucleos estan libres.\n";
                cout << "Ejecucion de procesos finalizada." << endl; 
                cout << endl;
                cout << "Tiempo medio de estancia en el sistema operativo: " << Planificador::contadorTiempoEstancia/contador << " minutos." << endl; // Dividir entre el numero de procesos
                cout << endl;
                cout << endl;
                break;
            }
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Tiempo actual: ";
            Planificador::mostrar_tiempo();
            cout << endl;
            cout << endl;

            // Al principio, insertar los procesos de la pila que se inician en el tiempo actual
            if(!pila.esVacia() && Planificador::tiempoTranscurrido == 0){ 
                Proceso p = pila.mostrar();
                cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                cout << endl;
                while(p.get_inicio() == Planificador::tiempoTranscurrido){ // poner <= por si se meten procesos con inicio menor al tiempo actual
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
                if (lista.coger(i).get_proceso().get_PID() != -1 && lista.coger(i).get_tiempo_fin() == Planificador::tiempoTranscurrido){ // aqui falla la ejecucion, PROBLEMAS creo en coger()
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
                while(p.get_inicio() == Planificador::tiempoTranscurrido){
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
    }



    /**
     * @brief Mostrar el estado de los nucleos
     * 
     */
    void mostrar_estado_nucleos() {
        // Mostrar estado de los nucleos
        cout << "Estado de los nucleos: " << endl;
        cout << endl;
        lista.mostrar_estado_nucleos();
        cout << endl;
    }



    /**
     * @brief Consulta el nucleo con menos carga y el nucleo con mas carga
     * 
     */
    void nucleo_menos_mas_carga() {
        // Consulta nucleo con menos carga, nucleo con mas carga
        lista.nucleo_menos_carga(true);
        lista.nucleo_mas_carga(true);
    }



    /**
     * @brief Consulta el numero de nucleos operativos
     * 
     */
    void numero_nucleos_operativos() {
        // Consulta numero de nucleos operativos
        cout << "Numero de nucleos operativos: " << lista.get_longitud() << endl; // La longitud de la lista de nucleos es igual al numero de nucleos operativos
        cout << endl;
    }


    /**
     * @brief Introduce un proceso en el arbol de procesos
     * 
     */
    void introducir_proceso_BST() {
        int ppid1, inicio1, tiempoDeVida1, prioridad1;
        cout << "Introduzca el PID del proceso padre: ";
        cin >> ppid1;
        cout << "Introduzca el tiempo de inicio del proceso: ";
        cin >> inicio1;
        if (inicio1 < tiempoTranscurrido) {
            cout << "El tiempo de inicio del proceso debe ser igual o superior al tiempo actual.\n";
            cout << endl;
            cout << endl;
            return;
        }
        cout << "Introduzca el tiempo de vida del proceso: ";
        cin >> tiempoDeVida1;
        cout << "Introduzca la prioridad del proceso: ";
        cin >> prioridad1;
        if (prioridad1 < 0 || prioridad1 >= 10) {
            cout << "La prioridad del proceso debe estar entre 0 y 9.\n";
            cout << endl;
            cout << endl;
            return;
        }
        Proceso p = Proceso(ppid1, inicio1, tiempoDeVida1, prioridad1);
        p.set_tiempo_ejecucion(tiempoDeVida1);

        arbolProcesos.insertar(p);
        cout << "Proceso introducido correctamente.\n";
        cout << endl;
        cout << endl;
    }



    /**
     * @brief Muestra los procesos del arbol de procesos
     * 
     */
    void mostrar_procesos_BST() {
        arbolProcesos.verInorden(); 
        cout << endl;
    }



    /**
     * @brief Muestra los procesos de una prioridad concreta
     * 
     */
    void mostrar_procesos_BST_prioridad() {
        int prioridad;
        cout << "Introduzca la prioridad de los procesos a mostrar: ";
        cin >> prioridad;
        arbolProcesos.buscar(prioridad);
        cout << endl;
    }



    /**
     * @brief Muestra los niveles de prioridad registrados que tienen al menos un proceso
     * 
     */
    void mostrar_niveles_BST() {
        arbolProcesos.mostrarNiveles();
        cout << endl;
    }



    /**
     * @brief Muestra el nivel de prioridad con mayor y menor numero de procesos
     * 
     */
    void mostrar_niveles_BST_mayor_menor() {
        arbolProcesos.nivelesMayorMenorProcesos();
        cout << endl;
    }



    /**
     * @brief Muestra el tiempo promedio de ejecucion de procesos con prioridad n
     * 
     */
    void mostrar_tiempo_promedio_procesos_prioridad_insertada() {
        int prioridad;
        cout << "Introduzca la prioridad de los procesos a mostrar: ";
        cin >> prioridad;
        cout << "Tiempo promedio de ejecucion de procesos con prioridad " << prioridad << ": " << arbolProcesos.tiempoPromedioProcesos(prioridad) << " minutos" << endl;
        cout << endl;
    }



    /**
     * @brief Muestra el tiempo promedio de ejecucion de procesos en cada nivel de prioridad
     * 
     */
    void mostrar_tiempo_promedio_procesos_prioridad() {
        cout << "Tiempo promedio de ejecucion de procesos en cada nivel de prioridad:" << endl;
        cout << endl;
        arbolProcesos.mostrar_tiempo_promedio_procesos_prioridad();
        cout << endl;
    }



    /**
     * @brief Simula la ejecucion de los procesos
     * 
     */
    void simular_ejecucion_procesos() {
        cout << "A continuacion se simulara el paso del tiempo en el sistema operativo hasta que finalicen todos los procesos" << endl;
        while (!(pila.esVacia() && lista.get_longitud() == 1 && lista.coger(0).get_proceso().get_PID() == -1 && lista.coger(0).get_cola_procesos().es_vacia())){
            cout << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Tiempo actual: ";
            Planificador::mostrar_tiempo();
            cout << endl;
            cout << endl;

            // Al principio, insertar los procesos de la pila que se inician en el tiempo actual
            if(!pila.esVacia() && Planificador::tiempoTranscurrido == 0){ 
                Proceso p = pila.mostrar();
                cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                cout << endl;

                while(p.get_inicio() == Planificador::tiempoTranscurrido){
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

            // Eliminar procesos que han terminado
            for (int i = 0; i < lista.get_longitud(); i++){
                if (lista.coger(i).get_proceso().get_PID() != -1 && lista.coger(i).get_tiempo_fin() == Planificador::tiempoTranscurrido){ // aqui falla la ejecucion, PROBLEMAS creo en coger()
                    lista.eliminar_proceso(i);
                }
            }

            // Eliminar nucleos vacios y sin carga
            for (int i = 0; i < lista.get_longitud(); i++){
                if (lista.get_longitud() > 1 && lista.coger(i).get_proceso().get_PID() == -1 && lista.coger(i).get_cola_procesos().es_vacia()){
                    lista.eliminar(i);
                }
            }

            if(!pila.esVacia()){ // Al final, insertar los procesos de la pila que se inician en el tiempo actual
                Proceso p = pila.mostrar();
                cout << "Proceso en la cima de la pila: PID: " << p.get_PID() << ", PPID: " << p.get_PPID() << ", Inicio: " << p.get_inicio() << ", Tiempo de vida: " << p.get_tiempo_de_vida() << ", Prioridad: " << p.get_prioridad() << endl;
                cout << endl;
                while(p.get_inicio() == Planificador::tiempoTranscurrido){
                    lista.insertar_proceso(p, lista.nucleo_menos_carga()); 
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
            Planificador::tiempoTranscurrido++;
            this_thread::sleep_for(chrono::milliseconds(250)); // Esperar 0,23 segundos
        }
        cout << endl;
        cout << "Ejecucion de procesos finalizada." << endl; 
        cout << endl;
        cout << "Tiempo medio de estancia en el sistema operativo: " << Planificador::contadorTiempoEstancia/contador << " minutos." << endl; // Dividir entre el numero de procesos
        cout << endl;
    }
}