#include "definiciones.h"

void leerArchivosYGuardarDatos()		
{											
	FILE* archivo_entrada;		
	int costo, lineaVacia, i, largoLinea,posicion;
	char buffer[100],buffer2[100],*inversion,*beneficio, *valor3;

	archivo_entrada = fopen("ejemplo.txt","r");

	fscanf(archivo_entrada," %119[^\n]",buffer);
	CAPITAL_LIMITE = atoi(buffer);
	fgetc(archivo_entrada);

	fscanf(archivo_entrada," %119[^\n]",buffer);
	NUMERO_INVERSIONES = atoi(buffer);
	fgetc(archivo_entrada);

	listaDatos = (Datos*)calloc(NUMERO_INVERSIONES,sizeof(Datos*));
	posicion = 0;

	while (!feof(archivo_entrada))
	{
		memset(buffer,0, 100);
		memset(buffer2,0, 100);
		lineaVacia = 1;
		fscanf(archivo_entrada," %119[^\n]",buffer);
		largoLinea = strlen(buffer);

		for (i = 0; i < largoLinea; ++i)
			if (buffer[i] == ' ')
				lineaVacia++;

		if (buffer[0] != '\0' && lineaVacia != largoLinea && buffer[0] != '\n' && buffer[0] != '\t')
		{	
			for (i = 0; i < largoLinea; ++i)
				if (buffer[i] != ' ')
					break;

			strncpy(buffer2,buffer+i,largoLinea-i);

			inversion = strtok(buffer2," ");
			beneficio = strtok(NULL," ");

			listaDatos[posicion].inversion = atoi(inversion);
			listaDatos[posicion].beneficio = atoi(beneficio);
			posicion++;
		}	
		fgetc(archivo_entrada);
		if (feof(archivo_entrada))
			break;	
	}
	fclose(archivo_entrada);
	free(NOMBRE_ARCHIVO);
}