#include "definiciones.h"
/*
 * En este archivo se encuentran las llamadas a las funciones que hacen la correcta ejecución
   del programa
 * @author: Valentina Ligueño
 * @version: 31/12/2018
 */

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
	printf("El programa ha terminado su ejecucion\n");
	return 0;
}
