#pragma once
//Librerías a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de estructuras a utilizar

struct Combinacion{
	int barril1;
	int barril2;
};

typedef struct Combinacion Combinacion;

//Definición de las variables globales
int NUMERO_CASOS;
char *NOMBRE_ARCHIVO;

//Encabezados de las funciones implementadas
void goloso(char const*,char const*);
void ordenar_lista(int*,int);
int remover_elemento(int*,int,int);
void printCurrent(int,Combinacion*,int);
