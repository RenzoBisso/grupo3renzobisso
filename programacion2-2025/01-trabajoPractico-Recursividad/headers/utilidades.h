#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#ifndef UTILIDADES_H
#define UTILIDADES_H

//FUNCIONES AUXILIARES GENERALES

void limpiarBuffer();

void limpiar_pantalla();

void pausa();

void menu();

int es_decimal();

int esEntero(double num);

void a_minusculas(char *str);

void imprimirArr(int* arr, int length);

//FIN DE FUNCIONES AUXILIARES GENERALES
//
//
//FUNCIONES AUXILIARES DE EJERCICIOS

//PUNTO 2
int productoAux(int m, int n);

//PUNTO 4
float divisionNoExacta(int m, int n, float resto);

//PUNTO 5
char * separadorMilesAux(char * numero, int longitud);

//PUNTO 6
void desarrollarPatron(char *cadena, int mitad, int nivel);

//PUNTO 7
void digitalizacion(char * digital, char * seniales, int pos, int posAux);

//PUNTO 8
void cargarArray(int arr[], int n,int count);

void imprimirSubconjunto(int arr[], int n, int count);

void encontrarSubconjuntos(int conjunto[], int largo, int index, int subconjunto[], int tamanoSub, int sumaActual, int objetivo);

void sumaSubConjuntos();

//PUNTO 10
int explosionRecursiva(int n, int b,int* arr, int* count);

//FIN DE FUNCIONES AUXILIARES DE PUNTOS

#endif