#include "global.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include "BST.h"

#include <iostream>

using namespace std;

/**
 * @brief Inicializa el tiempo de referencia y el tiempo transcurrido
 * 
 */ 

namespace Global {
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

    void aumentar_tiempo() {
        tiempoTranscurrido++;
    }

    void aumentar_tiempo(int n) {
        tiempoTranscurrido += n;
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
        Proceso p = Proceso(ppid1, inicio1, tiempoDeVida1, prioridad1);

        arbolProcesos.insertar(p);
        cout << "Proceso introducido correctamente.\n";
        cout << endl;
        cout << endl;
    }

    void mostrar_procesos_BST() {
        arbolProcesos.verInorden(); 
        cout << endl;
    }

    void mostrar_procesos_BST_prioridad(int prioridad) {
        arbolProcesos.buscar(prioridad);
        cout << endl;
    }

    void mostrar_niveles_BST() {
        arbolProcesos.mostrarNiveles();
        cout << endl;
    }

    void mostrar_niveles_BST_mayor_menor() {
        arbolProcesos.mostrarNivelesMayorMenor();
        cout << endl;
    }
}