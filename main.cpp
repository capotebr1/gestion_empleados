#include <stdio.h>
#include <string.h>
#include "include/abb.h"
#include "include/info.h"

#define LARGO_CEDULA 9

int main(){
	TAbb hashing[LARGO_CEDULA];
	for(int i = 0; i < LARGO_CEDULA ; i++){
		hashing[i] = crearAbb();
	}

	int opcion = 1;
	printf("BIENVENIDO A GESTION DE EMPLEADOS\n");
	while(opcion != 0){
		printf("\n");
		printf("---------------------------------\n");
		printf("Seleccione una Opcion:\n");
		printf("---------------------------------\n");
		printf("1 : Dar de alta un empleado\n");
		printf("2 : Dar de baja un empleado\n");
		printf("3 : Modificar informacion de empleado\n");
		printf("4 : Mostrar empleados\n");
		printf("5 : Buscar empleado\n");
		printf("0 : QUIT\n");
		printf("---------------------------------\n");
		printf("\n");
		scanf("%d" , &opcion);
		switch(opcion){
			case 1: {
				printf("Ingrese datos de empleado : \nNombre - Apellido - fechaNacimiento - cedulaIdentidad - salarioInicial - fechaIngreso\n");
				char nombre[64];
				char apellido[64];
				unsigned int fechaNacimiento;
				unsigned int cedulaIdentidad;
				unsigned int salarioInicial;
				unsigned int fechaIngreso;
				scanf("%s %s %u %u %u %u" , nombre, apellido , &fechaNacimiento , &cedulaIdentidad , &salarioInicial , &fechaIngreso);
				TInfo datos = crearInfo(nombre , apellido , fechaNacimiento , cedulaIdentidad , salarioInicial , fechaIngreso);
				hashing[(cedulaIdentidad%10) % LARGO_CEDULA] = darAlta(datos , hashing[(cedulaIdentidad%10) % LARGO_CEDULA] );
				printf("Nombre : %s\n", nombre);
				printf("Apellido : %s\n", apellido);
				printf("Fecha de nacimiento : %u / %u / %u\n",fechaNacimiento/1000000 ,(fechaNacimiento/10000)%100 ,fechaNacimiento%10000);
				printf("Cedula de Identidad : %u-%u\n", cedulaIdentidad/10,cedulaIdentidad%10);
				printf("Salario inicial : $%u\n", salarioInicial);
				printf("Fecha de ingreso : %u\n" , fechaIngreso);
				break;
			}
			case 2: {
				printf("Ingrese cedula del empleado: ");
				unsigned int cedulaIdentidad;
				scanf("%u" , &cedulaIdentidad);
				hashing[(cedulaIdentidad%10) % LARGO_CEDULA] = darBaja(cedulaIdentidad , hashing[(cedulaIdentidad%10) % LARGO_CEDULA])	;			
				break;
			}
				
			case 3: {
				printf("Ingrese cedula de empleado : ");
				unsigned int cedulaIdentidad;
				scanf("%u" , &cedulaIdentidad);
				hashing[(cedulaIdentidad%10) % LARGO_CEDULA] = modificarEmpleado(cedulaIdentidad , hashing[(cedulaIdentidad%10) % LARGO_CEDULA] );	
				printf("\nCambios realizados con exito!\n");	
				break;
			}
				
			case 4: {
				printf("Nombre		Apellido	fecha-Nacimiento 	cedula-Identidad 	salario-Inicial 	fecha-Ingreso 		edad 		antiguedad 	Salario-Actual");
				printf("\n");
				for(int i = 0; i < LARGO_CEDULA;i++){
					imprimirEmpleados(hashing[i]);
				}
				break;
			}
				
			case 5: 
				printf("Ingrese cedula de empleado : ");
				unsigned int cedulaIdentidad;
				scanf("%u" , &cedulaIdentidad);
				infoEmpleado(cedulaIdentidad,hashing[(cedulaIdentidad%10) % LARGO_CEDULA]);
				break;
		}
	}
	if(opcion == 0){
		for(int i = 0; i < LARGO_CEDULA ; i++){
			liberarAbb(hashing[i]);
		}
	}
}