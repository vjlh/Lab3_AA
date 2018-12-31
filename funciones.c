#include "definiciones.h"

void leerArchivosYGuardarDatos()		
{											
	FILE *archivo_entrada, *archivo_salida;		
	int numero_combinaciones,i,numero_barriles,costo_tramo,*lista_barriles,barril1,barril2,indice;
	char buffer[100],*barril;

	archivo_entrada = fopen("ejemplo2.txt","r");
	archivo_salida = fopen("salida.txt","w");

	fscanf(archivo_entrada," %119[^\n]",buffer);
	NUMERO_CASOS = atoi(buffer);
	fgetc(archivo_entrada);


	while (!feof(archivo_entrada))
	{
		Combinacion *lista_combinaciones;
		memset(buffer,0, 100);

		fscanf(archivo_entrada," %119[^\n]",buffer);fgetc(archivo_entrada);

		numero_barriles = atoi(strtok(buffer," "));
		costo_tramo = atoi(strtok(NULL," \n"));

		lista_barriles = (int*)calloc(numero_barriles,sizeof(int));
		
		fscanf(archivo_entrada," %119[^\n]",buffer);

   		barril = strtok(buffer, " ");
		lista_barriles[0] = atoi(barril);
   		i = 1;

   		while(barril != NULL && i<numero_barriles)
   		{
      		barril = strtok(NULL, " ");
      		lista_barriles[i] = atoi(barril);      		
      		i++;
   		}
   		
   		ordenar_lista(lista_barriles,numero_barriles);
   		for (int i = 0; i < numero_barriles; ++i)
   		{
   			printf("%i ",lista_barriles[i]);
   		}
   		printf("Costo tramo: %i\n",costo_tramo);

		lista_combinaciones = (Combinacion*)calloc(numero_barriles,sizeof(Combinacion));
   		indice = 0;
   		for (int i = 0; i < numero_barriles; ++i)
   		{
   			barril1 = lista_barriles[i];
   			numero_barriles = remover_elemento(lista_barriles,numero_barriles,i);
   			for (int j = 0; j < numero_barriles; ++j)
   			{
   				barril2 = lista_barriles[j];
   				printf("%i - % i\n",barril1,barril2);
   				if(barril1+barril2>=costo_tramo)
   				{
   					lista_combinaciones[indice].barril1 = barril1;
   					lista_combinaciones[indice].barril2 = barril2;
   					numero_barriles = remover_elemento(lista_barriles,numero_barriles,j);
   					indice++;
   					break;
   				}
   			}
   		}
   		fprintf(archivo_salida,"%i\n",indice);
   		for (int i = 0; i < indice; ++i)
   		{
   			fprintf(archivo_salida,"| %i-%i |",lista_combinaciones[i].barril1,lista_combinaciones[i].barril2);
   		}

   		fprintf(archivo_salida,"\n---\n");

		fgetc(archivo_entrada);
		if (feof(archivo_entrada))
			break;	
	}
	fclose(archivo_entrada);
	fclose(archivo_salida);
}
void ordenar_lista(int* lista,int largo){
	for (int i = 0; i < largo-1; ++i)
	{
		if(lista[i]>lista[i+1])
		{
			int temporal = lista[i];
			lista[i] = lista[i+1];
			lista[i+1] = temporal;
			i = -1;
		}
	}
}

int remover_elemento(int* lista,int largo,int indice)
{
	for (int i = 0; i < largo; ++i)
	{
		if (i >= indice)
			lista[i] = lista[i+1];
		
	}
	return largo-1;
}
