#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "..\..\arboles\headers\arbol-avl.h"
#include "..\..\arboles\headers\arbol-binario-busqueda.h"
#include "..\..\arboles\headers\arbol-binario.h"
#include "..\..\arboles\headers\nodo.h"
#include "..\..\colas\headers\colas.h"
#include "..\..\listas\headers\listas.h"
#include "..\..\pilas\headers\pilas.h"
#include "..\..\tipoElemento\headers\tipo_elemento.h"

#ifndef UTILIDADES_H
#define UTILIDADES_H

// ###################
// ###################
// FUNCIONES GENERALES

void limpiarBuffer();

void limpiar_pantalla();

void pausa();

void menu();

int es_decimal();

float divisionNoExacta(int m, int n, float resto);

void digitalizacion(char* digital, char* seniales, int pos, int posAux);

int* valoresQueSuman();

int esEntero(double num);

char* separadorMilesAux(char* numero, int longitud);

void a_minusculas(char* str);

void imprimirArr(int* arr, int length);

int explosionRecursiva(int n, int b, int* arr, int* count);

void desarrollarPatron(char* cadena, int mitad, int nivel);

void cargarArray(int arr[], int n, int count);

void encontrarSubconjuntos(int conjunto[], int largo, int index, int subconjunto[], int tamanoSub, int sumaActual, int objetivo, char** output, int* indiceOutput);

void guardarSubconjunto(int arr[], int tamano, char** output, int* indiceOutput);

char salir();

void pedirNumero(int* valor);

void pedirNumeroPos(int* valor); //pedriNumero PERO SOLO POSITIVOS

int cargaManualAuto();

int maximo(int a, int b); //RETORNA EL MAXIMO DE DOS NUMEROS

// FUNCIONES GENERALES
// ###################
// ###################

// ###################
// ###################
// FUNCIONES DE LISTAS

void llenarLRandom(Lista l1);

void l_mostrar_con_valor(Lista lista);

void l_mostrar_comunes_pc(Lista l);

void cargarLista(Lista l, int n, int count);

void mostrar_coeficientes(Lista l);

void interfazCargaLista(Lista l);

void lRandomSinRepetir(Lista l, int min, int max, int cantidad, int count); //CREA UNA LISTA RANDOM SIN REPETIR NUMEROS

// FUNCIONES DE LISTAS
// ###################
// ###################

// ##################
// ##################
// FUNCIONES DE PILAS

void p_cargar(Pila p, int n, int count);

Pila p_ej6_eliminarclaveR(Pila p, int clave);

void llenarPRandom(Pila p1);

void p_mostrar_con_valor(Pila p);

int largo(Pila p);

// FUNCIONES DE PILAS
// ##################
// ##################

// ##################
// ##################
// FUNCIONES DE COLAS

void c_cargar(Cola c, int n, int count);

void c_cargarSinRepetir(Cola c, int n, int count);

void interfazCargaColaSinRepetir(Cola c1);

void llenarCRandom(Cola c);

void llenarCRandomSinRepetir(Cola c);

void llenarCRandomValor(Cola c, int max);

void atenderClientes(Cola c, Cola resultado, int tiempoatencion, int nroC);

void enumerar(Cola c);

void c_mostrar_clientes(Cola c);

void c_mostrar_valor(Cola c);

void c_mostrar_bien(Cola c);

bool cexisteclave(Cola c, int clave);

// FUNCIONES DE COLAS
// ##################
// ##################

// FUNCIONES DE ARBOLES
// ##################
// ##################

void l_mostrar_con_nodo(Lista l); //GUARDA EN EL VALOR DEL TE DE LA LISTA EL NODO

void cargar_arbol_binario(ArbolBinario a); //INTERFAZ PARA CARGAR ARBOL

void cargar_nodo(ArbolBinario a, NodoArbol padre, int es_izquierdo); //CARGA UN NODO, E HIJOS

char leer_opcion_sn(); //TE PREGUNTA SI QUERES INGRESAR UN NODO

void l_mostrar_ej2(Lista l); //FUNCION DEL EJ2 PARA MOSTRAR UNA LISTA

void mostrar_arbol(NodoArbol n, char* prefijo, int Izq); //FUNCION PARA MOSTRAR UN ARBOL

void pre_orden(NodoArbol N); //FUNCION PARA MOSTRAR ARBOL EN PREORDEN

void in_orden(NodoArbol N); //FUNCION PARA MOSTRAR ARBOL EN INORDEN

void post_orden(NodoArbol N); //FUNCION PARA MOSTRAR ARBOL EN POSTORDEN

ArbolBinario binarioAleatorio(); //FUNCION RESUMEN DE crearBinarioAleatorio [PARTE 1 DE CARGA BINARIA RANDOM]

NodoArbol nodoAleatorio(); //FUNCION PARA CREAR UN NODO CON HIJOS ALEATORIOS [PARTE 2 DE CARGA BINARIA RANDOM]

void cargar_avl(ArbolAVL v); //FUNCION PARA CARGAR UN AVL CON NUMEROS RANDOM [PARTE 3 DE CARGA BINARIA RANDOM]

void crearBinarioAleatorio(ArbolBinario b, NodoArbol aleatorio, NodoArbol vacio); //FUNCION PARA CONECTAR UN NODO RANDOM A UN ARBOL [PARTE 4 DE CARGA BINARIA RANDOM]

int alturaNodo(NodoArbol na); //DEVUELVE LA ALTURA DE UN NODO: -HI+HD

void cargarNArio(ArbolBinario a, NodoArbol p, int aux); //INTERFAZ PARA CARGAR N-ARIO

char pedirNodo(NodoArbol n); //TE PREGUNTA SI QUERES INGRESAR UN NODO PARA ARBOL N-ARIO

// FUNCIONES DE ARBOLES
// ##################
// ##################

#endif