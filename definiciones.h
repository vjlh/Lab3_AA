#pragma once
/*
 * En este archivo se encuentran las cabeceras de las funciones, las estructuras utilizadas
   y la declaración de las variables globales que se usan durante el programa
 * @author: Valentina Ligueño
 * @version: 31/12/2018
 */

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

//Encabezados de las funciones implementadas
void goloso(char const*,char const*);
void ordenar_lista(int*,int);
int remover_elemento(int*,int,int);
void printCurrent(int,Combinacion*,int);
