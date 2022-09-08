#include <stdio.h> 
typedef struct rep_info * TInfo;

//Devuelve un TInfo con los datos enviados por parámetro
TInfo crearInfo(char * nombre , char * apellido , unsigned int fechaNacimiento,
				unsigned int cedulaIdentidad , unsigned int salarioInicial , unsigned int fechaIngreso);

//Devuelve el elemento "cedula" dentro "info"
unsigned int numeroCI(TInfo info);

//Imprime en pantalla todos los elementos de "info"
void imprimirInfo(TInfo info);

//Libera la memoria asociada a "info" y la de todos sus elementos
void liberarInfo(TInfo info);

//Devuelve una copa de "info" que no comparte direccion de memoria con "info"
TInfo copiaInfo(TInfo info);

