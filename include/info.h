#include <stdio.h> 
typedef struct rep_info * TInfo;

TInfo crearInfo(char * nombre , char * apellido , unsigned int fechaNacimiento,
				unsigned int cedulaIdentidad , unsigned int salarioInicial , unsigned int fechaIngreso);

unsigned int numeroCI(TInfo info);

void imprimirInfo(TInfo info);

void liberarInfo(TInfo info);

TInfo copiaInfo(TInfo info);

