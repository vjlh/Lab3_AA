#include "definiciones.h"
int main(int argc, char const *argv[]){
	char const *entrada, *salida;
	
	entrada = argv[1];
	if (fopen(entrada,"r")==NULL)
	{
		printf("Ingrese un nombre de archivo de entrada válido\n");
		exit(1);
	}
	salida = argv[2];

	goloso(entrada,salida);
	return 0;
}
