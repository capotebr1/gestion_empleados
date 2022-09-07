#include "info.h"
#include <stdio.h>
typedef struct empleadoNodo * TAbb;

//crea un Arbol Binario de Busqueda vacio
TAbb crearAbb();

//Libera memoria asignada a abb y todos sus elementos
void liberarAbb(TAbb abb);

//devuelve "true" si y solo si abb no tiene elementos
bool esVacioAbb(TAbb abb);

//inserta un empleado con sus "datos" en el ABB
TAbb darAlta(TInfo datos, TAbb abb);

//elimina al empleado cuyo numero de cedula coincide con el "ci" ingresado
//!Precondicion : Existe empleado con cedula "ci"
TAbb darBaja(unsigned int ci , TAbb abb);

//Devuelve la informacion del nodo "empleado" de abb
TInfo raiz(TAbb abb);



//Devuelve el subarbol que tiene el nodo cuyo componente CI coincide con "cedulaIdentidad".
//Si "cedulaIdentidad" no pertenece a "abb", devuelve el árbol vacío.
TAbb buscarSubarbol(unsigned int cedulaIdentidad, TAbb abb);

void infoEmpleado(unsigned int cedula , TAbb abb);

void imprimirEmpleados(TAbb abb);

TInfo menorEnAbb(TAbb abb);

TInfo mayorEnAbb(TAbb abb);

TAbb modificarEmpleado(unsigned int cedulaIdentidad , TAbb abb);