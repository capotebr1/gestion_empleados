
#include "../include/abb.h"

struct empleadoNodo{
	TInfo data;
	empleadoNodo * izq;
	empleadoNodo * der;
};


TAbb crearAbb(){
	TAbb nuevo = NULL;
	return nuevo;
}

void liberarAbb(TAbb abb) {
	if (abb != NULL){

		if (abb->izq != NULL){
			liberarAbb(abb->izq);
		}
		if (abb->der != NULL){
			liberarAbb(abb->der);
		}

		liberarInfo(abb->data);
		delete abb;
	}
}


bool esVacioAbb(TAbb abb){
	return abb == NULL;
}

TInfo raiz(TAbb abb){
	return abb->data;
}

TAbb darAlta(TInfo datos, TAbb abb) {
	TAbb nuevo = new empleadoNodo;
		nuevo->data = datos;
		nuevo->izq = NULL;
		nuevo->der = NULL;

	if (abb == NULL){
		abb = nuevo;
	}
	else{
		TAbb aux = abb;
		while(aux != NULL){
			if (numeroCI(datos) < numeroCI(aux->data)){
				if (aux->izq == NULL){
					aux->izq = nuevo;
					break;
				}
				else aux = aux->izq;
			}
			else if (numeroCI(datos) > numeroCI(aux->data)){
				if (aux->der == NULL){
					aux->der = nuevo;
					break;
				}
				else aux = aux->der;
			}
		}
		aux = nuevo;
	}
	printf("---------------------------------\n");
	return abb;
}

TAbb darBaja(unsigned int ci , TAbb abb){
	if (numeroCI(abb->data) == ci){
		if (abb->izq == NULL){
			TAbb aux = abb;
			abb = abb->der;
			liberarInfo(aux->data);
			delete aux;		
		}
		else if (abb->der == NULL){
			TAbb aux = abb;
			abb = abb->izq;
			liberarInfo(aux->data);
			delete aux;
		}
		else{
			liberarInfo(abb->data);
			abb->data = copiaInfo(mayorEnAbb(abb->izq));
			abb->izq = darBaja(numeroCI(abb->data) , abb->izq);
		}
	} 
	else if (ci < numeroCI(abb->data))
		abb->izq = darBaja(ci,abb->izq);

	else if(esVacioAbb(abb)){
		printf("No existe empleado con cedula %u \n", ci);
	}

	else
	 	abb->der = darBaja(ci,abb->der);

	return abb;
}

TAbb modificarEmpleado(unsigned int cedulaIdentidad , TAbb abb){
	TAbb aux = abb;
	while ((aux != NULL) && (numeroCI(aux->data) != cedulaIdentidad)){
		if (cedulaIdentidad < numeroCI(aux->data))
			aux = aux->izq;
		else aux = aux->der;
	}
	if(aux != NULL){
		liberarInfo(aux->data);
		printf("Ingrese nueva informacion: \n");
		printf("Nombre - Apellido - Fecha-Nacimiento - Salario-Inicial - Fecha-ingreso\n");
		char nombre[64];
		char apellido[64];
		unsigned int fechaNacimiento;
		unsigned int salarioInicial;
		unsigned int fechaIngreso;
		scanf("%s %s %u %u %u" , nombre , apellido , &fechaNacimiento , &salarioInicial , &fechaIngreso);
		TInfo nuevaInfo = crearInfo(nombre, apellido , fechaNacimiento , cedulaIdentidad , salarioInicial , fechaIngreso);
		aux->data = nuevaInfo;

	}
	else{
		printf("El empleado ingresado no existe en la base de datos. \n");
	}
	return abb;
}

void imprimirEmpleados(TAbb abb){
	if(abb != NULL){
		if(abb->izq != NULL){
			imprimirEmpleados(abb->izq);
		}
		if(abb->der != NULL){
			imprimirEmpleados(abb->der);
		}
		imprimirInfo(abb->data);
	}
}

void infoEmpleado(unsigned int cedula , TAbb abb){
	if(abb != NULL){
		if(numeroCI(raiz(abb)) == cedula){
			printf("Nombre		Apellido	fecha-Nacimiento 	cedula-Identidad 	salario-Inicial 	fecha-Ingreso 		edad 		antiguedad 		Salario-Actual \n");
			imprimirInfo(raiz(abb));
		}
		else if(cedula < numeroCI(raiz(abb))){
			infoEmpleado(cedula , abb->izq);
		}
		else if(cedula > numeroCI(raiz(abb))){
			infoEmpleado(cedula , abb->der);
		}
	}
	else{
		printf("No existe empleado con la CI %u en la base de datos.\n", cedula);
	}

}


TInfo menorEnAbb(TAbb abb) {
	TAbb aux = abb;
	while(aux->izq != NULL){
		aux = aux->izq;
	}
	return raiz(aux);
}

TInfo mayorEnAbb(TAbb abb) {
	TAbb aux = abb;
	while(aux->der != NULL){
		aux = aux->der;
	}
	return raiz(aux);
}