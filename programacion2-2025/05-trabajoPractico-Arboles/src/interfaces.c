#define _CRT_SECURE_NO_WARNINGS

#include "..\..\libs\validaciones\headers\utilidades.h"
#include "..\headers\interfaz.h"
#include "..\headers\tp_arboles.h"

void interfaz2(){
    char c;
    int opcion;
    int clave;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 2      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        ArbolBinario A = a_crear();

        Lista l = l_crear();

        opcion = cargaManualAuto();
        if(opcion){
            //LLENAR RANDOM
        }
        else{
            //LLENAR MANUAL
        }

        printf("\t||\n");

        //A
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||A: RETORNA UNA LISTA CON TODOS LOS NODOS HOJA                                                       ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        l = a_ej2_hojas(A);

        printf("\t||\n");
        printf("\t|| "); l_mostrar(l);
        printf("\t||\n");

        free(l);
        
        //B
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: RETORNA UNA ESTRUCTURA CON TODOS LOS NODOS INTERIORES                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        l = a_ej2_interiores(A);

        printf("\t||\n");
        printf("\t|| "); l_mostrar(l);
        printf("\t||\n");

        free(l);

        //C
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: BUSCA TODAS LAS OCURRENCIAS DE UNA CLAVE Y RETORNA SUS POSICIONES                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t||\n");

        pedirNumero(&clave);

        l = a_ej2_buscarclave(A, clave);

        printf("\t||\n");
        printf("\t|| "); //l_mostrar_ej2(l);
        printf("\t||\n");

        free(l);

        //D
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||D: COMPLEJIDAD ALGORITMICA DE LOS PUNTOS A), B) Y C)                                                ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t||\n");
        printf("\t|| Complejidad A: \n");
        printf("\t|| Complejidad B: \n");
        printf("\t|| Complejidad C: \n");
        printf("\t||\n");

        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz3(){
    char c;
    int opcion;
    int clave;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 3      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        ArbolBinario A = a_crear();

        Lista l = l_crear();

        opcion = cargaManualAuto();
        if(opcion){
            //LLENAR RANDOM
        }
        else{
            //LLENAR MANUAL
        }

        //A
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||A: RETORNA LA CLAVE DEL NODO PADRE/RAIZ                                                             ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE LA CLAVE DEL NODO HIJO \n");
        pedirNumero(&clave);

        printf("\t||\n");
        printf("\t|| CLAVE: %d\n", a_ej3_clavepadre(A, clave));

        //B
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: LISTA LOS NODOS HOJA (CLAVE)                                                                     ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE LA CLAVE DEL NODO PADRE \n");
        pedirNumero(&clave);

        l = a_ej3_hijos(A, clave);

        printf("\t||\n");
        printf("\t|| "); l_mostrar(l);
        printf("\t||\n");

        free(l);

        //C
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: RETORNA EL NODO HERMANO DE UNA CLAVE                                                             ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE EL NODO HERMANO \n");
        pedirNumero(&clave);

        printf("\t||\n");
        printf("\t|| NODO HERMANO DE %d: [%d] \n", clave, a_ej3_hermano(A, clave)); 
        printf("\t||\n");

        //D
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||D: CALCULA EL NIVEL EN EL QUE SE ENCUENTRA UN NODO                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE LA CLAVE DEL NODO \n");
        pedirNumero(&clave);

        printf("\t||\n");
        printf("\t|| EL NODO CON LA CLAVE '%d' SE ENCUENTRA EN EL NIVEL %d \n", clave, a_ej3_nivel(A, clave)); 
        printf("\t||\n");

        //E
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||E: CALCULA LA ALTURA DE LA RAMA DE UN NODO                                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE LA CLAVE DEL NODO \n");
        pedirNumero(&clave);

        printf("\t||\n");
        printf("\t|| LA ALTURA DE LA RAMA DEL NODO CON LA CLAVE '%d' ES: [%d] \n", clave, a_ej3_alturarama(A, clave)); 
        printf("\t||\n");

        //F
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||F: LISTA TODOS LOS NODOS EN EL MISMO NIVEL (CLAVE)                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("\t|| INGRESE EL NIVEL \n");
        pedirNumero(&clave);

        l = a_ej3_clavesmismonivel(A, clave);

        printf("\t||\n");
        printf("\t|| "); l_mostrar(l);
        printf("\t||\n");

        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz4(){
    char c;
    int opcion;
    
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 4      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        

        pausa();

    }while (c == 'n');
}

void interfaz5(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 7      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        
        

        
        pausa();

    }while (c == 'n');
}

void interfaz6(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 8      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");


        pausa();

    }while (c == 'n');
}

void interfaz7(){
    char c;
    int opcion;
    bool flag;
    int q;
    
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 9      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");


        pausa();

    }while (c == 'n');
}

void interfaz8(){
    char c;
    int opcion;
    bool flag;
    int q;
    
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 10      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n"); 

        pausa();

    }while (c == 'n');
}