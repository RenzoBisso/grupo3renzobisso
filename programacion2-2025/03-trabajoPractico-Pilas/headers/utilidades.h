#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "..\..\libs\listas\headers\listas.h"
#include "..\..\libs\pilas\headers\pilas.h"
#include "..\..\libs\tipoElemento\headers\tipo_elemento.h"

#ifndef UTILIDADES_H
#define UTILIDADES_H

void limpiarBuffer();

void limpiar_pantalla();

void pausa();

void menu();

int es_decimal();

float divisionNoExacta(int m, int n, float resto);

void digitalizacion(char * digital, char * seniales, int pos, int posAux);

int* valoresQueSuman();

int esEntero(double num);

char * separadorMilesAux(char * numero, int longitud);

void a_minusculas(char *str);

void imprimirArr(int* arr, int length);

int explosionRecursiva(int n, int b,int* arr, int* count);

void desarrollarPatron(char *cadena, int mitad, int nivel);

void cargarArray(int arr[], int n,int count);

void encontrarSubconjuntos(int conjunto[], int largo, int index, int subconjunto[], int tamanoSub, int sumaActual, int objetivo,char** output,int * indiceOutput);

void guardarSubconjunto(int arr[], int tamano,char** output,int *indiceOutput);

void llenarLRandom(Lista l1);

void l_mostrar_con_valor(Lista lista);

void cargarLista(Lista l, int n, int count);

char salir();

void mostrar_coeficientes(Lista l);

void pedirNumero(int* valor);

int cargaManualAuto();
void p_cargar(Pila p,int n, int count);
Pila p_ej6_eliminarclaveR(Pila p, int clave);
void llenarPRandom(Pila p1);
#endif