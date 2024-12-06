#include "Planificador.h"
#include <iostream>
using namespace std;
using namespace Planificador;


int main() {
    Planificador::iniciar_nucleos();
    int opcion;
    do {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        Planificador::mostrar_tiempo(); cout << "              MENU PRINCIPAL\n\n";
        cout << "1. Crear pila de procesos. (datos creados manualmente en el codigo)\n";
        cout << "2. Crear e introducir proceso en la pila de procesos.\n";
        cout << "3. Mostrar todos los procesos en la pila de procesos.\n";
        cout << "4. Borrar pila de procesos del sistema.\n"; 
        cout << "5. Aumentar tiempo del sistema (n minutos).\n";    
        cout << "6. Mostrar estado de los nucleos.\n";              
        cout << "7. Consulta nucleo con menos carga, nucleo con mas carga.\n";
        cout << "8. Consulta numero de nucleos operativos.\n";              
        cout << "9. Insertar un proceso directamente al ABBProcesos, leyendo sus datos de teclado.\n"; 
        cout << "10. Mostrar los datos almacenados en el ABBProcesos, ordenados por prioridad.\n"; 
        cout << "11. Mostrar los procesos con la prioridad n.\n"; 
        cout << "12. Niveles de prioridad registrados.\n"; 
        cout << "13. Nivel de prioridad con mayor y menor numero de procesos.\n"; // Corregir
        cout << "14. Tiempo promedio de ejecucion de procesos con prioridad n.\n"; 
        cout << "15. Tiempo promedio de ejecucion de procesos en cada nivel de prioridad.\n"; 
        cout << "16. Simular ejecucion de procesos.\n";
        cout << "17. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;


        switch (opcion) {
            case 1: {
                Planificador::cargar_procesos();
                break;
            }

            case 2: {
                Planificador::introducir_proceso();
                break;
            }

            case 3: {
                Planificador::mostrar_procesos();
                break;
            }

            case 4: {
                Planificador::borrar_procesos();
                break;
            }

            case 5: {   
                Planificador::aumentar_tiempo_sistema();
                break;
            }

            case 6: {
                Planificador::mostrar_estado_nucleos();
                break;
            }

            case 7: {
                Planificador::nucleo_menos_mas_carga();
                break;
            }

            case 8: {
                Planificador::numero_nucleos_operativos();
                break;
            }

            case 9: {
                Planificador::introducir_proceso_BST();
                break;
            }

            case 10: {
                Planificador::mostrar_procesos_BST();
                break;
            }

            case 11: {
                Planificador::mostrar_procesos_BST_prioridad();
                break;
            }

            case 12: {
                Planificador::mostrar_niveles_BST();
                break;
            }

            case 13: {
                Planificador::mostrar_niveles_BST_mayor_menor();
                break;
            }

            case 14: {
                Planificador::mostrar_tiempo_promedio_procesos_prioridad_insertada();
                break;
            }

            case 15: {
                Planificador::mostrar_tiempo_promedio_procesos_prioridad();
                break;
            }

            case 16: {
                Planificador::simular_ejecucion_procesos();
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