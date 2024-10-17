#include "NodoCola.h"
#include "Proceso.h"

NodoCola::NodoCola()
{
    Proceso proceso;
    siguiente=NULL;
    //constructor por defecto
}
NodoCola::NodoCola(Proceso proceso, int prioridad, NodoCola*sig)
{
    proceso = proceso;
    siguiente = sig;
    prioridad = prioridad;
}
NodoCola::~NodoCola()
{
 //dtor
}