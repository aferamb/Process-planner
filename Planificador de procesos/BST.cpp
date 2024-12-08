#include "BST.h"
#include <vector>

BST::BST() {
    raiz = nullptr;
}

BST::BST(NodoBST *raiz) {
    this->raiz = raiz;
}

BST::BST(ListaProcesos lproc, NodoBST *hIz, NodoBST *hDer, int prio) {
    try { // try catch para asegurar que la prioridad pasada y la de la lista sean iguales, si la lista es vacíano se compara
        if ((!lproc.es_vacia()) && (prio != lproc.coger(0).get_prioridad())) {
            throw "La prioridad del nodo no coincide con la prioridad de la lista de procesos; no crea Arbol";
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
    raiz = new NodoBST(lproc, hIz, hDer, prio);
}

BST::~BST() {
}

void BST::verInorden() {
    if (raiz == nullptr) {
        cout << "El árbol está vacío" << endl;
    } else {
        verInorden(raiz);
    }
}


void BST::verInorden(NodoBST* nodo) {
    if (nodo != nullptr) {
        // Recorrer subárbol izquierdo
        verInorden(nodo->hi);

        // Imprimir la prioridad del nodo
        cout << "Nodo con prioridad: " << nodo->prioridad << endl;

        // Imprimir los procesos de la lista asociada al nodo
        cout << "Procesos en la lista:" << endl;
        nodo->listaProc.mostrar(); // Acceso directo al miembro listaProc

        // Recorrer subárbol derecho
        verInorden(nodo->hd);
    }
}

// modificar pasar parametros de proceso y arbol
void BST::insertar_arbol(Proceso proc, NodoBST*& nodo) {
    if (nodo == nullptr) {
        // Crear un nuevo nodo si no existe uno con la prioridad
        ListaProcesos nuevaLista;
        nodo = new NodoBST(nuevaLista, nullptr, nullptr, proc.get_prioridad());
        cout << "Nodo creado con prioridad: " << proc.get_prioridad() << endl;
        nodo->listaProc.insertar_proceso(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
        return;
    }

    if (proc.get_prioridad() == nodo->prioridad) {
        // Insertar en la lista si ya existe un nodo con la misma prioridad
        nodo->listaProc.insertar_proceso(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
    } else if (proc.get_prioridad() < nodo->prioridad) {
        // Recorrer hacia la izquierda si la prioridad del proceso es menor
        insertar_arbol(proc, nodo->hi);
    } else {
        // Recorrer hacia la derecha si la prioridad del proceso es mayor
        insertar_arbol(proc, nodo->hd);
    }
}

void BST::insertar(Proceso proc) {
    insertar_arbol(proc, raiz);
}

NodoBST* BST::get_raiz() {
    return raiz;
}

bool BST::esVacio() {
    return raiz == nullptr;
}

void BST::buscar(int prioridad) {
    buscar(prioridad, raiz);
}

void BST::buscar(int prioridad, NodoBST *nodo) {
    if (nodo == nullptr) {
        cout << "No se ha encontrado un nodo con prioridad " << prioridad << endl;
    } else if (nodo->prioridad == prioridad) {
        cout << "Nodo con prioridad " << prioridad << " encontrado" << endl;
        cout << "Procesos en la lista:" << endl;
        nodo->listaProc.mostrar();
    } else if (nodo->prioridad < prioridad) {
        buscar(prioridad, nodo->hd);
    } else {
        buscar(prioridad, nodo->hi);
    }
}

void BST::mostrarNiveles() {
    mostrarNiveles(raiz);
}

void BST::mostrarNiveles(NodoBST *nodo) {
    if (nodo != nullptr && !nodo->listaProc.es_vacia()) {
        mostrarNiveles(nodo->hd);
        cout << "Prioridad: " << nodo->prioridad << endl;
        mostrarNiveles(nodo->hi);
    }
}

void BST::nivelesMayorMenorProcesos() {
    vector<NodoBST*> nodosMayor; // Nodos con la mayor cantidad de procesos
    vector<NodoBST*> nodosMenor; // Nodos con la menor cantidad de procesos
    int maxProcesos = -1;
    int minProcesos = INT_MAX;

    // Recorrer el árbol en preorden para determinar los niveles
    nivelesMayorMenorProcesos(raiz, nodosMayor, nodosMenor, maxProcesos, minProcesos);

    // Mostrar los nodos con mayor cantidad de procesos
    cout << "Niveles con mayor cantidad de procesos (" << maxProcesos << " procesos):" << endl;
    for (NodoBST* nodo : nodosMayor) {
        cout << "Prioridad: " << nodo->prioridad << endl;
    }

    // Mostrar los nodos con menor cantidad de procesos
    cout << "Niveles con menor cantidad de procesos (" << minProcesos << " procesos):" << endl;
    for (NodoBST* nodo : nodosMenor) {
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

void BST::nivelesMayorMenorProcesos(NodoBST* nodo, vector<NodoBST*>& nodosMayor, vector<NodoBST*>& nodosMenor, int& maxProcesos, int& minProcesos) {
    if (nodo != nullptr) {
        int cantidadProcesos = nodo->listaProc.get_longitud();

        // Comparar con el máximo actual
        if (cantidadProcesos > maxProcesos) {
            maxProcesos = cantidadProcesos;
            nodosMayor.clear(); // Limpiar los nodos previos, ya que hay un nuevo máximo
            nodosMayor.push_back(nodo);
        } else if (cantidadProcesos == maxProcesos) {
            nodosMayor.push_back(nodo); // Agregar nodo al vector si empata con el máximo
        }

        // Comparar con el mínimo actual
        if (cantidadProcesos < minProcesos) {
            minProcesos = cantidadProcesos;
            nodosMenor.clear(); // Limpiar los nodos previos, ya que hay un nuevo mínimo
            nodosMenor.push_back(nodo);
        } else if (cantidadProcesos == minProcesos) {
            nodosMenor.push_back(nodo); // Agregar nodo al vector si empata con el mínimo
        }

        // Recorrer subárbol izquierdo y derecho
        nivelesMayorMenorProcesos(nodo->hi, nodosMayor, nodosMenor, maxProcesos, minProcesos);
        nivelesMayorMenorProcesos(nodo->hd, nodosMayor, nodosMenor, maxProcesos, minProcesos);
    }
}

float BST::tiempoPromedioProcesos(int prioridad) {
    return tiempoPromedioProcesos(prioridad, raiz);
}

float BST::tiempoPromedioProcesos(int prioridad, NodoBST* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    if (nodo->prioridad == prioridad) {
        float tiempoTotal = 0;
        float cantidadProcesos = nodo->listaProc.get_longitud();
        if (cantidadProcesos == 0) {
            return 0;
        }
        for (int i = 0; i < cantidadProcesos; ++i) {
            Proceso p = nodo->listaProc.coger(i);
            tiempoTotal += p.get_tiempo_ejecucion(); // O cambiar a get_tiempo_ejecucion si es correcto
        }
    return tiempoTotal / cantidadProcesos;
    } else if (prioridad < nodo->prioridad) {
        return tiempoPromedioProcesos(prioridad, nodo->hi);
    } else {
        return tiempoPromedioProcesos(prioridad, nodo->hd);
    }
}

void BST::mostrar_tiempo_promedio_procesos_prioridad() {
    mostrar_tiempo_promedio_procesos_prioridad(raiz);
}

void BST::mostrar_tiempo_promedio_procesos_prioridad(NodoBST* nodo) {
    if (nodo != nullptr) {
        // Calcular el tiempo promedio para el nodo actual
        float tiempoPromedio = tiempoPromedioProcesos(nodo->prioridad, nodo);
        cout << "Prioridad: " << nodo->prioridad << " - Tiempo promedio: " << tiempoPromedio << " minutos" << endl;

        // Recorrer el subárbol izquierdo y derecho
        mostrar_tiempo_promedio_procesos_prioridad(nodo->hi);
        mostrar_tiempo_promedio_procesos_prioridad(nodo->hd);
    }
}