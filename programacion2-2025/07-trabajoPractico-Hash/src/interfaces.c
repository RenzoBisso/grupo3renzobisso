#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\interfaz.h"
#include "..\headers\tp_thash.h"



void interfaz2(){
    th_ej4_abm();
}

void interfaz3(){
    int cantIte, rango_desde, rango_minimo, rango_hasta, cantElementos;
    bool flag=false;
    do {
        printf("Ingrese la cantidad de elementos que tendran ambas estructuras (entre 1 y 2000): ");
        pedirDatos(&cantElementos, 11);
        if (cantElementos < 1 || cantElementos > 2000)
        printf("Valor fuera de rango.\n");
    } while (cantElementos < 1 || cantElementos > 2000);

    do {
        printf("\nIngrese rango maximo de las claves: ");
        pedirDatos(&rango_hasta , 11);
        if(rango_hasta<cantElementos){
            printf("Por favor ingrese un rango maximo mayor a la cantidad de elementos.\n");
        }
    } while(rango_hasta<cantElementos);

    rango_minimo=rango_hasta-cantElementos;

    do{
        printf("\nIngrese el rango minimo de las claves: ");
        pedirDatos(&rango_desde, 11);
        if (rango_desde > rango_hasta || rango_desde<rango_minimo){
            printf("Ingrese un numero mayor a %d y menor a %d, para poder tener la cantidad de elementos ingresada",rango_minimo, rango_hasta); 
        }else{flag=true;}

    } while (flag=false);

    do{
        printf("\nIngrese la cantidad de busquedas a realizar (A partir de 500 iteraciones): ");
        pedirDatos(&cantIte, 11);
        if (cantIte < CANTIDAD_MINIMA_ITERACIONES)
        printf("Entrada invalida.\n");
    } while (cantIte < CANTIDAD_MINIMA_ITERACIONES);

    th_ej5_comparacion(cantElementos,cantIte,rango_desde,rango_hasta);

    printf("\nSe concluye que, la Tabla Hash es mas eficiente que Arbol AVL cuando se utiliza la implementacion de listas enlazadas\n");
    printf("Sin embargo, al utilizar la implementacion de zona overflow, el AVL realiza las busquedas en menor tiempo que Hash\n");    
}

void interfaz4(){
    th_ej6_covid();
}

