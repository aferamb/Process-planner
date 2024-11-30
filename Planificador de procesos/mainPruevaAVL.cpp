#include "NodoBST.h"
#include "BST.h"
#include "Proceso.h"
#include "ListaProcesos.h"
#include <iostream>

using namespace std;

int main()
{
	BST arbol;

	// Crear procesos con diferentes prioridades
	Proceso p1(1, 0, 5, 5);  // PID 1, Prioridad 5
	Proceso p2(2, 2, 3, 3);  // PID 2, Prioridad 3
	Proceso p3(3, 1, 4, 5);  // PID 3, Prioridad 5
	Proceso p4(4, 4, 6, 7);  // PID 4, Prioridad 7
	Proceso p5(5, 3, 2, 2);  // PID 5, Prioridad 2
	Proceso p6(6, 5, 1, 1);  // PID 6, Prioridad 1
	Proceso p7(7, 6, 8, 9);  // PID 7, Prioridad 9
	Proceso p8(4, 12, 2, 6); // PID 8, Prioridad 6
	Proceso p9(7, 13, 1, 8); // PID 9, Prioridad 8
	Proceso p10(5, 15, 4, 2); // PID 10, Prioridad 2
	Proceso p11(4, 16, 3, 3); // PID 11, Prioridad 3
	Proceso p12(5, 18, 2, 5); // PID 12, Prioridad 5
	Proceso p13(6, 18, 1, 1); // PID 13, Prioridad 1
	Proceso p14(6, 18, 2, 4); // PID 14, Prioridad 4
	Proceso p15(7, 19, 5, 1); // PID 15, Prioridad 0
	Proceso p16(8, 19, 3, 6); // PID 16, Prioridad 6
	Proceso p17(10, 20, 2, 7); // PID 17, Prioridad 7
	Proceso p18(8, 21, 1, 8); // PID 18, Prioridad 8
	Proceso p19(9, 21, 4, 2); // PID 19, Prioridad 2
	Proceso p20(0, 0, 5, 1); // PID 20, Prioridad 1
	Proceso p21(1, 0, 3, 2); // PID 21, Prioridad 2
	Proceso p22(1, 0, 6, 9); // PID 22, Prioridad 9
	Proceso p23(1, 0, 7, 5); // PID 23, Prioridad 5
	Proceso p24(1, 0, 6, 1); // PID 24, Prioridad 1
	Proceso p25(1, 0, 8, 3); // PID 25, Prioridad 3
	Proceso p26(1, 0, 9, 0); // PID 26, Prioridad 0

	cout << "Insertando procesos en el árbol..." << endl;
	arbol.insertar(p1);
	arbol.insertar(p2);
	arbol.insertar(p3);
	arbol.insertar(p4);
	arbol.insertar(p5);
	arbol.insertar(p6);
	arbol.insertar(p7);
	arbol.insertar(p8);
	arbol.insertar(p9);
	arbol.insertar(p10);
	arbol.insertar(p11);
	arbol.insertar(p12);
	arbol.insertar(p13);
	arbol.insertar(p14);
	arbol.insertar(p15);
	arbol.insertar(p16);
	arbol.insertar(p17);
	arbol.insertar(p18);
	arbol.insertar(p19);
	arbol.insertar(p20);
	arbol.insertar(p21);
	arbol.insertar(p22);
	arbol.insertar(p23);
	arbol.insertar(p24);
	arbol.insertar(p25);
	arbol.insertar(p26);


	cout << "\nRecorrido inorden del árbol:" << endl;
	arbol.verInorden();

	return 0;
}