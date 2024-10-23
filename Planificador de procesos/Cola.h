#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso.h"
class Cola
{
private:
    NodoCola*primero;
    NodoCola*ultimo;
    int longitud;
public:
    Cola();  
    ~Cola();
    void encolar(Proceso proceso);
    void insertar_por_prioridad(Proceso proceso);
    Proceso inicio();
    Proceso fin();
    Proceso desencolar();
    int get_longitud();
    bool es_vacia() const;
    void mostrarCola (); //No es correcto, se implementa para ver que está creada correctamente
    void ordenar_por_prioridad();
    void ordenar_por_prioridad_no_provada();
};
#endif // COLA_H
