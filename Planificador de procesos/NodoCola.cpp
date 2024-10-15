#include "NodoCola.h"

NodoCola::NodoCola()
{
    elemento='0';
    siguiente=NULL;
    //constructor por defecto
}
NodoCola::NodoCola(char elemento, int prioridad, NodoCola*sig)
{
    elemento = elemento;
    siguiente = sig;
    prioridad = prioridad;
}
NodoCola::~NodoCola()
{
 //dtor
}