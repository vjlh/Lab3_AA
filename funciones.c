#include "definiciones.h"
/*
 * En este archivo se encuentran todas las funciones que se utilizan para el correcto funcionamiento
   del programa
 * @author: Valentina Ligueño
 * @version: 31/12/2018
 */


/*
*Funcion que se encarga de leer el archivo de entrada, e inmediatamente generar la solución buscada
*@param entrada: Es el nombre del archivo de entrada del cual se extraerán los datos
*@param salida: Es el nombre del archivo de salida, en el cuál se escribirán las combinaciones encontradas para cada caso
*No posee salidas, ya que escribe de inmediato la solución a medida que la encuentra
*/
void goloso(char const *entrada,char const *salida)		
{											
	FILE *archivo_entrada, *archivo_salida;		
	int i,numero_casos,numero_barriles,costo_tramo,*lista_barriles,barril1,barril2,indice,caso;
	char buffer[100],*barril;

	archivo_entrada = fopen(entrada,"r");
	archivo_salida = fopen(salida,"w");

	fscanf(archivo_entrada," %119[^\n]",buffer);
	numero_casos = atoi(buffer);
	fgetc(archivo_entrada);
	caso = 1;

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

		lista_combinaciones = (Combinacion*)calloc(numero_barriles,sizeof(Combinacion));
   		indice = 0;
   		for (int i = 0; i < numero_barriles; ++i)
   		{
   			barril1 = lista_barriles[i];
   			numero_barriles = remover_elemento(lista_barriles,numero_barriles,i);
   			for (int j = 0; j < numero_barriles; ++j)
   			{
   				barril2 = lista_barriles[j];
   				if(barril1+barril2>=costo_tramo)
   				{
   					lista_combinaciones[indice].barril1 = barril1;
   					lista_combinaciones[indice].barril2 = barril2;
   					numero_barriles = remover_elemento(lista_barriles,numero_barriles,j);
   					indice++;
   					break;
   				}
   			}
   			i=0;
   		}
   		printCurrent(caso,lista_combinaciones,indice);
   		fprintf(archivo_salida,"%i\n",indice);
   		for (int i = 0; i < indice; ++i)
   		{
   			fprintf(archivo_salida,"| %i-%i |",lista_combinaciones[i].barril1,lista_combinaciones[i].barril2);
   		}

   		fprintf(archivo_salida,"\n---\n");

		fgetc(archivo_entrada);
		caso++;
		if (feof(archivo_entrada))
			break;	
	}
	fclose(archivo_entrada);
	fclose(archivo_salida);
}


/*
*Funcion que ordena una lista de enteros en orden ascendente
*@param lista: Lista a ordenar
*@param largo: Cantidad de elementos que posee la lista a ordenar
*No posee salidas, ya que recibe la lista como puntero se hacen directamente los cambios dentro de esta 
*/
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


/*
*Funcion que elimina un elemento de una lista de enteros
*@param lista: Lista a ordenar
*@param largo: Cantidad de elementos que posee la lista a ordenar
*@param indice: Posicion en la que se encuentra el elemento a eliminar de la lista
*No posee salidas, ya que recibe la lista como puntero se hacen directamente los cambios dentro de esta 
*/
int remover_elemento(int* lista,int largo,int indice)
{
	for (int i = 0; i < largo; ++i)
	{
		if (i >= indice)
			lista[i] = lista[i+1];
		
	}
	return largo-1;
}

/*
*Funcion que muestra por pantalla un caso del archivo de entrada y las combinaciones de barriles que cumplen
 las condiciones del caso
*@param caso: Caso que se está evaluando
*@param lista: Lista que posee las combinaciones que cumplen la condicion del caso
*@param largo: Cantidad de elementos que contiene "lista"
*No posee salidas, ya que solo muestra información por pantalla
*/
void printCurrent(int caso,Combinacion *lista,int largo){
	#ifdef DEBUG

	printf("enter para continuar...\n");
	while(getchar() != '\n')
	;
	printf("Para el caso número %i se obtienen las siguientes combinaciones\n",caso);
	for (int i = 0; i < largo; ++i)
	{
		printf("[%i, %i] ",lista[i].barril1,lista[i].barril2);
	}
	printf("\n");
	
	#endif
}
