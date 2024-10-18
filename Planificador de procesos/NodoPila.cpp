#include "NodoPila.h"

NodoPila::NodoPila(Proceso p, NodoPila *sig) {
    proceso = p;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
    //dtor
}
