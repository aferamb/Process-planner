#include "NodoBST.h"
#include "BST.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Inserto" << endl;
    BST abb;    
    ListaProcesos p1;
    p1.insertar_proceso(Proceso(1, 0, 4, 0));
    abb.insertar(p1);
}