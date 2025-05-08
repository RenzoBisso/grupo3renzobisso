#define _CRT_SECURE_NO_WARNINGS

#include "interfaz.h"
#include "utilidades.h"
#include "tp_4_colas.h"

void interfaz2(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 2      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Cola c1=c_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
        }
        else{
            interfazCargaCola(c1);
        }

        printf("\t||");
        printf("\n\t|| Cola: ");
        c_mostrar(c1);
        printf("\t||\n");

        int numero;
        int posicion;

        //A
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||A: DETERMINA SI UNA CLAVE SE ENCUENTRA DENTRO DE LA COLA                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        pedirNumero(&numero);

        if(c_ej2_existeclave(c1,numero)==true){
            printf("\t||                                                                                                    ||\n");
            printf("\t||EXISTE LA CLAVE %d EN LA COLA                                                                       ||\n", numero);
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }else{
            printf("\t||                                                                                                    ||\n");
            printf("\t||NO EXISTE LA CLAVE %d EN LA COLA                                                                    ||\n", numero);
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }
        
        //B
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||B: AGREGAR UN ELEMENTO EN LA POSICION DADA                                                          ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        printf("Ingrese el elemento a agregar: \n");
        pedirNumero(&numero);
        TipoElemento elementoNuevo=te_crear(numero);
        printf("Ingrese la posicion en que lo quiere agregar: \n");
        pedirNumero(&posicion);
        c_ej2_colarelemento(c1,posicion,elementoNuevo);
        c_mostrar(c1);

        //C
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||C: SACAR UN ELEMENTO ENCONTRADO TODAS VECES DADAS                                                   ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        printf("Ingrese el numero a eliminar: \n");
        pedirNumero(&numero);
        c_ej2_sacarelemento(c1,numero);
        c_mostrar(c1);

        //D
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||D: CONTAR LOS ELEMENTOS DE LA COLA                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        int elementos=c_ej2_contarelementos(c1);
        printf("Hay %d elementos\n",elementos);
        
        //E
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||E: COPIAR UNA COLA                                                                                  ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        Cola cCopia=c_crear();
        cCopia=c_ej2_copiar(c1);
        c_mostrar(cCopia);

        //F
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||F: INVERTIR CONTENIDO DE LA COLA                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Cola cInvertida=c_crear();

        cInvertida=c_ej2_invertir(c1);
        c_mostrar(cInvertida);
        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

void interfaz3(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 3      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||Dadas dos colas, determinar si sus contenidos son iguales                                           ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Cola c1=c_crear();
        Cola c2=c_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
            llenarCRandom(c2);
        }
        else{
            interfazCargaCola(c1);
            interfazCargaCola(c2);
        }
        
        printf("\t||");
        printf("\n\t|| Cola 1: ");
        c_mostrar(c1);
        printf("\t||\n");
        printf("\t||");
        printf("\n\t|| Cola 2: ");
        c_mostrar(c2);
        printf("\t||\n");

        if(c_ej3_iguales(c1,c2)==true){
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||SON IGUALES                                                                                         ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }else{
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
            printf("\t||NO SON IGUALES                                                                                      ||\n");
            printf("\t||----------------------------------------------------------------------------------------------------||\n");
        }

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
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        
        Cola c1=c_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
        }
        else{
            interfazCargaCola(c1);
        }

        printf("\t||");
        printf("\n\t|| Cola: ");
        c_mostrar(c1);
        printf("\t||\n");

        limpiarBuffer();

        c = salir();
        
        pausa();

    }while (c == 'n');
}

void interfaz5(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 5      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        
        
        Cola c1=c_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
        }
        else{
            interfazCargaCola(c1);
        }

        printf("\t||");
        printf("\n\t|| Cola: ");
        c_mostrar(c1);
        printf("\t||\n");

        limpiarBuffer();

        c = salir();
        
        pausa();

    }while (c == 'n');
}

void interfaz6(){
    char c;
    int opcion;
    do  //MENU/////////////////////////////////////////////////
    {
        printf("\t\t\t                      +------------------------+\n");
        printf("\t\t\t                      |       EJERCICIO 6      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||                                                                                                    ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Cola c1=c_crear();

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
        }
        else{
            interfazCargaCola(c1);
        }

        printf("\t||");
        printf("\n\t|| Cola: ");
        c_mostrar(c1);
        printf("\t||\n");

        limpiarBuffer();

        c = salir();

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
        printf("\t\t\t                      |       EJERCICIO 7      |\n");
        printf("\t\t\t                      +------------------------+\n\n\n");
        printf("\t||>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>||\n");
        printf("\t||UN NEGOCIO TIENE 3 VENTANILLAS PARA ATENDER CLIENTE. LOS CLIENTES FORMAN COLA EN CADA VENTANILLA    ||\n");
        printf("\t||UN DIA QUEDA SOLO UN EMPLEADO PARA ATENDER LAS 3 COLAS. LAS ATIENDE EN UN TIEMPO(Q),                ||\n");
        printf("\t||PASANDO POR CADA COLA EQUITATIVAMENTE                                                               ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");
        printf("\t||INTRODUZCA 1 PARA CARGA AUTOMATICA Y 0 PARA CARGA MANUAL                                            ||\n");
        printf("\t||----------------------------------------------------------------------------------------------------||\n");

        Cola c1 = c_crear();
        Cola c2 = c_crear();
        Cola c3 = c_crear();

        flag = true;

        opcion = cargaManualAuto();
        if(opcion){
            llenarCRandom(c1);
            llenarCRandom(c2);
            llenarCRandom(c3);
        }
        else{
            interfazCargaCola(c1);
            interfazCargaCola(c2);
            interfazCargaCola(c3);
        }

        printf("\t||INGRESE TIEMPO DE ATENCION(Q): ");

        scanf("%d", &q);
        limpiarBuffer();
        
        while(flag){
            if(q <= 0){
                printf("\n\t||Entrada invalida.\n");
                printf("\t||INGRESE TIEMPO DE ATENCION(Q): ");
                scanf("%d", &q);
                limpiarBuffer();
            }
            else{
                flag = false;
            }
        }

        printf("\n\t||----------------------------------------------------------------------------------------------------||\n");

        Cola res = c_crear();
        
        res = c_ej7_atenderclientes(c1, c2, c3, q);

        c_mostrar_clientes(res);

        limpiarBuffer();

        c = salir();

        pausa();

    }while (c == 'n');
}

