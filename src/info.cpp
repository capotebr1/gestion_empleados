#include <stdio.h> 
#include <string.h>
#include <time.h>
#include "../include/info.h"

struct rep_info{
	char nombre[64]; 
	char apellido[64];
	unsigned int fechaNacimiento;
	unsigned int cedulaIdentidad;
	unsigned int salarioInicial;
	unsigned int fechaIngreso;
};

TInfo crearInfo(char * nombre , char * apellido , unsigned int fechaNacimiento,
					unsigned int cedulaIdentidad , unsigned int salarioInicial , unsigned int fechaIngreso){
	TInfo nuevo = new rep_info;
	strcpy(nuevo->nombre , nombre);
	strcpy(nuevo->apellido , apellido);
	nuevo->fechaNacimiento = fechaNacimiento;
	nuevo->cedulaIdentidad = cedulaIdentidad;
	nuevo->salarioInicial = salarioInicial;
	nuevo->fechaIngreso = fechaIngreso;
	return nuevo;
}

unsigned int numeroCI(TInfo info){
	return info->cedulaIdentidad;
}

void imprimirInfo(TInfo info){
	printf("%s 		",info->nombre);
	printf("%s 		",info->apellido);
	printf("%u / %u / %u 		", info->fechaNacimiento/1000000 , (info->fechaNacimiento/10000)%100 , info->fechaNacimiento%10000);
	printf("%u-%u 		", info->cedulaIdentidad/10 , info->cedulaIdentidad%10);
	printf("$%u  		", info->salarioInicial);
	printf("%u / %u / %u 		", info->fechaIngreso/1000000 , (info->fechaIngreso/10000)%100 , info->fechaIngreso%10000);

	//CALCULO EDAD//
	time_t now = time(0);
	tm * time = localtime(&now);

	//calculo edad empleado
	unsigned int edad = time->tm_year + 1900 - info->fechaNacimiento%10000;
	if((info->fechaNacimiento/10000)%100 == time->tm_mon + 1){
		if(info->fechaNacimiento/1000000 < time->tm_mday){
			edad--;
		}
	}
	else if((info->fechaNacimiento/10000)%100 > time->tm_mon + 1){
		edad--;
	}

	//calculo antigüedad empleado
	unsigned int antiguedad = time->tm_year + 1900 - info->fechaIngreso%10000;
	if((info->fechaIngreso/10000)%100 == time->tm_mon + 1){
		if(info->fechaIngreso/1000000 < time->tm_mday){
			antiguedad--;
		}
	}
	else if((info->fechaIngreso/10000)%100 > time->tm_mon + 1){
		antiguedad--;
	}

	//calculo salario actual del empleado
	unsigned int salarioActual = info->salarioInicial;
	if(antiguedad >= 3){
		salarioActual += (antiguedad - 3)*(0.08)*info->salarioInicial;
	}
	printf("%u 		", edad);
	printf("%u 		", antiguedad);
	printf("$%u\n", salarioActual);
	printf("\n");
}


void liberarInfo(TInfo info){
	delete info;
}

TInfo copiaInfo(TInfo info){
	TInfo copia = new rep_info;
	strcpy(copia->nombre , info->nombre);
	strcpy(copia->apellido , info->apellido);
	copia->fechaNacimiento = info->fechaNacimiento;
	copia->cedulaIdentidad = info->cedulaIdentidad;
	copia->salarioInicial = info->salarioInicial;
	copia->fechaIngreso = info->fechaIngreso;
	return copia;
}